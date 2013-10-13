// KxStyleView.h : interface of the CKxStyleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KXSTYLEVIEW_H__20455C18_AB05_42B1_BB75_CA0DD5F06589__INCLUDED_)
#define AFX_KXSTYLEVIEW_H__20455C18_AB05_42B1_BB75_CA0DD5F06589__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "KxStyleDoc.h"
#include "MainFrm.h"

#include "ViewDC.h"

class CKxStyleView : public CScrollView
{
	std::vector<CString> Code;
private:
// 	int  leftChar(std::vector<CString>::iterator itor, char ch);
	void exchangeVecStr(std::vector<CString>&, std::vector<CString>&);
	void removeIndention();
	void removeSpaceLine();
	void findBraces(char braces);


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
	virtual void OnDraw(CDC* pDC);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
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
