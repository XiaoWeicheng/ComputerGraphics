// CircleDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ComputerGraphics.h"
#include "CircleDialog.h"
#include "afxdialogex.h"


// CircleDialog �Ի���

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


// CircleDialog ��Ϣ�������


void CircleDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnOK();
}
