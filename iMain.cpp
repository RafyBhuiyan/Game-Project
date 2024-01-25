#include<iostream>
using namespace std;
#include "iGraphics.h"
#include "variable.h"
#include "struct.h"
#include "function.h"
#include "background.h"
#include "Level1.h"
#include "playerchar.h"
void iDraw()
{
	iClear();
	if (gameon)
	{
		iShowImage(0, 0, sclength, scheight, iLoadImage(level1bground[level]));
		iSetColor(255, 255, 255);
		iText(50, 560, "Player's Health", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(900, 560, "Enemy's Health", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0, 255, 0);
		iRectangle(50, 530, 300, 20);
		iFilledRectangle(50, 530, playerhealth, 20);
		iRectangle(900, 530, 300, 20);
		iSetColor(255, 0, 0);
		enemyhealthbarx = enemyhealth;
		iFilledRectangle(900, 530, enemyhealthbarx, 20);
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
		else if (enemycorx - playercorx <= distancebetweenchar)
		{
			iShowImage(playercorx, playercory, charwidth, charheight, iLoadImage(player_sheild[shieldindex]));
			shield = true;
			//healthcheck();
		}
		else
		{
			iShowImage(playercorx, playercory, charwidth, charheight, iLoadImage(player_idle));
		}
		healthcheck();
		enemycorx = min(enemycorx, sclength - enemywidth);
		//iShowImage(enemycorx, enemycory, enemyheight, enemywidth, iLoadImage(tlevels[levels].enemy_attack[enemyattackindex]));
		iShowImage(enemycorx, enemycory, enemyheight, enemywidth, iLoadImage(ra));
		if (enemycorx - playercorx >= 100)
		{
			enemycorx -= 2;
		}
		if (playerhealth <= 0 || enemyhealth <= 0)
		{
			gameon = false;
			if (playerhealth > enemyhealth)
			{
				enemydead = true;
			}
		}
	}
	else if (playerhealth>=0)
	{
		score += (playerhealth / 3);
		iText(sclength / 2, scheight / 2, "Game over......Player Won", GLUT_BITMAP_TIMES_ROMAN_24 );
		//iText(sclength / 2, scheight / 2 -25, "", GLUT_BITMAP_TIMES_ROMAN_24);
		//iText(sclength / 2, scheight / 2, "New one.......", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else
	{
		iText(sclength / 2, scheight / 2, "Game over.......Enemy Won", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	sprintf_s(ra, "image/enemy1/Attack_00%d.png", enemyattackindex);
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
	if (key == 'n')
	{
		if (!gameon && playerhealth)
		{
			level++;
			new_level();
		}
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
		playercorx += 30;
		playercorx = min(playercorx, sclength - charwidth-50);
		if (playercorx >= enemycorx-50)
		{
			enemycorx += 30;
		}
		run = true;
		shield = false;
	}
	if (key == GLUT_KEY_LEFT)
	{
		playercorx -= 30;
		playercorx = max(0, playercorx);
		run = true;
		shield = false;
	}
	if (key == GLUT_KEY_UP)
	{
		if (!countjump && !onair)
				countjump = 1;
		shield = false;
	}
}
void change()
{
	playerrun();
	jump();
	playerattack();
	enemyattack();
	playershield();
}
int main()
{
	///srand((unsigned)time(NULL));
	iInitialize(sclength, scheight, "Zeda : The Ultimate Revenge");
	iSetTimer(0, change);
	///updated see the documentations
	iStart();
	return 0;
}