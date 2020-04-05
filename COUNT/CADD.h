#pragma once


// CADD 对话框

class CADD : public CDialogEx
{
	DECLARE_DYNAMIC(CADD)

public:
	CADD(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CADD();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
