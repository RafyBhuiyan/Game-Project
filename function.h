void homepagefunc()
{
	iShowImage(0, 0, sclength, scheight, iLoadImage("image/homepage.png"));
}
void jump()
{
	if (countjump && jumpindex<8)
	{
		jumpindex++;
		playercory += 15;
	}
	else if (jumpindex)
	{
		jumpindex--;
		if (enemycory != playercory)
		{
			playercory -= 15;
		}
	}
	if (jumpindex == 8)
	{
		countjump = 0;
	}
}
void playerrun()
{
	if (run)
	{
		runindex++;
	}
	if (runindex == 3)
	{
		runindex = 0;
		run = false;
	}
}
void playerattack()
{
	if (attack)
		playerattackindex++;
	if (playerattackindex == 5)
	{
		playerattackindex = 0;
		attack = false;
	}
}
void playershield()
{
	if ((enemycorx - playercorx <= charwidth-100)||shieldindex)
	{
		shieldindex++;
		if (shieldindex == 2)
		{
			shieldindex = 0;
		}
	}
}
void enemyattack()
{
	if (rand() % (15-(level*2)) == 3 || enemyattackindex){
		if (enemyattackindex == 5)enemyfight = true;
		enemyattackindex++;
		if (enemyattackindex == 10)
		{
			enemyattackindex = 0;
		}
	}
}
void healthcheck()
{
	if (enemycorx - playercorx <= distancebetweenchar)
	{
		if ((playerattackindex * 2 > enemyattackindex && attack && playerattackindex == 3 ))
		{
			enemycorx += 20;
			enemyhealth -= (30 - (level*5));
			attack = false;
		}
		else if (playerattackindex * 2 == enemyattackindex && attack && enemyfight)
		{
			playercorx -= 20;
			playerhealth -= 10;
			enemyhealth -= 10;
			enemycorx += 20;
		}
		else if (((playerattackindex * 2 < enemyattackindex && enemyfight) || (run && enemyattackindex && enemyfight))&& enemyattackindex==7)
		{
			playercorx -= 20;
			playerhealth -= (20 + level*10);
			if (shield)
			{
				playerhealth += 10;
			}
			enemyfight = false;
			if (jumpindex)
			{
				jumpindex = 0;
				countjump = 0;
				playercory = 50;
			}
		}
	}
}
