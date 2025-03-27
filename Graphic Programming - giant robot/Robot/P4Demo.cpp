
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "OpenGL Window1"

float x = 0;
float y = 0;
float z = 0;
float angle = 0;
float angle1 = 0;
float rx = 0, ry = 0, rz = 0;
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
		else if (wParam == 'X') {
			x = 1.0;
			y = 0.0;
			z = 0.0;
		}
		else if (wParam == 'Y') {
			x = 0.0;
			y = 1.0;
			z = 0.0;
		}
		else if (wParam == 'Z') {
			x = 0.0;
			y = 0.0;
			z = 1.0;
		}
		else if (wParam == VK_UP) {
			angle += 0.5;
			if (angle >= 90) {
				angle = 90;
			}
		}
		else if (wParam == VK_DOWN) {
			angle -= 0.5;
			if (angle <= 0) {
				angle = 0;
			}
		}
		else if (wParam == VK_LEFT) {
			angle1 += 0.5;
			rx = 1.0;
			ry = 0.0;
			rz = 0.0;
		}
		else if (wParam == VK_RIGHT) {
			angle1 -= 0.5;
			rx = 1.0;
			ry = 0.0;
			rz = 0.0;
		}
		else if (wParam == ' ') {
			angle = 0.0;
			angle1 = 0.0;
			rx = 0.0;
			ry = 0.0;
			rz = 0.0;
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
	glVertex3f(0.0f, 0.0f, size/2);
	glVertex3f(size, 0.0f, size/2);
	glVertex3f(size, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	// Face 2 : Left
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, size / 2, 0.0f);
	glVertex3f(0.0f, size / 2, size/2);
	glVertex3f(0.0f, 0.0f, size/2);
	// Face 3 : Front according to Z axis
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, size/2);
	glVertex3f(0.0f, size / 2, size/2);
	glVertex3f(size, size / 2, size/2);
	glVertex3f(size, 0.0f, size/2);
	// Face 4 : Right
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(size, 0.0f, size/2);
	glVertex3f(size, size / 2, size/2);
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
	glVertex3f(0.0f, size / 2, size/2);
	glVertex3f(size, size / 2, size/2);
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
	glVertex3f(-0.0f, size/2, 0.0f);
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
	glBegin(GL_POLYGON);
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
	gluCylinder(cylinder, tr,br,h, 30, 30);
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

void drawRobotArm() {
	glLoadIdentity();
	glPushMatrix();
	glRotatef(angle1, rx, ry, rz);
	glPushMatrix();
	glRotatef(angle, 0.0, 0.0, 1.0);
	drawCube1(1.0);
	glPopMatrix();
	drawCube2(1.0);
	glPopMatrix();
	
}

float divideBy255(float num) {
	return num / 255;
}

void drawIceCream() {
	glColor3f(divideBy255(150), divideBy255(75), 0);
	glPushMatrix();
	glTranslatef(0.0, -0.8, 0.0);
	glPushMatrix();
	glRotatef(260.0, 1.0, 0.0, 0.0);
	drawCone3(0.3, 1.0);
	glColor3f(divideBy255(229), divideBy255(206), divideBy255(189));
	drawCone2(0.3, 1.0);
	glPopMatrix();
	glPopMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(0.0, 0.2, -0.16);
	drawSphere1(0.26);
	glPopMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslatef(0.0, 0.4, -0.23);
	drawSphere1(0.26);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.18, 0.58, -0.3);
	drawSphere1(0.05);
	glPopMatrix();
	glColor3f(divideBy255(92), divideBy255(64), divideBy255(51));
	glPushMatrix();
	glTranslatef(0.2, 0.9, -0.15);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glRotatef(20.0, 0.0, -1.0, 0.0);
	drawCylinder1(0.025, 0.025, 0.5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.1, 0.65, -0.12);
	drawDisk(0.1, 0.1);
	glPopMatrix();
	glRotatef(0.025, 0.0, 1.0, 0.0);
}

void demo() {
	glRotatef(0.01, x, y, z);
	drawPyramid(0.5);
	/*drawCube(0.5);
	glPushMatrix();
	glRotatef(0.5, 1.0, 1.0, 1.0);
	glPushMatrix();
	glRotatef(0.5, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	drawCylinder(0.2, 0.2, 0.8);
	glColor3f(0.0, 1.0, 0.0);
	drawDisk(0.0, 0.2);
	drawSphere(0.5);
	glPopMatrix();
	glPopMatrix();
	drawSphereWithoutGLU();*/
}

void display()
{
	//--------------------------------
	//	OpenGL drawing
	//--------------------------------
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	switch (qNo) {
	case 1:
		demo();
		break;
	case 2:
		drawRobotArm();
		break;
	case 3:
		drawIceCream();
		break;
	default:
		demo();
		break;
	}
	
	//drawIceCream();
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