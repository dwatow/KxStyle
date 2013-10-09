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

void CKxStyleView::TabtoSpace(int nSpace)
{
	for (std::vector<CString>::iterator itor = Code.begin(); itor != Code.end(); ++itor)
	{
// 		itor->TrimRight();
// 		itor->TrimLeft();
	}
}

void CKxStyleView::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
	GetDocument()->oData(Code);
	
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
