// ADDLAG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "ADDLAG.h"
#include "afxdialogex.h"
#include "Resource.h"


// CADDLAG �Ի���

IMPLEMENT_DYNAMIC(CADDLAG, CDialogEx)

CADDLAG::CADDLAG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADD_DIAG, pParent)
{
	
}

CADDLAG::~CADDLAG()
{
}

void CADDLAG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_lst);
	DDX_Control(pDX, IDC_EDIT_NAME, EDIT_name);
	DDX_Control(pDX, IDC_EDIT_CLASS, EDIT_class);
	DDX_Control(pDX, IDC_COMBO1, m_cb);
}



BEGIN_MESSAGE_MAP(CADDLAG, CDialogEx)
	ON_BN_CLICKED(IDC_BTNADD, &CADDLAG::OnBnClickedBtnadd)
	ON_BN_CLICKED(IDC_BTN_DEL, &CADDLAG::OnBnClickedBtnDel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CADDLAG::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// CADDLAG ��Ϣ�������


void CADDLAG::OnBnClickedBtnadd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString _name, _class;
	EDIT_name.GetWindowTextW(_name);
	EDIT_class.GetWindowTextW(_class);
	int cnt = m_lst.GetItemCount();
	m_lst.InsertItem(cnt, _name);
	m_lst.SetItemText(cnt, 1, _class);
	EDIT_name.SetWindowTextW(_T(""));
	EDIT_class.SetWindowTextW(_T(""));
	

}


BOOL CADDLAG::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_lst.ModifyStyle(0, LVS_REPORT);
	m_lst.InsertColumn(0, _T("����"), LVCFMT_CENTER, 100);
	m_lst.InsertColumn(1, _T("�༶"), LVCFMT_CENTER, 50);
	m_cb.AddString(_T("Test"));
	CString str;
	m_cb.GetLBText(0, str);
	MessageBox(str, MB_OK);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CADDLAG::OnBnClickedBtnDel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int pos = (int)m_lst.GetFirstSelectedItemPosition();
	
	std::string s = std::to_string(pos);
	CString str;
	str= s.c_str();
	
	MessageBox(str, MB_OK);
	if (pos == 0) {
		AfxMessageBox(_T("��ѡ������"));
	}
	m_lst.DeleteItem(pos-1);
}


void CADDLAG::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
