#pragma once


// CWRONG 对话框

class CWRONG : public CDialogEx
{
	DECLARE_DYNAMIC(CWRONG)

public:
	CWRONG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CWRONG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WRONG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
