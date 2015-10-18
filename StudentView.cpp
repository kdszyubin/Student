
// StudentView.cpp : CStudentView 类的实现
//

#include "stdafx.h"
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
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

// CStudentView 构造/析构

CStudentView::CStudentView()
{
	// TODO: 在此处添加构造代码
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


void CStudentView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 在此处添加消息处理程序代码
	CMenu menu;
	menu.LoadMenu(IDR_EDIT_MENU);
	menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}
