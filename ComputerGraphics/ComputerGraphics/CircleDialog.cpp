// CircleDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "ComputerGraphics.h"
#include "CircleDialog.h"
#include "afxdialogex.h"


// CircleDialog 对话框

IMPLEMENT_DYNAMIC(CircleDialog, CDialog)

CircleDialog::CircleDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CircleDIALOG, pParent)
	, x(0)
	, y(0)
	, r(0)
{

}

CircleDialog::~CircleDialog()
{
}

void CircleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT3, r);
}


BEGIN_MESSAGE_MAP(CircleDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CircleDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CircleDialog 消息处理程序


void CircleDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}
