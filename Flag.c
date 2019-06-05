#include <stdlib.h>
#include <GL/glut.h>

float flagWave = 1;
float move_flag = 1;
float flag_pos = 10;
float sphereMove = 10;


GLfloat ctrlPts1[4][4][3] =
	{
		{{-300, 20, 0.0}, {-100, 20, 150.0}, {100, 20, -50.0}, {250, 20, 150.0}},
		{{-300, 45, 0.0}, {-100, 45, 150.0}, {100, 45, -50.0}, {250, 45, 150.0}},
		{{-300, 70, 0.0}, {-100, 70, 150.0}, {100, 70, -50.0}, {250, 70, 150.0}},
		{{-300, 95, 0.0}, {-100, 95, 150.0}, {100, 95, -50.0}, {250, 95, 150.0}}};
GLfloat ctrlPts2[4][4][3] =
	{
		{{-300, 95, 0.0}, {-100, 95, 150.0}, {100, 95, -50.0}, {250, 95, 150.0}},
		{{-300, 120, 0.0}, {-100, 120, 150.0}, {100, 120, -50.0}, {250, 120, 150.0}},
		{{-300, 145, 0.0}, {-100, 145, 150.0}, {100, 145, -50.0}, {250, 145, 150.0}},
		{{-300, 170, 0.0}, {-100, 170, 150.0}, {100, 170, -50.0}, {250, 170, 150.0}}};
GLfloat ctrlPts3[4][4][3] =
	{
		{{-300, 170, 0.0}, {-100, 170, 150.0}, {100, 170, -50.0}, {250, 170, 150.0}},
		{{-300, 195, 0.0}, {-100, 195, 150.0}, {100, 195, -50.0}, {250, 195, 150.0}},
		{{-300, 220, 0.0}, {-100, 220, 150.0}, {100, 220, -50.0}, {250, 220, 150.0}},
		{{-300, 245, 0.0}, {-100, 245, 150.0}, {100, 245, -50.0}, {250, 245, 150.0}}};

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (move_flag == 1 && flag_pos <= 10)
			flag_pos++;

	else if (move_flag == -1 && flag_pos >= -430)
			flag_pos--;

	glPushMatrix();

		glTranslatef(0, flag_pos, 0);
		glEnable(GL_MAP2_VERTEX_3);

		glColor3f(1.0, 0.3, 0.0);
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlPts3[0][0][0]);
		glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0, 20, 0, 20);

		glColor3f(1.0, 1.0, 1.0);
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlPts2[0][0][0]);
		glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0, 20, 0, 20);

		glColor3f(0.0, 1.0, 0.0);
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlPts1[0][0][0]);
		glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0, 20, 0, 20);

	glPopMatrix();

	glPushMatrix();
		glColor3f(0.0, 0.0, 1);
		glTranslatef(0, 135 + flag_pos + sphereMove, 40);
		glutWireSphere(40, 24, 3);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.6, 0.3, 0.1);
		glTranslatef(-300, -200, 0);
		glScalef(1, 32, 1);
		glutSolidCube(30);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-300, -500, 0);
		glScalef(3, 2, 1);
		glutSolidCube(50);
	glPopMatrix();
	
	glFlush();
}

void Move()
{

	int i = 0;
	for (i = 0; i < 4; i++)
	{
		ctrlPts1[i][1][1] += flagWave;
		ctrlPts1[i][2][1] -= flagWave;
		ctrlPts1[i][3][1] += flagWave;

		ctrlPts2[i][1][1] += flagWave;
		ctrlPts2[i][2][1] -= flagWave;
		ctrlPts2[i][3][1] += flagWave;

		ctrlPts3[i][1][1] += flagWave;
		ctrlPts3[i][2][1] -= flagWave;
		ctrlPts3[i][3][1] += flagWave;
	}

	
	if (ctrlPts1[0][1][1] > 100){
		sphereMove = -2; 
		flagWave = -0.3;
	}
		
	if (ctrlPts1[0][1][1] < -50){
		sphereMove = 2;
		flagWave = 0.3;
	}
	glutPostRedisplay();
}

void menu(int value)
{

	switch (value)
	{
	case 0:
		exit(0);
		break;
	case 1:
		glClearColor(1,1,1,1);
		break;
	case 2:
		glClearColor(0,0,0,1);
		break;
	case 3:
		glClearColor(0,0,1,1);
		break;
	case 4:
		move_flag = 1;
		break;
	case 5:
		move_flag = -1;
		break;
	}
}

void myinit(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500, 500, -500, 500, -500, 500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}

void myMenu()
{

	int backgroundcolor = glutCreateMenu(menu);

	// Add sub menu entry
	glutAddMenuEntry("white", 1);
	glutAddMenuEntry("black", 2);
	glutAddMenuEntry("blue", 3);

	int flagmovement = glutCreateMenu(menu);

	glutAddMenuEntry("up", 4);
	glutAddMenuEntry("down", 5);

	// Create the menu, this menu becomes the current menu
	glutCreateMenu(menu);

	// Create an entry
	glutAddSubMenu("Background color", backgroundcolor);
	glutAddSubMenu("Flag movement", flagmovement);
	// Create an entry
	glutAddMenuEntry("exit", 0);

	// Let the menu respond on the right mouse button
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Indian Flag");
	myinit();
	myMenu();
	
	glutIdleFunc(Move);
	glutDisplayFunc(display);
	glutMainLoop();
}
