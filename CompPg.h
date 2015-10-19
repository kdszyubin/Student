#pragma once


// CCompPg 对话框

class CCompPg : public CPropertyPage
{
	DECLARE_DYNAMIC(CCompPg)

public:
	CCompPg();
	virtual ~CCompPg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_iProg;
	int m_iData;
	int m_iOrga;
};
