
#include <Windows.h>
#include <gl/GL.h>
#include <iostream>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "OpenGL Window"

float tx = 0, ty = 0, tSpeed = 0.1; //translate x and y with tSpeed
float r = 1.0, g = 1.0, b = 1.0;	//White
float sx = 1.0, sy = 1.0;
int qNo = 1;

bool increasing = true;
bool scale = true;
float rColor = 0.0f;

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		else if (wParam == VK_LEFT) { //press LEFT arrow key
			tx -= tSpeed;
		}
		else if (wParam == VK_RIGHT) { //press RIGHT arrow key
			tx += tSpeed;
		}
		else if (wParam == VK_UP) {
			ty += tSpeed;
		}
		else if (wParam == VK_DOWN) {
			ty -= tSpeed;
		}
		else if (wParam == 'R') {	//press 'R' key
			r = 1.0;
			g = 0.0;
			b = 0.0;
		}
		else if (wParam == 'G') {	//press 'G' key
			r = 0.0;
			g = 1.0;
			b = 0.0;
		}
		else if (wParam == 'B') {	//press 'B' key
			r = 0.0;
			g = 0.0;
			b = 1.0;
		}
		else if (wParam == ' ') {	
			r = 1.0;
			g = 1.0;
			b = 1.0;
			tx = 0;
			ty = 0;
		}
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

void demo() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();						//reset the transformation matrix
	glPushMatrix();
	glTranslatef(-0.5f, 0.5f, 0.0f);		//Tx(-0.5) Left, Ty(0.5) Up
	glRotatef(90, 0.0f, 0.0f, 1.0f);		//Rz(90), anti-clockwise
	glScalef(0.5f, 0.5f, 0.5f);				//Sx(0.5), Sy(0.5) Half

	glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, 0.0f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
		glVertex2f(-0.5, 0.0);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, 0.0);
	glEnd();
	glPopMatrix();
}

void p2q1() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	//r -= 0.0001;
	//g -= 0.0001;

	glLoadIdentity();
	glTranslatef(tx, ty, 0.0);
	//glRotatef(0.01, 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
	glColor3f(r, g, b); //color
		glVertex2f(-0.5, 0.0);
		glVertex2f(0.0, 0.5);
		glVertex2f(0.5, 0.0);
	glEnd();
}

void p2q2() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
		
	if (increasing) {
		rColor += 0.0001;

		if (rColor >= 1.0f) {
			increasing = false;
		}
	}
	else {
		rColor -= 0.0001;

		if (rColor <= 0.0f) {
			increasing = true;
		}
	}

	glRotatef(0.01, 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
	glColor3f(rColor, g, 1.0f);
	glVertex2f(0.0f, 0.3f);
	glVertex2f(-0.1f, 0.0f);
	glVertex2f(0.1f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(rColor, g, 1.0f);
	glVertex2f(-0.1f, 0.0f);
	glVertex2f(-0.4f, 0.0f);
	glVertex2f(-0.2f, -0.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(rColor, g, 1.0f);
	glVertex2f(0.1f, 0.0f);
	glVertex2f(0.4f, 0.0f);
	glVertex2f(0.2f, -0.2f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(rColor, g, 1.0f);
	glVertex2f(-0.1f, 0.0f);
	glVertex2f(-0.2f, -0.2f);
	glVertex2f(0.0f, -0.4f);
	glVertex2f(0.1f, 0.0f);
	glVertex2f(0.2f, -0.2f);
	glVertex2f(0.0f, -0.4f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(rColor, g, 1.0f);
	glVertex2f(-0.3f, -0.7f);
	glVertex2f(-0.2f, -0.2f);
	glVertex2f(0.0f, -0.4f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(rColor, g, 1.0f);
	glVertex2f(0.3f, -0.7f);
	glVertex2f(0.2f, -0.2f);
	glVertex2f(0.0f, -0.4f);
	glEnd();
}

void p2q3() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5);
	glRotatef(0.05, 0.0, 0.0, 1.0);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.1f, -0.5f);
	glEnd();
}

void p2q4() {
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	if (scale) {
		sx += 0.0001;
		if (sx >= 1.0f) {
			scale = false;
		}
	}
	else {
		sx -= 0.0001;
		if (sx <= 0.1f) {
			scale = true;
		}
	}
	glPushMatrix();
	glScalef(sx, sx, sx);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.2, 0.2);
		glVertex2f(0.2, 0.2);
		glVertex2f(0.2, -0.2);
		glVertex2f(-0.2, -0.2);
	glEnd();
	glPopMatrix();
}

void display()
{
	//--------------------------------
	//	OpenGL drawing
	//--------------------------------
	switch (qNo) {
	case 1:
		p2q1();
		break;
	case 2:
		p2q2();
		break;
	case 3:
		p2q3();
		break;
	case 4:
		p2q4();
		break;
	case 5:
		demo();
		break;
	default:
		p2q1();
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
		900, 10, 300, 300,
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