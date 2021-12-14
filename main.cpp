#include<iostream>
#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#define PI 3.1416
int posCloud[5]={0,400,800,1200,1700};int cloudSpeed[5]={4,20,7,9,11};

using namespace std;
void drawQuads(GLfloat x, GLfloat y, GLfloat height,GLfloat width);
void drawSquare(GLfloat x, GLfloat y, GLfloat height);
void curve(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4);
void bridgeCurve(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4);
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius);
void cloud();
void drawMoon();
void drawLampPost();

string mode="sunrise";
void update(int a)
{

    for(int i=0;i<5;i++)
    {

        if(posCloud[i]>1900)
            posCloud[i]=-100;
        posCloud[i]+=cloudSpeed[i];

    }
    glutPostRedisplay();
	glutTimerFunc(100, update, 0);

}
void drawStar() {
  glColor3ub(255,255,255);
  drawFilledCircle(0, 0, 5);
  glColor3f(.8, .8, .8);
  drawFilledCircle(0, 0, 3);
}



void background(string mode){
	int sunriseColors[]={214,107,75,138, 74, 75};
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

	glColor3ub(255, 230, 200);
	drawFilledCircle(1161,594,111);

}

void tower(){
	glLineWidth(1);
	glBegin(GL_LINES);
	int x1=0,x2=1920,y=462;
	glColor3ub(0,0,0);
	for(int i=0;i<3;i++)
	{
		glVertex2i(x1, y);
		glVertex2i(x2, y);
		y+=40;
	}
	glEnd();
	for(int i=0,dx=0;i<3;i++,dx+=706){
	for(int j=0,dy=0;j<3;j++,dy+=40)
    {
        glBegin(GL_LINE_STRIP);
        glVertex2i(273+dx,463+dy);
	    glVertex2i(292+dx,450+dy);
        glVertex2i(307+dx,450+dy);
	    glVertex2i(328+dx,463+dy);
	    glEnd();

    }
    glBegin(GL_LINE_STRIP);
    glVertex2i(292+dx,450);
    glVertex2i(292+dx,544);
    glVertex2i(238+dx,775);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2i(296+dx,450);
    glVertex2i(296+dx,544);
    glVertex2i(267+dx,779);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2i(304+dx,450);
    glVertex2i(304+dx,544);
    glVertex2i(321+dx,787);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2i(308+dx,450);
    glVertex2i(308+dx,544);
    glVertex2i(354+dx,762);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2i(297+dx,450);
    glVertex2i(304+dx,457);
    glVertex2i(297+dx,463);
    glVertex2i(304+dx,467);
    glVertex2i(297+dx,471);
    glVertex2i(304+dx,474);
    glVertex2i(297+dx,477);
    glVertex2i(304+dx,482);
    glVertex2i(297+dx,485);
    glVertex2i(304+dx,490);
    glVertex2i(297+dx,496);
    glVertex2i(304+dx,500);
    glVertex2i(297+dx,504);
    glVertex2i(304+dx,507);
    glVertex2i(297+dx,511);
    glVertex2i(304+dx,514);
    glVertex2i(297+dx,517);
    glVertex2i(304+dx,519);
    glVertex2i(297+dx,524);
    glVertex2i(304+dx,530);
    glVertex2i(297+dx,538);
    glVertex2i(304+dx,544);

    glVertex2i(296+dx,552);
    glVertex2i(304+dx,564);
    glVertex2i(292+dx,577);
    glVertex2i(306+dx,591);
    glVertex2i(287+dx,615);
    glVertex2i(310+dx,633);
    glVertex2i(282+dx,658);
    glVertex2i(313+dx,684);
    glVertex2i(275+dx,708);
    glVertex2i(317+dx,737);
    glVertex2i(268+dx,770);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2i(320+dx,777);
    glVertex2i(272+dx,739);
    glVertex2i(316+dx,720);
    glVertex2i(280+dx,680);
    glVertex2i(311+dx,655);
    glVertex2i(285+dx,634);
    glVertex2i(307+dx,609);
    glVertex2i(290+dx,591);
    glVertex2i(305+dx,574);
    glVertex2i(294+dx,561);
    glVertex2i(304+dx,552);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2i(269+dx,762);
    glVertex2i(244+dx,748);
    glVertex2i(271+dx,739);
    glVertex2i(250+dx,721);
    glVertex2i(275+dx,705);
    glVertex2i(260+dx,682);
    glVertex2i(282+dx,656);
    glVertex2i(268+dx,644);
    glVertex2i(284+dx,634);
    glVertex2i(272+dx,625);
    glVertex2i(287+dx,612);
     glVertex2i(277+dx,605);
    glVertex2i(289+dx,592);
    glVertex2i(283+dx,583);
    glVertex2i(291+dx,576);
    glVertex2i(285+dx,569);
    glVertex2i(293+dx,563);
    glVertex2i(288+dx,558);
    glVertex2i(294+dx,551);
    glEnd();

     glBegin(GL_LINE_STRIP);
    glVertex2i(354+dx,763);
    glVertex2i(318+dx,742);
    glVertex2i(344+dx,720);
    glVertex2i(316+dx,710);
    glVertex2i(337+dx,688);
    glVertex2i(313+dx,672);
    glVertex2i(328+dx,647);
    glVertex2i(310+dx,633);
    glVertex2i(323+dx,623);
    glVertex2i(308+dx,610);
     glVertex2i(319+dx,602);
    glVertex2i(307+dx,591);
    glVertex2i(315+dx,584);
    glVertex2i(306+dx,575);
    glVertex2i(312+dx,570);
    glVertex2i(309+dx,557);
    glVertex2i(303+dx,548);
    glEnd();


	}




}

void bridge(){
	glColor3ub(104, 55, 61);
	drawQuads(0, 596, 20, 1920);
	glColor3ub(67, 36, 41);
	drawQuads(0, 616, 8, 1920);
	glColor3ub(133, 57, 61);
	bridgeCurve(24,680,124,362,451,362,551,680);
	int x1=1678,y1=594;
	drawQuads(x1, y1, 118, 65);
	x1-=570;
	drawQuads(x1, y1, 118, 65);
	x1-=570;
	drawQuads(x1, y1, 118, 65);
	x1-=565;
	drawQuads(x1, y1, 118, 65);


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
glPushMatrix();
//background theme
background("night");
glPopMatrix();


//bridge er shoja jayga
glPushMatrix();
bridge();
glPopMatrix();


//footpath
glPushMatrix();
footpath();
glPopMatrix();

//bench
glPushMatrix();
bench();
glPopMatrix();

//bridge curve
glPushMatrix();
tower();
glPopMatrix();

glPushMatrix();
drawStar();
glPopMatrix();

glPushMatrix();
cloud();
glPopMatrix();


glPushMatrix();
drawLampPost();
glPopMatrix();

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
glutInitWindowPosition (0,0);
glutCreateWindow ("Hatir Jheel lite");
glutDisplayFunc(myDisplay);
myInit ();
  glutTimerFunc(100, update, 0);
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
void bridgeCurve(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
	int n=569;
	curve(x1,y1,x2,y2,x3,y3,x4,y4);
	x1+=n;x2+=n;x3+=n;x4+=n;
	curve(x1,y1,x2,y2,x3,y3,x4,y4);
	x1+=n;x2+=n;x3+=n;x4+=n;
	curve(x1,y1,x2,y2,x3,y3,x4,y4);
	x1+=n;x2+=n;x3+=n;x4+=n;
	curve(x1,y1,x2,y2,x3,y3,x4,y4);
}

//bridge curve...
void curve(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{

GLfloat x[4],y[4],xt[1000],yt[1000];

x[0]=x1,x[1]=x2,x[2]=x3,x[3]=x4;
y[0]=y1,y[1]=y2,y[2]=y3,y[3]=y4;

glPointSize(10.0);
glBegin(GL_POINTS);

int i=0;
for(GLfloat t=0;t<=1;t=t+0.001)
{
    //bezier equation for four control points
    xt[i]=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
    yt[i]=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
    glVertex2f(xt[i],yt[i]);
    i++;
}

glEnd();
}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 50;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
void cloud()
{

    for(int i=0;i<5;i++){
            glPushMatrix();
    glTranslatef(posCloud[i],0, 0);
    glColor3ub(255, 255 , 255);
	drawFilledCircle(0,150+i*20,40);
	drawFilledCircle(0+35,110+i*20,50);
	drawFilledCircle(0+55,150+i*20,55);
	drawFilledCircle(0+90,100+i*20,65);
	drawFilledCircle(0+100,140+i*20,65);
	drawFilledCircle(0+160,150+i*20,40);
	glPopMatrix();
    }
}
void drawMoon()
{
    glColor3ub(255, 255 , 255);
    drawFilledCircle(1161,294,111);
    glColor3ub(1, 1, 1);
    drawFilledCircle(1211,244,111);



}
void drawLampPost()
{
    glBegin(GL_POLYGON);
    glColor3ub(23, 23, 23);
	glVertex2i(1595, 863+45);
	glVertex2i(1595, 846+45);
	glVertex2i(1588, 838+45);
	glVertex2i(1563, 838+45);
	glVertex2i(1554, 847+45);
	glVertex2i(1554, 863+45);
	glEnd();
	glBegin(GL_POLYGON);
    glVertex2i(1588, 838+45);
	glVertex2i(1588, 745+45);
    glVertex2i(1580, 733+45);
    glVertex2i(1570, 733+45);

    glVertex2i(1563, 745+45);
    glColor3ub(248,248,248);
    glVertex2i(1563, 838+45);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(23, 23, 23);
	glVertex2i(1580, 733+45);
	glVertex2i(1580, 585+45);
    glVertex2i(1570, 585+45);
    glVertex2i(1570, 733+45);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(1547, 590+45);
    glVertex2i(1604, 590+45);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2i(1547, 590+45);
    glVertex2i(1604, 590+45);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(23, 23, 23 );
	glVertex2i(1580, 590+45);
	glVertex2i(1587, 571+45);
    glVertex2i(1562, 571+45);
	glVertex2i(1570, 590+45);

	glEnd();



	glBegin(GL_POLYGON);
    glColor3ub(255,255,102);
	glVertex2i(1587, 571+45);
	glVertex2i(1592, 571+45);
    glVertex2i(1598, 537+45);
	glVertex2i(1552, 537+45);
	glVertex2i(1558, 571+45);

	glEnd();

	glBegin(GL_LINE_STRIP);
    glColor3ub(23, 23, 23);


	glVertex2i(1592, 571+45);
    glVertex2i(1598, 537+45);
	glVertex2i(1552, 537+45);
	glVertex2i(1558, 571+45);
    glVertex2i(1592, 571+45);
	glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);

	glVertex2i(1576, 573+45);
    glVertex2i(1576, 536+45);
    glEnd();

	glBegin(GL_POLYGON);


	glVertex2i(1615, 537+45);
	glVertex2i(1597, 527+45);
    glVertex2i(1575, 508+45);
	glVertex2i(1535, 537+45);
	glEnd();
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(1558, 827+45);
    glVertex2i(1592, 827+45);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(1558, 760+45);
    glVertex2i(1592, 760+45);
    glEnd();





}
void handleKeypress(unsigned char key, int x, int y) {



	switch (key) {


case 'n':
	mode="night";
    	break;
case 's':
	mode="sunrise";
	break;
case 'm':
	mode="morning";
   	break;



glutPostRedisplay();





	}

}
