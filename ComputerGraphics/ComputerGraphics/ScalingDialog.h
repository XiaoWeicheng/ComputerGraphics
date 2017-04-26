#pragma once
#include "atltypes.h"
#include "afxwin.h"


// ScalingDialog 对话框

class ScalingDialog : public CDialog
{
	DECLARE_DYNAMIC(ScalingDialog)

public:
	ScalingDialog(CWnd* pParent = NULL, int dimensionality = 2);   // 标准构造函数
	virtual ~ScalingDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCALINGDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic sSZ;
	CEdit sZ;
	int dimensionality;
	double matrix[4][4] = { { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,1 } };
	afx_msg void OnBnClickedOk();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
