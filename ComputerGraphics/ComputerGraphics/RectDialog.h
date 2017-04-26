#pragma once
#include "afxwin.h"


// RectDialog �Ի���

class RectDialog : public CDialog
{
	DECLARE_DYNAMIC(RectDialog)

public:
	RectDialog(CWnd* pParent = NULL, int dimensionality = 2);   // ��׼���캯��
	virtual ~RectDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RECTDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int points[4][3] = { {0,0,0},{100,0,0},{100,100,0},{0,100,0} };
	afx_msg void OnBnClickedOk();
	int dimensionality;
	CStatic z;
	CEdit z1;
	CEdit z2;
	CEdit z3;
	CEdit z4;
	virtual BOOL OnInitDialog();
};
