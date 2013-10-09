// ViewDC.h: interface for the CViewDC class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWDC_H__9275CA0D_DA09_483C_932C_FBCFAE589CF9__INCLUDED_)
#define AFX_VIEWDC_H__9275CA0D_DA09_483C_932C_FBCFAE589CF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
class CViewDC
{
	CFont font;
	CFont* oldFont;
	LOGFONT lf;

	int textHight;
	CDC* pMainDC;
	int nDC;
public:
	CViewDC(CDC*);
	virtual ~CViewDC();

	void TextOut(std::vector<CString>&);
};

#endif // !defined(AFX_VIEWDC_H__9275CA0D_DA09_483C_932C_FBCFAE589CF9__INCLUDED_)
