// KxStyleDoc.cpp : implementation of the CKxStyleDoc class
//

#include "stdafx.h"
#include "KxStyle.h"

#include "KxStyleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKxStyleDoc

IMPLEMENT_DYNCREATE(CKxStyleDoc, CDocument)

BEGIN_MESSAGE_MAP(CKxStyleDoc, CDocument)
	//{{AFX_MSG_MAP(CKxStyleDoc)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
	// Enable default OLE container implementation
// 	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, CDocument::OnUpdateEditLinksMenu)
// 	ON_COMMAND(ID_OLE_EDIT_LINKS, CDocument::OnEditLinks)
// 	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, CDocument::OnUpdateObjectVerbMenu)
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
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

// CRichEditCntrItem* CKxStyleDoc::CreateClientItem(REOBJECT* preo) const
// {
// 	// cast away constness of this
// 	return new CKxStyleCntrItem(preo, (CKxStyleDoc*) this);
// }



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

	// Calling the base class CDocument enables serialization
	//  of the container document's COleClientItem objects.
	// TODO: set CDocument::m_bRTF = FALSE if you are serializing as text
	CDocument::Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CKxStyleDoc diagnostics

#ifdef _DEBUG
void CKxStyleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKxStyleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKxStyleDoc commands

void CKxStyleDoc::OnFileOpen() 
{
	// TODO: Add your command handler code here
	CFileDialog openFile(TRUE);
	openFile.DoModal();

	CTxtFile fileCppCode;
	CFileException fx;
	fileCppCode.Open(openFile.GetPathName(), fx);
	fileCppCode.oTxtData(dataCppCode);

	UpdateAllViews(NULL);
}

void CKxStyleDoc::oData(std::vector<CString>& vCode)
{
	vCode = dataCppCode;
}
