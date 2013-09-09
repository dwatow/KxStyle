// CntrItem.h : interface of the CKxStyleCntrItem class
//

#if !defined(AFX_CNTRITEM_H__F8343DE8_493D_4A17_A420_1E7721C37E32__INCLUDED_)
#define AFX_CNTRITEM_H__F8343DE8_493D_4A17_A420_1E7721C37E32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CKxStyleDoc;
class CKxStyleView;

class CKxStyleCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CKxStyleCntrItem)

// Constructors
public:
	CKxStyleCntrItem(REOBJECT* preo = NULL, CKxStyleDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CKxStyleDoc* GetDocument()
		{ return (CKxStyleDoc*)CRichEditCntrItem::GetDocument(); }
	CKxStyleView* GetActiveView()
		{ return (CKxStyleView*)CRichEditCntrItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKxStyleCntrItem)
	public:
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	~CKxStyleCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNTRITEM_H__F8343DE8_493D_4A17_A420_1E7721C37E32__INCLUDED_)
