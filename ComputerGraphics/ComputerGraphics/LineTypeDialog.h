#pragma once
#include "afxwin.h"


// LineTypeDialog 对话框

class LineTypeDialog : public CDialog
{
	DECLARE_DYNAMIC(LineTypeDialog)

public:
	LineTypeDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LineTypeDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LINETYPEDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int x0;
	int y0;
	int x1;
	int y1;
	afx_msg void OnBnClickedOk();
	int type;
	CComboBox typeComboBox;
};
