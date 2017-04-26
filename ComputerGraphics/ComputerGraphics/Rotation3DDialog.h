#pragma once

#define PI 3.14159265358979323846

// Rotation3DDialog �Ի���

class Rotation3DDialog : public CDialog
{
	DECLARE_DYNAMIC(Rotation3DDialog)

public:
	Rotation3DDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Rotation3DDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROTATIONDIALOG3D };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double matrix[4][4] = { { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,1 } };
	int axis;
	int angel;
	afx_msg void OnBnClickedOk();
};
