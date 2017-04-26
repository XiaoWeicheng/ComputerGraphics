#pragma once
#include "afxwin.h"


// ShearDialog 对话框

class ShearDialog : public CDialog
{
	DECLARE_DYNAMIC(ShearDialog)

public:
	ShearDialog(CWnd* pParent = NULL, int dimensionality=2);   // 标准构造函数
	virtual ~ShearDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHEARDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int dimensionality;
	double matrix[4][4] = { { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,1 } };
	afx_msg void OnBnClickedOk();
	afx_msg void OnStnClickedStaticZshear();
	CStatic zshear;
	CStatic zx;
	CEdit zxEdit;
	CStatic zy;
	CEdit zyEdit;
	CEdit xzEdit;
	CStatic xz;
	CStatic yz;
	CEdit yzEdit;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
