
// othelloDlg.h : ��� ����
//

#pragma once


// CothelloDlg ��ȭ ����
class CothelloDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CothelloDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OTHELLO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void DrawLine();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	bool m_turn;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CBitmap m_bitmap[2];
	int DrawStone(int x,int y);
	int** m_map;
	int* judgeStoneX(int x,int y);
	int* judgeStoneY(int x, int y);
	int** judgeStoneXY(int x, int y);
	void ChangeStoneX(int x1,int x2,int y);
	void ChangeStoneY(int x, int y1, int y2);
	void ChangeStoneXY(int x1, int x2, int y1, int y2);
	void SetCount();
	UINT m_1_count;
	UINT m_2_count;
	afx_msg void OnClickedBtnChangeTurn();
	int m_count;
};
