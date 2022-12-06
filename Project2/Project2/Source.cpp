#include <GL\glut.h>
//#include "Source.h"
GLfloat xT = 0, xY = 0, xX = 0, xZ = 0, tmpx = 0.0, tmpy = 0.0, angle = 0, rotX = 0, rotY = 0, rotZ = 0;
int flag = 0;
int rot = 0;
int ind = 0;

struct legs
{
	float x, y, z;
	float r, g, b;
	int status;
};

struct legs arr2[4];
void init_legs()
{
	int i;
	arr2[0].z = -1;
	arr2[1].z = -3;
	arr2[2].z = 1;
	arr2[3].z = 3.45;
	for (i = 0; i < 4; i++)
	{
		arr2[i].x = -4 + i;
		arr2[i].y = -2;

		arr2[i].r = 0.0;
		arr2[i].g = 0.0;
		arr2[i].b = 1.0;
		arr2[i].status = 0;
	}

}

void floor()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, -3, -12);
	glRotatef(rot, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.8, 0.1);
	glNormal3f(0, 1, 0);
	glVertex3f(-4.5, 0, -4.5);
	glVertex3f(4.5, 0, -4.5);
	glVertex3f(4.5, 0, 4.5);
	glVertex3f(-4.5, 0, 4.5);
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.2);
	glNormal3f(0, 1, 0);
	glVertex3f(-4, 0, -4);
	glVertex3f(4, 0, -4);
	glVertex3f(4, 0, 4);
	glVertex3f(-4, 0, 4);
	glEnd();
	

}
void func()
{

	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glutSolidSphere(0.3, 32, 32);
	glFlush();
	glColor3f(1.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glutSolidSphere(0.3, 32, 32);
	glFlush();
	glColor3f(0.0, 1.0, 1.0);
	glTranslatef(0.0,0.0, 0.0);
	glutSolidSphere(0.3, 32, 32);
	glFlush();
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glutSolidSphere(0.3, 32, 32);
	glFlush();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0.0,0.0, 0.0);
	glutSolidSphere(0.3, 32, 32);
	glFlush();
}
void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT |
		GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(0, -3, -13);
	glRotatef(rot, 0, 1, 0);
	floor();

	for (int i = 0; i < 5; i++)
	{

		glTranslatef(arr2[i].x, arr2[i].y, arr2[i].z);
		glColor3f(arr2[i].r, arr2[i].g, arr2[i].b);
		func();
		glTranslatef(-arr2[i].x, -arr2[i].y, -arr2[i].z);
		glTranslatef(0.2, 0, 0);
	}
	for (int i = 0; i < 5; i++)
	{
		glTranslatef(arr2[i].x, arr2[i].y, arr2[i].z);
		glColor3f(arr2[i].r, arr2[i].g, arr2[i].b);
		init_legs();
		glTranslatef(-arr2[i].x, -arr2[i].y, -arr2[i].z);
		glTranslatef(0.2, 0, 0);
	}

	glutSwapBuffers();
}
int move_x(int i)
{
	int j;
	for (j = 0; j < 5; j++)
	{
		if (j != i)
		{
			if (arr2[i].x >= arr2[j].x - 1.1&&
				arr2[i].x <= arr2[j].x + 1.1&&
				arr2[i].z >= arr2[j].z - 1.1&&
				arr2[i].z <= arr2[j].z + 1.1)
				return 0;
		}
	}
	return 1;
}

void Idle(void)
{

	
		/*if (xY <= 1 && flag == 0)
		{
			xY += 0.003;
			if (xY > 1) flag = 1;
		}
		if (xY >= -1 && flag == 1)
		{
			xY -= 0.003;
			if (xY < -1) flag = 0;
		}

		angle += 0.03;
		Display();*/

	for (int i = 0; i < 5; i++)
	{
		if (arr2[i].x <= 4.25 && flag == 0)
		{
			arr2[i].x -= 0.01;
			if (arr2[i].x < -4.25)
				flag = 1;
			if (move_x(i) == 0)
				arr2[i].x += 0.1;
		}
		if (arr2[i].x >= 4.25 && flag == 0)
		{
			arr2[i].x += 0.01;
			if (arr2[i].x < -4.25)
				flag = 1;
			if (move_x(i) == 0)
				arr2[i].x -= 0.1;
		}

		if (arr2[i].z <= 4.25 && flag == 0)
		{
			arr2[i].z -= 0.01;
			if (arr2[i].z < -4.25)
				flag = 1;
			if (move_x(i) == 0)
				arr2[i].z += 0.1;
		}
		if (arr2[i].z >= 4.25 && flag == 0)
		{
			arr2[i].z += 0.01;
			if (arr2[i].z < -4.25)
				flag = 1;
			if (move_x(i) == 0)
				arr2[i].z -= 0.1;
		}
		//angle += 0.03;
		Display();

	}
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);

}


//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key) {
//
//	case 'x':
//		rotX = 1;
//		rotY = 0;
//		rotZ = 0;
//
//		break;
//	case 'y':
//		rotX = 0;
//		rotY = 1;
//		rotZ = 0;
//		break;
//	case 'z':
//		rotX = 0;
//		rotY = 0;
//		rotZ = 1;
//		break;
//	case 27:
//		exit(0);
//		break;
//	default:
//		break;
//
//	}
//	glutPostRedisplay();
//}
int main(int argc, char **argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  //For animations you should use double buffering
	glutInitWindowSize(700, 700);
	glutCreateWindow("3D");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(Display);
	//glutKeyboardFunc(keyboard);
	glutIdleFunc(Idle);
	init_legs();
	init();
	glutMainLoop();
	return 0;
}
