
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
	UINT num1;//操作数一、编辑框1
	UINT num2;//操作数二、编辑框2
	UINT out;//输出、编辑框3

	CString edit1[100];
	CString edit2[100];
	CString edit3;

	CString countsign;
	CComboBox signbox;
	int nindex;
	
	afx_msg void OnBnClickedOk();

	int count(CString sign,int a,int b);
	afx_msg void OnBnClickedStart();

	int i = 0;//统计题目数量
	int j = 0;//统计答对题目数量
	int sum;//答对题目之和
	int d;//正确答案
	int t;//输入答案
	int a;//num1
	int b;//num2
	int is=0;
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedRule();
};
