// SymmetricalDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "ComputerGraphics.h"
#include "Symmetrical2DDialog.h"
#include "afxdialogex.h"


// SymmetricalDialog 对话框

IMPLEMENT_DYNAMIC(Symmetrical2DDialog, CDialog)

Symmetrical2DDialog::Symmetrical2DDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SYMMETRICALDIALOG2D, pParent)
{

}

Symmetrical2DDialog::~Symmetrical2DDialog()
{
}

void Symmetrical2DDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Symmetrical2DDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &Symmetrical2DDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &Symmetrical2DDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Symmetrical2DDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &Symmetrical2DDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// SymmetricalDialog 消息处理程序


void Symmetrical2DDialog::OnBnClickedButton1()
{
	matrix[0][0] = -1;
	matrix[1][1] = -1;
	OnOK();
}


void Symmetrical2DDialog::OnBnClickedButton3()
{
	matrix[1][1] = -1;
	OnOK();
}


void Symmetrical2DDialog::OnBnClickedButton4()
{
	matrix[0][0] = -1;
	OnOK();
}


void Symmetrical2DDialog::OnBnClickedButton2()
{
	matrix[0][1] = 1;
	matrix[1][0] = 1;
	OnOK();
}
