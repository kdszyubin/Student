#pragma once


// CMathPg �Ի���

class CMathPg : public CPropertyPage
{
	DECLARE_DYNAMIC(CMathPg)

public:
	CMathPg();
	virtual ~CMathPg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MATH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_iAnal;
	int m_iAlge;
	int m_iProb;
};
