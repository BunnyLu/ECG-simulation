// PAINT_02.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "PAINT_02.h"

#include "MainFrm.h"
#include "PAINT_02Doc.h"
#include "PAINT_02View.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPAINT_02App

BEGIN_MESSAGE_MAP(CPAINT_02App, CWinApp)
	//{{AFX_MSG_MAP(CPAINT_02App)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
//	ON_COMMAND(ID_SAVE_DATA, &CPAINT_02App::OnSaveData)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPAINT_02App construction

CPAINT_02App::CPAINT_02App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPAINT_02App object

CPAINT_02App theApp;

/////////////////////////////////////////////////////////////////////////////
// CPAINT_02App initialization

BOOL CPAINT_02App::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CPAINT_02Doc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CPAINT_02View));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnUpdate32774(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32775(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32776(CCmdUI *pCmdUI);
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
	ON_UPDATE_COMMAND_UI(ID_32774, &CAboutDlg::OnUpdate32774)
	ON_UPDATE_COMMAND_UI(ID_32775, &CAboutDlg::OnUpdate32775)
	ON_UPDATE_COMMAND_UI(ID_32776, &CAboutDlg::OnUpdate32776)
END_MESSAGE_MAP()

// App command to run the dialog
void CPAINT_02App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CPAINT_02App message handlers



void CAboutDlg::OnUpdate32774(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
}


void CAboutDlg::OnUpdate32775(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
}


void CAboutDlg::OnUpdate32776(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
}


/*void CPAINT_02App::OnSaveData()
{
	// TODO: 在此添加命令处理程序代码
	string strFilter;
	strFilter="txt文本文档|*.txt";
	CFileDialog dlg(FALSE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,strFilter);
	 if(IDOK!=dlg.DoModal())
         return;
	  HBS*pp=0;
	  HBS *hhead;
    string strFileName;
	strFileName=dlg.m_ofn.lpstrFile;
	 strFileName=_T("D:\\")+strFileName+_T(".txt");
	ofstream ofile;
	ofile.open(strFileName);
	pp = hhead;
	for (; pp != 0;)
	{
		ofile << pp->heartbeat << endl;
		pp = pp->next;
	}
	ofile.close(); 
}*/
