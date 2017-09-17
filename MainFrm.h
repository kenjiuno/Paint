
// MainFrm.h : xFrame クラスのインターフェイス
//

#pragma once

class xFrame : public CFrameWnd
{
	
protected: // シリアル化からのみ作成します。
	xFrame();
	DECLARE_DYNCREATE(xFrame)

// 属性
public:

// 操作
public:

// オーバーライド
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 実装
public:
	virtual ~xFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // コントロール バー用メンバー
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// 生成された、メッセージ割り当て関数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

};


