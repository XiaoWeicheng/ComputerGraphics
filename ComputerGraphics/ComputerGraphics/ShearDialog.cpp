// ShearDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "ComputerGraphics.h"
#include "ShearDialog.h"
#include "afxdialogex.h"


// ShearDialog 对话框

IMPLEMENT_DYNAMIC(ShearDialog, CDialog)

ShearDialog::ShearDialog(CWnd* pParent /*=NULL*/, int dimensionality)
	: CDialog(IDD_SHEARDIALOG, pParent)
{
	this->dimensionality = dimensionality;
	
}

ShearDialog::~ShearDialog()
{
}

void ShearDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, matrix[1][0]);
	DDX_Text(pDX, IDC_EDIT2, matrix[2][0]);
	DDX_Text(pDX, IDC_EDIT3, matrix[0][1]);
	DDX_Text(pDX, IDC_EDIT4, matrix[2][1]);
	DDX_Text(pDX, IDC_EDIT5, matrix[0][2]);
	DDX_Text(pDX, IDC_EDIT6, matrix[1][2]);
	DDX_Control(pDX, IDC_STATIC_ZSHEAR, zshear);
	DDX_Control(pDX, IDC_STATIC_ZX, zx);
	DDX_Control(pDX, IDC_EDIT5, zxEdit);
	DDX_Control(pDX, IDC_STATIC_ZY, zy);
	DDX_Control(pDX, IDC_EDIT6, zyEdit);
	DDX_Control(pDX, IDC_EDIT2, xzEdit);
	DDX_Control(pDX, IDC_STATIC_XZ, xz);
	DDX_Control(pDX, IDC_STATIC_YZ, yz);
	DDX_Control(pDX, IDC_EDIT4, yzEdit);
}


BEGIN_MESSAGE_MAP(ShearDialog, CDialog)
	ON_BN_CLICKED(IDOK, &ShearDialog::OnBnClickedOk)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// ShearDialog 消息处理程序


void ShearDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}


int ShearDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (dimensionality > 2)
	{
		zshear.ShowWindow(SW_SHOW);
		zx.ShowWindow(SW_SHOW);
		zxEdit.ShowWindow(SW_SHOW);
		zy.ShowWindow(SW_SHOW);
		zyEdit.ShowWindow(SW_SHOW);
		xzEdit.ShowWindow(SW_SHOW);
		xz.ShowWindow(SW_SHOW);
		yz.ShowWindow(SW_SHOW);
		yzEdit.ShowWindow(SW_SHOW);
	}

	return 0;
}
