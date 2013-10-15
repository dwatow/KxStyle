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
	BOOL IsInComment;
	std::vector<CString> ViewCode;
	std::vector<CString> Code;
	std::vector<CString> Include;
	std::vector<CString> UsingNameSpace;
private:
// 	int  leftChar(std::vector<CString>::iterator itor, char ch);
	void exchangeVecStr(std::vector<CString>&, std::vector<CString>&);  //�洫
	void cutCode();
	void forView();

	//�����ª�coding style
	void removeIndention(); //�����e���M�᭱���ťթM'\t'
	void removeSpaceLine(); //�����u���ťժ��@��

	//��������
	void singleSemicolon();   //�����u���������@��
	void multipleSemicolon(); //�����u���������@��
	void removeSemicolon();

	//���ʤj�A��
	BOOL IsComment(const CString& line);
	BOOL IsStringFormat(const CString& line);
	BOOL IsCtrlItemInit(const CString& line);
// 	void sortOutBraces(std::vector<CString>&, CString linecode, const char&);
	void findBraces();                                 //���s��m�j�A��
	void findLBraces(std::vector<CString>&, CString);
	void findRBraces(std::vector<CString>&, CString);

	void sortOutForIf();
	//�[�W�Y��
	void addIndention(int nSpace = 4);             //�Y�Ƴ]�w
	CString remakeIndention(int Lv, int LengthSpace);  //�����Y��

// 	removeOneLineInIndent


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
