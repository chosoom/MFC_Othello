
// othelloDlg.h : 헤더 파일
//

#pragma once


// CothelloDlg 대화 상자
class CothelloDlg : public CDialogEx
{
// 생성입니다.
public:
	CothelloDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OTHELLO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
