#include<GL/GLUT.H>


struct Ball
{
	float x;         //X-LOCETION
	float y;         //Y-LOCITION
	float z;         //Z-LOCITION
	float r;         //RED COLOR
	float g;         //GREEN COLOR
	float b;         //BLUE COLOR
	int status;           //BALL EXISTS OR NOT FLAG
	int flag;                   //UP & DOWN DIRECTION FLAG
	int rightLaftWallFlag;      //LEFT & RIGHT DIRECTION FLAG
	int throwBallFlag;          //HET THE STICK DIRECTION FLAG  
}typedef Ball;

int rot = 90, rot2 = 25;
float N = 0.1;
float z1 = 2, z2 = -2;//STICK DEFENTION
Ball ballsDet[5];  //BALL DECLERTION

char *pointsCal(int points);
void keyboard(unsigned char key, int x, int y);
void floor(); 
void BoundaryWall(); 
void block(); 
void legs();
void holes(); 
void balls(); 
void timer(); 
void init(); 
void draw(); 

int main(int argc, char *argv[]) {

	

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);	// RGB display, double-buffered, with Z-Buffer
	glutInitWindowSize(1000, 1000);	// 500 x 500 pixels
	glutCreateWindow("Project - shalom and luzan");
	glutDisplayFunc(draw);	// Set the display function
	glutKeyboardFunc(keyboard);	// Set the keyboard function
	glutTimerFunc(1000, timer, 0);
	balls();


	init();

	glutMainLoop();	// Start the main event loop
}
void keyboard(unsigned char key, int x, int y)
{

	if (key == 'n') N=N-0.1;// light down
	if (key == 'm') N = N + 0.1;//light up
	if (key == 'l') z1--;//RESIZE STICK
	if (key == 'k') z1++;//RESIZE STICK

	if (key == 'r') balls();//RESET BALLS
	if (key == 'q') exit(1);

	if (key == 'w' && rot < 120 && rot2 != 90)//move right
		rot += 5;

	if (key == 's' && rot > 60 && rot2 != 90)//move left
		rot -= 5;

	if (key == 'x') {						//upDown
		if (rot2 == 25) {
			rot = 90;
			rot2 = 90;
		}
		else
			rot2 = 25;
	}

	if (key == 'd' && z1 < 6.5 && z2 < 4.5) { // BLOCK MOVE RIGHT
		z1 += 0.5;
		z2 += 0.5;
	}
	else if (key == 'a' && z1 > -8.5 && z2 > -6.5) { // BLOCK MOVE LEFT
		z1 -= 0.5;
		z2 -= 0.5;
	}

	glutPostRedisplay();
}

void floor() {
	glColor3f(0.36, 0.54, 0.66);
	
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(-8, 0, -7);
	glVertex3f(5, 0, -7);
	glVertex3f(5, 0, 7);
	glVertex3f(-8, 0, 7);

	glNormal3f(0.6, 1, 0);
	glVertex3f(-8, 0, -7);
	glVertex3f(5, 0, -7);
	glVertex3f(5, -0.2, -7);
	glVertex3f(-8, -0.2, -7);

	glNormal3f(0.6, 1, 0);
	glVertex3f(5, 0, 7);
	glVertex3f(-8, 0, 7);
	glVertex3f(-8, -0.2, 7);
	glVertex3f(5, -0.2, 7);

	glNormal3f(0.6, 1, 0);
	glVertex3f(5, 0, -7);
	glVertex3f(5, 0, 7);
	glVertex3f(5, -0.2, 7);
	glVertex3f(5, -0.2, -7);

	glNormal3f(0.6, 1, 0);
	glVertex3f(-8, 0, -7);
	glVertex3f(-8, 0, 7);
	glVertex3f(-8, -0.2, 7);
	glVertex3f(-8, -0.2, -7);
	glEnd();
}
void BoundaryWall() {

	
	glColor3f(0.52, 0.87, 0.01);
	// LEFT CORNER
	
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(-7.5, 1, -7);
	glVertex3f(6, 1, -7);
	glVertex3f(6, 1, -6);
	glVertex3f(-7.5, 1, -6);

	glNormal3f(0.1, 1, 0);
	glVertex3f(-7.5, 0, -7);
	glVertex3f(6, 0, -7);
	glVertex3f(6, 1, -7);
	glVertex3f(-7.5, 1, -7);

	glNormal3f(0.1, 1, 0);
	glVertex3f(6, 0, -6);
	glVertex3f(-7.5, 0, -6);
	glVertex3f(-7.5, 1, -6);
	glVertex3f(6, 1, -6);

	glNormal3f(0.1, 1, 0);
	glVertex3f(6, 0, -7);
	glVertex3f(6, 0, -6);
	glVertex3f(6, 1, -6);
	glVertex3f(6, 1, -7);

	glNormal3f(0.5, 1, 0);
	glVertex3f(-7.5, 0, -7);
	glVertex3f(-7.5, 0, -6);
	glVertex3f(-7.5, 1, -6);
	glVertex3f(-7.5, 1, -7);
	glEnd();

	// RIGHT CORNER
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(-7.5, 1, 6);
	glVertex3f(6, 1, 6);
	glVertex3f(6, 1, 7);
	glVertex3f(-7.5, 1, 7);

	glNormal3f(0.1, 1, 0);
	glVertex3f(-7.5, 0, 6);
	glVertex3f(6, 0, 6);
	glVertex3f(6, 1, 7);
	glVertex3f(-7.5, 1, 7);

	glNormal3f(0.1, 1, 0);
	glVertex3f(6, 0, 7);
	glVertex3f(-7.5, 0, 7);
	glVertex3f(-7.5, 1, 7);
	glVertex3f(5, 1, 7);

	glNormal3f(0.1, 1, 0);
	glVertex3f(6, 0, 6);
	glVertex3f(6, 0, 7);
	glVertex3f(6, 1, 7);
	glVertex3f(6, 1, 6);

	glNormal3f(0.5, 1, 0);
	glVertex3f(-7.5, 0, 6);
	glVertex3f(-7.5, 0, 7);
	glVertex3f(-7.5, 1, 7);
	glVertex3f(-7.5, 1, 6);
	glEnd();

	// FRONT CORNER
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(6, 1, -6);
	glVertex3f(6, 1, 6);
	glVertex3f(5, 1, 6);
	glVertex3f(5, 1, -6);

	glNormal3f(0.1, 1, 0);
	glVertex3f(6, 0, -6);
	glVertex3f(6, 0, 6);
	glVertex3f(6, 1, 6);
	glVertex3f(6, 1, -6);

	glNormal3f(0.1, 1, 0);
	glVertex3f(5, 0, 6);
	glVertex3f(5, 0, -6);
	glVertex3f(5, 1, -6);
	glVertex3f(5, 1, 6);

	glNormal3f(0.1, 1, 0);
	glVertex3f(6, 0, 6);
	glVertex3f(5, 0, 6);
	glVertex3f(5, 1, 6);
	glVertex3f(6, 1, 6);

	glNormal3f(0.1, 1, 0);
	glVertex3f(6, 0, -6);
	glVertex3f(5, 0, -6);
	glVertex3f(5, 1, -6);
	glVertex3f(6, 1, -6);
	glEnd();
}
void block() {

	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(-8, 0.3, z2);
	glVertex3f(-8, 0.5, z1);
	glVertex3f(-7.5, 0.5, z1);
	glVertex3f(-7.5, 0.5, z2);

	glNormal3f(0.3, 1, 0);
	glVertex3f(-8, 0, z2);
	glVertex3f(-8, 0, z1);
	glVertex3f(-8, 0.5, z1);
	glVertex3f(-8, 0.5, z2);

	glNormal3f(0.9, 1, 0);
	glVertex3f(-7.5, 0, z1);
	glVertex3f(-7.5, 0, z2);
	glVertex3f(-7.5, 0.5, z2);
	glVertex3f(-7.5, 0.5, z1);

	glNormal3f(0.3, 1, 0);
	glVertex3f(-8, 0, z1);
	glVertex3f(-7.5, 0, z1);
	glVertex3f(-7.5, 0.5, z1);
	glVertex3f(-8, 0.5, z1);

	glNormal3f(0.3, 1, 0);
	glVertex3f(-8, 0, z2);
	glVertex3f(-7.5, 0, z2);
	glVertex3f(-7.5, 0.5, z2);
	glVertex3f(-8, 0.5, z2);
	glEnd();
}
void legs()
{
	glColor3f(0.0, 0.0, 0.0);
	//leg1
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 0.5);
	glVertex3f(-6, 0, -7);
	glVertex3f(-6, -12, -7);
	glVertex3f(-7, -12, -7);
	glVertex3f(-7, 0, -7);
	glNormal3f(0, 0, -0.5);
	glVertex3f(-6, 0, -6);
	glVertex3f(-7, 0, -6);
	glVertex3f(-7, -10, -6);
	glVertex3f(-6, -10, -6);
	glNormal3f(-0.5, 0, 0);
	glVertex3f(-6, 0, -7);
	glVertex3f(-6, -12, -7);
	glVertex3f(-6, -12, -6);
	glVertex3f(-6, 0, -6);
	glNormal3f(0.5, 0, 0);
	glVertex3f(-7, 0, -7);
	glVertex3f(-7, 0, -6);
	glVertex3f(-7,-12, -6);
	glVertex3f(-7, -12, -7);
	glEnd();
	//leg2
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 0.5);
	glVertex3f(-6, 0, 7);
	glVertex3f(-6, -12, 7);
	glVertex3f(-7, -12, 7);
	glVertex3f(-7, 0, 7);
	glNormal3f(0, 0, -0.5);
	glVertex3f(-6, 0, 6);
	glVertex3f(-7, 0, 6);
	glVertex3f(-7, -10, 6);
	glVertex3f(-6, -10, 6);
	glNormal3f(-0.5, 0, 0);
	glVertex3f(-6, 0, 7);
	glVertex3f(-6, -12, 7);
	glVertex3f(-6, -12, 6);
	glVertex3f(-6, 0, 6);
	glNormal3f(0.5, 0, 0);
	glVertex3f(-7, 0, 7);
	glVertex3f(-7, 0, 6);
	glVertex3f(-7, -12, 6);
	glVertex3f(-7, -12, 7);
	glEnd();
	//leg3
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 0.5);
	glVertex3f(5, 0, -7);
	glVertex3f(5, -12, -7);
	glVertex3f(4.5, -12, -7);
	glVertex3f(4.5, 0, -7);
	glNormal3f(0, 0, -0.5);
	glVertex3f(5, 0, -6);
	glVertex3f(4.5, 0, -6);
	glVertex3f(4.5, -10, -6);
	glVertex3f(5, -10, -6);
	glNormal3f(-0.5, 0, 0);
	glVertex3f(5, 0, -7);
	glVertex3f(5, -12, -7);
	glVertex3f(5, -12, -6);
	glVertex3f(5, 0, -6);
	glNormal3f(0.5, 0, 0);
	glVertex3f(4.5, 0, -7);
	glVertex3f(4.5, 0, -6);
	glVertex3f(4.5, -12, -6);
	glVertex3f(4.5, -12, -7);
	glEnd();
	//leg4
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 0.5);
	glVertex3f(5, 0, 7);
	glVertex3f(5, -12, 7);
	glVertex3f(4.5, -12, 7);
	glVertex3f(4.5, 0, 7);
	glNormal3f(0, 0, -0.5);
	glVertex3f(5, 0, 6);
	glVertex3f(4.5, 0, 6);
	glVertex3f(4.5, -10, 6);
	glVertex3f(5, -10, 6);
	glNormal3f(-0.5, 0, 0);
	glVertex3f(5, 0, 7);
	glVertex3f(5, -12, 7);
	glVertex3f(5, -12, 6);
	glVertex3f(5, 0, 6);
	glNormal3f(0.5, 0, 0);
	glVertex3f(4.5, 0, 7);
	glVertex3f(4.5, 0, 6);
	glVertex3f(4.5, -12,6);
	glVertex3f(4.5, -12,7);
	glEnd();
}
void holes() {

	glColor3f(0.59, 0.29, 0.00);

	// left hole
	glBegin(GL_QUADS);
	glVertex3f(3, 0.01, -5);
	glVertex3f(3, 0.01, -3.5);
	glVertex3f(1.5, 0.01, -3.5);
	glVertex3f(1.5, 0.01, -5);
	glEnd();

	// right hole
	glBegin(GL_QUADS);
	glVertex3f(3, 0.01, 5);
	glVertex3f(3, 0.01, 3.5);
	glVertex3f(1.5, 0.01, 3.5);
	glVertex3f(1.5, 0.01, 5);
	glEnd();
}
void balls() {
	ballsDet[0].x = -3.3;
	ballsDet[0].y = 0.2;
	ballsDet[0].z = 3.2;
	ballsDet[0].r = 0.7;
	ballsDet[0].g = 0.0;
	ballsDet[0].b = 0.1;
	ballsDet[0].status = 0;
	ballsDet[0].flag = 1;
	ballsDet[0].rightLaftWallFlag = -1;
	ballsDet[0].throwBallFlag = -1;

	ballsDet[1].x = 1.2;
	ballsDet[1].y = 0.2;
	ballsDet[1].z = 1.2;
	ballsDet[1].r = 0.7;
	ballsDet[1].g = 0.9;
	ballsDet[1].b = 0.2;
	ballsDet[1].status = 0;
	ballsDet[1].flag = 1;
	ballsDet[1].rightLaftWallFlag = -1;
	ballsDet[1].throwBallFlag = -1;

	ballsDet[2].x = -1.2;
	ballsDet[2].y = 0.2;
	ballsDet[2].z = -1.5;
	ballsDet[2].r = 1.0;
	ballsDet[2].g = 0.9;
	ballsDet[2].b = 0.2;
	ballsDet[2].status = 0;
	ballsDet[2].flag = 1;
	ballsDet[2].rightLaftWallFlag = -1;
	ballsDet[2].flag = 1;
	ballsDet[2].throwBallFlag = -1;

	ballsDet[3].x = -3.2;
	ballsDet[3].y = 0.2;
	ballsDet[3].z = -4.5;
	ballsDet[3].r = 0.6;
	ballsDet[3].g = 0.4;
	ballsDet[3].b = 1.2;
	ballsDet[3].status = 0;
	ballsDet[3].flag = 1;
	ballsDet[3].rightLaftWallFlag = -1;
	ballsDet[3].flag = 1;
	ballsDet[3].throwBallFlag = -1;

	ballsDet[4].x = 2;
	ballsDet[4].y = 0.2;
	ballsDet[4].z = 2;
	ballsDet[4].r = 0.1;
	ballsDet[4].g = 0.5;
	ballsDet[4].b = 1.0;
	ballsDet[4].status = 0;
	ballsDet[4].flag = 1;
	ballsDet[4].rightLaftWallFlag = -1;
	ballsDet[4].flag = 1;
	ballsDet[4].throwBallFlag = -1;
}
void headlight(float N)	
{
	
	// Lighting parameters

	GLfloat ambientLight[] = { N, N, N, N };
	GLfloat diffuseLighting[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat specularLighting[] = { 80.0 };
	GLfloat mat[] = { 128.0 };

	GLfloat position[] = { 1, 2,-3 };
	glClearColor(0.9, 0.9, 0.9, 0.0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);	// set both amb and diff components
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLighting);		// set specular
	glLightfv(GL_LIGHT0, GL_DIFFUSE, ambientLight);
	glLightfv(GL_MAX_LIGHTS, GL_SHININESS, mat);		// set light "position", in this case direction

	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	/////////////////////////////////////////////////////////////////
}
void timer() {
	float x, y, z; // BALL X,Y,Z
	int i;
	for (i = 0; i < 5; i++) {
		x = ballsDet[i].x, y = ballsDet[i].y, z = ballsDet[i].z;

		if (ballsDet[i].status != 0 && ballsDet[i].y < -35) continue; // ball that is out of game

		if (z < -5.75)
			ballsDet[i].rightLaftWallFlag = 1;  //LEFT LIMIT CONDITION
		if (z > 5.75)
			ballsDet[i].rightLaftWallFlag = 0;  //RIGHT LIMIT CONDITION

		if (ballsDet[i].flag == 1) {	// UP DIRECTION
			if ((x > 1.5 && x <3) && ((z > 3.75 && z < 5.25) || (z > -5.25 && z < -3.75))) { // THE BALL FALLOUT BECAUSE THE HOLE
				ballsDet[i].y -= 0.1;
				ballsDet[i].status = 1;
				continue;
			}

			if (ballsDet[i].rightLaftWallFlag == 1) { // RIGHT WALL LIMIT EXECUTION
				ballsDet[i].x += 0.1;
				ballsDet[i].z += 0.1;
			}
			else if (ballsDet[i].rightLaftWallFlag == 0) { // LEFT WALL LIMIT EXECUTION
				ballsDet[i].x += 0.1;
				ballsDet[i].z -= 0.1;
			}
			else if (ballsDet[i].rightLaftWallFlag == -1) {
				if (ballsDet[i].throwBallFlag == 1) { //BLOCK THROWING BALL DIRECTION FLAG 
					ballsDet[i].x += 0.1;
					ballsDet[i].z -= 0.1;
				}
				else if (ballsDet[i].throwBallFlag == 0) {
					ballsDet[i].x += 0.1;
					ballsDet[i].z += 0.1;
				}
				else { // START GAME SITUATION
					ballsDet[i].x += 0.1;
					if (i % 2 == 0)
						ballsDet[i].z += 0.1;
					else
						ballsDet[i].z -= 0.1;
				}
			}
			if (x > 2.75) // FRONT LIMIT
				ballsDet[i].flag = 0;
		}
		else {
			if ((x > 1.5 && x < 3) && ((z > 3.75 && z < 5.75) || (z > -5.75 && z < -3.75))) { // THE BALL FALLOUT BECAUSE THE HOLE
				ballsDet[i].y -= 0.1;
				ballsDet[i].status = 1;
				continue;
			}

			if (ballsDet[i].rightLaftWallFlag == 1 && x > -8.25) { // RIGHT WALL LIMIT
				ballsDet[i].x -= 0.1;
				ballsDet[i].z += 0.1;
			}
			else if (ballsDet[i].rightLaftWallFlag == 0 && x > -8.25) { // LEFT WALL LIMIT
				ballsDet[i].x -= 0.1;
				ballsDet[i].z -= 0.1;
			}
			else if (ballsDet[i].rightLaftWallFlag == -1 && x > -8.25) {
				ballsDet[i].x -= 0.1;
				ballsDet[i].z -= 0.1;
			}
			else if (x < -8.25) { // BALL FALLOUT
				ballsDet[i].y -= 0.1;
				ballsDet[i].status = -1;
				continue;
			}

			if ((z < z1 && z > z2) && (x < -6.75 && x > -7.0)) {
				ballsDet[i].flag = 1; // TURN TO ANOTHER SIDE DIRECTION
				ballsDet[i].rightLaftWallFlag = -1;
				if (z < ((z1 + z2) / 2)) // DIRECTION THROWING BALL
					ballsDet[i].throwBallFlag = 1;
				else
					ballsDet[i].throwBallFlag = 0;
			}
		}
	}
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
}
char *pointsCal(int points) {
	int i = 0;
	char *str, sen[8] = "Points: ";

	str = (char *)malloc(12);

	for (i = 0; i < 8; i++)
		str[i] = sen[i];

	if (points >= 0)
		str[i++] = points + '0';
	else if (points > -10 && points < 0) {
		str[i++] = '-';
		str[i++] = -(points)+'0';
	}
	else {
		str[i++] = '-';
		str[i++] = '1';
		str[i++] = '0';
	}

	str[i++] = 0;
	return str;
}

void drowball()
{
	// DRAWING BALLS
	for (int i = 0; i < 5; i++) {
		glColor3f(ballsDet[i].r, ballsDet[i].g, ballsDet[i].b);
		glTranslatef(ballsDet[i].x, ballsDet[i].y, ballsDet[i].z);
		glutSolidSphere(0.2, 50, 50);
		glTranslatef(-ballsDet[i].x, -ballsDet[i].y, -ballsDet[i].z);

	}
}
void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity(); // view
	glTranslatef(0, 0, -20);
	glRotatef(rot, 0, 1, 0);
	glRotatef(rot2, 0, 0, 1);

	floor(); // DROW FLOOR
	BoundaryWall(); // DROW Boundary Wall
	legs();//DROW LEGS
	holes(); // DROW HOLES
	block(); // DROW BLOCK
	headlight(N);
	// DRAWING BALLS
	drowball();

	// POINTS VIEW
	int points = 0;

	for (int i = 0; i < 5; i++) {
		if (ballsDet[i].status == 1)
			points++;
		else if (ballsDet[i].status == -1)
			points -= 2;
	}

	char *str = pointsCal(points);
	glColor3f(0.0, 0.0, 0.0);
	if (rot2 == 25) glRasterPos3f(12, 0, -1.3);
	else glRasterPos3f(3, 10, -0.3);
	do
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *str);
	while (*(++str));

	glutSwapBuffers();	// display the output
}
// Set OpenGL parameters
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);

	headlight(N);
	
}