
// MainFrm.h : xFrame �N���X�̃C���^�[�t�F�C�X
//

#pragma once

class xFrame : public CFrameWnd
{
	
protected: // �V���A��������̂ݍ쐬���܂��B
	xFrame();
	DECLARE_DYNCREATE(xFrame)

// ����
public:

// ����
public:

// �I�[�o�[���C�h
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����
public:
	virtual ~xFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �R���g���[�� �o�[�p�����o�[
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

};


