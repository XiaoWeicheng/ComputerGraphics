#pragma once
#include "afxwin.h"


// ShearDialog �Ի���

class ShearDialog : public CDialog
{
	DECLARE_DYNAMIC(ShearDialog)

public:
	ShearDialog(CWnd* pParent = NULL, int dimensionality=2);   // ��׼���캯��
	virtual ~ShearDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHEARDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int dimensionality;
	double matrix[4][4] = { { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,1 } };
	afx_msg void OnBnClickedOk();
	afx_msg void OnStnClickedStaticZshear();
	CStatic zshear;
	CStatic zx;
	CEdit zxEdit;
	CStatic zy;
	CEdit zyEdit;
	CEdit xzEdit;
	CStatic xz;
	CStatic yz;
	CEdit yzEdit;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
