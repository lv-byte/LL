#pragma once


// CSUB 对话框

class CSUB : public CDialogEx
{
	DECLARE_DYNAMIC(CSUB)

public:
	CSUB(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSUB();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SUB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
