
// CodeEditorView.cpp : CCodeEditorView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CodeEditor.h"
#endif

#include "CodeEditorDoc.h"
#include "CodeEditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCodeEditorView

IMPLEMENT_DYNCREATE(CCodeEditorView, CView)

BEGIN_MESSAGE_MAP(CCodeEditorView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCodeEditorView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CCodeEditorView 构造/析构

CCodeEditorView::CCodeEditorView()
{
	// TODO: 在此处添加构造代码

}

CCodeEditorView::~CCodeEditorView()
{
}

BOOL CCodeEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCodeEditorView 绘制

void CCodeEditorView::OnDraw(CDC* /*pDC*/)
{
	CCodeEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CCodeEditorView 打印


void CCodeEditorView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCodeEditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCodeEditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCodeEditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CCodeEditorView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCodeEditorView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCodeEditorView 诊断

#ifdef _DEBUG
void CCodeEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CCodeEditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCodeEditorDoc* CCodeEditorView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCodeEditorDoc)));
	return (CCodeEditorDoc*)m_pDocument;
}
#endif //_DEBUG


// CCodeEditorView 消息处理程序
