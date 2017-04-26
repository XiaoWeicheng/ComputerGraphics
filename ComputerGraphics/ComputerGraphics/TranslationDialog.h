#pragma once
#include "atltypes.h"
#include "afxwin.h"


// TranslateDialog �Ի���

class TranslationDialog : public CDialog
{
	DECLARE_DYNAMIC(TranslationDialog)

public:
	TranslationDialog(CWnd* pParent = NULL, int dimensionality = 2);   // ��׼���캯��
	virtual ~TranslationDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TranslationDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int dimensionality;
	double matrix[4][4] = { {1,0,0,0}, {0,1,0,0},{0,0,1,0},{0,0,0,1} };
	CEdit tZ;
	CStatic sTZ;
	virtual BOOL OnInitDialog();
};
