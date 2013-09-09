// KxStyleDoc.cpp : implementation of the CKxStyleDoc class
//

#include "stdafx.h"
#include "KxStyle.h"

#include "KxStyleDoc.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKxStyleDoc

IMPLEMENT_DYNCREATE(CKxStyleDoc, CRichEditDoc)

BEGIN_MESSAGE_MAP(CKxStyleDoc, CRichEditDoc)
	//{{AFX_MSG_MAP(CKxStyleDoc)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
	// Enable default OLE container implementation
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, CRichEditDoc::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, CRichEditDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, CRichEditDoc::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKxStyleDoc construction/destruction

CKxStyleDoc::CKxStyleDoc()
{
	// TODO: add one-time construction code here

}

CKxStyleDoc::~CKxStyleDoc()
{
}

BOOL CKxStyleDoc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

CRichEditCntrItem* CKxStyleDoc::CreateClientItem(REOBJECT* preo) const
{
	// cast away constness of this
	return new CKxStyleCntrItem(preo, (CKxStyleDoc*) this);
}



/////////////////////////////////////////////////////////////////////////////
// CKxStyleDoc serialization

void CKxStyleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}

	// Calling the base class CRichEditDoc enables serialization
	//  of the container document's COleClientItem objects.
	// TODO: set CRichEditDoc::m_bRTF = FALSE if you are serializing as text
	CRichEditDoc::Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CKxStyleDoc diagnostics

#ifdef _DEBUG
void CKxStyleDoc::AssertValid() const
{
	CRichEditDoc::AssertValid();
}

void CKxStyleDoc::Dump(CDumpContext& dc) const
{
	CRichEditDoc::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKxStyleDoc commands

void CKxStyleDoc::OnFileOpen() 
{
	// TODO: Add your command handler code here
	CFileDialog openFile(TRUE);
	openFile.DoModal();

	CFileException fx;
	fileCppCode.Open(openFile.GetPathName(), fx);
}
