#pragma once


// CANS 对话框

class CANS : public CDialogEx
{
	DECLARE_DYNAMIC(CANS)

public:
	CANS(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CANS();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ANS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
