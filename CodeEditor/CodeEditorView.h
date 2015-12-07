
// CodeEditorView.h : CCodeEditorView 类的接口
//

#pragma once


class CCodeEditorView : public CView
{
protected: // 仅从序列化创建
	CCodeEditorView();
	DECLARE_DYNCREATE(CCodeEditorView)

// 特性
public:
	CCodeEditorDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CCodeEditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CodeEditorView.cpp 中的调试版本
inline CCodeEditorDoc* CCodeEditorView::GetDocument() const
   { return reinterpret_cast<CCodeEditorDoc*>(m_pDocument); }
#endif

