#include <afxwin.h> 

static int count = 1;

class CMyMainWnd : public CFrameWnd
{
public:
	CMyMainWnd()
	{
		// конструктор   
		Create(NULL, L"WINDOW"); 
		SetTimer(1, 1000, NULL);
	}
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnTimer(UINT);
	afx_msg void OnPaint();
	//afx_msg void OnChar(UINT, UINT, UINT);
	DECLARE_MESSAGE_MAP()
};

class CMyApp : public CWinApp
{
public:
	CMyApp() {}; // конструктор 
	virtual BOOL InitInstance()
	{
		m_pMainWnd = new CMyMainWnd();
		m_pMainWnd->ShowWindow(SW_SHOW);
		return TRUE;
	}
};

void CMyMainWnd::OnLButtonDown(UINT, CPoint)
{
	static int c = 1;
	if (c<5)
	{
		MoveWindow(NULL, NULL, 500*c, 500*c);
		c++;
	}

	if (c>=5)
	{
		MoveWindow(NULL, NULL, 500 , 500 );
	}
}

void CMyMainWnd::OnTimer(UINT)
{
	MessageBeep(-1);
	count++;
	OnPaint();	
	Invalidate();
}

void CMyMainWnd::OnPaint()
{
	static int f = 100;
	if (f > 0)
	{
		CPaintDC* pDC = new CPaintDC(this);
		if (count%2==0)
		{
			pDC->Rectangle(5, 5, 50, 50);
			pDC->TextOutW(100, 100, L"Kvadrat");
		}
		if (count%2!=0)
		{
			pDC->Ellipse(50, 50, 10, 10);
			pDC->TextOutW(100, 100, L"Ellips");
		}
		f--;
	}
}


BEGIN_MESSAGE_MAP(CMyMainWnd, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_PAINT()
END_MESSAGE_MAP()

CMyApp theApp;
