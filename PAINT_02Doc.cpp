// PAINT_02Doc.cpp : implementation of the CPAINT_02Doc class
//

#include "stdafx.h"
#include "PAINT_02.h"

#include "PAINT_02Doc.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPAINT_02Doc

IMPLEMENT_DYNCREATE(CPAINT_02Doc, CDocument)

BEGIN_MESSAGE_MAP(CPAINT_02Doc, CDocument)
	//{{AFX_MSG_MAP(CPAINT_02Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPAINT_02Doc construction/destruction

CPAINT_02Doc::CPAINT_02Doc()
{
	// TODO: add one-time construction code here

}

CPAINT_02Doc::~CPAINT_02Doc()
{
}

BOOL CPAINT_02Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPAINT_02Doc serialization

void CPAINT_02Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPAINT_02Doc diagnostics

#ifdef _DEBUG
void CPAINT_02Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPAINT_02Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPAINT_02Doc commands
