// CompPg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Student.h"
#include "CompPg.h"
#include "afxdialogex.h"


// CCompPg �Ի���

IMPLEMENT_DYNAMIC(CCompPg, CPropertyPage)

CCompPg::CCompPg()
	: CPropertyPage(IDD_COMP)
	, m_iProg(0)
	, m_iData(0)
	, m_iOrga(0)
{

}

CCompPg::~CCompPg()
{
}

void CCompPg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PROG, m_iProg);
	DDV_MinMaxInt(pDX, m_iProg, 0, 100);
	DDX_Text(pDX, IDC_DATA, m_iData);
	DDV_MinMaxInt(pDX, m_iData, 0, 100);
	DDX_Text(pDX, IDC_ORGA, m_iOrga);
	DDV_MinMaxInt(pDX, m_iOrga, 0, 100);
}


BEGIN_MESSAGE_MAP(CCompPg, CPropertyPage)
END_MESSAGE_MAP()


// CCompPg ��Ϣ�������
