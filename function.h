void jump()
{
	if (countjump)
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
void shinobiattack()
{
	if (attack)
		playerattackindex++;
	if (playerattackindex == 5)
	{
		playerattackindex = 0;
		attack = false;
	}
}
void enemyattack()
{
	enemyattackindex++;
	if (enemyattackindex == 10)
	{
		enemyattackindex = 0;
	}
}