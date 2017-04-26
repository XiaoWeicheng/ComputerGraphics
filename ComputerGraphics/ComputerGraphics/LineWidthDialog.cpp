// LineWidthDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "ComputerGraphics.h"
#include "LineWidthDialog.h"
#include "afxdialogex.h"


// LineWidthDialog 对话框

IMPLEMENT_DYNAMIC(LineWidthDialog, CDialog)

LineWidthDialog::LineWidthDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_LINEWIDTHDIALOG, pParent)
	, x0(0)
	, y0(0)
	, x1(0)
	, y1(0)
	, width(1)
	, width_(1)
{

}

LineWidthDialog::~LineWidthDialog()
{
}

void LineWidthDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x0);
	DDX_Text(pDX, IDC_EDIT2, y0);
	DDX_Text(pDX, IDC_EDIT3, x1);
	DDX_Text(pDX, IDC_EDIT4, y1);
	DDX_Slider(pDX, IDC_SLIDER1, width);
	DDX_Text(pDX, IDC_EDIT5, width_);
}


BEGIN_MESSAGE_MAP(LineWidthDialog, CDialog)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &LineWidthDialog::OnNMCustomdrawSlider1)
	ON_EN_CHANGE(IDC_EDIT5, &LineWidthDialog::OnEnChangeEdit5)
	ON_BN_CLICKED(IDOK, &LineWidthDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// LineWidthDialog 消息处理程序


void LineWidthDialog::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	UpdateData(1);
	width_ = width / 10;
	UpdateData(0);
	UpdateData(1);
	*pResult = 0;
}


void LineWidthDialog::OnEnChangeEdit5()
{
	UpdateData(1);
	width = width_ * 10;
	UpdateData(0);
	UpdateData(1);
}


void LineWidthDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}
