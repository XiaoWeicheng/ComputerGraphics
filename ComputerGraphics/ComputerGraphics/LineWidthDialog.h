#pragma once


// LineWidthDialog 对话框

class LineWidthDialog : public CDialog
{
	DECLARE_DYNAMIC(LineWidthDialog)

public:
	LineWidthDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LineWidthDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LINEWIDTHDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int x0;
	int y0;
	int x1;
	int y1;
	int width;
	int width_;
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedOk();
};
