// MathPg.cpp : 实现文件
//

#include "stdafx.h"
#include "Student.h"
#include "MathPg.h"
#include "afxdialogex.h"


// CMathPg 对话框

IMPLEMENT_DYNAMIC(CMathPg, CPropertyPage)

CMathPg::CMathPg()
	: CPropertyPage(IDD_MATH)
	, m_iAnal(0)
	, m_iAlge(0)
	, m_iProb(0)
{

}

CMathPg::~CMathPg()
{
}

void CMathPg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ANAL, m_iAnal);
	DDV_MinMaxInt(pDX, m_iAnal, 0, 100);
	DDX_Text(pDX, IDC_ALGE, m_iAlge);
	DDV_MinMaxInt(pDX, m_iAlge, 0, 100);
	DDX_Text(pDX, IDC_PROB, m_iProb);
	DDV_MinMaxInt(pDX, m_iProb, 0, 100);
}


BEGIN_MESSAGE_MAP(CMathPg, CPropertyPage)
END_MESSAGE_MAP()


// CMathPg 消息处理程序
