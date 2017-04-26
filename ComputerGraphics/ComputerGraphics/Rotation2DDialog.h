#pragma once
#include "afxwin.h"

#define PI 3.14159265358979323846

// RotationDialog 对话框

class Rotation2DDialog : public CDialog
{
	DECLARE_DYNAMIC(Rotation2DDialog)

public:
	Rotation2DDialog(CWnd* pParent = NULL, int dimensionality = 2);   // 标准构造函数
	virtual ~Rotation2DDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROTATIONDIALOG2D };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int dimensionality;
	double matrix[4][4] = { { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,1 } };
	afx_msg void OnBnClickedOk();
	double angel = 0;
};
