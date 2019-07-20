#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
const float DEG2RAD = 3.14159/180;
void display1();
void stars();
void stars1();
void mars(float radius);
void menu(int num);
void createMenu(void);
void drawText(float x, float y, int r, int g, int b, int d, const char *string);
void drawText1(float x, float y, int r, int g, int b, int d, const char *string);
int submenu,value,p,d=0,rocketlaunched=0,bottomreleased=0,middlereleased=0,flag1=0,exitflag=0;//flag1 for stars to flicker
float i,j,t=0,f=0;
void rocket_in_motion1();
void createMenu(void)
{
	submenu=glutCreateMenu(menu);
	glutAddMenuEntry("View",1);
	glutAddMenuEntry("Launch",2);
	glutAddMenuEntry("Exit", 7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void menu(int num)
{
	if(num==7)
	{
		exit(0);
	}
	else
	value=num;
	
}




void semicircle(float radius,float u,float v)//satellite cup
{

	glColor3f(1.0 ,1.0 ,1.0);
	glBegin(GL_POLYGON);
	for (int i=135; i<=315; i++)
	{
	      float degInRad = i*DEG2RAD;
	      glVertex2f(u+cos(degInRad)*radius,v+(sin(degInRad))*radius);//u,v specifies centre of circle
   	}
   	glEnd();
}

void circle(float radius,float u,float v,float r,float g,float b)
{

	glColor3f(r ,g ,b);
	glBegin(GL_POLYGON);
	for (int i=0; i<=360; i++)
	{
	      float degInRad = i*DEG2RAD;
	      glVertex2f(u+cos(degInRad)*radius,v+(sin(degInRad))*radius);//U,V specifies centre of circle
   	}
   	glEnd();
}
void display1()
{
	glClearColor(0, 0,0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	stars();
	drawText(10, 450, 1, 0, 0, d, "PROJECT THEME: ");
	drawText(180, 450, 1, 1, 0, d, "MAKE IN INDIA");

	drawText(10, 400, 1, 0, 0.2, d, "PROJECT TITLE: ");
	drawText(180, 400, 1, 01, 0.2, d, "ROCKET LAUNCH VISUALISATION");

	drawText(50, 320, 1, 1, 0, d, "ARSALAN ANWAR");
	drawText(250, 320, 1, 1, 0, d, "(1BI16CS025)");

	drawText(50, 290, 1, 1, 0, d, "DHANUSH R");
	drawText(250, 290, 1, 1, 0, d, "(1BI16CS043)");

	drawText(25.0, 230.0, 1, 0, 0, d, "UNDER THE GUIDENCE OF");
	drawText(25.0, 200.0, 0, 0, 1, d, "Prof.K N Prashanth Kumar ");

	drawText(25.0, 170.0, 0, 0, 1, d, "Assistant Professor, Dept of CSE");
	drawText(25.0, 140, 0, 0, 1, d, "BIT, Bangalore");

	drawText(170, 80, 1, 0, 0, d, "PRESS '1' TO START");


glFlush();
glutSwapBuffers();

}

void rocket()
{

	//Rocket Definition Starts	
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 1: Payload
		glVertex2f(237.5,140.0);
		glVertex2f(262.5,140.0);
		glVertex2f(262.5,200.0);
		glVertex2f(237.5,200.0);
	glEnd();
	glColor3f(0.0,0.0 ,0.0);
	glBegin(GL_LINES);//payload lines
		glVertex2f(262.5,150);
		glVertex2f(242.5,150);
		glVertex2f(242.5,150);
		glVertex2f(242.5,190);
		glVertex2f(242.5,190);
		glVertex2f(262.5,190);
		
	glEnd();
	
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 2: Middle Part
		glVertex2f(237.5,80.0);
		glVertex2f(262.5,80.0);
		glVertex2f(262.5,140.0);
		glVertex2f(237.5,140.0);
	glEnd();
	//Indian Flag
	glColor3f(1.0,0.6,0.2);
	glBegin(GL_POLYGON);//Saffron
		glVertex2f(242.5,110.0);
		glVertex2f(245.5,110.0);
		glVertex2f(245.5,130.0);
		glVertex2f(242.5,130.0);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//White
		glVertex2f(245.5,110.0);
		glVertex2f(248.5,110.0);
		glVertex2f(248.5,130.0);
		glVertex2f(245.5,130.0);
	glEnd();
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);//Blue Chakra
		glVertex2f(245.5,119.0);
		glVertex2f(248.5,119.0);
		glVertex2f(248.5,121.0);
		glVertex2f(245.5,121.0);
	glEnd();
	glColor3f(0.14,1.0,0.059);
	glBegin(GL_POLYGON);//Green
		glVertex2f(248.5,110.0);
		glVertex2f(251.5,110.0);
		glVertex2f(251.5,130.0);
		glVertex2f(248.5,130.0);
	glEnd();
	//Indian Flag Def Ends
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 3: Bottom Part
		glVertex2f(237.5,20.0);
		glVertex2f(262.5,20.0);
		glVertex2f(262.5,80.0);
		glVertex2f(237.5,80.0);
	glEnd();

	glBegin(GL_POLYGON);//triangle
	glVertex2f(237.5,200);
	glVertex2f(262.5,200);
	glVertex2f(250,240.0);
	glEnd();
	glColor3f(0.0,0.0 ,0.0);
	glBegin(GL_LINES);
		glVertex2f(237.5,80);
		glVertex2f(262.5,80);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(237.5,140);
		glVertex2f(262.5,140);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(237.5,200);
		glVertex2f(262.5,200);
	glEnd();


	glColor3f(0.8,0.80,0.80);
	glBegin(GL_POLYGON);//left side wing
	glVertex2f(227.5,25.0);
	glVertex2f(237.5,25.0);
	glVertex2f(237.5,75.0);
	glVertex2f(227.5,75.0);
	glEnd();


	glBegin(GL_POLYGON);//right side wing
	glVertex2f(262.5,25.0);
	glVertex2f(272.5,25.0);
	glVertex2f(272.5,75.0);
	glVertex2f(262.5,75.0);
	glEnd();

	glBegin(GL_POLYGON);//middle wing
	glVertex2f(237.5+7.5,25.0);
	glVertex2f(262.5-7.5,25.0);
	glVertex2f(262.5-7.5,75.0);
	glVertex2f(237.5+7.5,75.0);
	glEnd();
	
	
	glColor3f(1 ,1 ,0);
	glBegin(GL_POLYGON);//bottom_1_exhaust
	glVertex2f(237.5,20.0);
	glVertex2f(244.5,20.0);
	glVertex2f(241,0.0);
	glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust
	glVertex2f(246.5,20.0);
	glVertex2f(253.5,20.0);
	glVertex2f(249.5,0.0);
	glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust
	glVertex2f(262.5,20.0);
	glVertex2f(255.5,20.0);
	glVertex2f(258.5,0.0);
	glEnd();
	//Rocket Definition Ends


}

void isro()
{
	//ISRO Definition Starts
	glColor3f(0.8,0.8 ,0.8);
	glBegin(GL_POLYGON);//Main Building
		glVertex2f(110.0,0.0);
		glVertex2f(210.0,0.0);
		glVertex2f(210.0,275.0);
		glVertex2f(110.0,275.0);
	glEnd();
	drawText(152,230, 1, 0, 0, 0, "ISRO");
	glColor3f(0.4,0.4 ,0.4);
	glBegin(GL_POLYGON);//Top Holder
		glVertex2f(237,190.0);
		glVertex2f(210.0,190.0);
		glVertex2f(210.0,170.0);
		glVertex2f(237,170.0);
	glEnd();
	glColor3f(0.4,0.4 ,0.4);
	glBegin(GL_POLYGON);//Bottom Holder
		glVertex2f(237,80.0);
		glVertex2f(210.0,80.0);
		glVertex2f(210.0,100.0);
		glVertex2f(237,100.0);
	glEnd();
	glBegin(GL_POLYGON);//ISRO Terrace
		glVertex2f(110,275.5);
		glVertex2f(210.0,275.5);
		glVertex2f(215.0,282.5);
		glVertex2f(105.0,282.5);
	glEnd();

	//Indian Flag
	glColor3f(1.0,0.6,0.2);
	glBegin(GL_POLYGON);//Saffron
		glVertex2f(130,215);
		glVertex2f(135.0,215);
		glVertex2f(135.0,255);
		glVertex2f(130.0,255);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//White
		glVertex2f(135,215);
		glVertex2f(140.0,215);
		glVertex2f(140.0,255);
		glVertex2f(135.0,255);
	glEnd();
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);//Blue Chakra
		glVertex2f(136,237);
		glVertex2f(139.0,237);
		glVertex2f(139.0,233);
		glVertex2f(136.0,233);
	glEnd();
	glColor3f(0.14,1.0,0.059);
	glBegin(GL_POLYGON);//Green
		glVertex2f(140,215);
		glVertex2f(145.0,215);
		glVertex2f(145.0,255);
		glVertex2f(140.0,255);
	glEnd();
	//Indian Flag Def Ends
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//Side Panel
		glVertex2f(200.0,0.0);
		glVertex2f(210.0,0.0);
		glVertex2f(210.0,275.0);
		glVertex2f(200.0,275.0);
	glEnd();
	
	//ISRO Definition Ends
}

void initialbackground()
{
	
	//Background Definition
		glPointSize(2.0);
		glColor3f(0.2,1,0.4);
		glBegin(GL_POLYGON);//green ground
		glVertex2f(0.0,0.0);
		glVertex2f(0.0,250.0);
		glVertex2f(270.0,250.0);
		glVertex2f(500.0,50.0);
		glVertex2f(500.0,0.0);
		glEnd();
		glBegin(GL_POLYGON);//green ground
		glVertex2f(280.0,250.0);
		glVertex2f(500.0,250.0);
		glVertex2f(500.0,60.0);
		glEnd();
		
			glBegin(GL_POLYGON);//road
		glVertex2f(260.0,250.0);
		glVertex2f(290.0,250.0);
		glVertex2f(500.0,70.0);
		glVertex2f(500.0,40.0);
		glEnd();
		glColor3f(0.0,0.0,0.0);


		glColor3f(0.5,0.298039 ,0.196078);
		glBegin(GL_POLYGON);//House Right Part 
			glVertex2f(425.0,250.0);
			glVertex2f(475.0,250.0);
			glVertex2f(475.0,350.0);
			glVertex2f(425.0,350.0);
		glEnd();
		glBegin(GL_POLYGON);//House Left Part 
			glVertex2f(325.0,250.0);
			glVertex2f(375.0,250.0);
			glVertex2f(375.0,350.0);
			glVertex2f(325.0,350.0);
		glEnd();
		glBegin(GL_POLYGON);//House Middle Part 
			glVertex2f(375.0,250.0);
			glVertex2f(425.0,250.0);
			glVertex2f(425.0,275.0);
			glVertex2f(375.0,275.0);
		glEnd();
		glColor3f(0.5,0.128039 ,0.1056);
		glBegin(GL_POLYGON);//Right Roof triangle
			glVertex2f(420,350);
			glVertex2f(480,350);
			glVertex2f(450,365);
		glEnd();
		glBegin(GL_POLYGON);//Left Roof triangle
			glVertex2f(320,350);
			glVertex2f(380,350);
			glVertex2f(350,365);
		glEnd();
		glColor3f(1.0,1.0,0.0);
		//windows RIGHT BUILDING
		glBegin(GL_POLYGON);//Windows A1
			glVertex2f(435,340);
			glVertex2f(445.0,340);
			glVertex2f(445.0,330);
			glVertex2f(435.0,330);
		glEnd();
		glBegin(GL_POLYGON);//Windows B1
			glVertex2f(435,320);
			glVertex2f(445.0,320);
			glVertex2f(445.0,310);
			glVertex2f(435.0,310);
		glEnd();
		glBegin(GL_POLYGON);//Windows C1
			glVertex2f(435,300);
			glVertex2f(445.0,300);
			glVertex2f(445.0,290);
			glVertex2f(435.0,290);
		glEnd();
		glBegin(GL_POLYGON);//Windows A2
			glVertex2f(465,340);
			glVertex2f(455.0,340);
			glVertex2f(455.0,330);
			glVertex2f(465.0,330);
		glEnd();
		glBegin(GL_POLYGON);//Windows B2
			glVertex2f(465,320);
			glVertex2f(455.0,320);
			glVertex2f(455.0,310);
			glVertex2f(465.0,310);
		glEnd();
		glBegin(GL_POLYGON);//Windows C2
			glVertex2f(465,300);
			glVertex2f(455.0,300);
			glVertex2f(455.0,290);
			glVertex2f(465.0,290);
		glEnd();
		//windows LEFT BUILDING
		glBegin(GL_POLYGON);//Windows A1
			glVertex2f(335,340);
			glVertex2f(345.0,340);
			glVertex2f(345.0,330);
			glVertex2f(335.0,330);
		glEnd();
		glBegin(GL_POLYGON);//Windows B1
			glVertex2f(335,320);
			glVertex2f(345.0,320);
			glVertex2f(345.0,310);
			glVertex2f(335.0,310);
		glEnd();
		glBegin(GL_POLYGON);//Windows C1
			glVertex2f(335,300);
			glVertex2f(345.0,300);
			glVertex2f(345.0,290);
			glVertex2f(335.0,290);
		glEnd();
		glBegin(GL_POLYGON);//Windows A2
			glVertex2f(365,340);
			glVertex2f(355.0,340);
			glVertex2f(355.0,330);
			glVertex2f(365.0,330);
		glEnd();
		glBegin(GL_POLYGON);//Windows B2
			glVertex2f(365,320);
			glVertex2f(355.0,320);
			glVertex2f(355.0,310);
			glVertex2f(365.0,310);
		glEnd();
		glBegin(GL_POLYGON);//Windows C2
			glVertex2f(365,300);
			glVertex2f(355.0,300);
			glVertex2f(355.0,290);
			glVertex2f(365.0,290);
		glEnd();
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON);//side satellite triangle
		glVertex2f(26,250);
		glVertex2f(52,250);
		glVertex2f(39,290);
		glEnd();
		semicircle(20.0,50,300);

		glColor3f(0.0,0.0 ,0.0);
		glBegin(GL_LINES);//wires
		glVertex2f(37,313);
		glVertex2f(62,310);
		glVertex2f(63,287);
		glVertex2f(62,310);
		glEnd();
		glColor3f(1.0,1.0,1.0);

		glEnd();
		circle(50,50,425,0.8,0.860705,0.0012);//sun
		circle(47,50,425,0.77007843,0.850549,0.0014);
		circle(44,50,425,0.760686,0.840392,0.0016);
		circle(41,50,425,0.750359,0.830235,0.0018);
		circle(38,50,425,0.7404137,0.82078,0.0020);
		circle(35,50,425,0.7300921,0.810921,0.0022);
		circle(32,50,425,0.720058,0.800764,0.0024);
		circle(29,50,425,0.7104902,0.790607,0.0026);
		circle(26,50,425,0.700745,0.780045,0.0028);
		circle(23,50,425,0.69043,0.770137,0.003);
		circle(20,50,425,0.6802843,0.760137,0.0032);
		circle(17,50,425,0.670434,0.750137,0.0034);
	//Background Definition Ends
}

void rocketmoving()
{
	//Rocket Definition Starts	
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 1: Payload
		glVertex2f(237.5,140.0);
		glVertex2f(262.5,140.0);
		glVertex2f(262.5,200.0);
		glVertex2f(237.5,200.0);
	glEnd();
	glColor3f(0.0,0.0 ,0.0);
	glBegin(GL_LINES);//payload lines
		glVertex2f(262.5,150);
		glVertex2f(242.5,150);
		glVertex2f(242.5,150);
		glVertex2f(242.5,190);
		glVertex2f(242.5,190);
		glVertex2f(262.5,190);
		
	glEnd();
	
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 2: Middle Part
		glVertex2f(237.5,80.0);
		glVertex2f(262.5,80.0);
		glVertex2f(262.5,140.0);
		glVertex2f(237.5,140.0);
	glEnd();
	//Indian Flag
	glColor3f(1.0,0.6,0.2);
	glBegin(GL_POLYGON);//Saffron
		glVertex2f(242.5,110.0);
		glVertex2f(245.5,110.0);
		glVertex2f(245.5,130.0);
		glVertex2f(242.5,130.0);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//White
		glVertex2f(245.5,110.0);
		glVertex2f(248.5,110.0);
		glVertex2f(248.5,130.0);
		glVertex2f(245.5,130.0);
	glEnd();
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);//Blue Chakra
		glVertex2f(245.5,119.0);
		glVertex2f(248.5,119.0);
		glVertex2f(248.5,121.0);
		glVertex2f(245.5,121.0);
	glEnd();
	glColor3f(0.14,1.0,0.059);
	glBegin(GL_POLYGON);//Green
		glVertex2f(248.5,110.0);
		glVertex2f(251.5,110.0);
		glVertex2f(251.5,130.0);
		glVertex2f(248.5,130.0);
	glEnd();
	//Indian Flag Def Ends
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 3: Bottom Part
		glVertex2f(237.5,20.0);
		glVertex2f(262.5,20.0);
		glVertex2f(262.5,80.0);
		glVertex2f(237.5,80.0);
	glEnd();
	glBegin(GL_POLYGON);//triangle
	glVertex2f(237.5,200);
	glVertex2f(262.5,200);
	glVertex2f(250,240.0);
	glEnd();
	glColor3f(0.0,0.0 ,0.0);
	glBegin(GL_LINES);
		glVertex2f(237.5,80);
		glVertex2f(262.5,80);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(237.5,140);
		glVertex2f(262.5,140);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(237.5,200);
		glVertex2f(262.5,200);
	glEnd();

	glColor3f(0.8,0.80,0.80);
	glBegin(GL_POLYGON);//left side wing
	glVertex2f(227.5,25.0);
	glVertex2f(237.5,25.0);
	glVertex2f(237.5,75.0);
	glVertex2f(227.5,75.0);
	glEnd();


	glBegin(GL_POLYGON);//right side wing
	glVertex2f(262.5,25.0);
	glVertex2f(272.5,25.0);
	glVertex2f(272.5,75.0);
	glVertex2f(262.5,75.0);
	glEnd();

	glBegin(GL_POLYGON);//middle wing
	glVertex2f(237.5+7.5,25.0);
	glVertex2f(262.5-7.5,25.0);
	glVertex2f(262.5-7.5,75.0);
	glVertex2f(237.5+7.5,75.0);
	glEnd();
	
	
	glColor3f(1 ,1 ,0);
	glBegin(GL_POLYGON);//bottom_1_exhaust
	glVertex2f(237.5,20.0);
	glVertex2f(244.5,20.0);
	glVertex2f(241,0.0);
	glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust
	glVertex2f(246.5,20.0);
	glVertex2f(253.5,20.0);
	glVertex2f(249.5,0.0);
	glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust
	glVertex2f(262.5,20.0);
	glVertex2f(255.5,20.0);
	glVertex2f(258.5,0.0);
	glEnd();
	//Rocket Definition Ends
	if((p%2)==0)//fumes
		glColor3f(1.0,0.25,0.0);
	 else
		glColor3f(1.0,0.816,0.0);

	glBegin(GL_POLYGON);//outer fume
		glVertex2f(237.5,20);
		glVertex2f(234.16,16.66);
		glVertex2f(230.82,13.32);
		glVertex2f(227.48,9.98);
		glVertex2f(224.14,6.64);
		glVertex2f(220.8,3.3);
		glVertex2f(217.5,0);
		glVertex2f(221.56,-5);
		glVertex2f(225.62,-10);
		glVertex2f(229.68,-15);
		glVertex2f(233.74,-20);
		glVertex2f(237.8,-25);
		glVertex2f(241.86,-30);
		glVertex2f(245.92,-35);
		glVertex2f(250,-40);
		glVertex2f(254.06,-35);
		glVertex2f(258.12,-30);
		glVertex2f(262.18,-25);
		glVertex2f(266.24,-20);
		glVertex2f(270.3,-15);
		glVertex2f(274.36,-10);
		glVertex2f(278.42,-5);
		glVertex2f(282.5,0);
		glVertex2f(278.5,4);
		glVertex2f(274.5,8);
		glVertex2f(270.5,12);
		glVertex2f(266.5,16);
		glVertex2f(262.5,20);//28 points
		glEnd();
	if((p%2)==0)
		glColor3f(1.0,0.816,0.0);
	else
		glColor3f(1.0,0.25,0.0);

	glBegin(GL_POLYGON);//inner fume
		glVertex2f(237.5,20);
		glVertex2f(236.5,17.5);
		glVertex2f(235.5,15);
		glVertex2f(234.5,12.5);
		glVertex2f(233.5,10);
		glVertex2f(232.5,7.5);
		glVertex2f(236,5);
		glVertex2f(239.5,2.5);
		glVertex2f(243,0);
		glVertex2f(246.5,-2.5);
		glVertex2f(250,-5);
		glVertex2f(253.5,-2.5);
		glVertex2f(257,0);
		glVertex2f(260.5,2.5);
		glVertex2f(264,5);
		glVertex2f(267.5,7.5);
		glVertex2f(266.5,10);
		glVertex2f(265.5,12.5);
		glVertex2f(264.5,15);
		glVertex2f(263.5,17.5);
		glVertex2f(262.5,20);//21 points
		glEnd();
	p++;
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
	
}


void rocketspace(int i,int p)
{
	//Rocket Definition Starts	
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 1: Payload
		glVertex2f(237.5,140.0+i);
		glVertex2f(262.5,140.0+i);
		glVertex2f(262.5,200.0+i);
		glVertex2f(237.5,200.0+i);
	glEnd();
	glColor3f(0.0,0.0 ,0.0);
	glBegin(GL_LINES);//payload lines
		glVertex2f(262.5,150+i);
		glVertex2f(242.5,150+i);
		glVertex2f(242.5,150+i);
		glVertex2f(242.5,190+i);
		glVertex2f(242.5,190+i);
		glVertex2f(262.5,190+i);
		
	glEnd();
	
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 2: Middle Part
		glVertex2f(237.5,80.0+i);
		glVertex2f(262.5,80.0+i);
		glVertex2f(262.5,140.0+i);
		glVertex2f(237.5,140.0+i);
	glEnd();
	//Indian Flag
	glColor3f(1.0,0.6,0.2);
	glBegin(GL_POLYGON);//Saffron
		glVertex2f(242.5,110.0+i);
		glVertex2f(245.5,110.0+i);
		glVertex2f(245.5,130.0+i);
		glVertex2f(242.5,130.0+i);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//White
		glVertex2f(245.5,110.0+i);
		glVertex2f(248.5,110.0+i);
		glVertex2f(248.5,130.0+i);
		glVertex2f(245.5,130.0+i);
	glEnd();
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);//Blue Chakra
		glVertex2f(245.5,119.0+i);
		glVertex2f(248.5,119.0+i);
		glVertex2f(248.5,121.0+i);
		glVertex2f(245.5,121.0+i);
	glEnd();
	glColor3f(0.14,1.0,0.059);
	glBegin(GL_POLYGON);//Green
		glVertex2f(248.5,110.0+i);
		glVertex2f(251.5,110.0+i);
		glVertex2f(251.5,130.0+i);
		glVertex2f(248.5,130.0+i);
	glEnd();
	//Indian Flag Def Ends
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 3: Bottom Part
		glVertex2f(237.5,20.0+i);
		glVertex2f(262.5,20.0+i);
		glVertex2f(262.5,80.0+i);
		glVertex2f(237.5,80.0+i);
	glEnd();

	glBegin(GL_POLYGON);//triangle
	glVertex2f(237.5,200+i);
	glVertex2f(262.5,200+i);
	glVertex2f(250,240.0+i);
	glEnd();
	glColor3f(0.0,0.0 ,0.0);
	glBegin(GL_LINES);
		glVertex2f(237.5,80+i);
		glVertex2f(262.5,80+i);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(237.5,140+i);
		glVertex2f(262.5,140+i);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(237.5,200+i);
		glVertex2f(262.5,200+i);
	glEnd();


	glColor3f(0.8,0.80,0.80);
	glBegin(GL_POLYGON);//left side wing
	glVertex2f(227.5,25.0+i);
	glVertex2f(237.5,25.0+i);
	glVertex2f(237.5,75.0+i);
	glVertex2f(227.5,75.0+i);
	glEnd();


	glBegin(GL_POLYGON);//right side wing
	glVertex2f(262.5,25.0+i);
	glVertex2f(272.5,25.0+i);
	glVertex2f(272.5,75.0+i);
	glVertex2f(262.5,75.0+i);
	glEnd();

	glBegin(GL_POLYGON);//middle wing
	glVertex2f(237.5+7.5,25.0+i);
	glVertex2f(262.5-7.5,25.0+i);
	glVertex2f(262.5-7.5,75.0+i);
	glVertex2f(237.5+7.5,75.0+i);
	glEnd();
	
	
	glColor3f(1 ,1 ,0);
	glBegin(GL_POLYGON);//bottom_1_exhaust
	glVertex2f(237.5,20.0+i);
	glVertex2f(244.5,20.0+i);
	glVertex2f(241,0.0+i);
	glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust
	glVertex2f(246.5,20.0+i);
	glVertex2f(253.5,20.0+i);
	glVertex2f(249.5,0.0+i);
	glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust
	glVertex2f(262.5,20.0+i);
	glVertex2f(255.5,20.0+i);
	glVertex2f(258.5,0.0+i);
	glEnd();
	//Rocket Definition Ends
	if((p%2)==0)
		glColor3f(1.0,0.25,0.0);
	else
		 glColor3f(1.0,0.816,0.0);
	glBegin(GL_POLYGON);//outer fume
		glVertex2f(237.5,20+i);
		glVertex2f(234.16,16.66+i);
		glVertex2f(230.82,13.32+i);
		glVertex2f(227.48,9.98+i);
		glVertex2f(224.14,6.64+i);
		glVertex2f(220.8,3.3+i);
		glVertex2f(217.5,0+i);
		glVertex2f(221.56,-5+i);
		glVertex2f(225.62,-10+i);
		glVertex2f(229.68,-15+i);
		glVertex2f(233.74,-20+i);
		glVertex2f(237.8,-25+i);
		glVertex2f(241.86,-30+i);
		glVertex2f(245.92,-35+i);
		glVertex2f(250,-40+i);
		glVertex2f(254.06,-35+i);
		glVertex2f(258.12,-30+i);
		glVertex2f(262.18,-25+i);
		glVertex2f(266.24,-20+i);
		glVertex2f(270.3,-15+i);
		glVertex2f(274.36,-10+i);
		glVertex2f(278.42,-5+i);
		glVertex2f(282.5,0+i);
		glVertex2f(278.5,4+i);
		glVertex2f(274.5,8+i);
		glVertex2f(270.5,12+i);
		glVertex2f(266.5,16+i);
		glVertex2f(262.5,20+i);//28 points
		glEnd();

		if((p%2)==0)
			glColor3f(1.0,0.816,0.0);
		else
			glColor3f(1.0,0.25,0.0);

		glBegin(GL_POLYGON);//inner fume
		glVertex2f(237.5,20+i);
		glVertex2f(236.5,17.5+i);
		glVertex2f(235.5,15+i);
		glVertex2f(234.5,12.5+i);
		glVertex2f(233.5,10+i);
		glVertex2f(232.5,7.5+i);
		glVertex2f(236,5+i);
		glVertex2f(239.5,2.5+i);
		glVertex2f(243,0+i);
		glVertex2f(246.5,-2.5+i);
		glVertex2f(250,-5+i);
		glVertex2f(253.5,-2.5+i);
		glVertex2f(257,0+i);
		glVertex2f(260.5,2.5+i);
		glVertex2f(264,5+i);
		glVertex2f(267.5,7.5+i);
		glVertex2f(266.5,10+i);
		glVertex2f(265.5,12.5+i);
		glVertex2f(264.5,15+i);
		glVertex2f(263.5,17.5+i);
		glVertex2f(262.5,20+i);//21 points

		glEnd();
}


void rocketBottomGone(int i,int p)
{
	//Rocket Definition Starts	
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 1: Payload
		glVertex2f(237.5,140.0+i);
		glVertex2f(262.5,140.0+i);
		glVertex2f(262.5,200.0+i);
		glVertex2f(237.5,200.0+i);
	glEnd();
	glColor3f(0.0,0.0 ,0.0);
	glBegin(GL_LINES);//payload lines
		glVertex2f(262.5,150+i);
		glVertex2f(242.5,150+i);
		glVertex2f(242.5,150+i);
		glVertex2f(242.5,190+i);
		glVertex2f(242.5,190+i);
		glVertex2f(262.5,190+i);
		
	glEnd();
	
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 2: Middle Part
		glVertex2f(237.5,80.0+i);
		glVertex2f(262.5,80.0+i);
		glVertex2f(262.5,140.0+i);
		glVertex2f(237.5,140.0+i);
	glEnd();
	//Indian Flag
	glColor3f(1.0,0.6,0.2);
	glBegin(GL_POLYGON);//Saffron
		glVertex2f(242.5,110.0+i);
		glVertex2f(245.5,110.0+i);
		glVertex2f(245.5,130.0+i);
		glVertex2f(242.5,130.0+i);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//White
		glVertex2f(245.5,110.0+i);
		glVertex2f(248.5,110.0+i);
		glVertex2f(248.5,130.0+i);
		glVertex2f(245.5,130.0+i);
	glEnd();
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);//Blue Chakra
		glVertex2f(245.5,119.0+i);
		glVertex2f(248.5,119.0+i);
		glVertex2f(248.5,121.0+i);
		glVertex2f(245.5,121.0+i);
	glEnd();
	glColor3f(0.14,1.0,0.059);
	glBegin(GL_POLYGON);//Green
		glVertex2f(248.5,110.0+i);
		glVertex2f(251.5,110.0+i);
		glVertex2f(251.5,130.0+i);
		glVertex2f(248.5,130.0+i);
	glEnd();
	//Indian Flag Def Ends
	
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//triangle
	glVertex2f(237.5,200+i);
	glVertex2f(262.5,200+i);
	glVertex2f(250,240.0+i);
	glEnd();
	glColor3f(0.0,0.0 ,0.0);
	glBegin(GL_LINES);
		glVertex2f(237.5,80+i);
		glVertex2f(262.5,80+i);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(237.5,140+i);
		glVertex2f(262.5,140+i);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(237.5,200+i);
		glVertex2f(262.5,200+i);
	glEnd();
	/*glColor3f(1 ,1 ,0);
	glBegin(GL_POLYGON);//bottom_1_exhaust
	glVertex2f(237.5,80.0+i);
	glVertex2f(244.5,80.0+i);
	glVertex2f(241,60.0+i);
	glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust
	glVertex2f(246.5,80.0+i);
	glVertex2f(253.5,80.0+i);
	glVertex2f(249.5,60.0+i);
	glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust
	glVertex2f(262.5,80.0+i);
	glVertex2f(255.5,80.0+i);
	glVertex2f(258.5,60.0+i);
	glEnd();*/
	//Rocket Definition Ends
	if((p%2)==0)
		glColor3f(1.0,0.25,0.0);
	else
		 glColor3f(1.0,0.816,0.0);
	glBegin(GL_POLYGON);//outer fume
		glVertex2f(237.5,60+20+i);
		glVertex2f(234.16,60+16.66+i);
		glVertex2f(230.82,60+13.32+i);
		glVertex2f(227.48,60+9.98+i);
		glVertex2f(224.14,60+6.64+i);
		glVertex2f(220.8,60+3.3+i);
		glVertex2f(217.5,60+0+i);
		glVertex2f(221.56,60-5+i);
		glVertex2f(225.62,60-10+i);
		glVertex2f(229.68,60+-15+i);
		glVertex2f(233.74,60+-20+i);
		glVertex2f(237.8,60+-25+i);
		glVertex2f(241.86,60+-30+i);
		glVertex2f(245.92,60+-35+i);
		glVertex2f(250,60-40+i);
		glVertex2f(254.06,60+-35+i);
		glVertex2f(258.12,60+-30+i);
		glVertex2f(262.18,60+-25+i);
		glVertex2f(266.24,60+-20+i);
		glVertex2f(270.3,60+-15+i);
		glVertex2f(274.36,60-10+i);
		glVertex2f(278.42,60+-5+i);
		glVertex2f(282.5,60+0+i);
		glVertex2f(278.5,60+4+i);
		glVertex2f(274.5,60+8+i);
		glVertex2f(270.5,60+12+i);
		glVertex2f(266.5,60+16+i);
		glVertex2f(262.5,60+20+i);//28 points
		glEnd();

		if((p%2)==0)
			glColor3f(1.0,0.816,0.0);
		else
			glColor3f(1.0,0.25,0.0);

		glBegin(GL_POLYGON);//inner fume
		glVertex2f(237.5,60+20+i);
		glVertex2f(236.5,60+17.5+i);
		glVertex2f(235.5,60+15+i);
		glVertex2f(234.5,60+12.5+i);
		glVertex2f(233.5,60+10+i);
		glVertex2f(232.5,60+7.5+i);
		glVertex2f(236,60+5+i);
		glVertex2f(239.5,60+2.5+i);
		glVertex2f(243,60+0+i);
		glVertex2f(246.5,60-2.5+i);
		glVertex2f(250,60-5+i);
		glVertex2f(253.5,60-2.5+i);
		glVertex2f(257,60+0+i);
		glVertex2f(260.5,60+2.5+i);
		glVertex2f(264,60+5+i);
		glVertex2f(267.5,60+7.5+i);
		glVertex2f(266.5,60+10+i);
		glVertex2f(265.5,60+12.5+i);
		glVertex2f(264.5,60+15+i);
		glVertex2f(263.5,60+17.5+i);
		glVertex2f(262.5,60+20+i);//21 points

		glEnd();
}	

void rocketBottom(int i)
{
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 3: Bottom Part
		glVertex2f(237.5,260.0-i-80);
		glVertex2f(262.5,260.0-i-80);
		glVertex2f(262.5,320.0-i-80);
		glVertex2f(237.5,320.0-i-80);
	glEnd();
	glColor3f(0.8,0.80,0.80);
	glBegin(GL_POLYGON);//left side wing
	glVertex2f(227.5,265.0-i-80);
	glVertex2f(237.5,265.0-i-80);
	glVertex2f(237.5,315.0-i-80);
	glVertex2f(227.5,315.0-i-80);
	glEnd();


	glBegin(GL_POLYGON);//right side wing
	glVertex2f(262.5,265.0-i-80);
	glVertex2f(272.5,265.0-i-80);
	glVertex2f(272.5,315.0-i-80);
	glVertex2f(262.5,315.0-i-80);
	glEnd();

	glBegin(GL_POLYGON);//middle wing
	glVertex2f(237.5+7.5,265.0-i-80);
	glVertex2f(262.5-7.5,265.0-i-80);
	glVertex2f(262.5-7.5,315.0-i-80);
	glVertex2f(237.5+7.5,315.0-i-80);
	glEnd();
}

void rocketMiddleGone(int i,int p)
{
	//Rocket Definition Starts	
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 1: Payload
		glVertex2f(237.5,140.0+i);
		glVertex2f(262.5,140.0+i);
		glVertex2f(262.5,200.0+i);
		glVertex2f(237.5,200.0+i);
	glEnd();
	glColor3f(0.0,0.0 ,0.0);
	glBegin(GL_LINES);//payload lines
		glVertex2f(262.5,150+i);
		glVertex2f(242.5,150+i);
		glVertex2f(242.5,150+i);
		glVertex2f(242.5,190+i);
		glVertex2f(242.5,190+i);
		glVertex2f(262.5,190+i);
		
	glEnd();
	
	
	
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//triangle
	glVertex2f(237.5,200+i);
	glVertex2f(262.5,200+i);
	glVertex2f(250,240.0+i);
	glEnd();
	glColor3f(0.0,0.0 ,0.0);
	glBegin(GL_LINES);
		glVertex2f(237.5,80+i);
		glVertex2f(262.5,80+i);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(237.5,140+i);
		glVertex2f(262.5,140+i);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(237.5,200+i);
		glVertex2f(262.5,200+i);
	glEnd();
	//Rocket Definition Ends
	if((p%2)==0)
		glColor3f(1.0,0.25,0.0);
	else
		 glColor3f(1.0,0.816,0.0);
	glBegin(GL_POLYGON);//outer fume
		glVertex2f(237.5,120+20+i);
		glVertex2f(234.16,120+16.66+i);
		glVertex2f(230.82,120+13.32+i);
		glVertex2f(227.48,120+9.98+i);
		glVertex2f(224.14,120+6.64+i);
		glVertex2f(220.8,120+3.3+i);
		glVertex2f(217.5,120+0+i);
		glVertex2f(221.56,120-5+i);
		glVertex2f(225.62,120-10+i);
		glVertex2f(229.68,120-15+i);
		glVertex2f(233.74,120-20+i);
		glVertex2f(237.8,120-25+i);
		glVertex2f(241.86,120-30+i);
		glVertex2f(245.92,120+-35+i);
		glVertex2f(250,120-40+i);
		glVertex2f(254.06,120-35+i);
		glVertex2f(258.12,120-30+i);
		glVertex2f(262.18,120-25+i);
		glVertex2f(266.24,120-20+i);
		glVertex2f(270.3,120-15+i);
		glVertex2f(274.36,120-10+i);
		glVertex2f(278.42,120-5+i);
		glVertex2f(282.5,120+0+i);
		glVertex2f(278.5,120+4+i);
		glVertex2f(274.5,120+8+i);
		glVertex2f(270.5,120+12+i);
		glVertex2f(266.5,120+16+i);
		glVertex2f(262.5,120+20+i);//28 points
		glEnd();

		if((p%2)==0)
			glColor3f(1.0,0.816,0.0);
		else
			glColor3f(1.0,0.25,0.0);

		glBegin(GL_POLYGON);//inner fume
		glVertex2f(237.5,120+20+i);
		glVertex2f(236.5,120+17.5+i);
		glVertex2f(235.5,120+15+i);
		glVertex2f(234.5,120+12.5+i);
		glVertex2f(233.5,120+10+i);
		glVertex2f(232.5,120+7.5+i);
		glVertex2f(236,120+5+i);
		glVertex2f(239.5,120+2.5+i);
		glVertex2f(243,120+0+i);
		glVertex2f(246.5,120-2.5+i);
		glVertex2f(250,120-5+i);
		glVertex2f(253.5,120-2.5+i);
		glVertex2f(257,120+0+i);
		glVertex2f(260.5,120+2.5+i);
		glVertex2f(264,120+5+i);
		glVertex2f(267.5,120+7.5+i);
		glVertex2f(266.5,120+10+i);
		glVertex2f(265.5,120+12.5+i);
		glVertex2f(264.5,120+15+i);
		glVertex2f(263.5,120+17.5+i);
		glVertex2f(262.5,120+20+i);//21 points

		glEnd();
}	

void rocketMiddle(int i)
{
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 2: Middle Part
		glVertex2f(237.5,240.0-i);
		glVertex2f(262.5,240.0-i);
		glVertex2f(262.5,300.0-i);
		glVertex2f(237.5,300.0-i);
	glEnd();
	//Indian Flag
	glColor3f(1.0,0.6,0.2);
	glBegin(GL_POLYGON);//Saffron
		glVertex2f(242.5,110.0+160-i);
		glVertex2f(245.5,110.0+160-i);
		glVertex2f(245.5,130.0+160-i);
		glVertex2f(242.5,130.0+160-i);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//White
		glVertex2f(245.5,110.0+160-i);
		glVertex2f(248.5,110.0+160-i);
		glVertex2f(248.5,130.0+160-i);
		glVertex2f(245.5,130.0+160-i);
	glEnd();
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);//Blue Chakra
		glVertex2f(245.5,119.0+160-i);
		glVertex2f(248.5,119.0+160-i);
		glVertex2f(248.5,121.0+160-i);
		glVertex2f(245.5,121.0+160-i);
	glEnd();
	glColor3f(0.14,1.0,0.059);
	glBegin(GL_POLYGON);//Green
		glVertex2f(248.5,110.0+160-i);
		glVertex2f(251.5,110.0+160-i);
		glVertex2f(251.5,130.0+160-i);
		glVertex2f(248.5,130.0+160-i);
	glEnd();
	//Indian Flag Def Ends
}
void payloadHold()
{
	//Rocket Top part Definition Starts	
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 1: Payload
		glVertex2f(237.5,140.0+200);
		glVertex2f(262.5,140.0+200);
		glVertex2f(262.5,200.0+200);
		glVertex2f(237.5,200.0+200);
	glEnd();
	glColor3f(0.0,0.0 ,0.0);
	glBegin(GL_LINES);//payload lines
		glVertex2f(262.5,150+200);
		glVertex2f(242.5,150+200);
		glVertex2f(242.5,150+200);
		glVertex2f(242.5,190+200);
		glVertex2f(242.5,190+200);
		glVertex2f(262.5,190+200);
	glEnd();
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//triangle
	glVertex2f(237.5,200+200);
	glVertex2f(262.5,200+200);
	glVertex2f(250,240.0+200);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(237.5,200+200);
		glVertex2f(262.5,200+200);
	glEnd();
	glColor3f(1 ,1 ,0);
	glBegin(GL_POLYGON);//bottom_1_exhaust
	glVertex2f(237.5,140.0+200);
	glVertex2f(244.5,140.0+200);
	glVertex2f(241,120.0+200);
	glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust
	glVertex2f(246.5,140.0+200);
	glVertex2f(253.5,140.0+200);
	glVertex2f(249.5,120.0+200);
	glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust
	glVertex2f(262.5,140.0+200);
	glVertex2f(255.5,140.0+200);
	glVertex2f(258.5,120.0+200);
	glEnd();	
}
void payloadRemoveCap(int i)
{
	//Rocket Top part with removed cap Definition Starts	
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 1: Payload
		glVertex2f(237.5,140.0+200);
		glVertex2f(262.5,140.0+200);
		glVertex2f(262.5,200.0+200);
		glVertex2f(237.5,200.0+200);
	glEnd();
	glColor3f(0.0,0.0 ,0.0);
	glBegin(GL_POLYGON);//payload lines
		glVertex2f(262.5,150+200);
		glVertex2f(242.5,150+200);
		glVertex2f(242.5,150+200);
		glVertex2f(242.5,190+200);
		glVertex2f(242.5,190+200);
		glVertex2f(262.5,190+200);
	glEnd();
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//payload cap
		glVertex2f(262.5+i,150+200);
		glVertex2f(242.5+i,150+200);
		glVertex2f(242.5+i,150+200);
		glVertex2f(242.5+i,190+200);
		glVertex2f(242.5+i,190+200);
		glVertex2f(262.5+i,190+200);
	glEnd();
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//triangle
	glVertex2f(237.5,200+200);
	glVertex2f(262.5,200+200);
	glVertex2f(250,240.0+200);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(237.5,200+200);
		glVertex2f(262.5,200+200);
	glEnd();
	glColor3f(1 ,1 ,0);
	glBegin(GL_POLYGON);//bottom_1_exhaust
	glVertex2f(237.5,140.0+200);
	glVertex2f(244.5,140.0+200);
	glVertex2f(241,120.0+200);
	glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust
	glVertex2f(246.5,140.0+200);
	glVertex2f(253.5,140.0+200);
	glVertex2f(249.5,120.0+200);
	glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust
	glVertex2f(262.5,140.0+200);
	glVertex2f(255.5,140.0+200);
	glVertex2f(258.5,120.0+200);
	glEnd();	
}
void payloadCapRemoved()
{
	//Rocket with cap removed so that sat comes out
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 1: Payload
		glVertex2f(237.5,140.0+200);
		glVertex2f(262.5,140.0+200);
		glVertex2f(262.5,200.0+200);
		glVertex2f(237.5,200.0+200);
	glEnd();
	glColor3f(0.0,0.0 ,0.0);
	glBegin(GL_POLYGON);//payload lines
		glVertex2f(262.5,150+200);
		glVertex2f(242.5,150+200);
		glVertex2f(242.5,150+200);
		glVertex2f(242.5,190+200);
		glVertex2f(242.5,190+200);
		glVertex2f(262.5,190+200);
	glEnd();
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//payload lines
		glVertex2f(262.5+20,150+200);
		glVertex2f(242.5+20,150+200);
		glVertex2f(242.5+20,150+200);
		glVertex2f(242.5+20,190+200);
		glVertex2f(242.5+20,190+200);
		glVertex2f(262.5+20,190+200);
	glEnd();
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//triangle
	glVertex2f(237.5,200+200);
	glVertex2f(262.5,200+200);
	glVertex2f(250,240.0+200);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(237.5,200+200);
		glVertex2f(262.5,200+200);
	glEnd();
	glColor3f(1 ,1 ,0);
	glBegin(GL_POLYGON);//bottom_1_exhaust
	glVertex2f(237.5,140.0+200);
	glVertex2f(244.5,140.0+200);
	glVertex2f(241,120.0+200);
	glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust
	glVertex2f(246.5,140.0+200);
	glVertex2f(253.5,140.0+200);
	glVertex2f(249.5,120.0+200);
	glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust
	glVertex2f(262.5,140.0+200);
	glVertex2f(255.5,140.0+200);
	glVertex2f(258.5,120.0+200);
	glEnd();	
}
void moveSatellite(int i)
{	
	//satellite hexagon definition
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(242.5+i,365);
		glVertex2f(242.5+i,375);
		glVertex2f(252.5+i,385);
		glVertex2f(267.5+i,385);
		glVertex2f(277.5+i,375);
		glVertex2f(277.5+i,365);
		glVertex2f(267.5+i,355);
		glVertex2f(252.5+i,355);
	glEnd();
}
void holdSatellite(int i)
{
	//move rocket down left cross and satellite down
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 1: Payload
		glVertex2f(237.5-i,140.0+200-i);
		glVertex2f(262.5-i,140.0+200-i);
		glVertex2f(262.5-i,200.0+200-i);
		glVertex2f(237.5-i,200.0+200-i);
	glEnd();
	glColor3f(0.0,0.0 ,0.0);
	glBegin(GL_POLYGON);//payload lines
		glVertex2f(262.5-i,150+200-i);
		glVertex2f(242.5-i,150+200-i);
		glVertex2f(242.5-i,150+200-i);
		glVertex2f(242.5-i,190+200-i);
		glVertex2f(242.5-i,190+200-i);
		glVertex2f(262.5-i,190+200-i);
	glEnd();
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//payload lines
		glVertex2f(262.5+20-i,150+200-i);
		glVertex2f(242.5+20-i,150+200-i);
		glVertex2f(242.5+20-i,150+200-i);
		glVertex2f(242.5+20-i,190+200-i);
		glVertex2f(242.5+20-i,190+200-i);
		glVertex2f(262.5+20-i,190+200-i);
	glEnd();
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//triangle
	glVertex2f(237.5-i,200+200-i);
	glVertex2f(262.5-i,200+200-i);
	glVertex2f(250-i,240.0+200-i);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(237.5-i,200+200-i);
		glVertex2f(262.5-i,200+200-i);
	glEnd();
	glColor3f(1 ,1 ,0);
	glBegin(GL_POLYGON);//bottom_1_exhaust
	glVertex2f(237.5-i,140.0+200-i);
	glVertex2f(244.5-i,140.0+200-i);
	glVertex2f(241-i,120.0+200-i);
	glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust
	glVertex2f(246.5-i,140.0+200-i);
	glVertex2f(253.5-i,140.0+200-i);
	glVertex2f(249.5-i,120.0+200-i);
	glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust
	glVertex2f(262.5-i,140.0+200-i);
	glVertex2f(255.5-i,140.0+200-i);
	glVertex2f(258.5-i,120.0+200-i);
	glEnd();
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(242.5+100,365-i);
		glVertex2f(242.5+100,375-i);
		glVertex2f(252.5+100,385-i);
		glVertex2f(267.5+100,385-i);
		glVertex2f(277.5+100,375-i);
		glVertex2f(277.5+100,365-i);
		glVertex2f(267.5+100,355-i);
		glVertex2f(252.5+100,355-i);
	glEnd();
}
void solar_panel()
{
	//Rocket Definition Starts	
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 1: Payload
		glVertex2f(237.5-100,140.0+200-100);
		glVertex2f(262.5-100,140.0+200-100);
		glVertex2f(262.5-100,200.0+200-100);
		glVertex2f(237.5-100,200.0+200-100);
	glEnd();
	glColor3f(0.0,0.0 ,0.0);
	glBegin(GL_POLYGON);//payload lines
		glVertex2f(262.5-100,150+200-100);
		glVertex2f(242.5-100,150+200-100);
		glVertex2f(242.5-100,190+200-100);
		glVertex2f(242.5-100,190+200-100);
		glVertex2f(262.5-100,190+200-100);
	glEnd();
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//payload lines
		glVertex2f(262.5+20-100,150+200-100);
		glVertex2f(242.5+20-100,150+200-100);
		glVertex2f(242.5+20-100,190+200-100);
		glVertex2f(242.5+20-100,190+200-100);
		glVertex2f(262.5+20-100,190+200-100);
	glEnd();
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//triangle
	glVertex2f(237.5-100,200+200-100);
	glVertex2f(262.5-100,200+200-100);
	glVertex2f(250-100,240.0+200-100);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(237.5-100,200+200-100);
		glVertex2f(262.5-100,200+200-100);
	glEnd();
	glColor3f(1 ,1 ,0);
	glBegin(GL_POLYGON);//bottom_1_exhaust
	glVertex2f(237.5-100,140.0+200-100);
	glVertex2f(244.5-100,140.0+200-100);
	glVertex2f(241-100,120.0+200-100);
	glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust
	glVertex2f(246.5-100,140.0+200-100);
	glVertex2f(253.5-100,140.0+200-100);
	glVertex2f(249.5-100,120.0+200-100);
	glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust
	glVertex2f(262.5-100,140.0+200-100);
	glVertex2f(255.5-100,140.0+200-100);
	glVertex2f(258.5-100,120.0+200-100);
	glEnd();
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);//sattelite
		glVertex2f(342.5,365-100);
		glVertex2f(342.5,375-100);
		glVertex2f(352.5,385-100);
		glVertex2f(367.5,385-100);
		glVertex2f(377.5,375-100);
		glVertex2f(377.5,365-100);
		glVertex2f(367.5,355-100);
		glVertex2f(352.5,355-100);
	glEnd();
	glColor3f(1.0,1.0,1.0);//left holder
	glBegin(GL_POLYGON);
		glVertex2f(342.5,268);
		glVertex2f(332.5,268);
		glVertex2f(332.5,272);
		glVertex2f(342.5,272);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//right holder
		glVertex2f(377.5,268);
		glVertex2f(387.5,268);
		glVertex2f(387.5,272);
		glVertex2f(377.5,272);
	glEnd();
	
		
}

void panels(int i)
{
	
		glColor3f(1.0,1.0,0.0);
		glBegin(GL_POLYGON);//left panel
			glVertex2f(282.5,260);
			glVertex2f(282.5,280);
			glVertex2f(332.5,280);
			glVertex2f(332.5,260);
		glEnd();
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_LINES);//panel left horizontal lines
			glVertex2f(282.5,265);
			glVertex2f(332.5,265);
			glVertex2f(282.5,270);
			glVertex2f(332.5,270);
			glVertex2f(282.5,275);
			glVertex2f(332.5,275);
		glEnd();
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_LINES);//panel left vertical lines
			glVertex2f(282.5,260);
			glVertex2f(282.5,280);
			glVertex2f(292.5,260);
			glVertex2f(292.5,280);
			glVertex2f(302.5,260);
			glVertex2f(302.5,280);
			glVertex2f(312.5,260);
			glVertex2f(312.5,280);
			glVertex2f(322.5,260);
			glVertex2f(322.5,280);
			glVertex2f(332.5,260);
			glVertex2f(332.5,280);
		glEnd();
		
			glColor3f(1.0,1.0,0.0);
		glBegin(GL_POLYGON);//right panel
			glVertex2f(387.5,260);
			glVertex2f(387.5,280);
			glVertex2f(437.5,280);
			glVertex2f(437.5,260);
		glEnd();
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_LINES);//panel right horizontal lines
			glVertex2f(387.5,265);
			glVertex2f(437.5,265);
			glVertex2f(387.5,270);
			glVertex2f(437.5,270);
			glVertex2f(387.5,275);
			glVertex2f(437.5,275);
		glEnd();
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_LINES);//panel right vertical lines
			glVertex2f(387.5,260);
			glVertex2f(387.5,280);
			glVertex2f(397.5,260);
			glVertex2f(397.5,280);
			glVertex2f(407.5,260);
			glVertex2f(407.5,280);
			glVertex2f(417.5,260);
			glVertex2f(417.5,280);
			glVertex2f(427.5,260);
			glVertex2f(427.5,280);
			glVertex2f(437.5,260);
			glVertex2f(437.5,280);
		glEnd();
	
}
void panels1(int i)
{
	//Orbit frame: Panels set to extreme left
		glColor3f(1.0,1.0,0.0);
		glBegin(GL_POLYGON);//left panel
			glVertex2f(282.5-350,260);
			glVertex2f(282.5-350,280);
			glVertex2f(332.5-350,280);
			glVertex2f(332.5-350,260);
		glEnd();
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_LINES);//panel left horizontal lines
			glVertex2f(282.5-350,265);
			glVertex2f(332.5-350,265);
			glVertex2f(282.5-350,270);
			glVertex2f(332.5-350,270);
			glVertex2f(282.5-350,275);
			glVertex2f(332.5-350,275);
		glEnd();
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_LINES);//panel left vertical lines
			glVertex2f(282.5-350,260);
			glVertex2f(282.5-350,280);
			glVertex2f(292.5-350,260);
			glVertex2f(292.5-350,280);
			glVertex2f(302.5-350,260);
			glVertex2f(302.5-350,280);
			glVertex2f(312.5-350,260);
			glVertex2f(312.5-350,280);
			glVertex2f(322.5-350,260);
			glVertex2f(322.5-350,280);
			glVertex2f(332.5-350,260);
			glVertex2f(332.5-350,280);
		glEnd();
		
			glColor3f(1.0,1.0,0.0);
		glBegin(GL_POLYGON);//right panel
			glVertex2f(387.5-350,260);
			glVertex2f(387.5-350,280);
			glVertex2f(437.5-350,280);
			glVertex2f(437.5-350,260);
		glEnd();
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_LINES);//panel right horizontal lines
			glVertex2f(387.5-350,265);
			glVertex2f(437.5-350,265);
			glVertex2f(387.5-350,270);
			glVertex2f(437.5-350,270);
			glVertex2f(387.5-350,275);
			glVertex2f(437.5-350,275);
		glEnd();
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_LINES);//panel right vertical lines
			glVertex2f(387.5-350,260);
			glVertex2f(387.5-350,280);
			glVertex2f(397.5-350,260);
			glVertex2f(397.5-350,280);
			glVertex2f(407.5-350,260);
			glVertex2f(407.5-350,280);
			glVertex2f(417.5-350,260);
			glVertex2f(417.5-350,280);
			glVertex2f(427.5-350,260);
			glVertex2f(427.5-350,280);
			glVertex2f(437.5-350,260);
			glVertex2f(437.5-350,280);
		glEnd();
	
}
void solar_panel1()
{//sat to extreme left in orbit frame
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);//sattelite
		glVertex2f(342.5,365-100);
		glVertex2f(342.5,375-100);
		glVertex2f(352.5,385-100);
		glVertex2f(367.5,385-100);
		glVertex2f(377.5,375-100);
		glVertex2f(377.5,365-100);
		glVertex2f(367.5,355-100);
		glVertex2f(352.5,355-100);
	glEnd();
	glColor3f(1.0,1.0,1.0);//left holder
	glBegin(GL_POLYGON);
		glVertex2f(342.5,268);
		glVertex2f(332.5,268);
		glVertex2f(332.5,272);
		glVertex2f(342.5,272);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//right holder
		glVertex2f(377.5,268);
		glVertex2f(387.5,268);
		glVertex2f(387.5,272);
		glVertex2f(377.5,272);
	glEnd();
	panels(1);
}
void solar_panel11()
{//complete satellite for scaling and translation
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);//sattelite
		glVertex2f(342.5-350,365-100);
		glVertex2f(342.5-350,375-100);
		glVertex2f(352.5-350,385-100);
		glVertex2f(367.5-350,385-100);
		glVertex2f(377.5-350,375-100);
		glVertex2f(377.5-350,365-100);
		glVertex2f(367.5-350,355-100);
		glVertex2f(352.5-350,355-100);
	glEnd();
	glColor3f(1.0,1.0,1.0);//left holder
	glBegin(GL_POLYGON);
		glVertex2f(342.5-350,268);
		glVertex2f(332.5-350,268);
		glVertex2f(332.5-350,272);
		glVertex2f(342.5-350,272);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//right holder
		glVertex2f(377.5-350,268);
		glVertex2f(387.5-350,268);
		glVertex2f(387.5-350,272);
		glVertex2f(377.5-350,272);
	glEnd();
	panels1(1);
}
void rockettop()
{
glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 1: Payload
		glVertex2f(237.5-100,140.0+200-100);
		glVertex2f(262.5-100,140.0+200-100);
		glVertex2f(262.5-100,200.0+200-100);
		glVertex2f(237.5-100,200.0+200-100);
	glEnd();
	glColor3f(0.0,0.0 ,0.0);
	glBegin(GL_POLYGON);//payload lines
		glVertex2f(262.5-100,150+200-100);
		glVertex2f(242.5-100,150+200-100);
		glVertex2f(242.5-100,190+200-100);
		glVertex2f(242.5-100,190+200-100);
		glVertex2f(262.5-100,190+200-100);
	glEnd();
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//payload lines
		glVertex2f(262.5+20-100,150+200-100);
		glVertex2f(242.5+20-100,150+200-100);
		glVertex2f(242.5+20-100,190+200-100);
		glVertex2f(242.5+20-100,190+200-100);
		glVertex2f(262.5+20-100,190+200-100);
	glEnd();
	glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//triangle
	glVertex2f(237.5-100,200+200-100);
	glVertex2f(262.5-100,200+200-100);
	glVertex2f(250-100,240.0+200-100);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(237.5-100,200+200-100);
		glVertex2f(262.5-100,200+200-100);
	glEnd();
	glColor3f(1 ,1 ,0);
	glBegin(GL_POLYGON);//bottom_1_exhaust
	glVertex2f(237.5-100,140.0+200-100);
	glVertex2f(244.5-100,140.0+200-100);
	glVertex2f(241-100,120.0+200-100);
	glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust
	glVertex2f(246.5-100,140.0+200-100);
	glVertex2f(253.5-100,140.0+200-100);
	glVertex2f(249.5-100,120.0+200-100);
	glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust
	glVertex2f(262.5-100,140.0+200-100);
	glVertex2f(255.5-100,140.0+200-100);
	glVertex2f(258.5-100,120.0+200-100);
	glEnd();
}



void mars(float radius)
{

glColor3f(1.0,1.0,1.0);
   glBegin(GL_POLYGON);

   for (int i=0; i<=359; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(300+f+cos(degInRad)*radius,500-t+(sin(degInRad))*radius);//100,100 specifies centre of the circle
   }
	
   glEnd();
   t=t+0.2;
   f=f+0.2;
}

void myinit()
{
	glClearColor(0,0,0,1.0);
	glPointSize(1.0);
	gluOrtho2D(0, 499, 0, 499);
}
void drawText(float x, float y, int r, int g, int b, int d, const char *string)
{
	int j = strlen(string);
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	for (int k = d; k>0; k--) {
			glFlush();
		}
	}
}
void drawText1(float x, float y, int r, int g, int b, int d, const char *string)
{
	int j = strlen(string);

	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
		for (int k = d; k>0; k--) {
			glFlush();
		}
	}
}
void win1() {
	glClearColor(0.196078  ,0.6 ,0.8,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	initialbackground();
	rocket();
	isro();
	drawText(200, 50, 1, 0, 0, 0, "Enter '2' to launch the rocket");
	glFlush();
	glutSwapBuffers();
}

void win2() {
	rocketlaunched=1;
	glClearColor(0.196078  ,0.6 ,0.8,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	initialbackground();
	isro();
	glFlush();
	int i;
	t=0,f=0;
	int x=0,y=0,z=0,j=0;
	for (i = 0; i <= 600; i++) {  
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		initialbackground();
		isro();
		glPushMatrix();
		//glTranslatef(x,y+i,z);
		glTranslatef(x+(0.2*i),y+i,z);
		rocket();
		glPopMatrix();
		p++;
		for(j=0;j<=70;j++);
		glFlush();
		glutSwapBuffers();
	}
	int k=0;
	for(k=0;k<2;k++){
	if(exitflag==1)break;
	for(i=0;i<=700;i++)
	{
		if(exitflag==1)break;
		if(k==0){
		glClearColor(0.096078  ,0.35 ,1,1.0);
		for(j=0;j<=60000;j++);
		}
		else{
		glClearColor(0.006078  ,0.15 ,1,1.0);
		for(j=0;j<=3000;j++);
		}
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		stars1();
		glPushMatrix();
		glTranslatef(x-50+(i*0.2),y+i,z);
		rocketmoving();
		glPopMatrix();
		glFlush();
		glutSwapBuffers();
	}
	}
	for(i=0;i<=200;i++)
	{
		if(exitflag==1)break;
		glClearColor(0.006078  ,0.005 ,0.4,1.0);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		stars();
		glPushMatrix();
		glTranslatef(x-40+(i*0.2),y+i,z);
		rocketmoving();
		glPopMatrix();
		for(j=0;j<=1000;j++)
		;
		glFlush();
		glutSwapBuffers();
	}
	
	
	for(k=0;k<=275;k++){
		if(exitflag==1)break;
		glClearColor(0.0 ,0.0 ,0.0,1.0);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		if(flag1==0)
		{
			stars();
			flag1=1;
		}
		else
		{
			stars1();
			flag1=0;
		}
	drawText(200, 75, 1, 0, 0, 0, "Rocket Launched");
		drawText(200, 50, 1, 0, 0, 0, "Enter '3' to release the lower part");
	for(i=195;i<=200;i++)
	{
		if(exitflag==1)break;
		for(j=0;j<=100;j++);
		glClearColor(0.0 ,0.0 ,0.0,1.0);
		glPushMatrix();
		glScalef(1-(k*0.0001),1-(k*0.0005),0);
		mars(30.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(x,y+i,z);
		rocketmoving();
		glPopMatrix();
		drawText(200, 75, 1, 0, 0, 0, "Rocket Launched");
		drawText(200, 50, 1, 0, 0, 0, "Enter '3' to release the lower part");
		glFlush();
		glutSwapBuffers();
}
}


}

void win3() {
	if(rocketlaunched==1)
	{
	bottomreleased=1;
	glClearColor(0.0 ,0.0 ,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	int k=0;
	t=0;f=0;
	for(k=0;k<=320;k++){
		if(exitflag==1)break;
		glClearColor(0.0 ,0.0 ,0.0,1.0);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		if(flag1==0)
		{
			stars();
			flag1=1;
		}
		else
		{
			stars1();
			flag1=0;
		}
	rocketBottom(k);
	for(i=195;i<=200;i++)
	{
		if(exitflag==1)break;
		glClearColor(0.0 ,0.0 ,0.0,1.0);
		glPushMatrix();
		glScalef(1-(k*0.0001),1-(k*0.0005),0);
		mars(25.0);
		glPopMatrix();
		rocketBottomGone(i,p);	
		p=p+1;
		for(j=0;j<=10000;j++);
		drawText(200, 75, 1, 0, 0, 0, "Bottom Portion Released");
		drawText(200, 50, 1, 0, 0, 0, "Enter '4' to release the middle part ");
		glFlush();
		glutSwapBuffers();		
	}
	}
	glFlush();
	glutSwapBuffers();
	}
}
void win4() {
	if(rocketlaunched==1 && bottomreleased==1)
	{
	middlereleased=1;
	glClearColor(0.0 ,0.0 ,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	int k=0;
	t=0;f=0;
	for(k=0;k<=340;k++){
		if(exitflag==1)break;
		glClearColor(0.0 ,0.0 ,0.0,1.0);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		if(flag1==0)
		{
			stars();
			flag1=1;
		}
		else
		{
			stars1();
			flag1=0;
		}
	rocketMiddle(k);
	for(i=195;i<=200;i++)
	{
		if(exitflag==1)break;
		glClearColor(0.0 ,0.0 ,0.0,1.0);
		glPushMatrix();
		glScalef(1-(k*0.0001),1-(k*0.0005),0);
		mars(20.0);
		glPopMatrix();
		rocketMiddleGone(i,p);	
		p=p+1;
		for(j=0;j<=10000;j++);
		drawText(200, 75, 1, 0, 0, 0, "Middle Part Released");
		drawText(200, 50, 1, 0, 0, 0, "Enter '5' to release the satellite ");
		glFlush();
		glutSwapBuffers();		
	}
	}
	}
}
void win5() {
	if(rocketlaunched==1 && bottomreleased==1 && middlereleased==1)
	{
		int k=0;
		t=0;f=0;
		for(k=0;k<=350;k++){
			if(exitflag==1)break;
			glClearColor(0.0 ,0.0 ,0.0,1.0);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			if(flag1==0)
			{
				stars();
				flag1=1;
			}
			else
			{
				stars1();
				flag1=0;
			}
			payloadHold();
			for(j=0;j<100000;j++);
			glFlush();
			glutSwapBuffers();
		}
		for(t=1;t<=20;t++)
		{
			if(exitflag==1)break;
			glClearColor(0.0 ,0.0 ,0.0,1.0);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			if(flag1==0)
			{
				stars();
				flag1=1;
			}
			else
			{
				stars1();
				flag1=0;
			}
			payloadRemoveCap(t);
			for(j=0;j<10000000;j++);
			glFlush();
			glutSwapBuffers();
		}
		for(k=1;k<=100;k++)
		{
			if(exitflag==1)break;
			glClearColor(0.0 ,0.0 ,0.0,1.0);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			if(flag1==0)
			{
				stars();
				flag1=1;
			}
			else
			{
				stars1();
				flag1=0;
			}
			payloadCapRemoved();
			moveSatellite(k);//move polygon hexa to right
			for(j=0;j<1000000;j++);
			glutSwapBuffers();
		}
		for(k=0;k<=100;k++)
		{
			if(exitflag==1)break;
			glClearColor(0.0 ,0.0 ,0.0,1.0);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			if(flag1==0)
			{
				stars();
				flag1=1;
			}
			else
			{
				stars1();
				flag1=0;
			}
			holdSatellite(k);//move rocket left cross and satellite down
			for(j=0;j<2000000;j++);
			drawText(200, 75, 1, 0, 0, 0, "Satellite Released");
			drawText(200, 50, 1, 0, 0, 0, "Enter '6' to place the satellite ");
			//glFlush();
			glutSwapBuffers();
		}
		for(k=0;k<=50;k++)
		{
			if(exitflag==1)break;
			glClearColor(0.0 ,0.0 ,0.0,1.0);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			if(flag1==0)
			{
				stars();
				flag1=1;
			}
			else
			{
				stars1();
				flag1=0;
			}
			solar_panel();//only hexa
			for(j=0;j<1000000;j++);
			drawText(200, 75, 1, 0, 0, 0, "Satellite Released");
			drawText(200, 50, 1, 0, 0, 0, "Enter '6' to place the satellite ");
			glutSwapBuffers();
		}
		for(k=0;k<=250;k++)
		{
	if(exitflag==1)break;
			glClearColor(0.0 ,0.0 ,0.0,1.0);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			if(flag1==0)
			{
				stars();
				flag1=1;
			}
			else
			{
				stars1();
				flag1=0;
			}
			solar_panel();
			for(j=1;j<=3;j++)
			{
				panels(j);
				for(f=0;f<100000;f++);//complete sat
			}
			drawText(200, 75, 1, 0, 0, 0, "Satellite Released");
			drawText(200, 50, 1, 0, 0, 0, "Enter '6' to place the satellite ");
			glutSwapBuffers();
		}
		drawText(200, 75, 1, 0, 0, 0, "Satellite Released");
		drawText(200, 50, 1, 0, 0, 0, "Enter '6' to place the satellite ");
					
	}
	glFlush();
	
}
void win6() 
{
	int j,k,t=0,f=0;
	for(k=0;k<=200;k++)//to move sat to next frame
	{
		if(exitflag==1)break;
		glClearColor(0.0 ,0.0 ,0.0,1.0);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		if(flag1==0)
		{
			stars();
			flag1=1;
		}
		else
		{
			stars1();
			flag1=0;
		}
		glPushMatrix();
		glTranslatef(0-k,0-k,0);
		rockettop();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0+k,0,0);
		solar_panel1();
		glPopMatrix();
		for(j=0;j<1000000;j++);
		glFlush();
		glutSwapBuffers();
	}
	for(k=0;k<=200;k++)//diagonally move sat
	{
		if(exitflag==1)break;
		glClearColor(0.0 ,0.0 ,0.0,1.0);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		if(flag1==0)
		{
			stars();
			flag1=1;
		}
		else
		{
			stars1();
			flag1=0;
		}
		circle(75,250,250,0.4,0.164705,0.094117);
		circle(70,250,250,0.407843,0.172549,0.10196);
		circle(65,250,250,0.415686,0.180392,0.109803);
		circle(60,250,250,0.42359,0.188235,0.117647);
		circle(55,250,250,0.43137,0.196078,0.12549);
		circle(50,250,250,0.43921,0.203921,0.133333);
		circle(45,250,250,0.447058,0.211764,0.141176);
		circle(40,250,250,0.454902,0.219607,0.149019);
		circle(35,250,250,0.462745,0.22745,0.156862);
		circle(30,250,250,0.47043,0.235137,0.164549);
		circle(25,250,250,0.47843,0.243137,0.172549);
		circle(20,250,250,0.48434,0.251137,0.180549);
		
		glPushMatrix();
		glScalef(1-(0.0017*k),1-(0.0015*k),1);
		glTranslatef(0+(1.4*k),0+(k*1.27),0);
		solar_panel11();			
		glPopMatrix();
		for(j=0;j<1000000;j++);
		glutSwapBuffers();
	}
	for(k=0;k<2;k++)//rotate around mars
	{
		int i;
		glClearColor(0.0 ,0.0 ,0.0,1.0);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);			
		for(j=0;j<1000000;j++);
		for(j=0;j<360;j++)
		{
			if(exitflag==1)break;
			glClearColor(0.0 ,0.0 ,0.0,1.0);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			if(flag1==0)
			{
			stars();
			flag1=1;
			}
			else
			{
			stars1();
			flag1=0;
			}	
			circle(75,250,250,0.4,0.164705,0.094117);
			circle(70,250,250,0.407843,0.172549,0.10196);
			circle(65,250,250,0.415686,0.180392,0.109803);
			circle(60,250,250,0.42359,0.188235,0.117647);
			circle(55,250,250,0.43137,0.196078,0.12549);
			circle(50,250,250,0.43921,0.203921,0.133333);
			circle(45,250,250,0.447058,0.211764,0.141176);
			circle(40,250,250,0.454902,0.219607,0.149019);
			circle(35,250,250,0.462745,0.22745,0.156862);
			circle(30,250,250,0.47043,0.235137,0.164549);
			circle(25,250,250,0.47843,0.243137,0.172549);
			circle(20,250,250,0.48434,0.251137,0.180549);
			glPushMatrix();
			glTranslatef(230,210,0);//change this to cange the center
			glScalef(0.6,0.6,0);
			glRotatef(0+j,0.0,0.0,-0.9);
			solar_panel11();//the whole satellite
			glPopMatrix();
			if(k>=1){
			drawText1(140, 450, 1, 1, 0, 0, "CONGRATULATIONS");
			drawText1(125, 425, 1, 1, 0, 0, "MISSION SUCCESSFUL!!");
			drawText(350,25, 1, 0, 0, 0, "Enter '7' to Exit");}
			for(i=0;i<3000000;i++);
			glFlush();
			glutSwapBuffers();
			glutPostRedisplay();
		}
	}
}

void win7() {
	exitflag=1;
	exit(0);
}
void Normalkey(unsigned char k, int x, int y)
{

	switch (k)
	{
	case '1':win1();//static view
		break;
	case '2':win2();//rocket launch
		break;
	case '3':win3();//bottom part release
		break;
	case '4':win4();//middle part release
		break;
	case '5':win5();//release satellite
		break;
	case '6':win6();//place satellite in orbit around mars
		break;
	case '7':win7();//exit
		break;
	}
	
}


int main(int argc,char*argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("Rocket Launch Visualization");
	createMenu();
	myinit();
	glutDisplayFunc(display1);
	glutKeyboardFunc(Normalkey);
	glutMainLoop();
   	return 0;
}

void stars()
{

	glColor3f(1.0,1.0,1.0);
	glPointSize(0.47);
	glBegin(GL_POINTS);
	glVertex2i(10,20);
	glVertex2i(20,100);
	glVertex2i(30,10);
	glVertex2i(15,150);
	glVertex2i(17,80);
	glVertex2i(200,200);
	glVertex2i(55,33);
	glVertex2i(400,300);
	glVertex2i(330,110);
	glVertex2i(125,63);
	glVertex2i(63,125);
	glVertex2i(20,10);
	glVertex2i(110,330);
	glVertex2i(440,430);
	glVertex2i(32,65);
	glVertex2i(110,440);
	glVertex2i(210,230);
	glVertex2i(390,490);
	glVertex2i(12,90);
	glVertex2i(400,322);
	glVertex2i(420,366);
	glVertex2i(455,400);
	glVertex2i(20,20);
	glVertex2i(111,120);
	glVertex2i(401,200);
	glVertex2i(230,30);
	glVertex2i(220,20);
	glVertex2i(122,378);
	glVertex2i(133,340);
	glVertex2i(345,420);
	glVertex2i(130,360);
	glVertex2i(333,120);
	glVertex2i(250,22);
	glVertex2i(242,11);
	glVertex2i(280,332);
	glVertex2i(233,40);
	glVertex2i(210,418);
	glVertex2i(256,12);
	glVertex2i(288,232);
	glVertex2i(247,36);
	glVertex2i(229,342);
	glVertex2i(257,47);
	glVertex2i(290,63);
	glVertex2i(232,72);
	glVertex2i(243,143);
	glVertex2i(100,200);
	glVertex2i(90,250);
	glVertex2i(80,225);
	glVertex2i(50,333);
	glVertex2i(60,350);
	glVertex2i(243,143);
	glVertex2i(243,143);
	glEnd();
}

void stars1()
{
	int l;
	glColor3f(1.0,1.0,1.0);
	glPointSize(0.3);
	glBegin(GL_POINTS);
	glVertex2i(50,20);
	glVertex2i(70,100);
	glVertex2i(80,10);
	glVertex2i(65,150);
	glVertex2i(67,80);
	glVertex2i(105,33);
	glVertex2i(450,300);
	glVertex2i(380,110);
	glVertex2i(175,63);
	glVertex2i(113,125);
	glVertex2i(70,10);
	glVertex2i(160,330);
	glVertex2i(490,430);
	glVertex2i(82,65);
	glVertex2i(160,440);
	glVertex2i(440,490);
	glVertex2i(62,90);
	glVertex2i(450,322);
	glVertex2i(420,366);
	glVertex2i(455,400);
	glVertex2i(60,20);
	glVertex2i(111,120);
	glVertex2i(451,200);
	glVertex2i(280,30);
	glVertex2i(220,20);
	glVertex2i(132,378);
	glVertex2i(173,340);
	glVertex2i(325,420);
	glVertex2i(180,360);
	glVertex2i(383,120);
	glVertex2i(200,22);
	glVertex2i(342,11);
	glVertex2i(330,332);
	glVertex2i(283,40);
	glVertex2i(210,418);
	glVertex2i(256,12);
	glVertex2i(288,232);
	glVertex2i(247,36);
	glVertex2i(229,342);
	glVertex2i(257,47);
	glVertex2i(290,63);
	glVertex2i(232,72);
	glVertex2i(243,143);
	glVertex2i(100,200);
	glVertex2i(90,250);
	glVertex2i(80,225);
	glVertex2i(50,333);
	glVertex2i(60,350);
	glVertex2i(243,143);
	glVertex2i(243,143);
	glEnd();
	for(l=0;l<=10000;l++);
}



