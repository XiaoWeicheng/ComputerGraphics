
// ComputerGraphicsView.h : CComputerGraphicsView 类的接口
//

#pragma once
#include "ComputerGraphicsDoc.h"

#include "LineDailog.h"
#include "CircleDialog.h"
#include "EllipseDialog.h"
#include "LineTypeDialog.h"
#include "LineWidthDialog.h"
#include "RectDialog.h"
#include "TranslationDialog.h"
#include "ScalingDialog.h"
#include "Rotation2DDialog.h"
#include "Rotation3DDialog.h"
#include "Symmetrical2DDialog.h"
#include "Symmetrical3DDialog.h"
#include "ShearDialog.h"

class CComputerGraphicsView : public CView
{
protected: // 仅从序列化创建
	CComputerGraphicsView();
	DECLARE_DYNCREATE(CComputerGraphicsView)

// 特性
public:
	CComputerGraphicsDoc* GetDocument() const;

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
	virtual ~CComputerGraphicsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()


private:
	void DrawLine(CDC &dc, int x1, int y1, int x2, int y2);

	void TractalSnow(CDC &dc_Fractal, int iterations, int x1, int y1, int x2, int y2, int angel, double d);
	void TractalSnowEdge(CDC &dc_Fractal, int iterations, int x1, int y1, int x2, int y2, int angel, double d);
	void TractalSpiral(CDC &dc_Fractal, int angel);

	void Curve(CDC &dc_Fractal, int x0, int x1, double k, double b);
	void TractalSpiral_(CDC &dc_Fractal, int x, int y, double angel, int size);

	void LineDDA(CDC &dc, int x1, int y1, int x2, int y2, int color);
	void LineMidBresenham(CDC &dc, int x1, int y1, int x2, int y2, int color);
	void LineBresenham(CDC &dc, int x0, int y0, int x1, int y1, int color);

	void CirclePoint(CDC &dc, int x, int y, int Ox, int Oy, int color);
	void CircleMidbresenham(CDC &dc, int Ox, int Oy, int r, int color);

	void EllipsePoint(CDC &dc, int x, int y, int Ox, int Oy, int color);
	void EllipseMidbresenham(CDC &dc, int Ox, int Oy, int a, int b, int color);

	void BoundaryFill(CDC &dc, CPoint &point, COLORREF &boundaryColor, COLORREF &fillColor);
	void FloodFill(CDC &dc, CPoint &point, COLORREF &interColor, COLORREF &fillColor);
	
	void LineTypeSolid(CDC &dc, int x0, int y0, int x1, int y1, int color);
	void LineTypeDash(CDC &dc, int x0, int y0, int x1, int y1, int color);
	void LineTypeDot(CDC &dc, int x0, int y0, int x1, int y1, int color);

	void LineWidth(CDC &dc, int x0, int y0, int x1, int y1, int width, int color);
	void SetLinePoint(CDC &dc, int x, int y, int r, int color);

	void PointTransformation(int points[4][3], double matrix[4][4], int transformedPoints[4][3], int dimensionality=2);
	void Display(CDC &dc, int points[4][3], int points_[4][3]);

protected:

	bool SetWindowPixelFormat(HDC hDC);
	// 创建绘制环境(RC)并使之成为当前绘制环境    
	bool CreateViewGLContext(HDC hDC);
	// 初始化openGL
	bool InitGL();
	//>像素格式的索引值
	int m_GLPixelIndex;
	// 绘制环境，HGLRC是一个指向rendering context的句柄
	HGLRC m_hGLContext;

public:
	afx_msg void OnLine();

	afx_msg void OnFractalSnow();
	afx_msg void OnFractalSpiral();

	afx_msg void OnLineBresenham();
	afx_msg void OnLineDDA();
	afx_msg void OnLineMidbresenham();

	afx_msg void OnCircleMidbresenham();

	afx_msg void OnEllipseMidbresenham();

	afx_msg void OnFillBoundary();
	afx_msg void OnFillFlood();
	afx_msg void OnLineType();
	afx_msg void OnLineWidth();
	afx_msg void On2dTranslation();
	afx_msg void On2dScaling();
	afx_msg void On2dRotation();
	afx_msg void On2dSymmetrical();
	afx_msg void On2dShear();
	afx_msg void On3dTranslation();
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void On3dScaling();
	afx_msg void On3dRotation();
	afx_msg void On3dSymmetrical();
	afx_msg void On3dShear();
};

#ifndef _DEBUG  // ComputerGraphicsView.cpp 中的调试版本
inline CComputerGraphicsDoc* CComputerGraphicsView::GetDocument() const
   { return reinterpret_cast<CComputerGraphicsDoc*>(m_pDocument); }
#endif

