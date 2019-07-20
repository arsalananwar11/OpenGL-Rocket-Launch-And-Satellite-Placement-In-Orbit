#include<GL/glut.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
const float DEG2RAD = 3.14159/180;
void display1();
void stars();
void stars1();
void static_rocket();
void rocket_to_cam_pos();
void rocket_in_motion();
void mars(float radius);
void menu(int num);
void createMenu(void);
bool lflag=false,e1flag=false,e2flag=false,rflag=false,sflag=false;
int submenu,value,p;
float i,j,count=10,count1=0,flag=0,flag1=0,t=0,f=0,flag3=0, forflag=0;
void rocket_in_motion1();
void createMenu(void)
{
	submenu=glutCreateMenu(menu);
	glutAddMenuEntry("Launch",1);
	glutAddMenuEntry("Eject-1",2);
	glutAddMenuEntry("Eject-2",3);
	glutAddMenuEntry("Release-Sat",4);
	glutAddMenuEntry("Rotate", 5);
	glutAddMenuEntry("Retry", 6);
	glutAddMenuEntry("Exit", 7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display()
{
count1++;
	static_rocket();
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




void semicircle(float radius,float u,float v)
{

	glColor3f(1.0 ,1.0 ,1.0);
	glBegin(GL_POLYGON);
	for (int i=135; i<=315; i++)
	{
	      float degInRad = i*DEG2RAD;
	      glVertex2f(u+cos(degInRad)*radius,v+(sin(degInRad))*radius);//100,100 specifies centre of circle
   	}
   	glEnd();
}

void display1()
{
	static_rocket();
	switch(value)	
	{
		case 1: //launch functions
			lflag=true;
	
			static_rocket();
       			rocket_to_cam_pos();
			
      			rocket_in_motion();
			
			break;
		case 2: if(lflag==true)
			{
				//eject bottom part
				e1flag=true;
				value=0;
				for(i=0;i<100;i++)
				rocket_in_motion1();
				
				break;
			}
			else
			{
				//mission fail function
				break;
			}
		case 3: if(e1flag==true)
			{
				//eject middle part
				e2flag=true;
				break;
			}
			else
			{
				//mission fail function
				break;
			}
		case 4: if(e2flag==true)
			{
				//release satellite
				rflag=true;
				break;
			}
			else
			{
				//mission fail function
				break;
			}
		case 5: if(rflag==true)
			{
				//rotate function
				sflag=true;
				if(sflag==true)
				{
					//mission success functions
					break;
				}
			}
			else
			{
				//mission fail
				break;
			}
		case 6: lflag=e1flag=e2flag=rflag=sflag=false;
			display();
			break;
		case 7: exit(0);
	}

count1++;
/*if(count1==500)
      flag=1;
 if(flag==0)
       static_rocket();
 else if(value==1 && (count1==51||count1==52))
       rocket_to_cam_pos();
 else
      rocket_in_motion();*/
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


		glColor3f(0.8,0.498039 ,0.196078);
		glBegin(GL_POLYGON);//House Right Part 
			glVertex2f(425.0,250.0);
			glVertex2f(475.0,250.0);
			glVertex2f(475.0,350.0);
			glVertex2f(425.0,350.0);
		glEnd();
		glColor3f(0.8,0.498039 ,0.196078);
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
		glColor3f(0.0,0.0,0.0);
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
		
		/*//windows
		glColor3f(1.0,1.0,0.0);
		glBegin(GL_POLYGON);//Windows A
			glVertex2f(255,267.5);
			glVertex2f(275.0,267.5);
			glVertex2f(275.0,277.5);
			glVertex2f(255.0,277.5);
			glEnd();
		glBegin(GL_POLYGON);//Windows B
			glVertex2f(255,285.0);
			glVertex2f(275.0,285);
			glVertex2f(275.0,295);
			glVertex2f(255.0,295);
			glEnd();

		glBegin(GL_POLYGON);//Windows C
			glVertex2f(255,302.5);
			glVertex2f(275.0,302.5);
			glVertex2f(275.0,312.5);
			glVertex2f(255.0,312.5);
			glEnd();

		glBegin(GL_POLYGON);//Windows D
			glVertex2f(255,320.0);
			glVertex2f(275.0,320.0);
			glVertex2f(275.0,330.0);
			glVertex2f(255.0,330.0);
			glEnd();

		glBegin(GL_POLYGON);//Windows E
			glVertex2f(285,267.5);
			glVertex2f(295.0,267.5);
			glVertex2f(295.0,277.5);
			glVertex2f(285.0,277.5);
			glEnd();

		glBegin(GL_POLYGON);//Windows F
			glVertex2f(285,285.0);
			glVertex2f(295.0,285);
			glVertex2f(295.0,295);
			glVertex2f(285.0,295);
			glEnd();

		glBegin(GL_POLYGON);//Windows G
			glVertex2f(285,302.5);
			glVertex2f(295.0,302.5);
			glVertex2f(295.0,312.5);
			glVertex2f(285.0,312.5);
			glEnd();

		glBegin(GL_POLYGON);//Windows H
			glVertex2f(285,320.0);
			glVertex2f(295.0,320.0);
			glVertex2f(295.0,330.0);
			glVertex2f(285.0,330.0);
			glEnd();
		*/
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
		
	//Background Definition Ends
}
void static_rocket()
{


count1+=10;
if(count1==500)
flag=1;
  if(flag==0)
  {
	glClearColor(0.196078  ,0.6 ,0.8,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	initialbackground();
	
	rocket();
	isro();	
	for(j=0;j<=1000000;j++)
		;
	glutSwapBuffers();
	glFlush();
	glutPostRedisplay();
	
}
}

void rocketmoving(int i, int p)
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
	if((p%2)==0)//fumes
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

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
	
}

void rocket_to_cam_pos()
{
count+=100;

for(i=0;i<=200;i++)
{

	glClearColor(0.196078  ,0.6 ,0.8,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	rocketmoving(i,p);

	
	
	p=p+1;
	for(j=0;j<=1000000;j++)
		;
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
	

	
}
glFlush();
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
void rocket_in_motion()
{
	
count++;
forflag=1;

for(i=195;i<=200;i++)
{
     if(count>=0)
	 {
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
	}
	else
	{
		glClearColor(0.196078  ,0.6 ,0.8,1.0);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	}
	if(count>=0)
	mars(20.0);
	rocketspace(i,p);
	
	
		p=p+1;


	for(j=0;j<=1000000;j++)
		;
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
	
}

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
	/*glColor3f(1.0,1.0 ,1.0);
	glBegin(GL_POLYGON);//Core 3: Bottom Part
		glVertex2f(237.5,20.0+i);
		glVertex2f(262.5,20.0+i);
		glVertex2f(262.5,80.0+i);
		glVertex2f(237.5,80.0+i);
	glEnd();*/
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
	glColor3f(1 ,1 ,0);
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
	glEnd();
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
void rocket_in_motion1()
{
	
count++;


for(i=195;i<=200;i++)
{
     
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
	
	
	rocketBottomGone(i,p);
	
		p=p+1;


	for(j=0;j<=1000000;j++)
		;
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
	
}
}
void mars(float radius)
{


   glBegin(GL_POLYGON);

   for (int i=0; i<=359; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(300+f+cos(degInRad)*radius,500-t+(sin(degInRad))

*radius);//100,100 specifies centre of the circle
   }
	
   glEnd();
   t=t+0.1;
   f=f+0.1;
}






void myinit()
{
	//int i;
	glClearColor(0.196078  ,0.6 ,0.8,1.0);
	glPointSize(1.0);
	gluOrtho2D(0.0,499.0,0.0,499.0);
}


void Normalkey(unsigned char k, int x, int y)
{
	switch (k)
	{
		case '1': //launch functions
			lflag=true;
	
			static_rocket();
       			rocket_to_cam_pos();
			rocket_in_motion();
			
			break;
		case '2': if(lflag==true)
			{
				//eject bottom part
				e1flag=true;
				value=0;
				for(i=0;i<100;i++)
				rocket_in_motion1();
				
				break;
			}
			else
			{
				//mission fail function
				break;
			}
		case '3': if(e1flag==true)
			{
				//eject middle part
				e2flag=true;
				break;
			}
			else
			{
				//mission fail function
				break;
			}
		case '4': if(e2flag==true)
			{
				//release satellite
				rflag=true;
				break;
			}
			else
			{
				//mission fail function
				break;
			}
		case '5': if(rflag==true)
			{
				//rotate function
				sflag=true;
				if(sflag==true)
				{
					//mission success functions
					break;
				}
			}
			else
			{
				//mission fail
				break;
			}
		case '6': lflag=e1flag=e2flag=rflag=sflag=false;
			display();
			break;
		case '7': exit(0);
	}
}


int main(int argc,char*argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1000,800);
	glutCreateWindow("Rocket Simulation");
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
	for(l=0;l<=10000;l++)
		;
}



