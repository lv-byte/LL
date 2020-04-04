
// COUNTDlg.h: 头文件
//

#pragma once


// CCOUNTDlg 对话框
class CCOUNTDlg : public CDialogEx
{
// 构造
public:
	CCOUNTDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COUNT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedCount();
	UINT num1;
	UINT num2;
	UINT out;

	CString edit1[100];
	CString edit2[100];
	CString edit3;

	CString countsign;
	CComboBox signbox;
	int nindex;
	
	afx_msg void OnBnClickedOk();

	int count(CString sign,int a,int b);
};
