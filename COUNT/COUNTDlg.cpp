
// COUNTDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "COUNT.h"
#include "COUNTDlg.h"
#include "afxdialogex.h"

#include "CWARN.h"
#include "CADD.h"
#include "CSUB.h"
#include "CMUL.h"
#include "CDIV.h"
#include "CANS.h"
#include "CRIGHT.h"
#include "CWRONG.h"
#include "CRULE.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCOUNTDlg 对话框



CCOUNTDlg::CCOUNTDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COUNT_DIALOG, pParent)
	, num1(0)
	, num2(0)
	, out(0)
	, countsign(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCOUNTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, num1);
	DDX_Text(pDX, IDC_EDIT2, num2);
	DDX_Text(pDX, IDC_EDIT3, out);
	DDX_CBString(pDX, IDC_COMBO1, countsign);
	DDX_Control(pDX, IDC_COMBO1, signbox);
}

BEGIN_MESSAGE_MAP(CCOUNTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CCOUNTDlg::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CCOUNTDlg::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT2, &CCOUNTDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CCOUNTDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_COUNT, &CCOUNTDlg::OnBnClickedCount)
	ON_BN_CLICKED(IDOK, &CCOUNTDlg::OnBnClickedOk)
	
	ON_BN_CLICKED(IDC_START, &CCOUNTDlg::OnBnClickedStart)
	ON_EN_CHANGE(IDC_EDIT4, &CCOUNTDlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_RULE, &CCOUNTDlg::OnBnClickedRule)
END_MESSAGE_MAP()


// CCOUNTDlg 消息处理程序

BOOL CCOUNTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	//为combox添加四个运算符，用来选择运算函数
	signbox.InsertString(0,_T("+"));
	signbox.InsertString(1,_T("-"));
	signbox.InsertString(2,_T("*"));
	signbox.InsertString(3,_T("/"));


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCOUNTDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCOUNTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCOUNTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCOUNTDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCOUNTDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CCOUNTDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCOUNTDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCOUNTDlg::OnBnClickedCount()
{
	// TODO: 在此添加控件通知处理程序代码
	CWARN warning;
	CRIGHT right;
	CWRONG wrong;

	if (is == 0) { 
		warning.DoModal();
		return; 
	}


	//nindex = signbox.GetCurSel();
	//signbox.GetLBText(nindex,countsign);
	//GetDlgItem(IDC_EDIT3)->SetWindowText(countsign);

	t=GetDlgItemInt(IDC_EDIT3);
	if (d==t) {
		j++;
		right.DoModal();
	}
	else {
		wrong.DoModal();
	}

	SetDlgItemInt(IDC_EDIT1, 0, 1);
	SetDlgItemInt(IDC_EDIT2, 0, 1);

	//GetDlgItem(IDC_EDIT4)->SetWindowTextW(edit3);


	CADD add;
	CSUB sub;
	CMUL mul;
	CDIV div;
	CANS ans;

	if (i==10) {
		SetDlgItemInt(IDC_EDIT4, j, 1);
		ans.DoModal();
	}



	//使用switch函数出现无法正确选择的错误，但out的结果是符合预期的.错误原因out为UINT型，所以自动识别别d>=0，故一直错过了switch选择函数，因使用int数据代替，最后赋值到out
	//之前由于题目理解错误，以下部分在修改后不会有实际用处。
	/*
	switch (output) {
	case -1: add.DoModal();
	case -2: sub.DoModal();
	case -3: mul.DoModal();
	case -4: div.DoModal();
	}
	*/
	//out=-4

	is = 0;
	
}

//并未使用
void CCOUNTDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}

/* 之前用来验证的计算函数，经过讨论，第二次修改后放弃使用，暂留
int CCOUNTDlg::count(CString sign, int a, int b)
{
	int d=-5;
	
	
		if (sign=='+') {
			d = a + b;
			if (d > 100) {
				return -1;
			}
		}
		else if(sign == '-'){
			d = a - b;
			if (d < 0) {
				return -2;
			}
		}
		else if(sign == '*'){
			d = a * b;
			if (d>100) {
				return -3;
			}
		}
		else if(sign == '/'){
			if (a < b) {
				return -4;
			}
			else if (a%b!=0) {
				return -4;
			}
			d = a / b;
		}
		
	
	return d;
}
*/


void CCOUNTDlg::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	
	i++;
	is = 1;
	srand(time(0)); 
	SetDlgItemInt(IDC_EDIT4, 0, 1);
	
		a = rand() % 100 + 1;
		b = rand() % 100 + 1;
		nindex = rand() % 4;     

		switch (nindex)
		{
		case 0:
			while ((d = a + b) > 100)    
			{
				a = rand() % 100 + 1;
				b = rand() % 100 + 1;
			}
			signbox.SetCurSel(nindex);
			SetDlgItemInt(IDC_EDIT1, a, 1);
			SetDlgItemInt(IDC_EDIT2, b, 1);
			break;
		case 1:
			while (a > 100 || b > 100) 
			{
				a = rand() % 100 + 1;
				b = rand() % 100 + 1;
			}
			if (a < b)             
			{
				d = a;
				a = b;
				b = d;
			}
			d = a - b;
			signbox.SetCurSel(nindex);
			SetDlgItemInt(IDC_EDIT1, a, 1);
			SetDlgItemInt(IDC_EDIT2, b, 1);
			break;
		case 2:
			while ((d = a * b) > 100)    
			{
				a = rand() % 100 + 1;
				b = rand() % 100 + 1;
			}
			signbox.SetCurSel(nindex);
			SetDlgItemInt(IDC_EDIT1, a, 1);
			SetDlgItemInt(IDC_EDIT2, b, 1);
			break;
		case 3:
			while (a > 100 || b > 100 || (a * b == 0))  
			{
				a = rand() % 100 + 1;
				b = rand() % 100 + 1;
			}
			if (a < b)           
			{
				d = a;
				a = b;
				b = d;
			}
			a = (a / b) * b;      
			d = a / b;
			signbox.SetCurSel(nindex);
			SetDlgItemInt(IDC_EDIT1, a, 1);
			SetDlgItemInt(IDC_EDIT2, b, 1);
			break;
		}
}







void CCOUNTDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCOUNTDlg::OnBnClickedRule()
{
	// TODO: 在此添加控件通知处理程序代码
	CRULE rule;
	rule.DoModal();
}
