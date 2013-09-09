// KxStyle.h : main header file for the KXSTYLE application
//

#if !defined(AFX_KXSTYLE_H__878B2367_97B5_44B0_88F4_10E8AB341514__INCLUDED_)
#define AFX_KXSTYLE_H__878B2367_97B5_44B0_88F4_10E8AB341514__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CKxStyleApp:
// See KxStyle.cpp for the implementation of this class
//

class CKxStyleApp : public CWinApp
{
public:
	CKxStyleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKxStyleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CKxStyleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KXSTYLE_H__878B2367_97B5_44B0_88F4_10E8AB341514__INCLUDED_)
