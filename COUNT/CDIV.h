#pragma once


// CDIV 对话框

class CDIV : public CDialogEx
{
	DECLARE_DYNAMIC(CDIV)

public:
	CDIV(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDIV();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIV };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
