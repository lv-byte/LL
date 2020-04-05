#pragma once


// CMUL 对话框

class CMUL : public CDialogEx
{
	DECLARE_DYNAMIC(CMUL)

public:
	CMUL(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMUL();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MUL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
