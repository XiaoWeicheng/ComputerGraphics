// RotationDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "ComputerGraphics.h"
#include "Rotation2DDialog.h"
#include "afxdialogex.h"


// RotationDialog 对话框

IMPLEMENT_DYNAMIC(Rotation2DDialog, CDialog)

Rotation2DDialog::Rotation2DDialog(CWnd* pParent /*=NULL*/, int dimensionality)
	: CDialog(IDD_ROTATIONDIALOG2D, pParent)
{
	this->dimensionality = dimensionality;
}

Rotation2DDialog::~Rotation2DDialog()
{
}

void Rotation2DDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, angel);
}

void Rotation2DDialog::OnBnClickedOk()
{
	UpdateData(1);
	matrix[0][0] = cos(angel * PI / 180);
	matrix[0][1] = sin(angel * PI / 180);
	matrix[1][0] = -sin(angel * PI / 180);
	matrix[1][1] = cos(angel * PI / 180);
	CDialog::OnOK();
}


BEGIN_MESSAGE_MAP(Rotation2DDialog, CDialog)
	ON_BN_CLICKED(IDOK, &Rotation2DDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// RotationDialog 消息处理程序