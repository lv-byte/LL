// CANS.cpp: 实现文件
//

#include "pch.h"
#include "COUNT.h"
#include "CANS.h"
#include "afxdialogex.h"


// CANS 对话框

IMPLEMENT_DYNAMIC(CANS, CDialogEx)

CANS::CANS(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ANS, pParent)
{

}

CANS::~CANS()
{
}

void CANS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CANS, CDialogEx)
END_MESSAGE_MAP()


// CANS 消息处理程序
