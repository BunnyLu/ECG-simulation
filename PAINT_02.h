// PAINT_02.h : main header file for the PAINT_02 application
//

#if !defined(AFX_PAINT_02_H__3B908B85_0AAB_42B8_B6D1_FC96686DF4CE__INCLUDED_)
#define AFX_PAINT_02_H__3B908B85_0AAB_42B8_B6D1_FC96686DF4CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPAINT_02App:
// See PAINT_02.cpp for the implementation of this class
//

class CPAINT_02App : public CWinApp
{
public:
	CPAINT_02App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPAINT_02App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPAINT_02App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
//	afx_msg void OnSaveData();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINT_02_H__3B908B85_0AAB_42B8_B6D1_FC96686DF4CE__INCLUDED_)
