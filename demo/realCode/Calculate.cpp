
#include "stdafx.h"
#include "Calculate.h"
#include <math.h>
#include <stdio.h>
#include <complex>
#include <algorithm>
//#include "BaseDefinitions.h"


using namespace System;
using namespace System::Diagnostics;
using namespace System::Collections;
using namespace DensityClass;



bool CalculateGridMeshDensity(int CurveType ,float PenPara , float &density ,float distance ,float Boundarydistance ){
	switch (CurveType){
		case 1:
			density = (cos(distance/Boundarydistance*3.1415926f) + 1.0f)*(PenPara-density)/2.0f + density;
			break;
		case 2:
			density = (distance/Boundarydistance)*(PenPara-density) + density;
			break;
		case 3:			
			density = PenPara;
			break;
	}



	return true;
}

void BulidMeshRelation(MeshGrid *mg,DataInput inputdata,float VerlertFactor,deque<int> *relationMeshGrid){

	if (mg != nullptr){
		for(int i =0; i<inputdata.MeshNumber[0]*inputdata.MeshNumber[1]; i++){
			float properdist = (2*inputdata.PatternRadius+inputdata.Pattern_Space)*mg[i].DividSqrtDensity;	
			float tmpdata = VerlertFactor*properdist;
			float *Pos_I;
			float *Size;
			Pos_I = mg[i].GetMeshPosition();
			Size = mg[i].GetMeshSize();
			relationMeshGrid[i].clear();
			for(int j =0; j<inputdata.MeshNumber[0]*inputdata.MeshNumber[1]; j++){
				if(i != j){
					float *Pos_J;					
					Pos_J = mg[j].GetMeshPosition();
					if (fabs(Pos_J[0]-Pos_I[0])<=tmpdata && fabs(Pos_J[1]-Pos_I[1])<=tmpdata){
						//將Relation資料加入
						relationMeshGrid[i].push_back(j);
					}
				}
			}
		}
	}
}
void CalculatePtNumberInMash(MeshGrid *mg,Point3d *pt,DataInput inputdata,long NR ,bool& flagReCalActDen){

	if (mg != nullptr){
		for(int i =0; i<inputdata.MeshNumber[0]*inputdata.MeshNumber[1]; i++){	
			mg[i].PtNumbers = 0;
		};
		for(int j=0;j<NR;j++){
			double px,py,pz;
			pt[j].GetPointPosition(px,py,pz);
			for(int i=0;i<inputdata.MeshNumber[0]*inputdata.MeshNumber[1];i++){
				float *pos;
				float *size;	
				pos = mg[i].GetMeshPosition();
				size = mg[i].GetMeshSize();
				if (px+inputdata.PatternRadius>=pos[0] && px+inputdata.PatternRadius <= (pos[0]+size[0]) && py+inputdata.PatternRadius>=pos[1] && py+inputdata.PatternRadius<=(pos[1]+size[1])){				
					mg[i].PtNumbers ++;
					break;
				}
			}
		}
		flagReCalActDen = false;
	}		

}


void VerifyPtInMeshIndex(Point3d &pt,MeshGrid *mg,int MeshSize,float PatternRadius){
	
	double px,py,pz;
	pt.GetPointPosition(px,py,pz);
	for(int i=0;i<MeshSize;i++){
		float *pos;
		float *size;	
		pos = mg[i].GetMeshPosition();
		size = mg[i].GetMeshSize();
		if (px+PatternRadius>=pos[0] && px+PatternRadius <= (pos[0]+size[0]) && py+PatternRadius>=pos[1] && py+PatternRadius<=(pos[1]+size[1])){
			pt.SetMeshIndex(i);
			mg[i].PtNumbers ++;
			break;
		}
	}

}

void TwoPointForce_Morse(Point3d &p1,Point3d p2,double properdistance){

	double Rij[2];
    Force f;
	double distance ;
	Rij[0] = p1.X-p2.X;
	Rij[1] = p1.Y-p2.Y;
	distance = sqrt(power_2(Rij[0])+power_2(Rij[1]));
	f.Fx =(float)(Rij[0]/distance*(exp(-2*1*(distance-properdistance)) - exp(-1*(distance-properdistance))));
	f.Fy =(float)(Rij[1]/distance*(exp(-2*1*(distance-properdistance)) - exp(-1*(distance-properdistance))));
	f.Fz = 0;
	p1.AddForce(f);
};
void TwoPointForce(double K,double Radius,Point3d &p1,Point3d &p2,int shape,double properdistance,bool Verlert){
	
	double Bij,Rij[2];
	double x1,y1,z1;
	double x2,y2,z2;
	K = 1;
	p1.GetPointPosition(x1,y1,z1);
	p2.GetPointPosition(x2,y2,z2);
	Rij[0] = x1-x2;
	Rij[1] = y1-y2;
	if (shape == 0)
		Bij = fabs(K*properdistance*sqrt((power_2(Rij[0]) + power_2(Rij[1]))/(power_2(K)*power_2(Rij[0])+power_2(Rij[1]))));
	else
		Bij = max(fabs(Rij[0]),fabs(Rij[1])/K);
		

	Force f;
	double distance = sqrt(power_2(Rij[0])+power_2(Rij[1]));
	
	if (Bij >=properdistance && distance != 0){		
		//Assume L =2D
			f.Fx = (float)(Rij[0]/distance*exp(-(distance-Bij)/(0.2f*properdistance)));
			f.Fy = (float)(Rij[1]/distance*exp(-(distance-Bij)/(0.2f*properdistance)));

		f.Fz = 0;
	}
	else{

		if (distance != 0) {
			f.Fx =(float)( Rij[0]/distance);
			f.Fy =(float)( Rij[1]/distance);

		}else{
			f.Fx = 0.0f;
			f.Fy = 0.0f;
		}

		f.Fz = 0;

	}

	p1.AddForce(f);
	f.Fx = -f.Fx;
	f.Fy = -f.Fy;

	if (Verlert == true) p2.AddForce(f);

};


void MoveDistance(double C ,double t,Point3d &pt){

	//計算移動的距離


	double px,py,pz;
	Force f;
	pt.GetPointPosition(px,py,pz);
	pt.GetForce(f);
	px = px + t/C*f.Fx;
	py = py + t/C*f.Fy;	
	pt.SetPointPosition(px,py,pz);

};

void ProduceLDSPattern(MeshGrid *mesh,Point3d *pt,int MeshGrid,int PtNumber){
    

	double sum =0;
	for(int i=0;i<MeshGrid;i++){
		sum = sum + mesh[i].GetPatternDensityinMesh();
	}
	double *ratio = new double[MeshGrid];
	for(int i=0;i<MeshGrid;i++){
		ratio[i] = mesh[i].GetPatternDensityinMesh()/sum;
	}
	for(int i=0;i<PtNumber;i++){
		double px,py,pz =0;
		pt[i].GetPointPosition(px,py,pz);
		
			double sumK=0;
			for(int k=0;k<MeshGrid;k++){
				double tempK;
				tempK = sumK;
				sumK = sumK + ratio[k];
				if (pz >=tempK && pz < sumK){
					float *pos =0;
					float *size =0;
					pos = mesh[k].GetMeshPosition();
					size = mesh[k].GetMeshSize();
					px =pos[0]+size[0]*px;
					py =pos[1]+size[1]*py;
					pt[i].SetPointPosition(px,py,pz);
					pt[i].SetMeshIndex(k);
					mesh[k].PtNumbers ++;
					break;
				}
			}
	
	}

	delete[] ratio;

};


void RapidDynamicsMode(int MeshSize ,long NR ,Point3d *pt ,MeshGrid *mg ,float PatternRadius , 
					   float K , float C , int &overlapnumber , int &actualnumber,float PlateH ,
					   float PlateW ,float BoundaryDist[4],float PatternSpace){

	//區塊運算 (May Lost Data)

	deque<int> vec1;
	deque<int> vec2;	
	int OverlapNumber=0;	
	double properdist;
	

	for(int ii =0 ;ii<MeshSize ;ii++){
		int count =0;	
		for(int j=0;j<NR ;j++){
			if(pt[j].GetMeshIndex() == ii){
				count ++;
				 vec2.push_back(j);
			}			
		}
		vec1.push_back(count);
	}
		

	int prenumber = 0;
	for(int i=0;i<MeshSize;i++){
		
		for(int j= 0; j<vec1.at(i);j++){
			
			int index1 = vec2.at(j+prenumber);
			pt[index1].IniForce();
			double px1,py1,pz1;
			pt[index1].GetPointPosition(px1,py1,pz1);
			for(int k=0;k<vec1.at(i);k++){
				int index2 = vec2.at(k+prenumber);
				double px2,py2,pz2;
				pt[index2].GetPointPosition(px2,py2,pz2);
				double dx ,dy;
				dx =fabs(px1-px2);
				dy =fabs(py1-py2);	
				int pt1index = pt[index1].GetMeshIndex();
				int pt2index = pt[index2].GetMeshIndex();
			//	if((index1!=index2) && (dx<2*PatternRadius) && (dy<2*PatternRadius)&& (pt1index != -1) && (pt2index != -1)){	
			//		OverlapNumber ++;
			//	}
			//	double tempdensity= mg[i].GetPatternDensityinMesh();
				if (mg[i].SqrtDensity >0.00001)	properdist = 2*PatternRadius*mg[i].DividSqrtDensity;	
				else	properdist = 2000*PatternRadius;
				//properdist = 2*PatternRadius/sqrt(tempdensity);
				if ((index1!=index2) && (dx<1.5*properdist && dy<1.5*properdist))
						TwoPointForce(K,PatternRadius,pt[index1],pt[index2] ,0,properdist,false);	

			}
			
		}
		prenumber = prenumber +vec1.at(i);
		
	}

	//if (OverlapNumber != 0){
	actualnumber = NR;
	for(int i=0;i<NR;i++){		
		MoveDistance(C,0.001,pt[i]);
		double px,py,pz;
		pt[i].GetPointPosition(px,py,pz);
		float *pos;
		float *size;

		pos =mg[pt[i].GetMeshIndex()].GetMeshPosition();
		size = mg[pt[i].GetMeshIndex()].GetMeshSize();
		
		if (((px+2*PatternRadius >= pos[0]+size[0]) || (px <= pos[0]) || (py+2*PatternRadius >= pos[1]+size[1]) || (py <= pos[1]))== true){
	//			pt[i].SetMeshIndex(-1);				
		}
		else if(((px+2*PatternRadius >= PlateW-BoundaryDist[3]) || (px <= BoundaryDist[2]) || (py+2*PatternRadius >= PlateH-BoundaryDist[1]) || (py <= BoundaryDist[0]))== true)
		{
	//			pt[i].SetMeshIndex(-1);
		}
		else{

				VerifyPtInMeshIndex(pt[i],mg,MeshSize,PatternRadius);
		}
		if (pt[i].GetMeshIndex() == -1){
			actualnumber --;
		}

	}
	//}
	
	
	overlapnumber = OverlapNumber/2;
	vec2.clear();

};









void NormalDynamicsMode(int MeshSize ,long NR ,Point3d *pt ,MeshGrid *mg,float PatternRadius , 
					   float K , float C , int &overlapnumber, int &actualnumber ,float PlateH ,
					   float PlateW ,float BoundaryDist[4],float PatternSpace){

  
	


	

	 
	
	int OverlapNumber=0;
	double properdist;
	double sumdensity = 0;
	for(int i=0 ; i<MeshSize;i++){
		sumdensity = sumdensity+mg[i].GetPatternDensityinMesh();
	}
	for(int i=0;i<NR;i++){

		pt[i].IniForce();
		double px1,py1,pz1;
		pt[i].GetPointPosition(px1,py1,pz1);
		int pt1index = pt[i].GetMeshIndex();
		if (pt1index != -1){
		//	double tempdensity= mg[pt1index].GetPatternDensityinMesh();
	//		if (tempdensity >0.00001)	properdist = pow(NR*tempdensity/sumdensity,0.3)*(2*PatternRadius+PatternSpace)/sqrt(tempdensity);	
	//		else	properdist = 2000*(PatternRadius+PatternSpace);
			if (mg[pt1index].SqrtDensity >0.00001)	properdist =(2*PatternRadius+PatternSpace)*mg[pt1index].DividSqrtDensity;	
			else	properdist = 2000*(PatternRadius+PatternSpace);


			for(int j= 0;j<NR ;j++){
				if ( pt[j].GetMeshIndex() != -1){
				//	if ( pt[j].GetMeshIndex() == pt1index){
					double px2,py2,pz2;				
					pt[j].GetPointPosition(px2,py2,pz2);
					double dx ,dy;
					dx =fabs(px1-px2);//*Width ;
					dy =fabs(py1-py2);//*Height ;						
					int pt2index = pt[j].GetMeshIndex();					
				
//*
					if ((i!=j) && (dx<3*properdist && dy<3*properdist)) { // 相當於截斷半徑
						TwoPointForce(K,PatternRadius,pt[i],pt[j] ,0,properdist,false);	
						//TwoPointForce_Morse(pt[i],pt[j],properdist);
					};
//*/					
				}

		
			}
			
		}

	}
	




	///*
	actualnumber = NR;
	for(int i=0;i<NR;i++){		
		MoveDistance(C,0.0001,pt[i]);
		//VerifyPtInMeshIndex(pt[i],mg,MeshSize);
		Force f;
		pt[i].GetForce(f);
		//pt[i].Velocity_X = 0;
		//pt[i].Velocity_Y = 0;
		//pt[i].Velocity_X = pt[i].Velocity_X + 0.05*1/C*f.Fx;
		//pt[i].Velocity_Y = pt[i].Velocity_Y + 0.05*1/C*f.Fx;
		VerifyPtInMeshIndex(pt[i],mg,MeshSize,PatternRadius);

		//IsolateBoundaryCondition(pt[i],mg,MeshSize,NR,PlateW,PlateH,PatternRadius);
	
	//	double px,py,pz;
	//	pt[i].GetPointPosition(px,py,pz);		
	//	if (((px+2*PatternRadius >= PlateW-BoundaryDist[3]) || (px <= BoundaryDist[2]) || (py+2*PatternRadius >= PlateH-BoundaryDist[1]) || (py <= BoundaryDist[0]))== true){
	//			pt[i].SetMeshIndex(-1);
	//	}
	//	else{
	//			VerifyPtInMeshIndex(pt[i],mg,MeshSize);
	//	}
	//	if (pt[i].GetMeshIndex() == -1){
	//		actualnumber --;
	//	}
	
				
	}
	//*/


	overlapnumber = OverlapNumber/2;


};
///*
//void VerlertDynamicsMode(int MeshSize ,long NR ,Point3d *pt ,MeshGrid *mg ,float PatternRadius ,
//						 float K , float C , int &overlapnumber , int &actualnumber , float VerlertFactor
//						 , bool ReConstrct ,vector<int> &vec1 ,vector<int> &vec2 ,vector<int> &sortvec
//						 ,float PlateH , float PlateW ,float BoundaryDist[4],float PatternSpace ){
void VerlertDynamicsMode(int MeshSize ,long NR ,Point3d *pt ,MeshGrid *mg ,float PatternRadius ,
						 float K , float C , int &overlapnumber , int &actualnumber , float VerlertFactor
						 , bool ReConstrct ,deque<int> *relationPt
						 ,float PlateH , float PlateW ,float BoundaryDist[4],float PatternSpace ){


	//Verlert 表列法
	int OverlapNumber=0;
	double properdist;
	

	if (ReConstrct == true){
	
	


		//使用Normal 方式

		
		//*
		for(int i=0;i<NR;i++){	
			
			double px1,py1,pz1;
		
		
			if (mg[pt[i].GetMeshIndex()].SqrtDensity >0.00001)	properdist = (2*PatternRadius+PatternSpace)*mg[pt[i].GetMeshIndex()].DividSqrtDensity;	
			else	properdist = 2000*(PatternRadius+PatternSpace);
			pt[i].GetPointPosition(px1,py1,pz1);			

			relationPt[i].clear();
		
			
			double tmpdata = VerlertFactor*properdist;
			int count = 0;
			for(int j= i;j<NR ;j++){
				
					double px2,py2,pz2;				
					pt[j].GetPointPosition(px2,py2,pz2);
					double dx ,dy;
					dx =fabs(px1-px2);
					dy =fabs(py1-py2);								

					if ((dx<tmpdata && dy<tmpdata)){
					//	if (count < 200){
					//		relationPt[i][count] = j;
					//	}
					//	else{
							relationPt[i].push_back(j);
					//	}
						count ++;
					}

			}
			pt[i].RelationPtNumber = count;
							
		}
	
	}

	
	//初始化
	for(int i= 0; i<NR;i++){
		pt[i].IniForce();
	}

	//進行分子動力學移動(與Normal搭配使用)


	for(int i= 0; i<NR;i++){

		
		if (mg[pt[i].GetMeshIndex()].SqrtDensity >0.00001)	properdist = (2*PatternRadius+PatternSpace)*mg[pt[i].GetMeshIndex()].DividSqrtDensity;	
		else	properdist = 2000*(PatternRadius+PatternSpace);

		for(int j =0 ;j< pt[i].RelationPtNumber;j++){	
		//for(int j =0 ;j< relationPt[i].size() ;j++){												
			TwoPointForce(K,PatternRadius,pt[i],pt[relationPt[i].at(j)] ,0,properdist,true);	
	
		};

	};


	actualnumber = NR;
	for(int i=0;i<NR;i++){		
		MoveDistance(C,0.001,pt[i]);
		VerifyPtInMeshIndex(pt[i],mg,MeshSize,PatternRadius);
	};

	overlapnumber = OverlapNumber/2;
	
	
};
/*
void VerlertDynamicsMode(int MeshSize ,long NR ,Point3d *pt ,MeshGrid *mg ,float PatternRadius ,
						 float K , float C , int &overlapnumber , int &actualnumber , float VerlertFactor
						 , bool ReConstrct ,deque<int> &vec1 ,deque<int> &vec2 ,deque<int> &sortvec
						 ,float PlateH , float PlateW ,float BoundaryDist[4],float PatternSpace ){


	//Verlert 表列法
	int OverlapNumber=0;
	double properdist;
	

	if (ReConstrct == true){
		// 排序
		/*
		
		
	
		Array^ Pt_X = Array::CreateInstance(double::typeid,(int)NR);
		Array^ Pt_Index = Array::CreateInstance(int::typeid,(int)NR);
		


		for(int i = 0;i<NR;i++){		
			//Pt_Y->SetValue(pt[i].Y,i);
			Pt_X->SetValue(pt[i].X,i);
			Pt_Index->SetValue(i,i);
		}

		Array::Sort(Pt_X,Pt_Index);
		int currentIndex = 0;
		int tmp = 0;
		int count = 0;
		for(int arrayindex=0;arrayindex< NR ;arrayindex++){
			int oriIndex  = Convert::ToInt32(Pt_Index->GetValue(arrayindex)); //Pt[i] 的 i值	
			sortvec.push_back(oriIndex);
			tmp = arrayindex;
			count = 0;
			if (mg[pt[oriIndex].GetMeshIndex()].SqrtDensity >0.00001)	properdist = (2*PatternRadius+PatternSpace)/mg[pt[oriIndex].GetMeshIndex()].SqrtDensity;	
			else	properdist = 2000*(PatternRadius+PatternSpace);
			
			
			do{
				currentIndex = Convert::ToInt32(Pt_Index->GetValue(tmp));
				if(fabs(pt[currentIndex].Y-pt[oriIndex].Y) < VerlertFactor*properdist && currentIndex != oriIndex ){
					vec2.push_back(currentIndex);
					count ++;
				}
				tmp ++;	
				currentIndex = Convert::ToInt32(Pt_Index->GetValue(tmp));
			}while(fabs(pt[currentIndex].X-pt[oriIndex].X) < VerlertFactor*properdist && tmp < (NR));
							
			vec1.push_back(count);	


			
		}
		delete Pt_X;
		delete Pt_Index;
		//*/
		



		//使用Normal 方式

		
		/*
		for(int i=0;i<NR;i++){	
			
			double px1,py1,pz1;
			int count = 0;
		
			if (mg[pt[i].GetMeshIndex()].SqrtDensity >0.00001)	properdist = (2*PatternRadius+PatternSpace)/mg[pt[i].GetMeshIndex()].SqrtDensity;	
			else	properdist = 2000*(PatternRadius+PatternSpace);
			pt[i].GetPointPosition(px1,py1,pz1);			

			for(int j= i;j<NR ;j++){
				
					double px2,py2,pz2;				
					pt[j].GetPointPosition(px2,py2,pz2);
					double dx ,dy;
					dx =fabs(px1-px2);
					dy =fabs(py1-py2);								

					if ((dx<VerlertFactor*properdist && dy<VerlertFactor*properdist)){
					//if ((i< j) && (dx<VerlertFactor*properdist && dy<VerlertFactor*properdist)){
						int a = vec2.size();
						int b = vec2.max_size();
						if (vec2.size() < 100000000){
		
							vec2.push_back(j);
							count ++;
							
						}
					}

			}
			
									
			vec1.push_back(count);			
		}
		//*/
//	}

	
	//初始化
//	for(int i= 0; i<NR;i++){
//		pt[i].IniForce();
//	}

	//進行分子動力學移動(與Normal搭配使用)
	//*
//	int prenumber = 0;
//	for(int i= 0; i<NR;i++){

		
//		if (mg[pt[i].GetMeshIndex()].SqrtDensity >0.00001)	properdist = (2*PatternRadius+PatternSpace)/mg[pt[i].GetMeshIndex()].SqrtDensity;	
//		else	properdist = 2000*(PatternRadius+PatternSpace);
		
		//*
//		for(int j =0 ;j< vec1.at(i) ;j++){									
//			int index = vec2.at(prenumber + j);
//			TwoPointForce(K,PatternRadius,pt[i],pt[index] ,0,properdist,true);	
	
//		};
		//*/
		
//		prenumber = prenumber + vec1.at(i);
		

//	};
//	//*/
//
//	//進行分子動力學移動(與排序搭配使用)
//	/*
//	int prenumber = 0;
//	for(int i=0 ; i<NR ; i++){
//		int oriIndex = sortvec.at(i);
//
//		if (mg[pt[oriIndex].GetMeshIndex()].SqrtDensity >0.00001)	properdist = (2*PatternRadius+PatternSpace)/mg[pt[oriIndex].GetMeshIndex()].SqrtDensity;	
//		else	properdist = 2000*(PatternRadius+PatternSpace);
//		
//		
//		for(int j =0 ;j< vec1.at(i) ;j++){									
//			int index = vec2.at(prenumber + j);
//			TwoPointForce(K,PatternRadius,pt[oriIndex],pt[index] ,0,properdist,true);	
//	
//		};
//		
//		prenumber = prenumber + vec1.at(i);
//
//
//	}
//	
//	//*/

	//*
//	actualnumber = NR;
//	for(int i=0;i<NR;i++){		
//		MoveDistance(C,0.001,pt[i]);
//		VerifyPtInMeshIndex(pt[i],mg,MeshSize,PatternRadius);
//	};
	//*/

	
	
	
//	overlapnumber = OverlapNumber/2;
	



//};
//*/
/*
void IsolateBoundaryCondition(Point3d &pt,MeshGrid *mg,int MeshSize,long NR ,float PlateW ,float PlateH,float PatternRadius ){
	//絕熱璧邊界條件
	//*
	//---------------------------_______________________---------------------------------------------------------------------
	//---------------------------|o ->              <- o|--------------------------------------------------------------------
	//---------------------------|o ->              <- o|--------------------------------------------------------------------
	//---------------------------|o ->              <- o|--------------------------------------------------------------------
	//---------------------------|o ->     or       <- o|--------------------------------------------------------------------
	//---------------------------|o ->              <- o|--------------------------------------------------------------------
	//---------------------------|o ->              <- o|--------------------------------------------------------------------
    //---------------------------________________________--------------------------------------------------------------------


		bool verify = false;
		double tmppx =0,tmppy =0,tmppz =0;

		pt.GetPointPosition(tmppx,tmppy,tmppz);
		while(((tmppx+2*PatternRadius) >= PlateW+1) || (tmppx <= 0-1)){
			if((tmppx+2*PatternRadius) >= PlateW+1){
				tmppx = PlateW - fabs(tmppx-PlateW)-2*PatternRadius;
				pt.SetPointPosition(tmppx,tmppy,tmppz);
				pt.Velocity_X = - pt.Velocity_X;
				verify = true;
			}
			else if(tmppx <= 0-1){
				tmppx = -tmppx;
				pt.SetPointPosition(tmppx,tmppy,tmppz);	
				pt.Velocity_X = - pt.Velocity_X;
				verify = true;
			}

		}

		while( (tmppy+2*PatternRadius >= PlateH+1) || (tmppy <= 0-1)  ){
			pt.GetPointPosition(tmppx,tmppy,tmppz);
			if(tmppy+2*PatternRadius >= PlateH+1){
				tmppy = PlateH-fabs(tmppy-PlateH)-2*PatternRadius;
				pt.SetPointPosition(tmppx,tmppy,tmppz);
				pt.Velocity_Y = - pt.Velocity_Y;
				verify = true;
			}
			else if(tmppy <= 0-1){
				tmppy = -tmppy;
				pt.SetPointPosition(tmppx,tmppy,tmppz);
				pt.Velocity_Y = - pt.Velocity_Y;
				verify = true;
			}
		}
		
		if(verify == true)
			VerifyPtInMeshIndex(pt,mg,MeshSize,PatternRadius);						

}
*/

double power_2(double x){
	return x*x;
};

void Cross(float &x ,float &y ,float &z , float vecA_x,  float vecA_y, float vecA_z,  float vecB_x,  float vecB_y, float vecB_z){
		x = vecA_y*vecB_z - vecB_y*vecA_z;
		y = vecA_x*vecB_z - vecB_x*vecA_z;
		z = vecA_x*vecB_y - vecB_x*vecA_y;

};

void Sort(array<PointF>^ Data){
	bool sortComplete ;
	do{
		sortComplete = true;
		for(int ii = 0 ;ii <Data->Length-1 ;ii++){
			
			
			if(Data[ii].X > Data[ii+1].X){
				Array::Reverse(Data,ii,2);
				sortComplete = false;
			}

		}

	}while(sortComplete == false);
}
/*
void BuildRelation(Pattern^ Dot,GridDensity^ Density,MainFormData^ maindata,Point GirdNumber){

		//建立網點和網格間的資料
		Density->DotIndex = gcnew array<List<int>^,2>(GirdNumber.X,GirdNumber.Y);


		for(int ii = 0 ;ii <GirdNumber.X ;ii++){
			for(int jj = 0 ;jj < GirdNumber.Y ;jj++){
				List<int>^ tempList = gcnew List<int>(0);
			//	Density->DotIndex->SetValue(tempList,ii,jj);
				Density->DotIndex[ii,jj] = tempList;

			}
		}

					
	
		int tempSearchX[2] ,tempSearchY[2] ;


		for(int ii = 0 ; ii <Dot->GetDotNumber(); ii++){


			PointF TargetDot(0,0);
			float tmp;
			//Dot->GetDotValue(TargetDot,tmp,ii);
			TargetDot = Dot->Dot_Coordinate[ii];
			int tmpIndexX =0  ,tmpIndexY = 0;

			
		//	if(TargetDot.X >= 0 && TargetDot.X<=maindata->LGPDimension.X && TargetDot.Y >= 0 && TargetDot.Y<=maindata->LGPDimension.Y){
			if(TargetDot.X >= 0 && TargetDot.X<=maindata->LGPInformation.Width && TargetDot.Y >= 0 && TargetDot.Y<=maindata->LGPInformation.Height){

				PointF RangeX(0,0);
				PointF RangeY(0,0);
				
				//此tmpIndexX 和 tmpIndexY和Density 的對應關係必須和"產生初使網點"的對應關係一致
				tempSearchX[0] = 0;
				tempSearchX[1] = GirdNumber.X;
				tempSearchY[0] = 0;
				tempSearchY[1] = GirdNumber.Y;
				tmpIndexX = Math::Round((tempSearchX[0]+tempSearchX[1])/2);
				tmpIndexY = Math::Round((tempSearchY[0]+tempSearchY[1])/2);


				do{
					RangeX.X =tmpIndexX*maindata->LGPInformation.Width/GirdNumber.X;
					RangeX.Y =(tmpIndexX+1)*maindata->LGPInformation.Width/GirdNumber.X;

					RangeY.X =tmpIndexY*maindata->LGPInformation.Height/GirdNumber.Y;
					RangeY.Y =(tmpIndexY+1)*maindata->LGPInformation.Height/GirdNumber.Y;



					if ( TargetDot.X < RangeX.X){
						tempSearchX[1] = tmpIndexX;
					};
					if ( TargetDot.X > RangeX.Y){
						tempSearchX[0] = tmpIndexX;	
					};
						
					if ( TargetDot.Y < RangeY.X){
						tempSearchY[1] = tmpIndexY;
					};
					if ( TargetDot.Y > RangeY.Y){
						tempSearchY[0] = tmpIndexY;
					};

					tmpIndexX = Math::Round((tempSearchX[0]+tempSearchX[1])/2);
					tmpIndexY = Math::Round((tempSearchY[0]+tempSearchY[1])/2);

					if (tmpIndexX > GirdNumber.X-1) tmpIndexX = GirdNumber.X-1;
					if (tmpIndexY > GirdNumber.Y-1) tmpIndexY = GirdNumber.Y-1;
					if (tmpIndexX <0) tmpIndexX = 0;
					if (tmpIndexY <0) tmpIndexY = 0;
				
						
						




				}while (TargetDot.X <RangeX.X ||TargetDot.X > RangeX.Y || TargetDot.Y <RangeY.X ||TargetDot.Y > RangeY.Y);

				List<int>^	tempList = Density->DotIndex[tmpIndexX,tmpIndexY];
				tempList->Add(ii);
			}
		
			

		}







}
//*/
void MovePoint(Pattern^ Dot,MainFormData^ maindata,float time,int &UnSelectPt){
	PointF cood;
	PointF force;
	
	//不要用SetValue或GetValue 指令 因為還要做型別轉換,耗時間 約 2 sec , for32吋>
	for(int ii = 0 ; ii<Dot->GetDotNumber(); ii++){
	//	force = Dot->Dot_Force->GetValue(ii);
		force = Dot->Dot_Force[ii];
	//	Dot->GetDotValue(cood,tmp,ii);
		cood = Dot->Dot_Coordinate[ii];
		cood.X = cood.X + time/maindata->Parameter_C*force.X;
		cood.Y = cood.Y + time/maindata->Parameter_C*force.Y;	
	//	Dot->SetDotValue(cood,tmp,ii);
		Dot->Dot_Coordinate[ii] = cood;
		Dot->Dot_Force[ii]= PointF(0,0);
	//	if(cood.X < Dot->Dot_Diameter[ii]/2 || cood.X > maindata->LGPDimension.X - Dot->Dot_Diameter[ii]/2  || cood.Y < Dot->Dot_Diameter[ii]/2 || cood.Y > maindata->LGPDimension.Y - Dot->Dot_Diameter[ii]/2 ){
		if(cood.X < Dot->Dot_Diameter[ii]/2 || cood.X > maindata->LGPInformation.Width- Dot->Dot_Diameter[ii]/2  || cood.Y < Dot->Dot_Diameter[ii]/2 || cood.Y > maindata->LGPInformation.Height - Dot->Dot_Diameter[ii]/2 ){
			UnSelectPt = UnSelectPt + 1;
		}
	}


	
}
PointF PointForceFastMode(Pattern^ Dot,int index1 ,int index2 ,MainFormData^ maindata,float properdistance,array<PointF>^ D_T_Curve){

	//假定 K值 = 1;
	double Rij[2];
	PointF pt1 ,pt2;
	float tmp = 0;
	int tempIndex = 0;
	PointF CurvePt1 = (PointF)D_T_Curve[tempIndex] ;
	PointF CurvePt2 = (PointF)D_T_Curve[tempIndex+1] ;
	
	Dot->GetDotValue(pt1,tmp,index1);
	Dot->GetDotValue(pt2,tmp,index2);

	
	Rij[0] = pt1.X -pt2.X;
	Rij[1] = pt1.Y -pt2.Y;
	float  distance = (float)(Math::Sqrt(Math::Pow(Rij[0],2)+Math::Pow(Rij[1],2)));

	do{

	CurvePt1 = (PointF)D_T_Curve[tempIndex] ;
	CurvePt2 = (PointF)D_T_Curve[tempIndex] ;
	if(distance > CurvePt2.X) tempIndex++;
	if(distance < CurvePt1.X) tempIndex--;


	}while(CurvePt1.X > distance || CurvePt2.X < distance );


	float temp = (CurvePt1.Y*(CurvePt2.X-distance) + CurvePt2.Y*(distance-CurvePt1.X))/(CurvePt2.X-CurvePt1.X);
	PointF force;

//	force.X = Rij[0]*temp;
//	force.Y = Rij[1]*temp;	

	return force;


}
PointF PointForce(Pattern^ Dot,PointF pt1 ,PointF pt2,float distance ,MainFormData^ maindata,float properdistance){
	double Bij,Rij[2];
	float K = maindata->Parameter_K;
	
	Rij[0] = pt1.X -pt2.X;
	Rij[1] = pt1.Y -pt2.Y;

	if (maindata->RandomDotSimRule == 0){
		if(K == 1) Bij = properdistance;
		else Bij = fabs(K*properdistance*Math::Sqrt((Math::Pow(Rij[0],2) + Math::Pow(Rij[1],2))/(Math::Pow(K,2)*Math::Pow(Rij[0],2)+Math::Pow(Rij[1],2))));
	}
	else{
		Bij = Math::Max(fabs(Rij[0]),fabs(Rij[1])/K);	
	}
	
	

	double temp = 1/distance*exp(-(distance-Bij)/(0.2*properdistance));
	PointF force;
	
	if (Bij >=properdistance){		
		force.X = (float)(Rij[0]*temp);
		force.Y = (float)(Rij[1]*temp);	
		
	}
	else{
		force.X = (float)(Rij[0]/distance);
		force.Y = (float)(Rij[1]/distance);	
	}

	
		return force;










}
PointF PointForce(Pattern^ Dot,PointF pt1 ,PointF pt2 , MainFormData^ maindata,float properdistance){
	double Bij,Rij[2];
	float K = maindata->Parameter_K;
	
	Rij[0] = pt1.X -pt2.X;
	Rij[1] = pt1.Y -pt2.Y;

	if (maindata->RandomDotSimRule == 0){
		if(K == 1) Bij = properdistance;
		else Bij = fabs(K*properdistance*Math::Sqrt((Math::Pow(Rij[0],2) + Math::Pow(Rij[1],2))/(Math::Pow(K,2)*Math::Pow(Rij[0],2)+Math::Pow(Rij[1],2))));
	}
	else{
		Bij = Math::Max(fabs(Rij[0]),fabs(Rij[1])/K);	
	}
	
	
	double distance = Math::Sqrt(Math::Pow(Rij[0],2)+Math::Pow(Rij[1],2));
	double temp = 1/distance*exp(-(distance-Bij)/(0.2*properdistance));
	PointF force;
	
	if (Bij >=properdistance){		
		force.X = (float)(Rij[0]*temp);
		force.Y = (float)(Rij[1]*temp);	
		
	}
	else{
		force.X = (float)(Rij[0]/distance);
		force.Y = (float)(Rij[1]/distance);	
	}

	
		return force;
		
}
/*
void BuildDensityArrayData(Pattern^ Dot,GridDensity^ Density,Point GirdNumber ,array<array<int>^,2>^ PtIndex){
	
	//For 32吋 直徑0.3Dot ,Pattern版本 03版,70 X70  ,需耗時 2 Sec
	//array<array<PointF>^,2>^ Test = gcnew array<array<PointF>^,2>(GirdNumber.X,GirdNumber.Y);
	//array<array<int>^,2>^ Test2 = gcnew array<array<int>^,2>(GirdNumber.X,GirdNumber.Y);
	List<int>^ DotIndex = nullptr;
	for(int ii = 0 ; ii<GirdNumber.X ; ii++){
		for(int jj = 0 ; jj<GirdNumber.Y ; jj++){
		//   DotIndex = (List<int>^)Density->DotIndex->GetValue(ii,jj);
			 DotIndex = Density->DotIndex[ii,jj];
			
		//	array<PointF>^DotArray	= gcnew array<PointF>(DotIndex->Count);
			array<int>^DotArrayIndex	= gcnew array<int>(DotIndex->Count);

			for(int kk = 0 ; kk < DotArrayIndex->Length ; kk++){

			//	PointF tmpData;
			//	float tmp2;
			//	Dot->GetDotValue(tmpData,tmp2,DotIndex->default[kk]);
			//	Dot->Dot_Coordinate[DotIndex[kk]];
			//	DotArray->SetValue(tmpData,kk);
				DotArrayIndex->SetValue(DotIndex->default[kk],kk);
			//	DotArrayIndex[kk] = DotIndex[kk];
			}

		//	PtCood->SetValue(DotArray,ii,jj);
		//	PtIndex->SetValue(DotArrayIndex,ii,jj);
			PtIndex[ii,jj] = DotArrayIndex;


		}
	}

}
//*/
///*
void VelerttMode(Pattern^ Dot ,GridDensity^ Density,Point GirdNumber,MainFormData^ maindata ,array<array<int>^,2>^ PtIndex,float*  maxForcePow2,int* UnSelectedPt , int* SmallGapNumber){

	float tmpmaxForcePow2 = 0.0f;

	for(int ii = 0 ; ii<GirdNumber.X ; ii++){
		for(int jj = 0 ; jj<GirdNumber.Y ; jj++){
			float den = 0 ;
		//	Density->GetDensity_Value(den,ii,jj);  //20091226以前
			Point index(ii,jj);
			den = Density->GetDensityValue(index);
		
			den = (float)Math::Sqrt(den);
			//計算適當距離 ,設定範圍	---相當於R-Cut,只不過這R-Cut 不僅是兩點間的最短距離 ,而是依據密度決定的最短距離		
			float properdist =  (maindata->RandomDotSize+maindata->RandomDotGap)/den;

			//針對範圍內的網點進行計算
				//計算包含幾個網格
		//	int RoundX = Math::Round(properdist/WidthX);
		//	int RoundY = Math::Round(properdist/WidthY);
			int RoundX = 1 ;
			int RoundY = 1 ;

			int lowerX = ii- RoundX;
			int lowerY = jj- RoundY;
			int upperX = ii+ RoundX;
			int upperY = jj+ RoundY;

			if (lowerX < 0) lowerX = 0;
			if (lowerY < 0) lowerY = 0;
			if (upperX > GirdNumber.X-1) upperX = GirdNumber.X-1;
			if (upperY > GirdNumber.Y-1) upperY = GirdNumber.Y-1;

			array<int>^ DotInsdieMesh = PtIndex[ii,jj];
			
			for(int kk = 0 ;kk <DotInsdieMesh->Length ;kk++){
				int targetDotIndex = DotInsdieMesh[kk];
				PointF tmpValue(0.0f,0.0f);
				PointF force(0.0f,0.0f);
				PointF pt1(0,0);
				//float tmpa = 0 ;
				//Dot->GetDotValue(pt1,tmpa,targetDotIndex);
				pt1 = Dot->Dot_Coordinate[targetDotIndex];
				for(int k1=lowerX ;k1 <= upperX ; k1++){
					for(int k2 = lowerY; k2 <=upperY ;k2++){
						array<int>^ surroundingIndex =PtIndex[k1,k2];

						for(int k3 = 0 ; k3 <surroundingIndex->Length ; k3++){
							PointF pt2(0,0);						
							//Dot->GetDotValue(pt2,tmpa,surroundingIndex[k3]);
							pt2 =Dot->Dot_Coordinate[surroundingIndex[k3]];
							
							if ((pt1.Equals(pt2) == false) && fabs(pt2.X-pt1.X) <properdist && fabs(pt2.Y-pt1.Y) <properdist){
								//force = PointForce(Dot,pt1,pt2,maindata,properdist);
								double distance = Math::Sqrt(Math::Pow(pt2.X-pt1.X,2)+Math::Pow(pt2.Y-pt1.Y,2));
								force = PointForce(Dot,pt1,pt2,(float)distance,maindata,properdist);

								tmpValue.X = tmpValue.X + force.X;
								tmpValue.Y = tmpValue.Y + force.Y;
								if(distance < maindata->RandomDotSize/2 + maindata->RandomDotGap/2){
									*SmallGapNumber = *SmallGapNumber +1 ;
								}
							}
						



						}
					}
				}


				//Dot->Dot_Force->SetValue(tmpValue,targetDotIndex);
				Dot->Dot_Force[targetDotIndex] = tmpValue ;
				//if((tmpValue.X*tmpValue.X + tmpValue.Y*tmpValue.Y)  > tmpmaxForcePow2){
					tmpmaxForcePow2 = tmpmaxForcePow2 + sqrt(tmpValue.X*tmpValue.X + tmpValue.Y*tmpValue.Y);
				//	tmpmaxForcePow2 =(tmpValue.X*tmpValue.X + tmpValue.Y*tmpValue.Y) ;
				//}

			}

				
			

		}
	}

	//
	    *maxForcePow2 = tmpmaxForcePow2/Dot->GetDotNumber();
	//  *maxForcePow2 = tmpmaxForcePow2;


	//For 32吋 直徑0.3Dot ,Pattern版本 03版 ,需耗時 3 Sec
	MovePoint(Dot,maindata,0.001f,*UnSelectedPt);




}
//*/
/*
void VelertMode(Pattern^ Dot ,GridDensity^ Density ,Point GirdNumber,MainFormData^ maindata,float factor){

	
	float WidthX = 0 ,WidthY = 0;	
	WidthX = maindata->LGPDimension.X/GirdNumber.X;
	WidthY = maindata->LGPDimension.Y/GirdNumber.Y;
	
//----------------------------------------------------------------
//-------------迴圈中盡量不要做型別轉換 ,且盡量不用List-----------------------------
	



	
	for(int ii = 0 ; ii<GirdNumber.X ; ii++){
		for(int jj = 0 ; jj<GirdNumber.Y ; jj++){
			float den = 0 ;
			Density->GetDensity_Value(den,ii,jj);
			den = Math::Sqrt(den);
			//計算適當距離 ,設定範圍
			//float properdist = factor*(maindata->RandomDotSize+maindata->RandomDotGap)/den;
			float properdist =  (maindata->RandomDotSize+maindata->RandomDotGap)/den;

			//針對範圍內的網點進行計算
				//計算包含幾個網格
		//	int RoundX = Math::Round(properdist/WidthX);
		//	int RoundY = Math::Round(properdist/WidthY);
			int RoundX = 1 ;
			int RoundY = 1 ;

			
			//將所有"相關的"網點放入List中~~~

			//表示欲計算網格內的網點
		//	List<int>^ DotListInsdieMesh = (List<int>^)Density->DotIndex->GetValue(ii,jj);
			//將List 轉為Array (加快取值速度)
		//	array<int>^ DotArrayInsdieMesh = DotListInsdieMesh->ToArray();
			//表示要參與作用中的網點
		//	ArrayList^ DotArrayAll = gcnew ArrayList();
		//	array<int>^DotArray = nullptr;

			int lowerX = ii- RoundX;
			int lowerY = jj- RoundY;
			int upperX = ii+ RoundX;
			int upperY = jj+ RoundY;

			if (lowerX < 0) lowerX = 0;
			if (lowerY < 0) lowerY = 0;
			if (upperX > GirdNumber.X-1) upperX = GirdNumber.X-1;
			if (upperY > GirdNumber.Y-1) upperY = GirdNumber.Y-1;

			
	//		int count = 0 ;
	//		for(int kk = lowerX ;kk<=upperX ; kk++){
	//			for(int ll = lowerY ;ll<=upperY ;ll++){
	//				List<int>^ DotIndex = (List<int>^)Density->DotIndex->GetValue(kk,ll);
	//				DotArray = DotIndex->ToArray();
	//				count = count + DotArray->Length;
	//				DotArrayAll->Add(DotArray);
	//			}
	//		}

			
			

			//將-------------------------
		
		//	array<PointF>^ correspondDot = gcnew array<PointF>(count);
		//	count = 0;

		//	for(int ll = 0 ; ll< DotArrayAll->Count ; ll++){				
		//		array<int>^tmp = (array<int>^)DotArrayAll->default[ll];
		//		for(int mm = 0 ;mm <tmp->Length ;mm++){
		//			int correspondDotIndex = tmp[mm] ;

		//			PointF pt2(0,0);
		//			float tmpb = 0 ;
		//			Dot->GetDotValue(pt2,tmpb,correspondDotIndex);
		//			correspondDot->SetValue(pt2,count);
		//			count ++;
		//		}
		//	}  //7 minute



			
		

			//計算合力
		//	for(int kk = 0 ; kk< DotListInsdieMesh->Count ; kk++){
		//		int targetDotIndex = DotListInsdieMesh[kk];
				int targetDotIndex = 0;
				
				PointF tmpValue(0.0f,0.0f);
				PointF pt1(0,0);
				float tmpa = 0 ;
				Dot->GetDotValue(pt1,tmpa,targetDotIndex);
			//	for(int ll = 0 ; ll < correspondDot->Length ;ll++){
				//	PointF force;
				//	if (pt1.Equals(correspondDot[ll]) == false && fabs(correspondDot[ll].X-pt1.X) <properdist && fabs(correspondDot[ll].Y-pt1.Y) <properdist){
				//		force = PointForce(Dot,pt1,correspondDot[ll],maindata,properdist);
				//		tmpValue.X = tmpValue.X + force.X;
				//		tmpValue.Y = tmpValue.Y + force.Y;
				//	}
				

					
			//	} //7minute

		//		for(int ll = 0 ; ll< DotArrayAll->Count ; ll++){
					
		//			array<int>^tmp = (array<int>^)DotArrayAll->default[ll];
		//			for(int mm = 0 ;mm <tmp->Length ;mm++){
		//				int correspondDotIndex = tmp[mm] ;

		//				PointF pt2(0,0);
		//				float tmpb = 0 ;
		//				Dot->GetDotValue(pt2,tmpb,correspondDotIndex);


		//				if ( targetDotIndex != correspondDotIndex ) {
		//					PointF force = PointForce(Dot,pt1,pt2,maindata,(maindata->RandomDotSize+maindata->RandomDotGap)/den);
						//	PointF force(0,0);
		//					tmpValue.X = tmpValue.X + force.X;
		//					tmpValue.Y = tmpValue.Y + force.Y;
		//				}
		//			}
					

		//		} //13 minute
				Dot->Dot_Force->SetValue(tmpValue,targetDotIndex);

		//	}
			
			

		}
	}



	//For 32吋 直徑0.3Dot ,Pattern版本 03版 ,需耗時 3 Sec
//	MovePoint(Dot,maindata,0.001,* UnSelectedPt);

	
		

	



	




}
*/