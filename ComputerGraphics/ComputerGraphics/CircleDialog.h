#pragma once


// CircleDialog �Ի���

class CircleDialog : public CDialog
{
	DECLARE_DYNAMIC(CircleDialog)

public:
	CircleDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CircleDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CircleDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int x;
	int y;
	int r;
	afx_msg void OnBnClickedOk();
};
