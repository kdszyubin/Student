#pragma once


// CCompPg �Ի���

class CCompPg : public CPropertyPage
{
	DECLARE_DYNAMIC(CCompPg)

public:
	CCompPg();
	virtual ~CCompPg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_iProg;
	int m_iData;
	int m_iOrga;
};
