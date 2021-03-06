#include <Windows.h>
#include <gl/glut.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

void tampil(void);
void Mouse(int button, int state, int x, int y);
void MouseMove(int x, int y);

using namespace std;
const float BOX_SIZE = 7.0f;
float _angle = 0;
void init(void);
void keyboard(unsigned char, int, int);
void ukuran (int, int);

typedef struct{
	bool leftButton;
	bool rightButton;
	int x;
	int y;
} MouseState;
MouseState mouseState = {false, false, 0, 0 };

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;


void lapanganxlantai(){
	//pagarlapangandepan
	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex3f(75.0, 0.0, 50.0);
	glVertex3f(75.0, 10.0, 50.0);
	glVertex3f(-75.0, 10.0, 50.0);
	glVertex3f(-75.0, 0.0,50.0);
	glEnd();

	//pagarlapanganbelakang
	glBegin(GL_QUADS);
	glVertex3f(75.0, 0.0, -53.0);
	glVertex3f(75.0, 10.0, -53.0);
	glVertex3f(-75.0, 10.0, -53.0);
	glVertex3f(-75.0, 0.0, -53.0);
	glEnd();
	//pagarlapangankiri
	glBegin(GL_QUADS);
	glVertex3f(-75.0, 0.0, -48.0);
	glVertex3f(-75.0, 10.0, -48.0);
	glVertex3f(-75.0, 10.0, 48.0);
	glVertex3f(-75.0, 0.0, 48.0);
	glEnd();

	//pagarlapangankanan
	glBegin(GL_QUADS);
	glVertex3f(75.0, 0.0, -48.0);
	glVertex3f(75.0, 10.0, -48.0);
	glVertex3f(75.0, 10.0, 48.0);
	glVertex3f(75.0, 0.0, 48.0);
	glEnd();

	//BangkuCadangan1
	glBegin(GL_QUADS);
	glColor3f(0.75,0.75,0.75);
	glVertex3f(50.0, 0.0, -52.0);
	glVertex3f(50.0, 15.0, -52.0);
	glVertex3f(20.0, 15.0, -52.0);
	glVertex3f(20.0, 0.0, -52.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(50.0, 0.0, -48.0);
	glVertex3f(50.0, 5.0, -48.0);
	glVertex3f(20.0, 5.0, -48.0);
	glVertex3f(20.0, 0.0, -48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,0.0,0.0);
	glVertex3f(50.0, 5.0, -48.0);
	glVertex3f(50.0, 5.0, -52.0);
	glVertex3f(20.0, 5.0, -52.0);
	glVertex3f(20.0, 5.0, -48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(50.0, 15.0, -42.0);
	glVertex3f(50.0, 15.0, -52.0);
	glVertex3f(20.0, 15.0, -52.0);
	glVertex3f(20.0, 15.0, -42.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(20.0, 15.0, -52.0);
	glVertex3f(20.0, 0.0, -52.0);
	glVertex3f(20.0, 15.0, -42.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(50.0, 0.0, -52.0);
	glVertex3f(50.0, 15.0, -52.0);
	glVertex3f(50.0, 15.0, -42.0);
	glEnd();

	//BangkuCadangan2
	glBegin(GL_QUADS);
	glColor3f(0.75,0.75,0.75);
	glVertex3f(-50.0, 0.0, -52.0);
	glVertex3f(-50.0, 15.0, -52.0);
	glVertex3f(-20.0, 15.0, -52.0);
	glVertex3f(-20.0, 0.0, -52.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-50.0, 0.0, -48.0);
	glVertex3f(-50.0, 5.0, -48.0);
	glVertex3f(-20.0, 5.0, -48.0);
	glVertex3f(-20.0, 0.0, -48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,0.0,0.0);
	glVertex3f(-50.0, 5.0, -48.0);
	glVertex3f(-50.0, 5.0, -52.0);
	glVertex3f(-20.0, 5.0, -52.0);
	glVertex3f(-20.0, 5.0, -48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-50.0, 15.0, -42.0);
	glVertex3f(-50.0, 15.0, -52.0);
	glVertex3f(-20.0, 15.0, -52.0);
	glVertex3f(-20.0, 15.0, -42.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-20.0, 15.0, -52.0);
	glVertex3f(-20.0, 0.0, -52.0);
	glVertex3f(-20.0, 15.0, -42.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-50.0, 0.0, -52.0);
	glVertex3f(-50.0, 15.0, -52.0);
	glVertex3f(-50.0, 15.0, -42.0);
	glEnd();

	//KursiPenontonKiri
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_QUADS);
	glVertex3f(-85.0, 0.0, -75.0);
	glVertex3f(-85.0, 7.0, -75.0);
	glVertex3f(-85.0, 7.0, 75.0);
	glVertex3f(-85.0, 0.0, 75.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-85.0, 7.0, -75.0);
	glVertex3f(-110.0, 20.0, -72.0);
	glVertex3f(-110.0, 20.0, 72.0);
	glVertex3f(-85.0, 7.0, 75.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-110.0, 0.0, -72.0);
	glVertex3f(-110.0, 28.0, -72.0);
	glVertex3f(-110.0, 28.0, 72.0);
	glVertex3f(-110.0, 0.0, 72.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-110.0, 28.0, -72.0);
	glVertex3f(-130.0,38.0, -48.0);
	glVertex3f(-130.0,38.0, 48.0);
	glVertex3f(-110.0, 28.0, 72.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-130.0, 0.0, -48.0);
	glVertex3f(-130.0, 42.0, -48.0);
	glVertex3f(-130.0, 42.0, 48.0);
	glVertex3f(-130.0, 0.0, 48.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-130.0, 42.0, -48.0);
	glVertex3f(-157.0,50.0, -25.0);
	glVertex3f(-157.0,50.0, 25.0);
	glVertex3f(-130.0,42.0, 48.0);
	glEnd();

	//KursiPenontonKanan
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_QUADS);
	glVertex3f(85.0, 0.0, -75.0);
	glVertex3f(85.0, 7.0, -75.0);
	glVertex3f(85.0, 7.0, 75.0);
	glVertex3f(85.0, 0.0, 75.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(85.0, 7.0, -75.0);
	glVertex3f(110.0, 20.0, -72.0);
	glVertex3f(110.0, 20.0, 72.0);
	glVertex3f(85.0, 7.0, 75.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(110.0, 0.0, -72.0);
	glVertex3f(110.0, 28.0, -72.0);
	glVertex3f(110.0, 28.0, 72.0);
	glVertex3f(110.0, 0.0, 72.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(110.0, 28.0, -72.0);
	glVertex3f(130.0,38.0, -48.0);
	glVertex3f(130.0,38.0, 48.0);
	glVertex3f(110.0, 28.0, 72.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(130.0, 0.0, -48.0);
	glVertex3f(130.0, 42.0, -48.0);
	glVertex3f(130.0, 42.0, 48.0);
	glVertex3f(130.0, 0.0, 48.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(130.0, 42.0, -48.0);
	glVertex3f(157.0,50.0, -25.0);
	glVertex3f(157.0,50.0, 25.0);
	glVertex3f(130.0,42.0, 48.0);
	glEnd();

	//KursiPenontonBelakang
	glBegin(GL_QUADS);
	glVertex3f(90.0, 0.0, -60.0);
	glVertex3f(90.0, 7.0, -60.0);
	glVertex3f(-90.0, 7.0, -60.0);
	glVertex3f(-90.0, 0.0, -60.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(90.0, 7.0, -60.0);
	glVertex3f(90.0,7.0, -70.0);
	glVertex3f(-90.0, 7.0, -70.0);
	glVertex3f(-90.0, 7.0, -60.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(90.0, 0.0, -70.0);
	glVertex3f(90.0, 14.0, -70.0);
	glVertex3f(-90.0,14.0, -70.0);
	glVertex3f(-90.0, 0.0, -70.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(90.0, 14.0, -70.0);
	glVertex3f(90.0,14.0, -75.0);
	glVertex3f(-90.0, 14.0, -75.0);
	glVertex3f(-90.0, 14.0, -70.0);
	glEnd();

	//KursiPenontonDepan
	glBegin(GL_QUADS);
	glVertex3f(90.0, 0.0, 60.0);
	glVertex3f(90.0, 7.0, 60.0);
	glVertex3f(-90.0, 7.0,60.0);
	glVertex3f(-90.0, 0.0,60.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(90.0, 7.0, 60.0);
	glVertex3f(90.0,7.0, 70.0);
	glVertex3f(-90.0, 7.0, 70.0);
	glVertex3f(-90.0, 7.0, 60.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(90.0, 0.0, 70.0);
	glVertex3f(90.0, 14.0, 70.0);
	glVertex3f(-90.0,14.0, 70.0);
	glVertex3f(-90.0, 0.0, 70.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(90.0, 14.0, 70.0);
	glVertex3f(90.0,14.0, 75.0);
	glVertex3f(-90.0, 14.0, 75.0);
	glVertex3f(-90.0, 14.0, 70.0);
	glEnd();

	//GarisKursipenontonbelakang
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(85.0, 7.0, -60.0);
	glVertex3f(-85.0, 7.0, -60.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(85.0, 7.0, -60.0);
	glVertex3f(85.0,7.0, -70.0);
	glVertex3f(-85.0, 7.0, -70.0);
	glVertex3f(-85.0, 7.0, -60.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(90.0, 14.0, -70.0);
	glVertex3f(-90.0,14.0, -70.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(90.0, 14.0, -70.0);
	glVertex3f(90.0,14.0, -75.0);
	glVertex3f(-90.0, 14.0, -75.0);
	glVertex3f(-90.0, 14.0, -70.0);
	glEnd();

	//GarisKursipenontondepan
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(85.0, 7.0, 60.0);
	glVertex3f(-85.0, 7.0, 60.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(85.0, 7.0, 60.0);
	glVertex3f(85.0,7.0, 70.0);
	glVertex3f(-85.0, 7.0, 70.0);
	glVertex3f(-85.0, 7.0, 60.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(90.0, 14.0, 70.0);
	glVertex3f(-90.0,14.0, 70.0);

	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(90.0, 14.0, 70.0);
	glVertex3f(90.0,14.0, 75.0);
	glVertex3f(-90.0, 14.0, 75.0);
	glVertex3f(-90.0, 14.0, 70.0);
	glEnd();

	//GarisKursipenontonKiri
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-85.0, 0.0, -75.0);
	glVertex3f(-85.0, 7.0, -75.0);
	glVertex3f(-85.0, 7.0, 75.0);
	glVertex3f(-85.0, 0.0, 75.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(-85.0, 7.0, -75.0);
	glVertex3f(-110.0, 20.0, -72.0);
	glVertex3f(-110.0, 20.0, 72.0);
	glVertex3f(-85.0, 7.0, 75.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(-110.0, 0.0, -72.0);
	glVertex3f(-110.0, 28.0, -72.0);
	glVertex3f(-110.0, 28.0, 72.0);
	glVertex3f(-110.0, 0.0, 72.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(-110.0, 28.0, -72.0);
	glVertex3f(-130.0,38.0, -48.0);
	glVertex3f(-130.0,38.0, 48.0);
	glVertex3f(-110.0, 28.0, 72.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(-130.0, 0.0, -48.0);
	glVertex3f(-130.0, 42.0, -48.0);
	glVertex3f(-130.0, 42.0, 48.0);
	glVertex3f(-130.0, 0.0, 48.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(-130.0, 42.0, -48.0);
	glVertex3f(-157.0,50.0, -25.0);
	glVertex3f(-157.0,50.0, 25.0);
	glVertex3f(-130.0,42.0, 48.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-85.0, 7.0, -27.0);
	glVertex3f(-110.0, 20.0, -25.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-85.0, 7.0, 27.0);
	glVertex3f(-110.0, 20.0, 25.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-110.0, 28.0, -27.0);
	glVertex3f(-130.0,38.0, -25.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-110.0, 28.0, 27.0);
	glVertex3f(-130.0,38.0, 25.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-130.0, 42.0, -27.0);
	glVertex3f(-157.0,50.0, -25.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-130.0, 42.0,27.0);
	glVertex3f(-157.0,50.0, 25.0);
	glEnd();

	//GarisKursipenontonKiri
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(85.0, 0.0, -75.0);
	glVertex3f(85.0, 7.0, -75.0);
	glVertex3f(85.0, 7.0, 75.0);
	glVertex3f(85.0, 0.0, 75.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(85.0, 7.0, -75.0);
	glVertex3f(110.0, 20.0, -72.0);
	glVertex3f(110.0, 20.0, 72.0);
	glVertex3f(85.0, 7.0, 75.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(110.0, 0.0, -72.0);
	glVertex3f(110.0, 28.0, -72.0);
	glVertex3f(110.0, 28.0, 72.0);
	glVertex3f(110.0, 0.0, 72.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(110.0, 28.0, -72.0);
	glVertex3f(130.0,38.0, -48.0);
	glVertex3f(130.0,38.0, 48.0);
	glVertex3f(110.0, 28.0, 72.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(130.0, 0.0, -48.0);
	glVertex3f(130.0, 42.0, -48.0);
	glVertex3f(130.0, 42.0, 48.0);
	glVertex3f(130.0, 0.0, 48.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(130.0, 42.0, -48.0);
	glVertex3f(157.0,50.0, -25.0);
	glVertex3f(157.0,50.0, 25.0);
	glVertex3f(130.0,42.0, 48.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(85.0, 7.0, -27.0);
	glVertex3f(110.0, 20.0, -25.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(85.0, 7.0, 27.0);
	glVertex3f(110.0, 20.0, 25.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(110.0, 28.0, -27.0);
	glVertex3f(130.0,38.0, -25.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(110.0, 28.0, 27.0);
	glVertex3f(130.0,38.0, 25.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(130.0, 42.0, -27.0);
	glVertex3f(157.0,50.0, -25.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(130.0, 42.0,27.0);
	glVertex3f(157.0,50.0, 25.0);
	glEnd();

	//kakigawang kiri
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 0.0, 6.5);
	glVertex3f(-78.0, 0.0, 6.5);
	glVertex3f(-78.0, 0.5, 6.5);
	glVertex3f(-73.0, 0.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 1.0, 6.5);
	glVertex3f(-78.0, 1.0, 6.5);
	glVertex3f(-78.0, 1.5, 6.5);
	glVertex3f(-73.0, 1.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 2.0, 6.5);
	glVertex3f(-78.0, 2.0, 6.5);
	glVertex3f(-78.0, 2.5, 6.5);
	glVertex3f(-73.0, 2.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 3.0, 6.5);
	glVertex3f(-78.0, 3.0, 6.5);
	glVertex3f(-78.0, 3.5, 6.5);
	glVertex3f(-73.0, 3.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 4.0, 6.5);
	glVertex3f(-78.0, 4.0, 6.5);
	glVertex3f(-78.0, 4.5, 6.5);
	glVertex3f(-73.0, 4.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 5.0, 6.5);
	glVertex3f(-78.0, 5.0, 6.5);
	glVertex3f(-78.0, 5.5, 6.5);
	glVertex3f(-73.0, 5.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 6.0, 6.5);
	glVertex3f(-78.0, 6.0, 6.5);
	glVertex3f(-78.0, 6.5, 6.5);
	glVertex3f(-73.0, 6.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 7.0, 6.5);
	glVertex3f(-78.0, 7.0, 6.5);
	glVertex3f(-78.0, 7.5, 6.5);
	glVertex3f(-73.0, 7.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 8.0, 6.5);
	glVertex3f(-78.0, 8.0, 6.5);
	glVertex3f(-78.0, 8.5, 6.5);
	glVertex3f(-73.0, 8.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 0.0, -6.5);
	glVertex3f(-78.0, 0.0, -6.5);
	glVertex3f(-78.0, 0.5, -6.5);
	glVertex3f(-73.0, 0.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 1.0, -6.5);
	glVertex3f(-78.0, 1.0, -6.5);
	glVertex3f(-78.0, 1.5, -6.5);
	glVertex3f(-73.0, 1.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 2.0, -6.5);
	glVertex3f(-78.0, 2.0, -6.5);
	glVertex3f(-78.0, 2.5, -6.5);
	glVertex3f(-73.0, 2.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 3.0, -6.5);
	glVertex3f(-78.0, 3.0, -6.5);
	glVertex3f(-78.0, 3.5, -6.5);
	glVertex3f(-73.0, 3.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 4.0, -6.5);
	glVertex3f(-78.0, 4.0, -6.5);
	glVertex3f(-78.0, 4.5, -6.5);
	glVertex3f(-73.0, 4.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 5.0, -6.5);
	glVertex3f(-78.0, 5.0, -6.5);
	glVertex3f(-78.0, 5.5, -6.5);
	glVertex3f(-73.0, 5.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 6.0, -6.5);
	glVertex3f(-78.0, 6.0, -6.5);
	glVertex3f(-78.0, 6.5, -6.5);
	glVertex3f(-73.0, 6.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 7.0, -6.5);
	glVertex3f(-78.0, 7.0, -6.5);
	glVertex3f(-78.0, 7.5, -6.5);
	glVertex3f(-73.0, 7.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 8.0, -6.5);
	glVertex3f(-78.0, 8.0, -6.5);
	glVertex3f(-78.0, 8.5, -6.5);
	glVertex3f(-73.0, 8.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 0.0, -6.5);
	glVertex3f(-78.0, 0.0, 6.5);
	glVertex3f(-78.0, 0.5, 6.5);
	glVertex3f(-78.0, 0.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 1.0, -6.5);
	glVertex3f(-78.0, 1.0, 6.5);
	glVertex3f(-78.0, 1.5, 6.5);
	glVertex3f(-78.0, 1.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 2.0, -6.5);
	glVertex3f(-78.0, 2.0, 6.5);
	glVertex3f(-78.0, 2.5, 6.5);
	glVertex3f(-78.0, 2.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 3.0, -6.5);
	glVertex3f(-78.0, 3.0, 6.5);
	glVertex3f(-78.0, 3.5, 6.5);
	glVertex3f(-78.0, 3.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 4.0, -6.5);
	glVertex3f(-78.0, 4.0, 6.5);
	glVertex3f(-78.0, 4.5, 6.5);
	glVertex3f(-78.0, 4.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 5.0, -6.5);
	glVertex3f(-78.0, 5.0, 6.5);
	glVertex3f(-78.0, 5.5, 6.5);
	glVertex3f(-78.0, 5.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 6.0, -6.5);
	glVertex3f(-78.0, 6.0, 6.5);
	glVertex3f(-78.0, 6.5, 6.5);
	glVertex3f(-78.0, 6.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 7.0, -6.5);
	glVertex3f(-78.0, 7.0, 6.5);
	glVertex3f(-78.0, 7.5, 6.5);
	glVertex3f(-78.0, 7.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 8.0, -6.5);
	glVertex3f(-78.0, 8.0, 6.5);
	glVertex3f(-78.0, 8.5, 6.5);
	glVertex3f(-78.0, 8.5, -6.5);
	glEnd();

	//sampingka-kigawangkanan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 0.0, 6.5);
	glVertex3f(78.0, 0.0, 6.5);
	glVertex3f(78.0, 0.5, 6.5);
	glVertex3f(73.0, 0.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 1.0, 6.5);
	glVertex3f(78.0, 1.0, 6.5);
	glVertex3f(78.0, 1.5, 6.5);
	glVertex3f(73.0, 1.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 2.0, 6.5);
	glVertex3f(78.0, 2.0, 6.5);
	glVertex3f(78.0, 2.5, 6.5);
	glVertex3f(73.0, 2.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 3.0, 6.5);
	glVertex3f(78.0, 3.0, 6.5);
	glVertex3f(78.0, 3.5, 6.5);
	glVertex3f(73.0, 3.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 4.0, 6.5);
	glVertex3f(78.0, 4.0, 6.5);
	glVertex3f(78.0, 4.5, 6.5);
	glVertex3f(73.0, 4.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 5.0, 6.5);
	glVertex3f(78.0, 5.0, 6.5);
	glVertex3f(78.0, 5.5, 6.5);
	glVertex3f(73.0, 5.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 6.0, 6.5);
	glVertex3f(78.0, 6.0, 6.5);
	glVertex3f(78.0, 6.5, 6.5);
	glVertex3f(73.0, 6.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 7.0, 6.5);
	glVertex3f(78.0, 7.0, 6.5);
	glVertex3f(78.0, 7.5, 6.5);
	glVertex3f(73.0, 7.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 8.0, 6.5);
	glVertex3f(78.0, 8.0, 6.5);
	glVertex3f(78.0, 8.5, 6.5);
	glVertex3f(73.0, 8.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 0.0, -6.5);
	glVertex3f(78.0, 0.0, -6.5);
	glVertex3f(78.0, 0.5, -6.5);
	glVertex3f(73.0, 0.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 1.0, -6.5);
	glVertex3f(78.0, 1.0, -6.5);
	glVertex3f(78.0, 1.5, -6.5);
	glVertex3f(73.0, 1.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 2.0, -6.5);
	glVertex3f(78.0, 2.0, -6.5);
	glVertex3f(78.0, 2.5, -6.5);
	glVertex3f(73.0, 2.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 3.0, -6.5);
	glVertex3f(78.0, 3.0, -6.5);
	glVertex3f(78.0, 3.5, -6.5);
	glVertex3f(73.0, 3.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 4.0, -6.5);
	glVertex3f(78.0, 4.0, -6.5);
	glVertex3f(78.0, 4.5, -6.5);
	glVertex3f(73.0, 4.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 5.0, -6.5);
	glVertex3f(78.0, 5.0, -6.5);
	glVertex3f(78.0, 5.5, -6.5);
	glVertex3f(73.0, 5.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 6.0, -6.5);
	glVertex3f(78.0, 6.0, -6.5);
	glVertex3f(78.0, 6.5, -6.5);
	glVertex3f(73.0, 6.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 7.0, -6.5);
	glVertex3f(78.0, 7.0, -6.5);
	glVertex3f(78.0, 7.5, -6.5);
	glVertex3f(73.0, 7.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 8.0, -6.5);
	glVertex3f(78.0, 8.0, -6.5);
	glVertex3f(78.0, 8.5, -6.5);
	glVertex3f(73.0, 8.5, -6.5);
	glEnd();

	//belakangkanangawang
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 0.0, -6.5);
	glVertex3f(78.0, 0.0, 6.5);
	glVertex3f(78.0, 0.5, 6.5);
	glVertex3f(78.0, 0.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 1.0, -6.5);
	glVertex3f(78.0, 1.0, 6.5);
	glVertex3f(78.0, 1.5, 6.5);
	glVertex3f(78.0, 1.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 2.0, -6.5);
	glVertex3f(78.0, 2.0, 6.5);
	glVertex3f(78.0, 2.5, 6.5);
	glVertex3f(78.0, 2.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 3.0, -6.5);
	glVertex3f(78.0, 3.0, 6.5);
	glVertex3f(78.0, 3.5, 6.5);
	glVertex3f(78.0, 3.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 4.0, -6.5);
	glVertex3f(78.0, 4.0, 6.5);
	glVertex3f(78.0, 4.5, 6.5);
	glVertex3f(78.0, 4.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 5.0, -6.5);
	glVertex3f(78.0, 5.0, 6.5);
	glVertex3f(78.0, 5.5, 6.5);
	glVertex3f(78.0, 5.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 6.0, -6.5);
	glVertex3f(78.0, 6.0, 6.5);
	glVertex3f(78.0, 6.5, 6.5);
	glVertex3f(78.0, 6.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 7.0, -6.5);
	glVertex3f(78.0, 7.0, 6.5);
	glVertex3f(78.0, 7.5, 6.5);
	glVertex3f(78.0, 7.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 8.0, -6.5);
	glVertex3f(78.0, 8.0, 6.5);
	glVertex3f(78.0, 8.5, 6.5);
	glVertex3f(78.0, 8.5, -6.5);
	glEnd();

	//vertical gawang kiri depan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.5, 8.5, 6.5);
	glVertex3f(-73.5, 0.0, 6.5);
	glVertex3f(-74.0, 0.0, 6.5);
	glVertex3f(-74.0, 8.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-74.5, 8.5, 6.5);
	glVertex3f(-74.5, 0.0, 6.5);
	glVertex3f(-75.0, 0.0, 6.5);
	glVertex3f(-75.0, 8.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-75.5, 8.5, 6.5);
	glVertex3f(-75.5, 0.0, 6.5);
	glVertex3f(-76.0, 0.0, 6.5);
	glVertex3f(-76.0, 8.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-76.5, 8.5, 6.5);
	glVertex3f(-76.5, 0.0, 6.5);
	glVertex3f(-77.0, 0.0, 6.5);
	glVertex3f(-77.0, 8.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-77.5, 8.5, 6.5);
	glVertex3f(-77.5, 0.0, 6.5);
	glVertex3f(-78.0, 0.0, 6.5);
	glVertex3f(-78.0, 8.5, 6.5);
	glEnd();

	//vertical gawang kiri belakang
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.5, 8.5, -6.5);
	glVertex3f(-73.5, 0.0, -6.5);
	glVertex3f(-74.0, 0.0, -6.5);
	glVertex3f(-74.0, 8.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-74.5, 8.5, -6.5);
	glVertex3f(-74.5, 0.0, -6.5);
	glVertex3f(-75.0, 0.0, -6.5);
	glVertex3f(-75.0, 8.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-75.5, 8.5, -6.5);
	glVertex3f(-75.5, 0.0, -6.5);
	glVertex3f(-76.0, 0.0, -6.5);
	glVertex3f(-76.0, 8.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-76.5, 8.5, -6.5);
	glVertex3f(-76.5, 0.0, -6.5);
	glVertex3f(-77.0, 0.0, -6.5);
	glVertex3f(-77.0, 8.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-77.5, 8.5, -6.5);
	glVertex3f(-77.5, 0.0, -6.5);
	glVertex3f(-78.0, 0.0, -6.5);
	glVertex3f(-78.0, 8.5, -6.5);
	glEnd();

	//vertical gawang kanan depan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.5, 8.5, 6.5);
	glVertex3f(73.5, 0.0, 6.5);
	glVertex3f(74.0, 0.0, 6.5);
	glVertex3f(74.0, 8.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(74.5, 8.5, 6.5);
	glVertex3f(74.5, 0.0, 6.5);
	glVertex3f(75.0, 0.0, 6.5);
	glVertex3f(75.0, 8.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(75.5, 8.5, 6.5);
	glVertex3f(75.5, 0.0, 6.5);
	glVertex3f(76.0, 0.0, 6.5);
	glVertex3f(76.0, 8.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(76.5, 8.5, 6.5);
	glVertex3f(76.5, 0.0, 6.5);
	glVertex3f(77.0, 0.0, 6.5);
	glVertex3f(77.0, 8.5, 6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(77.5, 8.5, 6.5);
	glVertex3f(77.5, 0.0, 6.5);
	glVertex3f(78.0, 0.0, 6.5);
	glVertex3f(78.0, 8.5, 6.5);
	glEnd();

	//vertical gawang kanan belakang
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.5, 8.5, -6.5);
	glVertex3f(73.5, 0.0, -6.5);
	glVertex3f(74.0, 0.0, -6.5);
	glVertex3f(74.0, 8.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(74.5, 8.5, -6.5);
	glVertex3f(74.5, 0.0, -6.5);
	glVertex3f(75.0, 0.0, -6.5);
	glVertex3f(75.0, 8.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(75.5, 8.5, -6.5);
	glVertex3f(75.5, 0.0, -6.5);
	glVertex3f(76.0, 0.0, -6.5);
	glVertex3f(76.0, 8.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(76.5, 8.5, -6.5);
	glVertex3f(76.5, 0.0, -6.5);
	glVertex3f(77.0, 0.0, -6.5);
	glVertex3f(77.0, 8.5, -6.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(77.5, 8.5, -6.5);
	glVertex3f(77.5, 0.0, -6.5);
	glVertex3f(78.0, 0.0, -6.5);
	glVertex3f(78.0, 8.5, -6.5);
	glEnd();

	//vertical gawang atas
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 8.5, 6.5);
	glVertex3f(-73.0, 8.5, 6.5);
	glVertex3f(-73.0, 9.5, 6.0);
	glVertex3f(-78.0, 9.5, 6.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 8.5, 5.5);
	glVertex3f(-73.0, 8.5, 5.5);
	glVertex3f(-73.0, 9.5, 5.0);
	glVertex3f(-78.0, 9.5, 5.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 8.5, 4.5);
	glVertex3f(-73.0, 8.5, 4.5);
	glVertex3f(-73.0, 9.5, 4.0);
	glVertex3f(-78.0, 9.5, 4.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 8.5, 3.5);
	glVertex3f(-73.0, 8.5, 3.5);
	glVertex3f(-73.0, 9.5, 3.0);
	glVertex3f(-78.0, 9.5, 3.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 8.5, 2.5);
	glVertex3f(-73.0, 8.5, 2.5);
	glVertex3f(-73.0, 9.5, 2.0);
	glVertex3f(-78.0, 9.5, 2.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 8.5, 1.5);
	glVertex3f(-73.0, 8.5, 1.5);
	glVertex3f(-73.0, 9.5, 1.0);
	glVertex3f(-78.0, 9.5, 1.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 8.5, 0.5);
	glVertex3f(-73.0, 8.5, 0.5);
	glVertex3f(-73.0, 9.5, 0.0);
	glVertex3f(-78.0, 9.5, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 8.5, -1.5);
	glVertex3f(-73.0, 8.5, -1.5);
	glVertex3f(-73.0, 9.5, -1.0);
	glVertex3f(-78.0, 9.5, -1.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 8.5, -2.5);
	glVertex3f(-73.0, 8.5, -2.5);
	glVertex3f(-73.0, 9.5, -2.0);
	glVertex3f(-78.0, 9.5, -2.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 8.5, -3.5);
	glVertex3f(-73.0, 8.5, -3.5);
	glVertex3f(-73.0, 9.5, -3.0);
	glVertex3f(-78.0, 9.5, -3.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 8.5, -4.5);
	glVertex3f(-73.0, 8.5, -4.5);
	glVertex3f(-73.0, 9.5, -4.0);
	glVertex3f(-78.0, 9.5, -4.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 8.5, -5.5);
	glVertex3f(-73.0, 8.5, -5.5);
	glVertex3f(-73.0, 9.5, -5.0);
	glVertex3f(-78.0, 9.5, -5.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-78.0, 8.5, -6.5);
	glVertex3f(-73.0, 8.5, -6.5);
	glVertex3f(-73.0, 9.5, -6.0);
	glVertex3f(-78.0, 9.5, -6.0);
	glEnd();

	//vertical gawang atas kanan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 8.5, 6.5);
	glVertex3f(73.0, 8.5, 6.5);
	glVertex3f(73.0, 9.5, 6.0);
	glVertex3f(78.0, 9.5, 6.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 8.5, 5.5);
	glVertex3f(73.0, 8.5, 5.5);
	glVertex3f(73.0, 9.5, 5.0);
	glVertex3f(78.0, 9.5, 5.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 8.5, 4.5);
	glVertex3f(73.0, 8.5, 4.5);
	glVertex3f(73.0, 9.5, 4.0);
	glVertex3f(78.0, 9.5, 4.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 8.5, 3.5);
	glVertex3f(73.0, 8.5, 3.5);
	glVertex3f(73.0, 9.5, 3.0);
	glVertex3f(78.0, 9.5, 3.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 8.5, 2.5);
	glVertex3f(73.0, 8.5, 2.5);
	glVertex3f(73.0, 9.5, 2.0);
	glVertex3f(78.0, 9.5, 2.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 8.5, 1.5);
	glVertex3f(73.0, 8.5, 1.5);
	glVertex3f(73.0, 9.5, 1.0);
	glVertex3f(78.0, 9.5, 1.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 8.5, 0.5);
	glVertex3f(73.0, 8.5, 0.5);
	glVertex3f(73.0, 9.5, 0.0);
	glVertex3f(78.0, 9.5, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 8.5, -1.5);
	glVertex3f(73.0, 8.5, -1.5);
	glVertex3f(73.0, 9.5, -1.0);
	glVertex3f(78.0, 9.5, -1.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 8.5, -2.5);
	glVertex3f(73.0, 8.5, -2.5);
	glVertex3f(73.0, 9.5, -2.0);
	glVertex3f(78.0, 9.5, -2.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 8.5, -3.5);
	glVertex3f(73.0, 8.5, -3.5);
	glVertex3f(73.0, 9.5, -3.0);
	glVertex3f(78.0, 9.5, -3.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 8.5, -4.5);
	glVertex3f(73.0, 8.5, -4.5);
	glVertex3f(73.0, 9.5, -4.0);
	glVertex3f(78.0, 9.5, -4.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 8.5, -5.5);
	glVertex3f(73.0, 8.5, -5.5);
	glVertex3f(73.0, 9.5, -5.0);
	glVertex3f(78.0, 9.5, -5.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(78.0, 8.5, -6.5);
	glVertex3f(73.0, 8.5, -6.5);
	glVertex3f(73.0, 9.5, -6.0);
	glVertex3f(78.0, 9.5, -6.0);
	glEnd();

}


void init(void){
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

	glEnable(GL_COLOR_MATERIAL);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);

}

void idle(){
    if(!mouseDown){
        xrot += 0.3f;
        yrot += 0.4f;
    }glutPostRedisplay();
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

void Mouse(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		std::cout << "KLIK KIRI" << " = anda menekan LEFT_BUTTON" << std::endl;
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}

	else{
        mouseDown = false;
	}
	tampil();
}

void MouseMove(int x, int y){
	if (mouseDown) {
		yrot= x - xdiff;
		_angle = y + ydiff;
		glLoadIdentity();
		gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(-_angle, 30.0f, 0.0f, 20.0f);
		glRotatef(yrot, 00.0f, 10.0f, 20.0f);
	}
	glutPostRedisplay();
}

void tampil(void){
	if (is_depth){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}else{
        glClear(GL_COLOR_BUFFER_BIT);
	}
	lapanganxlantai();
	//desaindepan a
	glBegin(GL_POLYGON);
	glColor3f(0.65, 0.65, 0.65);
	glVertex3f(-15.0, 5.0, 80.0);
	glVertex3f(-107.5, 60.0, 80.0);
	glVertex3f(-107.5, 70.0, 80.0);
	glVertex3f(-15.0, 45.0, 80.0);
	glEnd();

	//sisibawah
	glBegin(GL_QUADS);
	glVertex3f(-15.0, 5.0, 80.0);
	glVertex3f(-107.5, 60.0, 80.0);
	glVertex3f(-107.5, 60.0, 75.0);
	glVertex3f(-15.0, 5.0, 75.0);
	glEnd();

	//sisibawah
	glBegin(GL_QUADS);
	glVertex3f(-15.0, 45.0, 80.0);
	glVertex3f(-107.5, 70.0, 80.0);
	glVertex3f(-107.5, 70.0, 75.0);
	glVertex3f(-15.0, 45.0, 75.0);
	glEnd();

	//desaindepan b
	glBegin(GL_QUADS);
	glVertex3f(-15.0, 45.0, 80.0);
	glVertex3f(-15.0, 5.0, 80.0);
	glVertex3f(40.0, 40.0, 80.0);
	glVertex3f(30.0, 60.0, 80.0);
	glEnd();

	//sisibawah
	glBegin(GL_QUADS);
	glVertex3f(40.0, 40.0, 80.0);
	glVertex3f(-15.0, 5.0, 80.0);
	glVertex3f(-15.0, 5.0, 75.0);
	glVertex3f(40.0, 40.0, 75.0);
	glEnd();

	//sisiatas
	glBegin(GL_QUADS);
	glVertex3f(30.0, 60.0, 80.0);
	glVertex3f(-15.0, 45.0, 80.0);
	glVertex3f(-15.0, 45.0, 75.0);
	glVertex3f(30.0, 60.0, 75.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(40.0, 40.0, 80.0);
	glVertex3f(40.0, 40.0, 75.0);
	glVertex3f(50.0, 20.0, 75.0);
	glVertex3f(50.0, 20.0, 80.0);
	glEnd();

	//desaindepan c
	glBegin(GL_QUADS);
	glVertex3f(107.5, 50.0, 80.0);
	glVertex3f(107.5, 70.0, 80.0);
	glVertex3f(30.0, 60.0, 80.0);
	glVertex3f(50.0, 20.0, 80.0);
	glEnd();

	//sisiatas
	glBegin(GL_QUADS);
	glVertex3f(107.5, 70.0, 80.0);
	glVertex3f(30.0, 60.0, 80.0);
	glVertex3f(30.0, 60.0, 75.0);
	glVertex3f(107.5, 70.0, 75.0);
	glEnd();

	//sisibawah
	glBegin(GL_QUADS);
	glVertex3f(50.0, 20.0, 80.0);
	glVertex3f(107.5, 50.0, 80.0);
	glVertex3f(107.5, 50.0, 75.0);
	glVertex3f(50.0, 20.0, 75.0);
	glEnd();

	//desainsamping kiri
	glBegin(GL_QUADS);
	glVertex3f(-162.0, 60.0, -25.0);
	glVertex3f(-162.0, 60.0, 25.0);
	glVertex3f(-162.0, 70.0, 25.0);
	glVertex3f(-162.0, 70.0, -25.0);
	glEnd();

	//sisiatas
	glBegin(GL_QUADS);
	glVertex3f(-162.0, 70.0, 25.0);
	glVertex3f(-162.0, 70.0, -25.0);
	glVertex3f(-157.0, 70.0, -25.0);
	glVertex3f(-157.0, 70.0, 25.0);
	glEnd();

	//sisibawah
	glBegin(GL_QUADS);
	glVertex3f(-162.0, 60.0, -25.0);
	glVertex3f(-162.0, 60.0, 25.0);
	glVertex3f(-157.0, 60.0, 25.0);
	glVertex3f(-157.0, 60.0, -25.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(107.5, 70.0, -80.0);
	glVertex3f(-107.5, 70.0, -80.0);
	glVertex3f(-107.5, 60.0, -80.0);
	glVertex3f(107.5, 60.0, -80.0);
	glEnd();

	//penghubung
	glBegin(GL_QUADS);
	glVertex3f(-107.5, 60.0, 80.0);
	glVertex3f(-107.5, 70.0, 80.0);
	glVertex3f(-162.0, 70.0, 25.0);
	glVertex3f(-162.0, 60.0, 25.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(107.5, 50.0, 80.0);
	glVertex3f(107.5, 70.0, 80.0);
	glVertex3f(162.0, 70.0, 25.0);
	glVertex3f(162.0, 55.0, 25.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-107.5, 60.0, -80.0);
	glVertex3f(-107.5, 70.0, -80.0);
	glVertex3f(-162.0, 70.0, -25.0);
	glVertex3f(-162.0, 60.0, -25.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(107.5, 60.0, -80.0);
	glVertex3f(107.5, 70.0, -80.0);
	glVertex3f(162.0, 70.0, -25.0);
	glVertex3f(162.0, 60.0, -25.0);
	glEnd();

	//bawah
	glBegin(GL_QUADS);
	glVertex3f(-162.0, 60.0, 25.0);
	glVertex3f(-107.5, 60.0, 80.0);
	glVertex3f(-107.5, 60.0, 75.0);
	glVertex3f(-157.0, 60.0, 25.0);
	glEnd();

	//atas
	glBegin(GL_QUADS);
	glVertex3f(-162.0, 70.0, 25.0);
	glVertex3f(-107.5, 70.0, 80.0);
	glVertex3f(-107.5, 70.0, 75.0);
	glVertex3f(-157.0, 70.0, 25.0);
	glEnd();

	//bawah
	glBegin(GL_QUADS);
	glVertex3f(-162.0, 60.0, -25.0);
	glVertex3f(-107.5, 60.0, -80.0);
	glVertex3f(-107.5, 60.0, -75.0);
	glVertex3f(-157.0, 60.0, -25.0);
	glEnd();

	//atas
	glBegin(GL_QUADS);
	glVertex3f(-162.0, 70.0, -25.0);
	glVertex3f(-107.5, 70.0, -80.0);
	glVertex3f(-107.5, 70.0, -75.0);
	glVertex3f(-157.0, 70.0, -25.0);
	glEnd();

	//atas
	glBegin(GL_QUADS);
	glVertex3f(162.0, 70.0, 25.0);
	glVertex3f(107.5, 70.0, 80.0);
	glVertex3f(107.5, 70.0, 75.0);
	glVertex3f(157.0, 70.0, 25.0);
	glEnd();

	//bawah
	glBegin(GL_QUADS);
	glVertex3f(107.5, 50.0, 80.0);
	glVertex3f(162.0, 55.0, 25.0);
	glVertex3f(157.0, 55.0, 25.0);
	glVertex3f(107.5, 50.0, 75.0);
	glEnd();

	//atas
	glBegin(GL_QUADS);
	glVertex3f(107.5, 70.0, -80.0);
	glVertex3f(162.0, 70.0, -25.0);
	glVertex3f(157.0, 70.0, -25.0);
	glVertex3f(107.5, 70.0, -75.0);
	glEnd();

	//bawah
	glBegin(GL_QUADS);
	glVertex3f(162.0, 60.0, -25.0);
	glVertex3f(107.5, 60.0, -80.0);
	glVertex3f(107.5, 60.0, -75.0);
	glVertex3f(157.0, 60.0, -25.0);
	glEnd();

	//desainsampingkanan
	glBegin(GL_QUADS);
	glVertex3f(162.0, 60.0, -25.0);
	glVertex3f(162.0, 55.0, 25.0);
	glVertex3f(162.0, 70.0, 25.0);
	glVertex3f(162.0, 70.0, -25.0);
	glEnd();

	//bawah
	glBegin(GL_QUADS);
	glVertex3f(162.0, 60.0, -25.0);
	glVertex3f(162.0, 70.0, -25.0);
	glVertex3f(157.0, 70.0, -25.0);
	glVertex3f(157.0, 60.0, -25.0);
	glEnd();

	//atas
	glBegin(GL_QUADS);
	glVertex3f(162.0, 55.0, 25.0);
	glVertex3f(162.0, 70.0, 25.0);
	glVertex3f(157.0, 70.0, 25.0);
	glVertex3f(157.0, 55.0, 25.0);
	glEnd();

	//tianggawangkiri
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 10.0, 7.0);
	glVertex3f(-73.0, 10.0, 6.0);
	glVertex3f(-72.0, 10.0, 6.0);
	glVertex3f(-72.0, 10.0, 7.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-72.0, 10.0, 7.0);
	glVertex3f(-72.0, 10.0, 6.0);
	glVertex3f(-72.0, 0.0, 6.0);
	glVertex3f(-72.0, 0.0, 7.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 10.0, 7.0);
	glVertex3f(-73.0, 10.0, 6.0);
	glVertex3f(-73.0, 0.0, 6.0);
	glVertex3f(-73.0, 0.0, 7.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-72.0, 10.0, 7.0);
	glVertex3f(-73.0, 10.0, 7.0);
	glVertex3f(-73.0, 0.0, 7.0);
	glVertex3f(-72.0, 0.0, 7.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-72.0, 10.0, 6.0);
	glVertex3f(-73.0, 10.0, 6.0);
	glVertex3f(-73.0, 0.0, 6.0);
	glVertex3f(-72.0, 0.0, 6.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 10.0, -7.0);
	glVertex3f(-73.0, 10.0, -6.0);
	glVertex3f(-72.0, 10.0, -6.0);
	glVertex3f(-72.0, 10.0, -7.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-72.0, 10.0, -7.0);
	glVertex3f(-72.0, 10.0, -6.0);
	glVertex3f(-72.0, 0.0, -6.0);
	glVertex3f(-72.0, 0.0, -7.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 10.0, -7.0);
	glVertex3f(-73.0, 10.0, -6.0);
	glVertex3f(-73.0, 0.0, -6.0);
	glVertex3f(-73.0, 0.0, -7.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-72.0, 10.0, -7.0);
	glVertex3f(-73.0, 10.0, -7.0);
	glVertex3f(-73.0, 0.0, -7.0);
	glVertex3f(-72.0, 0.0, -7.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-72.0, 10.0, -6.0);
	glVertex3f(-73.0, 10.0, -6.0);
	glVertex3f(-73.0, 0.0, -6.0);
	glVertex3f(-72.0, 0.0, -6.0);
	glEnd();

	//tiangmelintang
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 10.0, -6.0);
	glVertex3f(-73.0, 10.0, 6.0);
	glVertex3f(-73.0, 9.0, 6.0);
	glVertex3f(-73.0, 9.0, -6.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 9.0, -6.0);
	glVertex3f(-73.0, 9.0, 6.0);
	glVertex3f(-72.0, 9.0, 6.0);
	glVertex3f(-72.0, 9.0, -6.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-72.0, 10.0, -6.0);
	glVertex3f(-72.0, 10.0, 6.0);
	glVertex3f(-72.0, 9.0, 6.0);
	glVertex3f(-72.0, 9.0, -6.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 10.0, -6.0);
	glVertex3f(-73.0, 10.0, 6.0);
	glVertex3f(-72.0, 10.0, 6.0);
	glVertex3f(-72.0, 10.0, -6.0);
	glEnd();

	//tianggawangkanan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 10.0, 7.0);
	glVertex3f(73.0, 10.0, 6.0);
	glVertex3f(72.0, 10.0, 6.0);
	glVertex3f(72.0, 10.0, 7.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(72.0, 10.0, 7.0);
	glVertex3f(72.0, 10.0, 6.0);
	glVertex3f(72.0, 0.0, 6.0);
	glVertex3f(72.0, 0.0, 7.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 10.0, 7.0);
	glVertex3f(73.0, 10.0, 6.0);
	glVertex3f(73.0, 0.0, 6.0);
	glVertex3f(73.0, 0.0, 7.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(72.0, 10.0, 7.0);
	glVertex3f(73.0, 10.0, 7.0);
	glVertex3f(73.0, 0.0, 7.0);
	glVertex3f(72.0, 0.0, 7.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(72.0, 10.0, 6.0);
	glVertex3f(73.0, 10.0, 6.0);
	glVertex3f(73.0, 0.0, 6.0);
	glVertex3f(72.0, 0.0, 6.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 10.0, -7.0);
	glVertex3f(73.0, 10.0, -6.0);
	glVertex3f(72.0, 10.0, -6.0);
	glVertex3f(72.0, 10.0, -7.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(72.0, 10.0, -7.0);
	glVertex3f(72.0, 10.0, -6.0);
	glVertex3f(72.0, 0.0, -6.0);
	glVertex3f(72.0, 0.0, -7.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 10.0, -7.0);
	glVertex3f(73.0, 10.0, -6.0);
	glVertex3f(73.0, 0.0, -6.0);
	glVertex3f(73.0, 0.0, -7.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(72.0, 10.0, -7.0);
	glVertex3f(73.0, 10.0, -7.0);
	glVertex3f(73.0, 0.0, -7.0);
	glVertex3f(72.0, 0.0, -7.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(72.0, 10.0, -6.0);
	glVertex3f(73.0, 10.0, -6.0);
	glVertex3f(73.0, 0.0, -6.0);
	glVertex3f(72.0, 0.0, -6.0);
	glEnd();

	//tiangmelintang
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 10.0, -6.0);
	glVertex3f(73.0, 10.0, 6.0);
	glVertex3f(73.0, 9.0, 6.0);
	glVertex3f(73.0, 9.0, -6.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 9.0, -6.0);
	glVertex3f(73.0, 9.0, 6.0);
	glVertex3f(72.0, 9.0, 6.0);
	glVertex3f(72.0, 9.0, -6.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(72.0, 10.0, -6.0);
	glVertex3f(72.0, 10.0, 6.0);
	glVertex3f(72.0, 9.0, 6.0);
	glVertex3f(72.0, 9.0, -6.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 10.0, -6.0);
	glVertex3f(73.0, 10.0, 6.0);
	glVertex3f(72.0, 10.0, 6.0);
	glVertex3f(72.0, 10.0, -6.0);
	glEnd();

	//alaskotakputih
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-80.0, 0.0, 75.0);
	glVertex3f(-100.0, 0.0, 75.0);
	glVertex3f(-100.0, 0.0, -75.0);
	glVertex3f(-80.0, 0.0, -75.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(80.0, 0.0, 75.0);
	glVertex3f(100.0, 0.0, 75.0);
	glVertex3f(100.0, 0.0, -75.0);
	glVertex3f(80.0, 0.0, -75.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-80.0, 0.0, 75.0);
	glVertex3f(-80.0, 0.0, 50.0);
	glVertex3f(80.0, 0.0, 50.0);
	glVertex3f(80.0, 0.0, 75.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-80.0, 0.0, -75.0);
	glVertex3f(-80.0, 0.0, -50.0);
	glVertex3f(80.0, 0.0, -50.0);
	glVertex3f(80.0, 0.0, -75.0);
	glEnd();

	//sisikanan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(100.0, 0.0, -75.0);
	glVertex3f(100.0, 0.0, 75.0);
	glVertex3f(107.5, 0.0, 75.0);
	glVertex3f(157.0, 0.0, 25.0);
	glVertex3f(157.0, 0.0, -25.0);
	glVertex3f(107.5, 0.0, -75.0);
	glEnd();

	//sisikiri
	glBegin(GL_POLYGON);
	glVertex3f(-100.0, 0.0, -75.0);
	glVertex3f(-100.0, 0.0, 75.0);
	glVertex3f(-107.5, 0.0, 75.0);
	glVertex3f(-157.0, 0.0, 25.0);
	glVertex3f(-157.0, 0.0, -25.0);
	glVertex3f(-107.5, 0.0, -75.0);
	glEnd();

	//dindingkananserong
	glBegin(GL_QUADS);
	glVertex3f(157.0, 0.0, 25.0);
	glVertex3f(107.5, 0.0, 75.0);
	glVertex3f(107.5, 65.0, 75.0);
	glVertex3f(157.0, 65.0, 25.0);
	glEnd();

	//dindingkanan
	glBegin(GL_QUADS);
	glVertex3f(157.0, 0.0, -25.0);
	glVertex3f(157.0, 0.0, 25.0);
	glVertex3f(157.0, 65.0, 25.0);
	glVertex3f(157.0, 65.0, -25.0);
	glEnd();

	//dindingkananserongbelakang
	glBegin(GL_QUADS);
	glVertex3f(157.0, 0.0, -25.0);
	glVertex3f(107.5, 0.0, -75.0);
	glVertex3f(107.5, 65.0, -75.0);
	glVertex3f(157.0, 65.0, -25.0);
	glEnd();

	//dindingkiriserong
	glBegin(GL_QUADS);
	glVertex3f(-157.0, 0.0, 25.0);
	glVertex3f(-107.5, 0.0, 75.0);
	glVertex3f(-107.5, 65.0, 75.0);
	glVertex3f(-157.0, 65.0, 25.0);
	glEnd();

	//dindingkiri
	glBegin(GL_QUADS);
	glVertex3f(-157.0, 0.0, -25.0);
	glVertex3f(-157.0, 0.0, 25.0);
	glVertex3f(-157.0, 65.0, 25.0);
	glVertex3f(-157.0, 65.0, -25.0);
	glEnd();

	//dindingkiriserongbelakang
	glBegin(GL_QUADS);
	glVertex3f(-157.0, 0.0, -25.0);
	glVertex3f(-107.5, 0.0, -75.0);
	glVertex3f(-107.5, 65.0, -75.0);
	glVertex3f(-157.0, 65.0, -25.0);
	glEnd();

	//pintu
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(5.0, 10.0, 75.0);
	glVertex3f(-5.0, 10.0, 75.0);
	glVertex3f(-5.0, 0.0, 75.0);
	glVertex3f(5.0, 0.0, 75.0);
	glEnd();

	//sisiputihpintukanan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(5.0, 10.0, 75.0);
	glVertex3f(107.5, 10.0, 75.0);
	glVertex3f(107.5, 0.0, 75.0);
	glVertex3f(5.0, 0.0, 75.0);
	glEnd();

	//sisiputihpintukiri
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-5.0, 10.0, 75.0);
	glVertex3f(-107.5, 10.0, 75.0);
	glVertex3f(-107.5, 0.0, 75.0);
	glVertex3f(-5.0, 0.0, 75.0);
	glEnd();

	//dinding sisa depan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(107.5, 10.0, 75.0);
	glVertex3f(-107.5, 10.0, 75.0);
	glVertex3f(-107.5, 65.0, 75.0);
	glVertex3f(107.5, 65.0, 75.0);
	glEnd();

	//dindingbelakang
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(107.5, 0.0, -75.0);
	glVertex3f(-107.5, 0.0, -75.0);
	glVertex3f(-107.5, 65.0, -75.0);
	glVertex3f(107.5, 65.0, -75.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(107.5, 75.0, 75.0);
	glVertex3f(-107.5, 75.0, 75.0);
	glVertex3f(-107.5, 65.0, 75.0);
	glVertex3f(107.5, 65.0, 75.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(107.5, 75.0, -75.0);
	glVertex3f(-107.5, 75.0, -75.0);
	glVertex3f(-107.5, 65.0, -75.0);
	glVertex3f(107.5, 65.0, -75.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(157.0, 75.0, 25.0);
	glVertex3f(107.5, 75.0, 75.0);
	glVertex3f(107.5, 65.0, 75.0);
	glVertex3f(157.0, 65.0, 25.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(157.0, 75.0, -25.0);
	glVertex3f(157.0, 75.0, 25.0);
	glVertex3f(157.0, 65.0, 25.0);
	glVertex3f(157.0, 65.0, -25.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(157.0, 75.0, -25.0);
	glVertex3f(107.5, 75.0, -75.0);
	glVertex3f(107.5, 65.0, -75.0);
	glVertex3f(157.0, 65.0, -25.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-157.0, 75.0, 25.0);
	glVertex3f(-107.5, 75.0, 75.0);
	glVertex3f(-107.5, 65.0, 75.0);
	glVertex3f(-157.0, 65.0, 25.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-157.0, 75.0, -25.0);
	glVertex3f(-157.0, 75.0, 25.0);
	glVertex3f(-157.0, 65.0, 25.0);
	glVertex3f(-157.0, 65.0, -25.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-157.0, 75.0, -25.0);
	glVertex3f(-107.5, 75.0, -75.0);
	glVertex3f(-107.5, 65.0, -75.0);
	glVertex3f(-157.0, 65.0, -25.0);
	glEnd();

	//serongatapdepan
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(107.5, 75.0, 75.0);
	glVertex3f(-107.5, 75.0, 75.0);
	glVertex3f(-107.5, 85.0, 65.0);
	glVertex3f(107.5, 85.0, 65.0);
	glEnd();

	//serongatapbelakang
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(107.5, 75.0, -75.0);
	glVertex3f(-107.5, 75.0, -75.0);
	glVertex3f(-107.5, 85.0, -65.0);
	glVertex3f(107.5, 85.0, -65.0);
	glEnd();

	//serongkanandepan
	glBegin(GL_QUADS);
	glVertex3f(157.0, 75.0, -25.0);
	glVertex3f(157.0, 75.0, 25.0);
	glVertex3f(147.0, 85.0, 25.0);
	glVertex3f(147.0, 85.0, -25.0);
	glEnd();

	//serongatapkiri
	glBegin(GL_QUADS);
	glVertex3f(-157.0, 75.0, -25.0);
	glVertex3f(-157.0, 75.0, 25.0);
	glVertex3f(-147.0, 85.0, 25.0);
	glVertex3f(-147.0, 85.0, -25.0);
	glEnd();

	//serongkiri-depan
	glBegin(GL_QUADS);
	glVertex3f(-157.0, 75.0, 25.0);
	glVertex3f(-147.0, 85.0, 25.0);
	glVertex3f(-107.5, 85.0, 65.0);
	glVertex3f(-107.5, 75.0, 75.0);
	glEnd();

	//serongkanan-depan
	glBegin(GL_QUADS);
	glVertex3f(157.0, 75.0, 25.0);
	glVertex3f(147.0, 85.0, 25.0);
	glVertex3f(107.5, 85.0, 65.0);
	glVertex3f(107.5, 75.0, 75.0);
	glEnd();

	//serongkiri-belakang
	glBegin(GL_QUADS);
	glVertex3f(-157.0, 75.0, -25.0);
	glVertex3f(-147.0, 85.0, -25.0);
	glVertex3f(-107.5, 85.0, -65.0);
	glVertex3f(-107.5, 75.0, -75.0);
	glEnd();

	//serongkanan-belakang
	glBegin(GL_QUADS);
	glVertex3f(157.0, 75.0, -25.0);
	glVertex3f(147.0, 85.0, -25.0);
	glVertex3f(107.5, 85.0, -65.0);
	glVertex3f(107.5, 75.0, -75.0);
	glEnd();

	//batasan pipa
	//depan
	glBegin(GL_QUADS);
	glVertex3f(-107.5, 85.0, 65.0);
	glVertex3f(107.5, 85.0, 65.0);
	glVertex3f(107.5, 85.0, 55.0);
	glVertex3f(-107.5, 85.0, 55.0);
	glEnd();

	//belakang
	glBegin(GL_QUADS);
	glVertex3f(-107.5, 85.0, -65.0);
	glVertex3f(107.5, 85.0, -65.0);
	glVertex3f(107.5, 85.0, -55.0);
	glVertex3f(-107.5, 85.0, -55.0);
	glEnd();

	//kanan
	glBegin(GL_QUADS);
	glVertex3f(147.0, 85.0, 25.0);
	glVertex3f(147.0, 85.0, -25.0);
	glVertex3f(137.0, 85.0, -25.0);
	glVertex3f(137.0, 85.0, 25.0);
	glEnd();

	//kiri
	glBegin(GL_QUADS);
	glVertex3f(-147.0, 85.0, 25.0);
	glVertex3f(-147.0, 85.0, -25.0);
	glVertex3f(-137.0, 85.0, -25.0);
	glVertex3f(-137.0, 85.0, 25.0);
	glEnd();

	//depankiri
	glBegin(GL_QUADS);
	glVertex3f(-107.5, 85.0, 65.0);
	glVertex3f(-107.5, 85.0, 55.0);
	glVertex3f(-137.0, 85.0, 25.0);
	glVertex3f(-147.0, 85.0, 25.0);
	glEnd();
	//depankanan
	glBegin(GL_QUADS);
	glVertex3f(107.5, 85.0, 65.0);
	glVertex3f(107.5, 85.0, 55.0);
	glVertex3f(137.0, 85.0, 25.0);
	glVertex3f(147.0, 85.0, 25.0);
	glEnd();

	//kiribelakang
	glBegin(GL_QUADS);
	glVertex3f(-107.5, 85.0, -65.0);
	glVertex3f(-107.5, 85.0, -55.0);
	glVertex3f(-137.0, 85.0, -25.0);
	glVertex3f(-147.0, 85.0, -25.0);
	glEnd();

	//kananbelakang
	glBegin(GL_QUADS);
	glVertex3f(107.5, 85.0, -65.0);
	glVertex3f(107.5, 85.0, -55.0);
	glVertex3f(137.0, 85.0, -25.0);
	glVertex3f(147.0, 85.0, -25.0);
	glEnd();

	//depan
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-107.5, 85.0, 50.0);
	glVertex3f(107.5, 85.0, 50.0);
	glVertex3f(107.5, 85.0, 55.0);
	glVertex3f(-107.5, 85.0, 55.0);
	glEnd();

	//belakang
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-107.5, 85.0, -50.0);
	glVertex3f(107.5, 85.0, -50.0);
	glVertex3f(107.5, 85.0, -55.0);
	glVertex3f(-107.5, 85.0, -55.0);
	glEnd();

	//kanan
	glBegin(GL_QUADS);
	glVertex3f(132.0, 85.0, 25.0);
	glVertex3f(132.0, 85.0, -25.0);
	glVertex3f(137.0, 85.0, -25.0);
	glVertex3f(137.0, 85.0, 25.0);
	glEnd();

	//kiri
	glBegin(GL_QUADS);
	glVertex3f(-132.0, 85.0, 25.0);
	glVertex3f(-132.0, 85.0, -25.0);
	glVertex3f(-137.0, 85.0, -25.0);
	glVertex3f(-137.0, 85.0, 25.0);
	glEnd();

	//depankiri
	glBegin(GL_QUADS);
	glVertex3f(-107.5, 85.0, 50.0);
	glVertex3f(-107.5, 85.0, 55.0);
	glVertex3f(-137.0, 85.0, 25.0);
	glVertex3f(-132.0, 85.0, 25.0);
	glEnd();

	//depankanan
	glBegin(GL_QUADS);
	glVertex3f(107.5, 85.0, 50.0);
	glVertex3f(107.5, 85.0, 55.0);
	glVertex3f(137.0, 85.0, 25.0);
	glVertex3f(132.0, 85.0, 25.0);
	glEnd();

	//belakangkiri
	glBegin(GL_QUADS);
	glVertex3f(-107.5, 85.0, -50.0);
	glVertex3f(-107.5, 85.0, -55.0);
	glVertex3f(-137.0, 85.0, -25.0);
	glVertex3f(-132.0, 85.0, -25.0);
	glEnd();

	//belakangkanan
	glBegin(GL_QUADS);
	glVertex3f(107.5, 85.0, -50.0);
	glVertex3f(107.5, 85.0, -55.0);
	glVertex3f(137.0, 85.0, -25.0);
	glVertex3f(132.0, 85.0, -25.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-5.0, 0.0, 75.0);
	glVertex3f(5.0, 0.0, 75.0);
	glVertex3f(5.0, 0.0, 150.0);
	glVertex3f(-5.0, 0.0, 150.0);
	glEnd();

	//penghijauan
	glBegin(GL_QUADS);
	glColor3f(0.125, 0.5, 0.0);
	glVertex3f(5.0, 0.0, 75.0);
	glVertex3f(5.0, 0.0, 150.0);
	glVertex3f(107.5, 0.0, 150.0);
	glVertex3f(107.5, 0.0, 75.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.125, 0.5, 0.0);
	glVertex3f(-5.0, 0.0, 75.0);
	glVertex3f(-5.0, 0.0, 150.0);
	glVertex3f(-107.5, 0.0, 150.0);
	glVertex3f(-107.5, 0.0, 75.0);
	glEnd();

	//lapanganminitengahkiri
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5, 0.0, -6.0);
	glVertex3f(-2.5, 0.0, -6.0);
	glVertex3f(-6.0, 0.0, -2.5);
	glVertex3f(-6.0, 0.0, 2.5);
	glVertex3f(-2.5, 0.0, 6.0);
	glVertex3f(-0.5, 0.0, 6.0);
	glEnd();

	//lapanganminitengahkanan
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.5, 0.0, -6.0);
	glVertex3f(2.5, 0.0, -6.0);
	glVertex3f(6.0, 0.0, -2.5);
	glVertex3f(6.0, 0.0, 2.5);
	glVertex3f(2.5, 0.0, 6.0);
	glVertex3f(0.5, 0.0, 6.0);
	glEnd();

	//lapanganminitengahpinggirkiri
	glBegin(GL_QUADS);
	glVertex3f(-0.5,  0.0, 47.0);
	glVertex3f(-72.0, 0.0, 47.0);
	glVertex3f(-72.0, 0.0, 30.0);
	glVertex3f(-0.5, 0.0, 30.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.5,  0.0, -47.0);
	glVertex3f(-72.0, 0.0, -47.0);
	glVertex3f(-72.0, 0.0, -30.0);
	glVertex3f(-0.5, 0.0, -30.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-45.0,  0.0, -30.0);
	glVertex3f(-7.0,  0.0, -30.0);
	glVertex3f(-7.0,  0.0, 30.0);
	glVertex3f(-45.0,  0.0, 30.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.5,  0.0, 7.0);
	glVertex3f(-0.5,  0.0, 47.0);
	glVertex3f(-7.0,  0.0, 47.0);
	glVertex3f(-7.0,  0.0, 2.5);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.5,  0.0, -7.0);
	glVertex3f(-0.5,  0.0, -47.0);
	glVertex3f(-7.0,  0.0, -47.0);
	glVertex3f(-7.0,  0.0, -2.5);
	glEnd();

	//lapanganminitengahpinggirkanan
	glBegin(GL_QUADS);
	glVertex3f(0.5,  0.0, 47.0);
	glVertex3f(72.0, 0.0, 47.0);
	glVertex3f(72.0, 0.0, 30.0);
	glVertex3f(0.5, 0.0, 30.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.5,  0.0, -47.0);
	glVertex3f(72.0, 0.0, -47.0);
	glVertex3f(72.0, 0.0, -30.0);
	glVertex3f(0.5, 0.0, -30.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(45.0,  0.0, -30.0);
	glVertex3f(7.0,  0.0, -30.0);
	glVertex3f(7.0,  0.0, 30.0);
	glVertex3f(45.0,  0.0, 30.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.5,  0.0, 7.0);
	glVertex3f(0.5,  0.0, 47.0);
	glVertex3f(7.0,  0.0, 47.0);
	glVertex3f(7.0,  0.0, 2.5);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.5,  0.0, -7.0);
	glVertex3f(0.5,  0.0, -47.0);
	glVertex3f(7.0,  0.0, -47.0);
	glVertex3f(7.0,  0.0, -2.5);
	glEnd();

	//luarlapangandepan
	glBegin(GL_QUADS);
	glVertex3f(80.0, 0.0, 48.0);
	glVertex3f(-80.5, 0.0, 48.0);
	glVertex3f(-80.5, 0.0, 50.0);
	glVertex3f(80.0, 0.0, 50.0);
	glEnd();

	//luarlapanganbelakang
	glBegin(GL_QUADS);
	glVertex3f(80.0, 0.0, -48.0);
	glVertex3f(-80.5, 0.0, -48.0);
	glVertex3f(-80.5, 0.0, -50.0);
	glVertex3f(80.0, 0.0, -50.0);
	glEnd();

	//luarlapangankiri
	glBegin(GL_QUADS);
	glVertex3f(-80.0, 0.0, -48.0);
	glVertex3f(-73, 0.0, -48.0);
	glVertex3f(-73.0, 0.0, 48.0);
	glVertex3f(-80.0, 0.0, 48.0);
	glEnd();

	//luarlapangankanan
	glBegin(GL_QUADS);
	glVertex3f(80.0, 0.0, -48.0);
	glVertex3f(73, 0.0, -48.0);
	glVertex3f(73.0, 0.0, 48.0);
	glVertex3f(80.0, 0.0, 48.0);
	glEnd();

	//garis tengah
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.5, 0.0, -48.0);
	glVertex3f(0.5, 0.0, 48.0);
	glVertex3f(-0.5, 0.0, 48.0);
	glVertex3f(-0.5, 0.0, -48.0);
	glEnd();

	//garis kanan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(73.0, 0.0, -48.0);
	glVertex3f(73.0, 0.0, 48.0);
	glVertex3f(72.0, 0.0, 48.0);
	glVertex3f(72.0, 0.0, -48.0);
	glEnd();

	//garis kiri
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-73.0, 0.0, -48.0);
	glVertex3f(-73.0, 0.0, 48.0);
	glVertex3f(-72.0, 0.0, 48.0);
	glVertex3f(-72.0, 0.0, -48.0);
	glEnd();

	//garisdepan
	glBegin(GL_QUADS);
	glVertex3f(-72.0, 0.0, 47.0);
	glVertex3f(72.0, 0.0, 47.0);
	glVertex3f(72.0, 0.0, 48.0);
	glVertex3f(-72.0, 0.0, 48.0);
	glEnd();

	//garis belakang
	glBegin(GL_QUADS);
	glVertex3f(-72.0, 0.0, -47.0);
	glVertex3f(72.0, 0.0, -47.0);
	glVertex3f(72.0, 0.0, -48.0);
	glVertex3f(-72.0, 0.0, -48.0);
	glEnd();

	//garistengahbulatbelakang
	glBegin(GL_QUADS);
	glVertex3f(0.5, 0.0, -7.0);
	glVertex3f(2.5, 0.0, -7.0);
	glVertex3f(2.5, 0.0, -6.0);
	glVertex3f(0.5, 0.0, -6.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.5, 0.0, -7.0);
	glVertex3f(-2.5, 0.0, -7.0);
	glVertex3f(-2.5, 0.0, -6.0);
	glVertex3f(-0.5, 0.0, -6.0);
	glEnd();

	//garistengahbulatdepan
	glBegin(GL_QUADS);
	glVertex3f(0.5, 0.0, 7.0);
	glVertex3f(2.5, 0.0, 7.0);
	glVertex3f(2.5, 0.0, 6.0);
	glVertex3f(0.5, 0.0, 6.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.5, 0.0, 7.0);
	glVertex3f(-2.5, 0.0, 7.0);
	glVertex3f(-2.5, 0.0, 6.0);
	glVertex3f(-0.5, 0.0, 6.0);
	glEnd();

	//garistengahbulatkiri
	glBegin(GL_QUADS);
	glVertex3f(-7.0, 0.0, 2.5);
	glVertex3f(-6.0, 0.0, 2.5);
	glVertex3f(-6.0, 0.0, -2.5);
	glVertex3f(-7.0, 0.0, -2.5);
	glEnd();

	//garistengahbulatkanan
	glBegin(GL_QUADS);
	glVertex3f(7.0, 0.0, 2.5);
	glVertex3f(6.0, 0.0, 2.5);
	glVertex3f(6.0, 0.0, -2.5);
	glVertex3f(7.0, 0.0, -2.5);
	glEnd();

    	//diagonalbelakangkiri
	glBegin(GL_QUADS);
	glVertex3f(-2.5, 0.0, -6.0);
	glVertex3f(-2.5, 0.0, -7.0);
	glVertex3f(-6.0, 0.0, -2.5);
	glVertex3f(-7.0, 0.0, -2.5);
	glEnd();

	//diagonaldepankiri
	glBegin(GL_QUADS);
	glVertex3f(-2.5, 0.0, 6.0);
	glVertex3f(-2.5, 0.0, 7.0);
	glVertex3f(-6.0, 0.0, 2.5);
	glVertex3f(-7.0, 0.0, 2.5);
	glEnd();

	//diagonalbelakangkanan
	glBegin(GL_QUADS);
	glVertex3f(2.5, 0.0, -6.0);
	glVertex3f(2.5, 0.0, -7.0);
	glVertex3f(6.0, 0.0, -2.5);
	glVertex3f(7.0, 0.0, -2.5);
	glEnd();

	//diagonaldepankanan
	glBegin(GL_QUADS);
	glVertex3f(2.5, 0.0, 6.0);
	glVertex3f(2.5, 0.0, 7.0);
	glVertex3f(6.0, 0.0, 2.5);
	glVertex3f(7.0, 0.0, 2.5);
	glEnd();

    	//garisgawangluarkiri
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-72.0, 0.0, -30.0);
	glVertex3f(-45.0, 0.0, -30.0);
	glVertex3f(-45.0, 0.0, -29.0);
	glVertex3f(-72.0, 0.0, -29.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-72.0, 0.0, 30.0);
	glVertex3f(-45.0, 0.0, 30.0);
	glVertex3f(-45.0, 0.0, 29.0);
	glVertex3f(-72.0, 0.0, 29.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-46.0, 0.0, 29.0);
	glVertex3f(-45.0, 0.0, 29.0);
	glVertex3f(-45.0, 0.0, -29.0);
	glVertex3f(-46.0, 0.0, -29.0);
	glEnd();

	//garisgawangluarkanan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(72.0, 0.0, -30.0);
	glVertex3f(45.0, 0.0, -30.0);
	glVertex3f(45.0, 0.0, -29.0);
	glVertex3f(72.0, 0.0, -29.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(72.0, 0.0, 30.0);
	glVertex3f(45.0, 0.0, 30.0);
	glVertex3f(45.0, 0.0, 29.0);
	glVertex3f(72.0, 0.0, 29.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(46.0, 0.0, 29.0);
	glVertex3f(45.0, 0.0, 29.0);
	glVertex3f(45.0, 0.0, -29.0);
	glVertex3f(46.0, 0.0, -29.0);
	glEnd();

	//garisgawangdalamkiri
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-72.0, 0.0, -15.0);
	glVertex3f(-60.0, 0.0, -15.0);
	glVertex3f(-60.0, 0.0, -14.0);
	glVertex3f(-72.0, 0.0, -14.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-72.0, 0.0, 15.0);
	glVertex3f(-60.0, 0.0, 15.0);
	glVertex3f(-60.0, 0.0, 14.0);
	glVertex3f(-72.0, 0.0, 14.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-60.0, 0.0, 14.0);
	glVertex3f(-61.0, 0.0, 14.0);
	glVertex3f(-61.0, 0.0, -14.0);
	glVertex3f(-60.0, 0.0, -14.0);
	glEnd();

	//garisgawangdalamkanan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(72.0, 0.0, -15.0);
	glVertex3f(60.0, 0.0, -15.0);
	glVertex3f(60.0, 0.0, -14.0);
	glVertex3f(72.0, 0.0, -14.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(72.0, 0.0, 15.0);
	glVertex3f(60.0, 0.0, 15.0);
	glVertex3f(60.0, 0.0, 14.0);
	glVertex3f(72.0, 0.0, 14.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(60.0, 0.0, 14.0);
	glVertex3f(61.0, 0.0, 14.0);
	glVertex3f(61.0, 0.0, -14.0);
	glVertex3f(60.0, 0.0, -14.0);
	glEnd();

	//lapangangawangdalamkanan
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(72.0, 0.0, 14.0);
	glVertex3f(72.0, 0.0, -14.0);
	glVertex3f(61.0, 0.0, -14.0);
	glVertex3f(61.0, 0.0, 14.0);
	glEnd();

	//lapangangawangdalamkiri
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-72.0, 0.0, 14.0);
	glVertex3f(-72.0, 0.0, -14.0);
	glVertex3f(-61.0, 0.0, -14.0);
	glVertex3f(-61.0, 0.0, 14.0);
	glEnd();

	//lapangangawangluarkanan
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(46.0, 0.0, 29.0);
	glVertex3f(46.0, 0.0, -29.0);
	glVertex3f(61.0, 0.0, -29.0);
	glVertex3f(61.0, 0.0, 29.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(72.0, 0.0, -15.0);
	glVertex3f(72.0, 0.0, -44.0);
	glVertex3f(61.0, 0.0, -44.0);
	glVertex3f(61.0, 0.0, -15.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(72.0, 0.0, 15.0);
	glVertex3f(72.0, 0.0, 44.0);
	glVertex3f(61.0, 0.0, 44.0);
	glVertex3f(61.0, 0.0, 15.0);
	glEnd();

	//lapangangawangluarkiri
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-46.0, 0.0, 29.0);
	glVertex3f(-46.0, 0.0, -29.0);
	glVertex3f(-61.0, 0.0, -29.0);
	glVertex3f(-61.0, 0.0, 29.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-72.0, 0.0, -15.0);
	glVertex3f(-72.0, 0.0, -44.0);
	glVertex3f(-61.0, 0.0, -44.0);
	glVertex3f(-61.0, 0.0, -15.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-72.0, 0.0, 15.0);
	glVertex3f(-72.0, 0.0, 44.0);
	glVertex3f(-61.0, 0.0, 44.0);
	glVertex3f(-61.0, 0.0, 15.0);
	glEnd();

	glPushMatrix();
	glPopMatrix();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
	switch (key){
	case 'w':
	case 'W':
		glTranslatef(0.0,0.0,3.0);
		break;
	case 'd':
	case 'D':
		glTranslatef(3.0,0.0,0.0);
		break;
	case 's':
	case 'S':
		glTranslatef(0.0,0.0,-3.0);
		break;
	case 'a':
	case 'A':
		glTranslatef(-3.0,0.0,0.0);
		break;
	case '7':
		glTranslatef(0.0,3.0,0.0);
		break;
	case '9':
		glTranslatef(0.0,-3.0,0.0);
		break;
	case '2':
		glRotatef(2.0,1.0,0.0,0.0);
		break;
	case '8':
		glRotatef(-2.0,1.0,0.0,0.0);
		break;
	case '6':
		glRotatef(2.0,0.0,1.0,0.0);
		break;
	case '4':
		glRotatef(-2.0,0.0,1.0,0.0);
		break;
	case '1':
		glRotatef(2.0,0.0,0.0,1.0);
		break;
	case '3':
		glRotatef(-2.0,0.0,0.0,1.0);
		break;
	case '5':
		if (is_depth){
			is_depth = 0;
			glDisable(GL_DEPTH_TEST);
		}else{
			is_depth =1;
			glEnable(GL_DEPTH_TEST);
		}
    case 27:
			exit(0);
	}
	tampil();
}

void ukuran(int lebar, int tinggi){
	if(tinggi == 0) tinggi = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, lebar, tinggi);
	gluPerspective(50.0, lebar / tinggi, 50.0, -250.0);
	glTranslatef(0.0, -50.0, -500.0);
	glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("TR_ASISTENSI_DOSEN_GRAFKOM_B");
	init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(Mouse);
	glutMotionFunc(MouseMove);
	glutReshapeFunc(ukuran);
	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}
