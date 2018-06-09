#pragma once

#include "Resource.h"
#include "afxcmn.h"
#include "afxwin.h"
#include "string"
// CADDLAG 对话框

class CADDLAG : public CDialogEx
{
	DECLARE_DYNAMIC(CADDLAG)

public:
	CADDLAG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CADDLAG();
	


// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_DIAG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_lst;
	afx_msg void OnBnClickedBtnadd();
	virtual BOOL OnInitDialog();
	CEdit EDIT_name;
	CEdit EDIT_class;
	afx_msg void OnBnClickedBtnDel();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	CComboBox m_cb;
};
