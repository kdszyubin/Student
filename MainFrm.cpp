
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "Student.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
END_MESSAGE_MAP()

/*static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};*/

static UINT indicators[] =
{
	ID_SEPARATOR, //提示 nIndex = 0
	ID_SEPARATOR, //进度条 nIndex = 1
	ID_SEPARATOR, //“x:” nIndex = 2
	ID_SEPARATOR, //x值 nIndex = 3
	ID_SEPARATOR, //“y:” nIndex = 4
	ID_SEPARATOR, //y值 nIndex = 5
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | /*WS_VISIBLE |*/ CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_ToolBar.LoadToolBar(IDR_MYTB))
	{
		TRACE0("未能创建工具栏\n");
		return -1;		//未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	m_wndStatusBar.SetPaneInfo(0, prompt, SBPS_STRETCH, 0); //提示
	m_wndStatusBar.SetPaneInfo(1, progress, SBPS_NORMAL, 200);
	m_wndStatusBar.SetPaneText(progress, L"显示进度条");
	m_wndStatusBar.SetPaneInfo(2, xName, SBPS_NOBORDERS, 8); //"x:"
	m_wndStatusBar.SetPaneText(xName, L"x:");
	m_wndStatusBar.SetPaneInfo(3, xVal, SBPS_NORMAL, 24); //x值
	m_wndStatusBar.SetPaneInfo(4, yName, SBPS_NOBORDERS, 8);//"y:"
	m_wndStatusBar.SetPaneText(yName, L"y:");
	m_wndStatusBar.SetPaneInfo(5, yVal, SBPS_NORMAL, 24); //y值
	CRect rect;
	m_wndStatusBar.GetItemRect(progress, &rect);
	m_Progress.Create(WS_CHILD | WS_VISIBLE, rect,
		&m_wndStatusBar, 1111);

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	m_ToolBar.EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_ToolBar);
	ShowControlBar(&m_ToolBar, FALSE, FALSE);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



void CMainFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CFrameWnd::OnPaint()
	CRect rect;
	m_wndStatusBar.GetItemRect(progress, &rect);
	m_Progress.SetWindowPos(NULL, rect.left, rect.top,
		rect.Width(), rect.Height(), SWP_NOZORDER);
}
