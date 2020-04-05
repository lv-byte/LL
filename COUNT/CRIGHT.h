#pragma once


// CRIGHT 对话框

class CRIGHT : public CDialogEx
{
	DECLARE_DYNAMIC(CRIGHT)

public:
	CRIGHT(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CRIGHT();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RIGHT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
