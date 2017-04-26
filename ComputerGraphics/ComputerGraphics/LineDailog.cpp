// LineDailog.cpp : 实现文件
//

#include "stdafx.h"
#include "ComputerGraphics.h"
#include "ComputerGraphicsView.h"
#include "LineDailog.h"
#include "afxdialogex.h"


// LineDailog 对话框

IMPLEMENT_DYNAMIC(LineDailog, CDialog)

LineDailog::LineDailog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_LineDialog, pParent)
	, x1(0)
	, y1(0)
	, x2(0)
	, y2(0)
{

}

LineDailog::~LineDailog()
{
}

void LineDailog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_X1, x1);
	DDX_Text(pDX, IDC_Y1, y1);
	DDX_Text(pDX, IDC_X2, x2);
	DDX_Text(pDX, IDC_Y2, y2);
}


BEGIN_MESSAGE_MAP(LineDailog, CDialog)
	ON_BN_CLICKED(IDOK, &LineDailog::OnBnClickedOk)
END_MESSAGE_MAP()


// LineDailog 消息处理程序


void LineDailog::OnBnClickedOk()
{
	//UpdateData();
	//UpdateData(false);
	CDialog::OnOK();
}
