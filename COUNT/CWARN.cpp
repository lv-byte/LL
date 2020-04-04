// CWARN.cpp: 实现文件
//

#include "pch.h"
#include "COUNT.h"
#include "CWARN.h"
#include "afxdialogex.h"


// CWARN 对话框

IMPLEMENT_DYNAMIC(CWARN, CDialogEx)

CWARN::CWARN(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WARN, pParent)
{

}

CWARN::~CWARN()
{
}

void CWARN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWARN, CDialogEx)
END_MESSAGE_MAP()


// CWARN 消息处理程序
