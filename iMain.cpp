#include<iostream>
using namespace std;
#include "iGraphics.h"
#include "variable.h"
#include "function.h"
#include "background.h"
#include "Level1.h"
#include "playerchar.h"

void iDraw()
{
	iClear();
	iShowImage(0, 0, sclength, scheight, iLoadImage(bground[level]));
	iRectangle(50, 550, 300, 20);
	iFilledRectangle(50, 550, playerhealth * 3, 20);
	iRectangle(900, 550, 300, 20);
	iFilledRectangle(900, 550, enemyhealth*6, 20);
	if (run)
	{
		iShowImage(playercorx, playercory, charwidth, charheight, iLoadImage(player_run[runindex]));
	}
	else if (attack){
		iShowImage(playercorx, playercory, charwidth, charheight, iLoadImage(player_attack[playerattackindex]));
		if (playerattackindex == 3)
		{
			enemycorx += 20;
		}
	}
	else if (jumpindex)
	{
		iShowImage(playercorx, playercory, charwidth, charheight, iLoadImage(player_jump[jumpindex]));
	}
	else if (enemycorx-playercorx<=charwidth-100)
	{
		iShowImage(playercorx, playercory, charwidth, charheight, iLoadImage(player_sheild[shieldindex]));
		if (enemyattackindex == 5)
		{
			playercorx -= 20;
			playerhealth -= 25;
		}
	}
	else
	{
		iShowImage(playercorx, playercory, charwidth, charheight, iLoadImage(player_idle));
	}
	enemycorx = min(enemycorx, sclength - enemywidth);
	iShowImage(enemycorx, enemycory, enemyheight, enemywidth, iLoadImage(enemy_attack[enemyattackindex]));
	if (playercorx < enemycorx - 50)
	{
		enemycorx -= 2;
	}
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
	if (key == ' ')
	{
		attack = true;
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
		playercorx += 20;
		playercorx = min(playercorx, sclength - charwidth-50);
		if (playercorx >= enemycorx-50)
		{
			enemycorx += 30;
		}
		run = true;
	}
	if (key == GLUT_KEY_LEFT)
	{
		playercorx -= 20;
		playercorx = max(0, playercorx);
		run = true;
	}
	if (key == GLUT_KEY_UP)
	{
		if (!countjump && !onair)
				countjump = 1;
	}
}
int main()
{
	///srand((unsigned)time(NULL));
	iInitialize(sclength, scheight, "Zeda : The Ultimate Revenge");
	iSetTimer(1, playerrun);
	iSetTimer(1, jump);
	iSetTimer(1, playerattack);
	iSetTimer(1, enemyattack);
	iSetTimer(1, playershield);
	///updated see the documentations
	iStart();
	return 0;
}
