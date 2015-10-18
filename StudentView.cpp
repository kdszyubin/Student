
// StudentView.cpp : CStudentView ���ʵ��
//

#include "stdafx.h"
#include "MainFrm.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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
END_MESSAGE_MAP()

// CStudentView ����/����

CStudentView::CStudentView()
{
	// TODO: �ڴ˴���ӹ������
	m_bTBar = true;
	m_bZs = false;
}

CStudentView::~CStudentView()
{
}

BOOL CStudentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CStudentView ����

void CStudentView::OnDraw(CDC* /*pDC*/)
{
	CStudentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CStudentView ��ӡ

BOOL CStudentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CStudentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CStudentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CStudentView ���

#ifdef _DEBUG
void CStudentView::AssertValid() const
{
	CView::AssertValid();
}

void CStudentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStudentDoc* CStudentView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentDoc)));
	return (CStudentDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudentView ��Ϣ�������


void CStudentView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	CFrameWnd *pFrmWnd = GetTopLevelFrame(); //��ȡס��ܴ��ڶ���
	CMenu *pMenu = pFrmWnd->GetMenu(); //��ȡ�˵���
	CMenu *pSubMenu = pMenu->GetSubMenu(4); //��ȡ�ɼ��˵����˵����
								//��0��ʼ��������ֵӦ�����Լ��˵����е�һ��
	CBitmap *pBmp = new CBitmap(); //������λͼ����
	pBmp->LoadBitmap(IDB_MATH); //װ��λͼ��Դ
	//���ò˵���ͼ�꣬ǰһ���ʹ�ò˵���ID����һע�͵������ʹ�ò˵������
	pSubMenu->SetMenuItemBitmaps(ID_SCORE_MATH, MF_BYCOMMAND, pBmp, pBmp);
	//pSubMenu->SetMenuItemBitmaps(0, MF_BYPOSITION, pBmp, pBmp);
}


void CStudentView::OnNameZs()
{
	// TODO: �ڴ���������������
	MessageBox(L"����", L"����");
	m_bZs = !m_bZs;
	
}


void CStudentView::OnNameLs()
{
	// TODO: �ڴ���������������
	MessageBox(L"����", L"����");
}


void CStudentView::OnNameWw()
{
	// TODO: �ڴ���������������
	MessageBox(L"����", L"����");
}


void CStudentView::OnScoreComp()
{
	// TODO: �ڴ���������������
	MessageBox(L"�������0��", L"�ɼ�");
}


void CStudentView::OnScoreEng()
{
	// TODO: �ڴ���������������
	MessageBox(L"Ӣ�10��", L"�ɼ�");
}


void CStudentView::OnScoreMath()
{
	// TODO: �ڴ���������������
	MessageBox(L"��ѧ��80��", L"�ɼ�");
}


void CStudentView::OnTest()
{
	// TODO: �ڴ���������������
	MessageBox(L"����˵���", L"����");
}


void CStudentView::OnUpdateTest(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->Enable(FALSE);
	pCmdUI->SetCheck(1);
}


//void CStudentView::OnUpdateNameZs(CCmdUI *pCmdUI)
//{
//	// TODO: �ڴ������������û����洦��������
//	static BOOL isCheck = FALSE;
//	if (!isCheck)
//		pCmdUI->SetCheck(1);
//	else
//		pCmdUI->SetCheck(0);
//	isCheck = !isCheck;
//}


//void CStudentView::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	CView::OnMouseMove(nFlags, point);
//}


void CStudentView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: �ڴ˴������Ϣ����������
	CMenu menu;
	menu.LoadMenu(IDR_EDIT_MENU);
	menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}


void CStudentView::OnViewChangeTb()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_bZs);
}


void CStudentView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	wchar_t buf[20];
	CMainFrame *pFrmWnd = (CMainFrame*)GetTopLevelFrame();
	_itow_s(point.x, buf, 20, 10);
	pFrmWnd->m_wndStatusBar.SetPaneText(pFrmWnd->xVal, buf);
	_itow_s(point.y, buf, 20, 10);
	pFrmWnd->m_wndStatusBar.SetPaneText(pFrmWnd->yVal, buf);

	CView::OnMouseMove(nFlags, point);
}
