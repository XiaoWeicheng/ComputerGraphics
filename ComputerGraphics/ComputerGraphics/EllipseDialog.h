#pragma once


// EllipseDialog �Ի���

class EllipseDialog : public CDialog
{
	DECLARE_DYNAMIC(EllipseDialog)

public:
	EllipseDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~EllipseDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EllipseDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int x;
	int y;
	int a;
	int b;
	afx_msg void OnBnClickedOk();
};
