
// othelloDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "othello.h"
#include "othelloDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <iostream>
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CothelloDlg 대화 상자



CothelloDlg::CothelloDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_OTHELLO_DIALOG, pParent)
	, m_turn(false)
	, m_1_count(2)
	, m_2_count(2)
	, m_count(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_map = new int*[8];
	m_map[0] = new int[8]{ 0,0,0,0,0,0,0,0 };
	m_map[1] = new int[8]{ 0,0,0,0,0,0,0,0 };
	m_map[2] = new int[8]{ 0,0,0,0,0,0,0,0 };
	m_map[3] = new int[8]{ 0,0,0,1,2,0,0,0 };
	m_map[4] = new int[8]{ 0,0,0,2,1,0,0,0 };
	m_map[5] = new int[8]{ 0,0,0,0,0,0,0,0 };
	m_map[6] = new int[8]{ 0,0,0,0,0,0,0,0 };
	m_map[7] = new int[8]{ 0,0,0,0,0,0,0,0 };
}

void CothelloDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_1_SCORE, m_1_count);
	DDX_Text(pDX, IDC_2_SCORE, m_2_count);
}

BEGIN_MESSAGE_MAP(CothelloDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BTN_CHANGE_TURN, &CothelloDlg::OnClickedBtnChangeTurn)
END_MESSAGE_MAP()


// CothelloDlg 메시지 처리기

BOOL CothelloDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_bitmap[0].LoadBitmap(IDB_black);
	m_bitmap[1].LoadBitmap(IDB_white);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CothelloDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CothelloDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	DrawLine();

	/*CFont font;
	font.CreateFontW(50, 20, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("고딕"));
	GetDlgItem(IDC_1_SCORE)->SetFont(&font);
	GetDlgItem(IDC_2_SCORE)->SetFont(&font);*/
	CBitmap *pOldBitmap;
	CDC   MemDC, *pDC;

	pDC = this->GetDC();
	MemDC.CreateCompatibleDC(pDC);

	pOldBitmap = MemDC.SelectObject(&m_bitmap[0]);
	pDC->BitBlt(171, 171, 48, 48, &MemDC, 0, 0, SRCCOPY);
	pDC->BitBlt(221, 221, 48, 48, &MemDC, 0, 0, SRCCOPY);
	MemDC.SelectObject(pOldBitmap);

	pOldBitmap = MemDC.SelectObject(&m_bitmap[1]);
	pDC->BitBlt(221, 171, 48, 48, &MemDC, 0, 0, SRCCOPY);
	pDC->BitBlt(171, 221, 48, 48, &MemDC, 0, 0, SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CothelloDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CothelloDlg::DrawLine()
{
	CClientDC pDC(this);
	CRect r;
	GetClientRect(r);
	CPen myPen, *oldPen;
	myPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	oldPen = pDC.SelectObject(&myPen);

	for (int i = 0; i < 9; i++) {
		pDC.MoveTo(20, 50*i+20);
		pDC.LineTo(20 + 50 * 8, 50*i+20);
	}
	for (int i = 0; i < 9; i++) {
		pDC.MoveTo(50 * i + 20, 20);
		pDC.LineTo(50 * i + 20, 20 + 50 * 8);
	}
}


void CothelloDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (point.x > 420 || point.x < 10 || point.y>420 || point.y < 10) {
		AfxMessageBox(_T("보드 위를 클릭해주세요."), MB_ICONWARNING);
		return;
	}
	int m_x = (point.x - 20)/50, m_y=(point.y-20)/50;
	if (m_map[m_y][m_x] != 0) {
		AfxMessageBox(_T("이미 둔 곳 입니다."));
		return;
	}

	int* pointX, *pointY, **pointXY;
	pointX = judgeStoneX(m_x, m_y);
	pointY = judgeStoneY(m_x, m_y);
	pointXY = judgeStoneXY(m_x, m_y);
	if (pointX[0] == -1 & pointX[1] == -1 & pointY[0] == -1 & pointY[1] == -1 &
		pointXY[0][0]==-1 & pointXY[1][0] == -1 & pointXY[2][0] == -1 & pointXY[3][0] == -1) {
		AfxMessageBox(_T("잘못된 선택입니다."),MB_ICONWARNING);
	}
	else {
		ChangeStoneX(m_x, pointX[0],m_y);
		ChangeStoneX(m_x, pointX[1], m_y);
		ChangeStoneY(m_x, m_y, pointY[0]);
		ChangeStoneY(m_x, m_y, pointY[1]);
		ChangeStoneXY(m_x, pointXY[0][0], m_y, pointXY[0][1]);
		ChangeStoneXY(m_x, pointXY[1][0], m_y, pointXY[1][1]);
		ChangeStoneXY(m_x, pointXY[2][0], m_y, pointXY[2][1]);
		ChangeStoneXY(m_x, pointXY[3][0], m_y, pointXY[3][1]);
		DrawStone(m_x * 50 + 21, m_y * 50 + 21);
		SetCount();
		m_count++;
		m_turn = !m_turn;
		if (m_count == 61) {
			CString str;
			str.Format(_T("player1: %d player2: %d \r\n winner: %s"), m_1_count, m_2_count, (m_1_count > m_2_count ? "player1" : "player2"));
			AfxMessageBox(str, MB_OK | MB_ICONINFORMATION);
		}
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


int CothelloDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}


int CothelloDlg::DrawStone(int x,int y)
{
	int m_x=x/50, m_y=y/50;

	CBitmap *pOldBitmap;
	CDC   MemDC, *pDC;

	pDC = this->GetDC();

	MemDC.CreateCompatibleDC(pDC);
	if (!m_turn) {
		pOldBitmap = MemDC.SelectObject(&m_bitmap[0]);
		m_map[m_y][m_x] = 1;
	}
	else {
		pOldBitmap = MemDC.SelectObject(&m_bitmap[1]);
		m_map[m_y][m_x] = 2;
	}
	pDC->BitBlt(x, y, 48, 48, &MemDC, 0, 0, SRCCOPY);

	MemDC.SelectObject(pOldBitmap);

	return 0;
}

int* CothelloDlg::judgeStoneX(int x, int y) {
	int t,i;
	int* pointX = new int[2] {-1,-1};
	if (!m_turn) t = 1;
	else t = 2;

	for (i = x - 1; i > 0; i--) {
		if (m_map[y][i] == 0) break;
		if (m_map[y][i] == t) { 
			if (i == x - 1) break;
			pointX[0] = i; 
			break; 
		}
	}

	for (i = x + 1; i < 8; i++) {
		if (m_map[y][i] == 0)break;
		if (m_map[y][i] == t) { 
			if (i == x + 1) break;
			pointX[1] = i; 
			break; 
		}
	}
	return pointX;
}

int* CothelloDlg::judgeStoneY(int x, int y) {
	int t, i;
	int* pointY = new int[2]{ -1,-1 };
	if (!m_turn) t = 1;
	else t = 2;

	for (i = y - 1; i > 0; i--) {
		if (m_map[i][x] == 0) break;
		if (m_map[i][x] == t) { 
			if (i == y - 1) break;
			pointY[0] = i;
			break; 
		}
	}

	for (i = y + 1; i < 8; i++) {
		if (m_map[i][x] == 0) break;
		if (m_map[i][x] == t) {
			if (i == y + 1) break;
			pointY[1] = i;
			break; }
	}
	return pointY;
}

int** CothelloDlg::judgeStoneXY(int x, int y) {
	int **pointXY = new int*[4];
	for (int a = 0; a < 4; a++) {
		pointXY[a] = new int[2]{ -1,-1 };
	}
	int t,i_x,i_y;
	if (!m_turn) t = 1;
	else t = 2;
	i_x = x - 1;
	i_y = y - 1;
	while (i_x>0 && i_y>0) {
		if (m_map[i_y][i_x] == 0)break;
		if (m_map[i_y][i_x] == t) {
			if ((i_x == x - 1)&&(i_y=y-1)) break;
			pointXY[0][0] = i_x;
			pointXY[0][1] = i_y;
			break;
		}
		i_x--;i_y--;
	}
	i_x = x - 1;
	i_y = y + 1;
	while (i_x>0 && i_y<8) {
		if (m_map[i_y][i_x] == 0)break;
		if (m_map[i_y][i_x] == t) {
			if ((i_x == x - 1) && (i_y = y + 1)) break;
			pointXY[1][0] = i_x;
			pointXY[1][1] = i_y;
			break;
		}
		i_x--; i_y++;
	}
	i_x = x + 1;
	i_y = y - 1;
	while (i_x<8 && i_y>0) {
		if (m_map[i_y][i_x] == 0)break;
		if (m_map[i_y][i_x] == t) {
			if ((i_x == x + 1) && (i_y = y - 1)) break;
			pointXY[2][0] = i_x;
			pointXY[2][1] = i_y;
			break;
		}
		i_x++; i_y--;
	}
	i_x = x + 1;
	i_y = y + 1;
	while (i_x<8 && i_y<8) {
		if (m_map[i_y][i_x] == 0)break;
		if (m_map[i_y][i_x] == t) {
			if ((i_x == x + 1) && (i_y = y + 1)) break;
			pointXY[3][0] = i_x;
			pointXY[3][1] = i_y;
			break;
		}
		i_x++; i_y++;
	}

	return pointXY;
}

void CothelloDlg::ChangeStoneX(int x1,int x2,int y) {
	if (x2 == -1 ) return;
	for (int i = (x1 < x2 ? x1+1 : x2+1); i <= (x1 > x2 ? x1 : x2); i++) {
		DrawStone(i*50+21, y*50+21);
	}
}

void CothelloDlg::ChangeStoneY(int x, int y1, int y2) {
	if (y2 == -1) return;
	for (int i = (y1 < y2 ? y1 + 1 : y2 + 1); i <= (y1 > y2 ? y1 : y2); i++) {
		DrawStone(x * 50 + 21, i * 50 + 21);
	}
}

void CothelloDlg::ChangeStoneXY(int x1, int x2, int y1, int y2) {
	if ((x2 == -1) & (y2 == -1)) return;
	int i_x = x1 < x2 ? x1+1 : x2+1, i_y = x1<x2 ? y1 : y2, j_x = x1 > x2 ? x1 : x2, j_y = x1 > x2 ? y1 : y2, add=i_y>j_y?-1:1;

	i_y += add;
	while (i_x <= j_x && i_y <= j_x) {
		DrawStone(i_x * 50 + 21, i_y * 50 + 21);
		i_x++;
		i_y += add;
	}
}

void CothelloDlg::OnClickedBtnChangeTurn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_turn = !m_turn;
}

void CothelloDlg::SetCount() {
	int cnt1=0, cnt2=0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (m_map[j][i] == 1) cnt1++;
			if (m_map[j][i] == 2) cnt2++;
		}
	}
	UpdateData(true);
	m_1_count = cnt1;
	m_2_count = cnt2;
	UpdateData(false);
}