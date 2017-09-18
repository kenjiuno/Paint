
// PaintDoc.h : xDoc クラスのインターフェイス
//


#pragma once


class xDoc : public CDocument
{
protected: // シリアル化からのみ作成します。
	xDoc();
	DECLARE_DYNCREATE(xDoc)

// 属性
public:
	CBitmap offscreen;

// 操作
public:
	CSize getOffscreenSize() const {
		BITMAP bm = { 0 };
		if (offscreen.GetBitmap(&bm) == sizeof(bm)) {
			return CSize(bm.bmWidth, bm.bmHeight);
		}
		return CSize(0, 0);
	}

// オーバーライド
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 実装
public:
	virtual ~xDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 検索ハンドラーの検索コンテンツを設定するヘルパー関数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
};
