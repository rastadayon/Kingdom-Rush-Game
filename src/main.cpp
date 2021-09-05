#include "../src/rsdl.hpp"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>     /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <ctime>

using namespace std;

#define level1Map "src/assets/levels/1/level1-map.png"
#define level2Map "src/assets/levels/2/level2-map.png"
#define YOU_WIN "src/assets/general/win.png"
#define YOU_LOSE "src/assets/general/lose.png"
#define lev1_width 800
#define lev1_height 800
#define delay 15

#define dot0x 760
#define dot0y 278
#define dot1x 537
#define dot1y 156
#define dot2x 429
#define dot2y 156

#define dot3x 477
#define dot3y 131
#define dot4x 393
#define dot4y 289
#define dot5x 247
#define dot5y 289
#define dot6x 201
#define dot6y 363
#define dot7x 247
#define dot7y 417
#define dot8x 443
#define dot8y 417
#define dot9x 497
#define dot9y 471
#define dot10x 467
#define dot10y 545
#define dot11x 359
#define dot11y 545
#define dot12x 359
#define dot12y 800



const int dotCoords1 [13][2]={{800,266},{561,266},{523,140},{417,140},{377,264},{233,264},{191,338},{251,394},{425,394},{485,456},{449,528},{351,528},{351,800}};
const int dotCoords2 [13][2]={{481,-30},{485,166},{247,166},{191,250},{239,306},{519,306},{585,394},{533,462},{321,462},{253,534},{309,596},{497,596},{497,800}};
#define archer_tower 'a'
#define cannon_tower 'c'
#define mage_tower 'm'
#define icy_tower 'i'

#define BALL_IMG "src/assets/general/Ball.png"

#define ARCHER_IMAGE "src/assets/towers/archer.png"
#define CANON_IMAGE "src/assets/towers/canon.png"
#define ICY_IMAGE "src/assets/towers/icy.png"
#define MAGE_IMAGE "src/assets/towers/mage.png"

#define ORC_RIGHT "src/assets/enemies/orc/right.png"
#define ORC_LEFT "src/assets/enemies/orc/left.png"
#define ORC_FRONT "src/assets/enemies/orc/front.png"
#define ORC_BACK "src/assets/enemies/orc/back.png"

#define ARMORED_RIGHT "src/assets/enemies/armored/right.png"
#define ARMORED_LEFT "src/assets/enemies/armored/left.png"
#define ARMORED_FRONT "src/assets/enemies/armored/front.png"
#define ARMORED_BACK "src/assets/enemies/armored/back.png"

#define WOLF_RIGHT "src/assets/enemies/wolf/right.png"
#define WOLF_LEFT "src/assets/enemies/wolf/left.png"
#define WOLF_FRONT "src/assets/enemies/wolf/front.png"
#define WOLF_BACK "src/assets/enemies/wolf/back.png"

#define DEMON_RIGHT "src/assets/enemies/demon/right.png"
#define DEMON_LEFT "src/assets/enemies/demon/left.png"
#define DEMON_FRONT "src/assets/enemies/demon/front.png"
#define DEMON_BACK "src/assets/enemies/demon/back.png"
#define enemy_size 40

int TOWERNUM=-7;
double total_time = 0;
const int Tower1Coords [8][2]= {{438,178},{299,193},{100,307},{256,333},{386,453},{310,479},{484,547},{392,591}};
const int Tower2Coords [8][2]= {{435,236},{347,236},{263,236},{461,380},{365,380},{547,564},{435,518},{337,522}};


const int tower1span [8][2][2]={{{451,204},{507,234}},{{311,212},{367,242}},{{111,326},{171,360}},{{267,356},{323,384}},{{397,474},{453,502}},{{319,500},{377,528}},{{497,568},{557,598}},{{405,610},{465,640}}};
const int tower2span [8][2][2]={{{443,260},{505,294}},{{357,262},{419,292}},{{269,260},{333,290}},{{467,408},{533,440}},{{375,408},{435,440}},{{557,592},{621,624}},{{443,544},{507,576}},{{345,550},{409,582}}};
struct ENEMIES
{
	string type="orc";
	double speed;
	int life;
	int points;
	int health;
	string shield;
	int x=800;
	int y=266;
	int dot=0;
	char direction = 'l';
	
};

struct user
{
	int life = 15;
	int money= 220;
	
};

user* user1 = new user();

struct arrow
{
	int x;
	int y;
	ENEMIES* who_to_follow;
	int harm;
	string bullet;
	bool icy_or_not= false;
	bool canon = false;
};

struct wave
{
	int number;
	string type;
	int time;
	bool attack=false;
};

struct towers
{
	char type;
	int x;
	int y;
	bool built= false;
	string attack;
	int time;
	int harm;
};

void initial_tower (vector <towers*> &V)
{
	for (int i = 0; i < V.size(); ++i)
	{
		V[i]=new towers;
	}
}
char processLastEvent(Event lastEvent) 
{
  if (lastEvent.type() == QUIT)
    exit(0);
  if (lastEvent.type() == KEY_PRESS) 
    return char(lastEvent.pressedKey());
}


void ifclicked(Event lastEvent, int level)
{
	if(lastEvent.type()==LCLICK)
	{
		int x,y;
		x=lastEvent.mouseX();
		y=lastEvent.mouseY();
		if(level==1){

			if(x>tower1span[0][0][0] && x<tower1span[0][1][0] && y>tower1span[0][0][1] && y< tower1span[0][1][1])
			{
				TOWERNUM=1;
				
			}
			if(x>tower1span[1][0][0] && x<tower1span[1][1][0] && y>tower1span[1][0][1] && y< tower1span[1][1][1])
			{
				TOWERNUM=2;
				
			}
			if(x>tower1span[2][0][0] && x<tower1span[2][1][0] && y>tower1span[2][0][1] && y< tower1span[2][1][1])
			{
				TOWERNUM=3;
				
			}
			if(x>tower1span[3][0][0] && x<tower1span[3][1][0] && y>tower1span[3][0][1] && y< tower1span[3][1][1])
			{
				TOWERNUM=4;
			}
			if(x>tower1span[4][0][0] && x<tower1span[4][1][0] && y>tower1span[4][0][1] && y< tower1span[4][1][1])
			{
				TOWERNUM=5;
				
			}
			if(x>tower1span[5][0][0] && x<tower1span[5][1][0] && y>tower1span[5][0][1] && y< tower1span[5][1][1])
			{
				TOWERNUM=6;
				
			}
			if(x>tower1span[6][0][0] && x<tower1span[6][1][0] && y>tower1span[6][0][1] && y< tower1span[6][1][1])
			{
				TOWERNUM=7;
				
			}
			if(x>tower1span[7][0][0] && x<tower1span[7][1][0] && y>tower1span[7][0][1] && y< tower1span[7][1][1])
				TOWERNUM=8;
		}


		if (level==2){
			
			if(x>tower2span[0][0][0] && x<tower2span[0][1][0] && y>tower2span[0][0][1] && y< tower2span[0][1][1])
				TOWERNUM=1;
			if(x>tower2span[1][0][0] && x<tower2span[1][1][0] && y>tower2span[1][0][1] && y< tower2span[1][1][1])
				TOWERNUM=2;
			if(x>tower2span[2][0][0] && x<tower2span[2][1][0] && y>tower2span[2][0][1] && y< tower2span[2][1][1])
				TOWERNUM=3;
			if(x>tower2span[3][0][0] && x<tower2span[3][1][0] && y>tower2span[3][0][1] && y< tower2span[3][1][1])
				TOWERNUM=4;
			if(x>tower2span[4][0][0] && x<tower2span[4][1][0] && y>tower2span[4][0][1] && y< tower2span[4][1][1])
				TOWERNUM=5;
			if(x>tower2span[5][0][0] && x<tower2span[5][1][0] && y>tower2span[5][0][1] && y< tower2span[5][1][1])
				TOWERNUM=6;
			if(x>tower2span[6][0][0] && x<tower2span[6][1][0] && y>tower2span[6][0][1] && y< tower2span[6][1][1])
				TOWERNUM=7;
			if(x>tower2span[7][0][0] && x<tower2span[7][1][0] && y>tower2span[7][0][1] && y< tower2span[7][1][1])
				TOWERNUM=8;
		}
	}
}


void update_towers(Event lastEvent,vector<towers*> &V ,Window* win,int level)
{
	if(lastEvent.type() == KEY_PRESS) {
		if(lastEvent.pressedKey() =='a') {
			if (user1->money >= 70)
			{

				user1->money -= 70;
				V[TOWERNUM-1]->built = true;
				V[TOWERNUM-1]->type = 'a';
				if (level==1){
					
				V[TOWERNUM-1]->x = Tower1Coords[TOWERNUM-1][0];
				V[TOWERNUM-1]->y = Tower1Coords[TOWERNUM-1][1];
				}
				if (level==2){
				V[TOWERNUM-1]->x = Tower2Coords[TOWERNUM-1][0];
				V[TOWERNUM-1]->y = Tower2Coords[TOWERNUM-1][1];
				}
			}

		}
		if(lastEvent.pressedKey() =='c') {
			if (user1->money >= 125)
			{
				user1->money -=125;
				V[TOWERNUM-1]->built = true;
				V[TOWERNUM-1]->type = 'c';
				if (level==1){
				V[TOWERNUM-1]->x = Tower1Coords[TOWERNUM-1][0];
				V[TOWERNUM-1]->y = Tower1Coords[TOWERNUM-1][1];
				}
				if (level==2){
				V[TOWERNUM-1]->x = Tower2Coords[TOWERNUM-1][0];
				V[TOWERNUM-1]->y = Tower2Coords[TOWERNUM-1][1];
				}
			}
		}
		if(lastEvent.pressedKey() =='i') {
			if (user1->money >= 80)
			{
				user1->money -=80;
				V[TOWERNUM-1]->built = true;
				V[TOWERNUM-1]->type = 'i';
				if (level==1){
				V[TOWERNUM-1]->x = Tower1Coords[TOWERNUM-1][0];
				V[TOWERNUM-1]->y = Tower1Coords[TOWERNUM-1][1];
				}
				if (level==2){
				V[TOWERNUM-1]->x = Tower2Coords[TOWERNUM-1][0];
				V[TOWERNUM-1]->y = Tower2Coords[TOWERNUM-1][1];
				}	
			}
		}
		if(lastEvent.pressedKey() =='m') {
			if (user1->money >= 90)
			{
				user1->money -=90;
				V[TOWERNUM-1]->built = true;
				V[TOWERNUM-1]->type = 'm';
				if (level==1){
				V[TOWERNUM-1]->x = Tower1Coords[TOWERNUM-1][0];
				V[TOWERNUM-1]->y = Tower1Coords[TOWERNUM-1][1];
				}
				if (level==2){
				V[TOWERNUM-1]->x = Tower2Coords[TOWERNUM-1][0];
				V[TOWERNUM-1]->y = Tower2Coords[TOWERNUM-1][1];
				}
			}
		}
	}
	
	for (int i = 0; i < V.size(); ++i)
	{
		if (V[i]->built==true)
		{
			if(V[i]->type=='a')
			{
				if (level==1)
					win->draw_png(ARCHER_IMAGE, Tower1Coords[i][0], Tower1Coords[i][1],80,60);
				if (level==2)
					win->draw_png(ARCHER_IMAGE, Tower2Coords[i][0], Tower2Coords[i][1],80,60);
			}
			if(V[i]->type=='c')
			{
				if (level==1)
					win->draw_png(CANON_IMAGE, Tower1Coords[i][0], Tower1Coords[i][1],80,60);
				if (level==2)
					win->draw_png(CANON_IMAGE, Tower2Coords[i][0], Tower2Coords[i][1],80,60);
			}
			if(V[i]->type=='m')
			{
				if (level==1)
					win->draw_png(MAGE_IMAGE, Tower1Coords[i][0], Tower1Coords[i][1],80,60);
				if (level==2)
					win->draw_png(MAGE_IMAGE, Tower2Coords[i][0], Tower2Coords[i][1],80,60);
			}
			if(V[i]->type=='i')
			{
				if (level==1)
					win->draw_png(ICY_IMAGE, Tower1Coords[i][0], Tower1Coords[i][1],80,60);
				if (level==2)
					win->draw_png(ICY_IMAGE, Tower2Coords[i][0], Tower2Coords[i][1],80,60);
			}
		}
	}


}
void draw_arrow (vector <arrow*> & arrows, Window* win)
{
	for (int i = 0; i < arrows.size(); ++i)
	{
		win->draw_png(BALL_IMG,arrows[i]->x,arrows[i]->y,6,6);
	}
}

void move_all_arrows(vector<arrow*> & arrows,vector <ENEMIES*> & enemy)
{
	for (int i = 0; i < arrows.size(); ++i)
	{
		int v_x = arrows[i] -> who_to_follow->x - arrows[i]->x;
		int v_y = arrows[i] -> who_to_follow->y - arrows[i]->y;
		if (v_x>0)
			arrows[i]->x +=10;
		else if(v_x<0)
			arrows[i]->x -=10;
		if (v_y >0)
			arrows[i]->y +=10;
		else if (v_y<0)
			arrows[i]->y -=10;
		if (v_y<2&& v_y>-2 && v_x <2&& v_x>-2)
		{ 
			
			

			if (arrows[i]->who_to_follow->shield == arrows[i]->bullet)
				arrows[i]->harm = arrows[i]->harm / 2;
			

			if (arrows[i]->icy_or_not)
			{
				for (int j = 0; j < enemy.size(); ++j)
				{
					if (enemy[j] != arrows[i]->who_to_follow)
					{
						if (sqrt((arrows[i]->who_to_follow->x-enemy[j]->x)^2+(arrows[i]->who_to_follow->y - enemy[j]->y)^2)<50)
						{
							enemy[j]->speed = enemy[j]->speed /2;
							enemy[j]->life -= arrows[i]->harm;
						}
					}
					else
					{
						arrows[i]->who_to_follow->speed = arrows[i]->who_to_follow->speed/2;
						arrows[i]->who_to_follow->life -= arrows[i]->harm;
					}
				}
			} 



			if (arrows[i]->canon == true)
			{
				for (int j = 0; j < enemy.size(); ++j)
				{
					if (enemy[j] != arrows[i]->who_to_follow)
					{
						if (sqrt((arrows[i]->who_to_follow->x-enemy[j]->x)^2+(arrows[i]->who_to_follow->y - enemy[j]->y)^2)<50)
						{
							enemy[j]->life -= arrows[i]->harm;
						}
					}
					else
					{
						arrows[i]->who_to_follow->life -= arrows[i]->harm;
					}
				}
			}
			else
			{
				arrows[i]->who_to_follow->life -= arrows[i]->harm;
				if (arrows[i]->who_to_follow->life<=0)
				{
					arrows[i]->x= -7;
					arrows[i]->y =-7;
				}
			}
			arrows.erase(arrows.begin()+i);
		}
	}

}

void run_arrow (int time,vector <towers*> &tower, vector <ENEMIES*> & enemy, vector <arrow*> &arrows)
{
	
	for (int i = 0; i < tower.size(); ++i)
	{
		if (tower[i]-> built == true)
		{
			if (tower[i]->type == 'a')
			{
				tower[i]->attack = "physical";
				if (!(time% 700))
				{
					for (int j = 0; j <enemy.size() ; j++)
					{
						if (sqrt((enemy[j]->x - tower[i]->x)^2 + (enemy[j]->y - tower[i]->y)^2)<85)
						{
							arrow* new_arrow = new arrow();
							new_arrow->x = tower[i]->x;
							new_arrow->y = tower[i]->y;
							new_arrow->who_to_follow =  enemy[j];
							new_arrow->bullet = "physical";
							new_arrow->harm = 50;
							arrows.push_back(new_arrow);
						}
					}
				}
			}
			else if(tower[i]->type == 'm')
			{
				tower[i]->attack = "magical";
				if (!(time% 1500))
				{
					for (int j = 0; j <enemy.size() ; j++)
					{
						if (sqrt((enemy[j]->x - tower[i]->x)^2 + (enemy[j]->y - tower[i]->y)^2)<85)
						{
							arrow* new_arrow = new arrow();
							new_arrow->x = tower[i]->x;
							new_arrow->y = tower[i]->y;
							new_arrow->who_to_follow =  enemy[j];
							new_arrow->bullet = "magical";
							new_arrow->harm = 140;
							arrows.push_back(new_arrow);
						}
					}
				}
			}
			else if (tower[i]->type =='c')
			{
				tower[i]->attack = "physical";
				if (!(time% 2000))
				{
					for (int j = 0; j <enemy.size() ; j++)
					{
						if (sqrt((enemy[j]->x - tower[i]->x)^2 + (enemy[j]->y - tower[i]->y)^2)<85)
						{
							arrow* new_arrow = new arrow();
							new_arrow->x = tower[i]->x;
							new_arrow->y = tower[i]->y;
							new_arrow->who_to_follow =  enemy[j];
							new_arrow->bullet = "physical";
							new_arrow ->canon = true;
							new_arrow->harm = 140;
							arrows.push_back(new_arrow);
						}
					}
				}
			}
			else if (tower[i]->type == 'i')
			{
				tower[i]->attack = "magical";
				if (!(time% 2000))
				{
					for (int j = 0; j <enemy.size() ; j++)
					{
						if (sqrt((enemy[j]->x - tower[i]->x)^2 + (enemy[j]->y - tower[i]->y)^2)<85)
						{
							arrow* new_arrow = new arrow();
							new_arrow->x = tower[i]->x;
							new_arrow->y = tower[i]->y;
							new_arrow-> icy_or_not = true;
							new_arrow->who_to_follow =  enemy[j];
							new_arrow->bullet = "magical";
							new_arrow->harm = 30;
							arrows.push_back(new_arrow);
						}
					}
				}
			}
		}
	}
	move_all_arrows(arrows,enemy);
}

void update_waves(vector<wave>& waves, vector<ENEMIES*>& enemies, int level) {
	while(!waves.empty() && waves[0].time < total_time) 
	{
		for(int i = 0; i < waves[0].number; i++) {
			
				ENEMIES* enemy = new ENEMIES();
				if (waves[0].type == "orc")
				{
					enemy->type = "orc";
					if (level==1){
						enemy->x=dotCoords1[0][0]+10*i;
						enemy->y=dotCoords1[0][1]+(-1)^i*20*i;
					}
					else if (level==2){
						enemy->x=dotCoords2[0][0]+10*i;
						enemy->y=dotCoords2[0][1]+(-1)^i*20*i;
					}
					enemy->speed=4;
					enemy->life=200;
					enemy->health = 1;
					enemy -> shield ="no shield";
					enemy -> points= 5;
				}
				else if (waves[0].type == "armored")
				{
					enemy->type = "armored";
					if (level==1){
						enemy->x=dotCoords1[0][0]+10*i;
						enemy->y=dotCoords1[0][1]+(-1)^i*20*i;
					}
					else if (level==2){
						enemy->x=dotCoords2[0][0]+10*i;
						enemy->y=dotCoords2[0][1]+(-1)^i*20*i;
					}
					enemy->speed=2;
					enemy->life=450;
					enemy->health = 3;
					enemy -> shield = "physical";
					enemy -> points= 8;
				}
				else if (waves[0].type == "wolf")
				{
					enemy->type = "wolf";
					if (level==1){
						enemy->x=dotCoords1[0][0]+10*i;
						enemy->y=dotCoords1[0][1]+(-1)^i*20*i;
					}
					else if (level==2){
						enemy->x=dotCoords2[0][0]+10*i;
						enemy->y=dotCoords2[0][1]+(-1)^i*20*i;
					}
					enemy->speed=8;
					enemy->life=100;
					enemy->health = 1;
					enemy -> shield ="no shield";
					enemy -> points= 2;
				}
				else if (waves[0].type == "demon")
				{
					enemy->type = "demon";
					if (level==1){
						enemy->x=dotCoords1[0][0]+10*i;
						enemy->y=dotCoords1[0][1]+(-1)^i*20*i;
					}
					else if (level==2){
						enemy->x=dotCoords2[0][0]+10*i;
						enemy->y=dotCoords2[0][1]+(-1)^i*20*i;
					}
					enemy->speed=2.66666666666666;
					enemy->life=400;
					enemy->health = 3;
					enemy -> shield ="magical";
					enemy -> points= 8;
				}
				enemies.push_back(enemy);
			}
		
		waves.erase(waves.begin());
	}
}


void getAndProcessInput(Event event)
{
  	char key = processLastEvent(event);
}




void move_all_enemies (vector<ENEMIES*> &enemy, int level)
{
	for (int i = 0; i < enemy.size(); ++i)
	{
		
		if (enemy[i]->life<=0)
		{
			user1->money += enemy[i]->points;
			enemy.erase(enemy.begin() + i);
		}
		else
		{
			float v_x, v_y;
			float size;
			if (level==1){
				v_x = dotCoords1 [enemy [i]->dot][0] - enemy [i]->x;
				v_y = dotCoords1 [enemy [i]->dot][1] - enemy [i]->y;
				size = sqrt(v_x* v_x + v_y*v_y);
				if (size<=4) {
					enemy [i]->dot ++;
					if(enemy [i]->dot == 13) {
						enemy [i]->dot--;
					}
				}
				else {
					v_x = v_x /size * enemy [i]->speed;
					v_y = v_y /size * enemy [i]->speed;	
				}
			}
			else if (level==2){
				v_x = dotCoords2 [enemy [i]->dot][0] - enemy [i]->x;
				v_y = dotCoords2 [enemy [i]->dot][1] - enemy [i]->y;
				size = sqrt(v_x* v_x + v_y*v_y);
				if (size<=4) {
					enemy [i]->dot ++;
					if(enemy [i]->dot == 13) {
						enemy [i]->dot--;
					}
				}
				else {
					v_x = v_x /size * enemy [i]->speed;
					v_y = v_y /size * enemy [i]->speed;	
				}
			}
				if (enemy[i]->dot ==1 && level == 2)
					enemy[i]->direction = 'f';
				else if (v_x == 0)
				{
					if(v_y > 0)
						enemy [i]->direction = 'f';
					if(v_y <=0)
						enemy [i]->direction ='b';
				}
				else
				{
					if (v_x>0)
						enemy [i]->direction = 'r';
					else
						enemy [i]->direction = 'l';
				}
				enemy [i]->x += v_x;
				enemy [i]->y += v_y;

				if (enemy[i]->y >= lev1_height)
				{
					user1 -> life -= enemy[i]-> health;
					enemy.erase(enemy.begin() + i);
				}
			
		}
	}
	

}

void draw_enemy_vec (vector <ENEMIES*> &V, Window * win)
{
	for (int i = 0; i < V.size(); i++)
	{	
		if (V[i]->type == "orc" && V[i]->direction =='r')
			win->draw_png(ORC_RIGHT,V[i]->x, V[i]->y,enemy_size,enemy_size);
		else if (V[i]->type == "orc" && V[i]->direction =='l')
			win->draw_png(ORC_LEFT,V[i]->x, V[i]->y,enemy_size,enemy_size);
		else if (V[i]->type == "orc" && V[i]->direction =='f')
			win->draw_png(ORC_FRONT,V[i]->x, V[i]->y,enemy_size,enemy_size);
		else if (V[i]->type == "orc" && V[i]->direction =='b')
			win->draw_png(ORC_BACK,V[i]->x, V[i]->y,enemy_size,enemy_size);

		else if (V[i]->type == "armored" && V[i]->direction =='r')
			win->draw_png(ARMORED_RIGHT,V[i]->x, V[i]->y,enemy_size,enemy_size);
		else if (V[i]->type == "armored" && V[i]->direction =='l')
			win->draw_png(ARMORED_LEFT,V[i]->x, V[i]->y,enemy_size,enemy_size);
		else if (V[i]->type == "armored" && V[i]->direction =='f')
			win->draw_png(ARMORED_FRONT,V[i]->x, V[i]->y,enemy_size,enemy_size);
		else if (V[i]->type == "armored" && V[i]->direction =='b')
			win->draw_png(ARMORED_BACK,V[i]->x, V[i]->y,enemy_size,enemy_size);

		else if (V[i]->type == "wolf" && V[i]->direction =='r')
			win->draw_png(WOLF_RIGHT,V[i]->x, V[i]->y,enemy_size,enemy_size);
		else if (V[i]->type == "wolf" && V[i]->direction =='l')
			win->draw_png(WOLF_LEFT,V[i]->x, V[i]->y,enemy_size,enemy_size);
		else if (V[i]->type == "wolf" && V[i]->direction =='f')
			win->draw_png(WOLF_FRONT,V[i]->x, V[i]->y,enemy_size,enemy_size);
		else if (V[i]->type == "wolf" && V[i]->direction =='b')
			win->draw_png(WOLF_BACK,V[i]->x, V[i]->y,enemy_size,enemy_size);

		else if (V[i]->type == "demon" && V[i]->direction =='r')
			win->draw_png(DEMON_RIGHT,V[i]->x, V[i]->y,enemy_size,enemy_size);
		else if (V[i]->type == "demon" && V[i]->direction =='l')
			win->draw_png(DEMON_LEFT,V[i]->x, V[i]->y,enemy_size,enemy_size);
		else if (V[i]->type == "demon" && V[i]->direction =='f')
			win->draw_png(DEMON_FRONT,V[i]->x, V[i]->y,enemy_size,enemy_size);
		else if (V[i]->type == "demon" && V[i]->direction =='b')
			win->draw_png(DEMON_BACK,V[i]->x, V[i]->y,enemy_size,enemy_size);
	}
}
void draw_map (Window* win,int level)
{
	if (level==1)
		win->draw_png(level1Map, 0, 0,lev1_width,lev1_height);
	else if(level==2)
		win->draw_png(level2Map, 0, 0,lev1_width,lev1_height);
}

int if_game_over (vector <wave> &waves,vector <ENEMIES*> & enemy)
{
	if(user1->life <=0)
	{
		cout<<"game over, YOU LOSE!"<<endl;
		return 2;
	}
	else if(total_time>5 && waves.empty() && enemy.empty()&& user1->life>=0)
	{
		return 1;
	}
	else 
		return 0;
}



int main() {
	int temp_life = user1->life, temp_money=user1->money;
	cout <<user1->life <<":life           "<<user1->money<<":money"<<endl;
	double ms_time=0;
	Window * win = new Window(lev1_width, lev1_height, "ma game");
	vector <wave> waves;
	int time,number,level;
	string str;
	cin>>level;
	while (cin >> time && cin >> number && cin >> str)
	{
		wave w;
		w.time = time;
		w.number = number;
		w.type = str;
		waves.push_back(w);
	}
	vector <ENEMIES*> enemy;
	vector <towers*> towerVec (8);
	initial_tower(towerVec);
	vector<ENEMIES*> enemies;
	vector <arrow*> arrows;


	while (true)
	{

		ms_time+=75;
		total_time += 0.075;
		
		if (temp_money!=user1->money || temp_life!=user1->life)
		{
			cout <<user1->life <<":life           "<<user1->money<<":money"<<endl;
		}
		temp_life = user1->life;
		temp_money = user1->money;
		Event event = win->pollForEvent();
		if (event.pressedKey() == 'q')
			return 0;
	 	getAndProcessInput(event);
	 	update_waves(waves,enemies,level);
	 	win->clear();
		draw_map(win,level);
		move_all_enemies(enemies,level);
		draw_enemy_vec(enemies,win); //tick
		ifclicked(event,level);
		update_towers(event,towerVec,win,level);
		run_arrow(ms_time,towerVec,enemies,arrows);
		draw_arrow(arrows,win); //tick
		if(if_game_over(waves, enemies)!= 0)
			break;
		win->update_screen();
		Delay(75);
	} 
	double temp = total_time;
	while (true)
	{
		total_time +=0.075;
		if(total_time-temp>=10.0)
			break;
		if (if_game_over(waves,enemies)==1){
			win->draw_png(YOU_WIN,0,0,lev1_width,lev1_height);
				
		}
		if (if_game_over(waves,enemies)==2)
		{
			win->draw_png(YOU_LOSE,0,0,lev1_width,lev1_height);
		}
		win->update_screen();
		Delay(delay);
	}
}

