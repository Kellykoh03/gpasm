
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "P6 Demo"

float ambL[3] = { 1.0, 1.0, 1.0 };		//white color amb light
float posA[3] = { 0.0, 0.8, 0.0 };		//amb light pos at (0,0.8,0)
float difL[3] = { 1.0, 1.0, 1.0 };		//white color dif light
float posD[3] = { 0.8, 0.0, 0.0 };		//dif light pos at (0.8,0,0)
float ambM[3] = { 0.0, 0.0, 1.0 };		//red color amb material
float difM[3] = { 0.0, 0.0, 1.0 };		//red color dif material
bool isLightOn = true;					//is Light on?

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		else if (wParam == VK_SPACE) {
			isLightOn = !isLightOn;					//press Space to on off light
		}
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

void lighting() {

	if (isLightOn) {
		glEnable(GL_LIGHTING);
	}
	else {
		glDisable(GL_LIGHTING);
	}

	//Light 0 : red color amb light at pos (0,0.8,0) above sphere
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambL);
	glLightfv(GL_LIGHT0, GL_POSITION, posA);
	glEnable(GL_LIGHT0);

	//Light 1 : green color amb light at pos (0,0.8,0) above sphere
	glLightfv(GL_LIGHT1, GL_DIFFUSE, difL);
	glLightfv(GL_LIGHT1, GL_POSITION, posD);
	glEnable(GL_LIGHT1);
}

void drawSphere(double radius) {
	GLUquadricObj* sphere = NULL;		//create quadric obj pointer
	sphere = gluNewQuadric();			//create quadric obj in the memory
	gluQuadricDrawStyle(sphere, GLU_FILL);	//set to use line
	gluSphere(sphere, radius, 30, 30);
	gluDeleteQuadric(sphere);			//make sure only one object being created, memory not incrementing
}
//--------------------------------------------------------------------

void display()
{
	//--------------------------------
	//	OpenGL drawing
	//--------------------------------
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	
	lighting();

	glRotatef(0.05, 1.0, 1.0, 1.0);
	//Blue Sphere
	glColor3f(0.0, 0.0, 1.0);						//no longer works when light comes in
	//glMaterialfv(GL_FRONT, GL_AMBIENT, ambM);		//red color amb material
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difM);		//red color amb material
	drawSphere(0.5);
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
		CW_USEDEFAULT, CW_USEDEFAULT, 600, 600,
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