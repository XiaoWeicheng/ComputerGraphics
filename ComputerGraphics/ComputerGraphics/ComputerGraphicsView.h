
// ComputerGraphicsView.h : CComputerGraphicsView ��Ľӿ�
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
protected: // �������л�����
	CComputerGraphicsView();
	DECLARE_DYNCREATE(CComputerGraphicsView)

// ����
public:
	CComputerGraphicsDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CComputerGraphicsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// ���ɵ���Ϣӳ�亯��
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
	// �������ƻ���(RC)��ʹ֮��Ϊ��ǰ���ƻ���    
	bool CreateViewGLContext(HDC hDC);
	// ��ʼ��openGL
	bool InitGL();
	//>���ظ�ʽ������ֵ
	int m_GLPixelIndex;
	// ���ƻ�����HGLRC��һ��ָ��rendering context�ľ��
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

#ifndef _DEBUG  // ComputerGraphicsView.cpp �еĵ��԰汾
inline CComputerGraphicsDoc* CComputerGraphicsView::GetDocument() const
   { return reinterpret_cast<CComputerGraphicsDoc*>(m_pDocument); }
#endif

