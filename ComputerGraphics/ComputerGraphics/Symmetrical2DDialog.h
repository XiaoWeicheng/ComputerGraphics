#pragma once


// SymmetricalDialog 对话框

class Symmetrical2DDialog : public CDialog
{
	DECLARE_DYNAMIC(Symmetrical2DDialog)

public:
	Symmetrical2DDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Symmetrical2DDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SYMMETRICALDIALOG2D};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double matrix[4][4] = { { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,1 } };
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
};
