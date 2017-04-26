#pragma once


// CircleDialog 对话框

class CircleDialog : public CDialog
{
	DECLARE_DYNAMIC(CircleDialog)

public:
	CircleDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CircleDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CircleDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int x;
	int y;
	int r;
	afx_msg void OnBnClickedOk();
};
