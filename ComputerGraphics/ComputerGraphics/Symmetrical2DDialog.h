#pragma once


// SymmetricalDialog �Ի���

class Symmetrical2DDialog : public CDialog
{
	DECLARE_DYNAMIC(Symmetrical2DDialog)

public:
	Symmetrical2DDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Symmetrical2DDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SYMMETRICALDIALOG2D};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double matrix[4][4] = { { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,1 } };
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
};
