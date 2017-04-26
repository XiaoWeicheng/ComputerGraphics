// TranslateDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ComputerGraphics.h"
#include "TranslationDialog.h"
#include "afxdialogex.h"


// TranslateDialog �Ի���

IMPLEMENT_DYNAMIC(TranslationDialog, CDialog)

TranslationDialog::TranslationDialog(CWnd* pParent /*=NULL*/, int dimensionality)
	: CDialog(IDD_Translation, pParent)
{
	this->dimensionality = dimensionality;
	
}

TranslationDialog::~TranslationDialog()
{
}

void TranslationDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, matrix[dimensionality][0]);
	DDX_Text(pDX, IDC_EDIT2, matrix[dimensionality][1]);
	DDX_Text(pDX, IDC_EDIT3, matrix[dimensionality][2]);
	DDX_Control(pDX, IDC_EDIT3, tZ);
	DDX_Control(pDX, IDC_STATIC_Z, sTZ);
}


BEGIN_MESSAGE_MAP(TranslationDialog, CDialog)
	ON_BN_CLICKED(IDOK, &TranslationDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// TranslateDialog ��Ϣ�������


void TranslationDialog::OnBnClickedOk()
{
	CDialog::OnOK();
}


BOOL TranslationDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	if (dimensionality > 2)
	{
		tZ.ShowWindow(SW_SHOW);
		sTZ.ShowWindow(SW_SHOW);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
