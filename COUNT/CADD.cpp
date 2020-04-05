// CADD.cpp: 实现文件
//

#include "pch.h"
#include "COUNT.h"
#include "CADD.h"
#include "afxdialogex.h"


// CADD 对话框

IMPLEMENT_DYNAMIC(CADD, CDialogEx)

CADD::CADD(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD, pParent)
{

}

CADD::~CADD()
{
}

void CADD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CADD, CDialogEx)
END_MESSAGE_MAP()


// CADD 消息处理程序
