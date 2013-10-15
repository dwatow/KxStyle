// ViewDC.cpp: implementation of the CViewDC class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "KxStyle.h"
#include "ViewDC.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CViewDC::CViewDC(CDC* pDC):pMainDC(pDC), textHight(16)
{
	nDC = pMainDC->SaveDC();


   font.CreatePointFont(80,"Monaco"); 
   oldFont = pMainDC->SelectObject(&font);
}

CViewDC::~CViewDC()
{
	pMainDC->SelectObject(oldFont);
	font.DeleteObject(); 
	
	pMainDC->RestoreDC( nDC );
}

void CViewDC::TextOut(std::vector<CString>& Code)
{
	int indexLine = 0;
	CString strTest;

	for (std::vector<CString>::iterator itor = Code.begin(); itor != Code.end(); ++itor)
	{
		strTest.Format("%s", Code.at(indexLine));
		pMainDC->TextOut(0, indexLine*textHight, strTest);
		++indexLine;
	}
}