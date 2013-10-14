#include "stdafx.h"
#include "B-Spline.h"
#include <math.h>
#include "Calculate.h"
#include <stdio.h>
#include <complex>
#include <algorithm>
using namespace System;
using namespace System::ComponentModel;
//using namespace System::Diagnostics;
//using namespace System::Collections;
void GetKnotVector(array<float>^ &KnotVector,int n_value , int k_value)
{
    // 開放式均勻節點向量
    //	Array::Resize(KnotVector,n_value+k_value+1);             //20080310
    
    for(int i =1 ; i<= (n_value+k_value+1) ; i++)
    {
        if(1<=i && (i)<= k_value) KnotVector->SetValue(0/(n_value+2-k_value),i-1);
        if(k_value+1<=i && (i)<= n_value+1) KnotVector->SetValue((float)(i-k_value)/(float)(n_value+2-k_value),i-1);
        if(n_value+2<=i && (i)<= n_value+k_value+1) KnotVector->SetValue((n_value+2-k_value)/(n_value+2-k_value),i-1);
    }
}
void GetNikValue(array<float>^ &NikVector , array<float>^ KnotVector , int k_value ,float t,int n_value)
{
    //正規化的B-spline基底函數
    //k_value 為 階數
    //NiVector的數目 為 n_value + 1
    //KnotVector 的數目 為 n_value + k_value + 1
    //tmpNikVector 為 Previous NiVector
    //在先前的式中已經Resize過了
    //Array::Clear(NikVector,0,NikVector->Length);
    //Array::Resize(NikVector,n_value+1);
    array<float>^ tmpNikVector = gcnew array<float>(n_value+1);
    //Array::Resize(tmpNikVector,n_value+1);
    
    for(int k = 1 ; k <= k_value ; k++)
    {
        
        for(int i= 1 ; i<=(n_value+1) ; i++)
        {
            if( k == 1)
            {
                if (t >=Convert::ToSingle(KnotVector->GetValue(i-1)) && t < Convert::ToSingle(KnotVector->GetValue(i))) NikVector->SetValue(1,i-1);
                
                else NikVector->SetValue(0.0f,i-1);
            }
            
            else
            {
                float tmpa;
                float tmpb;
                if(Convert::ToSingle(KnotVector->GetValue(i+k_value-1-1))-Convert::ToSingle(KnotVector->GetValue(i-1)) == 0) tmpa = 0;
                
                else tmpa = (t-Convert::ToSingle(KnotVector->GetValue(i-1))) *Convert::ToSingle(tmpNikVector->GetValue(i-1))/(Convert::ToSingle(KnotVector->GetValue(i+k_value-1-1))-Convert::ToSingle(KnotVector->GetValue(i-1)));
                if((Convert::ToSingle(KnotVector->GetValue(i+k_value-1))-Convert::ToSingle(KnotVector->GetValue(i))) == 0) tmpb = 0;
                
                else tmpb = (Convert::ToSingle(KnotVector->GetValue(i+k_value-1))- t) *Convert::ToSingle(tmpNikVector->GetValue(i))/(Convert::ToSingle(KnotVector->GetValue(i+k_value-1))-Convert::ToSingle(KnotVector->GetValue(i)));
                NikVector->SetValue( tmpa + tmpb ,i-1) ;
            }
        }
        
        for(int j = 0; j<n_value+1 ; j++)
        {
            tmpNikVector->SetValue(Convert::ToSingle(NikVector->GetValue(j)),j);
        }
    }
}
void Get_BSplineSurface_Point(float &SurfacePoint_u_v_X,float &SurfacePoint_u_v_Y,float &SurfacePoint_u_v_Z,array<float,2>^ CotorllPt_X,array<float,2>^ CotorllPt_Y,array<float,2>^ CotorllPt_Z,float para_u,float para_v, int k_value )
{
    //SurfacePoint_u_v 為在參數u,v時Surface上的點座標
    //CotorllPt        為控制點座標,X,Y,Z
    // Prar_u 描述Surface的參數 ,介於(0~1) ?
    // Prar_v 描述Surface的參數 ,介於(0~1) ?
    // k_value : 階數  ,n_value +1 : u方向控制點數目 , m_value : v方向控制點數目
    //定義兩方向的k_value一樣
    //B-spline曲面數學模式
    //得到 B-Spline曲面上上的某一點 P(u,v) 位置座標
    //Ini數值
    SurfacePoint_u_v_X = 0;
    SurfacePoint_u_v_Y = 0;
    SurfacePoint_u_v_Z = 0;
    //獲得 n_value  , m_value
    int n_value = CotorllPt_X->GetLength(0)-1;
    int m_value = CotorllPt_X->GetLength(1)-1;
    //獲得KnotVector(u)
    array<float>^ KnotVector_u = gcnew array<float>(n_value+k_value+1);     //20080310
    //	Array::Resize(KnotVector_u,n_value+k_value+1);                 //20080310
    GetKnotVector(KnotVector_u,n_value ,k_value);
    Array::Sort(KnotVector_u);
    //獲得NikValue(u)
    array<float>^ tmpNikVector = gcnew array<float>(n_value+1);	     //20080310
    //	Array::Resize(tmpNikVector,n_value+1);                          //20080310
    GetNikValue(tmpNikVector,KnotVector_u,k_value,para_u,n_value);
    //獲得KnotVector(v)
    array<float>^ KnotVector_v = gcnew array<float>(m_value+k_value+1);         //20080310
    //	Array::Resize(KnotVector_v,m_value+k_value+1);                             //20080310
    GetKnotVector(KnotVector_v,m_value ,k_value);
    Array::Sort(KnotVector_v);
    //獲得MjlValue(v)
    array<float>^ tmpMjlVector = gcnew array<float>(m_value+1);	             //20080310
    //	Array::Resize(tmpMjlVector,m_value+1);                                  //20080310
    GetNikValue(tmpMjlVector,KnotVector_v,k_value,para_v,m_value);
    
    for(int i = 0 ; i < n_value+1 ; i++)
    {
        float tmp_NikValue ;
        tmp_NikValue = Convert::ToSingle(tmpNikVector->GetValue(i));
        
        for(int j = 0 ; j < m_value+1 ; j++)
        {
            float tmp_MijValue ;
            tmp_MijValue = Convert::ToSingle(tmpMjlVector->GetValue(j));
            if ( tmp_NikValue != 0 && tmp_MijValue != 0)
            {
                SurfacePoint_u_v_X = SurfacePoint_u_v_X + (Convert::ToSingle(CotorllPt_X->GetValue(i,j))*tmp_NikValue*tmp_MijValue);
                SurfacePoint_u_v_Y = SurfacePoint_u_v_Y + (Convert::ToSingle(CotorllPt_Y->GetValue(i,j))*tmp_NikValue*tmp_MijValue);
                SurfacePoint_u_v_Z = SurfacePoint_u_v_Z + (Convert::ToSingle(CotorllPt_Z->GetValue(i,j))*tmp_NikValue*tmp_MijValue);
            }
        }
    }
    delete KnotVector_u;
    delete tmpNikVector;
    delete KnotVector_v;
    delete tmpMjlVector;
}
void Get_BSplineSurface_Point_New071101(float &SurfacePoint_u_v_X,float &SurfacePoint_u_v_Y,float &SurfacePoint_u_v_Z,array<float,2>^ CotorllPt_X,array<float,2>^ CotorllPt_Y,array<float,2>^ CotorllPt_Z,
float para_u,float para_v, int k_value,int tmp_ii,int tmp_jj,float plateW,float plateH,float *size,float *pos )
{
    //SurfacePoint_u_v 為在參數u,v時Surface上的點座標
    //CotorllPt        為控制點座標,X,Y,Z
    // Prar_u 描述Surface的參數 ,介於(0~1) ?
    // Prar_v 描述Surface的參數 ,介於(0~1) ?
    // k_value : 階數  ,n_value +1 : u方向控制點數目 , m_value : v方向控制點數目
    //定義兩方向的k_value一樣
    //B-spline曲面數學模式
    //得到 B-Spline曲面上上的某一點 P(u,v) 位置座標
    //Ini數值
    SurfacePoint_u_v_X = 0;
    SurfacePoint_u_v_Y = 0;
    SurfacePoint_u_v_Z = 0;
    //獲得 n_value  , m_value
    int n_value = CotorllPt_X->GetLength(0)-1;
    int m_value = CotorllPt_X->GetLength(1)-1;
    //獲得KnotVector(u)
    array<float>^ KnotVector_u = gcnew array<float>(n_value+k_value+1);
    //Array::Resize(KnotVector_u,n_value+k_value+1);
    GetKnotVector(KnotVector_u,n_value ,k_value);
    Array::Sort(KnotVector_u);
    //獲得NikValue(u)
    array<float>^ tmpNikVector = gcnew array<float>(n_value+1);
    //Array::Resize(tmpNikVector,n_value+1);
    //獲得KnotVector(v)
    array<float>^ KnotVector_v = gcnew array<float>(m_value+k_value+1);
    //Array::Resize(KnotVector_v,m_value+k_value+1);
    GetKnotVector(KnotVector_v,m_value ,k_value);
    Array::Sort(KnotVector_v);
    //獲得MjlValue(v)
    array<float>^ tmpMjlVector = gcnew array<float>(m_value+1);
    //Array::Resize(tmpMjlVector,m_value+1);
    //增加速度 ,避免乘法和除法在迴圈中使用 ------------------
    int tmpcount = 0;
    float tmp_u_v_X = 0 ;
    float tmp_u_v_Y = 0 ;
    float tmp_u_v_Z = 0 ;
    double tmpRatioX,tmpRatioY;
    float D_plateW = 1/plateW ;
    float D_plateH = 1/plateH ;
    float c1 = pos[0]+0.5f*size[0] ;
    float c2 = pos[1]+0.5f*size[1] ;
    float dis_x = (tmp_ii+0.5f)*size[0];
    float dis_y = (tmp_jj+0.5f)*size[1];
    float s_size_0 = 0.01f*size[0];
    float s_size_1 = 0.01f*size[1];
    //------------------------------------------------------
    do
    {
        GetNikValue(tmpNikVector,KnotVector_u,k_value,para_u,n_value);
        GetNikValue(tmpMjlVector,KnotVector_v,k_value,para_v,m_value);
        
        for(int i = 0 ; i < n_value+1 ; i++)
        {
            
            for(int j = 0 ; j < m_value+1 ; j++)
            {
                float tmpCal =  Convert::ToSingle(tmpNikVector->GetValue(i))*Convert::ToSingle(tmpMjlVector->GetValue(j));
                tmp_u_v_X = tmp_u_v_X + tmpCal*Convert::ToSingle(CotorllPt_X->GetValue(i,j));
                tmp_u_v_Y = tmp_u_v_Y + tmpCal*Convert::ToSingle(CotorllPt_Y->GetValue(i,j));
                tmp_u_v_Z = tmp_u_v_Z + tmpCal*Convert::ToSingle(CotorllPt_Z->GetValue(i,j));
                //tmp_u_v_X = tmp_u_v_X + (Convert::ToSingle(CotorllPt_X->GetValue(i,j))*Convert::ToSingle(tmpNikVector->GetValue(i))*Convert::ToSingle(tmpMjlVector->GetValue(j)));
                //tmp_u_v_Y = tmp_u_v_Y + (Convert::ToSingle(CotorllPt_Y->GetValue(i,j))*Convert::ToSingle(tmpNikVector->GetValue(i))*Convert::ToSingle(tmpMjlVector->GetValue(j)));
                //tmp_u_v_Z = tmp_u_v_Z + (Convert::ToSingle(CotorllPt_Z->GetValue(i,j))*Convert::ToSingle(tmpNikVector->GetValue(i))*Convert::ToSingle(tmpMjlVector->GetValue(j)));
            }
        }
        tmpRatioX = (tmp_u_v_X- c1)*D_plateW;
        tmpRatioY = (tmp_u_v_Y- c2)*D_plateH;
        //避免u,v值跳動
        if(tmpcount > 1000)
        {
            tmpRatioX = tmpRatioX / tmpcount*500;
            tmpRatioY = tmpRatioY / tmpcount*500;
        }
        tmpcount ++;
        if(tmp_u_v_X-dis_x > s_size_0 || tmp_u_v_X-dis_x < -s_size_0 )
        {
            para_u = para_u-(float)tmpRatioX;
        }
        if(tmp_u_v_Y-dis_y > s_size_1 || tmp_u_v_Y-dis_y < -s_size_1 )
        {
            para_v = para_v-(float)tmpRatioY;
        }
    }
    while((tmp_u_v_X>(dis_x + s_size_0) || tmp_u_v_X<(dis_x-s_size_0) || tmp_u_v_Y>(dis_y + s_size_1) || tmp_u_v_Y<(dis_y - s_size_1) )&&(para_u>=0 && para_v>=0 && para_u<=1 && para_v<=1 ));
    SurfacePoint_u_v_X = tmp_u_v_X;
    SurfacePoint_u_v_Y = tmp_u_v_Y;
    SurfacePoint_u_v_Z = tmp_u_v_Z;
    delete KnotVector_u;
    delete tmpNikVector;
    delete KnotVector_v;
    delete tmpMjlVector;
}
void Get_BSplineSurface_Point_New080311(float &SurfacePoint_u_v_X,float &SurfacePoint_u_v_Y,float &SurfacePoint_u_v_Z,array<float,2>^ CotorllPt_X,array<float,2>^ CotorllPt_Y,array<float,2>^ CotorllPt_Z,float para_u,float para_v, int k_value,array<float>^ KnotVector_u,array<float>^ KnotVector_v)
{
    //SurfacePoint_u_v 為在參數u,v時Surface上的點座標
    //CotorllPt        為控制點座標,X,Y,Z
    // Prar_u 描述Surface的參數 ,介於(0~1) ?
    // Prar_v 描述Surface的參數 ,介於(0~1) ?
    // k_value : 階數  ,n_value +1 : u方向控制點數目 , m_value : v方向控制點數目
    //定義兩方向的k_value一樣
    //B-spline曲面數學模式
    //得到 B-Spline曲面上上的某一點 P(u,v) 位置座標
    //Ini數值
    SurfacePoint_u_v_X = 0;
    SurfacePoint_u_v_Y = 0;
    SurfacePoint_u_v_Z = 0;
    //獲得 n_value  , m_value
    int n_value = CotorllPt_X->GetLength(0)-1;
    int m_value = CotorllPt_X->GetLength(1)-1;
    //獲得NikValue(u)
    array<float>^ tmpNikVector = gcnew array<float>(n_value+1);	     //20080310
    //	Array::Resize(tmpNikVector,n_value+1);                          //20080310
    GetNikValue(tmpNikVector,KnotVector_u,k_value,para_u,n_value);
    //獲得MjlValue(v)
    array<float>^ tmpMjlVector = gcnew array<float>(m_value+1);	             //20080310
    //	Array::Resize(tmpMjlVector,m_value+1);                                  //20080310
    GetNikValue(tmpMjlVector,KnotVector_v,k_value,para_v,m_value);
    
    for(int i = 0 ; i < n_value+1 ; i++)
    {
        float tmp_NikValue ;
        tmp_NikValue = Convert::ToSingle(tmpNikVector->GetValue(i));
        if (tmp_NikValue != 0)
        {
            
            for(int j = 0 ; j < m_value+1 ; j++)
            {
                float tmp_MijValue ;
                tmp_MijValue = Convert::ToSingle(tmpMjlVector->GetValue(j));
                if ( tmp_MijValue != 0)
                {
                    SurfacePoint_u_v_X = SurfacePoint_u_v_X + (Convert::ToSingle(CotorllPt_X->GetValue(i,j))*tmp_NikValue*tmp_MijValue);
                    SurfacePoint_u_v_Y = SurfacePoint_u_v_Y + (Convert::ToSingle(CotorllPt_Y->GetValue(i,j))*tmp_NikValue*tmp_MijValue);
                    SurfacePoint_u_v_Z = SurfacePoint_u_v_Z + (Convert::ToSingle(CotorllPt_Z->GetValue(i,j))*tmp_NikValue*tmp_MijValue);
                }
            }
        }
    }
    delete tmpNikVector;
    delete tmpMjlVector;
}
//-----------------------B-Spline    Curve --------------------------------------------------
array<PointF>^ B_Spline_Curve::GetCurve()
{
    return Curve;
}
void B_Spline_Curve::SetKnotVector()
{
    // 開放式均勻節點向量
    //n_value 和 k_value 不得為0
    if( this->rebuildKnotVector == true)
    {
        int n_value = this->ControllPt->Count-1;
        Array::Resize(this->KnotVector,n_value+this->k_value+1);
        
        for(int i =1 ; i<= (n_value+this->k_value+1) ; i++)
        {
            if(1<=i && (i)<= this->k_value)this-> KnotVector->SetValue(0.0f,i-1);
            if(this->k_value+1<=i && (i)<= n_value+1) this->KnotVector->SetValue((float)(i-this->k_value)/(float)(n_value+2-this->k_value),i-1);
            if(n_value+2<=i && (i)<= n_value+this->k_value+1) this->KnotVector->SetValue((float)(n_value+2-this->k_value)/(float)(n_value+2-this->k_value),i-1);
        }
        this->rebuildKnotVector = false;
        this->rebuildNikVector  = true;
    }
}
void B_Spline_Curve::SetNikVectorGroup(int resolution)
{
    if(Curve->Length != resolution)
    {
        Array::Resize(Curve,resolution);
        this->rebuildNikVector = true ;
    }
    if(this->pre_ControllPt_Number != this->ControllPt->Count)
    {
        this->rebuildNikVector = true ;
        this->rebuildKnotVector = true;
        this->pre_ControllPt_Number = this->ControllPt->Count ;
    }
    this->SetKnotVector();
    if( this->rebuildNikVector == true)
    {
        Array::Resize(this->NikVectorGroup,resolution) ;
        
        for(int ii = 0 ; ii <resolution ;ii ++)
        {
            float t = (float)ii/(resolution-1);
            if( t>= 1) t= 0.99999f; //必須Check Paper 的公式
            array<float>^ NikVector = gcnew array<float>(0);
            SetNikVector(t,NikVector);
            this->NikVectorGroup->SetValue(NikVector,ii);
        }
        this->rebuildNikVector = false;
    }
}
void B_Spline_Curve::SetNikVector(float t,array<float>^ &xNikVector)
{
    //正規化的B-spline基底函數
    //k_value 為 階數
    //NiVector的數目 為 n_value + 1
    //KnotVector 的數目 為 n_value + k_value + 1
    //tmpNikVector 為 Previous NiVector
    Array::Resize(xNikVector,this->ControllPt->Count);
    // Modify By Vinshen 2008119 ---修正Nik計算錯誤的問題 ---V 2,0 版之後都用此方法計算
    array<float>^ tmpNikVector = gcnew array<float>(this->ControllPt->Count + this->k_value -1);
    
    for(int k = 1 ; k <= this->k_value ; k++)
    {
        
        for(int i= 0 ; i<(this->ControllPt->Count+ this->k_value-k) ; i++)
        {
            float ui ,ui_1,ui_p,ui_p_1;
            ui = Convert::ToSingle(KnotVector->GetValue(i));
            ui_1 = Convert::ToSingle(KnotVector->GetValue(i+1));
            if( k == 1)
            {
                if (t >= ui && t < ui_1) tmpNikVector->SetValue(1,i);
                
                else tmpNikVector->SetValue(0.0f,i);
            }
            
            else
            {
                float tmpa;
                float tmpb;
                int p_degree = k-1;
                //float ui ,ui_1,ui_p,ui_p_1;
                ui_p = Convert::ToSingle(KnotVector->GetValue(i+p_degree));
                ui_p_1 = Convert::ToSingle(KnotVector->GetValue(i+p_degree+1));
                if((ui_p-ui) == 0) tmpa = 0;
                
                else tmpa = (t-ui)/(ui_p-ui)*Convert::ToSingle(tmpNikVector->GetValue(i));
                if((ui_p_1-ui_1) == 0) tmpb = 0;
                
                else tmpb = (ui_p_1- t)/(ui_p_1-ui_1) *Convert::ToSingle(tmpNikVector->GetValue(i+1));
                tmpNikVector->SetValue( tmpa + tmpb ,i) ;
            }
        }
    }
    
    for(int i= 0 ; i<(this->ControllPt->Count); i++)
    {
        xNikVector->SetValue(tmpNikVector->GetValue(i),i);
    }
}
void B_Spline_Curve::Set_k_Value(int xk_value)
{
    //一但設定n,k value , KnotVector 和 NikVector 大小和數值就有可能變動 ,但 NikVector 必須由 Para t 產生 ,
    // 故這邊變動只是Resize NikVector 大小 ,但會設定 KnotVector 數值和大小
    if (this->k_value !=  xk_value )
    {
        //將參數傳入類別中
        //if (xk_value >= this->ControllPt->Count)  xk_value = this->ControllPt->Count;
        this->k_value = xk_value;
        this->rebuildKnotVector = true;
    }
    /*
    if (this->k_value !=  xk_value )
    {
        Array::Resize(this->KnotVector,this->ControllPt->Count + xk_value);
        //設定KnotVector
        this->SetKnotVector();
    }
    */
}
float B_Spline_Curve::GetCurve_Z_Value(float X,int StartSearchIndex)
{
    PointF CurvePt_1(0,0) ,CurvePt_2(0,0) ;
    int tmpindex = StartSearchIndex;
    CurvePt_1 = (PointF)this->Curve->GetValue(StartSearchIndex);
    CurvePt_2 = (PointF)this->Curve->GetValue(StartSearchIndex+1);
    do
    {
        if(X>Math::Max(CurvePt_1.X,CurvePt_2.X))
        {
            if(CurvePt_2.X >= CurvePt_1.X ) tmpindex = tmpindex +1;
            if(CurvePt_2.X < CurvePt_1.X )  tmpindex = tmpindex -1;
        }
        if(X< Math::Min(CurvePt_1.X,CurvePt_2.X))
        {
            if(CurvePt_2.X >= CurvePt_1.X ) tmpindex = tmpindex -1;
            if(CurvePt_2.X < CurvePt_1.X )  tmpindex = tmpindex +1;
        }
        //表示已經到邊界,取邊界值
        if(tmpindex <=0)
        {
            CurvePt_1 = (PointF)this->Curve->GetValue(0);
            CurvePt_2 = (PointF)this->Curve->GetValue(1);
            break;
        }
        if(tmpindex  >= this->Curve->Length-2)
        {
            CurvePt_1 = (PointF)this->Curve->GetValue(this->Curve->Length-2);
            CurvePt_2 = (PointF)this->Curve->GetValue(this->Curve->Length-1);
            break;
        }
        CurvePt_1 = (PointF)this->Curve->GetValue(tmpindex);
        CurvePt_2 = (PointF)this->Curve->GetValue(tmpindex + 1);
    }
    while (X>Math::Max(CurvePt_1.X,CurvePt_2.X) || X < Math::Min(CurvePt_1.X,CurvePt_2.X));
    return (CurvePt_1.Y + CurvePt_2.Y)/2;
}
void B_Spline_Curve::ReProduceCurve(int xResolution)
{
    if(this->ControllPt->Count >= 2)
    {
        this->SetNikVectorGroup(xResolution);
        
        for(int i = 0 ;i < xResolution ; i++)
        {
            PointF CurvePt(0,0);
            array<float>^ tmp = (array<float>^)this->NikVectorGroup->GetValue(i);
            
            for(int j = 0 ; j <	this->ControllPt->Count ; j++)
            {
                float tmpValue = Convert::ToSingle(tmp->GetValue(j));
                CurvePt.X = CurvePt.X + ControllPt->default[j].X*tmpValue;
                CurvePt.Y = CurvePt.Y + ControllPt->default[j].Y*tmpValue;
            }
            this->Curve->SetValue(CurvePt,i);
        }
    }
}
void B_Spline_Curve::ReProduceCurve(int xResolution,Rectangle xCoordinate_Boundary)
{
    if(this->ControllPt->Count >= 2)
    {
        this->SetNikVectorGroup(xResolution);
        
        for(int i = 0 ;i < xResolution ; i++)
        {
            PointF CurvePt(0,0);
            array<float>^ tmp = (array<float>^)this->NikVectorGroup->GetValue(i);
            
            for(int j = 0 ; j <	this->ControllPt->Count ; j++)
            {
                float tmpValue = Convert::ToSingle(tmp->GetValue(j));
                CurvePt.X = CurvePt.X + ControllPt->default[j].X*tmpValue;
                CurvePt.Y = CurvePt.Y + ControllPt->default[j].Y*tmpValue;
            }
            if (CurvePt.Y >(xCoordinate_Boundary.Height+xCoordinate_Boundary.Y))
            CurvePt.Y = ((float)xCoordinate_Boundary.Height+(float)xCoordinate_Boundary.Y);
            if (CurvePt.Y < xCoordinate_Boundary.Y)
            CurvePt.Y = (float)xCoordinate_Boundary.Y;
            this->Curve->SetValue(CurvePt,i);
        }
    }
}
int B_Spline_Curve::ComapreControllPt(PointF xtmpPt1,PointF xtmpPt2)
{
    if (xtmpPt1.X > xtmpPt2.X)	return 1;
    else if (xtmpPt1.X == xtmpPt2.X)  return 0;
    
    else return -1;
}
int B_Spline_Curve::Get_k_Value()
{
    return this->k_value;
}
void B_Spline_Curve::xInitialize(PointF startPt,PointF endPt)
{
    KnotVector = gcnew array<float>(0);
    NikVectorGroup = gcnew array<array<float>^>(0);
    Curve = gcnew array<PointF>(0);
    //輸入的初始參數
    this->ControllPt =  gcnew List<PointF>(0);
    this->ControllPt->Add(startPt);
    this->ControllPt->Add(endPt);
    k_value = 2 ;
    rebuildKnotVector = true;
    rebuildNikVector = true;
    this->ReProduceCurve(100);
}
PointF TranslateModule::Translate_Pt_From_BSplineCoordinate_To_Screen(PointF^ B_SplinePt,SizeF^ DrawingFrameSize,int Y_Direction_Boundary,int X_Direction_Boundary,float X_Coordinate_Range,float Y_Coordinate_Range)
{
    //Y_Direction_Boundary      : 坐標網格 單側離繪圖視窗的Pixel數(上下邊緣)
    //X_Direction_Boundary : 坐標網格 單側離繪圖視窗的Pixel數(左右邊緣)
    PointF tmpPt;
    tmpPt.X =  B_SplinePt->X/X_Coordinate_Range*(DrawingFrameSize->Width-X_Direction_Boundary*2)+X_Direction_Boundary;
    tmpPt.Y =  -(B_SplinePt->Y/Y_Coordinate_Range*(DrawingFrameSize->Height-Y_Direction_Boundary*2)+Y_Direction_Boundary-DrawingFrameSize->Height);
    return tmpPt;
}
PointF TranslateModule::Translate_Pt_From_Screen_To_BSplineCoordinate(PointF^ ScreenPt,SizeF^ DrawingFrameSize,int Y_Direction_Boundary,int X_Direction_Boundary,float X_Coordinate_Range,float Y_Coordinate_Range)
{
    //Y_Direction_Boundary      : 坐標網格 單側離繪圖視窗的Pixel數(上下邊緣)
    //X_Direction_Boundary : 坐標網格 單側離繪圖視窗的Pixel數(左右邊緣)
    PointF tmpPt;
    tmpPt.X = (ScreenPt->X-X_Direction_Boundary)/(DrawingFrameSize->Width-X_Direction_Boundary*2)*X_Coordinate_Range;
    tmpPt.Y = (DrawingFrameSize->Height- Y_Direction_Boundary-ScreenPt->Y)/(DrawingFrameSize->Height-Y_Direction_Boundary*2)*Y_Coordinate_Range;
    return tmpPt;
}
//----------------------B-Spline    Surface--------------------------------------------------
void B_Spline_Surface::Set_uv_Value(int u_value, int v_value)
{
    //一但設定n,k value , KnotVector 和 NikVector 大小和數值就有可能變動 ,但 NikVector 必須由 Para t 產生 ,
    // 故這邊變動只是Resize NikVector 大小 ,但會設定 KnotVector 數值和大小
    if (this->u_value !=  u_value )
    {
        //將參數傳入類別中
        if (u_value >= this->ControllPt->GetLength(0))  u_value = this->ControllPt->GetLength(0);
        this->u_value = u_value;
        this->BuildKnotVector_u = true;
    }
    if (this->v_value !=  v_value )
    {
        //將參數傳入類別中
        if (v_value >= this->ControllPt->GetLength(1))  v_value = this->ControllPt->GetLength(1);
        this->v_value = v_value;
        this->BuildKnotVector_v = true;
    }
}
void B_Spline_Surface::Get_uv_Value(int &u_value, int &v_value)
{
    u_value = this->u_value;
    v_value = this->v_value;
}
array<float>^ B_Spline_Surface::SetKnotVector(char KnotVector_Type)
{
    // 開放式均勻節點向量
    //n_value 和 k_value 不得為0
    array<float>^ xKnotVector = gcnew array<float>(0);
    int mn_value = 0;
    int uv_value = 0;
    bool execute = false;
    if (KnotVector_Type == 'u')
    {
        mn_value = this->ControllPt->GetLength(0)-1;
        uv_value = this->u_value;
        this->BuildBlendingVector_Nik = true;
        execute = true;
    }
    else if( KnotVector_Type == 'v')
    {
        mn_value = this->ControllPt->GetLength(1)-1;
        uv_value = this->v_value;
        this->BuildBlendingVector_Mjl = true;
        execute = true;
    }
    if (execute == true )
    {
        Array::Resize(xKnotVector,mn_value+ uv_value + 1);
        
        for(int i =1 ; i<= (xKnotVector->Length) ; i++)
        {
            if(1<=i && (i)<= uv_value)                           xKnotVector->SetValue(0.0f,i-1);
            if(uv_value+1<=i && (i)<= mn_value +1)               xKnotVector->SetValue((float)(i-uv_value)/(float)(mn_value+2-uv_value),i-1);
            if(mn_value+2<=i && (i)<= mn_value+uv_value +1)      xKnotVector->SetValue((float)(mn_value+2-uv_value)/(float)(mn_value+2-uv_value),i-1);
        }
        return xKnotVector;
    }
    
    else
    {
        if (KnotVector_Type == 'u') return this->KnotVector_u;
        else if (KnotVector_Type == 'v') return this->KnotVector_v;
        
        else return nullptr;
    }
}
void B_Spline_Surface::SetBlendingVector(float t,array<float>^ &xBlendingVector ,char direction )
{
    //正規化的B-spline基底函數
    //k_value 為 階數
    //NiVector的數目 為 n_value + 1
    //KnotVector 的數目 為 n_value + k_value + 1
    //tmpNikVector 為 Previous NiVector
    int uv_value = 0;
    int ControllPt_number = 0;
    array<float>^ tmpKnotVector;
    if (direction == 'u')
    {
        uv_value = this->u_value;
        ControllPt_number = this->ControllPt->GetLength(0);
        //	this->KnotVector_u = this->SetKnotVector('u');
        tmpKnotVector = this->KnotVector_u;
    }
    else if (direction == 'v')
    {
        uv_value = this->v_value;
        ControllPt_number = this->ControllPt->GetLength(1);
        //	this->KnotVector_v = this->SetKnotVector('v');
        tmpKnotVector = this->KnotVector_v;
    }
    Array::Resize(xBlendingVector,ControllPt_number);
    // Modify By Vinshen 2008119 ---修正Nik計算錯誤的問題 ---V 2,0 版之後都用此方法計算
    array<float>^ tmpNikVector = gcnew array<float>(ControllPt_number + uv_value -1);
    
    for(int k = 1 ; k <= uv_value ; k++)
    {
        
        for(int i= 0 ; i<(ControllPt_number+ uv_value-k) ; i++)
        {
            float ui ,ui_1,ui_p,ui_p_1;
            ui = Convert::ToSingle(tmpKnotVector->GetValue(i));
            ui_1 = Convert::ToSingle(tmpKnotVector->GetValue(i+1));
            if( k == 1)
            {
                if (t >= ui && t < ui_1) tmpNikVector->SetValue(1,i);
                
                else tmpNikVector->SetValue(0.0f,i);
            }
            
            else
            {
                float tmpa;
                float tmpb;
                int p_degree = k-1;
                //float ui ,ui_1,ui_p,ui_p_1;
                ui_p = Convert::ToSingle(tmpKnotVector->GetValue(i+p_degree));
                ui_p_1 = Convert::ToSingle(tmpKnotVector->GetValue(i+p_degree+1));
                if((ui_p-ui) == 0) tmpa = 0;
                
                else tmpa = (t-ui)/(ui_p-ui)*Convert::ToSingle(tmpNikVector->GetValue(i));
                if((ui_p_1-ui_1) == 0) tmpb = 0;
                
                else tmpb = (ui_p_1- t)/(ui_p_1-ui_1) *Convert::ToSingle(tmpNikVector->GetValue(i+1));
                tmpNikVector->SetValue( tmpa + tmpb ,i) ;
            }
        }
    }
    
    for(int i= 0 ; i<(ControllPt_number); i++)
    {
        xBlendingVector->SetValue(tmpNikVector->GetValue(i),i);
    }
}
void B_Spline_Surface::SetBlendingVectorGroup(int resolution ,char BlendVector_Type)
{
    int uv_value =  0;
    int Count = 0 ;
    bool active = false;
    if (BlendVector_Type == 'u' && this->BuildBlendingVector_Nik == true)
    {
        uv_value = this->u_value;
        Count = this->ControllPt->GetLength(0);
        this->BuildBlendingVector_Nik = false;
        active = true;
    }
    else if (BlendVector_Type == 'v' && this->BuildBlendingVector_Mjl == true)
    {
        uv_value = this->v_value;
        Count = this->ControllPt->GetLength(1);
        this->BuildBlendingVector_Mjl = false;
        active = true;
    }
    if (active == true)
    {
        if (BlendVector_Type == 'u') Array::Resize(this->NikVectorGroup,resolution);
        if (BlendVector_Type == 'v') Array::Resize(this->MjlVectorGroup,resolution);
        
        for(int ii = 0 ; ii <resolution ;ii ++)
        {
            float t = (float)ii/(resolution-1);
            if( t>= 1) t= 0.99999f; //必須Check Paper 的公式
            array<float>^ BlendingVector = gcnew array<float>(0);
            this->SetBlendingVector(t,BlendingVector,BlendVector_Type);
            if (BlendVector_Type == 'u') this->NikVectorGroup->SetValue(BlendingVector,ii);
            if (BlendVector_Type == 'v') this->MjlVectorGroup->SetValue(BlendingVector,ii);
        }
    }
}
void B_Spline_Surface::ProduceSurface(int resolution_u ,int resolution_v)
{
    this->KnotVector_u = gcnew array<float>(0);
    this->KnotVector_v = gcnew array<float>(0);
    this->KnotVector_u = this->SetKnotVector('u');
    this->KnotVector_v = this->SetKnotVector('v');
    this->SetBlendingVectorGroup(resolution_u,'u');
    this->SetBlendingVectorGroup(resolution_v,'v');
    this->Surface = gcnew array<PointF,2>(resolution_u,resolution_v);
    this->Surface_Z = gcnew array<float,2>(resolution_u,resolution_v);
    
    for(int i = 0 ;i < resolution_u ; i++)
    {
        array<float>^ tmp0 = (array<float>^)this->NikVectorGroup->GetValue(i);
        
        for(int ii = 0 ;ii< resolution_v ; ii ++)
        {
            PointF SurfacePt(0.0f,0.0f);
            float Surface_Z = 0.0f;
            float TmpValue = 0;
            array<float>^ tmp1 = (array<float>^)this->MjlVectorGroup->GetValue(ii);
            
            for(int j = 0 ; j <	this->ControllPt->GetLength(0) ; j++)
            {
                
                for (int jj = 0 ; jj <this->ControllPt->GetLength(1) ; jj++)
                {
                    float tmpValue0 = Convert::ToSingle(tmp0->GetValue(j));
                    float tmpValue1 = Convert::ToSingle(tmp1->GetValue(jj));
                    PointF tmpControll_Pt = (PointF)(this->ControllPt->GetValue(j,jj));
                    float tmpControll_Pt_Z = Convert::ToSingle(this->ControllPt_Z->GetValue(j,jj));
                    //	SurfacePt.X = SurfacePt.X + tmpControll_Pt.X*tmpValue0*tmpValue1;
                    //	SurfacePt.Y = SurfacePt.Y + tmpControll_Pt.Y*tmpValue0*tmpValue1;
                    //	Surface_Z = Surface_Z +tmpControll_Pt_Z*tmpValue0*tmpValue1;
                    //增加權重
                    SurfacePt.X = SurfacePt.X + Convert::ToSingle(this->Weight->GetValue(j,jj))*tmpControll_Pt.X*tmpValue0*tmpValue1;
                    SurfacePt.Y = SurfacePt.Y + Convert::ToSingle(this->Weight->GetValue(j,jj))*tmpControll_Pt.Y*tmpValue0*tmpValue1;
                    Surface_Z = Surface_Z +Convert::ToSingle(this->Weight->GetValue(j,jj))*tmpControll_Pt_Z*tmpValue0*tmpValue1;
                    TmpValue = TmpValue + Convert::ToSingle(this->Weight->GetValue(j,jj))*tmpValue0*tmpValue1;
                }
            }
            //增加權重........................
            SurfacePt.X = SurfacePt.X/TmpValue;
            SurfacePt.Y = SurfacePt.Y/TmpValue;
            Surface_Z = Surface_Z/TmpValue;
            //---------------------------------
            this->Surface->SetValue(SurfacePt,i,ii);
            this->Surface_Z->SetValue(Surface_Z,i,ii);
            if(i==0 && ii == 0)
            {
                this->SurfaceBoundary.X = SurfacePt.X;
                this->SurfaceBoundary.Y = SurfacePt.Y;
            }
            if(i== resolution_u-1 && ii == resolution_v-1)
            {
                this->SurfaceBoundary.Width = SurfacePt.X-this->SurfaceBoundary.X;
                this->SurfaceBoundary.Height = SurfacePt.Y-this->SurfaceBoundary.Y;
            }
        }
    }
}
void B_Spline_Surface::xInitialize()
{
    this->KnotVector_u = gcnew array<float>(0);
    this->KnotVector_v = gcnew array<float>(0);
    this->NikVectorGroup= gcnew array<array<float>^>(0);
    this->MjlVectorGroup= gcnew array<array<float>^>(0);
    this->ControllPt = gcnew array<PointF,2>(3,3);
    this->ControllPt_Z = gcnew array<float,2>(3,3) ;
    this->Surface = gcnew array<PointF,2>(100,100);
    this->Surface_Z = gcnew array<float,2>(100,100) ;
    this->Set_uv_Value(2,2);
    this->Weight = gcnew array<float,2>(15,15);
    
    for(int ii= 0 ;ii <5 ;ii++)
    {
        
        for(int jj= 0 ;jj <5 ;jj++)
        {
            this->Weight->SetValue(1.0f,ii,jj);
        }
    }
}
void B_Spline_Surface::CopyFrom(B_Spline_Surface^ SourceObj)
{
    //將objSource 物件的Data Copy 到 此物件
    Array::Copy(SourceObj->ControllPt,this->ControllPt,0);
    Array::Copy(SourceObj->ControllPt_Z,this->ControllPt_Z,0);
    Array::Copy(SourceObj->Surface,this->Surface,0);
    Array::Copy(SourceObj->Surface_Z,this->Surface_Z,0);
    Array::Copy(SourceObj->KnotVector_u,this->KnotVector_u,0);
    Array::Copy(SourceObj->KnotVector_v,this->KnotVector_v,0);
    Array::Copy(SourceObj->NikVectorGroup,this->NikVectorGroup,0);
    Array::Copy(SourceObj->MjlVectorGroup,this->MjlVectorGroup,0);
    this->u_value = SourceObj->u_value;
    this->v_value = SourceObj->v_value;
    this->BuildBlendingVector_Nik = SourceObj->BuildBlendingVector_Nik;
    this->BuildBlendingVector_Mjl = SourceObj->BuildBlendingVector_Mjl;
    this->BuildKnotVector_u = SourceObj->BuildKnotVector_u;
    this->BuildKnotVector_v = SourceObj->BuildKnotVector_u;
}
float B_Spline_Surface::GetSurface_Z_Value(float X_Location, float Y_Location,int IniIndexX,int IniIndexY)
{
    float tmpZ_pre;
    float boundaryX0 ,boundaryX1 ,boundaryY0 ,boundaryY1;
    PointF LU(0,0), LD(0,0) , RU(0,0) ,RD(0,0);
    int tmpX,tmpY;
    tmpX = IniIndexX;
    tmpY = IniIndexY;
    do
    {
        LU = (PointF)(this->Surface->GetValue(tmpX,tmpY));
        LD = (PointF)(this->Surface->GetValue(tmpX,tmpY+1));
        RU = (PointF)(this->Surface->GetValue(tmpX+1,tmpY));
        RD = (PointF)(this->Surface->GetValue(tmpX+1,tmpY+1));
        //找出邊界
        boundaryX0 = Math::Min(Math::Min(LU.X,LD.X),Math::Min(RU.X,RD.X));
        boundaryX1 = Math::Max(Math::Max(LU.X,LD.X),Math::Max(RU.X,RD.X));
        boundaryY0 = Math::Min(Math::Min(LU.Y,LD.Y),Math::Min(RU.Y,RD.Y));
        boundaryY1 = Math::Max(Math::Max(LU.Y,LD.Y),Math::Max(RU.Y,RD.Y));
        if((tmpX == 0 || tmpX == this->Surface->GetLength(0)-2) && boundaryY0 <= Y_Location && boundaryY1 >= Y_Location)
        {
            //			//表示已經到邊界 ,取最近值
            //			MessageBox::Show("有點在邊界外 ,取最近值 !!");
            break;
        }
        if((tmpY == 0 || tmpY == this->Surface->GetLength(1)-2) && boundaryX0 <= X_Location && boundaryX1 >= X_Location)
        {
            //表示已經到邊界 ,取最近值
            //			MessageBox::Show("有點在邊界外 ,取最近值 !!");
            break;
        }
        if((tmpY == 0 || tmpY == this->Surface->GetLength(1)-2) && (tmpX == 0 || tmpX == this->Surface->GetLength(0)-2))
        {
            //表示已經到邊界 ,取最近值
            break;
        }
        if( boundaryX0 < X_Location  && boundaryX1 < X_Location)
        {
            if(RU.X>=LU.X)	tmpX = tmpX + 1;
            if(RU.X<LU.X)   tmpX = tmpX - 1;
        }
        else if ( boundaryX0 > X_Location  && boundaryX1 > X_Location)
        {
            if(RU.X>=LU.X)	tmpX = tmpX - 1;
            if(RU.X<LU.X)   tmpX = tmpX + 1;
        }
        if( boundaryY0 < Y_Location  && boundaryY1 < Y_Location)
        {
            if(LD.Y>=LU.Y)	tmpY = tmpY + 1;
            if(LD.Y<LU.Y)   tmpY = tmpY - 1;
        }
        else if ( boundaryY0 > Y_Location  && boundaryY1 > Y_Location)
        {
            if(LD.Y>=LU.Y)	tmpY = tmpY - 1;
            if(LD.Y<LU.Y)   tmpY = tmpY + 1;
        }
        if (tmpX <0)  tmpX = 0;
        if (tmpY <0)  tmpY = 0;
        if (tmpX >=this->Surface->GetLength(0)-2)  tmpX = this->Surface->GetLength(0)-2;
        if (tmpY >=this->Surface->GetLength(1)-2)  tmpY = this->Surface->GetLength(1)-2;
    }
    while  (boundaryX0 > X_Location || boundaryX1 < X_Location || boundaryY0 > Y_Location || boundaryY1 < Y_Location) ;
    //空間平面求點_1
    float LU_Z = Convert::ToSingle(this->Surface_Z->GetValue(tmpX,tmpY));
    float LD_Z = Convert::ToSingle(this->Surface_Z->GetValue(tmpX,tmpY+1));
    float RU_Z = Convert::ToSingle(this->Surface_Z->GetValue(tmpX+1,tmpY));
    float RD_Z = Convert::ToSingle(this->Surface_Z->GetValue(tmpX+1,tmpY+1));
    tmpZ_pre = (LU_Z + LD_Z + RU_Z + RD_Z)/4;
    return tmpZ_pre;
}
float B_Spline_Surface::GetSurface_Z_Value(float X_Location, float Y_Location)
{
    float tmpZ_pre;
    float boundaryX0 ,boundaryX1 ,boundaryY0 ,boundaryY1;
    PointF LU(0,0), LD(0,0) , RU(0,0) ,RD(0,0);
    int tmpX,tmpY;
    //tmpX ,tmpY 的初始值 <暫時>...
    tmpX = (int)(this->Surface->GetLength(0))/2;
    tmpY = (int)(this->Surface->GetLength(1))/2;
    do
    {
        LU = (PointF)(this->Surface->GetValue(tmpX,tmpY));
        LD = (PointF)(this->Surface->GetValue(tmpX,tmpY+1));
        RU = (PointF)(this->Surface->GetValue(tmpX+1,tmpY));
        RD = (PointF)(this->Surface->GetValue(tmpX+1,tmpY+1));
        //找出邊界
        boundaryX0 = Math::Min(Math::Min(LU.X,LD.X),Math::Min(RU.X,RD.X));
        boundaryX1 = Math::Max(Math::Max(LU.X,LD.X),Math::Max(RU.X,RD.X));
        boundaryY0 = Math::Min(Math::Min(LU.Y,LD.Y),Math::Min(RU.Y,RD.Y));
        boundaryY1 = Math::Max(Math::Max(LU.Y,LD.Y),Math::Max(RU.Y,RD.Y));
        if((tmpX == 0 || tmpX == this->Surface->GetLength(0)-2) && boundaryY0 <= Y_Location && boundaryY1 >= Y_Location)
        {
            //表示已經到邊界 ,取最近值
            break;
        }
        if((tmpY == 0 || tmpY == this->Surface->GetLength(1)-2) && boundaryX0 <= X_Location && boundaryX1 >= X_Location)
        {
            //表示已經到邊界 ,取最近值
            break;
        }
        if((tmpY == 0 || tmpY == this->Surface->GetLength(1)-2) && (tmpX == 0 || tmpX == this->Surface->GetLength(0)-2))
        {
            //表示已經到邊界 ,取最近值
            break;
        }
        if( boundaryX0 < X_Location  && boundaryX1 < X_Location)
        {
            if(RU.X>=LU.X)	tmpX = tmpX + 1;
            if(RU.X<LU.X)   tmpX = tmpX - 1;
        }
        else if ( boundaryX0 > X_Location  && boundaryX1 > X_Location)
        {
            if(RU.X>=LU.X)	tmpX = tmpX - 1;
            if(RU.X<LU.X)   tmpX = tmpX + 1;
        }
        if( boundaryY0 < Y_Location  && boundaryY1 < Y_Location)
        {
            if(LD.Y>=LU.Y)	tmpY = tmpY + 1;
            if(LD.Y<LU.Y)   tmpY = tmpY - 1;
        }
        else if ( boundaryY0 > Y_Location  && boundaryY1 > Y_Location)
        {
            if(LD.Y>=LU.Y)	tmpY = tmpY - 1;
            if(LD.Y<LU.Y)   tmpY = tmpY + 1;
        }
        if (tmpX <0)  tmpX = 0;
        if (tmpY <0)  tmpY = 0;
        if (tmpX >=this->Surface->GetLength(0)-2)  tmpX = this->Surface->GetLength(0)-2;
        if (tmpY >=this->Surface->GetLength(1)-2)  tmpY = this->Surface->GetLength(1)-2;
    }
    while  (boundaryX0 > X_Location || boundaryX1 < X_Location || boundaryY0 > Y_Location || boundaryY1 < Y_Location) ;
    //空間平面求點_1
    float LU_Z = Convert::ToSingle(this->Surface_Z->GetValue(tmpX,tmpY));
    float LD_Z = Convert::ToSingle(this->Surface_Z->GetValue(tmpX,tmpY+1));
    float RU_Z = Convert::ToSingle(this->Surface_Z->GetValue(tmpX+1,tmpY));
    float RD_Z = Convert::ToSingle(this->Surface_Z->GetValue(tmpX+1,tmpY+1));
    tmpZ_pre = (LU_Z + LD_Z + RU_Z + RD_Z)/4;
    /*
    float A1C_x,A1C_y,A1C_z,B_x,B_y,B_z,C_x,C_y,C_z,Target_x,Target_y ; //平面一
    A1C_x =RD.X - LU.X ;
    A1C_y =RD.Y - LU.Y ;
    A1C_z =RD_Z - LU_Z ;
    B_x =RU.X - LU.X ;
    B_y =RU.Y - LU.Y ;
    B_z =RU_Z - LU_Z ;
    C_x =LD.X-LU.X ;
    C_y =LD.Y-LU.Y ;
    C_z =LD_Z - LU_Z ;
    Target_x =X_Location - LU.X ;
    Target_y =Y_Location - LU.Y ;
    float	temp_z1 = Target_x*A1C_y - A1C_x*Target_y;
    float	temp_z2 = B_x*A1C_y - A1C_x*B_y;
    if(temp_z1*temp_z2  >= 0)
    {
        //表示點在B 和 A1_C 的平面區  , [= 0 表示 點在交線上]
        float VecX = 0,VecY = 0,VecZ = 0 ;
        Cross(VecX,VecY,VecZ,B_x,B_y,B_z,A1C_x,A1C_y,A1C_z);
        tmpZ_pre = -(VecX*(X_Location-LU.X)+VecY*(Y_Location-LU.Y))/VecZ +LU_Z;
    }
    else if (temp_z1*temp_z2  < 0)
    {
        //表示點在C 和 A1_C 的平面區
        float VecX = 0,VecY = 0,VecZ = 0 ;
        Cross(VecX,VecY,VecZ,C_x,C_y,C_z,A1C_x,A1C_y,A1C_z);
        tmpZ_pre = -(VecX*(X_Location-LU.X)+VecY*(Y_Location-LU.Y))/VecZ +LU_Z;
    }
    */
    return tmpZ_pre;
}
