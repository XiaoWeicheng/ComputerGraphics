#pragma once


// Symmetrical3DDialog 对话框

class Symmetrical3DDialog : public CDialog
{
	DECLARE_DYNAMIC(Symmetrical3DDialog)

public:
	Symmetrical3DDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Symmetrical3DDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SYMMETRICALDIALOG3D };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double matrix[4][4] = { { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,1 } };
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
};
