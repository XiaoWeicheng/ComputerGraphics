#pragma once
#include "afxwin.h"


// LineTypeDialog �Ի���

class LineTypeDialog : public CDialog
{
	DECLARE_DYNAMIC(LineTypeDialog)

public:
	LineTypeDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LineTypeDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LINETYPEDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int x0;
	int y0;
	int x1;
	int y1;
	afx_msg void OnBnClickedOk();
	int type;
	CComboBox typeComboBox;
};
