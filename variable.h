int mposx, mposy;
bool homepage = true;
char enemyattackpic[40];
char enemywalkpic[40];
char storypic[40];
int sclength = 1263;
int scheight = 593;
int level = 0;
int playercorx = 350;
int playercory = 50;
int distancebetweenchar = 200;
int playerattackindex = 0;
int enemycorx = 700;
int enemycory = 20;
int enemyheight = 400;
int enemywidth = 400;
int enemyattackindex = 0;
bool onair = false;
int countjump = 0;
int jumpindex = 0;
int charheight = 300;
int charwidth = 300;
bool attack = false;
bool run = false;
int runindex = 0;
bool enemymove = false;
bool enemyfight = false;
int shieldindex = 0;
int playerhealthbarx;
int playerhealth = 300;
int enemyhealth = 300;
int enemyhealthbarx = 300;
int score=0;
bool gameon=true;
bool shield = true;
bool playerdead = false;
bool enemydead = false;
int enemydeathindex = 0;
int playerdeathindex = 0;
int enemywalkindex = 0;
bool story = true;
bool option = false;
bool control = false;
bool about = false;
int storynum = 1;
bool mute = false;
void new_level()
{
	playercorx = 350;
	playercory = 50;
	playerattackindex = 0;
	enemycorx = 700;
	enemycory = 20;
	enemyheight = 400;
	enemywidth = 400;
	enemyattackindex = 0;
	onair = false;
	countjump = 0;
	jumpindex = 0;
	charheight = 300;
	charwidth = 300;
	attack = false;
	run = false;
	runindex = 0;
	enemymove = false;
	enemyfight = false;
	shieldindex = 0;
	playerhealth = 300;
	enemyhealth = 300;
	playerhealthbarx=playerhealth;
	enemyhealthbarx = (300 / enemyhealth) * 300;
	gameon = true;
	shield = true;
}