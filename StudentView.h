
// StudentView.h : CStudentView ��Ľӿ�
//

#pragma once


class CStudentView : public CView
{
protected: // �������л�����
	CStudentView();
	DECLARE_DYNCREATE(CStudentView)

// ����
public:
	CStudentDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CStudentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL m_bTBar;
	BOOL m_bZs;
// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnNameZs();
	afx_msg void OnNameLs();
	afx_msg void OnNameWw();
	afx_msg void OnScoreComp();
	afx_msg void OnScoreEng();
	afx_msg void OnScoreMath();
	afx_msg void OnTest();
	afx_msg void OnUpdateTest(CCmdUI *pCmdUI);
//	afx_msg void OnUpdateNameZs(CCmdUI *pCmdUI);
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnViewChangeTb();
	afx_msg void OnUpdateNameZs(CCmdUI *pCmdUI);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // StudentView.cpp �еĵ��԰汾
inline CStudentDoc* CStudentView::GetDocument() const
   { return reinterpret_cast<CStudentDoc*>(m_pDocument); }
#endif

