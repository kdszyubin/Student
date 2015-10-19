#pragma once


// CCommPg 对话框

class CCommPg : public CPropertyPage
{
	DECLARE_DYNAMIC(CCommPg)

public:
	CCommPg();
	virtual ~CCommPg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_iPoli;
	int m_iEngl;
	int m_iPhys;
};
