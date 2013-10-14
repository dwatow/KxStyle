#include "StdAfx.h"
#include "ScreenMura.h"



using namespace PatternContruction;

/*
float ScreenMura::CalculateMuraValue(PointF DotCoordinate,float DotDiameter){

			float ratio;
			float Decrease_Area;



			//块把计
			float angle = Convert::ToSingle(this->txtScreenAngle->Text)*Math::PI/180;
			float StartPosX = Convert::ToSingle(this->txtStartPos->Text);
			float StartPosY = Convert::ToSingle(this->txtStartPosY->Text);
			float ScreenPitch = Convert::ToSingle(this->txtScreenPitch->Text);
			float ScreenThick = Convert::ToSingle(this->txtScreenThick->Text);





			 // 秈︽呼だ猂  X よ

		


			 PointF Coordinate ;
			 //畒夹锣传
			 Coordinate.X = Math::Cos(angle)*DotCoordinate.X - Math::Sin(angle)*DotCoordinate.Y ;
			 Coordinate.Y = Math::Sin(angle)*DotCoordinate.X + Math::Cos(angle)*DotCoordinate.Y ;



			float oriArea = DotDiameter*DotDiameter*Math::PI/4;


			
			// X よ把计

			float h1 ;
			float h2 ;
			float line1 ;
			float line2 ;
			int tmp ;
			
			tmp = Math::Truncate((StartPosX + Coordinate.X-DotDiameter/2)/ScreenPitch) ;
			if (tmp >=0) {	
				line1 = ScreenPitch*(tmp+1) - (Coordinate.X) ;
			}else{
				line1 = ScreenPitch*(tmp) - (Coordinate.X) ;
			}
			line2 = line1 + ScreenThick;
			

			do{
				 
				
				
				 h1 = DotDiameter*DotDiameter/4 - line1*line1 ;
				 h2 = DotDiameter*DotDiameter/4 - line2*line2 ;

				 if((h1<=0 && h2 >=0) || (h1 >=0 && h2 <=0)){
					 if(h1<=0) h1 = 0;
					 if(h2<=0) h2 = 0;
				 }

				 if(h1<=0 && h2 <=0) break;

				
				 
				 if(h1== 0) {
					Decrease_Area = Decrease_Area + (Math::Sqrt(h1) + Math::Sqrt(h2))*fabs(line2-DotDiameter/2);
				 }else if(h2 == 0){
					Decrease_Area = Decrease_Area + (Math::Sqrt(h1) + Math::Sqrt(h2))*fabs(line1-DotDiameter/2);
				 }else{
					Decrease_Area = Decrease_Area + (Math::Sqrt(h1) + Math::Sqrt(h2))*ScreenThick;
				 }
				

			
				line1 = line1 + ScreenPitch;
				line2 = line1 + ScreenThick;



			}while (h1 >= 0 && h2 >= 0 );






			// 秈︽呼だ猂  Y よ

			float h3 ;
			float h4 ;
			float line3 ;
			float line4 ;

			int tmp2 ;
			tmp2 = Math::Truncate((StartPosY + Coordinate.Y-DotDiameter/2)/ScreenPitch) ;
			if (tmp2 >=0) {	
				line3 = ScreenPitch*(tmp2+1) - (Coordinate.Y) ;
			}else{
				line4 = ScreenPitch*(tmp2) - (Coordinate.Y) ;
			}
			line4 = line3 + ScreenThick;



			do{
				 
				
				
				 h3 = DotDiameter*DotDiameter/4 - line3*line3 ;
				 h4 = DotDiameter*DotDiameter/4 - line4*line4 ;

				 if((h3<=0 && h4 >=0) || (h3 >=0 && h4 <=0)){
					 if(h3<=0) h3 = 0;
					 if(h4<=0) h4 = 0;
				 }

				 if(h3<=0 && h4 <=0) break;

				//int tmpnumber = Math::Truncate((Math::Sqrt(h1)+ Math::Sqrt(h2))/ScreenPitch);
				int tmpnumber = 0 ; 

				 
				 float tmpheight = 0 ;
				 if(h3 == 0 ){
					tmpheight =fabs(line2-DotDiameter/2);
				 }else if (h4 == 0) {
					tmpheight =fabs(line1-DotDiameter/2);
				 }else{
					tmpheight = ScreenThick;
				 }
			
				 Decrease_Area = Decrease_Area + (Math::Sqrt(h3) + Math::Sqrt(h4))*tmpheight  ;

				 line3 = line3 + ScreenPitch;
				 line4 = line3 + ScreenThick;


			}while (h3 >= 0 && h4 >= 0 );





			//-----------------------竊翴丁计---------------------------------------------------------------
			float lineA ;  //X Left
			float lineB ;  //X Right
			float lineC ;  //Y Left
			float lineD ;  //Y Right
			int tmp3 ;		
			tmp3 = Math::Truncate((StartPosX + Coordinate.X-DotDiameter/2)/ScreenPitch) ;
			if (tmp3 >=0) {	
				lineA = ScreenPitch*(tmp3+1) - (Coordinate.X) ;
			}else{
				lineA = ScreenPitch*(tmp3) - (Coordinate.X) ;
			}

			tmp3 = Math::Truncate((StartPosX + Coordinate.X+ DotDiameter/2)/ScreenPitch) ;
			if (tmp3 >=0) {	
				lineB = ScreenPitch*(tmp3) - (Coordinate.X) ;
			}else{
				lineB = ScreenPitch*(tmp3-1) - (Coordinate.X) ;
			}

			tmp3 = Math::Truncate((StartPosY + Coordinate.Y-DotDiameter/2)/ScreenPitch) ;
			if (tmp2 >=0) {	
				lineC = ScreenPitch*(tmp3+1) - (Coordinate.Y) ;
			}else{
				lineC = ScreenPitch*(tmp3) - (Coordinate.Y) ;
			}

			tmp3 = Math::Truncate((StartPosY + Coordinate.Y + DotDiameter/2)/ScreenPitch) ;
			if (tmp2 >=0) {	
				lineD = ScreenPitch*(tmp3) - (Coordinate.Y) ;
			}else{
				lineD = ScreenPitch*(tmp3-1) - (Coordinate.Y) ;
			}
			int NumberX = Math::Round((lineB-lineA-ScreenThick)/ScreenPitch) ;
			int NumberY = Math::Round((lineD-lineC-ScreenThick)/ScreenPitch) ;

			int count = 0;

			for(int aa = 0 ; aa < NumberX ; aa ++){
				for(int bb = 0 ; bb < NumberY ;bb ++){
					PointF DL(lineA + aa*ScreenThick ,lineC + bb*ScreenThick);
					PointF UL(lineA + aa*ScreenThick ,lineC + (bb+1)*ScreenThick);
					PointF DR(lineA + (aa+1)*ScreenThick ,lineC + bb*ScreenThick);
					PointF UR(lineA + (aa+1)*ScreenThick ,lineC + (bb+1)*ScreenThick);
					//PointF Center = (D_L + U_L + D_R + U_R)/4;
					
					if(Math::Sqrt(DL.X*DL.X+DL.Y*DL.Y) <=DotDiameter/2){
						count ++;
					}
					if(Math::Sqrt(UL.X*UL.X+UL.Y*UL.Y) <=DotDiameter/2){
						count ++;
					}
					if(Math::Sqrt(DR.X*DR.X+DR.Y*DR.Y) <=DotDiameter/2){
						count ++;
					}
					if(Math::Sqrt(UR.X*UR.X+UR.Y*UR.Y) <=DotDiameter/2){
						count ++;
					}


					






				}
			}

			Decrease_Area = Decrease_Area -count*ScreenThick*ScreenThick/4 ;


			//-------------------------------------------------------------------------------

				


				
			ratio =  (oriArea- Decrease_Area)/oriArea;
			

			return  ratio;

};
*/
