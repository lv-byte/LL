// CRIGHT.cpp: 实现文件
//

#include "pch.h"
#include "COUNT.h"
#include "CRIGHT.h"
#include "afxdialogex.h"


// CRIGHT 对话框

IMPLEMENT_DYNAMIC(CRIGHT, CDialogEx)

CRIGHT::CRIGHT(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RIGHT, pParent)
{

}

CRIGHT::~CRIGHT()
{
}

void CRIGHT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRIGHT, CDialogEx)
END_MESSAGE_MAP()


// CRIGHT 消息处理程序
