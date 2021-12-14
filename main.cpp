#include <GL/freeglut_std.h>
#include <cstdlib>
#include<iostream>
#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.1416
using namespace std;

int posCloud[5]={0,400,800,1200,1700};int cloudSpeed[5]={4,20,7,9,11};


int Colors[]={42,46,137,20,27,79};
string mode="night";
int modeTime=0;
void drawQuads(GLfloat x, GLfloat y, GLfloat height,GLfloat width);
void drawSquare(GLfloat x, GLfloat y, GLfloat height);
void curve(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4);
void bridgeCurve(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4);
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius);
void handleKeypress(unsigned char key, int x, int y);
void drawStar(int x,int y);
void cloud();
void drawMoon();
void drawLampPost();
int starX[]={1295,239,400,1479,1461,1264,849,784,369,780,987,1429,464,1706,1062,1611,624,1109,1250,171,52,420,295,901,162,1584,1879,334	,450	,768,1506,621,39		,879	,374	,584	,1432	,1694	,476	,136,250	 ,417,1468	,1300	,436	,550	,698	,1909	,549	,785,32	 ,1240,1808	,583	,125	,1555	,1455	,412	,1538	,1227,770	 ,667,468	,924	,1663	,269	,134	,1842	,1466	,702,783	 ,1737,1445	,921	,317	,627	,202	,317	,854	,177,1494 ,672,1323	,867	,1068	,1398	,1262	,489	,481	,593,1559 ,500,1407	,175	,820	,992	,1128	,1738	,1198	,176,32	 ,1240,1808	,583	,125	,1555	,1455	,412	,1538	,1227,770	 ,667,468	,924	,1663	,269	,134	,1842	,1466	,702,783	 ,1737,1445	,921	,317	,627	,202	,317	,854	,177,1494 ,672,1323	,867	,1068	,1398	,1262	,489	,481	,593,1559 ,500,1407	,175	,820	,992	,1128	,1738	,1198	,176};
int starY[]={257,395,82,358	,56,231	,47,259,151,205,75	,397,185,211,301,335,221,373,287,103,335,193,113,45,399	,292,278	,231	,382	,219,294	,396,275	,100	,317	,90		,269	,164	,153	,372,24	,70	,84		,41		,167	,298	,333	,245	,6		,21,218	,232,58		,169	,16		,218	,372	,294	,246	,241,277	,395,138	,169	,240	,21		,30		,311	,301	,77,21	,388,116	,152	,49		,275	,217	,193	,237	,131,250	,247,207	,333	,63		,362	,50		,27		,222	,265,184	,42	,182	,32		,108	,367	,112	,149	,188	,200,257	,395,82		,358	,56		,231	,47		,259	,151	,205,75	,397,185	,211	,301	,335	,221	,373	,287	,103,335	,193,113	,45		,399	,292	,278	,231	,382	,219,294	,396,275	,100	,317	,90		,269	,164	,153	,372,24	,70	,84		,41		,167	,298	,333	,245	,6		,21,};

void drawStar(){
	for(int i=0;i<150;i++){
		glPushMatrix();
		drawStar(starX[i],starY[i]);
		glPopMatrix();
	}
}

void update(int a)
{

    for(int i=0;i<5;i++)
    {

        if(posCloud[i]>1900)
            posCloud[i]=-100;
        posCloud[i]+=cloudSpeed[i];

    }
	if(modeTime==50){
		modeTime=0;
		if(mode=="night")
			mode="sunrise";
		else
			mode="night";
	}
	else
		modeTime++;
    
    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}
void drawStar(int x,int y) {
  glColor3ub(255,255,255);
  drawFilledCircle(x, y, 1);
  glColor3f(.8, .8, .8);
  drawFilledCircle(x, y, 2);
}



void background(){
	if(mode=="sunrise"){
	Colors[0]=214;
	Colors[1]=107;
	Colors[2]=75;
	Colors[3]=138;
	Colors[4]=74;
	Colors[5]=75;
	}
	else if(mode=="night")
	{
	Colors[0]=42;
	Colors[1]=46;
	Colors[2]=137;
	Colors[3]=20;
	Colors[4]=27;
	Colors[5]=79;
	}

	glBegin(GL_QUADS);
	glColor3ub(Colors[0],Colors[1],Colors[2]);
	glVertex2i(0, 0);
	glColor3ub(Colors[0],Colors[1],Colors[2]);
	glVertex2i(1920, 0);
	glColor3ub(Colors[3],Colors[4],Colors[5]);
	glVertex2i(1920, 885);
	glColor3ub(Colors[3],Colors[4],Colors[5]);
	glVertex2i(0, 885);
	glEnd();
	if(mode=="night"){
			drawMoon();
			drawStar();
	}
	else if(mode=="sunrise"){
			glColor3ub(255, 230, 200);
			drawFilledCircle(1161,594,111);
	}
	}


void tower(){
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

//
//
//
//display function 
//
//
//
void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);

glPointSize(5.0);
glPushMatrix();
//background theme
background();
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
glScalef(1,.6,0);
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
    glColor3ub(241,221,127);
    drawFilledCircle(1472,186,30);
    glColor3ub(251,244,215);
    glColor4ub(241,221,127,0.15);
    drawFilledCircle(1472,186,50);
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



glutPostRedisplay();




	}

}
