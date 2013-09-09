// KxStyleView.cpp : implementation of the CKxStyleView class
//

#include "stdafx.h"
#include "KxStyle.h"

#include "KxStyleDoc.h"
#include "CntrItem.h"
#include "KxStyleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKxStyleView

IMPLEMENT_DYNCREATE(CKxStyleView, CRichEditView)

BEGIN_MESSAGE_MAP(CKxStyleView, CRichEditView)
	//{{AFX_MSG_MAP(CKxStyleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRichEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKxStyleView construction/destruction

CKxStyleView::CKxStyleView()
{
	// TODO: add construction code here

}

CKxStyleView::~CKxStyleView()
{
}

BOOL CKxStyleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

void CKxStyleView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// Set the printing margins (720 twips = 1/2 inch).
	SetMargins(CRect(720, 720, 720, 720));
}

/////////////////////////////////////////////////////////////////////////////
// CKxStyleView printing

BOOL CKxStyleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}


void CKxStyleView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used.
   CRichEditView::OnDestroy();
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
}


/////////////////////////////////////////////////////////////////////////////
// CKxStyleView diagnostics

#ifdef _DEBUG
void CKxStyleView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CKxStyleView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CKxStyleDoc* CKxStyleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKxStyleDoc)));
	return (CKxStyleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKxStyleView message handlers
