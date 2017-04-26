// ScalingDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "ComputerGraphics.h"
#include "ScalingDialog.h"
#include "afxdialogex.h"


// ScalingDialog 对话框

IMPLEMENT_DYNAMIC(ScalingDialog, CDialog)

ScalingDialog::ScalingDialog(CWnd* pParent /*=NULL*/, int dimensionality)
	: CDialog(IDD_SCALINGDIALOG, pParent)
{
	this->dimensionality = dimensionality;
	
}

ScalingDialog::~ScalingDialog()
{
}

void ScalingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_SCALING, sSZ);
	DDX_Control(pDX, IDC_EDIT3, sZ);
	DDX_Text(pDX, IDC_EDIT1, matrix[0][0]);
	DDX_Text(pDX, IDC_EDIT2, matrix[1][1]);
	DDX_Text(pDX, IDC_EDIT3, matrix[2][2]);
}


BEGIN_MESSAGE_MAP(ScalingDialog, CDialog)
	ON_BN_CLICKED(IDOK, &ScalingDialog::OnBnClickedOk)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// ScalingDialog 消息处理程序


void ScalingDialog::OnBnClickedOk()
{
	CDialog::OnOK();
}


int ScalingDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (dimensionality > 2)
	{
		sZ.ShowWindow(SW_SHOW);
		sSZ.ShowWindow(SW_SHOW);
	}

	return 0;
}
