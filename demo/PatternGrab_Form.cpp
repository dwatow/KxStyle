#include "StdAfx.h"
#include "PatternGrab_Form.h"
using namespace PatternContruction;


float PatternGrab_Form::GetPatternAreaInRec(RectangleF Rec,PointF DotCoor,float DotDia){
	float Density = 0 ;
	RectangleF InnerRec(Rec.X+DotDia/2,Rec.Y+DotDia/2,Rec.Width-DotDia,Rec.Height-DotDia);
	RectangleF OutsideRec(Rec.X-DotDia/2,Rec.Y-DotDia/2,Rec.Width+DotDia,Rec.Height+DotDia);







	return Density;

}