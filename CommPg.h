#pragma once


// CCommPg �Ի���

class CCommPg : public CPropertyPage
{
	DECLARE_DYNAMIC(CCommPg)

public:
	CCommPg();
	virtual ~CCommPg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_iPoli;
	int m_iEngl;
	int m_iPhys;
};
