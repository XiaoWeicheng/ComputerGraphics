// EllipseDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ComputerGraphics.h"
#include "EllipseDialog.h"
#include "afxdialogex.h"


// EllipseDialog �Ի���

IMPLEMENT_DYNAMIC(EllipseDialog, CDialog)

EllipseDialog::EllipseDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_EllipseDIALOG, pParent)
	, x(0)
	, y(0)
	, a(0)
	, b(0)
{

}

EllipseDialog::~EllipseDialog()
{
}

void EllipseDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT3, a);
	DDX_Text(pDX, IDC_EDIT4, b);
}


BEGIN_MESSAGE_MAP(EllipseDialog, CDialog)
	ON_BN_CLICKED(IDOK, &EllipseDialog::OnBnClickedOk)
END_MESSAGE_MAP()




void EllipseDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnOK();
}
