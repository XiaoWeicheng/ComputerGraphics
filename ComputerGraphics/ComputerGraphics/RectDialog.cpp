// RectDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "ComputerGraphics.h"
#include "RectDialog.h"
#include "afxdialogex.h"


// RectDialog 对话框

IMPLEMENT_DYNAMIC(RectDialog, CDialog)

RectDialog::RectDialog(CWnd* pParent /*=NULL*/, int dimensionality)
	: CDialog(IDD_RECTDIALOG, pParent)
{
	this->dimensionality = dimensionality;
	if (dimensionality == 3)
	{
		points[0][0] = 0;
		points[0][1] = 0;
		points[0][2] = 0;
		points[1][0] = 100;
		points[1][1] = 0;
		points[1][2] = 0;
		points[2][0] = 0;
		points[2][1] = 100;
		points[2][2] = 0;
		points[3][0] = 0;
		points[3][1] = 0;
		points[3][2] = 100;
	}
}

RectDialog::~RectDialog()
{
}

void RectDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, points[0][0]);
	DDX_Text(pDX, IDC_EDIT2, points[0][1]);
	DDX_Text(pDX, IDC_EDIT9, points[0][2]);
	DDX_Text(pDX, IDC_EDIT3, points[1][0]);
	DDX_Text(pDX, IDC_EDIT4, points[1][1]);
	DDX_Text(pDX, IDC_EDIT10, points[1][2]);
	DDX_Text(pDX, IDC_EDIT5, points[2][0]);
	DDX_Text(pDX, IDC_EDIT6, points[2][1]);
	DDX_Text(pDX, IDC_EDIT11, points[2][2]);
	DDX_Text(pDX, IDC_EDIT7, points[3][0]);
	DDX_Text(pDX, IDC_EDIT8, points[3][1]);
	DDX_Text(pDX, IDC_EDIT12, points[3][2]);
	DDX_Control(pDX, IDC_STATIC_Z, z);
	DDX_Control(pDX, IDC_EDIT9, z1);
	DDX_Control(pDX, IDC_EDIT10, z2);
	DDX_Control(pDX, IDC_EDIT11, z3);
	DDX_Control(pDX, IDC_EDIT12, z4);
}



BEGIN_MESSAGE_MAP(RectDialog, CDialog)
	ON_BN_CLICKED(IDOK, &RectDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// RectDialog 消息处理程序


void RectDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}


BOOL RectDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	if (dimensionality == 3)
	{
		z.ShowWindow(SW_SHOW);
		z1.ShowWindow(SW_SHOW);
		z2.ShowWindow(SW_SHOW);
		z3.ShowWindow(SW_SHOW);
		z4.ShowWindow(SW_SHOW);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
