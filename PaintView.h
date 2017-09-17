
// PaintView.h : xView クラスのインターフェイス
//

#pragma once


class xView : public CView
{
protected: // シリアル化からのみ作成します。
	xView();
	DECLARE_DYNCREATE(xView)

// 属性
public:
	xDoc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 実装
public:
	virtual ~xView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // PaintView.cpp のデバッグ バージョン
inline xDoc* xView::GetDocument() const
   { return reinterpret_cast<xDoc*>(m_pDocument); }
#endif

