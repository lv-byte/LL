// CSUB.cpp: 实现文件
//

#include "pch.h"
#include "COUNT.h"
#include "CSUB.h"
#include "afxdialogex.h"


// CSUB 对话框

IMPLEMENT_DYNAMIC(CSUB, CDialogEx)

CSUB::CSUB(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SUB, pParent)
{

}

CSUB::~CSUB()
{
}

void CSUB::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSUB, CDialogEx)
END_MESSAGE_MAP()


// CSUB 消息处理程序
