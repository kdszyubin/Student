// InputDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Student.h"
#include "InputDlg.h"
#include "afxdialogex.h"


// CInputDlg 对话框

IMPLEMENT_DYNAMIC(CInputDlg, CDialogEx)

CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INPUT, pParent)
	, m_sName(_T(""))
	, m_iMath(0)
	, m_iEng(0)
	, m_iComp(0)
{

}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, m_sName);
	DDV_MaxChars(pDX, m_sName, 4);
	DDX_Text(pDX, IDC_MATH, m_iMath);
	DDV_MinMaxInt(pDX, m_iMath, 0, 100);
	DDX_Text(pDX, IDC_ENG, m_iEng);
	DDV_MinMaxInt(pDX, m_iEng, 0, 100);
	DDX_Text(pDX, IDC_COMP, m_iComp);
	DDV_MinMaxInt(pDX, m_iComp, 0, 100);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialogEx)
END_MESSAGE_MAP()


// CInputDlg 消息处理程序
