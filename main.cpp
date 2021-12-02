#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>

void drawQuads(GLfloat x, GLfloat y, GLfloat height,GLfloat width);
void drawSquare(GLfloat x, GLfloat y, GLfloat height);

void background(int a,int b,int c, int d){
	glBegin(GL_QUADS);
	glColor3ub(214, 107, 75);
	glVertex2i(0, 0);
	glColor3ub(214, 107, 75);
	glVertex2i(1920, 0);
	glColor3ub(138, 74, 75);
	glVertex2i(1920, 885);
	glColor3ub(138, 74, 75);
	glVertex2i(0, 885);
	glEnd();
}

void bridge(){
	glColor3ub(104, 55, 61);
	drawQuads(0, 596, 20, 1920);
	glColor3ub(67, 36, 41);
	drawQuads(0, 616, 8, 1920);
}

void footpath(){
	int flag=0;
	glColor3ub(57, 48, 39);
	drawQuads(0, 885, 63, 1920);
	for(int i=0;i<1920;i+=80){
		if(flag==0){
			glColor3ub(68, 47, 46);
			drawQuads(i, 948, 14, 80);
			
			glColor3ub(47, 24, 8);
			drawQuads(i, 962, 38, 80);

			flag=1;
		}
		else{
			glColor3ub(110, 95, 88);
			drawQuads(i, 948, 14, 80);
			glColor3ub(83, 68, 61);
			drawQuads(i, 962, 38, 80);

			flag=0;
		}
	}
	glColor3ub(107, 89, 89);
	drawQuads(0, 1000, 80, 1920);
}

void bench(){
	glColor3ub(156, 90, 92);
	drawQuads(759, 792, 103, 12);
}

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);

glPointSize(5.0);

//background theme
background(1, 2, 3, 4);

//bridge er shoja jayga
bridge();

//footpath
footpath();

//bench
bench();

glEnd();
glFlush ();

}


void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 1920.0, 1080.0, 0.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (960, 540);
glutInitWindowPosition (960, 540);
glutCreateWindow ("Hatir Jheel lite");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();

}

//drawquads
void drawQuads(GLfloat x, GLfloat y, GLfloat height,GLfloat width){
	glBegin(GL_QUADS);
	glVertex2i(x, y);
	glVertex2i(x+width, y);
	glVertex2i(x+width, y+height);
	glVertex2i(x, y+height);
	glEnd();
}
//draw square
void drawSquare(GLfloat x, GLfloat y, GLfloat height){
	drawQuads(x, y, height, height);	
}
