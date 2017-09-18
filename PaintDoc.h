
// PaintDoc.h : xDoc �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class xDoc : public CDocument
{
protected: // �V���A��������̂ݍ쐬���܂��B
	xDoc();
	DECLARE_DYNCREATE(xDoc)

// ����
public:
	CBitmap offscreen;

// ����
public:
	CSize getOffscreenSize() const {
		BITMAP bm = { 0 };
		if (offscreen.GetBitmap(&bm) == sizeof(bm)) {
			return CSize(bm.bmWidth, bm.bmHeight);
		}
		return CSize(0, 0);
	}

// �I�[�o�[���C�h
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����
public:
	virtual ~xDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �����n���h���[�̌����R���e���c��ݒ肷��w���p�[�֐�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
};
