
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "OpenGL Window1"

float tx = 0, tz = 0, tSpeed = 1.0;		//tx and tz for modelview with tSpeed
bool isOrtho = true;					//is Ortho view?
float ONear = -10.0;					//Ortho Near
float OFar = 10.0;						//Ortho Far
float PNear = 1.0;						//Perspective near
float PFar = 21.0;						//Perspective far
float ptx = 0, pty = 0, ptSpeed = 0.1;	//tx and ty for projection with ptspeed
float pRy = 0, pRSpeed = 1.0;			//Ry for projection with pRSpeed

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		else if (wParam == VK_UP)		//press UP arrow key
			if (isOrtho) {
				if (tz > ONear) {			//bondary for ortho near
					tz -= tSpeed;
				}
			}
			else {
				if (tz > PNear) {		//bondary for perspective near
					tz -= tSpeed;
				}
			}
		else if (wParam == VK_DOWN) {	//press DOWN arrow key
			if (isOrtho) {
				if (tz < OFar) {			//bondary for ortho far
					tz += tSpeed;
				}
			}
			else {
				if (tz < PFar/2) {
					tz += tSpeed;		//bondary for perspective far
				}
			}
		}
		else if (wParam == VK_LEFT) {
			tx -= tSpeed;
		}
		else if (wParam == VK_RIGHT) {
			tx += tSpeed;
		}
		else if (wParam == 'O') {		//press 'O' key
			isOrtho = true;
			tz = 0;
		}
		else if (wParam == 'P') {		//press 'P' key
			isOrtho = false;
			tz = PNear;
		}
		else if (wParam == 'A') {
			ptx -= ptSpeed;
		}
		else if (wParam == 'D') {
			ptx += ptSpeed;
		}
		else if (wParam == 'L') {		//press 'L' key to Ry anticlockwise projection
			pRy += pRSpeed;
		}
		else if (wParam == 'R') {		// press 'R' key to Ry clockwise projection
			pRy -= pRSpeed;
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
//--------------------------------------------------------------------

void drawCube(float size) {
	glBegin(GL_QUADS);
	// Face 1
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, size);
	glVertex3f(size, 0.0f, size);
	glVertex3f(size, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	// Face 2 : Left
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, size, 0.0f);
	glVertex3f(0.0f, size, size);
	glVertex3f(0.0f, 0.0f, size);
	// Face 3 : Front according to Z axis
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, size);
	glVertex3f(0.0f, size, size);
	glVertex3f(size, size, size);
	glVertex3f(size, 0.0f, size);
	// Face 4 : Right
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(size, 0.0f, size);
	glVertex3f(size, size, size);
	glVertex3f(size, size, 0.0f);
	glVertex3f(size, 0.0f, 0.0f);
	// Face 5 : Back
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(size, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, size, 0.0f);
	glVertex3f(size, size, 0.0f);
	// Face 6 : Top
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(size, size, 0.0f);
	glVertex3f(0.0f, size, 0.0f);
	glVertex3f(0.0f, size, size);
	glVertex3f(size, size, size);
	glEnd();
}

void drawCube1(float size) {
	glBegin(GL_LINE_STRIP);
	// Face 1
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, size / 2);
	glVertex3f(size, 0.0f, size / 2);
	glVertex3f(size, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	// Face 2 : Left
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, size / 2, 0.0f);
	glVertex3f(0.0f, size / 2, size / 2);
	glVertex3f(0.0f, 0.0f, size / 2);
	// Face 3 : Front according to Z axis
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, size / 2);
	glVertex3f(0.0f, size / 2, size / 2);
	glVertex3f(size, size / 2, size / 2);
	glVertex3f(size, 0.0f, size / 2);
	// Face 4 : Right
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(size, 0.0f, size / 2);
	glVertex3f(size, size / 2, size / 2);
	glVertex3f(size, size / 2, 0.0f);
	glVertex3f(size, 0.0f, 0.0f);
	// Face 5 : Back
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(size, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, size / 2, 0.0f);
	glVertex3f(size, size / 2, 0.0f);
	// Face 6 : Top
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(size, size / 2, 0.0f);
	glVertex3f(0.0f, size / 2, 0.0f);
	glVertex3f(0.0f, size / 2, size / 2);
	glVertex3f(size, size / 2, size / 2);
	glEnd();
}

void drawCube2(float size) {
	glBegin(GL_LINE_STRIP);
	// Face 1
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.0f, 0.0f, size / 2);
	glVertex3f(-size, 0.0f, size / 2);
	glVertex3f(-size, 0.0f, 0.0f);
	glVertex3f(-0.0f, 0.0f, 0.0f);
	// Face 2 : Left
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.0f, 0.0f, 0.0f);
	glVertex3f(-0.0f, size / 2, 0.0f);
	glVertex3f(-0.0f, size / 2, size / 2);
	glVertex3f(-0.0f, 0.0f, size / 2);
	// Face 3 : Front according to Z axis
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.0f, 0.0f, size / 2);
	glVertex3f(-0.0f, size / 2, size / 2);
	glVertex3f(-size, size / 2, size / 2);
	glVertex3f(-size, 0.0f, size / 2);
	// Face 4 : Right
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-size, 0.0f, size / 2);
	glVertex3f(-size, size / 2, size / 2);
	glVertex3f(-size, size / 2, 0.0f);
	glVertex3f(-size, 0.0f, 0.0f);
	// Face 5 : Back
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-size, 0.0f, 0.0f);
	glVertex3f(-0.0f, 0.0f, 0.0f);
	glVertex3f(-0.0f, size / 2, 0.0f);
	glVertex3f(-size, size / 2, 0.0f);
	// Face 6 : Top
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-size, size / 2, 0.0f);
	glVertex3f(-0.0f, size / 2, 0.0f);
	glVertex3f(-0.0f, size / 2, size / 2);
	glVertex3f(-size, size / 2, size / 2);
	glEnd();
}

void drawPyramid(float size) {
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
	// Face 1
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, size);
	glVertex3f(size, 0.0f, size);
	glVertex3f(size, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(size / 2, size, size / 2);
	glVertex3f(0.0f, 0.0f, size);
	glVertex3f(size / 2, size, size / 2);
	glVertex3f(size, 0.0f, size);
	glVertex3f(size / 2, size, size / 2);
	glVertex3f(size, 0.0f, 0.0f);
	glVertex3f(size / 2, size, size / 2);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();
}

void drawSphere(double radius) {
	GLUquadricObj* sphere = NULL;		//create quadric obj pointer
	sphere = gluNewQuadric();			//create quadric obj in the memory
	gluQuadricDrawStyle(sphere, GLU_LINE);	//set to use line
	gluSphere(sphere, radius, 30, 30);
	gluDeleteQuadric(sphere);			//make sure only one object being created, memory not incrementing
}

void drawSphere1(double radius) {
	GLUquadricObj* sphere = NULL;		//create quadric obj pointer
	sphere = gluNewQuadric();			//create quadric obj in the memory
	gluQuadricDrawStyle(sphere, GLU_FILL);	//set to use line
	gluSphere(sphere, radius, 30, 30);
	gluDeleteQuadric(sphere);			//make sure only one object being created, memory not incrementing
}

void drawCylinder(double tr, double br, double h) {
	GLUquadricObj* cylinder = NULL;		//create quadric obj pointer
	cylinder = gluNewQuadric();			//create quadric obj in the memory
	gluQuadricDrawStyle(cylinder, GLU_LINE);	//set to use line
	gluCylinder(cylinder, tr, br, h, 30, 30);
	gluDeleteQuadric(cylinder);			//make sure only one object being created, memory not incrementing
}

void drawCylinder1(double tr, double br, double h) {
	GLUquadricObj* cylinder = NULL;		//create quadric obj pointer
	cylinder = gluNewQuadric();			//create quadric obj in the memory
	gluQuadricDrawStyle(cylinder, GLU_FILL);	//set to use line
	gluCylinder(cylinder, tr, br, h, 30, 30);
	gluDeleteQuadric(cylinder);			//make sure only one object being created, memory not incrementing
}

void drawCone(double br, double h) {
	GLUquadricObj* cone = NULL;
	cone = gluNewQuadric();
	gluQuadricDrawStyle(cone, GLU_LINE);
	gluCylinder(cone, 0, br, h, 30, 30);
	gluDeleteQuadric(cone);
}

void drawCone2(double br, double h) {
	GLUquadricObj* cone = NULL;
	cone = gluNewQuadric();
	gluQuadricDrawStyle(cone, GLU_LINE);
	gluCylinder(cone, 0, br, h, 10, 10);
	gluDeleteQuadric(cone);
}

void drawCone3(double br, double h) {
	GLUquadricObj* cone = NULL;
	cone = gluNewQuadric();
	gluQuadricDrawStyle(cone, GLU_FILL);
	gluCylinder(cone, 0, br, h, 10, 10);
	gluDeleteQuadric(cone);
}

void drawDisk(double inr, double outr) {
	GLUquadricObj* disk = NULL;		//create quadric obj pointer
	disk = gluNewQuadric();			//create quadric obj in the memory
	gluQuadricDrawStyle(disk, GLU_LINE);	//set to use line
	gluDisk(disk, inr, outr, 30, 30);
	gluDeleteQuadric(disk);			//make sure only one object being created, memory not incrementing
}

void drawHalfSphereWithoutGLU()
{
	const float PI = 3.141592f;
	GLfloat x, y, z, sliceA, stackA;
	GLfloat radius = 0.5;
	int sliceNo = 30, stackNo = 30;

	for (sliceA = 0.0; sliceA < PI; sliceA += PI / sliceNo)
	{
		glBegin(GL_LINE_STRIP);
		for (stackA = 0.0; stackA < PI; stackA += PI / stackNo)
		{
			x = radius * cos(stackA) * sin(sliceA);
			y = radius * sin(stackA) * sin(sliceA);
			z = radius * cos(sliceA);
			glVertex3f(x, y, z);
			x = radius * cos(stackA) * sin(sliceA + PI / stackNo);
			y = radius * sin(stackA) * sin(sliceA + PI / sliceNo);
			z = radius * cos(sliceA + PI / sliceNo);
			glVertex3f(x, y, z);
		}
		glEnd();
	}
}

void drawSphereWithoutGLU()
{
	const float PI = 3.141592f;
	GLfloat x, y, z, sliceA, stackA;
	GLfloat radius = 0.5;
	int sliceNo = 30, stackNo = 30;

	for (sliceA = 0.0; sliceA < 2 * PI; sliceA += PI / sliceNo)
	{
		glBegin(GL_LINE_STRIP);
		for (stackA = 0.0; stackA < 2 * PI; stackA += PI / stackNo)
		{
			x = radius * cos(stackA) * sin(sliceA);
			y = radius * sin(stackA) * sin(sliceA);
			z = radius * cos(sliceA);
			glVertex3f(x, y, z);
			x = radius * cos(stackA) * sin(sliceA + PI / stackNo);
			y = radius * sin(stackA) * sin(sliceA + PI / sliceNo);
			z = radius * cos(sliceA + PI / sliceNo);
			glVertex3f(x, y, z);
		}
		glEnd();
	}
}

float divideBy255(float num) {
	return num / 255;
}

void projection() {
	glMatrixMode(GL_PROJECTION);					//refer to the projection matrix
	glLoadIdentity();								//reset the projection matrix

	glTranslatef(ptx, pty, 0.0);					//translate x and y for projection
	glRotatef(pRy, 0.0, 1.0, 0.0);					//rotate y for projection
	if (isOrtho) {
		//Ortho view
		glOrtho(-10.0, 10.0, -10.0, 10.0, ONear, OFar);
	}
	else {
		//Perspective view
		gluPerspective(20, 1.0, -1.0, 1.0);
		glFrustum(-10.0, 10.0, -10.0, 10.0, PNear, PFar); // x and y can use but z cannot because it is placing behind the camera
	}
}

void display()
{
	//--------------------------------
	//	OpenGL drawing
	//--------------------------------
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	projection();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(tx, 0.0, tz);
	drawSphere(1.0);

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