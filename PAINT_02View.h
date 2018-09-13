// PAINT_02View.h : interface of the CPAINT_02View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PAINT_02VIEW_H__2F99F8A4_A9DA_4DA5_B6F6_75C1C4FEF74E__INCLUDED_)
#define AFX_PAINT_02VIEW_H__2F99F8A4_A9DA_4DA5_B6F6_75C1C4FEF74E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"HBSS.h"
#include<iostream>
using namespace std;

class CPAINT_02View : public CView
{
protected: // create from serialization only
	CPAINT_02View();
	DECLARE_DYNCREATE(CPAINT_02View)

// Attributes
public:
	CPAINT_02Doc* GetDocument();
	HBSS HB;
	int type;
	bool start;
	CImage m_Image;
	int j;
	int kind;
	int v;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPAINT_02View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnTimer(UINT_PTR nIDEvent);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPAINT_02View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPAINT_02View)
	afx_msg void OnStratDraw();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnStopDraw();
//	afx_msg void OnSaveImage();
//	afx_msg void OnFileOpen();
//	afx_msg void OnFileSave();
//	afx_msg void OnFileSaveAs();
	afx_msg void OnFileOpen();
//	afx_msg void OnFilePrint();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveCopyAs();
	afx_msg void OnStopDraw();
	afx_msg void OnReload();
	afx_msg void OnAI();
	afx_msg void OnSaveData();
};

#ifndef _DEBUG  // debug version in PAINT_02View.cpp
inline CPAINT_02Doc* CPAINT_02View::GetDocument()
   { return (CPAINT_02Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINT_02VIEW_H__2F99F8A4_A9DA_4DA5_B6F6_75C1C4FEF74E__INCLUDED_)
