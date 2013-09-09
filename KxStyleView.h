// KxStyleView.h : interface of the CKxStyleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KXSTYLEVIEW_H__20455C18_AB05_42B1_BB75_CA0DD5F06589__INCLUDED_)
#define AFX_KXSTYLEVIEW_H__20455C18_AB05_42B1_BB75_CA0DD5F06589__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CKxStyleCntrItem;

class CKxStyleView : public CRichEditView
{
protected: // create from serialization only
	CKxStyleView();
	DECLARE_DYNCREATE(CKxStyleView)

// Attributes
public:
	CKxStyleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKxStyleView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKxStyleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKxStyleView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in KxStyleView.cpp
inline CKxStyleDoc* CKxStyleView::GetDocument()
   { return (CKxStyleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KXSTYLEVIEW_H__20455C18_AB05_42B1_BB75_CA0DD5F06589__INCLUDED_)
