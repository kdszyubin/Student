
// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};*/

static UINT indicators[] =
{
	ID_SEPARATOR, //��ʾ nIndex = 0
	ID_SEPARATOR, //������ nIndex = 1
	ID_SEPARATOR, //��x:�� nIndex = 2
	ID_SEPARATOR, //xֵ nIndex = 3
	ID_SEPARATOR, //��y:�� nIndex = 4
	ID_SEPARATOR, //yֵ nIndex = 5
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
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
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | /*WS_VISIBLE |*/ CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_ToolBar.LoadToolBar(IDR_MYTB))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;		//δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	m_wndStatusBar.SetPaneInfo(0, prompt, SBPS_STRETCH, 0); //��ʾ
	m_wndStatusBar.SetPaneInfo(1, progress, SBPS_NORMAL, 200);
	m_wndStatusBar.SetPaneText(progress, L"��ʾ������");
	m_wndStatusBar.SetPaneInfo(2, xName, SBPS_NOBORDERS, 8); //"x:"
	m_wndStatusBar.SetPaneText(xName, L"x:");
	m_wndStatusBar.SetPaneInfo(3, xVal, SBPS_NORMAL, 24); //xֵ
	m_wndStatusBar.SetPaneInfo(4, yName, SBPS_NOBORDERS, 8);//"y:"
	m_wndStatusBar.SetPaneText(yName, L"y:");
	m_wndStatusBar.SetPaneInfo(5, yVal, SBPS_NORMAL, 24); //yֵ
	CRect rect;
	m_wndStatusBar.GetItemRect(progress, &rect);
	m_Progress.Create(WS_CHILD | WS_VISIBLE, rect,
		&m_wndStatusBar, 1111);

	// TODO: �������Ҫ��ͣ������������ɾ��������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

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


// CMainFrame ��Ϣ�������



void CMainFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CFrameWnd::OnPaint()
	CRect rect;
	m_wndStatusBar.GetItemRect(progress, &rect);
	m_Progress.SetWindowPos(NULL, rect.left, rect.top,
		rect.Width(), rect.Height(), SWP_NOZORDER);
}
