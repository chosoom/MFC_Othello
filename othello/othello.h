
// othello.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CothelloApp:
// �� Ŭ������ ������ ���ؼ��� othello.cpp�� �����Ͻʽÿ�.
//

class CothelloApp : public CWinApp
{
public:
	CothelloApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CothelloApp theApp;