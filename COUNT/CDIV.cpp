// CDIV.cpp: 实现文件
//

#include "pch.h"
#include "COUNT.h"
#include "CDIV.h"
#include "afxdialogex.h"


// CDIV 对话框

IMPLEMENT_DYNAMIC(CDIV, CDialogEx)

CDIV::CDIV(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIV, pParent)
{

}

CDIV::~CDIV()
{
}

void CDIV::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDIV, CDialogEx)
END_MESSAGE_MAP()


// CDIV 消息处理程序
