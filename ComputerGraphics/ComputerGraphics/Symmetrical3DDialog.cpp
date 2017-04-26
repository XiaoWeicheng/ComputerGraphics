// Symmetrical3DDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "ComputerGraphics.h"
#include "Symmetrical3DDialog.h"
#include "afxdialogex.h"


// Symmetrical3DDialog 对话框

IMPLEMENT_DYNAMIC(Symmetrical3DDialog, CDialog)

Symmetrical3DDialog::Symmetrical3DDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SYMMETRICALDIALOG3D, pParent)
{

}

Symmetrical3DDialog::~Symmetrical3DDialog()
{
}

void Symmetrical3DDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Symmetrical3DDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &Symmetrical3DDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Symmetrical3DDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Symmetrical3DDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Symmetrical3DDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Symmetrical3DDialog::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Symmetrical3DDialog::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &Symmetrical3DDialog::OnBnClickedButton7)
END_MESSAGE_MAP()


// Symmetrical3DDialog 消息处理程序


void Symmetrical3DDialog::OnBnClickedButton1()
{
	matrix[0][0] = -1;
	matrix[1][1] = -1;
	matrix[2][2] = -1;
	OnOK();
}


void Symmetrical3DDialog::OnBnClickedButton2()
{
	matrix[1][1] = -1;
	matrix[2][2] = -1;
	OnOK();
}


void Symmetrical3DDialog::OnBnClickedButton3()
{
	matrix[0][0] = -1;
	matrix[2][2] = -1;
	OnOK();
}


void Symmetrical3DDialog::OnBnClickedButton4()
{
	matrix[0][0] = -1;
	matrix[1][1] = -1;
	OnOK();
}


void Symmetrical3DDialog::OnBnClickedButton5()
{
	matrix[2][2] = -1;
	OnOK();
}


void Symmetrical3DDialog::OnBnClickedButton6()
{
	matrix[1][1] = -1;
	OnOK();
}


void Symmetrical3DDialog::OnBnClickedButton7()
{
	matrix[0][0] = -1;
	OnOK();
}
