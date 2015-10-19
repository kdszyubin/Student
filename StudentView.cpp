
// StudentView.cpp : CStudentView ���ʵ��
//

#include "stdafx.h"
#include "MainFrm.h"
#include "InputDlg.h"
#include "MathPg.h"
#include "CompPg.h"
#include "CommPg.h"
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
ON_COMMAND(ID_DLG_INPUT, &CStudentView::OnDlgInput)
ON_COMMAND(ID_DLG_OPEN, &CStudentView::OnDlgOpen)
ON_COMMAND(ID_DLG_COLOR, &CStudentView::OnDlgColor)
ON_COMMAND(ID_SCORE_LESSION, &CStudentView::OnScoreLession)
END_MESSAGE_MAP()

// CStudentView ����/����

CStudentView::CStudentView()
{
	// TODO: �ڴ˴���ӹ������
	m_bTBar = true;
	m_bZs = false;
	m_mlDlg.Create(IDD_INPUT);
	m_sName = "����";
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
	m_mlDlg.SetDlgItemText(IDC_NAME, L"����");
	m_mlDlg.SetDlgItemInt(IDC_MATH, 75);
	m_mlDlg.SetDlgItemInt(IDC_ENG, 90);
	m_mlDlg.SetDlgItemInt(IDC_COMP, 80);
	m_mlDlg.ShowWindow(SW_SHOW);
	
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


void CStudentView::OnDlgInput()
{
	// TODO: �ڴ���������������
	CInputDlg dlg; // �����Ի������
	dlg.m_sName = m_sName; // ��ʼ���Ի������
	dlg.m_iMath = m_iMath;
	dlg.m_iEng = m_iEng;
	dlg.m_iComp = m_iComp;
	if (dlg.DoModal() == IDOK)
	{ // ��ʾ�Ի���
		m_sName = dlg.m_sName; // �����û��������ѡ��
		m_iMath = dlg.m_iMath;
		m_iEng = dlg.m_iEng;
		m_iComp = dlg.m_iComp;
	}
}


void CStudentView::OnDlgOpen()
{
	// TODO: �ڴ���������������
	wchar_t *filters = L"λͼ�ļ�(*.bmp)|*.bmp|�ɽ���ͼ�θ�ʽ�ļ�(*.gif) | *.gif | ����ͼ��ר�����ļ�(*.jpg; *.jpe) | *.jpg; *.jpe | �����ļ�(*.*) | *.* || ";
		CFileDialog fileDlg(TRUE, L"bmp", L"*.bmp",
			OFN_HIDEREADONLY, filters);
	if (fileDlg.DoModal() == IDOK) 
	{
		CString sPath = fileDlg.GetPathName();
		MessageBox(sPath, L"�û�ѡ����ļ�");
	}
}


void CStudentView::OnDlgColor()
{
	// TODO: �ڴ���������������
	CColorDialog colDlg(m_crCol, CC_FULLOPEN);
	if (colDlg.DoModal() == IDOK)
		m_crCol = colDlg.GetColor();
}


void CStudentView::OnScoreLession()
{
	// TODO: �ڴ���������������
    // ��������ҳ����
    CMathPg pgMath;
    CCompPg pgComp;
    CCommPg pgComm;
    // ��ʼ���ؼ�����
    pgMath.m_iAnal = m_iAnal;
    pgMath.m_iAlge = m_iAlge;
    pgMath.m_iProb = m_iProb;
    pgComp.m_iProg = m_iProg;
    pgComp.m_iData = m_iData;
    pgComp.m_iOrga = m_iOrga;
    pgComm.m_iPoli = m_iPoli;
    pgComm.m_iEngl = m_iEngl;
    pgComm.m_iPhys = m_iPhys;
    // �������Ե�����
    CPropertySheet ps(L"�γ̳ɼ�");
    // �������ҳ����
    ps.AddPage(&pgMath);
    ps.AddPage(&pgComp);
    ps.AddPage(&pgComm);
    // ��ʾģʽѡ��Ի���
    if (ps.DoModal() == IDOK)
    {
        // �����û���ѡ�������
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
