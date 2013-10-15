// KxStyleView.cpp : implementation of the CKxStyleView class
//

#include "stdafx.h"
#include "KxStyle.h"

#include "KxStyleDoc.h"
#include "KxStyleView.h"
#include "MainFrm.h"

#include "ViewDC.h"
#include "syntaxFor.h"


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
	std::vector<CString> processingCode;
	for (std::vector<CString>::iterator itor = Code.begin(); itor != Code.end(); ++itor)
		if (!itor->IsEmpty())
			processingCode.push_back(*itor);

	exchangeVecStr(Code, processingCode);
}

void CKxStyleView::singleSemicolon()
{
	std::vector<CString> processingCode;
	for (std::vector<CString>::iterator itor = Code.begin(); itor != Code.end(); ++itor)
	{
		if (itor->GetLength() != 1 || *itor != ';')
			processingCode.push_back(*itor);
	}
	exchangeVecStr(Code, processingCode);
}

void CKxStyleView::multipleSemicolon()
{
	std::vector<CString> processingCode;
	for (std::vector<CString>::iterator itor = Code.begin(); itor != Code.end(); ++itor)
	{
		int indexSemicolon;

		//т';'
		indexSemicolon = itor->Find(";");
		processingCode.push_back(itor->Left(indexSemicolon));
		processingCode.push_back(itor->Left(indexSemicolon+1));
	}
	exchangeVecStr(Code, processingCode);
}

void CKxStyleView::removeSemicolon()
{
//	multipleSemicolon();
	singleSemicolon();
}

BOOL CKxStyleView::IsCtrlItemInit(const CString& line)
{
	//AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem
	//});
	int iSyntaxBegin = line.Find("AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem");
	int iSyntaxEnd   = line.Find("});");

	if ((iSyntaxBegin != -1) || (iSyntaxEnd != -1)) //场常т
	{
		return TRUE;
	}
	else
		return FALSE;
}
BOOL CKxStyleView::IsStringFormat(const CString& line)
{
	int iFor = line.Find("String::Format");
	int iLBraces = line.Find('{');
	int iRBraces = line.Find('}');
	if ( ((iFor != -1) && (iLBraces != -1) && (iRBraces != -1)) && //场常т
		 (iFor < iLBraces) && 
		 (iLBraces < iRBraces) )
	{
		return TRUE;
	}
	else
		return FALSE;
}

BOOL CKxStyleView::IsComment(const CString& line)
{
	if (line.Find("//") == 0)
		IsInComment = TRUE;
	else
	{
		if (line.Find("/*") != -1)
			IsInComment = TRUE;
		if (line.Find("*/") != -1)
			IsInComment = FALSE;
		else
			IsInComment = FALSE;

	}
	return IsInComment;
}

void CKxStyleView::findLBraces(std::vector<CString>& processingCode, CString codeLine)
{
	int iBraces = codeLine.Find('{');
	if ( (iBraces != -1 ) &&  //т'{'
		 (!IsComment(codeLine) && !IsStringFormat(codeLine)) && !IsCtrlItemInit(codeLine) )
	{
		if (iBraces != 0)  //normal case
		{
			processingCode.push_back(codeLine.Left(iBraces));
// 				processingCode.push_back(codeLine.Mid(iBraces));  //
			findLBraces(processingCode, codeLine.Mid(iBraces));
		}
		else if(codeLine.GetLength() > 1)  //"{..."
		{
			processingCode.push_back(codeLine.Left(iBraces+1));
// 				processingCode.push_back(codeLine.Mid(iBraces+1));  //
			findLBraces(processingCode, codeLine.Mid(iBraces+1));
		}
		else // "{"
		{
			processingCode.push_back(codeLine.Mid(iBraces));  //
		}
	} 
	else
	{
		processingCode.push_back(codeLine);  //all of line
	}
}

void CKxStyleView::findRBraces(std::vector<CString>& processingCode, CString codeLine)
{
	int iBraces = codeLine.Find('}');
	if ( (iBraces != -1 ) &&  //т'{'
		 (!IsComment(codeLine) && !IsStringFormat(codeLine)) && !IsCtrlItemInit(codeLine) )
	{
		if (iBraces != 0)  //normal case
		{
			//processingCode.push_back(codeLine.Left(iBraces));
			findRBraces(processingCode, codeLine.Left(iBraces));
			processingCode.push_back(codeLine.Mid(iBraces));
		}
		else if(codeLine.GetLength() > 1)  //"{..."
		{
			//processingCode.push_back(codeLine.Left(iBraces+1));
			findRBraces(processingCode, codeLine.Left(iBraces+1));
			processingCode.push_back(codeLine.Mid(iBraces+1));
		}
		else // "{"
		{
			processingCode.push_back(codeLine.Mid(iBraces));
		}

	}
	else
	{
		processingCode.push_back(codeLine);  //all of line
	}
}

void CKxStyleView::findBraces()
{
	std::vector<CString> pressedCode;
	std::vector<CString>::iterator itor;
	for (itor = Code.begin(); itor != Code.end(); ++itor)
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
		if (itor->Find('}') == 0)
			Lv--;		

		currentCode.Format("%s%s", remakeIndention(Lv, nSpace), *itor);
		pressingCode.push_back(currentCode);

		if (itor->Find('{') == 0)
			Lv++;
	}
	exchangeVecStr(Code, pressingCode);
}

void CKxStyleView::sortOutForIf()
{
	std::vector<CString> pressingCode;
	for (std::vector<CString>::iterator itor = Code.begin(); itor != Code.end(); ++itor)
	{
		if (( itor->Find("for") != -1) || 
			( (itor->Find("if") != -1) < (itor->Find("else") != -1)) )
			pressingCode.push_back("");

		pressingCode.push_back(*itor);
	}
	exchangeVecStr(Code, pressingCode);
}

void CKxStyleView::cutCode()
{
	for (std::vector<CString>::iterator itor = ViewCode.begin(); itor != ViewCode.end(); ++itor)
	{
// 		if (itor->Find("#include") != -1)
// 			Include.push_back(*itor);
// 		else if (itor->Find("using") != -1)
// 			UsingNameSpace.push_back(*itor);
// 		else
			Code.push_back(*itor);
	}
	ViewCode.clear();
}

void CKxStyleView::forView()
{
// 	ViewCode.insert(ViewCode.end(), Include.begin(), Include.end());
// 	if(ViewCode.size()) 
// 		ViewCode.push_back("");
// 	ViewCode.insert(ViewCode.end(), UsingNameSpace.begin(), UsingNameSpace.end());
// 	if(ViewCode.size()) 
// 		ViewCode.push_back("");
	ViewCode.insert(ViewCode.end(), Code.begin(), Code.end());
	
	Include.clear();
	UsingNameSpace.clear();
	Code.clear();

	for (std::vector<CString>::iterator itor = ViewCode.begin(); itor != ViewCode.end(); ++itor)
		*itor += "\n";
}

void CKxStyleView::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class

	// Loading code
	GetDocument()->oData(ViewCode);
 	cutCode();

	//remove codeing style
	removeIndention();
	removeSpaceLine();


	//start kxStyle
	//--------------
	//1. move '{' and '}'
	findBraces();
	removeIndention();

	//syntaxFor TestObj(Code.begin(), Code.end());

	//2. remove ; in one line
 	removeSemicolon();
	//2. remove { ; }
	//removeOneLineInIndent();
	//sortOutForIf();
	//3. add "Tab"
	addIndention();
/**/
 	forView();
	CViewDC DC(pDC);
 	DC.TextOut(ViewCode);
	GetDocument()->iData(ViewCode);
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

