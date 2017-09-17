
// PaintView.cpp : xView クラスの実装
//

#include "stdafx.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "Paint.h"
#endif

#include "PaintDoc.h"
#include "PaintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// xView

IMPLEMENT_DYNCREATE(xView, CView)

BEGIN_MESSAGE_MAP(xView, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// xView コンストラクション/デストラクション

xView::xView()
{
	// TODO: 構築コードをここに追加します。

}

xView::~xView()
{
}

BOOL xView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// xView 描画

void xView::OnDraw(CDC* /*pDC*/)
{
	xDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}


// xView 印刷

BOOL xView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void xView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void xView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// xView 診断

#ifdef _DEBUG
void xView::AssertValid() const
{
	CView::AssertValid();
}

void xView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

xDoc* xView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(xDoc)));
	return (xDoc*)m_pDocument;
}
#endif //_DEBUG


// xView メッセージ ハンドラー
