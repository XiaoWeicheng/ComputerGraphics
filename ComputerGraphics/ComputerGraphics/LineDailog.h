#pragma once


// LineDailog 对话框

class LineDailog : public CDialog
{
	DECLARE_DYNAMIC(LineDailog)

public:
	LineDailog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LineDailog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LineDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int x1;
	int y1;
	int x2;
	int y2;
	afx_msg void OnBnClickedOk();
};
