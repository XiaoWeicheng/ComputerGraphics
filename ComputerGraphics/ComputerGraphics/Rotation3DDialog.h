#pragma once

#define PI 3.14159265358979323846

// Rotation3DDialog 对话框

class Rotation3DDialog : public CDialog
{
	DECLARE_DYNAMIC(Rotation3DDialog)

public:
	Rotation3DDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Rotation3DDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROTATIONDIALOG3D };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double matrix[4][4] = { { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,1 } };
	int axis;
	int angel;
	afx_msg void OnBnClickedOk();
};
