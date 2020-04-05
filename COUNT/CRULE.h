#pragma once


// CRULE 对话框

class CRULE : public CDialogEx
{
	DECLARE_DYNAMIC(CRULE)

public:
	CRULE(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CRULE();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RULE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
