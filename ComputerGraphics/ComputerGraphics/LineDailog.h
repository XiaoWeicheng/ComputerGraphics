#pragma once


// LineDailog �Ի���

class LineDailog : public CDialog
{
	DECLARE_DYNAMIC(LineDailog)

public:
	LineDailog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LineDailog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LineDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int x1;
	int y1;
	int x2;
	int y2;
	afx_msg void OnBnClickedOk();
};
