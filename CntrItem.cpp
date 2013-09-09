// CntrItem.cpp : implementation of the CKxStyleCntrItem class
//

#include "stdafx.h"
#include "KxStyle.h"

#include "KxStyleDoc.h"
#include "KxStyleView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKxStyleCntrItem implementation

IMPLEMENT_SERIAL(CKxStyleCntrItem, CRichEditCntrItem, 0)

CKxStyleCntrItem::CKxStyleCntrItem(REOBJECT* preo, CKxStyleDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: add one-time construction code here
	
}

CKxStyleCntrItem::~CKxStyleCntrItem()
{
	// TODO: add cleanup code here
	
}

/////////////////////////////////////////////////////////////////////////////
// CKxStyleCntrItem diagnostics

#ifdef _DEBUG
void CKxStyleCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CKxStyleCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////
