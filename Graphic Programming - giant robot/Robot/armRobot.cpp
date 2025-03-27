#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "OpenGL Window"

int qNo = 1;
float Rx = 0, Ry = 0, Rz = 0;
float r3 = 0.03, Rx3 = 0, Ry3 = 0, Rz3 = 0;
float r1 = 0, r2 = 0;
float handAngle = 0.0, handAngle1 = 180;
float fingerRotationAngle = 0.0;
LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			PostQuitMessage(0);
		else if (wParam == 0x31) {
			qNo = 1;
		}

		else if (wParam == 0x32) {
			qNo = 2;
		}

		else if (wParam == 0x33) {
			qNo = 3;
		}

		if (qNo == 1) {
			if (wParam == VK_LEFT)		//press left arrow key
				r1 += 1;
			else if (wParam == VK_RIGHT)	//press right arrow key
				r1 -= 1;
			else if (wParam == VK_UP)	// press up arrow key
				r2 += 1;

			else if (wParam == VK_DOWN)	// press down arrow key
				r2 -= 1;
			else if (wParam == VK_SPACE) {	//press Space key
				r1 = 0.0;	//reset to center
				r2 = 0.0;
			}
			else if (wParam == 'Q')
				if (fingerRotationAngle < 2.0)
					fingerRotationAngle += 1.0;
		}

		if (qNo == 2) {
			r3 = 0.03; Rx = 0; Ry3 = 1.0; Rz = 0;
		}

		if (qNo == 3) {
			if (wParam == 'X')
				Rx = 1.0, Ry = 0.0, Rz = 0.0;
			else if (wParam == 'Y')
				Rx = 0.0, Ry = 1.0, Rz = 0.0;
			else if (wParam == 'Z')
				Rx = 0.0, Ry = 0.0, Rz = 1.0;
			else if (wParam == VK_SPACE)
				Rx = 0.0, Ry = 0.0, Rz = 0.0;
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

void drawQuad() {
	glBegin(GL_QUADS);
	glVertex2f(-0.5, 0.0);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, 0.0);
	glEnd();
}

void pyramid(float size) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glRotatef(0.05, Rx, Ry, Rz);


	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
	// Face 1 
	glColor3f(1.0, 0.0, 0.0);
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

void drawPyramid() {
	pyramid(0.5);
}

void drawCone(double br, double h) {
	GLUquadricObj* cone = NULL;			//create quadric obj pointer
	cone = gluNewQuadric();				//create quadric obj in the memory
	gluQuadricDrawStyle(cone, GLU_LINE);	//set to use line
	gluCylinder(cone, 0, br, h, 30, 30);
	gluDeleteQuadric(cone);
}

void drawDisk(double inr, double outr) {
	GLUquadricObj* disk = NULL;			//create quadric obj pointer
	disk = gluNewQuadric();				//create quadric obj in the memory
	gluQuadricDrawStyle(disk, GLU_LINE);	//set to use line
	gluDisk(disk, inr, outr, 30, 30);
	gluDeleteQuadric(disk);
}

void drawSphere(double radius) {
	//glColor3f(1.0, 0.0, 0.0);
	GLUquadricObj* sphere = NULL;			//create quadric obj pointer
	sphere = gluNewQuadric();				//create quadric obj in the memory
	gluQuadricDrawStyle(sphere, GLU_FILL);	//set to use line //GLU_FILL
	gluSphere(sphere, radius, 30, 30);
	gluDeleteQuadric(sphere);
}

void drawCylinderHand(GLenum obj, double tr, double br, double h, double n, double x, double y, double z) {
	GLUquadricObj* cylinder = gluNewQuadric(); // create quadric obj pointer
	gluQuadricDrawStyle(cylinder, obj);        // set to use line
	glPushMatrix(); // Save current transformation matrix
	glTranslatef(x, y, z); // Translate the cylinder to the desired position
	gluCylinder(cylinder, tr, br, h, n, 1);
	glPopMatrix(); // Restore previous transformation matrix
	gluDeleteQuadric(cylinder);
}

void drawSphereWithoutGLU()
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

void drawCube(float size) {
	glBegin(GL_QUADS);
	// Face 1 
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0f, 0.0f, size);
	glVertex3f(size, 0.0f, size);
	glVertex3f(size, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	// Face 2 
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, size, 0.0f);
	glVertex3f(0.0f, size, size);
	glVertex3f(0.0f, 0.0f, size);
	// Face 3
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0f, 0.0f, size);
	glVertex3f(0.0f, size, size);
	glVertex3f(size, size, size);
	glVertex3f(size, 0.0f, size);
	// Face 4
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(size, 0.0f, size);
	glVertex3f(size, size, size);
	glVertex3f(size, size, 0.0f);
	glVertex3f(size, 0.0f, 0.0f);
	// Face 5
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(size, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, size, 0.0f);
	glVertex3f(size, size, 0.0f);
	// Face 6
	glColor3f(0.0, 1.0, 1.0);
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

void drawArm(float x, float y, float z) {
	glBegin(GL_QUADS);
	// Face 1
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, z);
	glVertex3f(x, 0.0, z);
	glVertex3f(x, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	// Face 2
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, z);
	glVertex3f(x, 0.0, z);
	glVertex3f(x, y, z);
	glVertex3f(0.0, y, z);
	//Face 3
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, y, z);
	glVertex3f(0.0, y, 0.0);
	glVertex3f(x, y, 0.0);
	glVertex3f(x, y, z);
	//Face 4
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(x, y, z);
	glVertex3f(x, 0.0, z);
	glVertex3f(x, 0.0, 0.0);
	glVertex3f(x, y, 0.0);
	//Face 5
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(x, y, 0.0);
	glVertex3f(0.0, y, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(x, 0.0, 0.0);
	// Face 6
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, y, 0.0);
	glVertex3f(0.0, y, z);
	glVertex3f(0.0, 0.0, z);
	glEnd();


}

void drawShoulderArm() {

	//glPushMatrix();
	//glRotatef(180.0, 0.0, 0.0, 1.0); // Rotate the entire arm assembly by 180 degrees around the Z-axis
	//glTranslatef(0.0, -0.6, 0.0); // Translate down along y-axis
	//glRotatef(r2, 1.0, 0.0, 0.0); // Rotate about x-axis

	//

	//glPushMatrix();
	//glTranslatef(0.0, 0.6, 0.0); // Translate up along y-axis
	//glRotatef(r1, 0.0, 0.0, 1.0); // Rotate about z-axis
	//drawArm(0.2, 0.6, 0.1); // Top arm

	//glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	//face 1
	glVertex3f(-0.12, 0.58, 0.2);
	glVertex3f(0.1, 0.7, 0.2);
	glVertex3f(0.16, 0.6, 0.2);
	glVertex3f(-0.12, 0.28, 0.2);

	//face 2
	glVertex3f(-0.12, 0.58, -0.1);
	glVertex3f(-0.12, 0.58, 0.2);
	glVertex3f(-0.12, 0.28, 0.2);
	glVertex3f(-0.12, 0.28, -0.1);

	//face 3 
	glVertex3f(0.1, 0.7, -0.1);
	glVertex3f(0.1, 0.7, 0.2);
	glVertex3f(-0.11, 0.61, 0.2);
	glVertex3f(-0.12, 0.58, -0.1);

	//face 4
	glVertex3f(0.16, 0.6, -0.1);
	glVertex3f(0.16, 0.6, 0.2);
	glVertex3f(0.1, 0.7, 0.2);
	glVertex3f(0.1, 0.7, -0.1);

	//face 5 
	glVertex3f(-0.12, 0.28, -0.1);
	glVertex3f(-0.12, 0.28, 0.2);
	glVertex3f(0.16, 0.6, 0.2);
	glVertex3f(0.16, 0.6, -0.1);

	//face 6 
	glVertex3f(-0.12, 0.58, -0.1);
	glVertex3f(-0.12, 0.28, -0.1);
	glVertex3f(0.16, 0.6, -0.1);
	glVertex3f(0.1, 0.7, -0.1);

	glEnd();

	drawArm(0.2, 0.6, 0.1); // Bottom arm
	drawArm(0.2, -0.6, 0.1);

	glBegin(GL_POLYGON);
	//face 1
	glVertex3f(-0.05, 0.35, -0.1);
	glVertex3f(0.01, 0.43, -0.1);
	glVertex3f(0.04, 0.41, -0.1);
	glVertex3f(0.0, 0.25, -0.1);
	glVertex3f(0.0, 0.32, -0.1);

	//face 2
	glVertex3f(-0.06, 0.36, 0.2);
	glVertex3f(0.01, 0.43, 0.2);
	glVertex3f(0.01, 0.43, -0.1);
	glVertex3f(-0.05, 0.35, -0.1);

	//face 3
	glVertex3f(0.01, 0.43, 0.2);
	glVertex3f(0.04, 0.41, 0.2);
	glVertex3f(0.04, 0.41, -0.1);
	glVertex3f(0.01, 0.43, -0.1);

	//face 4
	glVertex3f(0.0, 0.25, 0.2);
	glVertex3f(0.04, 0.41, 0.2);
	glVertex3f(0.04, 0.41, -0.1);
	glVertex3f(0.0, 0.25, -0.1);

	//face 5
	glVertex3f(0.0, 0.32, 0.2);
	glVertex3f(0.0, 0.25, 0.2);
	glVertex3f(0.0, 0.25, -0.1);
	glVertex3f(0.0, 0.32, -0.1);

	//face 6
	glVertex3f(-0.06, 0.36, 0.2);
	glVertex3f(0.0, 0.32, 0.2);
	glVertex3f(0.0, 0.32, -0.1);
	glVertex3f(-0.05, 0.35, -0.1);

	//face 7
	glVertex3f(-0.06, 0.36, 0.2);
	glVertex3f(0.01, 0.43, 0.2);
	glVertex3f(0.04, 0.41, 0.2);
	glVertex3f(0.0, 0.25, 0.2);
	glVertex3f(0.0, 0.32, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	//face 1
	glVertex3f(0.01, 0.43, -0.1);
	glVertex3f(0.04, 0.46, -0.1);
	glVertex3f(0.06, 0.43, -0.1);
	glVertex3f(0.06, 0.42, -0.1);
	glVertex3f(0.05, 0.41, -0.1);
	glVertex3f(0.04, 0.41, -0.1);

	//face 2
	glVertex3f(0.01, 0.43, 0.2);
	glVertex3f(0.04, 0.46, 0.2);
	glVertex3f(0.04, 0.46, -0.1);
	glVertex3f(0.01, 0.43, -0.1);

	//face 3
	glVertex3f(0.04, 0.46, 0.2);
	glVertex3f(0.06, 0.43, 0.2);
	glVertex3f(0.06, 0.43, -0.1);
	glVertex3f(0.04, 0.46, -0.1);

	//face 4
	glVertex3f(0.06, 0.42, 0.2);
	glVertex3f(0.06, 0.43, 0.2);
	glVertex3f(0.06, 0.43, -0.1);
	glVertex3f(0.06, 0.42, -0.1);

	//face 5
	glVertex3f(0.05, 0.41, 0.2);
	glVertex3f(0.06, 0.42, 0.2);
	glVertex3f(0.06, 0.42, -0.1);
	glVertex3f(0.05, 0.41, -0.1);

	//face 6
	glVertex3f(0.04, 0.41, 0.2);
	glVertex3f(0.05, 0.41, 0.2);
	glVertex3f(0.05, 0.41, -0.1);
	glVertex3f(0.04, 0.41, -0.1);

	//face 7
	glVertex3f(0.01, 0.43, 0.2);
	glVertex3f(0.04, 0.41, 0.2);
	glVertex3f(0.04, 0.41, -0.1);
	glVertex3f(0.01, 0.43, -0.1);

	//face 8
	glVertex3f(0.01, 0.43, 0.2);
	glVertex3f(0.04, 0.46, 0.2);
	glVertex3f(0.06, 0.43, 0.2);
	glVertex3f(0.06, 0.42, 0.2);
	glVertex3f(0.05, 0.41, 0.2);
	glVertex3f(0.04, 0.41, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	//face 1
	glVertex3f(0.04, 0.46, -0.1);
	glVertex3f(0.11, 0.54, -0.1);
	glVertex3f(0.14, 0.51, -0.1);
	glVertex3f(0.12, 0.48, -0.1);
	glVertex3f(0.09, 0.48, -0.1);
	glVertex3f(0.08, 0.47, -0.1);
	glVertex3f(0.07, 0.45, -0.1);
	glVertex3f(0.06, 0.43, -0.1);

	//face 2
	glVertex3f(0.04, 0.46, 0.2);
	glVertex3f(0.11, 0.54, 0.2);
	glVertex3f(0.11, 0.54, -0.1);
	glVertex3f(0.04, 0.46, -0.1);

	//face 3
	glVertex3f(0.11, 0.54, 0.2);
	glVertex3f(0.14, 0.51, 0.2);
	glVertex3f(0.14, 0.51, -0.1);
	glVertex3f(0.11, 0.54, -0.1);

	//face 4
	glVertex3f(0.12, 0.48, 0.2);
	glVertex3f(0.14, 0.51, 0.2);
	glVertex3f(0.14, 0.51, -0.1);
	glVertex3f(0.12, 0.48, -0.1);

	//face 5
	glVertex3f(0.09, 0.48, 0.2);
	glVertex3f(0.12, 0.48, 0.2);
	glVertex3f(0.12, 0.48, -0.1);
	glVertex3f(0.09, 0.48, -0.1);

	//face 6

	glVertex3f(0.08, 0.47, 0.2);
	glVertex3f(0.09, 0.48, 0.2);
	glVertex3f(0.09, 0.48, -0.1);
	glVertex3f(0.08, 0.47, -0.1);

	//face 7
	glVertex3f(0.07, 0.45, 0.2);
	glVertex3f(0.08, 0.47, 0.2);
	glVertex3f(0.08, 0.47, -0.1);
	glVertex3f(0.07, 0.45, -0.1);

	//face 8
	glVertex3f(0.06, 0.43, 0.2);
	glVertex3f(0.07, 0.45, 0.2);
	glVertex3f(0.07, 0.45, -0.1);
	glVertex3f(0.06, 0.43, -0.1);

	//face 9
	glVertex3f(0.04, 0.46, 0.2);
	glVertex3f(0.06, 0.43, 0.2);
	glVertex3f(0.06, 0.43, -0.1);
	glVertex3f(0.04, 0.46, -0.1);

	//face 10
	glVertex3f(0.04, 0.46, 0.2);
	glVertex3f(0.11, 0.54, 0.2);
	glVertex3f(0.14, 0.51, 0.2);
	glVertex3f(0.12, 0.48, 0.2);
	glVertex3f(0.09, 0.48, 0.2);
	glVertex3f(0.08, 0.47, 0.2);
	glVertex3f(0.07, 0.45, 0.2);
	glVertex3f(0.06, 0.43, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	//face 1
	glVertex3f(0.11, 0.54, -0.1);
	glVertex3f(0.16, 0.6, -0.1);
	glVertex3f(0.24, 0.6, -0.1);
	glVertex3f(0.24, 0.57, -0.1);
	glVertex3f(0.25, 0.53, -0.1);
	glVertex3f(0.25, 0.5, -0.1);
	glVertex3f(0.24, 0.46, -0.1);
	glVertex3f(0.24, 0.43, -0.1);
	glVertex3f(0.2, 0.4, -0.1);
	glVertex3f(0.14, 0.51, -0.1);

	//face 2
	glVertex3f(0.11, 0.54, 0.2);
	glVertex3f(0.16, 0.6, 0.2);
	glVertex3f(0.16, 0.6, -0.1);
	glVertex3f(0.11, 0.54, -0.1);

	//face 3
	glVertex3f(0.16, 0.6, 0.2);
	glVertex3f(0.24, 0.6, 0.2);
	glVertex3f(0.24, 0.6, -0.1);
	glVertex3f(0.16, 0.6, -0.1);

	//face 4
	glVertex3f(0.24, 0.57, 0.2);
	glVertex3f(0.24, 0.6, 0.2);
	glVertex3f(0.24, 0.6, -0.1);
	glVertex3f(0.24, 0.57, -0.1);

	//face 5
	glVertex3f(0.25, 0.53, 0.2);
	glVertex3f(0.24, 0.57, 0.2);
	glVertex3f(0.24, 0.57, -0.1);
	glVertex3f(0.25, 0.53, -0.1);

	//face 6
	glVertex3f(0.25, 0.5, 0.2);
	glVertex3f(0.25, 0.53, 0.2);
	glVertex3f(0.25, 0.53, -0.1);
	glVertex3f(0.25, 0.5, -0.1);

	//face 7
	glVertex3f(0.24, 0.56, 0.2);
	glVertex3f(0.25, 0.5, 0.2);
	glVertex3f(0.25, 0.5, -0.1);
	glVertex3f(0.24, 0.46, -0.1);

	//face 8
	glVertex3f(0.24, 0.43, 0.2);
	glVertex3f(0.24, 0.46, 0.2);
	glVertex3f(0.24, 0.46, -0.1);
	glVertex3f(0.24, 0.43, -0.1);

	//face 9
	glVertex3f(0.2, 0.4, 0.2);
	glVertex3f(0.24, 0.43, 0.2);
	glVertex3f(0.24, 0.43, -0.1);
	glVertex3f(0.2, 0.4, -0.1);

	//face 10
	glVertex3f(0.14, 0.51, 0.2);
	glVertex3f(0.2, 0.4, 0.2);
	glVertex3f(0.2, 0.4, -0.1);
	glVertex3f(0.14, 0.51, -0.1);

	//face 11
	glVertex3f(0.11, 0.54, 0.2);
	glVertex3f(0.14, 0.51, 0.2);
	glVertex3f(0.14, 0.51, -0.1);
	glVertex3f(0.11, 0.54, -0.1);

	//face 12
	glVertex3f(0.11, 0.54, 0.2);
	glVertex3f(0.16, 0.6, 0.2);
	glVertex3f(0.24, 0.6, 0.2);
	glVertex3f(0.24, 0.57, 0.2);
	glVertex3f(0.25, 0.53, 0.2);
	glVertex3f(0.25, 0.5, 0.2);
	glVertex3f(0.24, 0.46, 0.2);
	glVertex3f(0.24, 0.43, 0.2);
	glVertex3f(0.2, 0.4, 0.2);
	glVertex3f(0.14, 0.51, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	//face 1
	glVertex3f(0.16, 0.6, -0.1);
	glVertex3f(0.1, 0.7, -0.1);
	glVertex3f(0.17, 0.68, -0.1);
	glVertex3f(0.21, 0.65, -0.1);
	glVertex3f(0.24, 0.6, -0.1);

	//face 2
	glVertex3f(0.16, 0.6, 0.2);
	glVertex3f(0.1, 0.7, 0.2);
	glVertex3f(0.1, 0.7, -0.1);
	glVertex3f(0.16, 0.6, -0.1);

	//face 3
	glVertex3f(0.17, 0.68, 0.2);
	glVertex3f(0.1, 0.7, 0.2);
	glVertex3f(0.1, 0.7, -0.1);
	glVertex3f(0.17, 0.68, -0.1);

	//face 4
	glVertex3f(0.21, 0.65, 0.2);
	glVertex3f(0.17, 0.68, 0.2);
	glVertex3f(0.17, 0.68, -0.1);
	glVertex3f(0.21, 0.656, -0.1);

	//face 5
	glVertex3f(0.24, 0.6, 0.2);
	glVertex3f(0.21, 0.65, 0.2);
	glVertex3f(0.21, 0.65, -0.1);
	glVertex3f(0.24, 0.6, -0.1);

	//face 6
	glVertex3f(0.24, 0.6, 0.2);
	glVertex3f(0.16, 0.6, 0.2);
	glVertex3f(0.16, 0.6, -0.1);
	glVertex3f(0.24, 0.6, -0.1);

	//face 7
	glVertex3f(0.16, 0.6, 0.2);
	glVertex3f(0.1, 0.7, 0.2);
	glVertex3f(0.17, 0.68, 0.2);
	glVertex3f(0.12, 0.65, 0.2);
	glVertex3f(0.24, 0.6, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	//face 1
	glVertex3f(0.0, 0.25, -0.1);
	glVertex3f(-0.03, 0.2, -0.1);
	glVertex3f(-0.01, 0.2, -0.1);
	glVertex3f(-0.02, 0.17, -0.1);
	glVertex3f(-0.02, 0.15, -0.1);
	glVertex3f(-0.02, 0.12, -0.1);
	glVertex3f(-0.02, 0.09, -0.1);
	glVertex3f(-0.01, 0.07, -0.1);
	glVertex3f(-0.01, 0.05, -0.1);
	glVertex3f(0.08, 0.03, -0.1);
	glVertex3f(0.1, 0.04, -0.1);
	glVertex3f(0.12, 0.06, -0.1);
	glVertex3f(0.14, 0.09, -0.1);
	glVertex3f(0.15, 0.11, -0.1);
	glVertex3f(0.15, 0.15, -0.1);
	glVertex3f(0.16, 0.18, -0.1);
	glVertex3f(0.16, 0.23, -0.1);
	glVertex3f(0.17, 0.26, -0.1);
	glVertex3f(0.17, 0.31, -0.1);
	glVertex3f(0.17, 0.36, -0.1);
	glVertex3f(0.16, 0.39, -0.1);
	glVertex3f(0.13, 0.41, -0.1);

	//face 2
	glVertex3f(0.0, 0.25, 0.2);
	glVertex3f(-0.03, 0.2, 0.2);
	glVertex3f(-0.03, 0.2, -0.1);
	glVertex3f(0.0, 0.25, -0.1);

	//face 3
	glVertex3f(-0.03, 0.2, 0.2);
	glVertex3f(-0.01, 0.2, 0.2);
	glVertex3f(-0.01, 0.2, -0.1);
	glVertex3f(-0.03, 0.2, -0.1);

	//face 4
	glVertex3f(-0.01, 0.2, 0.2);
	glVertex3f(-0.02, 0.17, 0.2);
	glVertex3f(-0.02, 0.17, -0.1);
	glVertex3f(-0.01, 0.2, -0.1);

	//face 5
	glVertex3f(-0.02, 0.17, 0.2);
	glVertex3f(-0.02, 0.15, 0.2);
	glVertex3f(-0.02, 0.15, -0.1);
	glVertex3f(-0.02, 0.17, -0.1);

	//face 6
	glVertex3f(-0.02, 0.15, 0.2);
	glVertex3f(-0.02, 0.12, 0.2);
	glVertex3f(-0.02, 0.12, -0.1);
	glVertex3f(-0.02, 0.15, -0.1);

	//face 7
	glVertex3f(-0.02, 0.12, 0.2);
	glVertex3f(-0.02, 0.09, 0.2);
	glVertex3f(-0.02, 0.09, -0.1);
	glVertex3f(-0.02, 0.12, -0.1);

	//face 8
	glVertex3f(-0.02, 0.09, 0.2);
	glVertex3f(-0.01, 0.07, 0.2);
	glVertex3f(-0.01, 0.07, -0.1);
	glVertex3f(-0.02, 0.09, -0.1);

	//face 9
	glVertex3f(-0.01, 0.07, 0.2);
	glVertex3f(-0.01, 0.05, 0.2);
	glVertex3f(-0.01, 0.05, -0.1);
	glVertex3f(-0.01, 0.07, -0.1);

	//face 10
	glVertex3f(-0.01, 0.05, 0.2);
	glVertex3f(0.08, 0.03, 0.2);
	glVertex3f(0.08, 0.03, -0.1);
	glVertex3f(-0.01, 0.05, -0.1);

	//face 11
	glVertex3f(0.08, 0.03, 0.2);
	glVertex3f(0.1, 0.04, 0.2);
	glVertex3f(0.1, 0.04, -0.1);
	glVertex3f(0.08, 0.03, -0.1);

	//face 12
	glVertex3f(0.1, 0.04, 0.2);
	glVertex3f(0.12, 0.06, 0.2);
	glVertex3f(0.12, 0.06, -0.1);
	glVertex3f(0.1, 0.04, -0.1);

	//face 13
	glVertex3f(0.12, 0.06, 0.2);
	glVertex3f(0.14, 0.08, 0.2);
	glVertex3f(0.14, 0.08, -0.1);
	glVertex3f(0.12, 0.06, -0.1);

	//face 14
	glVertex3f(0.14, 0.08, 0.2);
	glVertex3f(0.15, 0.11, 0.2);
	glVertex3f(0.15, 0.11, -0.1);
	glVertex3f(0.14, 0.08, -0.1);

	//face 15
	glVertex3f(0.15, 0.11, 0.2);
	glVertex3f(0.15, 0.15, 0.2);
	glVertex3f(0.15, 0.15, -0.1);
	glVertex3f(0.15, 0.11, -0.1);

	//face 16
	glVertex3f(0.15, 0.15, 0.2);
	glVertex3f(0.16, 0.18, 0.2);
	glVertex3f(0.16, 0.18, -0.1);
	glVertex3f(0.15, 0.15, -0.1);

	//face 17
	glVertex3f(0.16, 0.18, 0.2);
	glVertex3f(0.17, 0.23, 0.2);
	glVertex3f(0.17, 0.23, -0.1);
	glVertex3f(0.16, 0.18, -0.1);

	//face 18
	glVertex3f(0.17, 0.23, 0.2);
	glVertex3f(0.17, 0.26, 0.2);
	glVertex3f(0.17, 0.26, -0.1);
	glVertex3f(0.17, 0.23, -0.1);

	//face 19
	glVertex3f(0.17, 0.26, 0.2);
	glVertex3f(0.18, 0.31, 0.2);
	glVertex3f(0.18, 0.31, -0.1);
	glVertex3f(0.17, 0.26, -0.1);

	//face 20
	glVertex3f(0.18, 0.31, 0.2);
	glVertex3f(0.17, 0.36, 0.2);
	glVertex3f(0.17, 0.36, -0.1);
	glVertex3f(0.18, 0.31, -0.1);

	//face 21
	glVertex3f(0.17, 0.36, 0.2);
	glVertex3f(0.16, 0.39, 0.2);
	glVertex3f(0.16, 0.39, -0.1);
	glVertex3f(0.17, 0.36, -0.1);

	//face 22
	glVertex3f(0.16, 0.39, 0.2);
	glVertex3f(0.13, 0.41, 0.2);
	glVertex3f(0.13, 0.41, -0.1);
	glVertex3f(0.16, 0.39, -0.1);

	//face 23
	glVertex3f(0.13, 0.41, 0.2);
	glVertex3f(0.0, 0.25, 0.2);
	glVertex3f(0.0, 0.25, -0.1);
	glVertex3f(0.13, 0.41, -0.1);

	//face 24
	glVertex3f(0.0, 0.25, 0.2);
	glVertex3f(-0.03, 0.2, 0.2);
	glVertex3f(-0.01, 0.2, 0.2);
	glVertex3f(-0.02, 0.17, 0.2);
	glVertex3f(-0.02, 0.15, 0.2);
	glVertex3f(-0.02, 0.12, 0.2);
	glVertex3f(-0.02, 0.09, 0.2);
	glVertex3f(-0.01, 0.07, 0.2);
	glVertex3f(-0.01, 0.05, 0.2);
	glVertex3f(0.08, 0.03, 0.2);
	glVertex3f(0.1, 0.04, 0.2);
	glVertex3f(0.12, 0.06, 0.2);
	glVertex3f(0.14, 0.08, 0.2);
	glVertex3f(0.15, 0.11, 0.2);
	glVertex3f(0.15, 0.15, 0.2);
	glVertex3f(0.16, 0.18, 0.2);
	glVertex3f(0.17, 0.23, 0.2);
	glVertex3f(0.17, 0.26, 0.2);
	glVertex3f(0.18, 0.31, 0.2);
	glVertex3f(0.17, 0.36, 0.2);
	glVertex3f(0.16, 0.39, 0.2);
	glVertex3f(0.13, 0.41, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	//face 1
	glVertex3f(0.2, 0.0, -0.1);
	glVertex3f(0.2, 0.4, -0.1);
	glVertex3f(0.24, 0.43, -0.1);
	glVertex3f(0.24, 0.38, -0.1);
	glVertex3f(0.24, 0.3, -0.1);
	glVertex3f(0.25, 0.24, -0.1);
	glVertex3f(0.24, 0.18, -0.1);
	glVertex3f(0.23, 0.12, -0.1);
	glVertex3f(0.2, 0.0, -0.1);

	//face 2
	glVertex3f(0.2, 0.0, 0.2);
	glVertex3f(0.2, 0.4, 0.2);
	glVertex3f(0.2, 0.4, -0.1);
	glVertex3f(0.2, 0.0, -0.1);

	//face 3
	glVertex3f(0.2, 0.4, 0.2);
	glVertex3f(0.24, 0.43, 0.2);
	glVertex3f(0.24, 0.43, -0.1);
	glVertex3f(0.2, 0.4, -0.1);

	//face 4
	glVertex3f(0.24, 0.38, 0.2);
	glVertex3f(0.24, 0.43, 0.2);
	glVertex3f(0.24, 0.43, -0.1);
	glVertex3f(0.24, 0.38, -0.1);

	//face 5
	glVertex3f(0.24, 0.3, 0.2);
	glVertex3f(0.24, 0.38, 0.2);
	glVertex3f(0.24, 0.38, -0.1);
	glVertex3f(0.24, 0.3, -0.1);

	//face 6
	glVertex3f(0.25, 0.24, 0.2);
	glVertex3f(0.24, 0.3, 0.2);
	glVertex3f(0.24, 0.3, -0.1);
	glVertex3f(0.25, 0.24, -0.1);

	//face 7
	glVertex3f(0.24, 0.18, 0.2);
	glVertex3f(0.25, 0.24, 0.2);
	glVertex3f(0.25, 0.24, -0.1);
	glVertex3f(0.24, 0.18, -0.1);

	//face 8
	glVertex3f(0.23, 0.12, 0.2);
	glVertex3f(0.24, 0.18, 0.2);
	glVertex3f(0.24, 0.18, -0.1);
	glVertex3f(0.23, 0.12, -0.1);

	//face 9
	glVertex3f(0.22, 0.06, 0.2);
	glVertex3f(0.23, 0.12, 0.2);
	glVertex3f(0.23, 0.12, -0.1);
	glVertex3f(0.22, 0.06, -0.1);

	//face 10
	glVertex3f(0.2, 0.0, 0.2);
	glVertex3f(0.22, 0.06, 0.2);
	glVertex3f(0.22, 0.06, -0.1);
	glVertex3f(0.2, 0.0, -0.1);

	//face 11
	glVertex3f(0.2, 0.0, 0.2);
	glVertex3f(0.2, 0.4, 0.2);
	glVertex3f(0.24, 0.43, 0.2);
	glVertex3f(0.24, 0.38, 0.2);
	glVertex3f(0.24, 0.3, 0.2);
	glVertex3f(0.25, 0.24, 0.2);
	glVertex3f(0.24, 0.18, 0.2);
	glVertex3f(0.23, 0.12, 0.2);
	glVertex3f(0.2, 0.0, 0.2);
	glEnd();

	//line in the top arm
	glBegin(GL_QUADS);
	//face 1
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(-0.01, 0.18, 0.22);
	glVertex3f(0.15, 0.18, 0.22);
	glVertex3f(0.15, 0.15, 0.22);
	glVertex3f(-0.02, 0.16, 0.22);

	//face 2
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(-0.01, 0.18, 0.22);
	glVertex3f(0.15, 0.18, 0.22);
	glVertex3f(0.15, 0.18, -0.12);
	glVertex3f(-0.01, 0.18, -0.12);

	//face 3
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(0.15, 0.18, 0.22);
	glVertex3f(0.15, 0.15, 0.22);
	glVertex3f(0.15, 0.15, -0.12);
	glVertex3f(0.15, 0.18, -0.12);

	//face 4
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(0.15, 0.15, 0.22);
	glVertex3f(-0.02, 0.16, 0.22);
	glVertex3f(-0.02, 0.18, -0.12);
	glVertex3f(0.15, 0.15, -0.12);

	//face 5
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(-0.02, 0.16, 0.22);
	glVertex3f(-0.01, 0.18, 0.2);
	glVertex3f(-0.01, 0.18, -0.1);
	glVertex3f(-0.02, 0.16, 0.22);

	//face 6
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(-0.01, 0.18, 0.12);
	glVertex3f(0.15, 0.18, 0.12);
	glVertex3f(0.15, 0.15, 0.12);
	glVertex3f(-0.02, 0.16, 0.12);
	glEnd();

	//shoulder L size shape
	glBegin(GL_QUADS);
	//face 1
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(0.02, 0.45, -0.15);
	glVertex3f(-0.03, 0.53, -0.15);
	glVertex3f(0.01, 0.52, -0.15);
	glVertex3f(0.05, 0.47, -0.15);

	//face 2
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(0.02, 0.45, 0.25);
	glVertex3f(0.02, 0.45, -0.15);
	glVertex3f(-0.03, 0.53, -0.15);
	glVertex3f(0.01, 0.52, -0.15);

	//face 3
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(-0.03, 0.53, 0.25);
	glVertex3f(0.01, 0.52, 0.25);
	glVertex3f(0.01, 0.52, -0.15);
	glVertex3f(-0.03, 0.53, -0.15);

	//face 4
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(0.01, 0.52, 0.25);
	glVertex3f(0.05, 0.47, 0.25);
	glVertex3f(0.05, 0.47, -0.15);
	glVertex3f(0.01, 0.52, -0.15);

	//face 5
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(0.02, 0.45, 0.25);
	glVertex3f(0.05, 0.47, 0.25);
	glVertex3f(0.05, 0.47, -0.15);
	glVertex3f(0.02, 0.45, -0.15);

	//face 6
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(0.02, 0.45, 0.25);
	glVertex3f(0.03, 0.53, 0.25);
	glVertex3f(0.01, 0.52, 0.25);
	glVertex3f(0.05, 0.47, 0.25);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(-0.03, 0.53, -0.15);
	glVertex3f(0.04, 0.58, -0.15);
	glVertex3f(0.06, 0.56, -0.15);
	glVertex3f(0.01, 0.52, -0.15);

	//face 2
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(-0.03, 0.53, 0.25);
	glVertex3f(0.04, 0.58, 0.25);
	glVertex3f(0.04, 0.58, -0.15);
	glVertex3f(-0.03, 0.53, -0.15);

	//face 3
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(0.04, 0.58, 0.25);
	glVertex3f(0.06, 0.56, 0.25);
	glVertex3f(0.06, 0.56, -0.15);
	glVertex3f(0.04, 0.58, -0.15);

	//face 4
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(0.01, 0.52, 0.25);
	glVertex3f(0.06, 0.56, 0.25);
	glVertex3f(0.06, 0.56, -0.15);
	glVertex3f(0.01, 0.52, -0.15);

	//face 5
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(-0.03, 0.53, 0.25);
	glVertex3f(0.01, 0.52, 0.25);
	glVertex3f(0.01, 0.52, -0.15);
	glVertex3f(-0.03, 0.53, -0.15);

	//face 6
	glColor3f(0.37, 0.37, 0.37);
	glVertex3f(-0.03, 0.53, 0.25);
	glVertex3f(0.04, 0.58, 0.25);
	glVertex3f(0.06, 0.56, 0.25);
	glVertex3f(0.01, 0.52, 0.2);
	glEnd();

	glColor3f(0.75, 0.76, 0.75);
	drawCylinder(GLU_FILL, 0.07, 0.09, 0.12, 8, 0.13, 0.37, 0.2);
	glColor3f(0.38, 0.38, 0.38);
	drawCylinder(GLU_LINE, 0.07, 0.09, 0.12, 8, 0.13, 0.37, 0.2);

	//glPushMatrix();
	//glRotatef(180.0, 0.0, 0.0, 1.0); // Rotate the entire arm assembly by 180 degrees around the Z-axis
	//glTranslatef(0.0, -0.6, 0.0); // Translate down along y-axis
	//glRotatef(r2, 1.0, 0.0, 0.0); // Rotate about x-axis
	//drawArm(0.8, 0.6, 0.1); // Bottom arm

	//glPushMatrix();
	//glTranslatef(0.0, 0.6, 0.0); // Translate up along y-axis
	//glRotatef(r1, 0.0, 0.0, 1.0); // Rotate about z-axis
	//drawArm(0.8, 0.6, 0.2); // Top arm
	//glPopMatrix();
	//glPopMatrix();

}

void drawArm2() {
	glBegin(GL_QUADS);
	//face 1
	glVertex3f(-0.04, 0.07, 0.2);
	glVertex3f(-0.01, 0.07, 0.2);
	glVertex3f(0.0, 0.02, 0.2);
	glVertex3f(-0.06, 0.02, 0.2);

	//face 2
	glVertex3f(-0.04, 0.07, 0.2);
	glVertex3f(-0.01, 0.07, 0.2);
	glVertex3f(-0.01, 0.07, -0.1);
	glVertex3f(-0.04, 0.07, -0.1);

	//face 3
	glVertex3f(-0.01, 0.07, 0.2);
	glVertex3f(0.0, 0.02, 0.2);
	glVertex3f(0.0, 0.02, -0.1);
	glVertex3f(-0.01, 0.07, -0.1);

	//face 4
	glVertex3f(0.0, 0.02, 0.2);
	glVertex3f(-0.06, 0.02, 0.2);
	glVertex3f(-0.06, 0.02, -0.1);
	glVertex3f(0.0, 0.02, -0.1);

	//face 5
	glVertex3f(-0.06, 0.02, 0.2);
	glVertex3f(-0.04, 0.07, 0.2);
	glVertex3f(-0.04, 0.07, -0.1);
	glVertex3f(-0.06, 0.02, -0.1);

	//face 6
	glVertex3f(-0.04, 0.07, -0.1);
	glVertex3f(-0.01, 0.07, -0.1);
	glVertex3f(0.0, 0.02, -0.1);
	glVertex3f(-0.06, 0.02, -0.1);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glVertex3f(-0.06, 0.02, 0.2);
	glVertex3f(0.0, 0.2, 0.2);
	glVertex3f(0.0, -0.03, 0.2);
	glVertex3f(-0.07, -0.03, 0.2);

	//face 2
	glVertex3f(-0.06, 0.02, 0.2);
	glVertex3f(0.0, 0.02, 0.2);
	glVertex3f(0.0, 0.02, -0.1);
	glVertex3f(-0.06, 0.02, 0.2);

	//face 3
	glVertex3f(0.0, 0.02, 0.2);
	glVertex3f(0.0, -0.03, 0.2);
	glVertex3f(0.0, -0.03, -0.1);
	glVertex3f(0.0, 0.02, -0.1);

	//face 4
	glVertex3f(0.0, -0.03, 0.2);
	glVertex3f(-0.09, -0.08, 0.2);
	glVertex3f(-0.09, -0.08, -0.1);
	glVertex3f(0.0, -0.03, -0.1);

	//face 5
	glVertex3f(-0.09, -0.08, 0.2);
	glVertex3f(-0.07, -0.03, 0.2);
	glVertex3f(-0.07, -0.03, -0.1);
	glVertex3f(-0.09, -0.08, -0.1);

	//face 6
	glVertex3f(-0.06, 0.02, -0.1);
	glVertex3f(0.0, 0.2, -0.1);
	glVertex3f(0.0, -0.03, -0.1);
	glVertex3f(-0.07, -0.03, -0.1);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glVertex3f(-0.07, -0.03, 0.2);
	glVertex3f(0.0, -0.03, 0.2);
	glVertex3f(0.0, -0.08, 0.2);
	glVertex3f(-0.09, -0.08, 0.2);

	//face 2
	glVertex3f(-0.07, -0.03, 0.2);
	glVertex3f(0.0, -0.03, 0.2);
	glVertex3f(0.0, -0.03, -0.1);
	glVertex3f(-0.07, -0.03, -0.1);

	//face 3
	glVertex3f(0.0, -0.03, 0.2);
	glVertex3f(0.0, -0.08, 0.2);
	glVertex3f(0.0, -0.08, -0.1);
	glVertex3f(0.0, -0.03, -0.1);

	//face 4
	glVertex3f(-0.09, -0.08, 0.2);
	glVertex3f(0.0, -0.08, 0.2);
	glVertex3f(0.0, -0.08, -0.1);
	glVertex3f(-0.09, -0.08, -0.1);

	//face 5
	glVertex3f(-0.09, -0.08, 0.2);
	glVertex3f(-0.07, -0.03, 0.2);
	glVertex3f(-0.07, -0.03, -1.0);
	glVertex3f(-0.09, -0.08, -0.1);

	//face 6
	glVertex3f(-0.07, -0.03, -0.1);
	glVertex3f(0.0, -0.03, -0.1);
	glVertex3f(0.0, -0.08, -0.1);
	glVertex3f(-0.09, -0.08, -0.1);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glVertex3f(-0.09, -0.08, 0.2);
	glVertex3f(0.0, -0.08, 0.2);
	glVertex3f(0.0, -0.14, 0.2);
	glVertex3f(-0.1, -0.14, 0.2);

	//face 2
	glVertex3f(-0.09, -0.08, 0.2);
	glVertex3f(0.0, -0.08, 0.2);
	glVertex3f(0.0, -0.08, -0.1);
	glVertex3f(-0.09, -0.08, -0.1);

	//face 3
	glVertex3f(0.0, -0.08, 0.2);
	glVertex3f(0.0, -0.14, 0.2);
	glVertex3f(0.0, -0.14, -0.1);
	glVertex3f(0.0, -0.08, -0.1);

	//face 4
	glVertex3f(0.0, -0.14, 0.2);
	glVertex3f(-0.1, -0.14, 0.2);
	glVertex3f(-0.1, -0.14, -0.1);
	glVertex3f(0.0, -0.14, -0.1);

	//face 5
	glVertex3f(-0.1, -0.14, 0.2);
	glVertex3f(-0.09, -0.08, 0.2);
	glVertex3f(-0.09, -0.08, -0.1);
	glVertex3f(-0.1, -0.14, -0.1);

	//face 6
	glVertex3f(-0.09, -0.08, -0.1);
	glVertex3f(0.0, -0.08, -0.1);
	glVertex3f(0.0, -0.14, -0.1);
	glVertex3f(-0.1, -0.14, -0.1);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glVertex3f(-0.1, -0.14, 0.2);
	glVertex3f(0.0, -0.14, 0.2);
	glVertex3f(0.0, -0.21, 0.2);
	glVertex3f(-0.12, -0.2, 0.2);

	//face 2
	glVertex3f(-0.1, -0.14, 0.2);
	glVertex3f(0.0, -0.14, 0.2);
	glVertex3f(0.0, -0.14, -0.1);
	glVertex3f(-0.1, -0.14, -0.1);

	//face 3
	glVertex3f(0.0, -0.14, 0.2);
	glVertex3f(0.0, -0.21, 0.2);
	glVertex3f(0.0, -0.21, -0.1);
	glVertex3f(0.0, -0.14, -0.1);

	//face 4
	glVertex3f(0.0, -0.21, 0.2);
	glVertex3f(-0.12, -0.2, 0.2);
	glVertex3f(-0.12, -0.2, -0.1);
	glVertex3f(0.0, -0.21, -0.1);

	//face 5
	glVertex3f(-0.12, -0.2, 0.2);
	glVertex3f(-0.1, -0.14, 0.2);
	glVertex3f(-0.1, -0.14, -0.1);
	glVertex3f(-0.12, -0.2, -0.1);

	//face 6
	glVertex3f(-0.1, -0.14, -0.1);
	glVertex3f(0.0, -0.14, -0.1);
	glVertex3f(0.0, -0.21, -0.1);
	glVertex3f(-0.12, -0.2, -0.1);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glVertex3f(-0.12, -0.2, 0.2);
	glVertex3f(0.0, -0.21, 0.2);
	glVertex3f(0.0, -0.28, 0.2);
	glVertex3f(-0.13, -0.27, 0.2);

	//face 2
	glVertex3f(-0.12, -0.2, 0.2);
	glVertex3f(0.0, -0.21, 0.2);
	glVertex3f(0.0, -0.21, -0.1);
	glVertex3f(-0.12, -0.2, -0.1);

	//face 3
	glVertex3f(0.0, -0.21, 0.2);
	glVertex3f(0.0, -0.28, 0.2);
	glVertex3f(0.0, -0.28, -0.1);
	glVertex3f(0.0, -0.21, -0.1);

	//face 4
	glVertex3f(0.0, -0.28, 0.2);
	glVertex3f(-0.13, -0.27, 0.2);
	glVertex3f(-0.13, -0.27, -1.0);
	glVertex3f(0.0, -0.28, -0.1);

	//face 5
	glVertex3f(-0.13, -0.27, 0.2);
	glVertex3f(-0.12, -0.2, 0.2);
	glVertex3f(-0.12, -0.2, -0.1);
	glVertex3f(-0.13, -0.27, -0.1);

	//face 6
	glVertex3f(-0.12, -0.2, -0.1);
	glVertex3f(0.0, -0.21, -0.1);
	glVertex3f(0.0, -0.28, -0.1);
	glVertex3f(-0.13, -0.27, -0.1);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glVertex3f(-0.13, -0.27, 0.2);
	glVertex3f(0.0, -0.28, 0.2);
	glVertex3f(0.0, -0.38, 0.2);
	glVertex3f(-0.14, -0.36, 0.2);

	//face 2
	glVertex3f(-0.13, -0.27, 0.2);
	glVertex3f(0.0, -0.28, 0.2);
	glVertex3f(0.0, -0.28, -0.1);
	glVertex3f(-0.13, -0.27, -0.1);

	//face 3
	glVertex3f(0.0, -0.28, 0.2);
	glVertex3f(0.0, -0.38, 0.2);
	glVertex3f(0.0, -0.38, -0.1);
	glVertex3f(0.0, -0.28, -0.1);

	//face 4
	glVertex3f(0.0, -0.38, 0.2);
	glVertex3f(-0.14, -0.36, 0.2);
	glVertex3f(-0.14, -0.36, -0.1);
	glVertex3f(0.0, -0.38, -0.1);

	//face 5
	glVertex3f(-0.14, -0.36, 0.2);
	glVertex3f(-0.13, -0.27, 0.2);
	glVertex3f(-0.13, -0.27, -0.1);
	glVertex3f(-0.14, -0.36, -0.1);

	//face 6
	glVertex3f(-0.13, -0.27, -0.1);
	glVertex3f(0.0, -0.28, -0.1);
	glVertex3f(0.0, -0.38, -0.1);
	glVertex3f(-0.14, -0.36, -0.1);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glVertex3f(-0.14, -0.36, 0.2);
	glVertex3f(0.0, -0.38, 0.2);
	glVertex3f(0.0, -0.47, 0.2);
	glVertex3f(-0.16, -0.45, 0.2);

	//face 2
	glVertex3f(-0.14, -0.36, 0.2);
	glVertex3f(0.0, -0.38, 0.2);
	glVertex3f(0.0, -0.38, -0.1);
	glVertex3f(-0.14, -0.36, -0.1);

	//face 3
	glVertex3f(0.0, -0.38, 0.2);
	glVertex3f(0.0, -0.47, 0.2);
	glVertex3f(0.0, -0.47, -0.1);
	glVertex3f(0.0, -0.38, -0.1);

	//face 4
	glVertex3f(0.0, -0.47, 0.2);
	glVertex3f(-0.16, -0.45, 0.2);
	glVertex3f(-0.16, -0.45, -0.1);
	glVertex3f(0.0, -0.47, -0.1);

	//face 5
	glVertex3f(-0.16, -0.45, 0.2);
	glVertex3f(-0.14, -0.36, 0.2);
	glVertex3f(-0.14, -0.36, -0.1);
	glVertex3f(-0.16, -0.45, -0.1);

	//face 6
	glVertex3f(-0.14, -0.36, -0.1);
	glVertex3f(0.0, -0.38, -0.1);
	glVertex3f(0.0, -0.47, -0.1);
	glVertex3f(-0.16, -0.45, -0.1);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glVertex3f(-0.16, -0.45, 0.2);
	glVertex3f(0.0, -0.47, 0.2);
	glVertex3f(0.0, -0.55, 0.2);
	glVertex3f(-0.16, -0.54, 0.2);

	//face 2
	glVertex3f(-0.16, -0.45, 0.2);
	glVertex3f(0.0, -0.47, 0.2);
	glVertex3f(0.0, -0.47, -0.1);
	glVertex3f(-0.16, -0.45, -0.1);

	//face 3
	glVertex3f(0.0, -0.47, 0.2);
	glVertex3f(0.0, -0.55, 0.2);
	glVertex3f(0.0, -0.55, -0.1);
	glVertex3f(0.0, -0.47, -0.1);

	//face 4
	glVertex3f(0.0, -0.55, 0.2);
	glVertex3f(-0.16, -0.54, 0.2);
	glVertex3f(-0.16, -0.54, -0.1);
	glVertex3f(0.0, -0.55, -0.1);

	//face 5
	glVertex3f(-0.16, -0.54, 0.2);
	glVertex3f(-0.16, -0.45, 0.2);
	glVertex3f(-0.16, -0.45, -0.1);
	glVertex3f(-0.16, -0.54, -0.1);

	//face 6
	glVertex3f(-0.16, -0.45, -0.1);
	glVertex3f(0.0, -0.47, -0.1);
	glVertex3f(0.0, -0.55, -0.1);
	glVertex3f(-0.16, -0.54, -0.1);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glVertex3f(-0.16, -0.54, 0.2);
	glVertex3f(0.0, -0.55, 0.2);
	glVertex3f(0.0, -0.6, 0.2);
	glVertex3f(-0.12, -0.73, 0.2);

	//face 2
	glVertex3f(-0.16, -0.54, 0.2);
	glVertex3f(0.0, -0.55, 0.2);
	glVertex3f(0.0, -0.55, -0.1);
	glVertex3f(-0.16, -0.54, -0.1);

	//face 3
	glVertex3f(0.0, -0.55, 0.2);
	glVertex3f(0.0, -0.6, 0.2);
	glVertex3f(0.0, -0.6, -0.1);
	glVertex3f(0.0, -0.55, -0.1);

	//face 4
	glVertex3f(0.0, -0.6, 0.2);
	glVertex3f(-0.12, -0.73, 0.2);
	glVertex3f(-0.12, -0.73, -0.1);
	glVertex3f(0.0, -0.6, -0.1);

	//face 5
	glVertex3f(-0.12, -0.73, 0.2);
	glVertex3f(-0.16, -0.54, 0.2);
	glVertex3f(-0.16, -0.54, -0.1);
	glVertex3f(-0.12, -0.73, -0.1);

	//face 6
	glVertex3f(-0.16, -0.54, -0.1);
	glVertex3f(0.0, -0.55, -0.1);
	glVertex3f(0.0, -0.6, -0.1);
	glVertex3f(-0.12, -0.73, -0.1);
	glEnd();


	glBegin(GL_QUADS);
	//face 1
	glVertex3f(0.2, -0.17, 0.1);
	glVertex3f(0.2, 0.0, 0.1);
	glVertex3f(0.28, -0.09, 0.1);
	glVertex3f(0.28, -0.15, 0.1);

	//face 2
	glVertex3f(0.2, -0.17, 0.1);
	glVertex3f(0.2, 0.0, 0.1);
	glVertex3f(0.2, 0.0, 0.0);
	glVertex3f(0.2, -0.17, 0.0);

	//face 3
	glVertex3f(0.2, 0.0, 0.1);
	glVertex3f(0.28, -0.09, 0.1);
	glVertex3f(0.28, -0.09, 0.0);
	glVertex3f(0.2, 0.0, 0.0);

	//face 4
	glVertex3f(0.28, -0.09, 0.1);
	glVertex3f(0.28, -0.15, 0.10);
	glVertex3f(0.28, -0.15, 0.0);
	glVertex3f(0.28, -0.09, 0.0);

	//face 5
	glVertex3f(0.28, -0.15, 0.1);
	glVertex3f(0.2, -0.17, 0.1);
	glVertex3f(0.2, -0.17, 0.0);
	glVertex3f(0.28, -0.15, 0.0);

	//face 6
	glBegin(GL_QUADS);
	glVertex3f(0.2, -0.17, 0.0);
	glVertex3f(0.2, 0.0, 0.0);
	glVertex3f(0.28, -0.09, 0.0);
	glVertex3f(0.28, -0.15, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glVertex3f(0.2, -0.3, 0.1);
	glVertex3f(0.2, -0.17, 0.1);
	glVertex3f(0.28, -0.15, 0.1);
	glVertex3f(0.28, -0.25, 0.1);

	//face 2
	glVertex3f(0.2, -0.3, 0.1);
	glVertex3f(0.2, -0.17, 0.1);
	glVertex3f(0.2, -0.3, 0.0);
	glVertex3f(0.2, -0.17, 0.0);

	//face 3
	glVertex3f(0.2, -0.17, 0.1);
	glVertex3f(0.28, -0.15, 0.1);
	glVertex3f(0.28, -0.15, 0.0);
	glVertex3f(0.2, -0.17, 0.0);

	//face 4
	glVertex3f(0.28, -0.15, 0.1);
	glVertex3f(0.28, -0.25, 0.1);
	glVertex3f(0.28, -0.25, 0.0);
	glVertex3f(0.28, -0.15, 0.0);

	//face 5
	glVertex3f(0.28, -0.25, 0.1);
	glVertex3f(0.2, -0.3, 0.1);
	glVertex3f(0.2, -0.3, 0.0);
	glVertex3f(0.28, -0.25, 0.0);

	//face 6
	glVertex3f(0.2, -0.3, 0.0);
	glVertex3f(0.2, -0.17, 0.0);
	glVertex3f(0.28, -0.15, 0.0);
	glVertex3f(0.28, -0.25, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glVertex3f(0.0, -0.05, 0.2);
	glVertex3f(0.2, -0.02, 0.2);
	glVertex3f(0.2, -0.08, 0.2);
	glVertex3f(0.0, -0.11, 0.2);

	//face 2
	glVertex3f(0.0, -0.05, 0.2);
	glVertex3f(0.2, -0.02, 0.2);
	glVertex3f(0.2, -0.02, -0.1);
	glVertex3f(0.0, -0.05, -0.1);

	//face 3
	glVertex3f(0.2, -0.02, 0.2);
	glVertex3f(0.2, -0.08, 0.2);
	glVertex3f(0.2, -0.08, -0.1);
	glVertex3f(0.2, -0.02, -0.1);

	//face 4
	glVertex3f(0.2, -0.08, 0.2);
	glVertex3f(0.0, -0.11, 0.2);
	glVertex3f(0.0, -0.11, -0.1);
	glVertex3f(0.2, -0.08, -0.1);

	//face 5
	glVertex3f(0.0, -0.11, 0.2);
	glVertex3f(0.0, -0.05, 0.2);
	glVertex3f(0.0, -0.05, -0.1);
	glVertex3f(0.0, -0.11, -0.1);

	//face 6
	glVertex3f(0.0, -0.05, -0.1);
	glVertex3f(0.2, -0.02, -0.1);
	glVertex3f(0.2, -0.08, -0.1);
	glVertex3f(0.0, -0.11, -0.1);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glVertex3f(0.0, -0.19, 0.2);
	glVertex3f(0.2, -0.15, 0.2);
	glVertex3f(0.2, -0.2, 0.2);
	glVertex3f(0.0, -0.23, 0.2);

	//face 2
	glVertex3f(0.0, -0.19, 0.2);
	glVertex3f(0.2, -0.15, 0.2);
	glVertex3f(0.2, -0.15, -0.1);
	glVertex3f(0.0, -0.19, -0.1);

	//face 3
	glVertex3f(0.2, -0.15, 0.2);
	glVertex3f(0.2, -0.2, 0.2);
	glVertex3f(0.2, -0.2, -0.1);
	glVertex3f(0.2, -0.15, -0.1);

	//face 4
	glVertex3f(0.2, -0.2, 0.2);
	glVertex3f(0.0, -0.19, 0.2);
	glVertex3f(0.0, -0.19, -0.1);
	glVertex3f(0.2, -0.2, -0.1);

	//face 5
	glVertex3f(0.0, -0.23, 0.2);
	glVertex3f(0.0, -0.19, 0.2);
	glVertex3f(0.0, -0.19, -0.1);
	glVertex3f(0.0, -0.23, -0.1);

	//face 6
	glVertex3f(0.0, -0.19, -0.1);
	glVertex3f(0.2, -0.15, -0.1);
	glVertex3f(0.2, -0.2, -0.1);
	glVertex3f(0.0, -0.23, -0.1);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glVertex3f(0.0, -0.3, 0.2);
	glVertex3f(0.2, -0.28, 0.2);
	glVertex3f(0.2, -0.33, 0.2);
	glVertex3f(0.0, -0.35, 0.2);

	//face 2
	glVertex3f(0.0, -0.3, 0.2);
	glVertex3f(0.2, -0.28, 0.2);
	glVertex3f(0.2, -0.28, -0.1);
	glVertex3f(0.0, -0.3, -0.1);

	//face 3
	glVertex3f(0.2, -0.28, 0.2);
	glVertex3f(0.2, -0.33, 0.2);
	glVertex3f(0.2, -0.33, -0.1);
	glVertex3f(0.2, -0.28, -0.1);

	//face 4
	glVertex3f(0.2, -0.33, 0.2);
	glVertex3f(0.0, -0.35, 0.2);
	glVertex3f(0.0, -0.35, -0.1);
	glVertex3f(0.2, -0.33, -0.1);

	//face 5
	glVertex3f(0.0, -0.35, 0.2);
	glVertex3f(0.0, -0.3, 0.2);
	glVertex3f(0.0, -0.3, -0.1);
	glVertex3f(0.0, -0.35, -0.1);

	//face 6
	glVertex3f(0.0, -0.3, -0.1);
	glVertex3f(0.2, -0.28, -0.1);
	glVertex3f(0.2, -0.33, -0.1);
	glVertex3f(0.0, -0.35, -0.1);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glVertex3f(0.0, -0.41, 0.2);
	glVertex3f(0.2, -0.4, 0.2);
	glVertex3f(0.2, -0.45, 0.2);
	glVertex3f(0.0, -0.47, 0.2);

	//face 2
	glVertex3f(0.0, -0.41, 0.2);
	glVertex3f(0.2, -0.4, 0.2);
	glVertex3f(0.2, -0.4, -0.1);
	glVertex3f(0.0, -0.41, -0.1);

	//face 3
	glVertex3f(0.2, -0.4, 0.2);
	glVertex3f(0.2, -0.45, 0.2);
	glVertex3f(0.2, -0.45, -0.1);
	glVertex3f(0.2, -0.4, -0.1);

	//face 4
	glVertex3f(0.2, -0.45, 0.2);
	glVertex3f(0.0, -0.47, 0.2);
	glVertex3f(0.0, -0.47, -0.1);
	glVertex3f(0.2, -0.45, -0.1);

	//face 5
	glVertex3f(0.0, -0.47, 0.2);
	glVertex3f(0.0, -0.41, 0.2);
	glVertex3f(0.0, -0.41, -0.1);
	glVertex3f(0.0, -0.47, -0.1);

	//face 6
	glVertex3f(0.0, -0.41, -0.1);
	glVertex3f(0.2, -0.4, -0.1);
	glVertex3f(0.2, -0.45, -0.1);
	glVertex3f(0.0, -0.47, -0.1);
	glEnd();
}

void drawHand() {
	glBegin(GL_QUADS);
	//RIGHT - Lpalm	
	//face 1
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.04, -0.6, 0.0);
	glVertex3f(0.01, -0.69, 0.0);
	glVertex3f(0.13, -0.69, 0.0);
	glVertex3f(0.13, -0.6, 0.0);

	//face 2
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.04, -0.6, 0.1);
	glVertex3f(0.04, -0.6, 0.0);
	glVertex3f(0.01, -0.69, 0.0);
	glVertex3f(0.01, -0.69, 0.1);

	//face 3
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.04, -0.6, 0.1);
	glVertex3f(0.01, -0.69, 0.1);
	glVertex3f(0.13, -0.69, 0.1);
	glVertex3f(0.13, -0.6, 0.1);

	//face 4
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.01, -0.69, 0.1);
	glVertex3f(0.01, -0.69, 0.0);
	glVertex3f(0.13, -0.69, 0.0);
	glVertex3f(0.13, -0.69, 0.1);

	//face 5
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(0.13, -0.6, 0.1);
	glVertex3f(0.13, -0.69, 0.1);
	glVertex3f(0.13, -0.69, 0.0);
	glVertex3f(0.13, -0.6, 0.0);

	//face 6 
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.04, -0.6, 0.1);
	glVertex3f(0.13, -0.6, 0.1);
	glVertex3f(0.13, -0.6, 0.0);
	glVertex3f(0.04, -0.6, 0.0);

	//RIGHT - Rpalm
	//face 1 
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.13, -0.6, 0.1);
	glVertex3f(0.13, -0.69, 0.1);
	glVertex3f(0.2, -0.68, 0.1);
	glVertex3f(0.17, -0.6, 0.1);

	//face 2
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.13, -0.69, 0.1);
	glVertex3f(0.13, -0.69, 0.0);
	glVertex3f(0.2, -0.68, 0.0);
	glVertex3f(0.2, -0.68, 0.1);

	//face 3
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.2, -0.68, 0.1);
	glVertex3f(0.2, -0.68, 0.0);
	glVertex3f(0.17, -0.6, 0.0);
	glVertex3f(0.17, -0.6, 0.1);

	//face 4
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.13, -0.6, 0.1);
	glVertex3f(0.13, -0.6, 0.0);
	glVertex3f(0.17, -0.6, 0.0);
	glVertex3f(0.17, -0.6, 0.1);

	//face 5 
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.13, -0.69, 0.1);
	glVertex3f(0.13, -0.6, 0.1);
	glVertex3f(0.13, -0.6, 0.0);
	glVertex3f(0.13, -0.69, 0.0);

	//face 6
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(0.13, -0.6, 0.1);
	glVertex3f(0.17, -0.6, 0.1);
	glVertex3f(0.2, -0.68, 0.1);
	glVertex3f(0.13, -0.69, 0.1);
	glEnd();
}


void drawFingers() {
	glBegin(GL_QUADS);
	//little finger
	//first
	//face 1 - base
	glVertex3f(0.01, -0.69, 0.0);
	glVertex3f(0.04, -0.69, 0.0);
	glVertex3f(0.03, -0.75, 0.0);
	glVertex3f(0.0, -0.76, 0.0);

	//face 2
	glVertex3f(0.0, -0.76, 0.1);
	glVertex3f(0.01, -0.69, 0.1);
	glVertex3f(0.01, -0.69, 0.0);
	glVertex3f(0.0, -0.76, 0.0);

	//face 3
	glVertex3f(0.01, -0.69, 0.1);
	glVertex3f(0.04, -0.69, 0.1);
	glVertex3f(0.04, -0.69, 0.0);
	glVertex3f(0.01, -0.69, 0.0);

	//face 4
	glVertex3f(0.03, -0.75, 0.1);
	glVertex3f(0.04, -0.69, 0.1);
	glVertex3f(0.04, -0.69, 0.0);
	glVertex3f(0.03, -0.75, 0.0);

	//face 5
	glVertex3f(0.0, -0.76, 0.1);
	glVertex3f(0.03, -0.75, 0.1);
	glVertex3f(0.03, -0.75, 0.0);
	glVertex3f(0.0, -0.76, 0.0);

	//face 6
	glVertex3f(0.01, -0.69, 0.1);
	glVertex3f(0.04, -0.69, 0.1);
	glVertex3f(0.03, -0.75, 0.1);
	glVertex3f(0.0, -0.76, 0.1);

	//second 
	//face 1
	glVertex3f(0.0, -0.76, 0.0);
	glVertex3f(0.03, -0.75, 0.0);
	glVertex3f(0.06, -0.81, 0.0);
	glVertex3f(0.03, -0.83, 0.0);

	//face 2
	glVertex3f(0.03, -0.83, 0.1);
	glVertex3f(0.0, -0.76, 0.1);
	glVertex3f(0.0, -0.76, 0.0);
	glVertex3f(0.03, -0.83, 0.0);

	//face 3
	glVertex3f(0.0, -0.76, 0.1);
	glVertex3f(0.03, -0.75, 0.1);
	glVertex3f(0.03, -0.75, 0.0);
	glVertex3f(0.0, -0.76, 0.0);

	//face 4
	glVertex3f(0.06, -0.81, 0.1);
	glVertex3f(0.03, -0.75, 0.1);
	glVertex3f(0.03, -0.75, 0.0);
	glVertex3f(0.06, -0.81, 0.0);

	//face 5
	glVertex3f(0.03, -0.83, 0.1);
	glVertex3f(0.06, -0.81, 0.1);
	glVertex3f(0.06, -0.81, 0.0);
	glVertex3f(0.03, -0.83, 0.0);

	//face 6
	glVertex3f(0.0, -0.76, 0.1);
	glVertex3f(0.03, -0.75, 0.1);
	glVertex3f(0.06, -0.81, 0.1);
	glVertex3f(0.03, -0.83, 0.1);

	//third
	//face 1
	glVertex3f(0.03, -0.83, 0.0);
	glVertex3f(0.06, -0.81, 0.0);
	glVertex3f(0.09, -0.86, 0.0);
	glVertex3f(0.06, -0.88, 0.0);

	//face 2
	glVertex3f(0.06, -0.88, 0.1);
	glVertex3f(0.03, -0.83, 0.1);
	glVertex3f(0.03, -0.83, 0.0);
	glVertex3f(0.06, -0.88, 0.0);

	//face 3
	glVertex3f(0.03, -0.83, 0.1);
	glVertex3f(0.06, -0.81, 0.1);
	glVertex3f(0.06, -0.81, 0.0);
	glVertex3f(0.03, -0.83, 0.0);

	//face 4
	glVertex3f(0.09, -0.86, 0.1);
	glVertex3f(0.06, -0.81, 0.1);
	glVertex3f(0.06, -0.81, 0.0);
	glVertex3f(0.09, -0.86, 0.0);

	//face 5
	glVertex3f(0.06, -0.88, 0.1);
	glVertex3f(0.09, -0.86, 0.1);
	glVertex3f(0.09, -0.86, 0.0);
	glVertex3f(0.06, -0.88, 0.0);

	//face 6
	glVertex3f(0.03, -0.83, 0.1);
	glVertex3f(0.06, -0.81, 0.1);
	glVertex3f(0.09, -0.86, 0.1);
	glVertex3f(0.06, -0.88, 0.1);

	//wu ming zhi
	//first 
	//face 1
	glVertex3f(0.04, -0.69, 0.0);
	glVertex3f(0.07, -0.69, 0.0);
	glVertex3f(0.06, -0.75, 0.0);
	glVertex3f(0.03, -0.75, 0.0);

	//face 2
	glVertex3f(0.03, -0.75, 0.1);
	glVertex3f(0.04, -0.69, 0.1);
	glVertex3f(0.04, -0.69, 0.0);
	glVertex3f(0.03, -0.75, 0.0);

	//face 3
	glVertex3f(0.04, -0.69, 0.1);
	glVertex3f(0.07, -0.69, 0.1);
	glVertex3f(0.07, -0.69, 0.0);
	glVertex3f(0.04, -0.69, 0.0);

	//face 4
	glVertex3f(0.06, -0.75, 0.1);
	glVertex3f(0.07, -0.69, 0.1);
	glVertex3f(0.07, -0.69, 0.0);
	glVertex3f(0.06, -0.75, 0.0);

	//face 5
	glVertex3f(0.03, -0.75, 0.1);
	glVertex3f(0.06, -0.75, 0.1);
	glVertex3f(0.06, -0.75, 0.0);
	glVertex3f(0.03, -0.75, 0.0);

	//face 6
	glVertex3f(0.04, -0.69, 0.1);
	glVertex3f(0.07, -0.69, 0.1);
	glVertex3f(0.06, -0.75, 0.1);
	glVertex3f(0.03, -0.75, 0.1);

	//second
	//face 1
	glVertex3f(0.03, -0.75, 0.0);
	glVertex3f(0.06, -0.75, 0.0);
	glVertex3f(0.08, -0.79, 0.0);
	glVertex3f(0.06, -0.81, 0.0);

	//face 2
	glVertex3f(0.06, -0.81, 0.1);
	glVertex3f(0.03, -0.75, 0.1);
	glVertex3f(0.03, -0.75, 0.0);
	glVertex3f(0.06, -0.81, 0.0);

	//face 3
	glVertex3f(0.03, -0.75, 0.1);
	glVertex3f(0.06, -0.75, 0.1);
	glVertex3f(0.06, -0.75, 0.0);
	glVertex3f(0.03, -0.75, 0.0);

	//face 4
	glVertex3f(0.08, -0.79, 0.1);
	glVertex3f(0.06, -0.75, 0.1);
	glVertex3f(0.06, -0.75, 0.0);
	glVertex3f(0.08, -0.79, 0.0);

	//face 5
	glVertex3f(0.06, -0.81, 0.1);
	glVertex3f(0.08, -0.79, 0.1);
	glVertex3f(0.08, -0.79, 0.0);
	glVertex3f(0.06, -0.81, 0.0);

	//face 6
	glVertex3f(0.03, -0.75, 0.1);
	glVertex3f(0.06, -0.75, 0.1);
	glVertex3f(0.08, -0.79, 0.1);
	glVertex3f(0.06, -0.81, 0.1);

	//third
	//face 1
	glVertex3f(0.06, -0.81, 0.0);
	glVertex3f(0.08, -0.79, 0.0);
	glVertex3f(0.11, -0.84, 0.0);
	glVertex3f(0.09, -0.86, 0.0);

	//face 2
	glVertex3f(0.09, -0.86, 0.1);
	glVertex3f(0.06, -0.81, 0.1);
	glVertex3f(0.06, -0.81, 0.0);
	glVertex3f(0.09, -0.86, 0.0);

	//face 3
	glVertex3f(0.06, -0.81, 0.1);
	glVertex3f(0.08, -0.79, 0.1);
	glVertex3f(0.08, -0.79, 0.0);
	glVertex3f(0.06, -0.81, 0.0);

	//face 4
	glVertex3f(0.11, -0.84, 0.1);
	glVertex3f(0.08, -0.79, 0.1);
	glVertex3f(0.08, -0.79, 0.0);
	glVertex3f(0.11, -0.84, 0.0);

	//face 5
	glVertex3f(0.09, -0.86, 0.1);
	glVertex3f(0.11, -0.84, 0.1);
	glVertex3f(0.11, -0.84, 0.0);
	glVertex3f(0.09, -0.86, 0.0);

	//face 6
	glVertex3f(0.06, -0.81, 0.1);
	glVertex3f(0.08, -0.79, 0.1);
	glVertex3f(0.11, -0.84, 0.1);
	glVertex3f(0.09, -0.86, 0.1);

	//zhong zhi
	//first - face 1
	glVertex3f(0.07, -0.69, 0.0);
	glVertex3f(0.1, -0.69, 0.0);
	glVertex3f(0.09, -0.74, 0.0);
	glVertex3f(0.06, -0.75, 0.0);

	//face 2
	glVertex3f(0.06, -0.75, 0.1);
	glVertex3f(0.07, -0.69, 0.1);
	glVertex3f(0.07, -0.69, 0.0);
	glVertex3f(0.06, -0.75, 0.0);

	//face 3
	glVertex3f(0.07, -0.69, 0.1);
	glVertex3f(0.1, -0.69, 0.1);
	glVertex3f(0.1, -0.69, 0.0);
	glVertex3f(0.07, -0.69, 0.0);

	//face 4
	glVertex3f(0.09, -0.74, 0.1);
	glVertex3f(0.1, -0.69, 0.1);
	glVertex3f(0.1, -0.69, 0.0);
	glVertex3f(0.09, -0.74, 0.0);

	//face 5
	glVertex3f(0.06, -0.75, 0.1);
	glVertex3f(0.09, -0.74, 0.1);
	glVertex3f(0.09, -0.74, 0.0);
	glVertex3f(0.06, -0.75, 0.0);

	//face 6
	glVertex3f(0.07, -0.69, 0.1);
	glVertex3f(0.1, -0.69, 0.1);
	glVertex3f(0.09, -0.74, 0.1);
	glVertex3f(0.06, -0.75, 0.1);

	//second
	//face 1
	glVertex3f(0.06, -0.75, 0.0);
	glVertex3f(0.09, -0.74, 0.0);
	glVertex3f(0.11, -0.78, 0.0);
	glVertex3f(0.08, -0.79, 0.0);

	//face 2
	glVertex3f(0.08, -0.79, 0.1);
	glVertex3f(0.06, -0.75, 0.1);
	glVertex3f(0.06, -0.75, 0.0);
	glVertex3f(0.08, -0.79, 0.0);

	//face 3
	glVertex3f(0.06, -0.75, 0.1);
	glVertex3f(0.09, -0.74, 0.1);
	glVertex3f(0.09, -0.74, 0.0);
	glVertex3f(0.06, -0.75, 0.0);

	//face 4
	glVertex3f(0.11, -0.78, 0.1);
	glVertex3f(0.09, -0.74, 0.1);
	glVertex3f(0.09, -0.74, 0.0);
	glVertex3f(0.11, -0.78, 0.0);

	//face 5
	glVertex3f(0.08, -0.79, 0.1);
	glVertex3f(0.11, -0.78, 0.1);
	glVertex3f(0.11, -0.78, 0.0);
	glVertex3f(0.08, -0.79, 0.0);

	//face 6
	glVertex3f(0.06, -0.75, 0.1);
	glVertex3f(0.09, -0.74, 0.1);
	glVertex3f(0.11, -0.78, 0.1);
	glVertex3f(0.08, -0.79, 0.1);

	//third
	//face 1
	glVertex3f(0.08, -0.79, 0.0);
	glVertex3f(0.11, -0.78, 0.0);
	glVertex3f(0.14, -0.82, 0.0);
	glVertex3f(0.11, -0.84, 0.0);

	//face 2
	glVertex3f(0.11, -0.84, 0.1);
	glVertex3f(0.08, -0.79, 0.1);
	glVertex3f(0.08, -0.79, 0.0);
	glVertex3f(0.11, -0.84, 0.0);

	//face 3
	glVertex3f(0.08, -0.79, 0.1);
	glVertex3f(0.11, -0.78, 0.1);
	glVertex3f(0.11, -0.78, 0.0);
	glVertex3f(0.08, -0.79, 0.0);

	//face 4
	glVertex3f(0.14, -0.82, 0.1);
	glVertex3f(0.11, -0.78, 0.1);
	glVertex3f(0.11, -0.78, 0.0);
	glVertex3f(0.14, -0.82, 0.0);

	//face 5
	glVertex3f(0.11, -0.84, 0.1);
	glVertex3f(0.14, -0.82, 0.1);
	glVertex3f(0.14, -0.82, 0.0);
	glVertex3f(0.11, -0.84, 0.0);

	//face 6
	glVertex3f(0.08, -0.79, 0.1);
	glVertex3f(0.11, -0.78, 0.1);
	glVertex3f(0.14, -0.82, 0.1);
	glVertex3f(0.11, -0.84, 0.1);

	//shi zhi
	//first - face 1
	glVertex3f(0.1, -0.69, 0.0);
	glVertex3f(0.13, -0.69, 0.0);
	glVertex3f(0.12, -0.73, 0.0);
	glVertex3f(0.09, -0.74, 0.0);

	//face 2
	glVertex3f(0.09, -0.74, 0.1);
	glVertex3f(0.1, -0.69, 0.1);
	glVertex3f(0.1, -0.69, 0.0);
	glVertex3f(0.09, -0.74, 0.0);

	//face 3
	glVertex3f(0.1, -0.69, 0.1);
	glVertex3f(0.13, -0.69, 0.1);
	glVertex3f(0.13, -0.69, 0.0);
	glVertex3f(0.1, -0.69, 0.0);

	//face 4
	glVertex3f(0.12, -0.73, 0.1);
	glVertex3f(0.13, -0.69, 0.1);
	glVertex3f(0.13, -0.69, 0.0);
	glVertex3f(0.12, -0.73, 0.0);

	//face 5
	glVertex3f(0.09, -0.74, 0.1);
	glVertex3f(0.12, -0.73, 0.1);
	glVertex3f(0.12, -0.73, 0.0);
	glVertex3f(0.09, -0.74, 0.0);

	//face 6
	glVertex3f(0.1, -0.69, 0.1);
	glVertex3f(0.13, -0.69, 0.1);
	glVertex3f(0.12, -0.73, 0.1);
	glVertex3f(0.09, -0.74, 0.1);

	//second
	//face 1
	glVertex3f(0.09, -0.74, 0.0);
	glVertex3f(0.12, -0.73, 0.0);
	glVertex3f(0.14, -0.76, 0.0);
	glVertex3f(0.11, -0.78, 0.0);

	//face 2
	glVertex3f(0.11, -0.78, 0.1);
	glVertex3f(0.09, -0.74, 0.1);
	glVertex3f(0.09, -0.74, 0.0);
	glVertex3f(0.11, -0.78, 0.0);

	//face 3
	glVertex3f(0.09, -0.74, 0.1);
	glVertex3f(0.12, -0.73, 0.1);
	glVertex3f(0.12, -0.73, 0.0);
	glVertex3f(0.09, -0.74, 0.0);

	//face 4
	glVertex3f(0.14, -0.76, 0.1);
	glVertex3f(0.12, -0.73, 0.1);
	glVertex3f(0.12, -0.73, 0.0);
	glVertex3f(0.14, -0.76, 0.0);

	//face 5
	glVertex3f(0.11, -0.78, 0.1);
	glVertex3f(0.14, -0.76, 0.1);
	glVertex3f(0.14, -0.76, 0.0);
	glVertex3f(0.11, -0.78, 0.0);

	//face 6
	glVertex3f(0.09, -0.74, 0.1);
	glVertex3f(0.12, -0.73, 0.1);
	glVertex3f(0.14, -0.76, 0.1);
	glVertex3f(0.11, -0.78, 0.1);

	//third
	//face 1
	glVertex3f(0.11, -0.78, 0.0);
	glVertex3f(0.14, -0.76, 0.0);
	glVertex3f(0.16, -0.8, 0.0);
	glVertex3f(0.14, -0.82, 0.0);

	//face 2
	glVertex3f(0.14, -0.82, 0.1);
	glVertex3f(0.11, -0.78, 0.1);
	glVertex3f(0.11, -0.78, 0.0);
	glVertex3f(0.14, -0.82, 0.0);

	//face 3
	glVertex3f(0.11, -0.78, 0.1);
	glVertex3f(0.14, -0.76, 0.1);
	glVertex3f(0.14, -0.76, 0.0);
	glVertex3f(0.11, -0.78, 0.0);

	//face 4
	glVertex3f(0.16, -0.8, 0.1);
	glVertex3f(0.14, -0.76, 0.1);
	glVertex3f(0.14, -0.76, 0.0);
	glVertex3f(0.16, -0.8, 0.0);

	//face 5
	glVertex3f(0.14, -0.82, 0.1);
	glVertex3f(0.16, -0.8, 0.1);
	glVertex3f(0.16, -0.8, 0.0);
	glVertex3f(0.14, -0.82, 0.0);

	//face 6
	glVertex3f(0.11, -0.78, 0.1);
	glVertex3f(0.14, -0.76, 0.1);
	glVertex3f(0.16, -0.8, 0.1);
	glVertex3f(0.14, -0.82, 0.1);
	glEnd();
}

void drawFingers2() {
	glBegin(GL_QUADS);
	//thumb
	//first - face 1
	glVertex3f(0.16, -0.69, 0.0);
	glVertex3f(0.2, -0.68, 0.0);
	glVertex3f(0.22, -0.73, 0.0);
	glVertex3f(0.19, -0.72, 0.0);

	//face 2
	glVertex3f(0.19, -0.72, 0.1);
	glVertex3f(0.16, -0.69, 0.1);
	glVertex3f(0.16, -0.69, 0.0);
	glVertex3f(0.19, -0.72, 0.0);

	//face 3
	glVertex3f(0.16, -0.69, 0.1);
	glVertex3f(0.2, -0.68, 0.1);
	glVertex3f(0.2, -0.68, 0.0);
	glVertex3f(0.16, -0.69, 0.0);

	//face 4
	glVertex3f(0.22, -0.73, 0.1);
	glVertex3f(0.2, -0.68, 0.1);
	glVertex3f(0.2, -0.68, 0.0);
	glVertex3f(0.22, -0.73, 0.0);

	//face 5
	glVertex3f(0.19, -0.72, 0.1);
	glVertex3f(0.22, -0.73, 0.1);
	glVertex3f(0.22, -0.73, 0.0);
	glVertex3f(0.19, -0.72, 0.0);

	//face 6
	glVertex3f(0.16, -0.69, 0.1);
	glVertex3f(0.2, -0.68, 0.1);
	glVertex3f(0.22, -0.73, 0.1);
	glVertex3f(0.19, -0.72, 0.1);

	//second - face 1
	glVertex3f(0.19, -0.72, 0.0);
	glVertex3f(0.22, -0.73, 0.0);
	glVertex3f(0.19, -0.8, 0.0);
	glVertex3f(0.16, -0.77, 0.0);

	//face 2
	glVertex3f(0.16, -0.77, 0.1);
	glVertex3f(0.19, -0.72, 0.1);
	glVertex3f(0.19, -0.72, 0.0);
	glVertex3f(0.16, -0.77, 0.0);

	//face 3
	glVertex3f(0.19, -0.72, 0.1);
	glVertex3f(0.22, -0.73, 0.1);
	glVertex3f(0.22, -0.73, 0.0);
	glVertex3f(0.19, -0.72, 0.0);

	//face 4
	glVertex3f(0.19, -0.8, 0.1);
	glVertex3f(0.22, -0.73, 0.1);
	glVertex3f(0.22, -0.73, 0.0);
	glVertex3f(0.19, -0.8, 0.0);

	//face 5
	glVertex3f(0.16, -0.77, 0.1);
	glVertex3f(0.19, -0.8, 0.1);
	glVertex3f(0.19, -0.8, 0.0);
	glVertex3f(0.16, -0.77, 0.0);

	//face 6
	glVertex3f(0.19, -0.72, 0.1);
	glVertex3f(0.22, -0.73, 0.1);
	glVertex3f(0.19, -0.8, 0.1);
	glVertex3f(0.16, -0.77, 0.1);
	glEnd();
}


void robotHand() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	drawShoulderArm();
	drawHand();
	drawFingers2();
	glPushMatrix();
	glRotatef(fingerRotationAngle, 0.0, 0.0, 1.0);
	drawFingers();
	glPopMatrix();
	drawArm2();

	glScalef(-1, 1, 1);
	glTranslatef(0.4, 0.0, 0.0);
	drawShoulderArm();
	drawHand();
	drawFingers2();
	glPushMatrix();
	glRotatef(fingerRotationAngle, 0.0, 0.0, 1.0);
	drawFingers();
	glPopMatrix();
	drawArm2();

	//glPushMatrix();
	//glRotatef(180.0, 0.0, 0.0, 1.0); // Rotate the entire arm assembly by 180 degrees around the Z-axis

	//glTranslatef(0.0, -0.6, 0.0); // Translate down along y-axis
	//glRotatef(r2, 1.0, 0.0, 0.0); // Rotate about x-axis
	//drawArm(0.2, 0.6, 0.2); // Bottom arm

	//glPushMatrix();
	//glTranslatef(0.0, 0.6, 0.0); // Translate up along y-axis
	//glRotatef(r1, 0.0, 0.0, 1.0); // Rotate about z-axis
	//drawArm(0.2, 0.6, 0.2); // Top arm
	//glPopMatrix();
	//glPopMatrix();

}


void display()
{

	//glRotatef(0.01, 1.0, 1.0, 1.0);	//rotate in all axis

	switch (qNo) {
	case 1:
		robotHand();
		break;

	default:
		robotHand();
		break;
	}
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
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 800,
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