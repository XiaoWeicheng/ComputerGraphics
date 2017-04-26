// LineTypeDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "ComputerGraphics.h"
#include "LineTypeDialog.h"
#include "afxdialogex.h"


// LineTypeDialog 对话框

IMPLEMENT_DYNAMIC(LineTypeDialog, CDialog)

LineTypeDialog::LineTypeDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_LINETYPEDIALOG, pParent)
	, x0(0)
	, y0(0)
	, x1(0)
	, y1(0)
	, type(0)
{

}

LineTypeDialog::~LineTypeDialog()
{
}

void LineTypeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x0);
	DDX_Text(pDX, IDC_EDIT2, y0);
	DDX_Text(pDX, IDC_EDIT3, x1);
	DDX_Text(pDX, IDC_EDIT4, y1);
	DDX_CBIndex(pDX, IDC_COMBO1, type);
	DDX_Control(pDX, IDC_COMBO1, typeComboBox);
}


BEGIN_MESSAGE_MAP(LineTypeDialog, CDialog)
	ON_BN_CLICKED(IDOK, &LineTypeDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// LineTypeDialog 消息处理程序


void LineTypeDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}
