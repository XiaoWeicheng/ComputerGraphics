#pragma once
#include "afxwin.h"


// RectDialog 对话框

class RectDialog : public CDialog
{
	DECLARE_DYNAMIC(RectDialog)

public:
	RectDialog(CWnd* pParent = NULL, int dimensionality = 2);   // 标准构造函数
	virtual ~RectDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RECTDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
