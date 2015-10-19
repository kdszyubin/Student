
// StudentView.cpp : CStudentView 类的实现
//

#include "stdafx.h"
#include "MainFrm.h"
#include "InputDlg.h"
#include "MathPg.h"
#include "CompPg.h"
#include "CommPg.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Student.h"
#endif

#include "StudentDoc.h"
#include "StudentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStudentView

IMPLEMENT_DYNCREATE(CStudentView, CView)

BEGIN_MESSAGE_MAP(CStudentView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_NAME_ZS, &CStudentView::OnNameZs)
	ON_COMMAND(ID_NAME_LS, &CStudentView::OnNameLs)
	ON_COMMAND(ID_NAME_WW, &CStudentView::OnNameWw)
	ON_COMMAND(ID_SCORE_COMP, &CStudentView::OnScoreComp)
	ON_COMMAND(ID_SCORE_ENG, &CStudentView::OnScoreEng)
	ON_COMMAND(ID_SCORE_MATH, &CStudentView::OnScoreMath)
	ON_COMMAND(ID_TEST, &CStudentView::OnTest)
	ON_UPDATE_COMMAND_UI(ID_TEST, &CStudentView::OnUpdateTest)
//	ON_UPDATE_COMMAND_UI(ID_NAME_ZS, &CStudentView::OnUpdateNameZs)
//	ON_WM_MOUSEMOVE()
ON_WM_CONTEXTMENU()
ON_COMMAND(ID_VIEW_CHANGE_TB, &CStudentView::OnViewChangeTb)
ON_UPDATE_COMMAND_UI(ID_NAME_ZS, &CStudentView::OnUpdateNameZs)
ON_WM_MOUSEMOVE()
ON_COMMAND(ID_DLG_INPUT, &CStudentView::OnDlgInput)
ON_COMMAND(ID_DLG_OPEN, &CStudentView::OnDlgOpen)
ON_COMMAND(ID_DLG_COLOR, &CStudentView::OnDlgColor)
ON_COMMAND(ID_SCORE_LESSION, &CStudentView::OnScoreLession)
END_MESSAGE_MAP()

// CStudentView 构造/析构

CStudentView::CStudentView()
{
	// TODO: 在此处添加构造代码
	m_bTBar = true;
	m_bZs = false;
	m_mlDlg.Create(IDD_INPUT);
	m_sName = "张三";
	m_iMath = 80;
	m_iEng = 70;
	m_iComp = 60;
	m_crCol = RGB(255, 0, 0);
    m_iAnal = 0;
    m_iAlge = 0;
    m_iProb = 0;
	m_iProg = 0;
	m_iData = 0;
	m_iOrga = 0;
	m_iPoli = 0;
	m_iEngl = 0;
	m_iPhys = 0;
}

CStudentView::~CStudentView()
{
}

BOOL CStudentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CStudentView 绘制

void CStudentView::OnDraw(CDC* /*pDC*/)
{
	CStudentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CStudentView 打印

BOOL CStudentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CStudentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CStudentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CStudentView 诊断

#ifdef _DEBUG
void CStudentView::AssertValid() const
{
	CView::AssertValid();
}

void CStudentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStudentDoc* CStudentView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentDoc)));
	return (CStudentDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudentView 消息处理程序


void CStudentView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	CFrameWnd *pFrmWnd = GetTopLevelFrame(); //获取住框架窗口对象
	CMenu *pMenu = pFrmWnd->GetMenu(); //获取菜单条
	CMenu *pSubMenu = pMenu->GetSubMenu(4); //获取成绩菜单，菜单序号
								//从0开始，具体数值应与你自己菜单条中的一致
	CBitmap *pBmp = new CBitmap(); //创建空位图对象
	pBmp->LoadBitmap(IDB_MATH); //装入位图资源
	//设置菜单项图标，前一语句使用菜单项ID，后一注释掉的语句使用菜单项序号
	pSubMenu->SetMenuItemBitmaps(ID_SCORE_MATH, MF_BYCOMMAND, pBmp, pBmp);
	//pSubMenu->SetMenuItemBitmaps(0, MF_BYPOSITION, pBmp, pBmp);
}


void CStudentView::OnNameZs()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(L"张三", L"姓名");
	m_bZs = !m_bZs;
	m_mlDlg.SetDlgItemText(IDC_NAME, L"张三");
	m_mlDlg.SetDlgItemInt(IDC_MATH, 75);
	m_mlDlg.SetDlgItemInt(IDC_ENG, 90);
	m_mlDlg.SetDlgItemInt(IDC_COMP, 80);
	m_mlDlg.ShowWindow(SW_SHOW);
	
}


void CStudentView::OnNameLs()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(L"李四", L"姓名");
}


void CStudentView::OnNameWw()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(L"王五", L"姓名");
}


void CStudentView::OnScoreComp()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(L"计算机：0分", L"成绩");
}


void CStudentView::OnScoreEng()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(L"英语：10分", L"成绩");
}


void CStudentView::OnScoreMath()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(L"数学：80分", L"成绩");
}


void CStudentView::OnTest()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(L"顶层菜单项", L"测试");
}


void CStudentView::OnUpdateTest(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(FALSE);
	pCmdUI->SetCheck(1);
}


//void CStudentView::OnUpdateNameZs(CCmdUI *pCmdUI)
//{
//	// TODO: 在此添加命令更新用户界面处理程序代码
//	static BOOL isCheck = FALSE;
//	if (!isCheck)
//		pCmdUI->SetCheck(1);
//	else
//		pCmdUI->SetCheck(0);
//	isCheck = !isCheck;
//}


//void CStudentView::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//
//	CView::OnMouseMove(nFlags, point);
//}


void CStudentView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 在此处添加消息处理程序代码
	CMenu menu;
	menu.LoadMenu(IDR_EDIT_MENU);
	menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}


void CStudentView::OnViewChangeTb()
{
	// TODO: 在此添加命令处理程序代码
	CMainFrame *pFrmWnd = (CMainFrame*)GetTopLevelFrame();
	if (m_bTBar)
	{
		if (m_bTBar)
		{
			pFrmWnd->ShowControlBar(&pFrmWnd->m_wndToolBar, FALSE, FALSE);
			pFrmWnd->ShowControlBar(&pFrmWnd->m_ToolBar, TRUE, FALSE);
			m_bTBar = false;
		}
	}
	else
	{
		pFrmWnd->ShowControlBar(&pFrmWnd->m_ToolBar, FALSE, FALSE);
		pFrmWnd->ShowControlBar(&pFrmWnd->m_wndToolBar, TRUE, FALSE);
		m_bTBar = true;
	}
}


void CStudentView::OnUpdateNameZs(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_bZs);
}


void CStudentView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	wchar_t buf[20];
	CMainFrame *pFrmWnd = (CMainFrame*)GetTopLevelFrame();
	_itow_s(point.x, buf, 20, 10);
	pFrmWnd->m_wndStatusBar.SetPaneText(pFrmWnd->xVal, buf);
	_itow_s(point.y, buf, 20, 10);
	pFrmWnd->m_wndStatusBar.SetPaneText(pFrmWnd->yVal, buf);

	CView::OnMouseMove(nFlags, point);
}


void CStudentView::OnDlgInput()
{
	// TODO: 在此添加命令处理程序代码
	CInputDlg dlg; // 创建对话框对象
	dlg.m_sName = m_sName; // 初始化对话框变量
	dlg.m_iMath = m_iMath;
	dlg.m_iEng = m_iEng;
	dlg.m_iComp = m_iComp;
	if (dlg.DoModal() == IDOK)
	{ // 显示对话框
		m_sName = dlg.m_sName; // 保存用户的输入和选择
		m_iMath = dlg.m_iMath;
		m_iEng = dlg.m_iEng;
		m_iComp = dlg.m_iComp;
	}
}


void CStudentView::OnDlgOpen()
{
	// TODO: 在此添加命令处理程序代码
	wchar_t *filters = L"位图文件(*.bmp)|*.bmp|可交换图形格式文件(*.gif) | *.gif | 联合图像专家组文件(*.jpg; *.jpe) | *.jpg; *.jpe | 所有文件(*.*) | *.* || ";
		CFileDialog fileDlg(TRUE, L"bmp", L"*.bmp",
			OFN_HIDEREADONLY, filters);
	if (fileDlg.DoModal() == IDOK) 
	{
		CString sPath = fileDlg.GetPathName();
		MessageBox(sPath, L"用户选择的文件");
	}
}


void CStudentView::OnDlgColor()
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog colDlg(m_crCol, CC_FULLOPEN);
	if (colDlg.DoModal() == IDOK)
		m_crCol = colDlg.GetColor();
}


void CStudentView::OnScoreLession()
{
	// TODO: 在此添加命令处理程序代码
    // 创建属性页对象
    CMathPg pgMath;
    CCompPg pgComp;
    CCommPg pgComm;
    // 初始化控件变量
    pgMath.m_iAnal = m_iAnal;
    pgMath.m_iAlge = m_iAlge;
    pgMath.m_iProb = m_iProb;
    pgComp.m_iProg = m_iProg;
    pgComp.m_iData = m_iData;
    pgComp.m_iOrga = m_iOrga;
    pgComm.m_iPoli = m_iPoli;
    pgComm.m_iEngl = m_iEngl;
    pgComm.m_iPhys = m_iPhys;
    // 创建属性单对象
    CPropertySheet ps(L"课程成绩");
    // 添加属性页对象
    ps.AddPage(&pgMath);
    ps.AddPage(&pgComp);
    ps.AddPage(&pgComm);
    // 显示模式选项卡对话框
    if (ps.DoModal() == IDOK)
    {
        // 保存用户的选择和输入
        m_iAnal = pgMath.m_iAnal;
        m_iAlge = pgMath.m_iAlge;
        m_iProb = pgMath.m_iProb;
	    m_iProg = pgComp.m_iProg;
	    m_iData = pgComp.m_iData;
	    m_iOrga = pgComp.m_iOrga;
	    m_iPoli = pgComm.m_iPoli;
	    m_iEngl = pgComm.m_iEngl;
	    m_iPhys = pgComm.m_iPhys;
    }

}
