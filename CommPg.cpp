// CommPg.cpp : 实现文件
//

#include "stdafx.h"
#include "Student.h"
#include "CommPg.h"
#include "afxdialogex.h"


// CCommPg 对话框

IMPLEMENT_DYNAMIC(CCommPg, CPropertyPage)

CCommPg::CCommPg()
	: CPropertyPage(IDD_COMM)
	, m_iPoli(0)
	, m_iEngl(0)
	, m_iPhys(0)
{

}

CCommPg::~CCommPg()
{
}

void CCommPg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_POLI, m_iPoli);
	DDV_MinMaxInt(pDX, m_iPoli, 0, 100);
	DDX_Text(pDX, IDC_ENGL, m_iEngl);
	DDV_MinMaxInt(pDX, m_iEngl, 0, 100);
	DDX_Text(pDX, IDC_PHYS, m_iPhys);
	DDV_MinMaxInt(pDX, m_iPhys, 0, 100);
}


BEGIN_MESSAGE_MAP(CCommPg, CPropertyPage)
END_MESSAGE_MAP()


// CCommPg 消息处理程序
