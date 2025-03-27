
#include <Windows.h>
#include <gl/GL.h>
#include <math.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "OpenGL Window"

float tx = 0, ty = 0, tSpeed = 0.1;			//translate x and y with tSpeed
float r = 1.0, g = 1.0, b = 1.0;			//White
float tx1 = 0, ty1 = 0, tSpeed1 = 0.1;		//translate x and y for quad 1
float tx2 = 0, ty2 = 0;						//translate x and y for quad 2
float angle = 0;
float x = 1.0, y = 1.0, z = 1.0;
int count = 0;
int qNo = 1;


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
			tx1 -= tSpeed;
			tx2 += tSpeed;
		}
		else if (wParam == VK_RIGHT) { //press RIGHT arrow key
			tx1 += tSpeed;
			tx2 -= tSpeed;
		}
		else if (wParam == VK_UP) { //press UP arrow key
			ty1 -= tSpeed;
			ty2 += tSpeed;
		}
		else if (wParam == VK_DOWN) { //press DOWN arrow key
			ty1 += tSpeed;
			ty2 -= tSpeed;
		}
		else if (wParam == ' ') {
			tx1 = 0;
			ty1 = 0;
			tx2 = 0;
			ty2 = 0;
		}
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
		}
		else if (wParam == 'A'){
			count--;
		}
		else if (wParam == 'D') {
			count++;
		}
		else if (wParam == 'Q') {
			x -= 1.0;
			y -= 1.0;
			z -= 1.0;
			if (x < 1) {
				x = 1.0;
				y = 1.0;
				z = 1.0;
			}
		}
		else if (wParam == 'E') {
			x += 1.0;
			y += 1.0;
			z += 1.0;
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

	r -= 0.0001;
	g -= 0.0001;

	//glLoadIdentity();
	//glTranslatef(tx, ty, 0.0);
	glRotatef(0.01, 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
	glColor3f(r, g, b); //color
	glVertex2f(-0.5, 0.0);
	glVertex2f(0.0, 0.5);
	glVertex2f(0.5, 0.0);
	glEnd();
}

void drawQuad() {
	glBegin(GL_QUADS);
	glVertex2f(-0.5, 0.0);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, 0.0);
	glEnd();
}

void p3q1() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslatef(tx1, ty1, 0.0);	//translate x and y for quad 1
	glColor3f(1.0, 0.0, 0.0);
	drawQuad();			//quad 1
	glPopMatrix();

	glPushMatrix();
	glTranslatef(tx2, ty2, 0.0);	//translate x and y for quad 2
	glColor3f(1.0, 0.0, 0.0);
	drawQuad();			//quad 2
	glPopMatrix();
	glPopMatrix();
}

float divideBy255(float num) {
	return num / 255;
}

void drawCircle(float x, float xwidth, float y, float ywidth) {
	float theta;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(x + xwidth * cos(theta), y + ywidth * sin(theta));
	}
	glEnd();
}

void drawCirclePoint(float x, float xwidth, float y, float ywidth) {
	float theta;
	glBegin(GL_POINTS);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(x + xwidth * cos(theta), y + ywidth * sin(theta));
	}
	glEnd();
}

void drawLine(float x1, float y1, float x2, float y2) {
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void p3q2() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(divideBy255(135), divideBy255(206), divideBy255(235), 0);

	glColor3f(0.0, 1.0, 0.0);
	drawCircle(-0.3, 2.0, -0.8, 0.6); //draw hill

	glPushMatrix();
	glTranslatef(tx, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0); //draw bird
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.65, 0.7);
	glVertex2f(-0.55, 0.7);
	glVertex2f(-0.60, 0.8);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(-0.45, 0.7);
	glVertex2f(-0.45, 0.6);
	glVertex2f(-0.58, 0.65);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(-0.7, 0.67);
	glVertex2f(-0.75, 0.62);
	glVertex2f(-0.66, 0.6);
	glEnd();

	glColor3f(divideBy255(21), divideBy255(207), divideBy255(207));
	drawCircle(-0.6, 0.1, 0.65, 0.06);
	glColor3f(0.0, 0.0, 0.0);
	drawCirclePoint(-0.6, 0.1, 0.65, 0.06);
	drawCircle(-0.65, 0.015, 0.65, 0.015);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-tx, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);		//two clouds
	drawCircle(-0.3, 0.08, 0.62, 0.08);
	drawCircle(-0.36, 0.08, 0.55, 0.08);
	drawCircle(-0.24, 0.08, 0.55, 0.08);

	drawCircle(0.3, 0.08, 0.62, 0.08);
	drawCircle(0.36, 0.08, 0.55, 0.08);
	drawCircle(0.24, 0.08, 0.55, 0.08);
	glPopMatrix();

	glColor3f(divideBy255(79), divideBy255(33), divideBy255(29)); //mountain 1
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0, -0.3);
	glVertex2f(0.2, 0.2);
	glVertex2f(0.5, -0.3);
	glEnd();

	glColor3f(divideBy255(150), divideBy255(75), 0); //mountain 2
	glBegin(GL_TRIANGLES);
	glVertex2f(0.3, -0.3);
	glVertex2f(0.5, 0.2);
	glVertex2f(0.8, -0.3);
	glEnd();
	
	glColor3f(1.0, 1.0, 1.0);
	drawCircle(0.0, 0.15, 0.8, 0.15);	//sun
	
	glColor3f(divideBy255(245), divideBy255(236), divideBy255(231));
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, 0.0);
	glVertex2f(-0.3, 0.0);
	glVertex2f(-0.2, -0.7);
	glVertex2f(-0.6, -0.7);
	glEnd();

	glColor3f(divideBy255(234), divideBy255(210), divideBy255(162));
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, 0.0);
	glVertex2f(-0.44, 0.15);
	glVertex2f(-0.4, 0.2);
	glVertex2f(-0.36, 0.15);
	glVertex2f(-0.3, 0.0);
	glEnd();

	glColor3f(divideBy255(150), divideBy255(75), 0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.45, -0.5);
	glVertex2f(-0.35, -0.5);
	glVertex2f(-0.35, -0.7);
	glVertex2f(-0.45, -0.7);
	glEnd();

	glColor3f(divideBy255(211), divideBy255(182), divideBy255(131));
	drawCircle(-0.42, 0.015, -0.6, 0.015);
	
	glPushMatrix();
	glTranslatef(-0.4, -0.1, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glScalef(x, y, z);
	glColor3f(divideBy255(234), divideBy255(210), divideBy255(162));
	glLineWidth(5);
	drawLine(0.0, 0.0, -0.5, 0.0);
	drawLine(0.0, 0.0, 0.5, 0.0);
	drawLine(0.0, 0.0, 0.0, 0.5);
	drawLine(0.0, 0.0, 0.0, -0.5);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, 0.0);
	glVertex2f(-0.4, 0.0);
	glVertex2f(-0.4, -0.1);
	glVertex2f(-0.5, -0.1);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(-0.4, 0.0);
	glVertex2f(-0.3, 0.0);
	glVertex2f(-0.3, -0.1);
	glVertex2f(-0.4, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.3, 0.0);
	glVertex2f(-0.2, 0.0);
	glVertex2f(-0.2, -0.1);
	glVertex2f(-0.3, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.2, 0.0);
	glVertex2f(-0.1, 0.0);
	glVertex2f(-0.1, -0.1);
	glVertex2f(-0.2, -0.1);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.4, 0.0);
	glVertex2f(0.4, 0.1);
	glVertex2f(0.5, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.4, 0.0);
	glVertex2f(0.3, 0.0);
	glVertex2f(0.3, 0.1);
	glVertex2f(0.4, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.3, 0.0);
	glVertex2f(0.2, 0.0);
	glVertex2f(0.2, 0.1);
	glVertex2f(0.3, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.2, 0.0);
	glVertex2f(0.1, 0.0);
	glVertex2f(0.1, 0.1);
	glVertex2f(0.2, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.1, 0.5);
	glVertex2f(-0.1, 0.4);
	glVertex2f(0.0, 0.4);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.4);
	glVertex2f(-0.1, 0.4);
	glVertex2f(-0.1, 0.3);
	glVertex2f(0.0, 0.3);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.3);
	glVertex2f(-0.1, 0.3);
	glVertex2f(-0.1, 0.2);
	glVertex2f(0.0, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.2);
	glVertex2f(-0.1, 0.2);
	glVertex2f(-0.1, 0.1);
	glVertex2f(0.0, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.0, -0.5);
	glVertex2f(0.1, -0.5);
	glVertex2f(0.1, -0.4);
	glVertex2f(0.0, -0.4);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.0, -0.4);
	glVertex2f(0.1, -0.4);
	glVertex2f(0.1, -0.3);
	glVertex2f(0.0, -0.3);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.0, -0.3);
	glVertex2f(0.1, -0.3);
	glVertex2f(0.1, -0.2);
	glVertex2f(0.0, -0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.0, -0.2);
	glVertex2f(0.1, -0.2);
	glVertex2f(0.1, -0.1);
	glVertex2f(0.0, -0.1);
	glEnd();

	glColor3f(divideBy255(234), divideBy255(210), divideBy255(162));
	glLineWidth(1);
	drawLine(-0.4, 0.0, -0.4, -0.11);
	drawLine(-0.3, 0.0, -0.3, -0.11);
	drawLine(-0.2, 0.0, -0.2, -0.11);
	drawLine(-0.1, 0.0, -0.1, -0.11);

	drawLine(0.4, 0.0, 0.4, 0.11);
	drawLine(0.3, 0.0, 0.3, 0.11);
	drawLine(0.2, 0.0, 0.2, 0.11);
	drawLine(0.1, 0.0, 0.1, 0.11);

	drawLine(0.0, 0.4, -0.11, 0.4);
	drawLine(0.0, 0.3, -0.11, 0.3);
	drawLine(0.0, 0.2, -0.11, 0.2);
	drawLine(0.0, 0.1, -0.11, 0.1);

	drawLine(0.0, -0.4, 0.11, -0.4);
	drawLine(0.0, -0.3, 0.11, -0.3);
	drawLine(0.0, -0.2, 0.11, -0.2);
	drawLine(0.0, -0.1, 0.11, -0.1);
	/*glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0xADAD);
	glLineWidth(10);
	glColor3f(1.0, 1.0, 1.0);
	drawLine(-0.14, 0.0, -0.5, 0.0);
	drawLine(0.14, 0.0, 0.5, 0.0);
	drawLine(0.0, -0.14, 0.0, -0.5);
	drawLine(0.0, 0.14, 0.0, 0.5);
	glDisable(GL_LINE_STIPPLE);*/
	glPopMatrix();

	for (int i = 0; count <= i; i--) {
		angle += 0.01;
	}
	for (int i = 0; count >= i; i++) {
		angle -= 0.01;
	}

	for (int i = 0; count <= i; i--) {
		tx += 0.0001;
	}

	for (int i = 0; count >= i; i++) {
		tx -= 0.0001;
	}
}

void display()
{
	//--------------------------------
	//	OpenGL drawing
	//--------------------------------

	//glClearColor(0.0, 0.0, 0.0, 0.0);
	//glClear(GL_COLOR_BUFFER_BIT);

	////Block 5 : obj 1, obj 2, obj 3
	//glPushMatrix();
	//glScalef(0.5, 0.5, 0.5);		//Sx(0.5), Sy(0.5) HALF
	////obj 1 : Red triangle
	//glPushMatrix();
	//glTranslatef(0.0, 0.5, 0.0);	//Ty(0.5)
	//glBegin(GL_TRIANGLES);
	//glColor3f(1.0, 0.0, 0.0);
	//	glVertex2f(-0.5f, 0.0f);
	//	glVertex2f(0.0f, 0.5f);
	//	glVertex2f(0.5f, 0.0f);
	//glEnd();
	//glPopMatrix();
	//
	////Block 4 : obj 2 & 3
	//glPushMatrix();
	//glRotatef(90, 0.0, 0.0, 1.0);
	////obj 2 : Green quad
	//glPushMatrix();
	//glTranslatef(-0.5, 0.0, 0.0);
	//glBegin(GL_QUADS);
	//glColor3f(0.0, 1.0, 0.0);
	//	glVertex2f(-0.5, 0.0);
	//	glVertex2f(-0.5, 0.5);
	//	glVertex2f(0.5, 0.5);
	//	glVertex2f(0.5, 0.0);
	//glEnd();
	//glPopMatrix();

	//// obj 3 : Blue quad
	//glPushMatrix();
	//glTranslatef(0.5, 0.0, 0.0);
	//glBegin(GL_QUADS);
	//glColor3f(0.0, 0.0, 1.0);
	//	glVertex2f(-0.5, 0.0);
	//	glVertex2f(-0.5, 0.5);
	//	glVertex2f(0.5, 0.5);
	//	glVertex2f(0.5, 0.0);
	//glEnd();
	//glPopMatrix();
	//glPopMatrix();
	//glPopMatrix();
	switch (qNo) {
	case 1:
		p3q1();
		break;
	case 2:
		p3q2();
		break;
	default:
		demo();
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