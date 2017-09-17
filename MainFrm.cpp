
// MainFrm.cpp : xFrame �N���X�̎���
//

#include "stdafx.h"
#include "Paint.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// xFrame

IMPLEMENT_DYNCREATE(xFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(xFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // �X�e�[�^�X ���C�� �C���W�P�[�^�[
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// xFrame �R���X�g���N�V����/�f�X�g���N�V����

xFrame::xFrame()
{
	// TODO: �����o�[�������R�[�h�������ɒǉ����Ă��������B
}

xFrame::~xFrame()
{
}

int xFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("�c�[�� �o�[�̍쐬�Ɏ��s���܂����B\n");
		return -1;      // �쐬�ł��Ȃ��ꍇ
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("�X�e�[�^�X �o�[�̍쐬�Ɏ��s���܂����B\n");
		return -1;      // �쐬�ł��Ȃ��ꍇ
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: �c�[�� �o�[���h�b�L���O�\�ɂ��Ȃ��ꍇ�́A������ 3 �s���폜���Ă��������B
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL xFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return TRUE;
}

// xFrame �f�f

#ifdef _DEBUG
void xFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void xFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// xFrame ���b�Z�[�W �n���h���[

