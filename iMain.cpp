#include<iostream>
nihlkmnbvuy
using namespace std;
# include "iGraphics.h"
int mposx,  mposy;
int sclength = 1250, scheight = 600, x = 20, y = 6, r = 255,radius=6, b = 255, g = 255,dx=10,dy=10,a=0,l=70,t=25,k=1;
/*
	function iDraw() is called again and again by the system.
*/
void drawbar()
{
	iSetColor(120, 120, 120);
	iFilledRectangle(a, 0, l, 7);
}
void drawball()
{
	iSetColor(r, g, b);
	iFilledCircle(x, y, radius, 1000);
}
void drawbarrev()
{
	iSetColor(120, 120, 120);
	iFilledRectangle(sclength-a,0, l, 7);
}
void iDraw()
{
	//place your drawing codes here
	iClear();
	drawbar();
	drawball();
	drawbar();
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
	a = mx- l/2;
	if (a <= 0)
	{
		a = 0;
	}
	if (a + l > sclength)
	{
		a = sclength - l;
	}
	//y = my;
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here
 mposx = mx;
 mposy = my;
 a = mposx - l / 2;
 if (a <= 0)
 {
	 a = 0;
 }
 if (a + l > sclength)
 {
	 a = sclength - l;
 }  /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'r')
	{
		r = 255;
		g = 0;
		b = 0;
		//do something with 'q'
	}
	else if (key == 'g')
	{
		r = 0;
		g = 255;
		b = 0;
	}
	else if (key == 'b')
	{
		r = 0;
		g = 0;
		b = 255;
	}
	else if (key == 'y')
	{
		r = 255;
		g = 255;
		b = 0;
	}
	/*else if (key == 'w')
	{
		y += 10;
	}
	else if (key == 's')
	{
		y -= 10;
	}*/
	else if (key == 'a')
	{
		a -= 10;
		if (a <= 0)
		{
			a = 0;
		}
	}
	else if (key == 'd')
	{
		a += 10;
		if (a + l >= sclength)
		{
			a = sclength - l;
		}
	}
	else if (key == 'n')
	{
		a = 0;
		x = 50;
		y = 50;
		dx = 10;
		dy = 10;
	}
	else if (key == 'x')
	{
		exit(0);
	}
	/*else if (key == 'q')
	{
		y += 10;
		x -= 10;
	}*/
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	/*if(key == GLUT_KEY_UP)
	{
		y += 10;
		if (y + 20 > scheight)
		{
			y = 0;
		}
	}
	else if (key == GLUT_KEY_DOWN)
	{
		y -= 10;
		if (y <= 0)
		{
			y = 0;
		}
	}
	else */
	if (key == GLUT_KEY_RIGHT)
	{
		a += 30;
		if (a + l >= sclength)
		{
			a=sclength - l;
		}
	}
	else if (key == GLUT_KEY_LEFT)
	{
		a -= 30;
		if (a <= 0)
		{
			a = 0;
		}
	}
	//place your codes for other keys here
}
//
void change()
{
	x += dx;
	y += dy;
	
	if (x >= sclength-radius || x <= radius)
	{
		dx *= (-1);
	}
	if (y >= scheight - radius)
	{
		dy *= (-1);
	}
	if (y <= 7 + radius && (x + radius<a || x - radius>a + l))
	{
		dx = 0;
		dy = 0;
	}
	else if (y<=7+radius)
	{
		dx = (x - a - (l / 2))/2;
		dy *= (-1);
		if (dy > 20)
		{
			dy = 15;
		}
	}
}
int main()
{
	//place your own initialization codes here.
	iSetTimer(5, change);
	iInitialize(sclength,scheight, "demooo");
	return 0;
}
 
