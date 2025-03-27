
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#define M_PI 3.14159265358979323846


#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "OpenGL Window"

float angle = 0;
float rx = 0;
float ry = 0;
float icecreamrotate = 0;
float angleLegMov = 0;
float leftangleLegMov = 0;
float tyLegMov = 0;

float tx = 0, tz = 0, tSpeed = 0.1;		//tx and tz for modelview with tSpeed
float ty = 0;
bool isOrtho = true;					//is Ortho view?
float ONear = 0.1;					//Ortho Near
float OFar = 1.0;						//Ortho Far
float PNear = 1;						//Perspective near
float PFar = 60.0;						//Perspective far
float ptx = 0, pty = 0, ptSpeed = 0.1;	//tx and ty for projection with ptspeed
float pRy = 0, pRSpeed = 1.0;			//Ry for projection with pRSpeed
float tzWalk = 0;
int count = 0;
int count2 = 0;
int count3 = 0;
float moveFront = true;
float moveFront2 = true;
float attack = true;
float flySword = true;
float rxLeg = 1.0;
float tyLeg = 0;
float tzLeg = 0;
float tzWeapon = 0;

float rxHead = 0;
float ryHead = 0;

float shoulderRxHand = 0.0;
float shoulderRyHand = 0.0;
float shoulderRzHand = 0.0;
float arm2RxHand = 0.0;
float arm2RyHand = 0.0;
float arm2RzHand = 0.0;
float handRxHand = 0.0;
float handRyHand = 0.0;
float handRzHand = 0.0;
float fingerRxHand = 0.0;
float fingerRyHand = 0.0;
float fingerRzHand = 0.0;
float finger2RxHand = 0.0;
float finger2RyHand = 0.0;
float finger2RzHand = 0.0;

float angleHandMov = 0.0;
float angleHeadMov = 0.0;
float leftshoulderRxHand = 0.0;
float leftshoulderRyHand = 0.0;
float leftshoulderRzHand = 0.0;
float leftarm2RxHand = 0.0;
float leftarm2RyHand = 0.0;
float leftarm2RzHand = 0.0;
float lefthandRxHand = 0.0;
float lefthandRyHand = 0.0;
float lefthandRzHand = 0.0;
float leftfingerRxHand = 0.0;
float leftfingerRyHand = 0.0;
float leftfingerRzHand = 0.0;
float leftfinger2RxHand = 0.0;
float leftfinger2RyHand = 0.0;
float leftfinger2RzHand = 0.0;
float leftangleHandMov = 0.0;

float lefttyLeg = 0;
float lefttzLeg = 0;

float fingerRotationAngle = 0.0;
float isEquip = false;
float fingerAngle = 0.0;
float fingerSpeed = 0.2;
float thumbAngle = 0.0;
float thumbSpeed = 0.2;
float maxFingerAngle = 0.6;
float minFingerAngle = -0.6;
float maxThumbAngle = 0.6;
float minThumbAngle = -0.6;

GLdouble camY = 0;

BITMAP BMP;		//bitmap structure
HBITMAP hBMP = NULL;	//bitmap handle
bool Texture = true;
bool Texture2 = false;
bool textureOnOff = true;

float lightX = 0;
float lightY = 0;
float lightZ = 0;

float red[3] = { 1.0, 0.0, 0.0 };
float grey[3] = { 0.6,0.8,1.0 };
float grey2[3] = { 0.38,0.38,0.5 };
float grey3[3] = { 0.75, 0.75, 0.5 };
float grey4[3] = { 0.5, 0.75, 0.75 };
float grey5[3] = { 0.5, 0.5, 0.75 };
float grey6[3] = { 0.35, 0.35, 0.5 };
float grey7[3] = { 0.22, 0.22, 0.5 };
float grey8[3] = { 0.4,0.4,1.0 };
float grey9[3] = { 0.3,0.3,0.5 };
float grey10[3] = { 0.25,0.25,0.25 };
float grey11[3] = { 0.15,0.15,0.15 };
float grey12[3] = { 0.13,0.13,0.13 };
float grey13[3] = { 0.37,0.37,0.37 };
float grey14[3] = { 0.88,0.88,0.5 };
float dgrey[3] = { 0.16, 0.16, 0.15 };
float hgrey[3] = { 1.0,0.7,0.4 };
float jgrey[3] = { 0.42,0.42,0.42 };
float blue[3] = { 0.2, 0.3, 0.6 };
float blue2[3] = { 0.0, 1.0, 1.0 };
float blue3[3] = { 0.5,1.0,1.0 };
float blue4[3] = { 0.1,0.2,0.5 };
float blue5[3] = { 0.11,0.11,0.11 };
float yellow[3] = { 1.0, 1.0, 0.0 };
float yellow2[3] = { 1.0,1.0,0.5 };
float pink[3] = { 1.0,0,1.0 };
float pink2[3] = { 0.0, 0.5, 1.0 };
float green[3] = { 0,0.5,0.5 };
float green2[3] = { 0.2,0.5,0.3 };
float green3[3] = { 0.1,0.3,0.3 };
float green4[3] = { 0.2,0.3,0.1 };
float green5[3] = { 0.1,0.7,0.6 };
float purple[3] = { 0.5,0.5,1.0 };

float ambL[3] = { 1.0,1.0,1.0 };  // white color ambient light
float posA[3] = { 0.0,0.8,0.0 }; //ambient light position at (0.0,0.8,0.0) (above)
float posD[3] = { lightX,lightY,lightZ };	//right side color (0.8,0.0,0.0)
float difL[3] = { 0.2,0.2,0.2 }; //white color diffuse light
float ambM[3] = { 0.0,0.0,1.0 };// blue color ambient material
float difM[3] = { 0.8,0.8,0.8 }; //red color dif material
bool isLightOn = false;
bool Rotateclockwise = true;
float degree = 90;
float radius = 1;

float cameraX = 0;
float cameraY = 0;
float cameraZ = 0;
float twist = 0;

float WINDOW_HEIGHT = 600;
float WINDOW_WIDTH = 600;

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		else if (wParam == VK_RIGHT) {
			twist += 0.5f;
		}
		else if (wParam == VK_LEFT) {
			twist -= 0.5f;
		}
		else if (wParam == VK_UP) {
			camY += 0.05f;
			if (camY >= 3) {
				camY -= 0.05f;
			}
		}
		else if (wParam == VK_DOWN) {
			camY -= 0.05f;
			if (camY <= -3) {
				camY += 0.05f;
			}
		}
		else if (wParam == 'Q') {
			cameraZ -= 1;
			if (cameraZ <= -1) {
				cameraZ += 1;
			}
		}
		else if (wParam == 'E') {
			cameraZ += 1;
			if (cameraZ >= 5) {
				cameraZ -= 1;
			}
		}
		else if (wParam == 'W') {
			count2 = 0;
			count++;
			count3 = 0;
		}
		else if (wParam == 'G') {
			isEquip = !isEquip;
		}
		else if (wParam == 'V') {
			count = 0;
			count2++;
			count3 = 0;
		}
		else if (wParam == 'B') {
			count = 0;
			count2 = 0;
			count3++;
		}
		else if (wParam == 'T') {
			angleHeadMov += 0.5;
			rxHead = 1.0;
			ryHead = 0.0;
			if (angleHeadMov >= 30) {
				angleHeadMov -= 0.5;
			}
		}
		else if (wParam == 'Y') {
			angleHeadMov -= 0.5;
			rxHead = 1.0;
			ryHead = 0.0;
			if (angleHeadMov <= -30) {
				angleHeadMov += 0.5;
			}
		}
		else if (wParam == 'N') {
			angleHeadMov += 0.5;
			rxHead = 0.0;
			ryHead = 1.0;
			if (angleHeadMov >= 45) {
				angleHeadMov -= 0.5;
			}
		}
		else if (wParam == 'M') {
			angleHeadMov -= 0.5;
			rxHead = 0.0;
			ryHead = 1.0;
			if (angleHeadMov <= -45) {
				angleHeadMov += 0.5;
			}
		}
		else if (wParam == VK_SPACE) {
			tzWalk = 0;
			count = 0;
			count2 = 0;
			count3 = 0;
			angleLegMov = 0;
			leftangleLegMov = 0;
			tyLeg = 0;
			lefttyLeg = 0;
			tzLeg = 0;
			lefttzLeg = 0;
			shoulderRxHand = 0.0;
			shoulderRzHand = 0.0;
			arm2RxHand = 0.0;
			arm2RzHand = 0.0;
			handRxHand = 0.0;
			handRzHand = 0.0;
			fingerRxHand = 0.0;
			fingerRzHand = 0.0;
			finger2RxHand = 0.0;
			finger2RzHand = 0.0;

			leftshoulderRxHand = 0.0;
			leftshoulderRzHand = 0.0;
			leftarm2RxHand = 0.0;
			leftarm2RzHand = 0.0;
			lefthandRxHand = 0.0;
			lefthandRzHand = 0.0;
			leftfingerRxHand = 0.0;
			leftfingerRzHand = 0.0;
			leftfinger2RxHand = 0.0;
			leftfinger2RzHand = 0.0;

			leftangleHandMov = 0;
			angleHandMov = 0;
			tzWeapon = 0;
			flySword = true;
			rxHead = 0;
			ryHead = 0;
			angleHeadMov = 0.0;
		}
		else if (wParam == 'I')		//press UP arrow key
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
		else if (wParam == 'K') {	//press DOWN arrow key
			if (isOrtho) {
				if (tz < OFar) {			//bondary for ortho far
					tz += tSpeed;
				}
			}
			else {
				if (tz < PFar / 2) {
					tz += tSpeed;		//bondary for perspective far
				}
			}
		}
		else if (wParam == 'J') {
			cameraX -= tSpeed;
		}
		else if (wParam == 'L') {
			cameraX += tSpeed;
		}
		else if (wParam == 'Z') {
			cameraY -= tSpeed;
		}
		else if (wParam == 'X') {
			cameraY += tSpeed;
		}
		else if (wParam == 0x31) {
			angleHandMov -= 0.2;
			shoulderRzHand = 1.0;
			arm2RzHand = 1.0;
			handRzHand = 1.0;
			fingerRzHand = 1.0;
			finger2RzHand = 1.0;
			if (angleHandMov <= -20) {
				angleHandMov += 0.2;
			}
		}
		else if (wParam == 0x32) {
			angleHandMov += 0.2;
			shoulderRzHand = 1.0;
			arm2RzHand = 1.0;
			handRzHand = 1.0;
			fingerRzHand = 1.0;
			finger2RzHand = 1.0;
			if (angleHandMov >= -2) {
				angleHandMov -= 0.2;
			}
		}
		else if (wParam == 0x33) {
			leftangleHandMov += 0.2;
			leftshoulderRzHand = 1.0;
			leftarm2RzHand = 1.0;
			lefthandRzHand = 1.0;
			leftfingerRzHand = 1.0;
			leftfinger2RzHand = 1.0;
			if (leftangleHandMov >= -2) {
				leftangleHandMov -= 0.2;
			}
		}
		else if (wParam == 0x34) {
			leftangleHandMov -= 0.2;
			leftshoulderRzHand = 1.0;
			leftarm2RzHand = 1.0;
			lefthandRzHand = 1.0;
			leftfingerRzHand = 1.0;
			leftfinger2RzHand = 1.0;
			if (leftangleHandMov <= -20) {
				leftangleHandMov += 0.2;
			}
		}
		else if (wParam == 0x35) {
			angleHandMov += 0.2;
			arm2RxHand = 1.0;
			handRxHand = 1.0;
			fingerRxHand = 1.0;
			finger2RxHand = 1.0;
			if (angleHandMov >= -2) {
				angleHandMov -= 0.2;
			}
		}
		else if (wParam == 0x36) {
			angleHandMov -= 0.2;
			arm2RxHand = 1.0;
			handRxHand = 1.0;
			fingerRxHand = 1.0;
			finger2RxHand = 1.0;
			if (angleHandMov <= -20) {
				angleHandMov += 0.2;
			}
		}
		else if (wParam == 0x37) {
			leftangleHandMov += 0.2;
			leftarm2RxHand = 1.0;
			lefthandRxHand = 1.0;
			leftfingerRxHand = 1.0;
			leftfinger2RxHand = 1.0;
			if (leftangleHandMov >= -2) {
				leftangleHandMov -= 0.2;
			}
		}
		else if (wParam == 0x38) {
			leftangleHandMov -= 0.2;
			leftarm2RxHand = 1.0;
			lefthandRxHand = 1.0;
			leftfingerRxHand = 1.0;
			leftfinger2RxHand = 1.0;
			if (leftangleHandMov <= -20) {
				leftangleHandMov += 0.2;
			}
		}
		else if (wParam == 'O') {		//press 'O' key
			isOrtho = true;
			tz = 0;
		}
		else if (wParam == 'P') {		//press 'P' key
			isOrtho = false;
			tz = PNear;
		}
		else if (wParam == 'F') {	//oprn finger
			fingerRxHand = 0.0;
			fingerRyHand = 0.0;
			fingerRzHand = 1.0;
			finger2RzHand = 0.0;
			angleHandMov -= fingerSpeed;
			if (angleHandMov <= minFingerAngle) {
				angleHandMov += fingerSpeed;
			}
		}
		else if (wParam == 'D') {	//close finger
			fingerRxHand = 0.0;
			fingerRyHand = 0.0;
			fingerRzHand = 1.0;
			finger2RzHand = 0.0;
			angleHandMov += fingerSpeed;
			if (angleHandMov >= maxFingerAngle) {
				angleHandMov -= fingerSpeed;
			}
		}
		else if (wParam == 0x39) {	//oprn finger
			leftfingerRxHand = 0.0;
			leftfingerRyHand = 0.0;
			leftfingerRzHand = 1.0;
			leftfinger2RzHand = 0.0;
			leftangleHandMov -= fingerSpeed;
			if (leftangleHandMov <= minFingerAngle) {
				leftangleHandMov += fingerSpeed;
			}
		}
		else if (wParam == 0x30) {	//open thumb
			leftfinger2RxHand = 0.0;
			leftfinger2RyHand = 0.0;
			leftfinger2RzHand = 1.0;
			leftfingerRzHand = 0.0;
			leftangleHandMov -= thumbSpeed;
			if (leftangleHandMov <= minThumbAngle) {
				leftangleHandMov += thumbSpeed;
			}
		}
		else if (wParam == 'S') {	//open waist
			handRxHand = 1.0;
			handRyHand = 0.0;
			handRzHand = 0.0;
			fingerRxHand = 1.0;
			fingerRyHand = 0.0;
			fingerRzHand = 0.0;
			finger2RxHand = 1.0;
			angleHandMov -= fingerSpeed;
			if (angleHandMov <= -10) {
				angleHandMov += fingerSpeed;
			}
			}
		else if (wParam == 'C') {	//close waist
			handRxHand = 1.0;
			handRyHand = 0.0;
			handRzHand = 0.0;
			fingerRxHand = 1.0;
			fingerRyHand = 0.0;
			fingerRzHand = 0.0;
			finger2RxHand = 1.0;
			angleHandMov += fingerSpeed;
			if (angleHandMov >= 1) {
				angleHandMov -= fingerSpeed;
			}
		}
		else if (wParam == 'R') {	//open waist
			lefthandRxHand = 1.0;
			lefthandRyHand = 0.0;
			lefthandRzHand = 0.0;
			leftfingerRxHand = 1.0;
			leftfingerRyHand = 0.0;
			leftfingerRzHand = 0.0;
			leftfinger2RxHand = 1.0;
			leftangleHandMov -= fingerSpeed;
			if (leftangleHandMov <= -10) {
				leftangleHandMov += fingerSpeed;
			}
			}
		else if (wParam == 'U') {	//close waist
			lefthandRxHand = 1.0;
			lefthandRyHand = 0.0;
			lefthandRzHand = 0.0;
			leftfinger2RxHand = 1.0;
			leftfinger2RyHand = 0.0;
			leftfinger2RzHand = 0.0;
			leftfingerRxHand = 1.0;
			leftangleHandMov += thumbSpeed;
			if (leftangleHandMov >= 1) {
				leftangleHandMov -= thumbSpeed;
			}
		}
		else if (wParam == VK_F1) {
			Texture = true;
			Texture2 = false;
		}
		else if (wParam == VK_F2) {
			Texture = false;
			Texture2 = true;
		}
		else if (wParam == VK_F3) {
			textureOnOff = !textureOnOff;
		}
		else if (wParam == VK_NUMPAD1) {
			isLightOn = !isLightOn;
		}
		else if (wParam == VK_NUMPAD2) {
			angle = 0.1;
			Rotateclockwise = true;
		}
		else if (wParam == VK_NUMPAD3) {
			angle = 0.1;
			Rotateclockwise = false;
		}
		else if (wParam == VK_NUMPAD4) {
			lightX += 0.1f;
		}
		else if (wParam == VK_NUMPAD5) {
			lightX -= 0.1f;
		}
		else if (wParam == VK_NUMPAD6) {
			lightY += 0.1f;
		}
		else if (wParam == VK_NUMPAD7) {
			lightY -= 0.1f;
		}
		else if (wParam == VK_NUMPAD8) {
			lightZ += 0.1f;
		}
		else if (wParam == VK_NUMPAD9) {
			lightZ -= 0.1f;
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
	glVertex3f(0.0f, 0.0f, size);
	glVertex3f(size, 0.0f, size);
	glVertex3f(size, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	// Face 2 
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, size, 0.0f);
	glVertex3f(0.0f, size, size);
	glVertex3f(0.0f, 0.0f, size);
	// Face 3
	glVertex3f(0.0f, 0.0f, size);
	glVertex3f(0.0f, size, size);
	glVertex3f(size, size, size);
	glVertex3f(size, 0.0f, size);
	// Face 4
	glVertex3f(size, 0.0f, size);
	glVertex3f(size, size, size);
	glVertex3f(size, size, 0.0f);
	glVertex3f(size, 0.0f, 0.0f);
	// Face 5
	glVertex3f(size, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, size, 0.0f);
	glVertex3f(size, size, 0.0f);
	// Face 6
	glVertex3f(size, size, 0.0f);
	glVertex3f(0.0f, size, 0.0f);
	glVertex3f(0.0f, size, size);
	glVertex3f(size, size, size);
	glEnd();
}

void drawSphere(double radius) {
	GLUquadricObj* sphere = NULL;		//create quadric obj pointer
	sphere = gluNewQuadric();			//create quadric obj in the memory
	gluQuadricTexture(sphere, true);	//set to use fill
	gluSphere(sphere, radius, 30, 30);
	gluDeleteQuadric(sphere);			//make sure only one object being created, memory not incrementing
}

void drawSphereLeg(GLenum obj, double radius) {
	GLUquadricObj* sphere = NULL;			//create quadric obj pointer
	sphere = gluNewQuadric();				//create quadric obj in the memory
	gluQuadricTexture(sphere, true);	//set to use line //GLU_FILL
	gluSphere(sphere, radius, 10, 10);
	gluDeleteQuadric(sphere);
}

void drawCylinder(GLenum obj, double tr, double br, double h, double n) {
	GLUquadricObj* cylinder = NULL;			//create quadric obj pointer
	cylinder = gluNewQuadric();				//create quadric obj in the memory
	gluQuadricTexture(cylinder, true);	//set to use line
	gluCylinder(cylinder, tr, br, h, n, 1);
	gluDeleteQuadric(cylinder);
}

void drawCone(GLenum obj, double br, double h, double n) {
	GLUquadricObj* cone = NULL;			//create quadric obj pointer
	cone = gluNewQuadric();				//create quadric obj in the memory
	gluQuadricTexture(cone, true);	//set to use line
	gluCylinder(cone, 0, br, h, n, 1);
	gluDeleteQuadric(cone);
}

void drawDisk(double inr, double outr) {
	GLUquadricObj* disk = NULL;			//create quadric obj pointer
	disk = gluNewQuadric();				//create quadric obj in the memory
	gluQuadricDrawStyle(disk, GLU_LINE);	//set to use line
	gluDisk(disk, inr, outr, 30, 30);
	gluDeleteQuadric(disk);
}

void drawPyramid(float size, float apexHeight) {
	float halfSize = size / 2.0;

	glLineWidth(3.0);
	glBegin(GL_POLYGON);
	// Base rectangle
	glVertex3f(-halfSize, 0.0f, -halfSize);
	glVertex3f(halfSize, 0.0f, -halfSize);
	glVertex3f(halfSize, 0.0f, halfSize);
	glVertex3f(-halfSize, 0.0f, halfSize);

	// Triangular faces
	glVertex3f(0.0f, apexHeight, 0.0f); // Apex
	glVertex3f(halfSize, 0.0f, -halfSize);
	glVertex3f(halfSize, 0.0f, halfSize);

	glVertex3f(0.0f, apexHeight, 0.0f); // Apex
	glVertex3f(halfSize, 0.0f, halfSize);
	glVertex3f(-halfSize, 0.0f, halfSize);

	glVertex3f(0.0f, apexHeight, 0.0f); // Apex
	glVertex3f(-halfSize, 0.0f, halfSize);
	glVertex3f(-halfSize, 0.0f, -halfSize);

	glVertex3f(0.0f, apexHeight, 0.0f); // Apex
	glVertex3f(-halfSize, 0.0f, -halfSize);
	glVertex3f(halfSize, 0.0f, -halfSize);
	glEnd();
}

void drawPyramid2(float size, float apexHeight) {
	float halfSize = size / 2.0;
	float halfWidth = halfSize / 2.0;

	glLineWidth(3.0);
	glBegin(GL_POLYGON);
	// Bottom diamond base
	glVertex3f(-halfWidth, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -halfSize);

	glVertex3f(0.0f, 0.0f, -halfSize);
	glVertex3f(halfWidth, 0.0f, 0.0f);

	glVertex3f(halfWidth, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, halfSize);

	glVertex3f(0.0f, 0.0f, halfSize);
	glVertex3f(-halfWidth, 0.0f, 0.0f);

	// Triangular faces
	glVertex3f(0.0f, apexHeight, 0.0f); // Apex
	glVertex3f(-halfWidth, 0.0f, 0.0f);

	glVertex3f(0.0f, apexHeight, 0.0f); // Apex
	glVertex3f(0.0f, 0.0f, -halfSize);

	glVertex3f(0.0f, apexHeight, 0.0f); // Apex
	glVertex3f(halfWidth, 0.0f, 0.0f);

	glVertex3f(0.0f, apexHeight, 0.0f); // Apex
	glVertex3f(0.0f, 0.0f, halfSize);
	glEnd();
}

void drawSphereWithoutGLU(GLfloat radius, GLenum obj)
{
	const float PI = 3.141592f;
	GLfloat x, y, z, sliceA, stackA;
	int sliceNo = 30, stackNo = 30;

	for (sliceA = 0.0; sliceA < PI; sliceA += PI / sliceNo)
	{
		glBegin(obj);
		//glBegin(GL_POLYGON);
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

void buildCube(GLenum obj, float orginX, float orginY, float orginZ, float width, float height, float depth) {
	float x1 = orginX + width / 2.0, x2 = orginX - width / 2.0;
	float y1 = orginY + height / 2.0, y2 = orginY - height / 2.0;
	float z1 = orginZ + depth / 2.0, z2 = orginZ - depth / 2.0;

	glBegin(obj);
	// 1st Quads : left
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y2, z1);
	glVertex3f(x1, y2, z2);
	glVertex3f(x1, y1, z2);

	//3rd Quads : back
	glVertex3f(x1, y1, z2);
	glVertex3f(x1, y2, z2);
	glVertex3f(x2, y2, z2);
	glVertex3f(x2, y1, z2);

	//4th Quads : bottom
	glVertex3f(x2, y1, z2);
	glVertex3f(x2, y1, z1);
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y1, z2);

	//5th Quads : right
	glVertex3f(x2, y1, z2);
	glVertex3f(x2, y1, z1);
	glVertex3f(x2, y2, z1);
	glVertex3f(x2, y2, z2);

	//2nd Quads : top
	glVertex3f(x2, y2, z2);
	glVertex3f(x1, y2, z2);
	glVertex3f(x1, y2, z1);
	glVertex3f(x2, y2, z1);

	//6th Quads : front
	glVertex3f(x2, y2, z1);
	glVertex3f(x2, y1, z1);
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y2, z1);


	glEnd();
}

void buildCubeSide(GLenum obj, float orginX, float orginY, float orginZ, float width, float height, float depth) {
	float x1 = orginX + width / 2.0, x2 = orginX - width / 2.0;
	float y1 = orginY, y2 = orginY - height;
	float z1 = orginZ + depth / 2.0, z2 = orginZ - depth / 2.0;

	glBegin(obj);
	// 1st Quads : left
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y2, z1);
	glVertex3f(x1, y2, z2);
	glVertex3f(x1, y1, z2);

	//3rd Quads : back
	glVertex3f(x1, y1, z2);
	glVertex3f(x1, y2, z2);
	glVertex3f(x2, y2, z2);
	glVertex3f(x2, y1, z2);

	//4th Quads : bottom
	glVertex3f(x2, y1, z2);
	glVertex3f(x2, y1, z1);
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y1, z2);

	//5th Quads : right
	glVertex3f(x2, y1, z2);
	glVertex3f(x2, y1, z1);
	glVertex3f(x2, y2, z1);
	glVertex3f(x2, y2, z2);

	//2nd Quads : top
	glVertex3f(x2, y2, z2);
	glVertex3f(x1, y2, z2);
	glVertex3f(x1, y2, z1);
	glVertex3f(x2, y2, z1);

	//6th Quads : front
	glVertex3f(x2, y2, z1);
	glVertex3f(x2, y1, z1);
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y2, z1);

	glEnd();
}

void drawArm(GLenum obj, float x, float y, float z) {
	glBegin(obj);
	// Face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.0, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, 0.0, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, 0.0, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.0, 0.0);

	// Face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.0, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, 0.0, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, y, z);

	//Face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, y, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, y, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y, 0.0); 
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);

	//Face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, 0.0, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, 0.0, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, 0.0);

	//Face 
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, y, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, 0.0, 0.0);

	// Face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, y, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, y, z);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.0, z);
	glEnd();
}

void draw_cylinder(GLfloat radius, GLfloat height, int slices) {
	GLfloat bend_angle = 3 * height;
	GLfloat bend_ang0 = -bend_angle / 2.0f;
	GLfloat bend_ang1 = bend_angle / 2.0f;

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= slices; i++) {
		GLfloat w0 = (GLfloat)i / (GLfloat)slices;
		GLfloat w1 = (GLfloat)(i + 1) / (GLfloat)slices;

		GLfloat ang0 = bend_ang0 + (bend_ang1 - bend_ang0) * w0;
		GLfloat ang1 = bend_ang0 + (bend_ang1 - bend_ang0) * w1;

		for (int j = 0; j <= 360; ++j) {
			GLfloat angle = M_PI * (GLfloat)j / 180.0f;
			GLfloat x = radius * cos(angle) + 3;
			GLfloat y = radius * sin(angle);

			GLfloat xb = sin(ang0) * x;
			GLfloat yb = y;
			GLfloat zb = cos(ang0) * x;
			glVertex3f(xb, yb, zb);

			xb = sin(ang1) * x;
			yb = y;
			zb = cos(ang1) * x;
			glVertex3f(xb, yb, zb);
		}
	}
	glEnd();
}

void ptrianglePoly() {
	glBegin(GL_QUADS);
	glVertex3f(-0.4, 0.6, 0.0);
	glVertex3f(-0.4, -0.4, 0.0);
	glVertex3f(0.2, -0.6, 0.15);
	glVertex3f(0.2, 0.4, 0.15);

	glVertex3f(-0.4, 0.6, 0.3);
	glVertex3f(-0.4, -0.4, 0.3);
	glVertex3f(0.2, -0.6, 0.15);
	glVertex3f(0.2, 0.4, 0.15);

	glVertex3f(-0.4, 0.6, 0.0);
	glVertex3f(-0.4, -0.4, 0.0);
	glVertex3f(-0.4, -0.4, 0.3);
	glVertex3f(-0.4, 0.6, 0.3);

	glVertex3f(0.2, 0.4, 0.15);
	glVertex3f(-0.4, 0.6, 0.0);
	glVertex3f(-0.4, 0.6, 0.3);

	glVertex3f(0.2, -0.6, 0.15);
	glVertex3f(-0.4, -0.4, 0.3);
	glVertex3f(-0.4, -0.4, 0);
	glEnd();
}

void drawCylinder2(GLenum obj, double tr, double br, double h, double n) {
	GLUquadricObj* cylinder = gluNewQuadric(); // create quadric obj pointer
	gluQuadricDrawStyle(cylinder, obj);        // set to use line
	gluCylinder(cylinder, tr, br, h, n, 1);    // draw the sides

	// Draw top disk
	gluQuadricOrientation(cylinder, GLU_INSIDE);
	gluDisk(cylinder, 0, tr, n, 1);

	// Draw bottom disk
	glPushMatrix();
	glTranslatef(0.0, 0.0, h); // Move to the bottom
	gluQuadricOrientation(cylinder, GLU_OUTSIDE);
	gluDisk(cylinder, 0, br, n, 1);
	glPopMatrix();

	gluDeleteQuadric(cylinder);
}

void drawSphereWeapon(GLenum obj, double radius) {
	GLUquadricObj* sphere = NULL;			//create quadric obj pointer
	sphere = gluNewQuadric();				//create quadric obj in the memory
	gluQuadricDrawStyle(sphere, obj);	//set to use line //GLU_FILL
	gluSphere(sphere, radius, 10, 10);
	gluDeleteQuadric(sphere);
}

void recBox(GLenum obj, float size, float h) {
	glColor3f(0.54, 0.54, 0.54);
	glBegin(obj);
	// Face 1 
	glVertex3f(0.0f, 0.0f, size / 2);
	glVertex3f(-size, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, size / 2);
	glVertex3f(size, 0.0f, 0.0f);
	// Face 2 
	glVertex3f(0.0f, 0.0f, size / 2);
	glVertex3f(0.0f, h, size / 2);
	glVertex3f(size, h, 0.0f);
	glVertex3f(size, 0.0f, 0.0f);
	// Face 3
	glVertex3f(-size, 0.0f, 0.0f);
	glVertex3f(-size, h, 0.0f);
	glVertex3f(0.0f, h, size / 2);
	glVertex3f(0.0f, 0.0f, size / 2);
	// Face 4
	glVertex3f(0.0f, 0.0f, size / 2);
	glVertex3f(0.0f, h, size / 2);
	glVertex3f(size, h, 0.0f);
	glVertex3f(size, 0.0f, 0.0f);
	// Face 5
	glVertex3f(0.0f, 0.0f, size / 2);
	glVertex3f(0.0f, h, size / 2);
	glVertex3f(size, h, 0.0f);
	glVertex3f(size, 0.0f, 0.0f);
	glEnd();
}

void drawCylinderHand(GLenum obj, double tr, double br, double h, double n, double x, double y, double z) {
	GLUquadricObj* cylinder = gluNewQuadric(); // create quadric obj pointer
	gluQuadricTexture(cylinder, true);        // set to use line
	glPushMatrix(); // Save current transformation matrix
	glTranslatef(x, y, z); // Translate the cylinder to the desired position
	gluCylinder(cylinder, tr, br, h, n, 1);
	glPopMatrix(); // Restore previous transformation matrix
	gluDeleteQuadric(cylinder);
}

void weapon() {
	glPushMatrix();
	glTranslatef(0.0, 0.0, tzWalk);

	glPushMatrix();


	glScalef(0.5, 0.5, 0.5);
	glTranslatef(-0.7, 0.15, -0.25);
	glTranslatef(0.0, 0.0, tzWeapon);
	glRotatef(angleHandMov, handRxHand, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.85);
	//glRotatef(icecreamrotate, 1.0, 1.0, 1.0);

	glPushMatrix();
	//jian bing men
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.95);
	glColor3f(0.75, 0.75, 0.75);
	drawCylinder(GLU_FILL, 0.045, 0.045, 0.1, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.9);
	glColor3f(0.75, 0.75, 1);
	drawCylinder(GLU_FILL, 0.04, 0.04, 0.3, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.55);
	glColor3f(0.75, 1, 0.75);
	drawSphereLeg(GLU_FILL, 0.055);
	glPopMatrix();

	//diamond itu
	glPushMatrix();
	glScalef(1, 0.5, 1);
	glPushMatrix();
	glRotatef(270, 1, 0, 0);
	glRotatef(45, 0, 1.0, 0);
	glTranslatef(0.0, 0.4, 0.0);
	glColor3f(1, 0.75, 0.75);
	drawPyramid(0.25, 0.15);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(45, 0, 1.0, 0);
	glTranslatef(0.0, -0.4, 0.0);
	glColor3f(0.5, 0.75, 0.75);
	drawPyramid(0.25, 0.15);
	glPopMatrix();
	glPopMatrix();

	//main
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0.0, -0.3, 0.0);
	glColor3f(0.75, 0.75, 0.5);
	recBox(GL_POLYGON, 0.1, 0.65);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(180, 0, 1.0, 0);
	glTranslatef(0.0, -0.3, 0.0);
	glColor3f(0.75, 0.75, 0.5);
	recBox(GL_POLYGON, 0.1, 0.65);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1.0, 0);
	glTranslatef(0.0, 0.35, 0.0);
	glColor3f(0.5, 0.5, 0.75);
	drawPyramid2(0.2, 0.3);
	glPopMatrix();

	//main middle rectangle + up pyramid
	glPushMatrix();
	glRotatef(180, 0, 1.0, 0);
	glRotatef(45, 0, 0, 1);
	glTranslatef(-0.055, -0.05, -0.3);
	glColor3f(0.75, 0.5, 0.5);
	drawArm(GL_POLYGON, 0.12, 0.12, 0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.2);
	glRotatef(-90, 1, 0, 0);
	glRotatef(45, 0, 1, 0);
	glColor3f(0.75, 0.5, 0.5);
	drawPyramid(0.1, 0.12);
	glPopMatrix();

	//jian jian
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glRotatef(90, 0, 1.0, 0);
	glTranslatef(0.0, -0.55, 0.0);
	glColor3f(0.5, 0.5, 0.75);
	drawPyramid2(0.2, 0.3);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1.0, 0);
	glTranslatef(0.0, 0.55, 0.0);
	glColor3f(0.5, 0.5, 0.75);
	drawPyramid2(0.2, 0.4);
	glPopMatrix();

	glPopMatrix();
	icecreamrotate += 0.01;
	glPopMatrix();
	glPopMatrix();
}

void rightbigLeg() {
	glPushMatrix();
	glRotatef(angleLegMov, rxLeg, 0.0, 0.0);
	glTranslatef(0.0, tyLegMov, 0.0);

	glPushMatrix();
	glRotatef(180, 0.0, 1.0, 0.0);

	glPushMatrix();
	glRotatef(angle, rx, ry, 0.0);
	glScalef(0.6, 0.6, 0.6);
	glTranslatef(0.2, -0.5, 0.15);

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(-0.2, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(0.3, 0, -0.52);
	glRotatef(90, 0, 0, 1);
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	glTranslatef(0.0, 0.0, -0.15);
	//up small rectangle
	glPushMatrix();
	glRotatef(-75, 1, 0, 0);
	glTranslatef(-0.09, 0.03, -0.1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_LINE_LOOP, 0.18, 0.07, 0.2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.18, 0.07, 0.2);
	glPopMatrix();
	//bigleg up up
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.1);
	drawCylinder(GLU_FILL, 0.08, 0.1, 0.1, 6);
	glPopMatrix();
	//bigleg upper
	drawCylinder(GLU_FILL, 0.1, 0.1, 0.2, 6);
	//bigleg
	glPopMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.1, 0.1, 0.35, 6);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glLineWidth(2.0);
	drawCylinder(GLU_LINE, 0.1, 0.1, 0.35, 6);
	//connect up and middle
	glPushMatrix();
	glRotatef(180, 1, 0, 0);
	glTranslatef(0.0, 0.0, -0.47);
	glLineWidth(2.0);
	drawCylinder(GLU_LINE, 0.07, 0.1, 0.12, 6);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.07, 0.1, 0.12, 6);
	glPopMatrix();
	//pipi
	glPushMatrix();
	glTranslatef(0.06, 0.0, -0.05);
	drawSphereLeg(GLU_FILL, 0.10);
	glPopMatrix();
	//bigleg side oval shape 
	glPushMatrix();
	glTranslatef(0, -0.07, 0.1);
	glScalef(0.2, 0.25, 1.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawSphereLeg(GLU_LINE, 0.25);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawSphereLeg(GLU_FILL, 0.25);
	glPopMatrix();
	//small box infront
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(-0.1, 0.15, -0.05);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_LINE_LOOP, 0.12, 0.05, 0.1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.12, 0.05, 0.1);
	glPopMatrix();
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(-0.1, 0.15, -0.03);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_LINE_LOOP, 0.1, 0.05, 0.06);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.1, 0.05, 0.06);
	glPopMatrix();
	//rectangle pipe
	glPushMatrix();
	glRotatef(15, 1, 0, 0);
	glTranslatef(-0.09, 0, -0.05);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_LINE_LOOP, 0.02, 0.02, 0.2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.02, 0.02, 0.2);
	glPopMatrix();
	glPushMatrix();
	glRotatef(20, 1, 0, 0);
	glTranslatef(-0.09, -0.06, -0.23);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_LINE_LOOP, 0.02, 0.02, 0.23);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.02, 0.02, 0.23);
	glPopMatrix();
	glPushMatrix();
	glRotatef(-20, 1, 0, 0);
	glTranslatef(-0.09, 0.03, -0.11);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_LINE_LOOP, 0.02, 0.02, 0.08);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.02, 0.02, 0.08);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	for (int i = 0; i < count; i++) {
		if (moveFront == true) {
			angleLegMov -= 0.12;
			angleHandMov -= 0.1;
			shoulderRxHand = -1.0;
			arm2RxHand = -1.0;
			handRxHand = -1.0;
			fingerRxHand = -1.0;
			finger2RxHand = -1.0;
			tyLeg += 0.00004;
			tzLeg += 0.0005;
			tzWeapon -= 0.0023;
		}
		else {
			angleLegMov += 0.12;
			angleHandMov += 0.1;
			shoulderRxHand = -1.0;
			arm2RxHand = -1.0;
			handRxHand = -1.0;
			fingerRxHand = -1.0;
			finger2RxHand = -1.0;
			tyLeg -= 0.00004;
			tzLeg -= 0.0005;
			tzWeapon += 0.0023;
		}
		if (angleLegMov <= -20 || angleLegMov >= 20) {
			moveFront = !moveFront;
		}
	}
}

void rightsmallLeg() {
	glPushMatrix();
	glTranslatef(0.0, tyLeg, tzLeg);

	glPushMatrix();
	glRotatef(180, 0.0, 1.0, 0.0);

	glPushMatrix();
	glRotatef(angle, rx, ry, 0.0);
	glScalef(0.6, 0.6, 0.6);
	glTranslatef(0.2, -0.42, 0.15);

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(-0.2, 0.0, 0.0);
	//xi gai sphere
	glPushMatrix();
	glTranslatef(0.3, 0, -0.03);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawSphereLeg(GLU_FILL, 0.07);
	glPopMatrix();
	//xi gai smallsphere
	glPushMatrix();
	glTranslatef(0.3, 0, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawSphereLeg(GLU_FILL, 0.06);
	glPopMatrix();
	//xi gai gebi
	glPushMatrix();
	glTranslatef(0.36, 0, 0.32);
	glRotatef(2, 0, 1, 0);
	glScalef(0.2, 0.25, 1.0); glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]); 
	drawSphereLeg(GLU_FILL, 0.28);
	glPopMatrix();
	//thin thin upper
	glPushMatrix();
	glTranslatef(0.3, 0, 0.04);
	glRotatef(-90, 0, 0, 1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawCylinder(GLU_LINE, 0.05, 0.06, 0.06, 6);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.05, 0.06, 0.06, 6);
	glPopMatrix();
	//xi gai na ge circle
	glPushMatrix();
	glTranslatef(0.27, -0.05, 0.06);
	glRotatef(-72, 1, 0, 0);
	glRotatef(20, 0, 1, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawCylinder(GLU_FILL, 0.02, 0.02, 0.02, 6);
	glPopMatrix();
	//middle thin thin that one
	glPushMatrix();
	glTranslatef(0.3, 0, 0.1);
	glRotatef(-90, 0, 0, 1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawCylinder(GLU_FILL, 0.06, 0.06, 0.02, 30);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.06, 0.06, 0.02, 30);
	glPopMatrix();
	//circle shang mian na ge 
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glTranslatef(0.3, 0, 0.15);
	glRotatef(-90, 0, 0, 1);
	drawCylinder(GLU_LINE, 0.06, 0.07, 0.05, 6);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.06, 0.07, 0.05, 6);
	glPopMatrix();
	//circle shang mian shang mian na ge cylinder
	glPushMatrix();
	glTranslatef(0.3, 0, 0.1);
	glRotatef(-90, 0, 0, 1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.06, 0.06, 0.05, 30);
	glPopMatrix();
	//xiaotui main
	glPushMatrix();
	glRotatef(-90, 0, 0, 1);
	glTranslatef(0, 0.3, 0.2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.07, 0.07, 0.4, 6);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glLineWidth(2.0);
	drawCylinder(GLU_LINE, 0.07, 0.07, 0.4, 6);
	glPushMatrix();
	glTranslatef(0, 0.03, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, dgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, dgrey);
	glColor3f(dgrey[0], dgrey[1], dgrey[2]);
	drawCylinder(GLU_FILL, 0.05, 0.07, 0.4, 30);
	glPopMatrix();
	glPopMatrix();
	//connect middle & jiao ban
	glPushMatrix();
	glTranslatef(0.3, 0, 0.6);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.07, 0.09, 0.12, 8);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawCylinder(GLU_LINE, 0.07, 0.09, 0.12, 8);
	glPopMatrix();
	//pipe na ge
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0.25, 0, -3.1);
	glScalef(0.3, 0.3, 1);
	draw_cylinder(0.02, 0.2, 20);
	glPopMatrix();
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0.5, 0, -0.21);
	glScalef(0.3, 0.3, 1);
	draw_cylinder(0.02, 0.2, 10);
	glPopMatrix();
	//side small triangle
	glPushMatrix();
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0.5, 0, -0.45);
	drawCone(GLU_FILL, 0.06, 0.12, 10);
	glPopMatrix();
	//zhong jian circle
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glLineWidth(2.0);
	glTranslatef(0.3, -0.25, -0.08);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawCylinder(GLU_LINE, 0.04, 0.04, 0.02, 30);
	drawCylinder(GLU_LINE, 0.02, 0.02, 0.02, 30);
	glPopMatrix();
	//back circle
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glLineWidth(2.0);
	glTranslatef(0.3, -0.035, 0.03);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawCylinder(GLU_LINE, 0.05, 0.05, 0.02, 30);
	drawCylinder(GLU_LINE, 0.03, 0.03, 0.02, 30);
	glPopMatrix();
	//side(got pipe that one)
	glPushMatrix();
	glTranslatef(0.25, 0, 0.07);
	glRotatef(3, 0, 1, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawCylinder(GLU_FILL, 0.05, 0.05, 0.53, 30);
	glPopMatrix();
	//side tut chu lai
	glPushMatrix();
	glTranslatef(0.18, 0, 0.1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_POLYGON, 0.05, 0.05, 0.06);
	glPopMatrix();
	//side upper tut chu lai (pipe side
	glPushMatrix();
	glTranslatef(0.18, 0, 0.05);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_POLYGON, 0.07, 0.03, 0.03);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

}

void rightjiaoban() {
	glPushMatrix();
	glTranslatef(0.0, tyLeg, tzLeg);

	glPushMatrix();
	glRotatef(180, 0.0, 1.0, 0.0);

	glPushMatrix();
	glRotatef(angle, rx, ry, 0.0);
	glScalef(0.6, 0.6, 0.6);
	glTranslatef(0.2, -0.42, 0.15);

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(-0.2, 0.0, 0.0);
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0.3, 0.0, 0.7);
	glRotatef(20, 1, 0, 0);
	glRotatef(70, 0, 0, 1);
	glLineWidth(2.0);
	//jiao ban up
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.1, 0.12, 0.1, 8);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glLineWidth(3.0);
	drawCylinder(GLU_LINE, 0.1, 0.12, 0.1, 8);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.3, -0.05, 0.75);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	//jiao ban middle
	drawCylinder(GLU_FILL, 0.1, 0.12, 0.1, 4);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glLineWidth(2.0);
	drawCylinder(GLU_LINE, 0.1, 0.12, 0.1, 4);
	glTranslatef(0, 0, 0.05);
	glPushMatrix();
	glTranslatef(0, -0.01, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	//jiao ban bottom
	drawCylinder(GLU_FILL, 0.07, 0.15, 0.1, 4);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glLineWidth(2.0);
	drawCylinder(GLU_LINE, 0.07, 0.15, 0.1, 4);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.21, -0.03, 0.72);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	//jiao gen cube
	drawArm(GL_LINE_LOOP, 0.18, 0.15, 0.18);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.18, 0.15, 0.18);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.3, 0.1, 0.9);
	glRotatef(-90, 1, 0, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	//jiao gen hemisphere
	drawSphereWithoutGLU(0.1, GL_POLYGON);
	glPopMatrix();
	//jiao zhi cube
	glPushMatrix();
	glTranslatef(0.26, -0.23, 0.87);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_LINE_LOOP, 0.08, 0.1, 0.03);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.08, 0.1, 0.03);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.25, -0.2, 0.85);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_LINE_LOOP, 0.1, 0.1, 0.05);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.1, 0.1, 0.05);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void leftbigLeg() {
	glPushMatrix();
	glRotatef(leftangleLegMov, rxLeg, 0.0, 0.0);
	glTranslatef(0.0, tyLegMov, 0.0);

	glPushMatrix();
	glRotatef(180, 0.0, 1.0, 0.0);

	glPushMatrix();
	glRotatef(angle, rx, ry, 0.0);
	glScalef(0.6, 0.6, 0.6);
	glTranslatef(0.2, -0.5, 0.15);

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glScalef(-1, 1, 1);
	glTranslatef(0.2, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.3, 0, -0.52);
	glRotatef(90, 0, 0, 1);
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	glTranslatef(0.0, 0.0, -0.15);
	//up small rectangle
	glPushMatrix();
	glRotatef(-75, 1, 0, 0);
	glTranslatef(-0.09, 0.03, -0.1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_LINE_LOOP, 0.18, 0.07, 0.2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.18, 0.07, 0.2);
	glPopMatrix();
	//bigleg up up
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.1);
	drawCylinder(GLU_FILL, 0.08, 0.1, 0.1, 6);
	glPopMatrix();
	//bigleg upper
	drawCylinder(GLU_FILL, 0.1, 0.1, 0.2, 6);
	//bigleg
	glPopMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.1, 0.1, 0.35, 6);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glLineWidth(2.0);
	drawCylinder(GLU_LINE, 0.1, 0.1, 0.35, 6);
	//connect up and middle
	glPushMatrix();
	glRotatef(180, 1, 0, 0);
	glTranslatef(0.0, 0.0, -0.47);
	glLineWidth(2.0);
	drawCylinder(GLU_LINE, 0.07, 0.1, 0.12, 6);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.07, 0.1, 0.12, 6);
	glPopMatrix();
	//pipi
	glPushMatrix();
	glTranslatef(0.06, 0.0, -0.05);
	drawSphereLeg(GLU_FILL, 0.10);
	glPopMatrix();
	//bigleg side oval shape 
	glPushMatrix();
	glTranslatef(0, -0.07, 0.1);
	glScalef(0.2, 0.25, 1.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawSphereLeg(GLU_LINE, 0.25);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawSphereLeg(GLU_FILL, 0.25);
	glPopMatrix();
	//small box infront
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(-0.1, 0.15, -0.05);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_LINE_LOOP, 0.12, 0.05, 0.1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.12, 0.05, 0.1);
	glPopMatrix();
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(-0.1, 0.15, -0.03);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_LINE_LOOP, 0.1, 0.05, 0.06);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.1, 0.05, 0.06);
	glPopMatrix();
	//rectangle pipe
	glPushMatrix();
	glRotatef(15, 1, 0, 0);
	glTranslatef(-0.09, 0, -0.05);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_LINE_LOOP, 0.02, 0.02, 0.2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.02, 0.02, 0.2);
	glPopMatrix();
	glPushMatrix();
	glRotatef(20, 1, 0, 0);
	glTranslatef(-0.09, -0.06, -0.23);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_LINE_LOOP, 0.02, 0.02, 0.23);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.02, 0.02, 0.23);
	glPopMatrix();
	glPushMatrix();
	glRotatef(-20, 1, 0, 0);
	glTranslatef(-0.09, 0.03, -0.11);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_LINE_LOOP, 0.02, 0.02, 0.08);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.02, 0.02, 0.08);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	for (int i = 0; i < count; i++) {
		if (moveFront2 == true) {
			tzWalk += 0.002;
			leftangleLegMov += 0.12;
			leftangleHandMov += 0.1;

			leftshoulderRxHand = -1.0;
			leftarm2RxHand = -1.0;
			lefthandRxHand = -1.0;
			leftfingerRxHand = -1.0;
			leftfinger2RxHand = -1.0;

			lefttyLeg -= 0.00004;
			lefttzLeg -= 0.0005;
		}
		else {
			tzWalk += 0.002;
			leftangleLegMov -= 0.12;
			leftangleHandMov -= 0.1;

			leftshoulderRxHand = -1.0;
			leftarm2RxHand = -1.0;
			lefthandRxHand = -1.0;
			leftfingerRxHand = -1.0;
			leftfinger2RxHand = -1.0;

			lefttyLeg += 0.00004;
			lefttzLeg += 0.0005;
		}
		if (leftangleLegMov <= -20 || leftangleLegMov >= 20) {
			moveFront2 = !moveFront2;
		}
	}
}

void leftsmallLeg() {
	glPushMatrix();
	glTranslatef(0.0, lefttyLeg, lefttzLeg);

	glPushMatrix();
	glRotatef(180, 0.0, 1.0, 0.0);

	glPushMatrix();
	glRotatef(angle, rx, ry, 0.0);
	glScalef(0.6, 0.6, 0.6);
	glTranslatef(0.2, -0.42, 0.15);

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glScalef(-1, 1, 1);
	glTranslatef(0.2, 0.0, 0.0);
	//xi gai sphere
	glPushMatrix();
	glTranslatef(0.3, 0, -0.03);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawSphereLeg(GLU_FILL, 0.07);
	glPopMatrix();
	//xi gai smallsphere
	glPushMatrix();
	glTranslatef(0.3, 0, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawSphereLeg(GLU_FILL, 0.06);
	glPopMatrix();
	//xi gai gebi
	glPushMatrix();
	glTranslatef(0.36, 0, 0.32);
	glRotatef(2, 0, 1, 0);
	glScalef(0.2, 0.25, 1.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawSphereLeg(GLU_FILL, 0.28);
	glPopMatrix();
	//thin thin upper
	glPushMatrix();
	glTranslatef(0.3, 0, 0.04);
	glRotatef(-90, 0, 0, 1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawCylinder(GLU_LINE, 0.05, 0.06, 0.06, 6);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.05, 0.06, 0.06, 6);
	glPopMatrix();
	//xi gai na ge circle
	glPushMatrix();
	glTranslatef(0.27, -0.05, 0.06);
	glRotatef(-72, 1, 0, 0);
	glRotatef(20, 0, 1, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawCylinder(GLU_FILL, 0.02, 0.02, 0.02, 6);
	glPopMatrix();
	//middle thin thin that one
	glPushMatrix();
	glTranslatef(0.3, 0, 0.1);
	glRotatef(-90, 0, 0, 1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawCylinder(GLU_FILL, 0.06, 0.06, 0.02, 30);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.06, 0.06, 0.02, 30);
	glPopMatrix();
	//circle shang mian na ge 
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glTranslatef(0.3, 0, 0.15);
	glRotatef(-90, 0, 0, 1);
	drawCylinder(GLU_LINE, 0.06, 0.07, 0.05, 6);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.06, 0.07, 0.05, 6);
	glPopMatrix();
	//circle shang mian shang mian na ge cylinder
	glPushMatrix();
	glTranslatef(0.3, 0, 0.1);
	glRotatef(-90, 0, 0, 1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.06, 0.06, 0.05, 30);
	glPopMatrix();
	//xiaotui main
	glPushMatrix();
	glRotatef(-90, 0, 0, 1);
	glTranslatef(0, 0.3, 0.2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.07, 0.07, 0.4, 6);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glLineWidth(2.0);
	drawCylinder(GLU_LINE, 0.07, 0.07, 0.4, 6);
	glPushMatrix();
	glTranslatef(0, 0.03, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, dgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, dgrey);
	glColor3f(dgrey[0], dgrey[1], dgrey[2]);
	drawCylinder(GLU_FILL, 0.05, 0.07, 0.4, 30);
	glPopMatrix();
	glPopMatrix();
	//connect middle & jiao ban
	glPushMatrix();
	glTranslatef(0.3, 0, 0.6);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.07, 0.09, 0.12, 8);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawCylinder(GLU_LINE, 0.07, 0.09, 0.12, 8);
	glPopMatrix();
	//pipe na ge
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0.25, 0, -3.1);
	glScalef(0.3, 0.3, 1);
	draw_cylinder(0.02, 0.2, 20);
	glPopMatrix();
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0.5, 0, -0.21);
	glScalef(0.3, 0.3, 1);
	draw_cylinder(0.02, 0.2, 10);
	glPopMatrix();
	//side small triangle
	glPushMatrix();
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0.5, 0, -0.45);
	drawCone(GLU_FILL, 0.06, 0.12, 10);
	glPopMatrix();
	//zhong jian circle
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glLineWidth(2.0);
	glTranslatef(0.3, -0.25, -0.08);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawCylinder(GLU_LINE, 0.04, 0.04, 0.02, 30);
	drawCylinder(GLU_LINE, 0.02, 0.02, 0.02, 30);
	glPopMatrix();
	//back circle
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glLineWidth(2.0);
	glTranslatef(0.3, -0.035, 0.03);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawCylinder(GLU_LINE, 0.05, 0.05, 0.02, 30);
	drawCylinder(GLU_LINE, 0.03, 0.03, 0.02, 30);
	glPopMatrix();
	//side(got pipe that one)
	glPushMatrix();
	glTranslatef(0.25, 0, 0.07);
	glRotatef(3, 0, 1, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawCylinder(GLU_FILL, 0.05, 0.05, 0.53, 30);
	glPopMatrix();
	//side tut chu lai
	glPushMatrix();
	glTranslatef(0.18, 0, 0.1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_POLYGON, 0.05, 0.05, 0.06);
	glPopMatrix();
	//side upper tut chu lai (pipe side
	glPushMatrix();
	glTranslatef(0.18, 0, 0.05);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_POLYGON, 0.07, 0.03, 0.03);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void leftjiaoban() {
	glPushMatrix();
	glTranslatef(0.0, lefttyLeg, lefttzLeg);
	glPushMatrix();
	glRotatef(180, 0, 1.0, 0);

	glPushMatrix();
	glRotatef(angle, rx, ry, 0.0);
	glScalef(0.6, 0.6, 0.6);
	glTranslatef(0.2, -0.42, 0.15);

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glScalef(-1, 1, 1);
	glTranslatef(0.2, 0.0, 0.0);
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0.3, 0.0, 0.7);
	glRotatef(20, 1, 0, 0);
	glRotatef(70, 0, 0, 1);
	glLineWidth(2.0);
	//jiao ban up
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawCylinder(GLU_FILL, 0.1, 0.12, 0.1, 8);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glLineWidth(3.0);
	drawCylinder(GLU_LINE, 0.1, 0.12, 0.1, 8);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.3, -0.05, 0.75);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	//jiao ban middle
	drawCylinder(GLU_FILL, 0.1, 0.12, 0.1, 4);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glLineWidth(2.0);
	drawCylinder(GLU_LINE, 0.1, 0.12, 0.1, 4);
	glTranslatef(0, 0, 0.05);
	glPushMatrix();
	glTranslatef(0, -0.01, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	//jiao ban bottom
	drawCylinder(GLU_FILL, 0.07, 0.15, 0.1, 4);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glLineWidth(2.0);
	drawCylinder(GLU_LINE, 0.07, 0.15, 0.1, 4);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.21, -0.03, 0.72);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	//jiao gen cube
	drawArm(GL_LINE_LOOP, 0.18, 0.15, 0.18);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.18, 0.15, 0.18);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.3, 0.1, 0.9);
	glRotatef(-90, 1, 0, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	//jiao gen hemisphere
	drawSphereWithoutGLU(0.1, GL_POLYGON);
	glPopMatrix();
	//jiao zhi cube
	glPushMatrix();
	glTranslatef(0.26, -0.23, 0.87);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_LINE_LOOP, 0.08, 0.1, 0.03);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.08, 0.1, 0.03);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.25, -0.2, 0.85);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(GL_LINE_LOOP, 0.1, 0.1, 0.05);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
	glColor3f(grey[0], grey[1], grey[2]);
	drawArm(GL_POLYGON, 0.1, 0.1, 0.05);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void leg() {
	glPushMatrix();
	glTranslatef(0.0, 0.0, tzWalk);


	rightbigLeg();
	rightsmallLeg();
	rightjiaoban();

	//this is left leg
	leftbigLeg();
	leftsmallLeg();
	leftjiaoban();

	glPopMatrix();
}

void head() {
	glPushMatrix();
	glTranslatef(0.0, 0.0, tzWalk);
	
	glPushMatrix();
	glRotatef(180, 0.0, 1.0, 0.0);

	glPushMatrix();
	glRotatef(angle, rx, ry, 0.0);

	glPushMatrix();
	glScalef(0.4, 0.4, 0.4);
	glTranslatef(0.0, 1.65, 0.0);

	//front face
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.2, 0.2, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, 0.2, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.2, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.2, -0.2, 0);
	glEnd();

	//front face details 2 triangles
	//front face details 2 triangles
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, red);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glColor3f(red[0], red[1], red[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, 0.202, -0.03);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.02, -0.03);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.0, 0.12, -0.03);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, red);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glColor3f(red[0], red[1], red[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, 0.202, -0.03);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.02, -0.03);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.0, 0.12, -0.03);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, red);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glColor3f(red[0], red[1], red[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.202, -0.03);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, 0.202, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.02, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.02, -0.03);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, red);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glColor3f(red[0], red[1], red[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.202, -0.03);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, 0.202, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.02, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.02, -0.03);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, red);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glColor3f(red[0], red[1], red[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.202, -0.03);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, 0.202, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.12, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.12, -0.03);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, red);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glColor3f(red[0], red[1], red[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.202, -0.03);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, 0.202, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.12, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.12, -0.03);
	glEnd();

	//rectangle above triangle
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blue);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
	glColor3f(blue[0], blue[1], blue[2]);
	glBegin(GL_POLYGON);
	glVertex3f(-0.03, 0.13, -0.04);
	glVertex3f(0.03, 0.13, -0.04);
	glVertex3f(0.03, 0.06, -0.04);
	glVertex3f(-0.03, 0.06, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.13, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.03, 0.13, -0.03);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.03, 0.06, -0.03);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.03, 0.06, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, 0.13, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, 0.13, -0.03);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, 0.06, -0.03);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, 0.06, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.13, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.03, 0.13, -0.03);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, 0.13, -0.03);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, 0.13, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.06, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.03, 0.06, -0.03);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, 0.06, -0.03);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, 0.06, -0.04);
	glEnd();

	//little triangle below rectangle
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blue);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
	glColor3f(blue[0], blue[1], blue[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.03, 0.05, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, 0.05, -0.04);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.0, 0.0, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.05, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.03, 0.05, -0.03);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.0, -0.03);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.0, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, 0.05, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, 0.05, -0.03);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.0, -0.03);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.0, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.05, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.03, 0.05, -0.03);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, 0.05, -0.03);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, 0.05, -0.04);
	glEnd();

	//left and right design pattern
	//left pattern upper
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.075, 0.12, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, 0.09, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.07, -0.04);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.065, 0.10, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.075, 0.12, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.075, 0.12, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.065, 0.10, -0.04);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.065, 0.10, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.09, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.12, 0.09, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.07, -0.04);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11, 0.07, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.09, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, 0.09, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.075, 0.12, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.075, 0.12, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.065, 0.10, -0.04);
	glVertex3f(-0.065, 0.10, 0.0);
	glVertex3f(-0.11, 0.07, 0.0);
	glVertex3f(-0.11, 0.07, -0.04);
	glEnd();

	//left pattern lower
	glBegin(GL_POLYGON);
	glVertex3f(-0.12, 0.09, -0.04);
	glVertex3f(0.0, -0.1, -0.04);
	glVertex3f(0.0, -0.13, -0.04);
	glVertex3f(-0.14, 0.08, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.09, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, 0.09, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.14, 0.08, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, 0.08, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.1, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.1, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.13, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.13, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.09, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, 0.09, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.1, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.1, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, 0.08, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.14, 0.08, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.13, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.13, -0.04);
	glEnd();

	//right pattern upper
	glBegin(GL_POLYGON);
	glVertex3f(0.075, 0.12, -0.04);
	glVertex3f(0.12, 0.09, -0.04);
	glVertex3f(0.11, 0.07, -0.04);
	glVertex3f(0.065, 0.10, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.075, 0.12, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.075, 0.12, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.065, 0.10, -0.04);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.065, 0.10, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.09, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, 0.09, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.07, -0.04);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.07, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.09, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, 0.09, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.075, 0.12, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.075, 0.12, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.065, 0.10, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.065, 0.10, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.07, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.07, -0.04);
	glEnd();

	//right pattern lower
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.09, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.1, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.13, -0.04);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, 0.08, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.09, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, 0.09, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, 0.08, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, 0.08, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.1, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.1, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.13, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.13, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.09, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, 0.09, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.1, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.1, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, 0.08, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.08, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.13, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.13, -0.04);
	glEnd();

	//left and right design pattern lower half
	//lower left inner upper
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, -0.08, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, -0.13, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, -0.16, -0.04);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, -0.11, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, -0.08, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.14, -0.11, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.14, -0.11, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, -0.08, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, -0.13, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, -0.16, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, -0.16, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, -0.13, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, -0.08, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, -0.13, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, -0.13, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, -0.08, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, -0.11, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, -0.16, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, -0.16, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, -0.11, 0.0);
	glEnd();

	//lower left inner lower
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.04, -0.14, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, -0.13, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, -0.34, -0.04);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.04, -0.36, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.04, -0.14, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, -0.13, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, -0.13, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.04, -0.14, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, -0.34, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.04, -0.36, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.04, -0.36, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, -0.34, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.04, -0.14, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.04, -0.36, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.04, -0.36, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.04, -0.14, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, -0.13, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, -0.34, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, -0.34, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, -0.13, 0.0);
	glEnd();

	//lower right inner upper
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, -0.08, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.13, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.16, -0.04);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, -0.11, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, -0.08, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, -0.11, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.11, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, -0.08, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.13, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.16, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.16, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.13, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, -0.08, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.13, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.13, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, -0.08, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, -0.11, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.16, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.16, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, -0.11, 0.0);
	glEnd();

	//lower right inner lower
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, -0.14, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.13, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.34, -0.04);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, -0.36, -0.04);
	glEnd();

	//lower left outer
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.14, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, -0.19, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, -0.30, -0.04);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.21, -0.04);
	glEnd();

	//lower right outer
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.2, -0.14, -0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.1, -0.19, -0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.1, -0.30, -0.04);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.2, -0.21, -0.04);
	glEnd();

	//jaw
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.2, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.4, 0.0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.2, -0.2, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.2, -0.2, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.2, -0.2, 0.4);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.0, -0.4, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.2, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.2, 0.4);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.0, -0.4, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.2, -0.2, 0.4);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.4, 0.0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.2, -0.2, 0.4);
	glEnd();

	//right face
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey6);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey6);
	glColor3f(grey6[0], grey6[1], grey6[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.2, 0.2, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.2, 0.2, 0.4);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.2, -0.2, 0.4);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.2, -0.2, 0);
	glEnd();

	//left face
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey6);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey6);
	glColor3f(grey6[0], grey6[1], grey6[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, 0.2, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, 0.2, 0.4);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.2, 0.4);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.2, 0);
	glEnd();

	//top face
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey6);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey6);
	glColor3f(grey6[0], grey6[1], grey6[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.2, 0.2, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.2, 0.2, 0.4);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, 0.2, 0.4);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, 0.2, 0);
	glEnd();

	//top sphere head
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glPushMatrix();
	glTranslatef(0.0, 0.15, 0.2);
	drawSphere(0.1);
	glPopMatrix();

	//behind face
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey6);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey6);
	glColor3f(grey6[0], grey6[1], grey6[2]);
	glBegin(GL_POLYGON);
	glVertex3f(-0.2, 0.2, 0.4);
	glVertex3f(0.2, 0.2, 0.4);
	glVertex3f(0.2, -0.2, 0.4);
	glVertex3f(-0.2, -0.2, 0.4);
	glEnd();

	//right ear 1
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blue2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue2);
	glColor3f(blue2[0], blue2[1], blue2[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, 0.09, 0.17);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.22, 0.09, 0.17);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.22, -0.09, 0.17);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.09, 0.17);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, yellow);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	glColor3f(yellow[0], yellow[1], yellow[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.22, 0.09, 0.17);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.22, 0.09, 0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.22, -0.09, 0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.22, -0.09, 0.17);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, pink);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, pink);
	glColor3f(pink[0], pink[1], pink[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, 0.09, 0.23);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.22, 0.09, 0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.22, -0.09, 0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.09, 0.23);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, pink2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, pink2);
	glColor3f(pink2[0], pink2[1], pink2[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, 0.09, 0.17);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, 0.09, 0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.22, 0.09, 0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.22, 0.09, 0.17);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, green);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
	glColor3f(green[0], green[1], green[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.09, 0.17);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.09, 0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.22, -0.09, 0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.22, -0.09, 0.17);
	glEnd();

	//right ear 2
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.22, 0.08, 0.18);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.26, 0.08, 0.18);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.26, -0.08, 0.18);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.22, -0.08, 0.18);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.26, 0.08, 0.18);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.26, 0.08, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.26, -0.08, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.26, -0.08, 0.18);
	glEnd();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]); glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.22, 0.08, 0.22);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.26, 0.08, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.26, -0.08, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.22, -0.08, 0.22);
	glEnd();


	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.22, 0.08, 0.18);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.22, 0.08, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.26, 0.08, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.26, 0.08, 0.18);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.22, -0.08, 0.18);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.22, -0.08, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.26, -0.08, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.26, -0.08, 0.18);
	glEnd();

	//left ear 1
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blue2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue2);
	glColor3f(blue2[0], blue2[1], blue2[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.2, 0.09, 0.17);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.22, 0.09, 0.17);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.22, -0.09, 0.17);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.2, -0.09, 0.17);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, yellow);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
	glColor3f(yellow[0], yellow[1], yellow[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.22, 0.09, 0.17);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.22, 0.09, 0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.22, -0.09, 0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.22, -0.09, 0.17);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, pink);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, pink);
	glColor3f(pink[0], pink[1], pink[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.2, 0.09, 0.23);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.22, 0.09, 0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.22, -0.09, 0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.2, -0.09, 0.23);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, pink2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, pink2);
	glColor3f(pink2[0], pink2[1], pink2[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.2, 0.09, 0.17);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.2, 0.09, 0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.22, 0.09, 0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.22, 0.09, 0.17);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, green);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
	glColor3f(green[0], green[1], green[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.2, -0.09, 0.17);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.2, -0.09, 0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.22, -0.09, 0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.22, -0.09, 0.17);
	glEnd();

	//left ear 2
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.22, 0.08, 0.18);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.26, 0.08, 0.18);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.26, -0.08, 0.18);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.22, -0.08, 0.18);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.26, 0.08, 0.18);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.26, 0.08, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.26, -0.08, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.26, -0.08, 0.18);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glVertex3f(-0.22, 0.08, 0.22);
	glVertex3f(-0.26, 0.08, 0.22);
	glVertex3f(-0.26, -0.08, 0.22);
	glVertex3f(-0.22, -0.08, 0.22);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.22, 0.08, 0.18);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.22, 0.08, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.26, 0.08, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.26, 0.08, 0.18);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.22, -0.08, 0.18);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.22, -0.08, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.26, -0.08, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.26, -0.08, 0.18);
	glEnd();

	//left horn lower half
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.2, 0.2, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.26, 0.26, 0.16);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.26, 0.18, 0.16);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.2, 0.12, 0.16);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, purple);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, purple);
	glColor3f(purple[0], purple[1], purple[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.2, 0.2, 0.22);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.26, 0.26, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.26, 0.18, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.2, 0.12, 0.22);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, yellow2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow2);
	glColor3f(yellow2[0], yellow2[1], yellow2[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.26, 0.26, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.26, 0.26, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.26, 0.18, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.26, 0.18, 0.16);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blue3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue3);
	glColor3f(blue3[0], blue3[1], blue3[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.26, 0.26, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.26, 0.26, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.2, 0.2, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.2, 0.2, 0.16);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, pink2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, pink2);
	glColor3f(pink2[0], pink2[1], pink2[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.26, 0.18, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.26, 0.18, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.2, 0.12, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.2, 0.12, 0.16);
	glEnd();

	//left horn upper half
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.26, 0.36, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.26, 0.36, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.26, 0.18, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.26, 0.18, 0.16);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, green2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green2);
	glColor3f(green2[0], green2[1], green2[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.31, 0.4, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.31, 0.4, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.31, 0.22, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.31, 0.22, 0.16);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, green3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green3);
	glColor3f(green3[0], green3[1], green3[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.26, 0.36, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.31, 0.4, 0.16);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.31, 0.4, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.26, 0.36, 0.22);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, green4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green4);
	glColor3f(green4[0], green4[1], green4[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.31, 0.4, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.26, 0.36, 0.16);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.26, 0.18, 0.16);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.31, 0.22, 0.16);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blue4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue4);
	glColor3f(blue4[0], blue4[1], blue4[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.31, 0.4, 0.22);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.26, 0.36, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.26, 0.18, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.31, 0.22, 0.22);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, green5);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green5);
	glColor3f(green5[0], green5[1], green5[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.26, 0.18, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.31, 0.22, 0.16);
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(-0.31, 0.22, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.26, 0.18, 0.22);
	glEnd();

	//right horn lower half
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, 0.2, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.26, 0.26, 0.16);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.26, 0.18, 0.16);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, 0.12, 0.16);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, purple);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, purple);
	glColor3f(purple[0], purple[1], purple[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, 0.2, 0.22);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.26, 0.26, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.26, 0.18, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, 0.12, 0.22);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, yellow2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow2);
	glColor3f(yellow2[0], yellow2[1], yellow2[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.26, 0.26, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.26, 0.26, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.26, 0.18, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.26, 0.18, 0.16);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blue3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue3);
	glColor3f(blue3[0], blue3[1], blue3[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.26, 0.26, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.26, 0.26, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, 0.2, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, 0.2, 0.16);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, pink2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, pink2);
	glColor3f(pink2[0], pink2[1], pink2[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.26, 0.18, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.26, 0.18, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, 0.12, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, 0.12, 0.16);
	glEnd();

	//right horn upper half
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.26, 0.36, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.26, 0.36, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.26, 0.18, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.26, 0.18, 0.16);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, green2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green2);
	glColor3f(green2[0], green2[1], green2[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.31, 0.4, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.31, 0.4, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.31, 0.22, 0.22);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.31, 0.22, 0.16);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, green3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green3);
	glColor3f(green3[0], green3[1], green3[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.26, 0.36, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.31, 0.4, 0.16);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.31, 0.4, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.26, 0.36, 0.22);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, green4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green4);
	glColor3f(green4[0], green4[1], green4[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.31, 0.4, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.26, 0.36, 0.16);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.26, 0.18, 0.16);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.31, 0.22, 0.16);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blue4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue4);
	glColor3f(blue4[0], blue4[1], blue4[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.31, 0.4, 0.22); 
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.26, 0.36, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.26, 0.18, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.31, 0.22, 0.22);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, green5);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green5);
	glColor3f(green5[0], green5[1], green5[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.26, 0.18, 0.16);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.31, 0.22, 0.16);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.31, 0.22, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.26, 0.18, 0.22);
	glEnd();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void body() {
	glPushMatrix();
	glTranslatef(0.0, 0.0, tzWalk);

	glPushMatrix();
	glRotatef(angle, rx, ry, 0.0);

	//glPushMatrix();
	//glRotatef(180, 0.0, 1.0, 0.0);

	//left shoulder upper design
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23455, 0.70014, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23455, 0.71014, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17385, 0.72015, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.17385, 0.71015, 0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23455, 0.71014, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.17385, 0.72015, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17385, 0.71015, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23455, 0.70014, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23455, 0.70014, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23, 0.59, 0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.23, 0.59, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23455, 0.70014, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23455, 0.71014, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.23455, 0.70014, -0.023);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.23455, 0.70014, 0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23, 0.59, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.17, 0.61, 0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17, 0.61, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23, 0.59, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23455, 0.70014, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.17385, 0.71015, 0.026);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17, 0.61, 0.026);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23, 0.59, 0.026);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.17385, 0.71015, -0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23455, 0.70014, -0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.23, 0.59, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.17, 0.61, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.17385, 0.71015, 0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17385, 0.72015, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.17385, 0.71015, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.17, 0.61, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.17385, 0.71015, 0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17385, 0.71015, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.17, 0.61, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.17, 0.61, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23, 0.59, 0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.23, 0.59, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.17, 0.61, -0.023);
	glEnd();

	//left shoulder
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11407, 0.639, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.17, 0.61, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17, 0.61, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11407, 0.639, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.17, 0.61, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23, 0.59, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.23, 0.59, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.17, 0.61, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23, 0.59, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25, 0.57, 0.026);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25, 0.57, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23, 0.59, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25, 0.57, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25, 0.54, 0.026);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25, 0.54, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25, 0.57, 0);
	glEnd();
	//
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25, 0.54, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.21, 0.53, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.21, 0.53, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25, 0.54, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glVertex3f(-0.21, 0.53, 0.038);
	glVertex3f(-0.14, 0.55, 0.038);
	glVertex3f(-0.14, 0.55, 0);
	glVertex3f(-0.21, 0.53, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, 0.55, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.1, 0.56, 0.026);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.1, 0.56, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, 0.55, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, 0.56, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11407, 0.639, 0.026);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11407, 0.639, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.1, 0.56, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25, 0.57, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23, 0.59, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17, 0.61, 0.038);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11407, 0.639, 0.026);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, 0.56, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.14, 0.55, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.21, 0.53, 0.038);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25, 0.54, 0.026);
	glTexCoord2f(0.0f, 1.0f);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25, 0.57, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23, 0.59, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17, 0.61, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11, 0.64, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, 0.56, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.14, 0.55, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.21, 0.53, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25, 0.54, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23455, 0.70014, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23455, 0.71014, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17385, 0.72015, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.17385, 0.71015, 0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23455, 0.71014, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.17385, 0.72015, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17385, 0.71015, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23455, 0.70014, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23455, 0.70014, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23, 0.59, 0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.23, 0.59, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23455, 0.70014, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23455, 0.71014, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.23455, 0.70014, -0.023);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.23455, 0.70014, 0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23, 0.59, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.17, 0.61, 0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17, 0.61, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23, 0.59, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23455, 0.71014, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.17385, 0.72015, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17, 0.61, 0.038);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23, 0.59, 0.038);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.17385, 0.71015, -0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23455, 0.70014, -0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.23, 0.59, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.17, 0.61, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.17385, 0.71015, 0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17385, 0.72015, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.17385, 0.71015, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.17, 0.61, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.17385, 0.71015, 0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17385, 0.71015, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.17, 0.61, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.17, 0.61, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23, 0.59, 0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.23, 0.59, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.17, 0.61, -0.023);
	glEnd();
	//

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11407, 0.639, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.17, 0.61, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17, 0.61, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11407, 0.639, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.17, 0.61, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23, 0.59, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.23, 0.59, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.17, 0.61, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23, 0.59, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25, 0.57, 0.026);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25, 0.57, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23, 0.59, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25, 0.57, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25, 0.54, 0.026);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25, 0.54, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25, 0.57, 0);
	glEnd();

	//
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25, 0.54, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.21, 0.53, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.21, 0.53, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25, 0.54, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.21, 0.53, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.14, 0.55, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.14, 0.55, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.21, 0.53, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, 0.55, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.1, 0.56, 0.026);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.1, 0.56, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, 0.55, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, 0.56, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11407, 0.639, 0.026);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11407, 0.639, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.1, 0.56, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25, 0.57, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23, 0.59, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17, 0.61, 0.038);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11407, 0.639, 0.026);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, 0.56, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.14, 0.55, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.21, 0.53, 0.038);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25, 0.54, 0.026);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25, 0.57, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23, 0.59, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.17, 0.61, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11, 0.64, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, 0.56, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.14, 0.55, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.21, 0.53, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25, 0.54, 0);
	glEnd();

	//right shoulder

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23455, 0.70014, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.23455, 0.71014, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17385, 0.72015, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17385, 0.71015, 0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23455, 0.71014, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17385, 0.72015, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17385, 0.71015, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23455, 0.70014, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23455, 0.70014, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.23, 0.59, 0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.59, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23455, 0.70014, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23455, 0.71014, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.23455, 0.70014, -0.023);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.23455, 0.70014, 0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.59, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17, 0.61, 0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, 0.61, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.59, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23455, 0.70014, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17385, 0.71015, 0.026);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, 0.61, 0.026);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.59, 0.026);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23455, 0.71014, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17385, 0.72015, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, 0.61, 0.038);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.59, 0.038);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.17385, 0.71015, -0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.23455, 0.70014, -0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.23, 0.59, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, 0.61, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17385, 0.71015, 0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17385, 0.72015, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.17385, 0.71015, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.17, 0.61, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17385, 0.71015, 0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17385, 0.71015, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, 0.61, -0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.17, 0.61, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.23, 0.59, 0.023);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.23, 0.59, -0.023);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, 0.61, -0.023);
	glEnd();
	//

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11407, 0.639, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17, 0.61, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, 0.61, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11407, 0.639, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.17, 0.61, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.23, 0.59, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.23, 0.59, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, 0.61, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.59, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.25, 0.57, 0.026);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25, 0.57, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.59, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25, 0.57, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.25, 0.54, 0.026);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25, 0.54, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25, 0.57, 0);
	glEnd();
	//
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25, 0.54, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.21, 0.53, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.21, 0.53, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25, 0.54, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.21, 0.53, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.55, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, 0.55, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.21, 0.53, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, 0.55, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, 0.56, 0.026);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.56, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, 0.55, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, 0.56, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11407, 0.639, 0.026);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11407, 0.639, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.1, 0.56, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25, 0.57, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.23, 0.59, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, 0.61, 0.038);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11407, 0.639, 0.026);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, 0.56, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.55, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.21, 0.53, 0.038);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25, 0.54, 0.026);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25, 0.57, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.23, 0.59, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, 0.61, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.64, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, 0.56, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.55, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.21, 0.53, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25, 0.54, 0);
	glEnd();

	//left breast
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.21, 0.53, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.21, 0.5, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.21, 0.5, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.21, 0.53, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.21, 0.5, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.48, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.48, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.21, 0.5, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.48, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.13, 0.45, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.13, 0.45, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.48, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.13, 0.45, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.09, 0.44, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.09, 0.44, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.13, 0.45, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, 0.44, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, 0.47, 0.068);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, 0.47, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, 0.44, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.47, 0.068);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, 0.52, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.07, 0.52, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.47, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, 0.52, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.14, 0.55, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.14, 0.55, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.07, 0.52, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, 0.55, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.21, 0.53, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.21, 0.53, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, 0.55, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, 0.55, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, 0.52, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.13, 0.49, 0.075);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.21, 0.53, 0.058);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, 0.52, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, 0.47, 0.068);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.09, 0.44, 0.058);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.13, 0.49, 0.075);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.21, 0.53, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.13, 0.49, 0.075);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.09, 0.44, 0.058);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, 0.44, 0.058);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.13, 0.45, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.48, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.21, 0.5, 0.058);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, 0.55, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, 0.52, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.13, 0.49, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.21, 0.53, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, 0.52, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, 0.47, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.09, 0.44, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.13, 0.49, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.21, 0.53, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.13, 0.49, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.09, 0.44, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, 0.44, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.13, 0.45, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.48, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.21, 0.5, 0);
	glEnd();

	//right breast
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.21, 0.53, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.21, 0.5, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.21, 0.5, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.21, 0.53, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.21, 0.5, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.48, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.48, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.21, 0.5, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.48, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, 0.45, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, 0.45, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.48, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, 0.45, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, 0.44, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, 0.44, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, 0.45, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, 0.44, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.47, 0.068);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.47, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, 0.44, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, 0.47, 0.068);
	glTexCoord2f(.0f, 1.0f);
	glVertex3f(0.07, 0.52, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, 0.52, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.47, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, 0.52, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.55, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, 0.55, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.07, 0.52, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, 0.55, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.21, 0.53, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.21, 0.53, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, 0.55, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, 0.55, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, 0.52, 0.058);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, 0.49, 0.075);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.21, 0.53, 0.058);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, 0.52, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.47, 0.068);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, 0.44, 0.058);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, 0.49, 0.075);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.21, 0.53, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, 0.49, 0.075);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, 0.44, 0.058);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, 0.44, 0.058);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, 0.45, 0.058);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.48, 0.058);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.21, 0.5, 0.058);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, 0.55, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, 0.52, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, 0.49, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.21, 0.53, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, 0.52, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.47, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, 0.44, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, 0.49, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.21, 0.53, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, 0.49, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, 0.44, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, 0.44, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, 0.45, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.48, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.21, 0.5, 0);
	glEnd();

	//middle left
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, 0.55, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.03, 0.55, 0.032);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.07, 0.52, 0.038);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, 0.55, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, 0.52, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.07, 0.52, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, 0.55, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, 0.52, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.03, 0.55, 0.032);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.03, 0.55, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.07, 0.52, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, 0.55, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.03, 0.55, 0.032);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.03, 0.55, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, 0.55, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.14, 0.55, 0);
	glVertex3f(-0.03, 0.55, 0);
	glVertex3f(-0.07, 0.52, 0);
	glEnd();

	//middle right
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, 0.55, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, 0.55, 0.032);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.07, 0.52, 0.038);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, 0.55, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, 0.52, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, 0.52, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, 0.55, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, 0.52, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, 0.55, 0.032);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, 0.55, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.07, 0.52, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, 0.55, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, 0.55, 0.032);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, 0.55, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, 0.55, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, 0.55, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, 0.55, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.07, 0.52, 0);
	glEnd();

	//middle up
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blue5);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue5);
	glColor3f(blue5[0], blue5[1], blue5[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.03, 0.55, 0.032);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(-0.07, 0.52, 0.038);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.06, 0.47, 0.048);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(0.06, 0.47, 0.048);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, 0.52, 0.038);
	glTexCoord2f(0.0f, 0.5f);
	glVertex3f(0.03, 0.55, 0.032);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.47, 0.048);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.47, 0.048);
	glTexCoord2f(01.0f, 0.0f);
	glVertex3f(0.06, 0.47, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.47, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.55, 0.032);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, 0.55, 0.032);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, 0.55, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.03, 0.55, 0);
	glEnd();

	//left waist
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glColor3f(0.22, 0.22, 0.22);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.48, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.16, 0.35, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.16, 0.35, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.48, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.48, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.13, 0.45, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.13, 0.45, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.48, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glVertex3f(-0.13, 0.45, 0.038);
	glVertex3f(-0.1, 0.38, 0.06);
	glVertex3f(-0.1, 0.38, 0);
	glVertex3f(-0.13, 0.45, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, 0.35, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.1, 0.38, 0.06);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.1, 0.38, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, 0.35, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, 0.44, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.08, 0.38, 0.048);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.04, 0.34, 0.038);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, 0.44, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.08, 0.38, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.04, 0.34, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey6);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey6);
	glColor3f(grey6[0], grey6[1], grey6[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.13, 0.45, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.09, 0.44, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.04, 0.34, 0.038);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.08, 0.31, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.13, 0.45, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.09, 0.44, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.04, 0.34, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.08, 0.31, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.13, 0.45, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.08, 0.31, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.08, 0.31, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.13, 0.45, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, 0.44, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.04, 0.34, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.04, 0.34, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, 0.44, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.48, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.13, 0.45, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.1, 0.38, 0.06);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, 0.35, 0.038);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.48, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.13, 0.45, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.1, 0.38, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, 0.35, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, 0.38, 0.06);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, 0.29, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.16, 0.3, 0.055);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.34, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, 0.38, 0.06);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, 0.29, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.07, 0.29, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.1, 0.38, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, 0.29, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.16, 0.3, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.16, 0.3, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.07, 0.29, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, 0.38, 0.06);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, 0.29, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.07, 0.29, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.1, 0.38, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, 0.29, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.16, 0.3, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.16, 0.3, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.07, 0.29, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, 0.3, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.34, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.34, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, 0.3, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, 0.38, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, 0.29, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.16, 0.3, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.34, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.04, 0.34, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.08, 0.31, 0.055);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.07, 0.29, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.04, 0.34, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, 0.29, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.07, 0.29, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.04, 0.34, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.04, 0.34, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.08, 0.31, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(-0.07, 0.29, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.04, 0.34, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, 0.29, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.07, 0.29, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.04, 0.34, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, 0.29, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.04, 0.23, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.04, 0.23, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.07, 0.29, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glVertex3f(-0.04, 0.23, 0.055);
	glVertex3f(0.04, 0.23, 0.055);
	glVertex3f(0.04, 0.23, 0);
	glVertex3f(-0.04, 0.23, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.04, 0.34, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.34, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.34, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.04, 0.34, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.34, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.16, 0.3, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.16, 0.3, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.34, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23, 0.31, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.27, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.27, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23, 0.31, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23, 0.27, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.23, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.23, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23, 0.27, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23, 0.27, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.23, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.23, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23, 0.27, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glVertex3f(-0.23, 0.23, 0.055);
	glVertex3f(-0.18, 0.19, 0.055);
	glVertex3f(-0.18, 0.19, 0);
	glVertex3f(-0.23, 0.23, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.24, 0.18, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.16, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.16, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.24, 0.18, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23, 0.12, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.12, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.12, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23, 0.12, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.34, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23, 0.31, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.23, 0.31, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.34, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23, 0.31, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23, 0.27, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.23, 0.27, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23, 0.31, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23, 0.27, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23, 0.23, 0.055);
	glTexCoord2f(2.0f, 0.0f);
	glVertex3f(-0.23, 0.23, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23, 0.27, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.23, 0.23, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.24, 0.18, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.24, 0.18, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23, 0.23, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.24, 0.18, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.23, 0.12, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.23, 0.12, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.24, 0.18, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, 0.3, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.27, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.27, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, 0.3, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.27, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.23, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.23, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.27, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.23, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.19, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.19, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.23, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.19, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.16, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.16, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.19, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.16, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.12, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.12, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.16, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.12, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, 0.25, 0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.12, 0.25, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.12, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.25, 0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, 0.17, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.09, 0.17, 0.055);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.13, 0.22, 0.04);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.13, 0.22, 0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.09, 0.17, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.09, 0.17, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.13, 0.22, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.25, 0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, 0.17, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, 0.17, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, 0.25, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.17, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.09, 0.17, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.09, 0.17, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.17, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.21, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, 0.19, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.12, 0.19, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, 0.21, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.19, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11975, 0.17696, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11975, 0.17696, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, 0.19, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11975, 0.17696, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11989, 0.16381, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11989, 0.16381, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11975, 0.17696, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11989, 0.16381, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12048, 0.15339, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.12048, 0.15339, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11989, 0.16381, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12048, 0.15339, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12217, 0.14404, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.12217, 0.14404, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12048, 0.15339, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12217, 0.14404, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, 0.13, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.12, 0.13, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12217, 0.14404, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11711, 0.1164, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11711, 0.1164, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11711, 0.1164, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.1024, 0.08484, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.1024, 0.08484, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11711, 0.1164, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glVertex3f(-0.11, 0.2, 0.035);
	glVertex3f(-0.11, 0.18, 0.035);
	glVertex3f(-0.11, 0.18, 0.022);
	glVertex3f(-0.11, 0.2, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11, 0.18, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11, 0.17, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.17, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11, 0.18, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11, 0.17, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11, 0.16, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.16, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11, 0.17, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11, 0.16, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11, 0.15, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.15, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11, 0.16, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11, 0.15, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11, 0.14, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.14, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11, 0.15, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11, 0.14, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.10729, 0.12967, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.10729, 0.12967, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11, 0.14, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.10729, 0.12967, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.1, 0.11, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.1, 0.11, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.10729, 0.12967, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, 0.11, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.09173, 0.09095, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.09173, 0.09095, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.1, 0.11, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11, 0.08, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.08, 0.1, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.08, 0.1, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11, 0.08, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11, 0.08, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, 0.01, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, 0.01, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11, 0.08, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.08, 0.1, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, 0.04, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, 0.04, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.08, 0.1, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11, 0.08, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.08, 0.1, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, 0.04, 0.055);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.01, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11, 0.08, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.08, 0.1, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, 0.04, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.01, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, 0.17, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.08, 0.13, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.08, 0.13, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, 0.17, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.08, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.05, 0.08, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.05, 0.08, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.08, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.08, 0.17, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, 0.13, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.07, 0.13, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.08, 0.17, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.05, 0.09, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.05, 0.09, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.07, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, 0.17, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.08, 0.17, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.08, 0.17, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, 0.17, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.08, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, 0.13, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.07, 0.13, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.08, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.05, 0.08, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.05, 0.09, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.05, 0.09, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.08, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, 0.17, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.08, 0.17, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.07, 0.13, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.08, 0.13, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, 0.17, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.08, 0.17, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.07, 0.13, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.08, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.08, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, 0.13, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.05, 0.09, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.08, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.08, 0.13, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, 0.13, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.05, 0.09, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.08, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.05, 0.09, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.09, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.08, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.08, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.05, 0.09, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.09, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.08, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.08, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.05, 0.09, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.09, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.09, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.09, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.05, 0.08, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.08, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.08, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.08, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, 0.17, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, 0.13, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, 0.13, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.07, 0.17, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.02, 0.1, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.02, 0.1, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.17, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.05, 0.13, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.05, 0.13, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.17, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.05, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.02, 0.11, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.02, 0.11, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, 0.17, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, 0.17, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.05, 0.13, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.13, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, 0.17, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, 0.17, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.05, 0.13, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.05, 0.13, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.02, 0.11, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.1, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.13, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.05, 0.13, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.02, 0.11, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.1, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.11, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.02, 0.11, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.02, 0.11, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.11, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.1, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.02, 0.1, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.02, 0.1, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.1, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.11, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.02, 0.11, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.02, 0.1, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.1, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.11, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.02, 0.11, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.02, 0.1, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.1, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.08, 0.1, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.1, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, 0.1, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.08, 0.1, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.04, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.04, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.04, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.04, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey6);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey6);
	glColor3f(grey6[0], grey6[1], grey6[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.08, 0.1, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.1, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.04, 0.055);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.04, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey6);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey6);
	glColor3f(grey6[0], grey6[1], grey6[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.08, 0.1, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.1, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.04, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.04, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.04, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.04, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.01, 0.055);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.01, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.04, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.04, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.01, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.01, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey8);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey8);
	glColor3f(grey8[0], grey8[1], grey8[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.01, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.01, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.01, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.01, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey8);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey8);
	glColor3f(grey8[0], grey8[1], grey8[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.01, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.01, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.04, 0.055);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, -0.04, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey8);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey8);
	glColor3f(grey8[0], grey8[1], grey8[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.01, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.01, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.04, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, -0.04, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey8);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey8);
	glColor3f(grey8[0], grey8[1], grey8[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.01, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, -0.04, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, -0.04, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.01, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey8);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey8);
	glColor3f(grey8[0], grey8[1], grey8[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, 0.01, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.04, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.04, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.01, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey8);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey8);
	glColor3f(grey8[0], grey8[1], grey8[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, -0.04, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.04, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.04, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, -0.04, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey8);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey8);
	glColor3f(grey8[0], grey8[1], grey8[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.21, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11, 0.2, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.18, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, 0.19, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.21, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11, 0.2, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.18, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, 0.19, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.19, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11, 0.18, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.17, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11975, 0.17696, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.19, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11, 0.18, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.17, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11975, 0.17696, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11975, 0.17696, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11, 0.17, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.16, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11989, 0.16381, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11975, 0.17696, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11, 0.17, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.16, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.11989, 0.16381, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11989, 0.16381, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11, 0.16, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.15, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12048, 0.15339, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.11989, 0.16381, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11, 0.16, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.15, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12048, 0.15339, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12048, 0.15339, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11, 0.15, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.14, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12217, 0.14404, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12048, 0.15339, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11, 0.15, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.14, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12217, 0.14404, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12217, 0.14404, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.11, 0.14, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.10729, 0.12967, 0.035);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(-0.12, 0.13, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(-0.12217, 0.14404, 0.022);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(-0.11, 0.14, 0.022);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(-0.10729, 0.12967, 0.022);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(-0.12, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(-0.12, 0.13, 0.035);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(-0.10729, 0.12967, 0.035);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(-0.1, 0.11, 0.035);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(-0.11711, 0.1164, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(-0.12, 0.13, 0.022);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(-0.10729, 0.12967, 0.022);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(-0.1, 0.11, 0.022);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(-0.11711, 0.1164, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(-0.11711, 0.1164, 0.035);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(-0.1, 0.11, 0.035);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(-0.09173, 0.09095, 0.035);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(-0.1024, 0.08484, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(-0.11711, 0.1164, 0.022);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(-0.1, 0.11, 0.022);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(-0.09173, 0.09095, 0.022);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(-0.1024, 0.08484, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(-0.18, 0.34, 0.055);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(-0.16, 0.3, 0.055);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(-0.18, 0.27, 0.055);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(-0.23, 0.31, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(-0.18, 0.34, 0);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(-0.16, 0.3, 0);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(-0.18, 0.27, 0);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(-0.23, 0.31, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(-0.23, 0.31, 0.055);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(-0.18, 0.27, 0.055);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(-0.18, 0.23, 0.055);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(-0.23, 0.27, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(-0.23, 0.31, 0);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(-0.18, 0.27, 0);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(-0.18, 0.23, 0);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(-0.23, 0.27, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(-0.23, 0.27, 0.055);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(-0.18, 0.23, 0.055);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(-0.18, 0.19, 0.055);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(-0.23, 0.23, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(-0.23, 0.27, 0);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(-0.18, 0.23, 0);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(-0.18, 0.19, 0);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(-0.23, 0.23, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(-0.23, 0.23, 0.055);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(-0.18, 0.19, 0.055);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(-0.18, 0.16, 0.055);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(-0.24, 0.18, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey6);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey6);
	glColor3f(grey6[0], grey6[1], grey6[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(-0.23, 0.23, 0);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(-0.18, 0.19, 0);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(-0.18, 0.16, 0);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(-0.24, 0.18, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey9);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey9);
	glColor3f(grey9[0], grey9[1], grey9[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(-0.24, 0.18, 0.055);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(-0.18, 0.16, 0.055);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(-0.18, 0.12, 0.055);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(-0.23, 0.12, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.24, 0.18, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.16, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.12, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.23, 0.12, 0);
	glEnd();

	//
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.48, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, 0.35, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.35, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.48, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.48, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, 0.45, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, 0.45, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.48, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, 0.45, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, 0.38, 0.06);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.38, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, 0.45, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, 0.35, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, 0.38, 0.06);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.38, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.35, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, 0.44, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, 0.38, 0.048);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.04, 0.34, 0.038);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, 0.44, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, 0.38, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.04, 0.34, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey6);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey6);
	glColor3f(grey6[0], grey6[1], grey6[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, 0.45, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, 0.44, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.34, 0.038);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, 0.31, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, 0.45, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, 0.44, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.34, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, 0.31, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, 0.45, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.31, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, 0.31, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, 0.45, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, 0.44, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.34, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.34, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, 0.44, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.48, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, 0.45, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.38, 0.06);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.35, 0.038);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.48, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, 0.45, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.38, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.35, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, 0.38, 0.06);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, 0.29, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.3, 0.055);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.34, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, 0.38, 0.06);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, 0.29, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, 0.29, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.1, 0.38, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, 0.29, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, 0.3, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.3, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.07, 0.29, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, 0.3, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.34, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.34, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.3, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, 0.38, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, 0.29, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.3, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.34, 0);
	glEnd();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.34, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, 0.31, 0.055);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.07, 0.29, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, 0.34, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, 0.29, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, 0.29, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.34, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.34, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, 0.31, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.07, 0.29, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, 0.34, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, 0.29, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, 0.29, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.34, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, 0.29, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.23, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.23, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.07, 0.29, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.04, 0.23, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.23, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.23, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.04, 0.23, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.04, 0.34, 0.038);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.34, 0.038);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.34, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.04, 0.34, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.34, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, 0.3, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.3, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.34, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.31, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.27, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.27, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.31, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.27, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.23, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.23, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.27, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.27, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.23, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.23, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.27, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.23, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.19, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.19, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.23, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.18, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.16, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.16, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.18, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.12, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.12, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.12, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.12, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.34, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.23, 0.31, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.23, 0.31, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.34, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.31, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.23, 0.27, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.23, 0.27, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.31, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.27, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.23, 0.23, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.23, 0.23, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.27, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.23, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.18, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.18, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.23, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.18, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.23, 0.12, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.23, 0.12, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.18, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, 0.3, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.27, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.27, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.3, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.27, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.23, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.23, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.27, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.23, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.19, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.19, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.23, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.19, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.16, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.16, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.19, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.16, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.12, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.12, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.16, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.12, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, 0.25, 0.04);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, 0.25, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.12, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.25, 0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.17, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, 0.17, 0.055);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, 0.22, 0.04);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, 0.22, 0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, 0.17, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, 0.17, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, 0.22, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.25, 0.04);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.17, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.17, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, 0.25, 0);
	glEnd();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, 0.17, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, 0.17, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, 0.17, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.17, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.21, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, 0.19, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, 0.19, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, 0.21, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.19, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11975, 0.17696, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11975, 0.17696, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, 0.19, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11975, 0.17696, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11989, 0.16381, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11989, 0.16381, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11975, 0.17696, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11989, 0.16381, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12048, 0.15339, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12048, 0.15339, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11989, 0.16381, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12048, 0.15339, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12217, 0.14404, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12217, 0.14404, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12048, 0.15339, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12217, 0.14404, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, 0.13, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, 0.13, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12217, 0.14404, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11711, 0.1164, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11711, 0.1164, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11711, 0.1164, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1024, 0.08484, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1024, 0.08484, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11711, 0.1164, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.2, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.18, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.18, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.2, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.18, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.17, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.17, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.18, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.17, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.16, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.16, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.17, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.16, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.15, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.15, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.16, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.15, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.14, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.14, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.15, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.14, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.10729, 0.12967, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.10729, 0.12967, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.14, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.10729, 0.12967, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, 0.11, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.11, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.10729, 0.12967, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, 0.11, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09173, 0.09095, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09173, 0.09095, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.1, 0.11, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.08, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.1, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, 0.1, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.08, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.08, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.01, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.01, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.08, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, 0.1, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.04, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.04, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, 0.1, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.08, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.1, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.04, 0.055);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.01, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.08, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.1, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.04, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.01, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, 0.17, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.13, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, 0.13, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, 0.17, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.08, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.08, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, 0.17, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, 0.13, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, 0.13, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, 0.17, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.09, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.09, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.07, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, 0.17, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.17, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, 0.17, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, 0.17, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, 0.13, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, 0.13, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.05, 0.08, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.09, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.09, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.05, 0.08, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, 0.17, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.17, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, 0.13, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, 0.13, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, 0.17, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.17, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, 0.13, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, 0.13, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.09, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.05, 0.08, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, 0.13, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, 0.13, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.09, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.05, 0.08, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.05, 0.09, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.09, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.08, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.08, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.05, 0.09, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.09, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.08, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.08, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.05, 0.09, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.09, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.09, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.09, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.05, 0.08, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.08, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.08, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.08, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, 0.17, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.13, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.13, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.07, 0.17, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.02, 0.1, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.02, 0.1, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, 0.17, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.13, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.13, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.17, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.05, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.02, 0.11, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.02, 0.11, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.05, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, 0.17, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.17, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.13, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.13, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, 0.17, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.17, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.13, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.13, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.02, 0.11, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.02, 0.1, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, 0.13, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.13, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.02, 0.11, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.02, 0.1, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.11, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.02, 0.11, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.02, 0.11, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.11, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.1, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.02, 0.1, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.02, 0.1, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.1, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.11, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.02, 0.11, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.02, 0.1, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.1, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.11, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.02, 0.11, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.02, 0.1, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.1, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.08, 0.1, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.1, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, 0.1, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.08, 0.1, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.04, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.04, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.04, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.04, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.08, 0.1, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.1, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.04, 0.055);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.04, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.08, 0.1, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.1, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.04, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.04, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.04, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.04, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.01, 0.055);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.01, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.04, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.04, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.01, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.01, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.01, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.01, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.01, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.01, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.01, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.01, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.04, 0.055);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, -0.04, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.01, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.01, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.04, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, -0.04, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, 0.01, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.04, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.04, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.01, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, 0.01, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.04, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.04, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.01, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, -0.04, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.04, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.04, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, -0.04, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.21, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.2, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.18, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, 0.19, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.21, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.2, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.18, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, 0.19, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.19, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.18, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.17, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11975, 0.17696, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.19, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.18, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.17, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11975, 0.17696, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11975, 0.17696, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.17, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.16, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11989, 0.16381, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11975, 0.17696, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.17, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.16, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11989, 0.16381, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11989, 0.16381, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.16, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.15, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12048, 0.15339, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11989, 0.16381, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.16, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.15, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12048, 0.15339, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12048, 0.15339, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.15, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.14, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12217, 0.14404, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12048, 0.15339, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.15, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.14, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12217, 0.14404, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12217, 0.14404, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.14, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.10729, 0.12967, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, 0.13, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12217, 0.14404, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.14, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.10729, 0.12967, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, 0.13, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.13, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.10729, 0.12967, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.11, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11711, 0.1164, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.13, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.10729, 0.12967, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.11, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11711, 0.1164, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11711, 0.1164, 0.035);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, 0.11, 0.035);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09173, 0.09095, 0.035);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.1024, 0.08484, 0.035);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11711, 0.1164, 0.022);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, 0.11, 0.022);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09173, 0.09095, 0.022);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.1024, 0.08484, 0.022);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.34, 0.055);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, 0.3, 0.055);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.27, 0.055);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.31, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.34, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, 0.3, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.27, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.31, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.31, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.27, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.23, 0.055);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.27, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.31, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.27, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.23, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.27, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.27, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.23, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.19, 0.055);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.23, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.27, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.23, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.19, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.23, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.23, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.19, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.16, 0.055);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.18, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.23, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.19, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.16, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.18, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.18, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.16, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.12, 0.055);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.12, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.18, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.16, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.12, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.12, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.04, 0.34, 0.038);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.04, 0.34, 0.038);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.07, 0.29, 0.055);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(0.04, 0.23, 0.055);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.04, 0.23, 0.055);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, 0.29, 0.055);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, jgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jgrey);
	glColor3f(jgrey[0], jgrey[1], jgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.04, 0.34, 0);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.04, 0.34, 0);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.07, 0.29, 0);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(0.04, 0.23, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.04, 0.23, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, 0.29, 0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, red);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glColor3f(red[0], red[1], red[2]);
	glPushMatrix();
	glTranslatef(0.0, 0.4, 0.0);
	drawSphere(0.05);
	drawDisk(GL_FILL, 0.15);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.15, 0.15, 0.15);
	glTranslatef(0.0, 0.4, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glTexCoord2f(0.5, 0.5);
	glVertex3f(0.0, 0.0, 0.4);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-0.2, -0.3, 0.4);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0.2, -0.3, 0.4);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0.3, -0.2, 0.4);
	glTexCoord2f(0.5, 1.0);
	glVertex3f(0.4, -0.1, 0.4);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.5, 0.0, 0.4);
	glTexCoord2f(0.0, 0.5);
	glVertex3f(0.4, 0.1, 0.4);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.3, 0.2, 0.4);
	glTexCoord2f(0.5, 0.0);
	glVertex3f(0.2, 0.3, 0.4);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-0.2, 0.3, 0.4);
	glTexCoord2f(1.0, 0.5);
	glVertex3f(-0.3, 0.2, 0.4);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-0.4, 0.1, 0.4);
	glTexCoord2f(0.5, 1.0);
	glVertex3f(-0.5, 0.0, 0.4);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-0.4, -0.1, 0.4);
	glTexCoord2f(0.0, 0.5);
	glVertex3f(-0.3, -0.2, 0.4);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-0.2, -0.3, 0.4);
	glEnd();
	glPopMatrix();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hgrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hgrey);
	glColor3f(hgrey[0], hgrey[1], hgrey[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.57, 0.026);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.57, -0.18);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.57, -0.18);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.57, 0.026);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey7);
	glColor3f(grey7[0], grey7[1], grey7[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.12, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.12, -0.18);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.12, -0.18);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.12, 0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey10);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey10);
	glColor3f(grey10[0], grey10[1], grey10[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.57, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.57, -0.18);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.12, -0.18);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.12, 0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey10);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey10);
	glColor3f(grey10[0], grey10[1], grey10[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.12, 0.023);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.12, -0.18);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.57, -0.18);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.57, 0.023);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey10);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey10);
	glColor3f(grey10[0], grey10[1], grey10[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.12, -0.18);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.12, -0.18);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.57, -0.18);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.57, -0.18);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey11);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey11);
	glColor3f(grey11[0], grey11[1], grey11[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.15, -0.19);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.10, 0.18, -0.19);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.10, 0.48, -0.19);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.45, -0.19);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey11);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey11);
	glColor3f(grey11[0], grey11[1], grey11[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.15, -0.19);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.15, -0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.10, 0.18, -0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.10, 0.18, -0.19);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey11);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey11);
	glColor3f(grey11[0], grey11[1], grey11[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.10, 0.48, -0.19);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.10, 0.48, -0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.45, -0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.45, -0.19);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey11);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey11);
	glColor3f(grey11[0], grey11[1], grey11[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.15, -0.19);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.18, 0.15, -0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.18, 0.45, -0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.45, -0.19);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey11);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey11);
	glColor3f(grey11[0], grey11[1], grey11[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.10, 0.18, -0.19);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.10, 0.18, -0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.10, 0.48, -0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.10, 0.48, -0.19);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey11);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey11);
	glColor3f(grey11[0], grey11[1], grey11[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.18, 0.15, -0.23);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.10, 0.18, -0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.10, 0.48, -0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.18, 0.45, -0.23);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey11);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey11);
	glColor3f(grey11[0], grey11[1], grey11[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.15, -0.19);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.10, 0.18, -0.19);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.10, 0.48, -0.19);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.45, -0.19);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey11);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey11);
	glColor3f(grey11[0], grey11[1], grey11[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.15, -0.19);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.15, -0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.10, 0.18, -0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.10, 0.18, -0.19);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey11);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey11);
	glColor3f(grey11[0], grey11[1], grey11[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.10, 0.48, -0.19);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.10, 0.48, -0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.45, -0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.45, -0.19);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey11);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey11);
	glColor3f(grey11[0], grey11[1], grey11[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.15, -0.19);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.15, -0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.45, -0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.45, -0.19);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey11);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey11);
	glColor3f(grey11[0], grey11[1], grey11[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.10, 0.18, -0.19);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.10, 0.18, -0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.10, 0.48, -0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.10, 0.48, -0.19);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey11);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey11);
	glColor3f(grey11[0], grey11[1], grey11[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.15, -0.23);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.10, 0.18, -0.23);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.10, 0.48, -0.23);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.45, -0.23);
	glEnd();

	glPopMatrix();
	glPopMatrix();
}

void drawArm(float x, float y, float z) {
	glPushMatrix();
	//glScalef(0.4, 0.4, 0.4);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey14);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey14);
	glColor3f(grey14[0], grey14[1], grey14[2]);
	glBegin(GL_QUADS);
	// Face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.0, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, 0.0, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, 0.0, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.0, 0.0);
	// Face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.0, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, 0.0, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, y, z);
	//Face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, y, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, y, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	//Face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, 0.0, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, 0.0, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, 0.0);
	//Face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, y, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, 0.0, 0.0);
	// Face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, y, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, y, z);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.0, z);
	glEnd();

	glPopMatrix();
}

void drawShoulderArm() {
	glPushMatrix();
	glTranslatef(-0.25, 0.7, -0.1);
	glRotatef(angleHandMov, shoulderRxHand, shoulderRyHand, shoulderRzHand);
	glRotatef(-12.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.35, 0.0);
	glPushMatrix();
	glScalef(0.4, 0.4, 0.4);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey12);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey12);
	glColor3f(grey12[0], grey12[1], grey12[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.58, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, 0.7, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, 0.28, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.58, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, 0.58, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.12, 0.28, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, 0.28, -0.1);

	//face 3 
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, 0.7, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, 0.7, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.61, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, 0.58, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, 0.6, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.7, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.1, 0.7, -0.1);

	//face 5 
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.28, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, 0.28, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.6, -0.1);

	//face 6 
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.58, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, 0.28, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.6, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.1, 0.7, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(0.2, 0.6, 0.1); // Bottom arm
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(0.2, -0.6, 0.1);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_POLYGON);
	//face 1
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.35, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, 0.43, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.41, -0.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.25, -0.1);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.0, 0.32, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.36, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.01, 0.43, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, 0.43, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.35, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, 0.43, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.41, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.41, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, 0.43, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.25, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.41, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.41, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.25, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.32, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, 0.25, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.25, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.32, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.36, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, 0.32, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.32, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.35, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 7
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.36, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, 0.43, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.41, 0.2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.25, 0.2);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.0, 0.32, 0.2);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);	
	glBegin(GL_POLYGON);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, 0.43, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.46, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.43, -0.1);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(0.06, 0.42, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.41, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.41, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, 0.43, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.46, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.46, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, 0.43, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, 0.46, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.43, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.43, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.46, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, 0.42, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.43, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.43, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.42, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.05, 0.41, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.42, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.42, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.05, 0.41, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, 0.41, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.41, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.41, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.41, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 7
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, 0.43, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.41, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.41, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, 0.43, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 8
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, 0.43, 0.2);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.04, 0.46, 0.2);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.06, 0.43, 0.2);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(0.06, 0.42, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.41, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.41, 0.2);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_POLYGON);
	//face 1
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.46, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.54, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.51, -0.1);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.12, 0.48, -0.1);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.09, 0.48, -0.1);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.08, 0.47, -0.1);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(0.07, 0.45, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.43, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, 0.46, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.54, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.54, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.46, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.54, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.51, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, 0.51, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.54, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.48, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.51, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, 0.51, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, 0.48, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, 0.48, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, 0.48, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, 0.48, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, 0.48, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, 0.47, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, 0.48, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, 0.48, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, 0.47, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 7
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, 0.45, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.47, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, 0.47, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.07, 0.45, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 8
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, 0.43, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, 0.45, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, 0.45, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.43, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 9
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, 0.46, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.43, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.43, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.46, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 10
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.46, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.54, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.51, 0.2);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.12, 0.48, 0.2);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.09, 0.48, 0.2);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.08, 0.47, 0.2);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(0.07, 0.45, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.43, 0.2);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_POLYGON);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.54, -0.1);
	glTexCoord2f(0.2f, 1.0f);
	glVertex3f(0.16, 0.6, -0.1);
	glTexCoord2f(0.4f, 1.0f);
	glVertex3f(0.24, 0.6, -0.1);
	glTexCoord2f(0.4f, 0.8f);
	glVertex3f(0.24, 0.57, -0.1);
	glTexCoord2f(0.5f, 0.6f);
	glVertex3f(0.25, 0.53, -0.1);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.25, 0.5, -0.1);
	glTexCoord2f(0.4f, 0.3f);
	glVertex3f(0.24, 0.46, -0.1);
	glTexCoord2f(0.4f, 0.2f);
	glVertex3f(0.24, 0.43, -0.1);
	glTexCoord2f(0.3f, 0.0f);
	glVertex3f(0.2, 0.4, -0.1);
	glTexCoord2f(0.1f, 0.6f);
	glVertex3f(0.14, 0.51, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.54, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.6, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.54, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.6, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.6, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.6, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.57, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.6, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.6, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.57, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25, 0.53, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.57, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.57, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25, 0.53, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25, 0.5, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.25, 0.53, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25, 0.53, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25, 0.5, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 7
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.56, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.25, 0.5, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25, 0.5, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.46, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 8
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.43, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.46, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.46, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.43, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 9
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, 0.4, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.43, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.43, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, 0.4, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 10
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, 0.51, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, 0.4, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, 0.4, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, 0.51, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 11
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.54, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.51, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, 0.51, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.54, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 12
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.54, 0.2);
	glTexCoord2f(0.2f, 1.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(0.4f, 1.0f);
	glVertex3f(0.24, 0.6, 0.2);
	glTexCoord2f(0.4f, 0.8f);
	glVertex3f(0.24, 0.57, 0.2);
	glTexCoord2f(0.5f, 0.6f);
	glVertex3f(0.25, 0.53, 0.2);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.25, 0.5, 0.2);
	glTexCoord2f(0.4f, 0.3f);
	glVertex3f(0.24, 0.46, 0.2);
	glTexCoord2f(0.4f, 0.2f);
	glVertex3f(0.24, 0.43, 0.2);
	glTexCoord2f(0.3f, 0.0f);
	glVertex3f(0.2, 0.4, 0.2);
	glTexCoord2f(0.1f, 0.6f);
	glVertex3f(0.14, 0.51, 0.2);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_POLYGON);
	//face 1
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.6, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.7, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17, 0.68, -0.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.21, 0.65, -0.1);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.24, 0.6, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, 0.7, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.7, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.6, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.17, 0.68, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, 0.7, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.7, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, 0.68, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.21, 0.65, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17, 0.68, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, 0.68, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.21, 0.656, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.6, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.21, 0.65, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.21, 0.65, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.6, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.6, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.6, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.6, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 7
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.7, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17, 0.68, 0.2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.65, 0.2);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.24, 0.6, 0.2);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_POLYGON);
	//face 1
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.0, 0.25, -0.1);
	glTexCoord2f(0.47f, 0.95f);
	glVertex3f(-0.03, 0.2, -0.1);
	glTexCoord2f(0.49f, 0.95f);
	glVertex3f(-0.01, 0.2, -0.1);
	glTexCoord2f(0.48f, 0.92f);
	glVertex3f(-0.02, 0.17, -0.1);
	glTexCoord2f(0.48, 0.9);
	glVertex3f(-0.02, 0.15, -0.1);
	glTexCoord2f(0.48, 0.87);
	glVertex3f(-0.02, 0.12, -0.1);
	glTexCoord2f(0.48, 0.84);
	glVertex3f(-0.02, 0.09, -0.1);
	glTexCoord2f(0.49, 0.82);
	glVertex3f(-0.01, 0.07, -0.1);
	glTexCoord2f(0.49, 0.8);
	glVertex3f(-0.01, 0.05, -0.1);
	glTexCoord2f(0.56, 0.78);
	glVertex3f(0.08, 0.03, -0.1);
	glTexCoord2f(0.58, 0.79);
	glVertex3f(0.1, 0.04, -0.1);
	glTexCoord2f(0.6, 0.81);
	glVertex3f(0.12, 0.06, -0.1);
	glTexCoord2f(0.62, 0.84);
	glVertex3f(0.14, 0.09, -0.1);
	glTexCoord2f(0.63, 0.86);
	glVertex3f(0.15, 0.11, -0.1);
	glTexCoord2f(0.63, 0.9);
	glVertex3f(0.15, 0.15, -0.1);
	glTexCoord2f(0.64, 0.93);
	glVertex3f(0.16, 0.18, -0.1);
	glTexCoord2f(0.64, 0.97);
	glVertex3f(0.16, 0.23, -0.1);
	glTexCoord2f(0.65, 1.0);
	glVertex3f(0.17, 0.26, -0.1);
	glTexCoord2f(0.65, 1.05);
	glVertex3f(0.17, 0.31, -0.1);
	glTexCoord2f(0.65, 1.1);
	glVertex3f(0.17, 0.36, -0.1);
	glTexCoord2f(0.64, 1.13);
	glVertex3f(0.16, 0.39, -0.1);
	glTexCoord2f(0.61, 1.15);
	glVertex3f(0.13, 0.41, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.25, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.03, 0.2, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.03, 0.2, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.25, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.2, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.01, 0.2, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.01, 0.2, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.03, 0.2, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.01, 0.2, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.02, 0.17, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.02, 0.17, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.01, 0.2, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.17, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.02, 0.15, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.02, 0.15, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.17, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.15, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.02, 0.12, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.02, 0.12, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.15, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 7
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.12, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.02, 0.09, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.02, 0.09, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.12, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 8
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.09, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.01, 0.07, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.01, 0.07, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.09, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 9
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.01, 0.07, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.01, 0.05, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.01, 0.05, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.01, 0.07, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 10
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.01, 0.05, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.03, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, 0.03, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.01, 0.05, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 11
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, 0.03, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, 0.04, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.04, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, 0.03, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 12
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, 0.04, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, 0.06, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, 0.06, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.1, 0.04, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 13
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.06, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.08, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, 0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, 0.06, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 14
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, 0.08, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.15, 0.11, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.15, 0.11, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, 0.08, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 15
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.15, 0.11, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.15, 0.15, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.15, 0.15, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.15, 0.11, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 16
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.15, 0.15, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, 0.18, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.18, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.15, 0.15, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 17
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, 0.18, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17, 0.23, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, 0.23, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.18, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 18
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.17, 0.23, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17, 0.26, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, 0.26, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, 0.23, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 19
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.17, 0.26, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.31, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.31, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, 0.26, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 20
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.31, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17, 0.36, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, 0.36, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.31, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 21
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.17, 0.36, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, 0.39, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.39, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, 0.36, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 22
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, 0.39, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, 0.41, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, 0.41, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.39, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 23
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, 0.41, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, 0.25, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.25, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, 0.41, -0.1);

	glBegin(GL_POLYGON);
	//face 24
	glTexCoord2f(0.5, 1.0);
	glVertex3f(0.0, 0.25, 0.2);
	glTexCoord2f(0.47, 0.95);
	glVertex3f(-0.03, 0.2, 0.2);
	glTexCoord2f(0.49, 0.95);
	glVertex3f(-0.01, 0.2, 0.2);
	glTexCoord2f(0.48, 0.92);
	glVertex3f(-0.02, 0.17, 0.2);
	glTexCoord2f(0.48, 0.9);
	glVertex3f(-0.02, 0.15, 0.2);
	glTexCoord2f(0.48, 0.87);
	glVertex3f(-0.02, 0.12, 0.2);
	glTexCoord2f(0.48, 0.84);
	glVertex3f(-0.02, 0.09, 0.2);
	glTexCoord2f(0.49, 0.82);
	glVertex3f(-0.01, 0.07, 0.2);
	glTexCoord2f(0.49, 0.8);
	glVertex3f(-0.01, 0.05, 0.2);
	glTexCoord2f(0.56, 0.78);
	glVertex3f(0.08, 0.03, 0.2);
	glTexCoord2f(0.58, 0.79);
	glVertex3f(0.1, 0.04, 0.2);
	glTexCoord2f(0.6, 0.81);
	glVertex3f(0.12, 0.06, 0.2);
	glTexCoord2f(0.62, 0.84);
	glVertex3f(0.14, 0.08, 0.2);
	glTexCoord2f(0.63, 0.86);
	glVertex3f(0.15, 0.11, 0.2);
	glTexCoord2f(0.63, 0.9);
	glVertex3f(0.15, 0.15, 0.2);
	glTexCoord2f(0.64, 0.93);
	glVertex3f(0.16, 0.18, 0.2);
	glTexCoord2f(0.64, 0.97);
	glVertex3f(0.17, 0.23, 0.2);
	glTexCoord2f(0.65, 1.0);
	glVertex3f(0.17, 0.26, 0.2);
	glTexCoord2f(0.65, 1.05);
	glVertex3f(0.18, 0.31, 0.2);
	glTexCoord2f(0.65, 1.1);
	glVertex3f(0.17, 0.36, 0.2);
	glTexCoord2f(0.64, 1.13);
	glVertex3f(0.16, 0.39, 0.2);
	glTexCoord2f(0.61, 1.15);
	glVertex3f(0.13, 0.41, 0.2);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_POLYGON);
	//face 1
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.2, 0.0, -0.1);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.2, 0.4, -0.1);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0.24, 0.43, -0.1);
	glTexCoord2f(1.0, 0.8);
	glVertex3f(0.24, 0.38, -0.1);
	glTexCoord2f(1.0, 0.6);
	glVertex3f(0.24, 0.3, -0.1);
	glTexCoord2f(1.0, 0.4);
	glVertex3f(0.25, 0.24, -0.1);
	glTexCoord2f(1.0, 0.2);
	glVertex3f(0.24, 0.18, -0.1);
	glTexCoord2f(0.5, 0.0);
	glVertex3f(0.23, 0.12, -0.1);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.2, 0.0, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, 0.0, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, 0.4, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, 0.4, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, 0.0, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, 0.4, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.43, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.43, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, 0.4, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.38, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.43, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.43, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.38, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.3, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.38, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.8, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.3, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25, 0.24, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.3, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.3, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25, 0.24, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 7
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.18, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.25, 0.24, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25, 0.24, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.18, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 8
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.12, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.18, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.18, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.12, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 9
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.22, 0.06, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.23, 0.12, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.23, 0.12, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.22, 0.06, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 10
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, 0.0, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.22, 0.06, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.22, 0.06, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, 0.0, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 11
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.2, 0.0, 0.2);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.2, 0.4, 0.2);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0.24, 0.43, 0.2);
	glTexCoord2f(1.0, 0.8);
	glVertex3f(0.24, 0.38, 0.2);
	glTexCoord2f(1.0, 0.6);
	glVertex3f(0.24, 0.3, 0.2);
	glTexCoord2f(1.0, 0.4);
	glVertex3f(0.25, 0.24, 0.2);
	glTexCoord2f(1.0, 0.2);
	glVertex3f(0.24, 0.18, 0.2);
	glTexCoord2f(0.5, 0.0);
	glVertex3f(0.23, 0.12, 0.2);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.2, 0.0, 0.2);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey12);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey12);
	glColor3f(grey12[0], grey12[1], grey12[2]);
	//line in the top arm
	glBegin(GL_QUADS);
	//face 1
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.01, 0.18, 0.22);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.15, 0.18, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.15, 0.15, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.16, 0.22);

	//face 2
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.01, 0.18, 0.22);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.15, 0.18, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.15, 0.18, -0.12);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.01, 0.18, -0.12);

	//face 3
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.15, 0.18, 0.22);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.15, 0.15, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.15, 0.15, -0.12);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.15, 0.18, -0.12);

	//face 4
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.15, 0.15, 0.22);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.02, 0.16, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.02, 0.18, -0.12);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.15, 0.15, -0.12);

	//face 5
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.16, 0.22);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.01, 0.18, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.01, 0.18, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.16, 0.22);

	//face 6
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.01, 0.18, 0.12);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.15, 0.18, 0.12);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.15, 0.15, 0.12);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.16, 0.12);
	glEnd();

	//shoulder L size shape
	glBegin(GL_QUADS);
	//face 1
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.02, 0.45, -0.15);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.03, 0.53, -0.15);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, 0.52, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.05, 0.47, -0.15);

	//face 2
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glVertex3f(0.02, 0.45, 0.25);
	glVertex3f(0.02, 0.45, -0.15);
	glVertex3f(-0.03, 0.53, -0.15);
	glVertex3f(0.01, 0.52, -0.15);

	//face 3
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.53, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.01, 0.52, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, 0.52, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.03, 0.53, -0.15);

	//face 4
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, 0.52, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.47, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.47, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, 0.52, -0.15);

	//face 5
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.02, 0.45, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.47, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.47, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.02, 0.45, -0.15);

	//face 6
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.02, 0.45, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, 0.53, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, 0.52, 0.25);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.05, 0.47, 0.25);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.53, -0.15);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.58, -0.15);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.56, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, 0.52, -0.15);

	//face 2
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.53, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.58, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.58, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.03, 0.53, -0.15);

	//face 3
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, 0.58, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.56, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.56, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.58, -0.15);

	//face 4
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, 0.52, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.56, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.56, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, 0.52, -0.15);

	//face 5
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.53, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.01, 0.52, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, 0.52, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.03, 0.53, -0.15);

	//face 6
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.53, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.58, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.56, 0.25);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, 0.52, 0.2);
	glEnd();


	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey14);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey14);
	glColor3f(grey14[0], grey14[1], grey14[2]);
	drawCylinderHand(GLU_FILL, 0.07, 0.09, 0.12, 8, 0.13, 0.37, 0.2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawCylinderHand(GLU_LINE, 0.07, 0.09, 0.12, 8, 0.13, 0.37, 0.2);
	glPopMatrix();
	glPopMatrix();

	for (int i = 0; i < count2; i++) {
		if (attack == true) {
			angleHandMov -= 0.3;
			shoulderRxHand = -1.0;
			arm2RxHand = -1.0;
			handRxHand = -1.0;
			fingerRxHand = -1.0;
			finger2RxHand = -1.0;
			tzWeapon -= 0.006;
		}
		else {
			angleHandMov += 0.3;
			shoulderRxHand = -1.0;
			arm2RxHand = -1.0;
			handRxHand = -1.0;
			fingerRxHand = -1.0;
			finger2RxHand = -1.0;
			tzWeapon += 0.006;
		}
		if (angleHandMov <= -1 || angleHandMov >= 35) {
			attack = !attack;
		}
	}

	for (int i = 0; i < count3; i++) {
		if (flySword == true) {
			angleHandMov += 0.6;
			shoulderRxHand = -1.0;
			arm2RxHand = -1.0;
			handRxHand = -1.0;
			fingerRxHand = -1.0;
			finger2RxHand = -1.0;
			tzWeapon += 0.6;
		}
		if (angleHandMov >= 30) {
			flySword = !flySword;
			angleHandMov = 0;
		}
	}
}

void drawArm2() {
	glPushMatrix();
	glTranslatef(-0.25, 0.7, -0.1);
	glRotatef(angleHandMov, arm2RxHand, arm2RyHand, arm2RzHand);
	glRotatef(-12.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.35, 0.0);

	glPushMatrix();
	glScalef(0.4, 0.4, 0.4);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.04, 0.07, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.01, 0.07, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.02, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.02, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.04, 0.07, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.01, 0.07, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.01, 0.07, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.04, 0.07, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.01, 0.07, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, 0.02, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.02, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.01, 0.07, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.02, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, 0.02, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, 0.02, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.02, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.02, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.04, 0.07, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.04, 0.07, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.02, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.04, 0.07, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.01, 0.07, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.02, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.02, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.02, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, 0.2, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.03, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.07, -0.03, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.02, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, 0.02, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.02, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.02, 0.2);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.02, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.03, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.03, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.02, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.03, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.09, -0.08, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.09, -0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.03, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, -0.08, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, -0.03, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.07, -0.03, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, -0.08, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.02, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, 0.2, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.03, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.07, -0.03, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, -0.03, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.03, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.08, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, -0.08, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, -0.03, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.03, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.03, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.07, -0.03, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.03, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.08, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.03, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, -0.08, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.08, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, -0.08, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, -0.08, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, -0.03, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.07, -0.03, -1.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, -0.08, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, -0.03, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.03, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, -0.08, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, -0.08, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.08, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.14, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.1, -0.14, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, -0.08, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.08, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, -0.08, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.08, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.14, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.14, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.08, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.14, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.1, -0.14, 0.2); 
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.1, -0.14, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.14, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, -0.14, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.09, -0.08, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.09, -0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.1, -0.14, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, -0.08, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.08, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.14, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.1, -0.14, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, -0.14, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.14, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.21, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, -0.2, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, -0.14, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.14, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.14, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.1, -0.14, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.14, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.21, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.21, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.14, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.21, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, -0.2, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.12, -0.2, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.21, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, -0.2, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.1, -0.14, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.1, -0.14, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, -0.2, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, -0.14, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.14, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.21, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, -0.2, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, -0.2, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.21, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.28, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.13, -0.27, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, -0.2, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.21, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.21, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, -0.2, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.21, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.28, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.28, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.21, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.28, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.13, -0.27, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.13, -0.27, -1.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.28, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.13, -0.27, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, -0.2, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.12, -0.2, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.13, -0.27, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, -0.2, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.21, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.28, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.13, -0.27, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.13, -0.27, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.28, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.38, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, -0.36, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.13, -0.27, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.28, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.28, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.13, -0.27, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.28, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.38, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.38, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.28, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.38, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.14, -0.36, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.14, -0.36, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.38, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, -0.36, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.13, -0.27, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.13, -0.27, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, -0.36, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.13, -0.27, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.28, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.38, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, -0.36, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, -0.36, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.38, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.47, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, -0.45, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, -0.36, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.38, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.38, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, -0.36, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.38, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.47, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.47, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.38, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.47, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.16, -0.45, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.16, -0.45, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.47, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, -0.45, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.14, -0.36, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.14, -0.36, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, -0.45, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, -0.36, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.38, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.47, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, -0.45, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, -0.45, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.47, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.55, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, -0.54, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, -0.45, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.47, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.47, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, -0.45, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.47, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.55, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.55, -0.1); 
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.47, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.55, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.16, -0.54, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.16, -0.54, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.55, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, -0.54, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.16, -0.45, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.16, -0.45, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, -0.54, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, -0.45, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.47, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.55, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, -0.54, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, -0.54, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.55, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.6, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, -0.73, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, -0.54, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.55, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.55, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, -0.54, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.55, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.6, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.6, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.55, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.6, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, -0.73, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.12, -0.73, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.6, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, -0.73, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.16, -0.54, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.16, -0.54, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, -0.73, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, -0.54, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.55, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.6, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, -0.73, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.17, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, 0.0, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.28, -0.09, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.28, -0.15, 0.1);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.17, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, 0.0, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, 0.0, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.17, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, 0.0, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.28, -0.09, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.28, -0.09, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, 0.0, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.28, -0.09, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.28, -0.15, 0.10);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.28, -0.15, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.28, -0.09, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.28, -0.15, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.17, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.17, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.28, -0.15, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.17, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.28, -0.09, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.28, -0.15, 0.0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.3, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.17, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.28, -0.15, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.28, -0.25, 0.1);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.3, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.17, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.3, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.17, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.17, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.28, -0.15, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.28, -0.15, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.17, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.28, -0.15, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.28, -0.25, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.28, -0.25, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.28, -0.15, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.28, -0.25, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.3, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.3, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.28, -0.25, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.3, 0.0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.17, 0.0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.28, -0.15, 0.0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.28, -0.25, 0.0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.05, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.02, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.08, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.11, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.05, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.02, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.02, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.05, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.02, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.08, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.02, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.08, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.11, 0.2);
	glTexCoord2f(11.0f, 0.0f);
	glVertex3f(0.0, -0.11, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.08, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.11, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.05, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.05, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.11, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.05, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.02, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.11, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.19, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.15, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.2, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.23, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.19, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.15, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.15, -0.1); 
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.19, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.15, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.2, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.2, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.15, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.2, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.19, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.19, -0.1); 
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.2, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.23, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.19, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.19, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.23, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.19, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.15, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.2, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.23, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.3, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.28, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.33, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.35, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.3, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.28, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.28, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.3, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.28, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.33, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.33, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.28, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.33, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.35, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.35, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.33, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.35, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.3, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.3, -0.1); 
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.35, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.3, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.28, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.33, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.35, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.41, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.4, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.45, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.47, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.41, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.4, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.4, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.41, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.4, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.45, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.45, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.4, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.45, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.47, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.47, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.45, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.47, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.41, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.41, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.47, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.41, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.4, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.45, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.47, -0.1);
	glEnd();

	glPopMatrix();
	glPopMatrix();
}

void drawHand() {
	glPushMatrix();
	glTranslatef(-0.25, 0.7, -0.1);
	glRotatef(angleHandMov, handRxHand, handRyHand, handRzHand);
	glRotatef(-12.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.35, 0.0);

	glPushMatrix();
	glScalef(0.4, 0.4, 0.4);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//RIGHT - Lpalm	
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, -0.6, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.01, -0.69, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, -0.6, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, -0.6, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, -0.6, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, -0.69, 0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, -0.6, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.01, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, -0.6, 0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.01, -0.69, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, -0.6, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, -0.6, 0.0);

	//face 6 
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, -0.6, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.6, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, -0.6, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, -0.6, 0.0);

	//RIGHT - Rpalm
	//face 1 
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, -0.6, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.68, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, -0.6, 0.1);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.68, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.68, 0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.68, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.68, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, -0.6, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, -0.6, 0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, -0.6, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.6, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, -0.6, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, -0.6, 0.1);

	//face 5 
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.6, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, -0.6, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, -0.6, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17, -0.6, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.68, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glEnd();
	
	glPopMatrix();
	glPopMatrix();
}

void drawFingers() {
	glPushMatrix();
	glTranslatef(-0.25, 0.7, -0.1);
	glRotatef(angleHandMov, fingerRxHand, fingerRyHand, fingerRzHand);
	glRotatef(-12.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.35, 0.0);

	glPushMatrix();
	glScalef(0.4, 0.4, 0.4);

	glBegin(GL_QUADS);
	//little finger
	//first
	//face 1 - base
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, -0.69, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, -0.69, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.76, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.76, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.01, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.76, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, -0.69, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, -0.69, 0.1); 
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.76, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.76, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.1); 
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.76, 0.1);

	//second 
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.76, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.83, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.83, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.76, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.76, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.83, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.76, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.76, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.83, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.83, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.76, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.83, 0.1);

	//third
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.83, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.86, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.88, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.88, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, -0.83, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, -0.83, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.88, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.83, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.83, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.86, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.86, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.88, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, -0.86, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.86, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.88, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.83, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.86, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.88, 0.1);

	//wu ming zhi
	//first 
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, -0.69, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, -0.69, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, -0.69, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, -0.69, 0.0); 
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0); 
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.1);

	//second
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1); 
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);

	//third
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.84, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.86, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.86, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.86, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.84, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.84, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.86, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, -0.84, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.84, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.86, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.84, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.86, 0.1);

	//zhong zhi
	//first - face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, -0.69, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, -0.69, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.07, -0.69, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.1);

	//second
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.1);

	//third
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.82, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.84, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.84, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.84, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);
	glTexCoord2f(0.0f, .0f);
	glVertex3f(0.08, -0.79, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, -0.82, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, -0.82, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.84, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, -0.82, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.82, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.84, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.82, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.84, 0.1);

	//shi zhi
	//first - face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, -0.69, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, -0.73, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.1, -0.69, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, -0.73, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, -0.73, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, -0.73, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, -0.73, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, -0.73, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.1);

	//second
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, -0.73, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.76, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, -0.73, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, -0.73, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, -0.76, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, -0.73, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, -0.73, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, -0.76, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, -0.76, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.76, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, -0.73, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.76, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.1);

	//third
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, -0.76, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, -0.8, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, -0.82, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, -0.82, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, -0.82, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, -0.76, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.76, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, -0.8, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, -0.76, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.76, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, -0.8, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, -0.82, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, -0.8, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, -0.8, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, -0.82, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, -0.76, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, -0.8, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, -0.82, 0.1);
	glEnd();

	glPopMatrix();
	glPopMatrix();
}

void drawFingers2() {
	glPushMatrix();
	glTranslatef(-0.25, 0.7, -0.1);
	glRotatef(angleHandMov, finger2RxHand, finger2RyHand, finger2RzHand);
	glRotatef(-12.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.35, 0.0);


	glPushMatrix();
	glScalef(0.4, 0.4, 0.4);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//thumb
	//first - face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, -0.69, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.68, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.22, -0.73, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.19, -0.72, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.19, -0.72, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.19, -0.72, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.68, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.68, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, -0.69, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.22, -0.73, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.68, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.68, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.22, -0.73, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.19, -0.72, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.22, -0.73, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.22, -0.73, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.19, -0.72, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.68, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.22, -0.73, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.19, -0.72, 0.1);

	//second - face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.19, -0.72, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.22, -0.73, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.19, -0.8, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, -0.77, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, -0.77, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.19, -0.72, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.19, -0.72, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, -0.77, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.19, -0.72, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.22, -0.73, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.22, -0.73, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.19, -0.72, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.19, -0.8, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.22, -0.73, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.22, -0.73, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.19, -0.8, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, -0.77, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.19, -0.8, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.19, -0.8, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, -0.77, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.19, -0.72, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.22, -0.73, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.19, -0.8, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, -0.77, 0.1);
	glEnd();

	glPopMatrix();
	glPopMatrix();
}

//left arm
void drawLeftShoulderArm() {
	glPushMatrix();
	glScalef(-1, 1, 1);
	glTranslatef(-0.25, 0.7, -0.1);
	glRotatef(leftangleHandMov, leftshoulderRxHand, leftshoulderRyHand, leftshoulderRzHand);
	glRotatef(-12.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.35, 0.0);


	glPushMatrix();
	glScalef(0.4, 0.4, 0.4);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey12);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey12);
	glColor3f(grey12[0], grey12[1], grey12[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.58, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, 0.7, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, 0.28, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.58, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, 0.58, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.12, 0.28, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, 0.28, -0.1);

	//face 3 
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, 0.7, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, 0.7, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.11, 0.61, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, 0.58, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, 0.6, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.7, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.1, 0.7, -0.1);

	//face 5 
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.28, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, 0.28, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.6, -0.1);

	//face 6 
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.58, -0.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, 0.28, -0.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, 0.6, -0.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, 0.7, -0.1);

	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(0.2, 0.6, 0.1); // Bottom arm
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawArm(0.2, -0.6, 0.1);
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_POLYGON);
	//face 1
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.35, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, 0.43, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.41, -0.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.25, -0.1);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.0, 0.32, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.36, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.01, 0.43, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, 0.43, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.35, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, 0.43, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.41, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.41, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, 0.43, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.25, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.41, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.41, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.25, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.32, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, 0.25, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.25, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.32, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.36, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, 0.32, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.32, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.05, 0.35, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 7
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.36, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, 0.43, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.41, 0.2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.25, 0.2);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.0, 0.32, 0.2);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_POLYGON);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, 0.43, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.46, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.43, -0.1);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(0.06, 0.42, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.41, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.41, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, 0.43, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.46, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.46, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, 0.43, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, 0.46, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.43, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.43, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.46, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, 0.42, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.43, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.43, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.42, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.05, 0.41, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.42, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.42, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.05, 0.41, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, 0.41, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.41, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.41, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.41, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 7
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, 0.43, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.41, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.41, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, 0.43, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 8
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, 0.43, 0.2);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.04, 0.46, 0.2);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.06, 0.43, 0.2);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(0.06, 0.42, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.41, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.41, 0.2);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_POLYGON);
	//face 1
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.46, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.54, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.51, -0.1);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.12, 0.48, -0.1);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.09, 0.48, -0.1);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.08, 0.47, -0.1);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(0.07, 0.45, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.43, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, 0.46, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, 0.54, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.54, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.46, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.54, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.51, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, 0.51, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.54, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.48, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.51, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, 0.51, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, 0.48, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, 0.48, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, 0.48, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, 0.48, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, 0.48, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, 0.47, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, 0.48, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, 0.48, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, 0.47, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 7
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, 0.45, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.47, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, 0.47, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.07, 0.45, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 8
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, 0.43, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, 0.45, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, 0.45, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.43, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 9
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, 0.46, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.43, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.43, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.46, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 10
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.46, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, 0.54, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.51, 0.2);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.12, 0.48, 0.2);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.09, 0.48, 0.2);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.08, 0.47, 0.2);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(0.07, 0.45, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, 0.43, 0.2);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_POLYGON);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.54, -0.1);
	glTexCoord2f(0.2f, 1.0f);
	glVertex3f(0.16, 0.6, -0.1);
	glTexCoord2f(0.4f, 1.0f);
	glVertex3f(0.24, 0.6, -0.1);
	glTexCoord2f(0.4f, 0.8f);
	glVertex3f(0.24, 0.57, -0.1);
	glTexCoord2f(0.5f, 0.6f);
	glVertex3f(0.25, 0.53, -0.1);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.25, 0.5, -0.1);
	glTexCoord2f(0.4f, 0.3f);
	glVertex3f(0.24, 0.46, -0.1);
	glTexCoord2f(0.4f, 0.2f);
	glVertex3f(0.24, 0.43, -0.1);
	glTexCoord2f(0.3f, 0.0f);
	glVertex3f(0.2, 0.4, -0.1);
	glTexCoord2f(0.1f, 0.6f);
	glVertex3f(0.14, 0.51, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.54, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.6, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.54, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.6, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.6, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.6, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.57, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.6, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.6, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.57, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25, 0.53, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.57, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.57, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25, 0.53, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25, 0.5, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.25, 0.53, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25, 0.53, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25, 0.5, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 7
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.56, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.25, 0.5, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25, 0.5, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.46, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 8
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.43, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.46, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.46, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.43, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 9
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, 0.4, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.43, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.43, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, 0.4, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 10
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, 0.51, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, 0.4, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, 0.4, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, 0.51, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 11
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.54, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.51, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, 0.51, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, 0.54, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 12
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, 0.54, 0.2);
	glTexCoord2f(0.2f, 1.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(0.4f, 1.0f);
	glVertex3f(0.24, 0.6, 0.2);
	glTexCoord2f(0.4f, 0.8f);
	glVertex3f(0.24, 0.57, 0.2);
	glTexCoord2f(0.5f, 0.6f);
	glVertex3f(0.25, 0.53, 0.2);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.25, 0.5, 0.2);
	glTexCoord2f(0.4f, 0.3f);
	glVertex3f(0.24, 0.46, 0.2);
	glTexCoord2f(0.4f, 0.2f);
	glVertex3f(0.24, 0.43, 0.2);
	glTexCoord2f(0.3f, 0.0f);
	glVertex3f(0.2, 0.4, 0.2);
	glTexCoord2f(0.1f, 0.6f);
	glVertex3f(0.14, 0.51, 0.2);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_POLYGON);
	//face 1
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.6, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.7, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17, 0.68, -0.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.21, 0.65, -0.1);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.24, 0.6, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, 0.7, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.7, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.6, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.17, 0.68, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, 0.7, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.7, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, 0.68, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.21, 0.65, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17, 0.68, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, 0.68, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.21, 0.656, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.6, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.21, 0.65, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.21, 0.65, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.6, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.6, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.6, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.6, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 7
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.6, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.7, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17, 0.68, 0.2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.65, 0.2);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(0.24, 0.6, 0.2);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_POLYGON);
	//face 1
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.0, 0.25, -0.1);
	glTexCoord2f(0.47f, 0.95f);
	glVertex3f(-0.03, 0.2, -0.1);
	glTexCoord2f(0.49f, 0.95f);
	glVertex3f(-0.01, 0.2, -0.1);
	glTexCoord2f(0.48f, 0.92f);
	glVertex3f(-0.02, 0.17, -0.1);
	glTexCoord2f(0.48, 0.9);
	glVertex3f(-0.02, 0.15, -0.1);
	glTexCoord2f(0.48, 0.87);
	glVertex3f(-0.02, 0.12, -0.1);
	glTexCoord2f(0.48, 0.84);
	glVertex3f(-0.02, 0.09, -0.1);
	glTexCoord2f(0.49, 0.82);
	glVertex3f(-0.01, 0.07, -0.1);
	glTexCoord2f(0.49, 0.8);
	glVertex3f(-0.01, 0.05, -0.1);
	glTexCoord2f(0.56, 0.78);
	glVertex3f(0.08, 0.03, -0.1);
	glTexCoord2f(0.58, 0.79);
	glVertex3f(0.1, 0.04, -0.1);
	glTexCoord2f(0.6, 0.81);
	glVertex3f(0.12, 0.06, -0.1);
	glTexCoord2f(0.62, 0.84);
	glVertex3f(0.14, 0.09, -0.1);
	glTexCoord2f(0.63, 0.86);
	glVertex3f(0.15, 0.11, -0.1);
	glTexCoord2f(0.63, 0.9);
	glVertex3f(0.15, 0.15, -0.1);
	glTexCoord2f(0.64, 0.93);
	glVertex3f(0.16, 0.18, -0.1);
	glTexCoord2f(0.64, 0.97);
	glVertex3f(0.16, 0.23, -0.1);
	glTexCoord2f(0.65, 1.0);
	glVertex3f(0.17, 0.26, -0.1);
	glTexCoord2f(0.65, 1.05);
	glVertex3f(0.17, 0.31, -0.1);
	glTexCoord2f(0.65, 1.1);
	glVertex3f(0.17, 0.36, -0.1);
	glTexCoord2f(0.64, 1.13);
	glVertex3f(0.16, 0.39, -0.1);
	glTexCoord2f(0.61, 1.15);
	glVertex3f(0.13, 0.41, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.25, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.03, 0.2, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.03, 0.2, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.25, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.2, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.01, 0.2, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.01, 0.2, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.03, 0.2, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.01, 0.2, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.02, 0.17, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.02, 0.17, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.01, 0.2, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.17, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.02, 0.15, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.02, 0.15, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.17, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.15, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.02, 0.12, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.02, 0.12, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.15, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 7
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.12, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.02, 0.09, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.02, 0.09, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.12, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 8
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.09, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.01, 0.07, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.01, 0.07, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.09, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 9
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.01, 0.07, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.01, 0.05, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.01, 0.05, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.01, 0.07, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 10
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.01, 0.05, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, 0.03, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, 0.03, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.01, 0.05, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 11
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, 0.03, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, 0.04, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, 0.04, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, 0.03, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 12
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, 0.04, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, 0.06, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, 0.06, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.1, 0.04, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 13
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, 0.06, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, 0.08, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, 0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, 0.06, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 14
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, 0.08, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.15, 0.11, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.15, 0.11, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, 0.08, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 15
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.15, 0.11, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.15, 0.15, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.15, 0.15, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.15, 0.11, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 16
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.15, 0.15, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, 0.18, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.18, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.15, 0.15, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 17
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, 0.18, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17, 0.23, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, 0.23, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.18, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 18
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.17, 0.23, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17, 0.26, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, 0.26, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, 0.23, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 19
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.17, 0.26, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.18, 0.31, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.18, 0.31, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, 0.26, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 20
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.18, 0.31, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17, 0.36, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, 0.36, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.18, 0.31, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 21
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.17, 0.36, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, 0.39, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, 0.39, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, 0.36, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 22
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, 0.39, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, 0.41, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, 0.41, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, 0.39, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 23
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, 0.41, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, 0.25, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.25, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, 0.41, -0.1);

	glBegin(GL_POLYGON);
	//face 24
	glTexCoord2f(0.5, 1.0);
	glVertex3f(0.0, 0.25, 0.2);
	glTexCoord2f(0.47, 0.95);
	glVertex3f(-0.03, 0.2, 0.2);
	glTexCoord2f(0.49, 0.95);
	glVertex3f(-0.01, 0.2, 0.2);
	glTexCoord2f(0.48, 0.92);
	glVertex3f(-0.02, 0.17, 0.2);
	glTexCoord2f(0.48, 0.9);
	glVertex3f(-0.02, 0.15, 0.2);
	glTexCoord2f(0.48, 0.87);
	glVertex3f(-0.02, 0.12, 0.2);
	glTexCoord2f(0.48, 0.84);
	glVertex3f(-0.02, 0.09, 0.2);
	glTexCoord2f(0.49, 0.82);
	glVertex3f(-0.01, 0.07, 0.2);
	glTexCoord2f(0.49, 0.8);
	glVertex3f(-0.01, 0.05, 0.2);
	glTexCoord2f(0.56, 0.78);
	glVertex3f(0.08, 0.03, 0.2);
	glTexCoord2f(0.58, 0.79);
	glVertex3f(0.1, 0.04, 0.2);
	glTexCoord2f(0.6, 0.81);
	glVertex3f(0.12, 0.06, 0.2);
	glTexCoord2f(0.62, 0.84);
	glVertex3f(0.14, 0.08, 0.2);
	glTexCoord2f(0.63, 0.86);
	glVertex3f(0.15, 0.11, 0.2);
	glTexCoord2f(0.63, 0.9);
	glVertex3f(0.15, 0.15, 0.2);
	glTexCoord2f(0.64, 0.93);
	glVertex3f(0.16, 0.18, 0.2);
	glTexCoord2f(0.64, 0.97);
	glVertex3f(0.17, 0.23, 0.2);
	glTexCoord2f(0.65, 1.0);
	glVertex3f(0.17, 0.26, 0.2);
	glTexCoord2f(0.65, 1.05);
	glVertex3f(0.18, 0.31, 0.2);
	glTexCoord2f(0.65, 1.1);
	glVertex3f(0.17, 0.36, 0.2);
	glTexCoord2f(0.64, 1.13);
	glVertex3f(0.16, 0.39, 0.2);
	glTexCoord2f(0.61, 1.15);
	glVertex3f(0.13, 0.41, 0.2);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_POLYGON);
	//face 1
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.2, 0.0, -0.1);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.2, 0.4, -0.1);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0.24, 0.43, -0.1);
	glTexCoord2f(1.0, 0.8);
	glVertex3f(0.24, 0.38, -0.1);
	glTexCoord2f(1.0, 0.6);
	glVertex3f(0.24, 0.3, -0.1);
	glTexCoord2f(1.0, 0.4);
	glVertex3f(0.25, 0.24, -0.1);
	glTexCoord2f(1.0, 0.2);
	glVertex3f(0.24, 0.18, -0.1);
	glTexCoord2f(0.5, 0.0);
	glVertex3f(0.23, 0.12, -0.1);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.2, 0.0, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, 0.0, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, 0.4, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, 0.4, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, 0.0, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, 0.4, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.43, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.43, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, 0.4, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.38, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.43, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.43, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.38, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.3, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.38, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.8, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.3, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.25, 0.24, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.3, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.3, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.25, 0.24, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 7
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.24, 0.18, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.25, 0.24, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.25, 0.24, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.24, 0.18, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 8
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.23, 0.12, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.24, 0.18, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.24, 0.18, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.23, 0.12, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 9
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.22, 0.06, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.23, 0.12, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.23, 0.12, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.22, 0.06, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 10
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, 0.0, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.22, 0.06, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.22, 0.06, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, 0.0, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	//face 11
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.2, 0.0, 0.2);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.2, 0.4, 0.2);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0.24, 0.43, 0.2);
	glTexCoord2f(1.0, 0.8);
	glVertex3f(0.24, 0.38, 0.2);
	glTexCoord2f(1.0, 0.6);
	glVertex3f(0.24, 0.3, 0.2);
	glTexCoord2f(1.0, 0.4);
	glVertex3f(0.25, 0.24, 0.2);
	glTexCoord2f(1.0, 0.2);
	glVertex3f(0.24, 0.18, 0.2);
	glTexCoord2f(0.5, 0.0);
	glVertex3f(0.23, 0.12, 0.2);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.2, 0.0, 0.2);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey12);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey12);
	glColor3f(grey12[0], grey12[1], grey12[2]);
	//line in the top arm
	glBegin(GL_QUADS);
	//face 1
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.01, 0.18, 0.22);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.15, 0.18, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.15, 0.15, 0.22);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.16, 0.22);

	//face 2
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.01, 0.18, 0.22);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.15, 0.18, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.15, 0.18, -0.12);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.01, 0.18, -0.12);

	//face 3
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.15, 0.18, 0.22);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.15, 0.15, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.15, 0.15, -0.12);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.15, 0.18, -0.12);

	//face 4
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.15, 0.15, 0.22);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.02, 0.16, 0.22);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.02, 0.18, -0.12);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.15, 0.15, -0.12);

	//face 5
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.02, 0.16, 0.22);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.01, 0.18, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.01, 0.18, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.16, 0.22);

	//face 6
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.01, 0.18, 0.12);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.15, 0.18, 0.12);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.15, 0.15, 0.12);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.02, 0.16, 0.12);
	glEnd();

	//shoulder L size shape
	glBegin(GL_QUADS);
	//face 1
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.02, 0.45, -0.15);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.03, 0.53, -0.15);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, 0.52, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.05, 0.47, -0.15);

	//face 2
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glVertex3f(0.02, 0.45, 0.25);
	glVertex3f(0.02, 0.45, -0.15);
	glVertex3f(-0.03, 0.53, -0.15);
	glVertex3f(0.01, 0.52, -0.15);

	//face 3
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.53, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.01, 0.52, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, 0.52, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.03, 0.53, -0.15);

	//face 4
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, 0.52, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.47, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.47, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, 0.52, -0.15);

	//face 5
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.02, 0.45, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.05, 0.47, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.05, 0.47, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.02, 0.45, -0.15);

	//face 6
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.02, 0.45, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, 0.53, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, 0.52, 0.25);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.05, 0.47, 0.25);
	glEnd();

	glBegin(GL_QUADS);
	//face 1
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.53, -0.15);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.58, -0.15);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.56, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, 0.52, -0.15);

	//face 2
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.53, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.58, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, 0.58, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.03, 0.53, -0.15);

	//face 3
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, 0.58, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.56, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.56, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, 0.58, -0.15);

	//face 4
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, 0.52, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, 0.56, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.56, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, 0.52, -0.15);

	//face 5
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.53, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.01, 0.52, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, 0.52, -0.15);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.03, 0.53, -0.15);

	//face 6
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey13);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey13);
	glColor3f(grey13[0], grey13[1], grey13[2]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.03, 0.53, 0.25);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, 0.58, 0.25);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, 0.56, 0.25);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, 0.52, 0.2);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey14);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey14);
	glColor3f(grey14[0], grey14[1], grey14[2]);
	drawCylinderHand(GLU_FILL, 0.07, 0.09, 0.12, 8, 0.13, 0.37, 0.2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	drawCylinderHand(GLU_LINE, 0.07, 0.09, 0.12, 8, 0.13, 0.37, 0.2);

	glPopMatrix();
	glPopMatrix();
}

void drawLeftArm2() {
	glPushMatrix();
	glScalef(-1, 1, 1);
	glTranslatef(-0.25, 0.7, -0.1);
	glRotatef(leftangleHandMov, leftarm2RxHand, leftarm2RyHand, leftarm2RzHand);
	glRotatef(-12.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.35, 0.0);

	glPushMatrix();
	glScalef(0.4, 0.4, 0.4);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.04, 0.07, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.01, 0.07, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.02, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.02, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.04, 0.07, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.01, 0.07, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.01, 0.07, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.04, 0.07, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.01, 0.07, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, 0.02, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.02, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.01, 0.07, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.02, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.06, 0.02, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.06, 0.02, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.02, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.02, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.04, 0.07, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.04, 0.07, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.02, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.04, 0.07, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.01, 0.07, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.02, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.02, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.02, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, 0.2, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.03, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.07, -0.03, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.02, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, 0.02, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, 0.02, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.06, 0.02, 0.2);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, 0.02, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.03, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.03, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, 0.02, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.03, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.09, -0.08, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.09, -0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.03, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, -0.08, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, -0.03, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.07, -0.03, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, -0.08, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.06, 0.02, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, 0.2, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.03, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.07, -0.03, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, -0.03, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.03, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.08, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, -0.08, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, -0.03, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.03, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.03, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.07, -0.03, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.03, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.08, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.03, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, -0.08, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.08, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, -0.08, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, -0.08, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.07, -0.03, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.07, -0.03, -1.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, -0.08, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, -0.03, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.03, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, -0.08, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, -0.08, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.08, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.14, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.1, -0.14, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, -0.08, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.08, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.09, -0.08, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.08, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.14, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.14, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.08, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.14, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.1, -0.14, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.1, -0.14, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.14, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, -0.14, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.09, -0.08, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.09, -0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.1, -0.14, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.09, -0.08, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.08, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.14, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.1, -0.14, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, -0.14, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.14, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.21, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, -0.2, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, -0.14, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.14, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.14, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.1, -0.14, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.14, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.21, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.21, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.14, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.21, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, -0.2, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.12, -0.2, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.21, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, -0.2, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.1, -0.14, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.1, -0.14, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, -0.2, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.1, -0.14, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.14, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.21, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, -0.2, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, -0.2, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.21, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.28, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.13, -0.27, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, -0.2, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.21, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.21, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, -0.2, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.21, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.28, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.28, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.21, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.28, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.13, -0.27, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.13, -0.27, -1.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.28, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.13, -0.27, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, -0.2, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.12, -0.2, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.13, -0.27, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, -0.2, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.21, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.28, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.13, -0.27, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.13, -0.27, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.28, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.38, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, -0.36, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.13, -0.27, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.28, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.28, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.13, -0.27, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.28, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.38, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.38, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.28, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.38, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.14, -0.36, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.14, -0.36, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.38, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, -0.36, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.13, -0.27, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.13, -0.27, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, -0.36, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.13, -0.27, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.28, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.38, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, -0.36, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, -0.36, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.38, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.47, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, -0.45, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, -0.36, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.38, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.38, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.14, -0.36, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.38, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.47, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.47, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.38, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.47, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.16, -0.45, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.16, -0.45, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.47, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, -0.45, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.14, -0.36, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.14, -0.36, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, -0.45, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.14, -0.36, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.38, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.47, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, -0.45, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, -0.45, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.47, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.55, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, -0.54, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, -0.45, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.47, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.47, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, -0.45, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.47, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.55, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.55, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.47, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.55, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.16, -0.54, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.16, -0.54, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.55, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, -0.54, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.16, -0.45, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.16, -0.45, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, -0.54, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, -0.45, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.47, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.55, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, -0.54, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, -0.54, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.55, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.6, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, -0.73, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, -0.54, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.55, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.55, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.16, -0.54, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.55, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.6, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.6, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.55, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.6, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.12, -0.73, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.12, -0.73, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.6, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.12, -0.73, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.16, -0.54, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.16, -0.54, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, -0.73, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.16, -0.54, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.55, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.6, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.12, -0.73, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.17, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, 0.0, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.28, -0.09, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.28, -0.15, 0.1);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.17, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, 0.0, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, 0.0, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.17, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, 0.0, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.28, -0.09, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.28, -0.09, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, 0.0, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.28, -0.09, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.28, -0.15, 0.10);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.28, -0.15, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.28, -0.09, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.28, -0.15, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.17, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.17, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.28, -0.15, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.17, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.28, -0.09, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.28, -0.15, 0.0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.3, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.17, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.28, -0.15, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.28, -0.25, 0.1);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.3, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.17, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.3, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.17, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.17, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.28, -0.15, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.28, -0.15, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.17, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.28, -0.15, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.28, -0.25, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.28, -0.25, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.28, -0.15, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.28, -0.25, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.3, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.3, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.28, -0.25, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.3, 0.0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.17, 0.0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.28, -0.15, 0.0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.28, -0.25, 0.0);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.05, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.02, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.08, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.11, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.05, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.02, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.02, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.05, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.02, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.08, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.02, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.08, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.11, 0.2);
	glTexCoord2f(11.0f, 0.0f);
	glVertex3f(0.0, -0.11, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.08, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.11, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.05, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.05, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.11, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.05, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.02, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.08, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.11, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.19, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.15, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.2, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.23, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.19, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.15, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.15, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.19, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.15, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.2, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.2, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.15, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.2, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.19, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.19, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.2, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.23, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.19, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.19, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.23, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.19, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.15, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.2, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.23, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.3, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.28, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.33, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.35, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.3, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.28, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.28, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.3, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.28, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.33, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.33, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.28, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.33, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.35, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.35, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.33, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.35, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.3, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.3, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.35, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.3, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.28, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.33, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.35, -0.1);
	glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.41, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.4, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.45, 0.2);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.47, 0.2);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.41, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.4, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.4, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.41, -0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.4, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.45, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.45, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.4, -0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.45, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.47, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.47, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.45, -0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.47, 0.2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.41, 0.2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.41, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.47, -0.1);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.41, -0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.4, -0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.45, -0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.47, -0.1);
	glEnd();

	glPopMatrix();
	glPopMatrix();
}

void drawLeftHand() {
	glPushMatrix();
	glScalef(-1, 1, 1);
	glTranslatef(-0.25, 0.7, -0.1);
	glRotatef(leftangleHandMov, lefthandRxHand, lefthandRyHand, lefthandRzHand);
	glRotatef(-12.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.35, 0.0);

	glPushMatrix();
	glScalef(0.4, 0.4, 0.4);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//RIGHT - Lpalm	
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, -0.6, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.01, -0.69, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, -0.6, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, -0.6, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, -0.6, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, -0.69, 0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, -0.6, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.01, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, -0.6, 0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.01, -0.69, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.1);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, -0.6, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, -0.6, 0.0);

	//face 6 
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, -0.6, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.6, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, -0.6, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, -0.6, 0.0);

	//RIGHT - Rpalm
	//face 1 
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, -0.6, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.68, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, -0.6, 0.1);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.68, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.2, -0.68, 0.1);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.2, -0.68, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.2, -0.68, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, -0.6, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, -0.6, 0.1);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, -0.6, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.6, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.17, -0.6, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.17, -0.6, 0.1);

	//face 5 
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.6, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, -0.6, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.13, -0.6, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.17, -0.6, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.2, -0.68, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glEnd();

	glPopMatrix();
	glPopMatrix();
}

void drawLeftFingers() {
	glPushMatrix();
	glScalef(-1, 1, 1);
	glTranslatef(-0.25, 0.7, -0.1);
	glRotatef(leftangleHandMov, leftfingerRxHand, leftfingerRyHand, leftfingerRzHand);
	glRotatef(-12.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.35, 0.0);

	glPushMatrix();
	glScalef(0.4, 0.4, 0.4);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
	glBegin(GL_QUADS);
	//little finger
	//first
	//face 1 - base
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, -0.69, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, -0.69, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.76, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.76, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.01, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.01, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.76, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.01, -0.69, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.76, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.76, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.01, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.76, 0.1);

	//second 
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.76, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.83, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.83, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0, -0.76, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0, -0.76, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.83, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.76, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0, -0.76, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.83, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.83, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0, -0.76, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.83, 0.1);

	//third
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.83, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.86, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.88, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.88, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, -0.83, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, -0.83, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.88, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.83, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.83, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.86, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.86, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.88, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, -0.86, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.86, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.88, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.83, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.86, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.88, 0.1);

	//wu ming zhi
	//first 
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, -0.69, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, -0.69, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.04, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.04, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.04, -0.69, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.04, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.1);

	//second
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.03, -0.75, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.03, -0.75, 0.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);

	//third
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.84, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.86, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.86, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.86, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.81, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.84, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.84, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.86, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, -0.84, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.84, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.86, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.81, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.84, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.86, 0.1);

	//zhong zhi
	//first - face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, -0.69, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, -0.69, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.07, -0.69, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.07, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.1);

	//second
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.06, -0.75, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.06, -0.75, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.1);

	//third
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.82, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.84, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.84, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.08, -0.79, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.84, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);
	glTexCoord2f(0.0f, .0f);
	glVertex3f(0.08, -0.79, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, -0.82, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, -0.82, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.84, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, -0.82, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.82, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.84, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.08, -0.79, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.82, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.84, 0.1);

	//shi zhi
	//first - face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, -0.69, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, -0.73, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.1, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.1, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.1, -0.69, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.12, -0.73, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.13, -0.69, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.12, -0.73, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, -0.73, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, -0.73, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.1, -0.69, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.13, -0.69, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, -0.73, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.1);

	//second
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, -0.73, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.76, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, -0.73, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, -0.73, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.09, -0.74, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, -0.76, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, -0.73, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.12, -0.73, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, -0.76, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, -0.76, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.76, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.09, -0.74, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.12, -0.73, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.76, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.1);

	//third
	//face 1
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, -0.76, 0.0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, -0.8, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, -0.82, 0.0);

	//face 2
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, -0.82, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, -0.82, 0.0);

	//face 3
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, -0.76, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.76, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.11, -0.78, 0.0);

	//face 4
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.16, -0.8, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, -0.76, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.14, -0.76, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.16, -0.8, 0.0);

	//face 5
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.14, -0.82, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.16, -0.8, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, -0.8, 0.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, -0.82, 0.0);

	//face 6
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.11, -0.78, 0.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.14, -0.76, 0.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.16, -0.8, 0.1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.14, -0.82, 0.1);
	glEnd();

	glPopMatrix();
	glPopMatrix();
}

void drawLeftFingers2() {
	glPushMatrix();
	glScalef(-1, 1, 1);
	glTranslatef(-0.25, 0.7, -0.1);
	glRotatef(leftangleHandMov, leftfinger2RxHand, leftfinger2RyHand, leftfinger2RzHand);
	glRotatef(-12.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.35, 0.0);


	glPushMatrix();
	glScalef(0.4, 0.4, 0.4);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grey2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, grey2);
	glColor3f(grey2[0], grey2[1], grey2[2]);
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

	glPopMatrix();
	glPopMatrix();
}

void robotHand() {
	glPushMatrix();
	glTranslatef(0.0, 0.0, tzWalk);
	
	drawShoulderArm();
	

	drawHand();
	drawFingers2();

	glPushMatrix();
	glRotatef(fingerRotationAngle, 0.0, 0.0, 1.0);
	drawFingers();
	glPopMatrix();

	drawArm2();

	drawLeftShoulderArm();
	drawLeftHand();
	drawLeftFingers2();
	glPushMatrix();
	glRotatef(fingerRotationAngle, 0.0, 0.0, 1.0);
	drawLeftFingers();
	glPopMatrix();
	drawLeftArm2();

	glPopMatrix();

}

void background() {
	glPushMatrix();
	//glTranslatef(tx/4, ty/4, tz/4);
	//glTranslatef(0, 0, -1);
	glColor3f(0.5, 0.5, 0.5);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-10, -10, -10);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-10, 10, -10);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(10, 10, -10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(10, -10, -10);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-10, -10, 10);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-10, 10, 10);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(10, 10, 10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(10, -10, 10);
	glEnd();
	
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-10, -10, -10);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-10, -10, 10);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-10, 10, 10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-10, 10, -10);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(10, 10, -10);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(10, 10, 10);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(10, -10, 10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(10, -10, -10);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-10, -10, -10);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-10, -10, 10);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(10, -10, 10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(10, -10, -10);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(10, 10, -10);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(10, 10, 10);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-10, 10, 10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-10, 10, -10);
	glEnd();
	glPopMatrix();
}

//void projection() {
//	glMatrixMode(GL_PROJECTION);					//refer to the projection matrix
//	glLoadIdentity();								//reset the projection matrix
//
//	glTranslatef(ptx, pty, 0.0);					//translate x and y for projection
//	glRotatef(pRy, 0.0, 1.0, 0.0);					//rotate y for projection
//	if (isOrtho) {
//		//Ortho view
//		glTranslatef(0, -0.3, 0);
//		glOrtho(-2.0, 2.0, -2.0, 2.0, ONear, OFar);
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//	}
//	else {
//		//Perspective view
//		gluPerspective(20, 1.0, -1.0, 1.0);
//		glFrustum(-5, 5, -5, 5, PNear, PFar); // x and y can use but z cannot because it is placing behind the camera
//	}
//}

void camera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float angleRad = twist * M_PI / 180.0f;  // Common angle for both views, converted to radians

	
	if (isOrtho) {
		glOrtho(-1.0, 1.0, -1.0, 1.0, 0.1, 1000);
		float camX = 10.0 * cos(angleRad);  // Scale these appropriately
		float camZ = 10.0 * sin(angleRad);
		glTranslatef(-cameraX, -cameraY, 0.0f);
		gluLookAt(camX, 0.0, camZ,   // Position camera far out along the same direction
			0.0, 0.0, 0.0,     // Look at the origin
			0.0, 1.0, 0.0);    // Up vector remains consistent
	}
	else {
		cameraX = 0.0f;
		cameraY = 0.0f;
		float fov = 60.0 - cameraZ * 5;
		fov = max(fov, 10.0);  // Limit the FOV to prevent extreme distortion
		gluPerspective(fov, (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 0.1, 1000);

		float radius = max(0.5, 2.0 + cameraZ);
		float camX = radius * cos(angleRad);
		float camZ = radius * sin(angleRad);

		gluLookAt(camX, camY, camZ,
			0.0, 0.0, 0.0,
			0.0, 1.0, 0.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void lighting()
{
	if (isLightOn) {
		glEnable(GL_LIGHTING);
		glLightfv(GL_LIGHT1, GL_AMBIENT, ambL);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, difL);
		glEnable(GL_LIGHT1);
	}
	else {
		glDisable(GL_LIGHTING);
	}
}

GLuint loadTexture(LPCSTR filename) {
	//take from step 1
	GLuint texture = 0;		//texture name

	//Step 3: Initialize texture Info
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), filename, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	GetObject(hBMP, sizeof(BMP), &BMP);

	//Step 4: Assign texture to polygon
	if (textureOnOff) {
		glEnable(GL_TEXTURE_2D);
	}
	else if (!textureOnOff){
		glDisable(GL_TEXTURE_2D);
	}
	
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	//take from stpe 5
	DeleteObject(hBMP);
	return texture;
}

void display()
{
	//--------------------------------
	//	OpenGL drawing
	//--------------------------------
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	lighting();

	camera();
	glRotatef(90, 0.0, 1.0, 0.0);
	glPushMatrix();
	
	
	
	glMatrixMode(GL_MODELVIEW);
	
	//glLoadIdentity();
	//gluLookAt(0 + (radius) * cos(degree * 3.1415 / 180), eyeY, 0 + (radius) * sin(degree * 3.1415 / 180), 0.0f, 0.0f, 0.0f, 0, 1, 0);
	glTranslatef(tx, ty, tz);

	/*glPushMatrix();
	glTranslatef(0.0, 0.0, tzWalk);*/
	glPushMatrix();
	glTranslatef(-0.1, 0.55, 0);
	glRotatef(angleHeadMov, rxHead, ryHead, 0.0);
	glTranslatef(0.1, -0.55, 0);

	GLuint textureArr[5];
	if (Texture == true && Texture2 == false) {
		textureArr[0] = loadTexture("bg.bmp");
		background();
		glDeleteTextures(1, &textureArr[0]);
		glDisable(GL_TEXTURE_2D);

		textureArr[1] = loadTexture("robot3.bmp");
		head();
		glDeleteTextures(1, &textureArr[1]);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		textureArr[2] = loadTexture("robot2.bmp");
		body();
		glDeleteTextures(1, &textureArr[2]);
		glDisable(GL_TEXTURE_2D);

		textureArr[3] = loadTexture("robot4.bmp");
		robotHand();
		glDeleteTextures(1, &textureArr[3]);
		glDisable(GL_TEXTURE_2D);

		textureArr[4] = loadTexture("robot.bmp");
		leg();
		glDeleteTextures(1, &textureArr[4]);
		glDisable(GL_TEXTURE_2D);
	}
	else if (Texture == false && Texture2 == true) {
		textureArr[0] = loadTexture("bg.bmp");
		background();
		glDeleteTextures(1, &textureArr[0]);
		glDisable(GL_TEXTURE_2D);

		textureArr[1] = loadTexture("robot3.bmp");
		head();
		glDeleteTextures(1, &textureArr[1]);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		textureArr[2] = loadTexture("robot2.bmp");
		body();
		glDeleteTextures(1, &textureArr[2]);
		glDisable(GL_TEXTURE_2D);

		textureArr[3] = loadTexture("robot5.bmp");
		robotHand();
		glDeleteTextures(1, &textureArr[3]);
		glDisable(GL_TEXTURE_2D);

		textureArr[4] = loadTexture("robot6.bmp");
		leg();
		glDeleteTextures(1, &textureArr[4]);
		glDisable(GL_TEXTURE_2D);
	}
	

	if (isEquip) {
		weapon();
	}

	glPopMatrix();

	glPushMatrix();
	GLfloat posD[4] = { lightX, lightY, lightZ, 1 };
	glLightfv(GL_LIGHT1, GL_POSITION, posD);
	glPopMatrix();
	
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
		CW_USEDEFAULT, CW_USEDEFAULT, 1000, 1000,
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