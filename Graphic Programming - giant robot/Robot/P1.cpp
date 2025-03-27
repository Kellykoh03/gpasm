
#include <Windows.h>
#include <gl/GL.h>
#include <math.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "OpenGL Window"

int qNo = 1;				//question no

//for method3japanFlag
float m3x = 0, m3y = 0;		//Origin of circle (x, y)
float m3r = 0.2;			//Radius
float m3angle = 0;			//angle to draw a triangle
float m3x2 = 0, m3y2 = 0;	//Point on circle (x2, y2)
float m3PI = 3.1429;		//PI
float noOfTri = 30;			//no of triangles in the circle



LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		else if (wParam == 0x31) qNo = 1; //press key '1'
		else if (wParam == 0x32) qNo = 2; //press key '2'
		else if (wParam == 0x33) qNo = 3;
		else if (wParam == 0x34) qNo = 4;
		else if (wParam == 0x35) qNo = 5;
		else if (wParam == 0x36) qNo = 6;
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

float divideBy255(float num) {
	return num / 255;
}

void testTriangle() {
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.3f, -0.5f);
	glVertex2f(-0.3f, 0.5f);
	glVertex2f(0.3f, -0.5f);
	glEnd();
}

void pahangFlag() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.3f, 0.3f);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.3f, 0.0f);
	glVertex2f(-0.3f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.3f, 0.0f);
	glVertex2f(0.3f, 0.0f);
	glVertex2f(0.3f, -0.3f);
	glVertex2f(-0.3f, -0.3f);
	glEnd();

	glLineWidth(6);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.3f, 0.3f);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.3f, -0.3f);
	glVertex2f(-0.3f, -0.3f);
	glVertex2f(-0.3f, 0.3f);
	glEnd();
}

void n9Flag() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(-0.3f, 0.3f);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.3f, -0.3f);
	glVertex2f(-0.3f, -0.3f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.3f, 0.3f);
	glVertex2f(0.0f, 0.3f);
	glVertex2f(0.0f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glEnd();

	glLineWidth(6);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.3f, 0.3f);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.3f, -0.3f);
	glVertex2f(-0.3f, -0.3f);
	glVertex2f(-0.3f, 0.3f);
	glEnd();
}

void englandFlag() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glLineWidth(6);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.3f, 0.3f);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.3f, -0.3f);
	glVertex2f(-0.3f, -0.3f);
	glVertex2f(-0.3f, 0.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex2f(-0.3f, 0.3f);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.3f, -0.3f);
	glVertex2f(-0.3f, -0.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(-0.3f, 0.3f);
	glVertex2f(-0.05f, 0.3f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.05f, 0.05f);
	glVertex2f(-0.3f, 0.05f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(0.05f, 0.3f);
	glVertex2f(0.3f, 0.3f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.3f, 0.05f);
	glVertex2f(0.05f, 0.05f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.3f, -0.07f);
	glVertex2f(-0.05f, -0.07f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(-0.05f, -0.3f);
	glVertex2f(-0.3f, -0.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.05f, -0.07f);
	glVertex2f(0.3f, -0.07f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(0.3f, -0.3f);
	glVertex2f(0.05f, -0.3f);
	glEnd();
}

void scotlandFlag() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glLineWidth(6);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.3f, 0.3f);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.3f, -0.3f);
	glVertex2f(-0.3f, -0.3f);
	glVertex2f(-0.3f, 0.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.3f, 0.3f);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.3f, -0.3f);
	glVertex2f(-0.3f, -0.3f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0, divideBy255(94), divideBy255(184));
	glVertex2f(-0.25f, 0.3f);
	glVertex2f(0.0f, 0.05f);
	glVertex2f(0.25f, 0.3f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0, divideBy255(94), divideBy255(184));
	glVertex2f(-0.3f, 0.2f);
	glVertex2f(-0.07f, 0.0f);
	glVertex2f(-0.3f, -0.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0, divideBy255(94), divideBy255(184));
	glVertex2f(0.3f, 0.2f);
	glVertex2f(0.07f, 0.0f);
	glVertex2f(0.3f, -0.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(0.25f, -0.3f);
	glColor3f(0, divideBy255(94), divideBy255(184));
	glVertex2f(0.0f, -0.05f);
	glVertex2f(-0.25f, -0.3f);
	glEnd();
}

void method1japanFlag() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	const int steps = 100;
	const float angle = 3.1415926 * 2.f / steps;
	int i;

	float x = 0.0f;
	float y = 0.0f;
	float radius = 0.3f;

	float prevX = x;
	float prevY = y - radius;

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glVertex2f(x, y);
	for (i = 0; i <= steps; i++) {
		float newX = radius * sin(angle * i);
		float newY = -radius * cos(angle * i);

		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(prevX, prevY, 0.0f);
		glVertex3f(newX, newY, 0.0f);
		glEnd();

		prevX = newX;
		prevY = newY;
	}
}

void method2japanFlag() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	float theta;
	glLineWidth(6);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.3f, 0.3f);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.3f, -0.3f);
	glVertex2f(-0.3f, -0.3f);
	glVertex2f(-0.3f, 0.3f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.3f, 0.3f);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.3f, -0.3f);
	glVertex2f(-0.3f, -0.3f);
	glEnd();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(0.0 + 0.15 * cos(theta), 0.0 + 0.15 * sin(theta));
	}
	glEnd();
}

void method3japanFlag() {
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m3x, m3y);
		glColor3f(1.0f, 0.0f, 0.0f);
		for (m3angle = 0; m3angle <= (2 * m3PI); m3angle += (2 * m3PI) / noOfTri) {
			m3x2 = m3x + m3r * cos(m3angle);
			m3y2 = m3y + m3r * sin(m3angle);

			glVertex2f(m3x2, m3y2);
		}
	glEnd();
}

void smileFace() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	int i;
	float x = 0;
	float y = 0;
	float theta;

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(-0.68 + 0.15 * cos(theta), 0.2 + 0.15 * sin(theta));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(0.68 + 0.15 * cos(theta), 0.2 + 0.15 * sin(theta));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(divideBy255(255), divideBy255(87), divideBy255(51));
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(-0.68 + 0.13 * cos(theta), 0.2 + 0.13 * sin(theta));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(divideBy255(255), divideBy255(87), divideBy255(51));
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(0.68 + 0.13 * cos(theta), 0.2 + 0.13 * sin(theta));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(0.0 + 0.7 * cos(theta), 0.0 + 0.7 * sin(theta));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(0.0 + 0.1 * cos(theta), 0.0 + 0.1 * sin(theta));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(-0.3 + 0.03 * cos(theta), 0.25 + 0.05 * sin(theta));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(0.3 + 0.03 * cos(theta), 0.25 + 0.05 * sin(theta));
	}
	glEnd();

	glLineWidth(5.0f);
	/*glBegin(GL_LINES);
	glVertex2f(0.0f, 0.1f);
	glVertex2f(0.0f, -0.15f);
	glEnd();*/

	/*glBegin(GL_LINES);
	glVertex2f(-0.005f, -0.15f);
	glVertex2f(0.07f, -0.15f);
	glEnd();*/

	glBegin(GL_LINES);
	glVertex2f(0.45f, 0.35f);
	glVertex2f(0.1f, 0.25f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-0.45f, 0.35);
	glVertex2f(-0.1f, 0.25f);
	glEnd();

	glPointSize(6);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	for (int i = 180; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(0.0 + 0.3 * cos(theta), -0.22 + 0.3 * sin(theta));
	}
	glEnd();

	glPointSize(3);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	for (int i = 140; i < 220; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(-0.05 + 0.18 * cos(theta), -0.7 + 0.18 * sin(theta));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	for (int i = -40; i < 41; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(0.05 + 0.18 * cos(theta), -0.7 + 0.18 * sin(theta));
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.19f, -0.59f);
	glVertex2f(-0.19f, -0.81f);
	glVertex2f(0.02f, -0.7f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.19f, -0.59f);
	glVertex2f(0.19f, -0.81f);
	glVertex2f(-0.02f, -0.7f);
	glEnd();

	glBegin(GL_POLYGON);
	glShadeModel(GL_SMOOTH);
	glColor3f(divideBy255(255), divideBy255(204), divideBy255(203));
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(-0.5 + 0.1 * cos(theta), -0.15 + 0.1 * sin(theta));
		glColor4f(1.0f, 1.0f, 1.0f, 0.1f);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glShadeModel(GL_SMOOTH);
	glColor3f(divideBy255(255), divideBy255(204), divideBy255(203));
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(0.5 + 0.1 * cos(theta), -0.15 + 0.1 * sin(theta));
		glColor4f(1.0f, 1.0f, 1.0f, 0.1f);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(divideBy255(240), divideBy255(213), divideBy255(168));
	glVertex2f(-0.4f, 0.9f);
	glVertex2f(0.4f, 0.9f);
	glVertex2f(0.8f, 0.4f);
	glVertex2f(-0.8, 0.4f);
	glEnd();
}

void display()
{
	//--------------------------------
	//	OpenGL drawing
	//--------------------------------
	glClear(GL_COLOR_BUFFER_BIT);
	switch (qNo) {
	case 1:
		pahangFlag();
		break;
	case 2:
		n9Flag();
		break;
	case 3:
		englandFlag();
		break;
	case 4:
		scotlandFlag();
		break;
	case 5:
		method2japanFlag();
		break;
	case 6:
		smileFace();
	default:
		break;
	}
	//--------------------------------
	//	End of OpenGL drawing
	//--------------------------------
}
//--------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------