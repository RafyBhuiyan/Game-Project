#include<iostream>
using namespace std;
# include "iGraphics.h"
int mposx, mposy, sclength = 1263, scheight = 593,level=0;
/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
int sx = 350, sy = 100, index = 0, ex = 700, ey = 80, index1 = 0;
char bground[3][50] = { "image/Cartoon_Forest_BG_02 (1).png", "", "" };
char player_attack[5][40] = { "image/shinobi_attack/00_Attack_1.png", "image/shinobi_attack/01_Attack_1.png", "image/shinobi_attack/02_Attack_1.png", "image/shinobi_attack/03_Attack_1.png", "image/shinobi_attack/04_Attack_1.png" };
char enemy_attack[10][40] = { "image/enemy1/Attack_000.png", "image/enemy1/Attack_001.png", "image/enemy1/Attack_002.png", "image/enemy1/Attack_003.png", "image/enemy1/Attack_004.png", "image/enemy1/Attack_005.png", "image/enemy1/Attack_006.png", "image/enemy1/Attack_007.png", "image/enemy1/Attack_008.png", "image/enemy1/Attack_009.png", };
void shinobi()
{
	index++;
	if (index == 5)
	{
		index = 0;
	}
}
void enemy()
{
	index1++;
	if (index1 == 10)
	{
		index1 = 0;
	}
}
void iDraw()
{
	iClear();
	iShowImage(0, 0, sclength, scheight, iLoadImage(bground[level]));
	iShowImage(sx, sy, 300, 300, iLoadImage(player_attack[index]));
	iShowImage(ex, ey, 350, 350, iLoadImage(enemy_attack[index1]));
}
void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{
		
	}
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
	if (key == GLUT_KEY_RIGHT)
	{
		sx += 20;
		sx = min(sx, sclength - 300);
	}
	if (key == GLUT_KEY_LEFT)
	{
		sx -= 20;
		sx = max(0, sx);
	}
	if (key == GLUT_KEY_UP)
	{
		sy += 20;
	}
	
}


int main()
{
	///srand((unsigned)time(NULL));
	iInitialize(sclength, scheight, "Zeda : The Ultimate Revenge");
	iSetTimer(1, shinobi);
	iSetTimer(1, enemy);
	///updated see the documentations
	iStart();
	return 0;
}
