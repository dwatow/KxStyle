// KxStyleView.cpp : implementation of the CKxStyleView class
//

#include "stdafx.h"
#include "KxStyle.h"

#include "KxStyleDoc.h"
#include "KxStyleView.h"
#include "MainFrm.h"

#include "ViewDC.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKxStyleView

IMPLEMENT_DYNCREATE(CKxStyleView, CScrollView)

BEGIN_MESSAGE_MAP(CKxStyleView, CScrollView)
	//{{AFX_MSG_MAP(CKxStyleView)
	//}}AFX_MSG_MAP
	// Standard printing commands

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKxStyleView construction/destruction

CKxStyleView::CKxStyleView(){}
CKxStyleView::~CKxStyleView(){}


void CKxStyleView::OnInitialUpdate()
{
    CScrollView::OnInitialUpdate();
    CSize sizeTotal;
    // TODO: calculate the total size of this view
    sizeTotal.cx = GetDeviceScrollPosition().x;
    sizeTotal.cy = GetDeviceScrollPosition().y;
    SetScrollSizes(MM_TEXT, sizeTotal);
}

//////////////////////////////////////////////////////////////////////////

#ifdef _DEBUG
void CKxStyleView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CKxStyleView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CKxStyleDoc* CKxStyleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKxStyleDoc)));
	return (CKxStyleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKxStyleView message handlers

// int CKxStyleView::leftChar(std::vector<CString>::iterator itor, char ch)
// {
// 	TCHAR tCh = ch;
// 	for (int indexSapce = 0; indexSapce < itor->GetLength(); ++indexSapce)
// 	{
// 		if (itor->GetAt(indexSapce) != tCh)
// 			return indexSapce;
// 		else;
// 	}
// 
// 	return 0;
// }
void CKxStyleView::removeIndention()
{
	for (std::vector<CString>::iterator itor = Code.begin(); itor != Code.end(); ++itor)
	{
		itor->TrimLeft();  //remove spaceline and startup '\t', space
		itor->TrimRight();  //remove "...;  " to "...;"
	}
}

void CKxStyleView::exchangeVecStr(std::vector<CString>& vBefore, std::vector<CString>& vAfter)
{
	//remove
	vBefore.clear();
	vBefore = vAfter;
	vAfter.clear();
}

void CKxStyleView::removeSpaceLine()
{
	std::vector<CString> NoSpaceLineCode;
	for (std::vector<CString>::iterator itor = Code.begin(); itor != Code.end(); ++itor)
		if (!itor->IsEmpty())
			NoSpaceLineCode.push_back(*itor);

	exchangeVecStr(Code, NoSpaceLineCode);
}

void CKxStyleView::findLBraces(std::vector<CString>& codePressing, CString codeLine)
{
		int iBraces = codeLine.Find('{');
// 		CString temp(codeLine.Mid(iBraces));
// 		temp.Find()
		if (iBraces != -1)  //§ä¨ì'{'
		{
			if (iBraces != 0)  //normal case
			{
				codePressing.push_back(codeLine.Left(iBraces));
// 				codePressing.push_back(codeLine.Mid(iBraces));  //
				findLBraces(codePressing, codeLine.Mid(iBraces));
			}
			else if(codeLine.GetLength() > 1)  //"{..."
			{
				codePressing.push_back(codeLine.Left(iBraces+1));
// 				codePressing.push_back(codeLine.Mid(iBraces+1));  //
				findLBraces(codePressing, codeLine.Mid(iBraces+1));
			}
			else // "{"
			{
				codePressing.push_back(codeLine.Mid(iBraces));  //
			}
		} 
		else
		{
			codePressing.push_back(codeLine);  //all of line
		}
}

void CKxStyleView::findRBraces(std::vector<CString>& codePressing, CString codeLine)
{
	int iBraces = codeLine.Find('}');
	if (iBraces != -1)  //§ä¨ì'{'
	{
		if (iBraces != 0)  //normal case
		{
			//codePressing.push_back(codeLine.Left(iBraces));
			findRBraces(codePressing, codeLine.Left(iBraces));
			codePressing.push_back(codeLine.Mid(iBraces));
		}
		else if(codeLine.GetLength() > 1)  //"{..."
		{
			//codePressing.push_back(codeLine.Left(iBraces+1));
			findRBraces(codePressing, codeLine.Left(iBraces+1));
			codePressing.push_back(codeLine.Mid(iBraces+1));
		}
		else // "{"
		{
			codePressing.push_back(codeLine.Mid(iBraces));
		}
	}
	else
	{
		codePressing.push_back(codeLine);  //all of line
	}
}

void CKxStyleView::findBraces()
{
	std::vector<CString> pressedCode;
	for (std::vector<CString>::iterator itor = Code.begin(); itor != Code.end(); ++itor)
		findLBraces(pressedCode, *itor);
	exchangeVecStr(Code, pressedCode);

	pressedCode.clear();
	for (itor = Code.begin(); itor != Code.end(); ++itor)
 		findRBraces(pressedCode, *itor);
	exchangeVecStr(Code, pressedCode);
}

CString CKxStyleView::remakeIndention(int Lv, int LengthSpace)
{
	CString spaceIndention;

	for(int i = 0; i < Lv*LengthSpace; ++i)
		spaceIndention += " ";

	return spaceIndention;
}

void CKxStyleView::addIndention(int nSpace)
{
	int Lv = 0;
	std::vector<CString> pressingCode;
	CString currentCode;
	for (std::vector<CString>::iterator itor = Code.begin(); itor != Code.end(); ++itor)
	{
		if (itor->Find('{') == 0)
			Lv++;
		if (itor->Find('}') == 0)
			Lv--;		

		currentCode.Format("%s%s", remakeIndention(Lv, nSpace), *itor);
		pressingCode.push_back(currentCode);
	}
	exchangeVecStr(Code, pressingCode);
}

void CKxStyleView::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
	GetDocument()->oData(Code);
	removeIndention();
	removeSpaceLine();
	findBraces();
	removeIndention();
	addIndention();

	CViewDC DC(pDC);
 	DC.TextOut(Code);
}


BOOL CKxStyleView::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN)
    {
        switch(pMsg->wParam)
        {
			case VK_F5:     GetDocument()->UpdateAllViews(NULL); break;
        }
        return TRUE;
    }

	return CScrollView::PreTranslateMessage(pMsg);
}

