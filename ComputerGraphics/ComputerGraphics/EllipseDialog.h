#pragma once


// EllipseDialog 对话框

class EllipseDialog : public CDialog
{
	DECLARE_DYNAMIC(EllipseDialog)

public:
	EllipseDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~EllipseDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EllipseDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int x;
	int y;
	int a;
	int b;
	afx_msg void OnBnClickedOk();
};
