// CWRONG.cpp: 实现文件
//

#include "pch.h"
#include "COUNT.h"
#include "CWRONG.h"
#include "afxdialogex.h"


// CWRONG 对话框

IMPLEMENT_DYNAMIC(CWRONG, CDialogEx)

CWRONG::CWRONG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WRONG, pParent)
{

}

CWRONG::~CWRONG()
{
}

void CWRONG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWRONG, CDialogEx)
END_MESSAGE_MAP()


// CWRONG 消息处理程序
