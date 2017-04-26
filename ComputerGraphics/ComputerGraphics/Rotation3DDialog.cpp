// Rotation3DDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "ComputerGraphics.h"
#include "Rotation3DDialog.h"
#include "afxdialogex.h"


// Rotation3DDialog 对话框

IMPLEMENT_DYNAMIC(Rotation3DDialog, CDialog)

Rotation3DDialog::Rotation3DDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_ROTATIONDIALOG3D, pParent)
	, axis(0)
	, angel(0)
{

}

Rotation3DDialog::~Rotation3DDialog()
{
}

void Rotation3DDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBIndex(pDX, IDC_COMBO1, axis);
	DDX_Text(pDX, IDC_EDIT1, angel);
}


BEGIN_MESSAGE_MAP(Rotation3DDialog, CDialog)
	ON_BN_CLICKED(IDOK, &Rotation3DDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// Rotation3DDialog 消息处理程序


void Rotation3DDialog::OnBnClickedOk()
{
	UpdateData(1);
	if (axis == 2) 
	{
		matrix[0][0] = cos(angel * PI / 180);
		matrix[0][1] = sin(angel * PI / 180);
		matrix[1][0] = -sin(angel * PI / 180);
		matrix[1][1] = cos(angel * PI / 180);
	}
	else if (axis == 1)
	{
		matrix[0][0] = cos(angel * PI / 180);
		matrix[0][2] = sin(angel * PI / 180);
		matrix[0][2] = -sin(angel * PI / 180);
		matrix[2][2] = cos(angel * PI / 180);
	}
	else
	{
		matrix[1][1] = cos(angel * PI / 180);
		matrix[1][2] = sin(angel * PI / 180);
		matrix[2][1] = -sin(angel * PI / 180);
		matrix[2][2] = cos(angel * PI / 180);
	}
	CDialog::OnOK();
}
