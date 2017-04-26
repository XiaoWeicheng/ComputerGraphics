
// ComputerGraphicsView.cpp : CComputerGraphicsView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ComputerGraphics.h"
#endif

#include "ComputerGraphicsDoc.h"
#include "ComputerGraphicsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PI 3.14159265358979323846

// CComputerGraphicsView

IMPLEMENT_DYNCREATE(CComputerGraphicsView, CView)

BEGIN_MESSAGE_MAP(CComputerGraphicsView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CComputerGraphicsView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_LINE, &CComputerGraphicsView::OnLine)
	ON_COMMAND(ID_FRACTAL_SNOW, &CComputerGraphicsView::OnFractalSnow)
	ON_COMMAND(ID_FRACTAL_SPIRAL, &CComputerGraphicsView::OnFractalSpiral)
	ON_COMMAND(ID_LINE_BRESENHAM, &CComputerGraphicsView::OnLineBresenham)
	ON_COMMAND(ID_LINE_DDA, &CComputerGraphicsView::OnLineDDA)
	ON_COMMAND(ID_LINE_MIDBRESENHAM, &CComputerGraphicsView::OnLineMidbresenham)
	ON_COMMAND(ID_CIRCLE_MIDBRESENHAM, &CComputerGraphicsView::OnCircleMidbresenham)
	ON_COMMAND(ID_ELLIPSE_MIDBRESENHAM, &CComputerGraphicsView::OnEllipseMidbresenham)
	ON_COMMAND(ID_FILL_BOUNDARY, &CComputerGraphicsView::OnFillBoundary)
	ON_COMMAND(ID_FILL_FLOOD, &CComputerGraphicsView::OnFillFlood)
	ON_COMMAND(ID_LINE_TYPE, &CComputerGraphicsView::OnLineType)
	ON_COMMAND(ID_LINE_WIDTH, &CComputerGraphicsView::OnLineWidth)
	ON_COMMAND(ID_2D_TRANSLATION, &CComputerGraphicsView::On2dTranslation)
	ON_COMMAND(ID_2D_SCALING, &CComputerGraphicsView::On2dScaling)
	ON_COMMAND(ID_2D_ROTATION, &CComputerGraphicsView::On2dRotation)
	ON_COMMAND(ID_2D_SYMMETRICAL, &CComputerGraphicsView::On2dSymmetrical)
	ON_COMMAND(ID_2D_SHEAR, &CComputerGraphicsView::On2dShear)
	ON_COMMAND(ID_3D_TRANSLATION, &CComputerGraphicsView::On3dTranslation)
//	ON_WM_DELETEITEM()
ON_WM_DESTROY()
ON_WM_CREATE()
ON_WM_SIZE()
ON_COMMAND(ID_3D_SCALING, &CComputerGraphicsView::On3dScaling)
ON_COMMAND(ID_3D_ROTATION, &CComputerGraphicsView::On3dRotation)
ON_COMMAND(ID_3D_SYMMETRICAL, &CComputerGraphicsView::On3dSymmetrical)
ON_COMMAND(ID_3D_SHEAR, &CComputerGraphicsView::On3dShear)
END_MESSAGE_MAP()

// CComputerGraphicsView ����/����

CComputerGraphicsView::CComputerGraphicsView()
{
	this->m_GLPixelIndex = 0;
	this->m_hGLContext = NULL;
}

CComputerGraphicsView::~CComputerGraphicsView()
{
}

BOOL CComputerGraphicsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	cs.style |= (WS_CLIPCHILDREN | WS_CLIPSIBLINGS);
	return CView::PreCreateWindow(cs);
}

// CComputerGraphicsView ����

void CComputerGraphicsView::OnDraw(CDC* /*pDC*/)
{
	CComputerGraphicsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

// CComputerGraphicsView ��ӡ

void CComputerGraphicsView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}
BOOL CComputerGraphicsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}
void CComputerGraphicsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}
void CComputerGraphicsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CComputerGraphicsView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CComputerGraphicsView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}

// CComputerGraphicsView ���

#ifdef _DEBUG
void CComputerGraphicsView::AssertValid() const
{
	CView::AssertValid();
}

void CComputerGraphicsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CComputerGraphicsDoc* CComputerGraphicsView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CComputerGraphicsDoc)));
	return (CComputerGraphicsDoc*)m_pDocument;
}
#endif //_DEBUG

// CComputerGraphicsView ��Ϣ�������

void CComputerGraphicsView::OnLine()
{
	LineDailog lineDailog(this);
	lineDailog.DoModal();
	CClientDC dc_Line(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	dc_Line.SetViewportOrg(point_Origin);
	DrawLine(dc_Line, lineDailog.x1, lineDailog.y1, lineDailog.x2, lineDailog.y2);
	// TODO: �ڴ���������������
}
void CComputerGraphicsView::DrawLine(CDC &dc_line, int x1, int y1, int x2, int y2)
{
	
	dc_line.MoveTo(x1, y1);
	dc_line.LineTo(x2, y2);
}

void CComputerGraphicsView::OnFractalSnow()
{
	CClientDC dc_Fractal(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	dc_Fractal.SetViewportOrg(point_Origin);
	CPen pen(PS_SOLID, 2, RGB(31, 159, 245));
	dc_Fractal.SelectObject(&pen);
	TractalSpiral(dc_Fractal, 0);
	// TODO: �ڴ���������������
}
void CComputerGraphicsView::OnFractalSpiral()
{
	CClientDC dc_Fractal(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	dc_Fractal.SetViewportOrg(point_Origin);
	CPen pen(PS_SOLID, 1, RGB(31, 159, 245));
	dc_Fractal.SelectObject(&pen);
	Curve(dc_Fractal, -600, 600, 40, 153);
	// TODO: �ڴ���������������
}
//ѩ����ͼ����
void CComputerGraphicsView::TractalSnow(CDC &dc_Fractal, int iterations, int x1, int y1, int x2, int y2, int angel, double d)
{
	int x3 = int(x1 + d * cos((angel - 60) * PI / 180));
	int y3 = int(y1 + d * sin((angel - 60) * PI / 180));
	//��һ����
	TractalSnowEdge(dc_Fractal, iterations, x1, y1, x2, y2, angel, d);
	//�ڶ�����
	TractalSnowEdge(dc_Fractal, iterations, x2, y2, x3, y3, angel + 240, d);
	//��������
	TractalSnowEdge(dc_Fractal, iterations, x3, y3, x1, y1, angel + 120, d);

}
//ѩ���߻�ͼ����
void CComputerGraphicsView::TractalSnowEdge(CDC &dc_Fractal, int iterations, int x1, int y1, int x2, int y2, int angel, double d)
{
	if (iterations == 0)
	{
		dc_Fractal.MoveTo(x1, y1);
		dc_Fractal.LineTo(x2, y2);
	}
	else
	{
		//C��
		int x3 = x1 + int((x2 - x1) / 3);
		int y3 = y1 + int((y2 - y1) / 3);
		//D��
		int x4 = x1 + int(2 * (x2 - x1) / 3);
		int y4 = y1 + int(2 * (y2 - y1) / 3);
		//E��
		int x5 = x3 + int(d / 3 * cos((angel + 60) * PI / 180));
		int y5 = y3 + int(d / 3 * sin((angel + 60) * PI / 180));
		//�ݹ����
		TractalSnowEdge(dc_Fractal, iterations - 1, x1, y1, x3, y3, angel, d / 3);
		TractalSnowEdge(dc_Fractal, iterations - 1, x3, y3, x5, y5, (angel + 60) % 360, d / 3);
		TractalSnowEdge(dc_Fractal, iterations - 1, x5, y5, x4, y4, (angel - 60) % 360, d / 3);
		TractalSnowEdge(dc_Fractal, iterations - 1, x4, y4, x2, y2, angel, d / 3);
	}
}
//������ͼ����
void CComputerGraphicsView::TractalSpiral(CDC &dc_Fractal, int angel)
{
	if (angel > 360) return;
	int temp = angel;
	int x, y;
	//����ת����������תֱ������
	x = temp * cos(angel * PI / 180);
	y = temp * sin(angel * PI / 180);
	//dc_Fractal.SetPixel(x, y, 0);
	if (angel % 25 == 0)
	{
		int dx = angel / 2 * cos(angel * PI / 180);
		int dy = angel / 2 * sin(angel * PI / 180);
		TractalSnow(dc_Fractal, 3, x, y, x + dx, y + dy, angel, angel / 2);
	}
	TractalSpiral(dc_Fractal, angel + 1);
}
//���߻�ͼ����
void CComputerGraphicsView::Curve(CDC &dc_Fractal, int x0, int x1, double k, double b)
{
	for (int i = x0;i <= x1;i = 1 + i)
	{
		int j = -i * k / 100 + (i - b) * sin(i / k + b) / 3;
		dc_Fractal.SetPixel(i, j, 0);
		if (i % 120 == 0)
		{
			int size = rand() % 180 + 180;
			TractalSpiral_(dc_Fractal, i, j, 0, size);
		}

	}
}
//�������߻�ͼ����
void CComputerGraphicsView::TractalSpiral_(CDC & dc_Fractal, int x, int y, double angel, int size)
{
	for (int i = 0;i < size;i++)
	{
		int x_ = x + i * cos((i + angel) * PI / 180) / 5;
		int y_ = y + i * sin((i + angel) * PI / 180) / 5;
		dc_Fractal.SetPixel(x_, y_, 0);
	}
	angel += 60;
	if (angel >= 360)	return;
	else
	{
		TractalSpiral_(dc_Fractal, x, y, angel, size);
	}
}

void CComputerGraphicsView::OnLineDDA()
{
	LineDailog lineDailog(this);
	lineDailog.DoModal();
	CClientDC dc_Line(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	dc_Line.SetViewportOrg(point_Origin);
	LineDDA(dc_Line, lineDailog.x1, lineDailog.y1, lineDailog.x2, lineDailog.y2,0);
}
void CComputerGraphicsView::LineDDA(CDC &dc, int x1, int y1, int x2, int y2, int color)
{
	int dx, dy, espl, k;
	float x, y, xIncre, yIncre;
	dx = x2 - x1, dy = y2 - y1;
	x = x1, y = y1;
	if (abs(dx) > abs(dy))
		espl = abs(dx);
	else
		espl = abs(dy);
	xIncre = (float)dx / (float)(espl);
	yIncre = (float)dy / (float)(espl);
	for(k = 0;k <= espl;k++)
	{
		dc.SetPixel(int(x + 0.5), int(y + 0.5), color);
		x += xIncre, y += yIncre;
	}
}

void CComputerGraphicsView::OnLineMidbresenham()
{
	LineDailog lineDailog(this);
	lineDailog.DoModal();
	CClientDC dc_Line(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	dc_Line.SetViewportOrg(point_Origin);
	LineMidBresenham(dc_Line, lineDailog.x1, lineDailog.y1, lineDailog.x2, lineDailog.y2, 0);
}
void CComputerGraphicsView::LineMidBresenham(CDC &dc, int x0, int y0, int x1, int y1, int color)
{
	int dx, dy, d, upIncre, downIcre, x, y;
	if (x0 > x1)
	{
		x = x1; x1 = x0; x0 = x;
		y = y1; y1 = y0; y0 = y;
	}
	x = x0;
	y = y0;
	dx = x1 - x0;
	dy = y1 - y0;
	d = dx - 2 * dy;
	upIncre = 2 * dx - 2 * dy;
	downIcre = -2 * dy;
	while (x <= x1)
	{
		dc.SetPixel(x, y, color);
		x++;
		if (d < 0)
		{
			y++;
			d += upIncre;
		}
		else
			d += downIcre;
	}
}

void CComputerGraphicsView::OnLineBresenham()
{
	LineDailog lineDailog(this);
	lineDailog.DoModal();
	CClientDC dc_Line(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	dc_Line.SetViewportOrg(point_Origin);
	LineBresenham(dc_Line, lineDailog.x1, lineDailog.y1, lineDailog.x2, lineDailog.y2, 0);
}
void CComputerGraphicsView::LineBresenham(CDC &dc, int x0, int y0, int x1, int y1, int color)
{
	int dx, dy, e, x, y;
	if (x0 > x1)
	{
		x = x1; x1 = x0; x0 = x;
		y = y1; y1 = y0; y0 = y;
	}
	x = x0;
	y = y0;
	dx = x1 - x0;
	dy = y1 - y0;
	e = -x;
	while (x <= x1)
	{
		dc.SetPixel(x, y, color);
		x++;
		e += 2 * dy;
		if (e > 0)
		{
			y++;
			e -= 2 * dx;
		}
	}
}

void CComputerGraphicsView::OnCircleMidbresenham()
{
	// TODO: �ڴ���������������
	CClientDC dc_Circle(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	dc_Circle.SetViewportOrg(point_Origin);
	CircleDialog circleDialog(this);
	circleDialog.DoModal();
	CircleMidbresenham(dc_Circle,circleDialog.x, circleDialog.y, circleDialog.r, 0);
}
void CComputerGraphicsView::CirclePoint(CDC &dc, int x, int y, int Ox, int Oy, int color)
{
	dc.SetPixel(x + Ox, y + Oy, color);
	dc.SetPixel(-x + Ox, y + Oy, color);
	dc.SetPixel(x + Ox, -y + Oy, color);
	dc.SetPixel(-x + Ox, -y + Oy, color);
	dc.SetPixel(y + Ox, x + Oy, color);
	dc.SetPixel(-y + Ox, x + Oy, color);
	dc.SetPixel(y + Ox, -x + Oy, color);
	dc.SetPixel(-y + Ox, -x + Oy, color);
}
void CComputerGraphicsView::CircleMidbresenham(CDC &dc, int Ox, int Oy, int r, int color)
{
	int x, y, d;
	x = 0, y = r, d = 1 - r;
	while (x <= y)
	{
		CirclePoint(dc, x, y, Ox, Oy, color);
		if (d < 0)
			d += 2 * x + 3;
		else
			d += 2 * (x - y) + 5, y--;
		x++;
	}
}

void CComputerGraphicsView::OnEllipseMidbresenham()
{
	CClientDC dc_Ellipse(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	dc_Ellipse.SetViewportOrg(point_Origin);
	EllipseDialog ellipseDialog(this);
	ellipseDialog.DoModal();
	EllipseMidbresenham(dc_Ellipse, ellipseDialog.x, ellipseDialog.y, ellipseDialog.a, ellipseDialog.b, 0);
}
void CComputerGraphicsView::EllipsePoint(CDC &dc, int x, int y, int Ox, int Oy, int color)
{
	dc.SetPixel(x + Ox, y + Oy, color);
	dc.SetPixel(-x + Ox, y + Oy, color);
	dc.SetPixel(x + Ox, -y + Oy, color);
	dc.SetPixel(-x + Ox, -y + Oy, color);
}
void CComputerGraphicsView::EllipseMidbresenham(CDC &dc, int Ox, int Oy, int a, int b, int color)
{
	int x, y, a_, b_;
	float d1, d2;
	a_ = a > b ? a : b, b_ = a > b ? b : a;
	x = 0, y = b_;
	d1 = b_ * b_ + a_ * a_ * (-b_ + 0.25);
	a > b ? EllipsePoint(dc, x, y, Ox, Oy, color) : EllipsePoint(dc, y, x, Ox, Oy, color);
	while (b_ * b_ * (x + 1) < a_ * a_ * (y - 0.5))
	{
		if (d1 <= 0)
			d1 += b_*b_*(2 * x + 3), x++;
		else
			d1 += b_ * b_ * (2 * x + 3) + a_ * a_ * (-2 * y + 2), x++, y--;
		a > b ? EllipsePoint(dc, x, y, Ox, Oy, color) : EllipsePoint(dc, y, x, Ox, Oy, color);
	}
	d2 = b_ * b_ * (x + 0.5) * (x + 0.5) + a_ * a_ * ((y - 1) * (y - 1) - b_ * b_);
	while (y>0)
	{
		if (d2 <= 0)
			d2 += b_ * b_ * (2 * x + 2) + a_ * a_ * (-2 * y + 3), x++, y--;
		else
			d2 += a_ * a_ * (-2 * y + 3), y--;
		a > b ? EllipsePoint(dc, x, y, Ox, Oy, color): EllipsePoint(dc, y, x, Ox, Oy, color);
	}
}

void CComputerGraphicsView::OnFillBoundary()
{
	CClientDC dc_Boundary(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	dc_Boundary.SetViewportOrg(point_Origin);
	COLORREF boundaryColor = 0, fillColor = 0x00ff00;
	BoundaryFill(dc_Boundary, *new CPoint(0, 0), boundaryColor, fillColor);
}
void CComputerGraphicsView::BoundaryFill(CDC &dc, CPoint &point, COLORREF &boundaryColor, COLORREF &fillColor)
{
	CPoint direct4[4] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
	stack<CPoint> points;
	points.push(point);
	CPoint point_;
	while(!points.empty())
	{
		point_ = points.top();
		points.pop();
		dc.SetPixel(point_, fillColor);
		CPoint point_t;
		for (int i = 0; i < 4; i++)
		{
			point_t = point_ + direct4[i];
			if (dc.GetPixel(point_t) != fillColor && dc.GetPixel(point_t) != boundaryColor)
				points.push(point_t);
		}
	}
	
}

void CComputerGraphicsView::OnFillFlood()
{
	CClientDC dc_Boundary(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	dc_Boundary.SetViewportOrg(point_Origin);
	COLORREF interColor = 0x00ff00, fillColor = 0x095fa6;
	FloodFill(dc_Boundary, *new CPoint(0, 0), interColor, fillColor);
}
void CComputerGraphicsView::FloodFill(CDC &dc, CPoint &point, COLORREF &interColor, COLORREF &fillColor)
{
	CPoint direct4[4] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
	stack<CPoint> points;
	points.push(point);
	CPoint point_;
	while (!points.empty())
	{
		point_ = points.top();
		points.pop();
		dc.SetPixel(point_, fillColor);
		CPoint point_t;
		for (int i = 0; i < 4; i++)
		{
			point_t = point_ + direct4[i];
			if (dc.GetPixel(point_t) != fillColor && dc.GetPixel(point_t) == interColor)
				points.push(point_t);
		}
	}

}


void CComputerGraphicsView::OnLineType()
{
	LineTypeDialog lineTypeDialog(this);
	lineTypeDialog.DoModal();
	CClientDC lineTypeDC(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	lineTypeDC.SetViewportOrg(point_Origin);
	switch (lineTypeDialog.type)
	{
	case 0:
	{
		LineTypeSolid(lineTypeDC, lineTypeDialog.x0, lineTypeDialog.y0, lineTypeDialog.x1, lineTypeDialog.y1, 0);
	}
	case 1:
	{
		LineTypeDash(lineTypeDC, lineTypeDialog.x0, lineTypeDialog.y0, lineTypeDialog.x1, lineTypeDialog.y1, 0);
	}
	case 2:
	{
		LineTypeDot(lineTypeDC, lineTypeDialog.x0, lineTypeDialog.y0, lineTypeDialog.x1, lineTypeDialog.y1, 0);
	}
	default:
		break;
	}

}
void CComputerGraphicsView::LineTypeSolid(CDC &dc, int x0, int y0, int x1, int y1, int color)
{
	int dx, dy, e, x, y;
	if (x0 > x1)
	{
		x = x1; x1 = x0; x0 = x;
		y = y1; y1 = y0; y0 = y;
	}
	x = x0;
	y = y0;
	dx = x1 - x0;
	dy = y1 - y0;
	e = -x;
	while (x <= x1)
	{
		dc.SetPixel(x, y, color);
		x++;
		e += 2 * dy;
		if (e > 0)
		{
			y++;
			e -= 2 * dx;
		}
	}
}
void CComputerGraphicsView::LineTypeDash(CDC &dc, int x0, int y0, int x1, int y1, int color)
{
	int dx, dy, e, x, y, dash;
	if (x0 > x1)
	{
		x = x1; x1 = x0; x0 = x;
		y = y1; y1 = y0; y0 = y;
	}
	dash = 0;
	x = x0;
	y = y0;
	dx = x1 - x0;
	dy = y1 - y0;
	e = -x;
	while (x <= x1)
	{
		if(dash < 10)
			dc.SetPixel(x, y, color);
		x++;
		e += 2 * dy;
		if (e > 0)
		{
			y++;
			e -= 2 * dx;
		}
		dash = (dash + 1) % 20;
	}
}
void CComputerGraphicsView::LineTypeDot(CDC &dc, int x0, int y0, int x1, int y1, int color)
{
	int dx, dy, e, x, y, dot;
	if (x0 > x1)
	{
		x = x1; x1 = x0; x0 = x;
		y = y1; y1 = y0; y0 = y;
	}
	dot = 0;
	x = x0;
	y = y0;
	dx = x1 - x0;
	dy = y1 - y0;
	e = -x;
	while (x <= x1)
	{
		if (dot == 0)
			dc.SetPixel(x, y, color);
		x++;
		e += 2 * dy;
		if (e > 0)
		{
			y++;
			e -= 2 * dx;
		}
		dot = (dot + 1) % 5;
	}
}

void CComputerGraphicsView::OnLineWidth()
{
	LineWidthDialog lineWidthDialog(this);
	lineWidthDialog.DoModal();
	CClientDC lineWidthDC(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	lineWidthDC.SetViewportOrg(point_Origin);
	LineWidth(lineWidthDC, lineWidthDialog.x0, lineWidthDialog.y0, lineWidthDialog.x1, lineWidthDialog.y1, lineWidthDialog.width_, 0);
}
void CComputerGraphicsView::LineWidth(CDC &dc, int x0, int y0, int x1, int y1, int width, int color)
{
	int dx, dy, e, x, y;
	if (x0 > x1)
	{
		x = x1; x1 = x0; x0 = x;
		y = y1; y1 = y0; y0 = y;
	}
	x = x0;
	y = y0;
	dx = x1 - x0;
	dy = y1 - y0;
	e = -x;
	COLORREF lineColor = RGB(color & 0x0000FF, (color >> 8) & 0x0000FF, (color >> 16) & 0x0000FF);
	COLORREF boundaryColor = RGB((color & 0x0000FF) - 1, ((color >> 8) & 0x0000FF) - 1, ((color >> 16) & 0x0000FF) - 1);
	while (x <= x1)
	{
		SetLinePoint(dc, x, y, width, color);
		//BoundaryFill(dc, *new CPoint(x, y), lineColor, lineColor);
		x++;
		e += 2 * dy;
		if (e > 0)
		{
			y++;
			e -= 2 * dx;
		}
	}
}
void CComputerGraphicsView::SetLinePoint(CDC &dc, int x, int y, int r, int color)
{
	while (r - 1)
	{
		CircleMidbresenham(dc, x, y, r, color);
		r --;
	}
}

void CComputerGraphicsView::PointTransformation(int points[4][3], double matrix[4][4], int transformedPoints[4][3], int dimensionality)
{
	double * tempPoint = new double[dimensionality + 1];
	double * tempPoint_ = new double[dimensionality];
	tempPoint[dimensionality] = 1;
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < dimensionality;j++)
			tempPoint[j] = points[i][j];
		for (int j = 0;j < dimensionality;j++)
		{
			tempPoint_[j] = 0;
			for (int k = 0;k < dimensionality + 1;k++)
			{
				tempPoint_[j] += tempPoint[k] * matrix[k][j];
			}
			transformedPoints[i][j] = tempPoint_[j];
		}
		
	}
}

void CComputerGraphicsView::On2dTranslation()
{
	CClientDC dc(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	dc.SetViewportOrg(point_Origin);

	CPoint points[4];

	RectDialog rectDialog(this);
	rectDialog.DoModal();

	int points_[4][3] = { {0,0,0},{0,0,0},{0,0,0},{0,0,0} };
	for (int i = 0;i < 4;i++)
		points[i].x = points_[i][0] = rectDialog.points[i][0], points[i].y = points_[i][1] = rectDialog.points[i][1];
	dc.Polygon(points,4);

	TranslationDialog translationDialog(this);
	translationDialog.DoModal();

	double matrix[4][4];
	for (int i = 0;i < 16;i++)
		matrix[i / 4][i % 4] = translationDialog.matrix[i / 4][i % 4];
	int points__[4][3] = { {0,0,0},{0,0,0},{0,0,0},{0,0,0} };
	PointTransformation(points_, matrix, points__);
	for (int i = 0;i < 4;i++)
		points[i].x = points__[i][0], points[i].y = points__[i][1];

	dc.Polygon(points, 4);
}
void CComputerGraphicsView::On2dScaling()
{
	CClientDC dc(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	dc.SetViewportOrg(point_Origin);

	CPoint points[4];

	RectDialog rectDialog(this);
	rectDialog.DoModal();

	int points_[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	for (int i = 0;i < 4;i++)
		points[i].x = points_[i][0] = rectDialog.points[i][0], points[i].y = points_[i][1] = rectDialog.points[i][1];
	dc.Polygon(points, 4);

	ScalingDialog scalingDialog(this);
	scalingDialog.DoModal();

	double matrix[4][4];
	for (int i = 0;i < 16;i++)
		matrix[i / 4][i % 4] = scalingDialog.matrix[i / 4][i % 4];
	int points__[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	PointTransformation(points_, matrix, points__);
	for (int i = 0;i < 4;i++)
		points[i].x = points__[i][0], points[i].y = points__[i][1];

	dc.Polygon(points, 4);
}
void CComputerGraphicsView::On2dRotation()
{
	CClientDC dc(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	dc.SetViewportOrg(point_Origin);

	CPoint points[4];

	RectDialog rectDialog(this);
	rectDialog.DoModal();

	int points_[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	for (int i = 0;i < 4;i++)
		points[i].x = points_[i][0] = rectDialog.points[i][0], points[i].y = points_[i][1] = rectDialog.points[i][1];
	dc.Polygon(points, 4);

	Rotation2DDialog rotation2DDialog(this);
	rotation2DDialog.DoModal();

	double matrix[4][4];
	for (int i = 0;i < 16;i++)
		matrix[i / 4][i % 4] = rotation2DDialog.matrix[i / 4][i % 4];
	int points__[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	PointTransformation(points_, matrix, points__);
	for (int i = 0;i < 4;i++)
		points[i].x = points__[i][0], points[i].y = points__[i][1];

	dc.Polygon(points, 4);
}
void CComputerGraphicsView::On2dSymmetrical()
{
	CClientDC dc(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	dc.SetViewportOrg(point_Origin);

	CPoint points[4];

	RectDialog rectDialog(this);
	rectDialog.DoModal();

	int points_[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	for (int i = 0;i < 4;i++)
		points[i].x = points_[i][0] = rectDialog.points[i][0], points[i].y = points_[i][1] = rectDialog.points[i][1];
	dc.Polygon(points, 4);

	Symmetrical2DDialog symmetrical2DDialog(this);
	symmetrical2DDialog.DoModal();

	double matrix[4][4];
	for (int i = 0;i < 16;i++)
		matrix[i / 4][i % 4] = symmetrical2DDialog.matrix[i / 4][i % 4];
	int points__[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	PointTransformation(points_, matrix, points__);
	for (int i = 0;i < 4;i++)
		points[i].x = points__[i][0], points[i].y = points__[i][1];

	dc.Polygon(points, 4);
}
void CComputerGraphicsView::On2dShear()
{
	CClientDC dc(this);
	CRect rect_ViewSize;
	GetClientRect(&rect_ViewSize);
	CPoint point_Origin(rect_ViewSize.CenterPoint());
	dc.SetViewportOrg(point_Origin);

	CPoint points[4];

	RectDialog rectDialog(this);
	rectDialog.DoModal();

	int points_[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	for (int i = 0;i < 4;i++)
		points[i].x = points_[i][0] = rectDialog.points[i][0], points[i].y = points_[i][1] = rectDialog.points[i][1];
	dc.Polygon(points, 4);

	ShearDialog shearDialog(this);
	shearDialog.DoModal();

	double matrix[4][4];
	for (int i = 0;i < 16;i++)
		matrix[i / 4][i % 4] = shearDialog.matrix[i / 4][i % 4];
	int points__[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	PointTransformation(points_, matrix, points__);
	for (int i = 0;i < 4;i++)
		points[i].x = points__[i][0], points[i].y = points__[i][1];

	dc.Polygon(points, 4);
}

bool CComputerGraphicsView::SetWindowPixelFormat(HDC hDC)
{
	PIXELFORMATDESCRIPTOR pixelDesc =
	{
		sizeof(PIXELFORMATDESCRIPTOR),           //nSize�ṹ����
		1,                                       //nVersion�ṹ�汾
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER | PFD_SUPPORT_GDI,        //dwFlags����OpenGL��δ�������
												   /*
												   wFlags�ܽ������±�־��
												   PFD_DRAW_TO_WINDOW ʹ֮���ڴ��ڻ��������豸���ڻ�ͼ��
												   PFD_DRAW_TO_BITMAP ʹ֮�����ڴ��е�λͼ��ͼ��
												   PFD_SUPPORT_GDI ʹ֮�ܵ���GDI������ע�����ָ����PFD_DOUBLEBUFFER�����ѡ���Ч����
												   PFD_SUPPORT_OpenGL ʹ֮�ܵ���OpenGL������
												   PFD_GENERIC_FORMAT �����������ظ�ʽ��Windows GDI��������ɵ�����Ӳ���豸��������֧�֣�����ָ����һ�
												   PFD_NEED_PALETTE ���߻������Ƿ���Ҫ��ɫ�壬�����������ɫ��ʹ��24�� 32λɫ�����Ҳ��Ḳ�ǵ�ɫ�壻
												   PFD_NEED_SYSTEM_PALETTE �����־ָ���������Ƿ��ϵͳ��ɫ�嵱���������ɫ���һ���֣�
												   PFD_DOUBLEBUFFER ָ��ʹ����˫��������ע��GDI������ʹ����˫�������Ĵ����л�ͼ����
												   PFD_STEREO ָ�����һ������Ƿ�����ͼ������֯��
												   PFD_SWAP_LAYER_BUFFERS
												   */
		PFD_TYPE_RGBA,  //iPixelType,��ɫģʽ����������PFD_TYPE_RGBA��ζ��ÿһλ(bit)�������rgb��������ֵ��PFD_TYPE_COLORINDEX��ζ��ÿһλ��������ڲ�ɫ���ұ��е�����ֵ
		24,   //cColorBits������ָ��һ����ɫ��λ������RGBA��˵��λ��������ɫ�к졢�̡�����������ռ��λ��������ɫ������ֵ��˵��ָ���Ǳ��е���ɫ����
		0,0,0,0,0,0,  //cRedBits��cRedShifts��cGreenBits��cGreenShifts��cBlueBits��cBlueShifts��,�����������ã�һ����0
					  //cRedBits��cGreenBits��cBlueBits������������Ӧ������ʹ�õ�λ����
					  //cRedShift��cGreenShift��cBlue-Shift������������������ɫ��ʼ��ƫ������ռ��λ����
		0,                                       //cAlphaBits,RGB��ɫ������Alpha��λ��                            
		0,                                 //cAlphaShift���Ѿ��������ã���0                   
		0,                                       //cAcuumBits�ۼƻ����λ��
		0,0,0,0,                                 //cAcuumRedBits/cAcuumGreenBits/cAcuumBlueBits/cAcuumAlphaBits,�����������ã���0
		32,                                      //cDepthBits��Ȼ����λ��
		0,                                       //cStencilBits,ģ�建���λ��
		0,                                       //cAuxBuffers�����������λ����һ����0
		PFD_MAIN_PLANE,                          //iLayerType,˵����������ͣ��ɺ�����0�������ڵİ汾������
												 //PFD_MAIN_PLANE,PFD_OVER_LAY_PLANE,PFD_UNDERLAY_PLANE
		0,0,0,0                                  //bReserved,dwLayerMask,dwVisibleMask,dwDamageMask,������0
	};

	this->m_GLPixelIndex = ChoosePixelFormat(hDC, &pixelDesc);//ѡ������������ظ�ʽ
															  /*
															  ChoosePixelFormat��������������һ����hDc����һ����һ��ָ��PIXELFORMATDESCRIPTOR�ṹ��ָ��&pixelDesc
															  �ú������ش����ظ�ʽ������ֵ,�������0���ʾʧ�ܡ�
															  ���纯��ʧ�ܣ�����ֻ�ǰ�����ֵ��Ϊ1���� DescribePixelFormat�õ����ظ�ʽ������
															  ����������һ��û�õ�֧�ֵ����ظ�ʽ����ChoosePixelFormat���᷵������Ҫ������ظ�ʽ��ӽ���һ��ֵ
															  һ�����ǵõ�һ�����ظ�ʽ������ֵ����Ӧ�����������ǾͿ��Ե���SetPixelFormat�������ظ�ʽ������ֻ������һ�Ρ�
															  */
	if (this->m_GLPixelIndex == 0)
	{//ѡ��ʧ��
		this->m_GLPixelIndex = 1;//Ĭ�ϵ����ظ�ʽ
								 //��Ĭ�ϵ����ظ�ʽ��������
								 //
		if (DescribePixelFormat(hDC, this->m_GLPixelIndex, sizeof(PIXELFORMATDESCRIPTOR), &pixelDesc) == 0)
		{
			return FALSE;
		}
	}

	if (SetPixelFormat(hDC, this->m_GLPixelIndex, &pixelDesc) == FALSE)
	{
		return FALSE;
	}
	return TRUE;
}
bool CComputerGraphicsView::CreateViewGLContext(HDC hDC)
{
	//WglCreateContext��������һ���µ�OpenGL��Ⱦ������(RC)
	//����������������ڻ��Ƶ���hdc���ص��豸
	//�����Ⱦ�������к��豸������(dc)һ�������ظ�ʽ.
	this->m_hGLContext = wglCreateContext(hDC);//����RC

	if (this->m_hGLContext == NULL)
	{//����ʧ��
		return FALSE;
	}

	/*
	wglMakeCurrent �����趨OpenGL��ǰ�߳�(�߳������)����Ⱦ������
	�Ժ�����߳����е�OpenGL���ö��������hdc��ʶ���豸�ϻ��ơ�
	��Ҳ����ʹ��wglMakeCurrent �������ı�����̵߳ĵ�ǰ��Ⱦ����
	ʹ֮�����ǵ�ǰ����Ⱦ������
	*/
	if (wglMakeCurrent(hDC, this->m_hGLContext) == FALSE)
	{//ѡΪ��ǰRCʧ��
		return FALSE;
	}
	return TRUE;
}
bool CComputerGraphicsView::InitGL()
{
	glShadeModel(GL_SMOOTH);                            // Enable Smooth Shading
	glClearColor(255.0, 255.0, 255.0, 0.0);// Black Background
	glClearDepth(1.0f);                                    // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);                            // Enables Depth Testing
	glDepthFunc(GL_LEQUAL);                                // The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);    // Really Nice Perspective Calculations
	return TRUE;                                        // Initialization Went OK
}

int CComputerGraphicsView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	//�õ�һ�����ڶ���CWnd����������ָ��ľ����HWND��  
	HWND hWnd = this->GetSafeHwnd();
	//GetDC�ú�������һָ�����ڵĿͻ������������Ļ����ʾ�豸�����Ļ����ľ��
	//�Ժ������GDI������ʹ�øþ�������豸�����Ļ����л�ͼ��
	HDC hDC = ::GetDC(hWnd);

	if (this->SetWindowPixelFormat(hDC) == FALSE)
	{//�������ظ�ʽ
		return 0;
	}
	if (this->CreateViewGLContext(hDC) == FALSE)
	{//����RC��ѡΪ����
		return 0;
	}
	if (!this->InitGL())
	{//��ʼ��openGL
		return 0;
	}
	return 0;
}
void CComputerGraphicsView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	if (wglGetCurrentContext() != NULL)
	{
		wglMakeCurrent(NULL, NULL);
	}
	if (this->m_hGLContext != NULL)
	{
		wglDeleteContext(this->m_hGLContext);
		this->m_hGLContext = NULL;
	}
}
void CComputerGraphicsView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	/*
	OnSizeͨ��glViewport(0, 0, width, height)�������ӿں��ӿ����ꡣ
	glViewport�ĵ�һ�������������ӿ����½ǵ��������꣬�������ĸ��������ӿڵĿ�Ⱥ͸߶ȡ�

	OnSize�е�glMatrixMode���������þ���ģʽ�ģ���������ѡ�GL_MODELVIEW��GL_PROJECTION�� GL_TEXTURE��
	GL_MODELVIEW��ʾ��ʵ������ϵת����������ϵ��
	GL_PROJECTION��ʾ����������ϵת����������ϵ��
	GL_TEXTURE��ʾ�Ӷ������������ϵ��ճ�����������ϵ�ı任��

	glLoadIdentity��ʼ�����̾���(project matrix)
	gluOrtho2D�ѹ��̾������ó���ʾһ����άֱ����ʾ����
	*/
	GLsizei width, height;
	width = cx;
	height = cy;
	if (height == 0)                                        // Prevent A Divide By Zero By
	{
		height = 1;                                        // Making Height Equal One
	}

	glViewport(0, 0, width, height);                        // Reset The Current Viewport
	//gluOrtho2D(-width / 2, width / 2, -height / 2, height / 2);
	glMatrixMode(GL_PROJECTION);                        // Select The Projection Matrix
	glLoadIdentity();                                    // Reset The Projection Matrix
														 // Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);//͸��ͶӰ
	glMatrixMode(GL_MODELVIEW);                            // Select The Modelview Matrix
	glLoadIdentity();                                    // Reset The Modelview Matrix
}

void CComputerGraphicsView::Display(CDC &dc, int points[4][3], int points_[4][3])
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -5.0f);
	//glRotatef(60.0, 0.0f, 1.0f, 0.0f);
	//ԭͼ
	glBegin(GL_TRIANGLES);
		glColor3f(255.0, 0.0, 0.0);
		glVertex3f(points[0][0] / 100.0, points[0][1] / 100.0, points[0][2] / 100.0);
		glColor3f(0.0, 255.0, 0.0);
		glVertex3f(points[1][0] / 100.0, points[1][1] / 100.0, points[1][2] / 100.0);
		glColor3f(0.0, 0.0, 255.0);
		glVertex3f(points[2][0] / 100.0, points[2][1] / 100.0, points[2][2] / 100.0);
		glColor3f(0.0, 255.0, 0.0);
		glVertex3f(points[0][0] / 100.0, points[0][1] / 100.0, points[0][2] / 100.0);
		glColor3f(0.0, 0.0, 255.0);
		glVertex3f(points[1][0] / 100.0, points[1][1] / 100.0, points[1][2] / 100.0);
		glColor3f(255.0, 0.0, 0.0);
		glVertex3f(points[3][0] / 100.0, points[3][1] / 100.0, points[3][2] / 100.0);
		glColor3f(0.0, 0.0, 255.0);
		glVertex3f(points[0][0] / 100.0, points[0][1] / 100.0, points[0][2] / 100.0);
		glColor3f(255.0, 0.0, 0.0);
		glVertex3f(points[2][0] / 100.0, points[2][1] / 100.0, points[2][2] / 100.0);
		glColor3f(0.0, 255.0, 0.0);
		glVertex3f(points[3][0] / 100.0, points[3][1] / 100.0, points[3][2] / 100.0);
		glColor3f(255.0, 0.0, 0.0);
		glVertex3f(points[1][0] / 100.0, points[1][1] / 100.0, points[1][2] / 100.0);
		glColor3f(0.0, 255.0, 0.0);
		glVertex3f(points[2][0] / 100.0, points[2][1] / 100.0, points[2][2] / 100.0);
		glColor3f(0.0, 0.0, 255.0);
		glVertex3f(points[3][0] / 100.0, points[3][1] / 100.0, points[3][2] / 100.0);
	glEnd();
	//�任ͼ
	glBegin(GL_TRIANGLES);
		glColor3f(255.0, 0.0, 0.0);
		glVertex3f(points_[0][0] / 100.0, points_[0][1] / 100.0, points_[0][2] / 100.0);
		glColor3f(0.0, 255.0, 0.0);
		glVertex3f(points_[1][0] / 100.0, points_[1][1] / 100.0, points_[1][2] / 100.0);
		glColor3f(0.0, 0.0, 255.0);
		glVertex3f(points_[2][0] / 100.0, points_[2][1] / 100.0, points_[2][2] / 100.0);
		glColor3f(0.0, 255.0, 0.0);
		glVertex3f(points_[0][0] / 100.0, points_[0][1] / 100.0, points_[0][2] / 100.0);
		glColor3f(0.0, 0.0, 255.0);
		glVertex3f(points_[1][0] / 100.0, points_[1][1] / 100.0, points_[1][2] / 100.0);
		glColor3f(255.0, 0.0, 0.0);
		glVertex3f(points_[3][0] / 100.0, points_[3][1] / 100.0, points_[3][2] / 100.0);
		glColor3f(0.0, 0.0, 255.0);
		glVertex3f(points_[0][0] / 100.0, points_[0][1] / 100.0, points_[0][2] / 100.0);
		glColor3f(255.0, 0.0, 0.0);
		glVertex3f(points_[2][0] / 100.0, points_[2][1] / 100.0, points_[2][2] / 100.0);
		glColor3f(0.0, 255.0, 0.0);
		glVertex3f(points_[3][0] / 100.0, points_[3][1] / 100.0, points_[3][2] / 100.0);
		glColor3f(255.0, 0.0, 0.0);
		glVertex3f(points_[1][0] / 100.0, points_[1][1] / 100.0, points_[1][2] / 100.0);
		glColor3f(0.0, 255.0, 0.0);
		glVertex3f(points_[2][0] / 100.0, points_[2][1] / 100.0, points_[2][2] / 100.0);
		glColor3f(0.0, 0.0, 255.0);
		glVertex3f(points_[3][0] / 100.0, points_[3][1] / 100.0, points_[3][2] / 100.0);
	glEnd();
	glFlush();
	SwapBuffers(dc.m_hDC);
}

void CComputerGraphicsView::On3dTranslation()
{
	CClientDC dc(this);

	int points[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	int points_[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	double matrix[4][4];

	RectDialog rectDialog(this, 3);
	rectDialog.DoModal();
	for (int i = 0;i < 4;i++)
		points[i][0] = rectDialog.points[i][0], points[i][1] = rectDialog.points[i][1];

	TranslationDialog translationDialog(this, 3);
	translationDialog.DoModal();
	for (int i = 0;i < 16;i++)
		matrix[i / 4][i % 4] = translationDialog.matrix[i / 4][i % 4];
	PointTransformation(points, matrix, points_, 3);

	Display(dc, points, points_);
}
void CComputerGraphicsView::On3dScaling()
{
	CClientDC dc(this);

	int points[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	int points_[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	double matrix[4][4];

	RectDialog rectDialog(this, 3);
	rectDialog.DoModal();
	for (int i = 0;i < 4;i++)
		points[i][0] = rectDialog.points[i][0], points[i][1] = rectDialog.points[i][1];

	ScalingDialog scalingDialog(this,3);
	scalingDialog.DoModal();
	for (int i = 0;i < 16;i++)
		matrix[i / 4][i % 4] = scalingDialog.matrix[i / 4][i % 4];
	PointTransformation(points, matrix, points_, 3);

	Display(dc, points, points_);

}
void CComputerGraphicsView::On3dRotation()
{
	CClientDC dc(this);

	int points[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	int points_[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	double matrix[4][4];

	RectDialog rectDialog(this, 3);
	rectDialog.DoModal();
	for (int i = 0;i < 4;i++)
		points[i][0] = rectDialog.points[i][0], points[i][1] = rectDialog.points[i][1];

	Rotation3DDialog rotation3DDialog(this);
	rotation3DDialog.DoModal();
	for (int i = 0;i < 16;i++)
		matrix[i / 4][i % 4] = rotation3DDialog.matrix[i / 4][i % 4];
	PointTransformation(points, matrix, points_, 3);

	Display(dc, points, points_);
}
void CComputerGraphicsView::On3dSymmetrical()
{
	CClientDC dc(this);

	int points[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	int points_[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	double matrix[4][4];

	RectDialog rectDialog(this, 3);
	rectDialog.DoModal();
	for (int i = 0;i < 4;i++)
		points[i][0] = rectDialog.points[i][0], points[i][1] = rectDialog.points[i][1];

	Symmetrical3DDialog symmetrical3DDialog(this);
	symmetrical3DDialog.DoModal();
	for (int i = 0;i < 16;i++)
		matrix[i / 4][i % 4] = symmetrical3DDialog.matrix[i / 4][i % 4];
	PointTransformation(points, matrix, points_, 3);

	Display(dc, points, points_);
}
void CComputerGraphicsView::On3dShear()
{
	CClientDC dc(this);

	int points[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	int points_[4][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 } };
	double matrix[4][4];

	RectDialog rectDialog(this, 3);
	rectDialog.DoModal();
	for (int i = 0;i < 4;i++)
		points[i][0] = rectDialog.points[i][0], points[i][1] = rectDialog.points[i][1];

	ShearDialog shearDialog(this, 3);
	shearDialog.DoModal();
	for (int i = 0;i < 16;i++)
		matrix[i / 4][i % 4] = shearDialog.matrix[i / 4][i % 4];
	PointTransformation(points, matrix, points_, 3);

	Display(dc, points, points_);
}
