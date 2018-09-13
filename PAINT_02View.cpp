// PAINT_02View.cpp : implementation of the CPAINT_02View class
//

#include "stdafx.h"
#include "PAINT_02.h"

#include "PAINT_02Doc.h"
#include "PAINT_02View.h"
#include "Virtual_Heartbeatsignal.h"
//#include "HBSS.h"
#include<windows.h>
#include<ctime>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPAINT_02View

IMPLEMENT_DYNCREATE(CPAINT_02View, CView)

BEGIN_MESSAGE_MAP(CPAINT_02View, CView)
	//{{AFX_MSG_MAP(CPAINT_02View)
	ON_COMMAND(ID_STRAT_DRAW,  &CPAINT_02View::OnStratDraw)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
//	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
//	ON_COMMAND(ID_STOP_DRAW, &CPAINT_02View::OnStopDraw)
//	ON_COMMAND(ID_SAVE_IMAGE, &CPAINT_02View::OnSaveImage)
//	ON_COMMAND(ID_FILE_OPEN, &CPAINT_02View::OnFileOpen)
//	ON_COMMAND(ID_FILE_SAVE, &CPAINT_02View::OnFileSave)
	ON_WM_TIMER()
ON_COMMAND(ID_FILE_OPEN, &CPAINT_02View::OnFileOpen)
ON_COMMAND(ID_FILE_PRINT, &CPAINT_02View::OnFilePrint)
ON_COMMAND(ID_FILE_SAVE, &CPAINT_02View::OnFileSave)
ON_COMMAND(ID_FILE_SAVE_COPY_AS, &CPAINT_02View::OnFileSaveCopyAs)
ON_COMMAND(ID_STOP_DRAW, &CPAINT_02View::OnStopDraw)
ON_COMMAND(ID_RELOAD, &CPAINT_02View::OnReload)
ON_COMMAND(ID_A_I, &CPAINT_02View::OnAI)
ON_COMMAND(ID_SAVE_DATA, &CPAINT_02View::OnSaveData)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPAINT_02View construction/destruction

CPAINT_02View::CPAINT_02View()
{
	HBSS HB(0);
	type=0;
	j = 0;
	kind=1;
	v = 0;
	// TODO: add construction code here

}

CPAINT_02View::~CPAINT_02View()
{
}

BOOL CPAINT_02View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPAINT_02View drawing

void CPAINT_02View::OnDraw(CDC* pDC)
{

	CPAINT_02Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	if(!m_Image.IsNull())
     {
         m_Image.Draw(pDC->m_hDC,0,0);       //CImage类
     }
	if (type == 1 && start == true)
	{
		    RedrawWindow();
		    CRect rect1(5,35,815,350);       //background 
	        CRect rect2(835,35,1050,350);    //data display
	        CRect rect3(5,370,1050,520);     //user's info
		   
			{
			pDC->Rectangle(&rect2);
	        pDC->Rectangle(&rect3);
		    pDC->SetBkMode(TRANSPARENT);
	        pDC->TextOut(855,60,"Heart rate");
	        pDC->TextOut(980,60,"75 bpm");
	          pDC->TextOut(855,95,"P-wave");
	          pDC->TextOut(1008,95,"ms");
	          pDC->TextOut(855,130,"PR interval");
              pDC->TextOut(1008,130,"ms");
	          pDC->TextOut(855,165,"QRS duration");
	          pDC->TextOut(1008,200,"ms");
	          pDC->TextOut(855,235,"Abnormal situation:");
	          pDC->TextOut(45,400,"No.   000213141xxx");
	          pDC->TextOut(345,400,"Name:   Patient1");
	          pDC->TextOut(645,400,"Sex:   Male");
	          pDC->TextOut(840,400,"Age:   60");
	          pDC->TextOut(45,440,"Past Medical History:   Sinus Arrhythmia");
	          pDC->TextOut(45,480,"Info：");
			int i = 0;
			int RAND = 0;
			srand(time(0));
			RAND = rand() % 100;
			if (RAND < 85)
			{
				kind = 1;
			}
			else if (85<= RAND&&RAND < 100)
			{
				kind = rand()%6+1;
				//rand()%11+1;
			}
			if (j > v)
			{
				while (i < 277)
				{
					HB.ADD(Virtual_Heartbeat(i, kind));
					i++;
				}
				v = j + 277;
			}
			pDC->SelectStockObject(BLACK_BRUSH); //设置画刷
			CString str;
			pDC->MoveTo(6, 400);//画线的开始位置
			int k = 0;
            
	        CBrush brush2;
	        CPen pen1,pen2;
	        brush2.CreateSolidBrush(RGB(255,255,255));
			CBrush *poldBrush = pDC ->SelectObject(&brush2);
	        pDC->Rectangle(&rect1);
	       
	        
	       // pDC->SelectObject(poldBrush);
	        int a,b;
	        pen1.CreatePen(PS_DOT,0,RGB(128,128,255));
	        CPen *poldPen=pDC->SelectObject(&pen1);
	        for(a=20;a<815;a=a+15)
		     {
			    pDC->MoveTo(a,35);
			    pDC->LineTo(a,350);
	          }
	        for(b=44;b<350;b=b+9)
	         {
			    pDC->MoveTo(5,b);
			    pDC->LineTo(815,b);
	          }
	          pDC->SelectObject(poldPen);
	         
			  pDC->MoveTo(k*4 + 6, HB.head->heartbeat * (-150) + 200);
			  HBS*pHB = HB.head;
			  HBS*ppHB = HB.head;
			  for (i = 0; i < j-808&&pHB!=HB.tail; i++)
			  {
				  pHB = pHB->next;
			  }
			 /* for (i = 0; ppHB != HB.tail; i++)
			  {
				  ppHB = ppHB->next;
				  if (i > 808)
				  {
					  pHB = pHB->next;
				  }
			  }*/
			  for (i = j; i < 808+j&&pHB!=HB.tail; i++)
			{
				pDC->SetPixel(0, 290, RGB(0, 255, 0));  //设置点的位置及颜色
				pDC->LineTo(k + 6, pHB->heartbeat* (-150) + 200);//换两点之间的线
				pHB = pHB->next;
				k++;
			}
			Sleep(20);
			CClientDC dc(this);//选定当前画图环境
			CPen pen(PS_SOLID, 1, RGB(0, 0, 0));//做一支粗细为1的笔
			dc.SelectObject(&pen);//将pen放到dc上
			dc.Rectangle(5,5, 815, 350);//画一个矩形
			j=j+10;
			start = false;
		} 
		
	}
	if (type == 2 && start == true)
	{
		int k = 0;
		int hi=1;
		HBS*pHB = HB.head;
		for (;pHB!=HB.tail;)
		{
			pDC->SetPixel(0, 290, RGB(0, 255, 0));  //设置点的位置及颜色
			pDC->LineTo(k*0.2+ 6, pHB->heartbeat* (-50) + 70 * hi);//换两点之间的线
			pHB = pHB->next;
			k++;
			if (k% 4040 == 0 && k != 0)
			{
				hi++;
				k = 0;
				pDC->MoveTo(k * 0.2 + 6, HB.head->heartbeat* (-50) + 70 * hi);
			}
		}
		start = false;
	}
	if (type == 3 && start == true)
	{
		period_list ill;
		HBS*phs = HB.head;
		for (;phs!=0 ; )
		{
			period*pp =0;
			pp = new period;
			phs=pp->C_PERIOD(phs,&HB);
			ill.ADD(pp);
			if (phs == HB.tail)
			{
				phs = 0;
			}
		}
		int k = 0;
		int hi = 1;
		HBS*pHB = HB.head;
		period *pp2=ill.head;
		pp2->tailofT = HB.head;
		CPen pen1,pen2;
		pen1.CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
		pen2.CreatePen(PS_SOLID, 0, RGB(255,0, 0));
		for (; pHB != HB.tail;)
		{
			if (pHB == NULL||pp2==NULL)
			{
				break;
			}
			if (pHB == pp2->tailofT)
			{
				pp2 = pp2->next;
			}
			if (pp2->normal == false)
			{
				CPen *poldPen = pDC->SelectObject(&pen2);
				//pHB = pp2->tailofT;
			}
			else
			{
				CPen *poldPen = pDC->SelectObject(&pen1);
			}
			if (pHB == NULL || pp2 == NULL)
			{
				break;
			}
			if (pHB == NULL||pp2 == NULL)
			{
				break;
			}
			pDC->SetPixel(0, 290, RGB(0, 255, 0));  //设置点的位置及颜色
			pDC->LineTo(k*0.2 + 6, pHB->heartbeat* (-50) + 70 * hi);//换两点之间的线
			pHB = pHB->next;
			k++;
			if (k % 4040 == 0 && k != 0)
			{
				hi++;
				k = 0;
				pDC->MoveTo(k * 0.2 + 6, HB.head->heartbeat* (-50) + 70 * hi);
			}
		}
		start = false;
	}
	
}

/////////////////////////////////////////////////////////////////////////////
// CPAINT_02View printing

BOOL CPAINT_02View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPAINT_02View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPAINT_02View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPAINT_02View diagnostics

#ifdef _DEBUG
void CPAINT_02View::AssertValid() const
{
	CView::AssertValid();
}

void CPAINT_02View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPAINT_02Doc* CPAINT_02View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPAINT_02Doc)));
	return (CPAINT_02Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPAINT_02View message handlers

void CPAINT_02View::OnStratDraw() 
{
	type=1;
	j = 0;
	start = true;
	SetTimer(1, 10, NULL);

	/*while(i<3000)
	{
		y[i]=Virtual_Heartbeat(i*100);
		i++;
	}*/
	// TODO: Add your command handler code here
	
}

void CPAINT_02View::OnLButtonDown(UINT nFlags, CPoint point) 
{
    //start=true;
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
}

void CPAINT_02View::OnLButtonUp(UINT nFlags, CPoint point) 
{
    //start=true;
	//Invalidate(false);
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonUp(nFlags, point);
}

void CPAINT_02View::OnMouseMove(UINT nFlags, CPoint point) 
{
	//Invalidate();
	// TODO: Add your message handler code here and/or call default
	
	CView::OnMouseMove(nFlags, point);
}

void CPAINT_02View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (type == 1 &&nIDEvent == 1)
	{
		CDC *pDC = GetDC();  //调用OnDraw(pDC)重画  
		OnDraw(pDC);  
		start =true;
		CView::OnTimer(nIDEvent); 
	}
}


void CPAINT_02View::OnStopDraw()
{
	start=false;
	KillTimer(1);
	// TODO: 在此添加命令处理程序代码
}



void CPAINT_02View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
     CString strFilter;
     CSimpleArray<GUID>aguidFileTypes;
     HRESULT hResult;   //获取CImage支持的图像文件的过滤字符串
     hResult=m_Image.GetExporterFilterString(strFilter,aguidFileTypes,_T("All Image Files"));
     if(FAILED(hResult))
     {
         MessageBox(_T("GetExporterFilter调用失败！"));
         return;
     }
     CFileDialog dlg(TRUE,NULL,NULL,OFN_FILEMUSTEXIST,strFilter);
     if(IDOK!=dlg.DoModal())
         return;
     m_Image.Destroy();
     //将外部图像文件装载到CImage对象中
     hResult=m_Image.Load(dlg.GetFileName());
     if(FAILED(hResult))
     {
         MessageBox(_T("调用图像文件失败！"));
         return;
     }
     //设置主窗口标题栏内容
     CString str;
     str.LoadString(AFX_IDS_APP_TITLE);
     AfxGetMainWnd()->SetWindowText(str+_T("-")+dlg.GetFileName());
     Invalidate();//强制调用OnDraw函数
}


void CPAINT_02View::OnFileSave()
{
	// TODO: 在此添加命令处理程序代码
	

CDC *pDC=GetDC();
 CRect rect;
 GetClientRect(&rect);
 CDC bmemDC;
 bmemDC.CreateCompatibleDC(pDC);
 CBitmap bmprect;
 bmprect.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());
 bmemDC.SelectObject(&bmprect);
 BITMAP mbitmap;
 bmprect.GetBitmap(&mbitmap);
 bmemDC.BitBlt(0,0,mbitmap.bmWidth,mbitmap.bmHeight,pDC,0,0,SRCCOPY);


 
 BITMAPINFOHEADER bih = {0};//位图信息头
 bih.biBitCount = mbitmap.bmBitsPixel;//每个像素字节大小
 bih.biCompression = BI_RGB;
 bih.biHeight = mbitmap.bmHeight;//高度
 bih.biPlanes = 1;
 bih.biSize = sizeof(BITMAPINFOHEADER);
 bih.biSizeImage = mbitmap.bmWidthBytes * mbitmap.bmHeight;//图像数据大小
 bih.biWidth = mbitmap.bmWidth;//宽度
 
 BITMAPFILEHEADER bfh = {0};//位图文件头
 bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);//到位图数据的偏移量
 bfh.bfSize = bfh.bfOffBits + mbitmap.bmWidthBytes * mbitmap.bmHeight;//文件总的大小
 bfh.bfType = (WORD)0x4d42;
 byte * p = new byte[mbitmap.bmWidthBytes * mbitmap.bmHeight];//申请内存保存位图数据
 GetDIBits(bmemDC.m_hDC, (HBITMAP) bmprect.m_hObject, 0, rect.Height(), p,
  (LPBITMAPINFO) &bih, DIB_RGB_COLORS);//获取位图数据

	 LPCTSTR lpszFilter="BMP Files(*.bmp)|*.bmp|任何文件|*.*||";
	CFileDialog dlg(FALSE,lpszFilter,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,lpszFilter,NULL);
	  if(IDOK!=dlg.DoModal())
         return;

	  CString strFileName;
	  strFileName = dlg.GetFileName();
  //strFileName +=".bmp";
  char filename[MAX_PATH];
  strcpy(filename,strFileName);
  FILE *fp = fopen(filename, "w+b");
  fwrite(&bfh, 1, sizeof(BITMAPFILEHEADER), fp);//写入位图文件头 
  fwrite(&bih, 1, sizeof(BITMAPINFOHEADER), fp);//写入位图信息头
  fwrite(p, 1, mbitmap.bmWidthBytes * mbitmap.bmHeight, fp);//写入位图数据
  fclose(fp);
   delete [] p;


}


void CPAINT_02View::OnFileSaveCopyAs()
{

	// TODO: 在此添加命令处理程序代码
	  if(m_Image.IsNull())
     {
         MessageBox(_T("请打开要另存的图像！"));
         return;
     }
     CString strFilter;
     strFilter="bmp位图文件|*.bmp|JPEG图像文件|*.jpg|GIF图像文件|*.gif|PNG图像文件|*.png||";
     CFileDialog dlg(FALSE,NULL,NULL,NULL,strFilter);
     if(IDOK!=dlg.DoModal())
         return;
     //如果没有指定文件扩展名，则为其添加一个
     CString strFileName,strExtension;
     strFileName=dlg.m_ofn.lpstrFile;
     if(dlg.m_ofn.nFileExtension==0)
     {
          switch(dlg.m_ofn.nFilterIndex)
         {
		   case 1:
              strExtension="bmp";
              break;
         case 2:
              strExtension="jpg";
              break;
         case 3:
              strExtension="gif";
              break;
         case 4:
              strExtension="png";
              break;
         default:
              break;
         }
         strFileName=strFileName+_T(".")+strExtension;
     }
     //图像保存
     HRESULT hResult=m_Image.Save(strFileName);
     if(FAILED(hResult))
     {
         MessageBox(_T("保存图像文件失败！"));
     }
}



void CPAINT_02View::OnReload()
{
	// TODO:  在此添加命令处理程序代码
	type = 2;
	start = true;
	CDC *pDC = GetDC();  //调用OnDraw(pDC)重画  
	OnDraw(pDC);
}


void CPAINT_02View::OnAI()
{
	// TODO:  在此添加命令处理程序代码
	type = 3;
	start = true;
	CDC *pDC = GetDC();  //调用OnDraw(pDC)重画  
	OnDraw(pDC);
}


void CPAINT_02View::OnSaveData()
{
	// TODO: 在此添加命令处理程序代码
	 LPCTSTR lpszFilter="txt Files|*.txt|任何文件|*.*||";
	CFileDialog dlg(FALSE,lpszFilter,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,lpszFilter,NULL);
	 if(IDOK!=dlg.DoModal())
         return;
	 
	  CString strFileName;
	  strFileName = dlg.GetFileName();
      char filename[MAX_PATH];
	  strcpy(filename,strFileName);
      FILE *fp = fopen(filename, "w+t");
	  //HBS*pp=0;
	  //HBS *hhead;
   // string strFileName;
	//strFileName=dlg.m_ofn.lpstrFile;
	 //strFileName=_T("D:\\")+strFileName+_T(".txt");
	//ofstream ofile;
	//ofile.open(strFileName);
	//pp = hhead;
	//for (; pp != 0;)
	//{
		//ofile << pp->heartbeat << endl;
		//pp = pp->next;
	//}
	 fclose(fp);
     //delete [] p;
	//ofile.close();
}
