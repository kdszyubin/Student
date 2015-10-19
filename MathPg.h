#pragma once


// CMathPg 对话框

class CMathPg : public CPropertyPage
{
	DECLARE_DYNAMIC(CMathPg)

public:
	CMathPg();
	virtual ~CMathPg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MATH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_iAnal;
	int m_iAlge;
	int m_iProb;
};
