#include <iostream>
#include<windows.h>
#include <GL/freeglut.h>
#include < string >
using namespace std;
GLdouble left_m = -100.0;
GLdouble right_m = 700.0;
GLdouble bottom_m = -140.0;
GLdouble top_m = 460.0;
double ok = 1;
double j = 0.0;
double i = 0.0;
double contor = 0;
double loc_vert = 800;
int vector[3] = { 0, 160, 320 };
double height = vector[rand() % 3];
int score = 0;
double timp = 0.15;
int pct = 1000;
double rsj, rdj, rss, rds = 0;
bool in_menu = false;
void init(void)
{
	glClearColor(0.98, 0.929, 0.792, 0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(left_m, right_m, bottom_m, top_m, -1.0, 1.0);
}
void RenderString(float x, float y, void* font, const unsigned char* string)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2f(x, y);
	glutBitmapString(font, string);
}
void startgame(void)
{
	if (height != j || (loc_vert > 90 || loc_vert < -90))
	{
		if (i < -380)
		{
			i = 0;
		}
		i = i - 2 * timp;
		loc_vert -= timp;
		if (loc_vert < -150)
		{
			score += 100;
			height = vector[rand() % 3];
			cout << "Score: " << score << endl;
			loc_vert = 800;
		}
		if (score >= pct && pct <= 15000)
		{
			timp += 0.1;
			pct += 1000;
		}
		glutPostRedisplay();
	}
	else {
		ok = 0;
	}
}
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	// Desenam iarba
	/*glColor3f(0.55, 0.788, 0.451);
	glBegin(GL_POLYGON);
	glVertex2i(-100, -140);
	glVertex2i(700, -140);
	glVertex2i(700, 400);
	glVertex2i(-100, 400);
	glEnd();*/
	glColor3f(0.55, 0.788, 0.451);
	// Iarba de jos
	glBegin(GL_POLYGON);
	glVertex2i(-100, -140);// Stanga jos
	glVertex2i(700, -140); // Dreapta jos
	glVertex2i(700, -60); // Dreapta sus
	glVertex2i(-100, -60); // Stanga sus
	glEnd();
	// Iarba de sus
	glBegin(GL_POLYGON);
	glVertex2i(-100, 360);// Stanga jos
	glVertex2i(700, 360); // Dreapta jos
	glVertex2i(700, 460); // Dreapta sus
	glVertex2i(-100, 460);// Stanga sus
	glEnd();
	// Desenam drumul
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2i(-100, -60);
	glVertex2i(1500, -60);
	glVertex2i(1500, 80);
	glVertex2i(-100, 80);
	glEnd();
	// Desenam liniile de pe drum
	glColor3f(1, 1, 1);
	glLineWidth(3);
	glLineStipple(10, 0xAAAA);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glVertex2i(-100, 15);
	glVertex2i(1500, 15);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	// Desenam drumul
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2i(-100, 360);
	glVertex2i(1500, 360);
	glVertex2i(1500, 80);
	glVertex2i(-100, 80);
	glEnd();
	// Desenam liniile de pe drum
	glColor3f(1, 1, 1);
	glLineWidth(3);
	glLineStipple(10, 0xAAAA);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glVertex2i(-100, 300);
	glVertex2i(1500, 300);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	// Desenam drumul
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2i(-100, 240);
	glVertex2i(1500, 240);
	glVertex2i(1500, 80);
	glVertex2i(-100, 80);
	glEnd();
	// Desenam liniile de pe drum
	glColor3f(1, 1, 1);
	glLineWidth(3);
	glLineStipple(10, 0xAAAA);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glVertex2i(-100, 160);
	glVertex2i(1500, 160);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2i(250, 400);
	string scoreText = "Score: " + to_string(score);
	for (char c : scoreText) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}
	// Delimitare sosea
	glLineWidth(3);
	glColor3f(1, 1, 1);
	// Delimitam soseaua de iarba partea de jos
	glBegin(GL_LINES);
	glVertex2i(-100, -60);
	glVertex2i(1500, -60);
	glEnd();
	// Delimitam soseaua de iarba partea de sus
	glBegin(GL_LINES);
	glVertex2i(-100, 360);
	glVertex2i(1500, 360);
	glEnd();
	// Liniile intrerupte
	glPushMatrix();
	glTranslated(i, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(-100, 80);
	glVertex2i(1500, 80);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(-100, 240);
	glVertex2i(1500, 240);
	glEnd();
	glPopMatrix();
	//copaci
	int copac_x = -80;
	int copac_y = -100;
	glPushMatrix();
	glTranslated(copac_x, copac_y, 0.0);
	// Desenam copacul 1
	glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_POLYGON);
	glVertex2i(45, -20);
	glVertex2i(55, -20);
	glVertex2i(55, 5);
	glVertex2i(45, 5);
	glEnd();
	// Coroana
	glColor3f(0.133, 0.545, 0.133);
	glBegin(GL_POLYGON);
	glVertex2i(25, 5);
	glVertex2i(75, 5);
	glVertex2i(62, 45);
	glVertex2i(38, 45);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(copac_x, copac_y, 0.0);
	// Desenam copacul 2
	glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_POLYGON);
	glVertex2i(195, -20);
	glVertex2i(205, -20);
	glVertex2i(205, 5);
	glVertex2i(195, 5);
	glEnd();
	// Coroana
	glColor3f(0.133, 0.545, 0.133);
	glBegin(GL_POLYGON);
	glVertex2i(175, 5);
	glVertex2i(225, 5);
	glVertex2i(212, 45);
	glVertex2i(188, 45);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(copac_x, copac_y, 0.0);
	// Desenam copacul 3
	glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_POLYGON);
	glVertex2i(345, -20);
	glVertex2i(355, -20);
	glVertex2i(355, 5);
	glVertex2i(345, 5);
	glEnd();
	// Coroana
	glColor3f(0.133, 0.545, 0.133);
	glBegin(GL_POLYGON);
	glVertex2i(325, 5);
	glVertex2i(375, 5);
	glVertex2i(362, 45);
	glVertex2i(338, 45);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(copac_x, copac_y, 0.0);
	// Desenam copacul 4
	glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_POLYGON);
	glVertex2i(495, -20);
	glVertex2i(505, -20);
	glVertex2i(505, 5);
	glVertex2i(495, 5);
	glEnd();
	// Coroana
	glColor3f(0.133, 0.545, 0.133);
	glBegin(GL_POLYGON);
	glVertex2i(475, 5);
	glVertex2i(525, 5);
	glVertex2i(512, 45);
	glVertex2i(488, 45);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(copac_x, copac_y, 0.0);
	// Desenam copacul 5
	glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_POLYGON);
	glVertex2i(645, -20);
	glVertex2i(655, -20);
	glVertex2i(655, 5);
	glVertex2i(645, 5);
	glEnd();
	// Coroana
	glColor3f(0.133, 0.545, 0.133);
	glBegin(GL_POLYGON);
	glVertex2i(625, 5);
	glVertex2i(675, 5);
	glVertex2i(662, 45);
	glVertex2i(638, 45);
	glEnd();
	glPopMatrix();
	int copac_x2 = 360;
	int copac_y2 = 400;
	glPushMatrix();
	glTranslated(copac_x2, copac_y2, 0.0);
	// Desenam copacul 6 sus
	glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_POLYGON);
	glVertex2i(45, -20);
	glVertex2i(55, -20);
	glVertex2i(55, 5);
	glVertex2i(45, 5);
	glEnd();
	// Coroana
	glColor3f(0.133, 0.545, 0.133);
	glBegin(GL_POLYGON);
	glVertex2i(25, 5);
	glVertex2i(75, 5);
	glVertex2i(62, 45);
	glVertex2i(38, 45);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(copac_x2, copac_y2, 0.0);
	// Desenam copacul 7 sus
	glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_POLYGON);
	glVertex2i(-205, -20);
	glVertex2i(-195, -20);
	glVertex2i(-195, 5);
	glVertex2i(-205, 5);
	glEnd();
	// Coroana
	glColor3f(0.133, 0.545, 0.133);
	glBegin(GL_POLYGON);
	glVertex2i(-225, 5);
	glVertex2i(-175, 5);
	glVertex2i(-188, 45);
	glVertex2i(-212, 45);
	glEnd();
	glPopMatrix();
	//desenam masina
	glPushMatrix();
	glTranslated(0.0, j, 0.0);
	// Partea de sus a masinii
	glBegin(GL_QUADS);
	glColor3f(0.996, 0.365, 0.149);
	glVertex2i(-40, 30);
	glVertex2i(40, 30);
	glVertex2i(40, 35);
	glVertex2i(-40, 35);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2i(-40, 25);
	glVertex2i(40, 25);
	glVertex2i(40, 30);
	glVertex2i(-40, 30);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2i(-40, 20);
	glVertex2i(40, 20);
	glVertex2i(40, 25);
	glVertex2i(-40, 25);
	glEnd();
	// Partea de jos a masinii
	glBegin(GL_QUADS);
	glVertex2i(-50, 0);
	glVertex2i(50, 0);
	glVertex2i(50, 20);
	glVertex2i(-50, 20);
	glEnd();
	// Geamul din stânga
	glBegin(GL_QUADS);
	glColor3f(0.882, 0.941, 0.973);
	glVertex2i(-35, 15);
	glVertex2i(-5, 15);
	glVertex2i(-5, 25);
	glVertex2i(-35, 25);
	glEnd();
	// Geamul din dreapta
	glBegin(GL_QUADS);
	glColor3f(0.882, 0.941, 0.973);
	glVertex2i(5, 15);
	glVertex2i(35, 15);
	glVertex2i(35, 25);
	glVertex2i(5, 25);
	glEnd();
	// Farul din față
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(40, 8);
	glVertex2i(50, 8);
	glVertex2i(50, 16);
	glVertex2i(40, 16);
	glEnd();
	// Farul din spate
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(-50, 2);
	glVertex2i(-40, 2);
	glVertex2i(-40, 8);
	glVertex2i(-50, 8);
	glEnd();
	// Roata stanga
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2i(-30, 0);
	for (float i = 0; i <= 360; i++)
	{
		float x = -30 + 8 * cos(i * 3.14159f / 180.0f);
		float y = 0 + 8 * sin(i * 3.14159f / 180.0f);
		glVertex2i(x, y);
	}
	glEnd();
	// Roata dreapta
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2i(30, 0);
	for (float i = 0; i <= 360; i++)
	{
		float x = 30 + 8 * cos(i * 3.14159f / 180.0f);
		float y = 0 + 8 * sin(i * 3.14159f / 180.0f);
		glVertex2i(x, y);
	}
	glEnd();
	//glColor3f(0.996, 0.365, 0.149);
	//glRecti(-45, -15, 45, 15);
	if (ok == 0)
	{
		rsj = 8;
		rss = -8;
		rdj = -8;
		rds = 8;
	}
	glPopMatrix();
	glPopMatrix();
	if (ok == 0)
		RenderString(250.0f, 200.0f, GLUT_BITMAP_8_BY_13, (const unsigned
			char*)"GAME OVER");
	PlaySound(TEXT("C:/Users/honci/OneDrive/Desktop/proiect
		1 / gameover.wav"), NULL, SND_ASYNC);
		if (contor == 1 && (j != 160 && j != 320))
			j = j + 1;
		else if (contor == -1 && (j != 160 && j != 0))
			j = j - 1;
		else {
			contor = 0;
		}
	// desenam a doua masina(adversara)
	glPushMatrix();
	glTranslated(loc_vert, height, 0.0);
	// Partea de sus a masinii
	glBegin(GL_QUADS);
	glColor3f(0.471, 0.667, 0.949);
	glVertex2i(-40, 30);
	glVertex2i(40, 30);
	glVertex2i(40, 35);
	glVertex2i(-40, 35);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2i(-40, 25);
	glVertex2i(40, 25);
	glVertex2i(40, 30);
	glVertex2i(-40, 30);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2i(-40, 20);
	glVertex2i(40, 20);
	glVertex2i(40, 25);
	glVertex2i(-40, 25);
	glEnd();
	// Partea de jos a masinii
	glBegin(GL_QUADS);
	glVertex2i(-50, 0);
	glVertex2i(50, 0);
	glVertex2i(50, 20);
	glVertex2i(-50, 20);
	glEnd();
	// Geamul din stânga
	glBegin(GL_QUADS);
	glColor3f(0.882, 0.941, 0.973);
	glVertex2i(-35, 15);
	glVertex2i(-5, 15);
	glVertex2i(-5, 25);
	glVertex2i(-35, 25);
	glEnd();
	// Geamul din dreapta
	glBegin(GL_QUADS);
	glColor3f(0.882, 0.941, 0.973);
	glVertex2i(5, 15);
	glVertex2i(35, 15);
	glVertex2i(35, 25);
	glVertex2i(5, 25);
	glEnd();
	// Farul din spate
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(40, 2);
	glVertex2i(50, 2);
	glVertex2i(50, 8);
	glVertex2i(40, 8);
	glEnd();
	// Farul din fata
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(-50, 8);
	glVertex2i(-40, 8);
	glVertex2i(-40, 16);
	glVertex2i(-50, 16);
	glEnd();
	// Roata stanga
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2i(-30, 0);
	for (float i = 0; i <= 360; i++)
	{
		float x = -30 + 8 * cos(i * 3.14159f / 180.0f);
		float y = 0 + 8 * sin(i * 3.14159f / 180.0f);
		glVertex2i(x, y);
	}
	glEnd();
	// Roata dreapta
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2i(30, 0);
	for (float i = 0; i <= 360; i++)
	{
		float x = 30 + 8 * cos(i * 3.14159f / 180.0f);
		float y = 0 + 8 * sin(i * 3.14159f / 180.0f);
		glVertex2i(x, y);
	}
	glEnd();
	glColor3f(0.471, 0.667, 0.949);
	//glRecti(-45, -15, 45, 15);
	glPopMatrix();
	startgame();
	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 700.0, -140.0, 460.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void miscasus(void)
{
	if (ok != 0)
	{
		if (j < 320)
		{
			contor = 1;
			j += 1;
		}
		glutPostRedisplay();
	}
}
void miscajos(void)
{
	if (ok != 0)
	{
		if (j > 0)
		{
			contor = -1;
			j -= 1;
		}
		glutPostRedisplay();
	}
}
void keyboard(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP:
		miscasus();
		break;
	case GLUT_KEY_DOWN:
		miscajos();
		break;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Depaseste masinile - mini game");
	init();
	glutDisplayFunc(drawScene);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard);
	glutMainLoop();
}