#include<iostream>
using namespace std;
#include "iGraphics.h"
#include "variable.h"
#include "struct.h"
#include "function.h"
#include "background.h"
#include "Level1.h"
#include "playerchar.h"
int temp = 0;
void iDraw()
{
	iClear();
	if (story)
	{
		sprintf_s(storypic, "image/storypage%d.png", storynum);
		iShowImage(0, 0, sclength, scheight, iLoadImage(storypic));
	}
	else if (control)
	{
		iShowImage(0, 0, sclength, scheight, iLoadImage("image/instructions.png"));
	}
	else if (about)
	{
		iShowImage(0, 0, sclength, scheight, iLoadImage("image/aboutpage.png"));
	}
	else if (option)
	{
		iShowImage(0, 0, sclength, scheight, iLoadImage("image/optionpage.png"));
	}
	else if (homepage)
	{
		homepagefunc();
	}
	else if (gameon)
	{
		sprintf_s(enemyattackpic, "image/enemy_%d/Attack_00%d.png", level + 1, enemyattackindex);
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
		else if (attack)
		{
			iShowImage(playercorx, playercory, charwidth, charheight, iLoadImage(player_attack[playerattackindex]));
			if (playerattackindex == 3)
			{
				if (!mute)
					PlaySound("sounds/playerhitsound.wav", NULL, SND_ASYNC);
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
		}
		else
		{
			iShowImage(playercorx, playercory, charwidth, charheight, iLoadImage(player_idle));
		}
		healthcheck();
		enemycorx = min(enemycorx, sclength - enemywidth);
		iShowImage(enemycorx, enemycory, enemyheight, enemywidth, iLoadImage(enemyattackpic));
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
	else if (playerhealth > 0)
	{
		score += (playerhealth / 3);
		if (level < 2){
			iShowImage(0, 0, sclength, scheight, iLoadImage("image/Won.png"));
			if (!temp)
			{
				temp++;
				if (!mute)
				PlaySound("sounds/levelwinsound.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
		else
		{
			iShowImage(0, 0, sclength, scheight, iLoadImage("image/final_win.png"));
			if (!temp)
			{
				temp++;
				if (!mute)
				PlaySound("sounds/finalwinsound.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
	}
	else
	{
		iShowImage(0, 0, sclength, scheight, iLoadImage("image/Game_Over.png"));
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
		cout << mx << " " << my << endl;
		if (story)
		{
			if (mx >= 1045 && mx <= 1150 && my >= 20 && my <= 100)
			{
				storynum++;
				if (storynum == 3)
				{
					story = false;
					homepage = true;
				}
			}
		}
		else if (control || about)
		{
			if (mx >= 45 && mx <= 125 && my >= 490 && my <= 530)
			{
				control = false;
				about = false;
			}
		}
		else if (option)
		{
			if (mx >= 55 && mx <= 115 && my >= 490 && my <= 530)
			{
				option = false;
				if (!mute)
					PlaySound("sounds/storyandhomesound.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			if (mx >= 500 && mx <= 780)
			{
				if (my >= 335 && my <= 405)
				{
				}
				else if (my >= 255 && my <= 325)
				{
					control = true;
				}
				else if (my >= 175 && my <= 245)
				{
					about = true;
				}
			}
		}
		else if (homepage)
		{
			if (mx >= 550 && mx <= 720 && my <= 230 && my >= 155)
			{
				homepage = 0;
				gameon = true;
				if (!mute)
				PlaySound("sounds/gameplaysound.wav", NULL, SND_ASYNC);
			}
			else if (mx >= 1110 && mx <= 1215 && my <= 75 && my >= 10)
			{
				exit(0);
			}
			else if (mx >= 60 && mx <= 140 && my <= 75 && my >= 5)
			{
				option = true;
				if (!mute)
					PlaySound("sounds/optionsound.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
		else if (playerhealth && !gameon)
		{
			if (mx >= 485 && mx <= 765 && my <= 340 && my >= 270)
			{
				if (level!=2)
				{
					level++;
					gameon = true;
					new_level();
					temp = 0;
				}
			}
			else if (mx >= 485 && mx <= 765 && my <= 260 && my >= 190)
			{
				level = 0;
				new_level();
				homepage = true;
				temp = 0;
				if (!mute)
				PlaySound("sounds/storyandhomesound.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else if (mx >= 500 && mx <= 770 && my <= 148 && my >= 80 && level == 2)
			{
				level = 0;
				new_level();
				homepage = true;
				temp = 0;
				if (!mute)
				PlaySound("sounds/storyandhomesound.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
		else if (!gameon && enemyhealth)
		{
			if (mx >= 500 && mx <= 770 && my <= 148 && my >= 80)
			{
				level = 0;
				new_level();
				homepage = true;
				temp = 0;
				if (!mute)
				PlaySound("sounds/storyandhomesound.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
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
		if (story)
		{
			storynum++;
			if (storynum == 3)
			{
				story = false;
				homepage = true;
			}
		}
		else if (gameon)
		{
			attack = true;
		}
	}
	if (key == 'm')
	{
		mute = mute ? false : true;
		if (mute)
		{
			PlaySound("sounds/soundoff.wav", NULL, SND_ASYNC);
		}
		else
		{
			if (option)
			{
				PlaySound("sounds/optionsound.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else if (homepage)
			{
				PlaySound("sounds/storyandhomesound.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else if (gameon)
			{
			}
			else
			{
				if (playerhealth)
				{
					if (level!=2)
					PlaySound("sounds/levelwinsound.wav", NULL, SND_LOOP | SND_ASYNC);
					else
					PlaySound("sounds/finalwinsound.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
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
		playercorx = min(playercorx, sclength - charwidth - 50);
		if (playercorx >= enemycorx - 50)
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
	if (key == GLUT_KEY_HOME)
	{
		homepage = true;
		level = 0;
		new_level();
		if (!mute) PlaySound("sounds/storyandhomesound.wav", NULL, SND_LOOP | SND_ASYNC);
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
	PlaySound("sounds/storyandhomesound.wav", NULL, SND_LOOP | SND_ASYNC);
	iSetTimer(0, change);
	///updated see the documentations
	iStart();
	return 0;
}
