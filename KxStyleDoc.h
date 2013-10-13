// KxStyleDoc.h : interface of the CKxStyleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KXSTYLEDOC_H__54E177E8_CB9E_4E9E_A0BA_C28A4E9DDEA3__INCLUDED_)
#define AFX_KXSTYLEDOC_H__54E177E8_CB9E_4E9E_A0BA_C28A4E9DDEA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TxtFile.h"

class CKxStyleDoc : public CDocument
{
	TxtStrData dataCppCode;
protected: // create from serialization only
	CKxStyleDoc();
	DECLARE_DYNCREATE(CKxStyleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKxStyleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL
// 	virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo) const;

// Implementation
public:
	void oData(std::vector<CString>&);
	virtual ~CKxStyleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKxStyleDoc)
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KXSTYLEDOC_H__54E177E8_CB9E_4E9E_A0BA_C28A4E9DDEA3__INCLUDED_)
