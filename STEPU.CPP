/// Header Files
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
#include<iostream.h>

/// Functions Declaration
void frontPage();
void ruleBook();
void createwindo(int, int, int, int, int, char);
void bcreate(int, int, int, int, int);
void board();
void getimg();
char gamePlay();
void diceRoll();
void score(int);
void move(int);
void displayMove(int);
int task(int);
void cut();
void won();

int mn, s1 = 0, s2 = 0, ps = 63, ps1 = 63, pl, unfair = 1, a1, b1, a3, b3, j1, k1, j11, k11;
int x40, y40, w40, z40, u1 = -1, u2 = -1;
char score1[3], score2[3];
void *x, *x1, *x2, *x3, *d, *s8;

int main()
{
	clrscr();
	randomize();
	int gdriver = DETECT, gmode;
	char user;
	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
	x40 = 0;
	y40 = 0;
	w40 = getmaxx();
	z40 = getmaxy();
	frontPage();
	ruleBook();
	do
	{
		createwindo(x40, y40, w40, z40, 9, ' ');
		board();
		getimg();
		while(s1<55 || s2<55)
		{
			user = gamePlay();
			if(s1 >= 55 || s2 >= 55)
				break;
			else if(user == 'n'|| user == 'N')
			{
				s1 = 0;
				s2 = 0;
				mn = 0;
				ps = 63;
				ps1 = 63;
				break;
			}
			else if(user == 'e' || user == 'E')
				break;
			else if(unfair<0)
				break;
		}
	}while(user == 'n' || user == 'N');
	clrscr();
	cleardevice();
	if(s1 >= 55 || s2 >= 55){
		won();
	}
	closegraph();
	cout<<"\n Thanks";
	getch();
	return 0;
}

void frontPage()
{
	setfillstyle(1, 10);   /// Light Green
	setcolor(15);  /// White
	rectangle(76, 228, 552, 257);
	setcolor(0);   /// Black
	for(int i = 100; i <= 550; i += 35)
	{
		bar(78, 230, i, 255);
		outtextxy(235, 240, "Processing...");
		delay(150);
		setcolor(10);
		outtextxy(235, 240, "Processing...");
		delay(170);
		setcolor(0);
		delay(110);
	}
}

void ruleBook()
{
	int y = 130;
	char a[] = "The";
	setfillstyle(1, 8);   /// Dark Grey
	bar(0, 0, getmaxx(), getmaxy());
	setcolor(14);   /// Yellow
	rectangle(50, 120, 600, 250);
	setfillstyle(1, 14);
	rectangle(350, 127, 390, 140);
	setcolor(11);   /// Light Cyan
	settextstyle(4, 0, 7);
	outtextxy(150, 10, "Rule  Book");
	settextstyle(0, 0, 0);
	setcolor(15);
	outtextxy(60, y, "1. The First person to reach 55 will WIN.");
	y += textheight(a);
	y += textheight(a);
	y += textheight(a);
	outtextxy(60, y, "2. There are certain hidden task on some numbers that you will");
	y += textheight(a);
	y += 2;
	outtextxy(84, y, "get to know when you land on them.");
	y += textheight(a);
	y += textheight(a);
	y += textheight(a);
	outtextxy(60, y, "3. No Cheating is allowed like you can't play again and again");
	y += textheight(a);
	y += 2;
	outtextxy(82, y, "and not letting other player to play if you do so you will lose.");
	y += textheight(a);
	y += textheight(a);
	y += textheight(a);
	outtextxy(60, y, "4. If you want, you can quit or start the game again any time");
	y += textheight(a);
	y += 2;
	outtextxy(84, y, "but the condition in it is that both the player should agree.");
	setcolor(11);
	settextstyle(3, 0, 2);
	outtextxy(70, 432, "Press any key to continue");
	getch();
	cleardevice();
}

void createwindo(int x,  int y,  int w,  int z,  int color,  char queryInput)
{
	setcolor(8);   // Dark Grey
	rectangle(x, y, w, z);
	setcolor(7);   // Light Grey
	setfillstyle(SOLID_FILL, 8);
	rectangle(x+1, x+1, w-1, z-1);
	floodfill(x+3, y+3, 7);
	setcolor(7);
	setfillstyle(SOLID_FILL, color);   // Light Blue
	rectangle(x+30, y+30, w-20, z-20);
	floodfill(x+32, y+32, 7);
	setcolor(BLACK);
	line(x+30, y+30, x+30, z-20);
	line(x+31, y+31, x+31, z-19);
	setfillstyle(SOLID_FILL, 8);
	settextstyle(DEFAULT_FONT, 0, 1);
	setcolor(0);
	rectangle(249, 7, 366, 22);
	setcolor(15);
	rectangle(250, 8, 365, 21);
	rectangle(248, 6, 367, 23);
	setfillstyle(1, 0);
	floodfill(307, 13, 15);
	outtextxy(260, 12, "Rolling Dice");
	
	// NEW / EXIT Game Button
	settextstyle(SMALL_FONT, 0, 4);
	setcolor(2);   // Green
	bcreate(500, 53, 600, 85, 15);
	bcreate(500, 90, 600, 120, 15);

	// DISPLAY Board
	bcreate(465, 340, 612, 452, 0);

	// SCORE Board
	bcreate(460, 275, 510, 317, 0);
	bcreate(555, 275, 605, 317, 0);

	// Dice TRAY
	settextstyle(0, 0, 0);
	setcolor(0);
	line(526, 190, 596, 190);
	line(526, 190, 465, 209);
	line(596, 190, 535, 209);
	rectangle(465, 209, 535, 216);
	line(535, 216, 596, 196);
	line(596, 190, 596, 196);
	setfillstyle(5, 3);
	floodfill(473, 214, 0);
	setfillstyle(4, 3);
	floodfill(541, 210, 0);
	setfillstyle(9, 11);
	floodfill(524, 200, 0);
	
	// DICE on Board
	setcolor(15);
	setfillstyle(1, 12);
	rectangle(507, 150, 559, 191);
	bar(508, 151, 558, 190);
	rectangle(497, 157, 549, 198);
	bar(498, 158, 548, 197);
	line(507, 150, 497, 157);
	line(549, 157, 559, 150);
	line(559, 191, 549, 198);
	floodfill(504, 155, 15);
	floodfill(551, 193, 15);
	setcolor(12);
	line(550, 191, 558, 191);
	line(507, 151, 507, 156);
	
	// Score Board
	setcolor(0);
	outtextxy(490, 240, "SCORE BOARD");
	outtextxy(457, 256, "PLAYER 1");
	outtextxy(546, 256, "PLAYER 2");

	// SCORE Board
	line(533, 253, 533, 328);
	rectangle(450, 235, 612, 328);
	int y9  =  imagesize(470, 283, 500, 300);
	s8 = malloc(y9);
	getimage(470, 283, 500, 300, s8);
	setcolor(15);
	if(queryInput == 'r' || queryInput == 'R')
	{
		sprintf(score1, "%d", s1);
		sprintf(score2, "%d", s2);
		outtextxy(480, 293, score1);
		outtextxy(575, 293, score2);
	}
	else 
	{
		outtextxy(480, 293, "0");
		outtextxy(575, 293, "0");
	}
	
	setcolor(0);
	outtextxy(511, 65, "NEW GAME");
	outtextxy(510, 103, "EXIT GAME");
}

void bcreate(int x, int y, int w, int z, int color)
{
	setcolor(7);
	rectangle(x, y, w, z);
	setcolor(8);
	setfillstyle(SOLID_FILL, 8);
	rectangle(x+1, y+1, w, z);
	floodfill(x+5, y+5, 8);
	setfillstyle(SOLID_FILL, color);
	bar(x+5, y+5, w-5, z-5);
}

void board()
{
	int i, j, x = 0, y = 0;
	char cc[3], num = 0;
	int m = 0;
	setfillstyle(1, 2);   // Green
	bar(61, 61, 439, 439);
	setcolor(0);
	rectangle(60, 60, 440, 440);
	// Vertical line
	line(98, 60, 98, 440);
	line(134, 60, 134, 98);
	line(134, 134, 134, 362);
	line(172, 60, 172, 98);
	line(210, 60, 210, 98);
	line(210, 324, 210, 362);
	line(248, 324, 248, 362);
	line(286, 324, 286, 362);
	line(324, 324, 324, 362);
	line(248, 60, 248, 98);
	line(286, 60, 286, 98);
	line(324, 60, 324, 98);
	line(134, 400, 134, 440);
	line(172, 134, 172, 362);
	line(172, 400, 172, 440);
	line(210, 134, 210, 172);
	line(210, 210, 210, 286);
	line(210, 400, 210, 440);
	line(248, 134, 248, 172);
	line(248, 210, 248, 286);
	line(248, 400, 248, 440);
	line(286, 134, 286, 286);
	line(286, 400, 286, 440);
	line(324, 134, 324, 286);
	line(324, 400, 324, 440);
	line(362, 60, 362, 362);
	line(362, 400, 362, 440);
	line(400, 60, 400, 362);
	line(400, 400, 400, 440);
	
	// Horizontal line
	line(60, 98, 400, 98);
	line(134, 134, 324, 134);
	line(60, 134, 98, 134);
	line(134, 172, 324, 172);
	line(60, 172, 98, 172);
	line(210, 210, 248, 210);
	line(286, 210, 324, 210);
	line(60, 210, 98, 210);
	line(210, 248, 324, 248);
	line(134, 248, 172, 248);
	line(134, 210, 172, 210);
	line(134, 286, 172, 286);
	line(362, 286, 400, 286);
	line(362, 210, 400, 210);
	line(362, 134, 400, 134);
	line(362, 248, 400, 248);
	line(362, 172, 400, 172);
	line(286, 248, 324, 248);
	line(60, 248, 98, 248);
	line(210, 286, 324, 286);
	line(60, 286, 98, 286);
	line(134, 324, 400, 324);
	line(60, 324, 98, 324);
	line(134, 362, 400, 362);
	line(60, 362, 98, 362);
	line(60, 400, 440, 400);
	settextstyle(0, 0, 0);
	setfillstyle(1, 15);
	x = 73;
	y = 76;
	m = 2;
	
	for(i = 0; i<10; i++)
	{
		for(j = 0; j<10; j++)
		{
			if(m == 2)
			{
				if(j%2)
				floodfill(x, y, 0);
			}
			else if(!(j%2))
				floodfill(x, y, 0);
			x += 38;
		}
		if(m == 3)
			m = 2;
		else
			m = 3;
			
		x = 73;
		y += 38;
	}
	x = 424;
	y = 418;
	num = 1;
	for(i = 0; i<10; i++)
	{
		sprintf(cc, "%d", num);
		num++;
		outtextxy(x, y, cc);
		x -= 38;
	}
	x += 38;
	y = 382;
	for(i = 0; i<9; i++)
	{
		sprintf(cc, "%d", num);
		num++;
		outtextxy(x, y, cc);
		y -= 37;
	}
	x = 101;
	y += 38;
	for(i = 0; i<8; i++)
	{
		sprintf(cc, "%d", num);
		num++;
		outtextxy(x, y, cc);
		x += 38;
	}
	x -= 39;
	y = 113;
	for(i = 0; i<7; i++)
	{
		sprintf(cc, "%d", num);
		num++;
		outtextxy(x, y, cc);
		y += 38;
	}
	x = 345;
	y -= 38;
	for(i = 0; i<6; i++)
	{
		sprintf(cc, "%d", num);
		num++;
		outtextxy(x, y, cc);
		x -= 38;
	}
	x += 38;
	y = 302;
	for(i = 0; i<5; i++)
	{
		sprintf(cc, "%d", num);
		num++;
		outtextxy(x, y, cc);
		y -= 38;
	}
	x = 192;
	y += 38;
	for(i = 0; i<4; i++)
	{
		sprintf(cc, "%d", num);
		num++;
		outtextxy(x, y, cc);
		x += 38;
	}
	x -= 38;
	y = 190;
	for(i = 0; i<3; i++)
	{
		sprintf(cc, "%d", num);
		num++;
		outtextxy(x, y, cc);
		y += 38;
	}
	x = 268;
	y -= 38;
	for(i = 0; i<2; i++)
	{
		sprintf(cc, "%d", num);
		num++;
		outtextxy(x, y, cc);
		x -= 38;
	}
	sprintf(cc, "%d", 55);
	outtextxy(223, 220, cc);
	setcolor(1);
	setfillstyle(1, 1);
	floodfill(380, 397, 0);
}

void getimg()
{
	int y, y1, y2, y3, d1;
	setfillstyle(1, 4);   // Red Player
	bar(450, 405, 460, 415);
	setfillstyle(1, 1);   // Blue Player
	bar(450, 428, 460, 438);
	y = imagesize(450, 405, 460, 415);
	y1 = imagesize(420, 405, 430, 415);
	y2 = imagesize(380, 405, 390, 415);
	y3 = imagesize(450, 428, 460, 438);
	d1 = imagesize(519, 172, 535, 187);
	x = malloc(y);
	x1 = malloc(y1);
	x2 = malloc(y2);
	x3 = malloc(y3);
	d = malloc(d1);
	getimage(420, 405, 430, 415, x1);//green
	getimage(380, 405, 390, 415, x2);//white
	getimage(450, 405, 460, 415, x);//red
	getimage(450, 428, 460, 438, x3);//blue
	getimage(519, 172, 535, 187, d);//dice no.
}

char gamePlay()
{
	char z[]="The";
	int input, movefinish=1, flag;
    do
    {
		setcolor(15);
		flag=1;
		setfillstyle(1, 0);
		bar(470, 351, 607, 447);
		outtextxy(471, 352, "Player 1 Chance");
		outtextxy(471, 364, "Press k or K");
		outtextxy(471, 394, "Press E/e to Exit");
		outtextxy(471, 406, "Press R/r for");
		int s =406 + textheight(z);
		outtextxy(565, s, "rules");
		outtextxy(471, 424, "Press N/n for");
		s = 424 + textheight(z);
		outtextxy(543, s+3, "New Game");
		
		input=getch();   // Take input
		if(input == 'k' || input == 'K')
		{
			pl=1;
			flag=0;
			diceRoll();
			score(pl);
			if(s1 >= 55)
				flag=0;
			else if(s1==5 || s1==9 || s1==10 || s1==17 || s1==23 || s1==25 || s1==29 || s1==34 || s1==37 || s1==43 || s1==46 || s1==51 || s1==54)
			{
				displayMove(pl);
				if(s1 == 29 || s1 == 46)
					u1=1;
				task(pl);
				move(pl);
			}
			else if(s1 == 30)
			{
				displayMove(pl);
				flag=1;
			}
			if(((s2 == 17) || (u2 == 1)) && (movefinish == 1))
			{
				movefinish=0;
				flag=1;
				u2=-1;
			}
			else if(((s2 == 25) || (u2 >= 0)) && (movefinish >= 0))
			{
				movefinish--;
				flag=1;
				u2--;
			}
			if(s1 == s2)
				cut();
		}
		else if(input == 'e' || input == 'E')
			return input;
		else if(input == 'r' || input == 'R')
		{
			cleardevice();
			ruleBook();
			createwindo(x40, y40, w40, z40, 9, input);
			board();
			putimage(j1, k1, x, 0);
			putimage(j11, k11, x3, 0);
		}
		else if(input=='n' || input=='N')
			return input;
		else if(input=='l' || input=='L')
		{
			cout<<"\a";
			if(unfair >= 0)
			{
				setfillstyle(1, 0);
				bar(470, 351, 607, 447);
				outtextxy(471, 352, "//INLEGAL MOVE//");
				outtextxy(471, 362, "Player 1 chance");
				outtextxy(471, 372, "not player 2.");
				outtextxy(471, 400, "You will LOOSE if");
				outtextxy(471, 411, "you do it again");
				outtextxy(471, 438, "Press any key");
				getch();
				unfair--;
			}
		}
	}while(flag);
	
	if((s1<55) && (unfair >= 0))
	{
		movefinish=1;
		unfair=1;
		flag=1;
		do
		{
			setfillstyle(1, 0);
			bar(470, 351, 607, 447);
			outtextxy(471, 352, "Player 2 Chance");
			outtextxy(471, 364, "Press l or L");
			outtextxy(471, 394, "Press E/e to Exit");
			outtextxy(471, 406, "Press R/r for");
			int s = 406 + textheight(z);
			outtextxy(565, s, "rules");
			outtextxy(471, 424, "Press N/n for");
			s = 424 + textheight(z);
			outtextxy(543, s+3, "New Game");
		
			input = getch();
			if(input == 'l' || input == 'L')
			{
				pl=2;
				flag=0;
				diceRoll();
				score(pl);
				if(s2 >= 55)
					flag=0;
		
				else if(s2==5 || s2==9 || s2==10 || s2==17 || s2==23 || s2==25 || s2==29 || s2==34 || s2==37 || s2==43 || s2==46 || s2==51 || s2==54)
				{
					displayMove(pl);
					if(s2 == 29 || s2 == 46)
						u2=1;
					task(pl);
					move(pl);
				}
				else if(s2 == 30)
				{
					displayMove(pl);
					flag=1;
				}
				if(((s1 == 17) || (u1 == 1)) && (movefinish == 1))
				{
					movefinish=0;
					flag=1;
					u1=-1;
				}
				else if(((s1 == 25) || (u1 >= 0)) && (movefinish >= 0))
				{
					movefinish--;
					flag=1;
					u1--;
				}
				if(s2 == s1)
					cut();
			}
			else if(input=='e' || input=='E')
				return input;
			else if(input=='r' || input=='R')
			{
				cleardevice();
				ruleBook();
				createwindo(x40, y40, w40, z40, 9, input);
				board();
				putimage(j1, k1, x, 0);
				putimage(j11, k11, x3, 0);
				setcolor(15);
			}
			else if(input=='n' || input=='N')
				return input;
			else if(input=='k' || input=='K')
			{
				cout<<"\a";
				if(unfair >= 0)
				{
					setfillstyle(1, 0);
					bar(470, 351, 607, 447);
					outtextxy(471, 352, "//INLEGAL MOVE//");
					outtextxy(471, 362, "Player 2 chance");
					outtextxy(471, 372, "not player 1.");
					outtextxy(471, 400, "You will LOOSE if");
					outtextxy(471, 411, "you do it again");
					outtextxy(471, 438, "Press any key");
					getch();
					unfair--;
				}
			}
		}while(flag);
	}
	return 0;
}

void diceRoll()
{
	int x1 = 517, y1 = 173;
	mn = random(6) + 1;
	setcolor(1);
	settextstyle(0, 0, 2);
    if(mn == 1)
    {
       putimage(x1-1, y1-1, d, 0);
       outtextxy(x1, y1, "1");
    }
	if(mn == 2)
	{
		putimage(x1-1, y1-1, d, 0);
		outtextxy(x1, y1, "2");
	}
	if(mn == 3)
	{
		putimage(x1-1, y1-1, d, 0);
		outtextxy(x1, y1, "3");
	}
	if(mn == 4)
	{
		putimage(x1-1, y1-1, d, 0);
		outtextxy(x1, y1, "4");
	}
	if(mn == 5)
	{
		putimage(x1-1, y1-1, d, 0);
		outtextxy(x1, y1, "5");
	}
	if(mn == 6)
	{
		putimage(x1-1, y1-1, d, 0);
		outtextxy(x1, y1, "6");
	}
	settextstyle(0, 0, 0);
}

void score(int h)
{
	if(h == 1)
	{
		s1 += mn;
		move(h);
	}
	else if(h == 2)
	{
		s2 += mn;
		move(h);
	}
}

void move(int p)
{
	char sc[3];
	if(p == 1)
	{
		if(ps%2 == 1 && ps < 61)
			putimage(j1, k1, x1, 0);
		else if(ps%2 == 0 && ps < 61 && ps != 0)
			putimage(j1, k1, x2, 0);
			
		setcolor(15);
		putimage(470, 287, s8, 0);
		sprintf(sc, "%d", s1);
		outtextxy(483, 293, sc);
	
		if((s1 >= 1) && (s1 <= 10))
		{
			a1 = 405;
			b1 = 405;
			if(s1 != 1)
			{
				int i = 37 * (s1-1);
				putimage(a1-i, b1, x, 0);
				j1 = a1-i;
				k1 = b1;
			}
			else
			{
				putimage(a1, b1, x, 0);
				j1 = a1;
				k1 = b1;
			}
		}
		else if((s1 >= 11) && (s1 <= 19))
		{
			a1 = 65;
			int i = 38 * (s1-10);
			putimage(a1, b1-i, x, 0);
			j1 = a1;
			k1 = b1-i;
		
		}
		else if((s1 >= 20) && (s1 <= 27))
		{
			a1 = 100;
			b1 = 66;
			if(s1 != 20)
			{
				int i = 38 * (s1-20);
				putimage(a1+i, b1, x, 0);
				j1 = a1+i;
				k1 = b1;
			}
			else
			{
				putimage(a1, b1, x, 0);
				j1 = a1;
				k1 = b1;
			}
		}
		else if((s1 >= 28) && (s1 <= 34))
		{
			a1 = 387;
			b1 = 122;
			if(s1 == 29)
			{
				int i = 37;
				putimage(a1, b1+i, x, 0);
				j1 = a1;
				k1 = b1+i;
			
			}
			else if((s1 != 30) && s1 <= 34)
			{
			
				float i = 38 * (s1-28);
				putimage(a1, b1+i, x, 0);
				j1 = a1;
				k1 = b1+i;
			}
			else if(s1 == 28)
			{
				putimage(a1, b1, x, 0);
				j1 = a1;
				k1 = b1;
			}
			else if(s1 == 30)
			{
				int i = 37 * 2;
				putimage(a1, b1+i, x, 0);
				j1 = a1;
				k1 = b1+i;
			}
		}
		else if((s1 >= 35) && (s1 <= 40))
		{
			a1 = 332;
			b1 = 329;
			if(s1 != 35 && s1 != 40)
			{
				int i = 39 * (s1-35);
				putimage(a1-i, b1, x, 0);
				j1 = a1-i;
				k1 = b1;
			}
			else if(s1 == 40)
			{
				int i = 39 * 5;
				putimage(a1-i, b1, x, 0);
				j1 = a1-i;
				k1 = b1;
			}
			else if(s1 == 35)
			{
				putimage(a1, b1, x, 0);
				j1 = a1;
				k1 = b1;
			}
		}
		else if((s1 >= 41) && (s1 <= 45))
		{
			a1 = 137;
			b1 = 327;
			
			int i = 37 * (s1-40);
			putimage(a1, b1-i, x, 0);
			j1 = a1;
			k1 = b1-i;
		}
		else if((s1 >= 46) && (s1 <= 49))
		{
			a1 = 142;
			b1 = 138;
		
			int i = 37 * (s1-45);
			putimage(a1+i, b1, x, 0);
			j1 = a1+i;
			k1 = b1;
		}
		else if((s1 >= 50) && (s1 <= 52))
		{
			a1 = 291;
			b1 = 198;
		
			if(s1 != 50)
			{
				int i = 37 * (s1-50);
				putimage(a1, b1+i, x, 0);
				j1 = a1;
				k1 = b1+i;
			}
			else
			{
				putimage(a1, b1, x, 0);
				j1 = a1;
				k1 = b1;
			}
		}
		else if((s1 >= 53) && (s1 <= 54))
		{
		
			if(s1 == 53)
			{  
				a1 = 253;
				b1 = 423;
				int i = 57 * (s1-50);
				putimage(a1, b1-i, x, 0);
				j1 = a1;
				k1 = b1-i;
			}
			else if(s1 == 54)
			{
				a1 = 214;
				b1 = 270;
				putimage(a1, b1, x, 0);
				j1 = a1;
				k1 = b1;
			}
		}
		else if(s1 >= 55)
		{
			a1 = 217;
			b1 = 235;
			putimage(a1, b1, x, 0);
			delay(500);
		}
		ps = s1;
	}

	else if(p == 2)
	{
		a3 = 407;
		b3 = 426;
		if(ps1%2 == 1 && ps1 < 61)
			putimage(j11, k11, x1, 0);
		else if(ps1%2 == 0 && ps1 < 61 && ps1 != 0)
			putimage(j11, k11, x2, 0);
		
		setcolor(15);
		putimage(565, 287, s8, 0);
		sprintf(sc, "%d", s2);
		outtextxy(577, 293, sc);
		if((s2 >= 1) && (s2 <= 10))
		{
			if(s2 != 1)
			{
				int i = 38 * (s2-1);
				putimage(a3-i, b3, x3, 0);
				j11 = a3-i;
				k11 = b3;
			}
			else
			{
				putimage(a3, b3, x3, 0);
				j11 = a3;
				k11 = b3;
			}
		}
		else if((s2 >= 11) && (s2 <= 19))
		{
			a3 = 65;
			int i = 38 * (s2-10);
			putimage(a3, b3-i, x3, 0);
			j11 = a3;
			k11 = b3-i;

		}
		else if((s2 >= 20) && (s2 <= 27))
		{
			a3 = 122;
			b3 = 66;
			if(s2 != 20)
			{
				int i = 38 * (s2-20);
				putimage(a3+i, b3, x3, 0);
				j11 = a3+i;
				k11 = b3;
			}
			else
			{
				putimage(a3, b3, x3, 0);
				j11 = a3;
				k11 = b3;
			}
		}
		else if((s2 >= 28) && (s2 <= 34))
		{
			a3 = 387;
			b3 = 102;
			if(s2 == 29)
			{
				int i = 37;
				putimage(a3, b3+i, x3, 0);
				j11 = a3;
				k11 = b3+i;
			
			}
			else if((s2 != 30) && (s2 <= 34))
			{
			
				float i = 38 * (s2-28);
				putimage(a3, b3+i, x3, 0);
				j11 = a3;
				k11 = b3+i;
			}
			else if(s2 == 28)
			{
				putimage(a3, b3, x3, 0);
				j1 = a3;
				k1 = b3;
			}
			else if(s2 == 30)
			{
				int i = 37 * 2;
				putimage(a3, b3+i, x3, 0);
				j11 = a3;
				k11 = b3+i;
			}
		}
		else if((s2 >= 35) && (s2 <= 40))
		{
			a3 = 332;
			b3 = 349;
			if(s2 != 35 && s2 != 40)
			{
				int i = 39 * (s2-35);
				putimage(a3-i, b3, x3, 0);
				j11 = a3-i;
				k11 = b3;
			}
			else if(s2 == 40)
			{
				int i = 39 * 5;
				putimage(a3-i, b3, x3, 0);
				j11 = a3-i;
				k11 = b3;
			}
			else if(s2 == 35)
			{
				putimage(a3, b3, x3, 0);
				j11 = a3;
				k11 = b3;
			}
		}
		else if((s2 >= 41) && (s2 <= 45))
		{
			a3 = 137;
			b3 = 346;
			int i = 37 * (s2-40);
			putimage(a3, b3-i, x3, 0);
			j11 = a3;
			k11 = b3-i;
		}
		else if((s2 >= 46) && (s2 <= 49))
		{
			a3 = 141;
			b3 = 159;
			int i = 37 * (s2-45);
			putimage(a3+i, b3, x3, 0);
			j11 = a3+i;
			k11 = b3;
		}
		else if((s2 >= 50) && (s2 <= 52))
		{
			a3 = 291;
			b3 = 177;
			if(s2 != 50)
			{
				int i = 37 * (s2-50);
				putimage(a3, b3+i, x3, 0);
				j11 = a3;
				k11 = b3+i;
			}
			else
			{
			putimage(a3, b3, x3, 0);
			j11 = a3;
			k11 = b3;
			}
		}
		else if((s2 >= 53) && (s2 <= 54))
		{
			if(s2 == 53)
			{
				a3 = 253;
				b3 = 443;
				int i = 57 * (s2-50);
				putimage(a3, b3-i, x3, 0);
				j11 = a3;
				k11 = b3-i;
			}
			else if(s2 == 54)
			{
				a3 = 214;
				b3 = 253;
				putimage(a3, b3, x3, 0);
				j11 = a3;
				k11 = b3;
			}
		}
		else if(s2 >= 55)
		{
			a3 = 217;
			b3 = 235;
			putimage(a3, b3, x3, 0);
			delay(500);
		}
		ps1 = s2;
	}
}

void displayMove(int ds)
{
	int s = 0;
	char z[] = "The";
	setfillstyle(1, 0);
	bar(470, 351, 607, 447);
	if(ds==1)
	{
		if(s1==5)
		{
			outtextxy(471, 352, "Initial Bonus:");
			outtextxy(471, 364, "Moving +10");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s1==9)
		{
			outtextxy(471, 352, "Moving +3");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s1==10)
		{
			outtextxy(471, 352, "Oops, Start Again");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s1==17)
		{
			outtextxy(471, 352, "Miss 1 Chance");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s1==23)
		{
			outtextxy(471, 352, "Jackpot:");
			outtextxy(471, 364, "Moving +10");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s1==25)
		{
			outtextxy(471, 352, "Miss 2 Chance");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s1==29)
		{
			outtextxy(471, 352, "CRIME: Move -3");
			outtextxy(500, 370, "&");
			outtextxy(471, 396, "Miss 1 Chance");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s1==30)
		{
			outtextxy(471, 352, "True Player:");
			outtextxy(525, 364, "+1 Chance");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s1==34)
		{
			outtextxy(471, 352, "Pure Heart");
			outtextxy(471, 364, "Move to 50");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s1==37)
		{
			outtextxy(471, 352, "Move to 10");
			outtextxy(525, 370, "OR");
			outtextxy(471, 396, "start again");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s1==43)
		{
			outtextxy(471, 352, "In a HURRY ");
			outtextxy(471, 364, "Move -10");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s1==46)
		{
			outtextxy(471, 352, "Good comes");
			s = 352 + textheight(z) + 1;
			outtextxy(525, s, " with bad");
			outtextxy(471, 370, "Move +7");
			outtextxy(525, 394, "&");
			outtextxy(500, 406, "Miss 2 Chance");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s1==51)
		{
			outtextxy(471, 352, "Not well prepared");
			outtextxy(471, 364, "Move -20");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s1==54)
		{
			outtextxy(471, 352, "Why in HURRY");
			outtextxy(471, 364, "Start from 20");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
	}
	else if(ds==2)
	{
		if(s2==5)
		{
			outtextxy(471, 352, "Initial Bonus:");
			outtextxy(471, 364, "Moving +10");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s2==9)
		{
			outtextxy(471, 352, "Moving +3");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s2==10)
		{
			outtextxy(471, 352, "Oops, Start Again");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s2==17)
		{
			outtextxy(471, 352, "Miss 1 Chance");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s2==23)
		{
			outtextxy(471, 352, "Jackpot:");
			outtextxy(471, 364, "Moving +10");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s2==25)
		{
			outtextxy(471, 352, "Miss 2 Chance");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s2==29)
		{
			outtextxy(471, 352, "CRIME Move -3");
			outtextxy(500, 370, "&");
			outtextxy(471, 396, "Miss 1 Chance");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s2==30)
		{
			outtextxy(471, 352, "True Player:");
			outtextxy(525, 364, "+1 Chance");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s2==34)
		{
			outtextxy(471, 352, "Pure Heart");
			outtextxy(471, 364, "Move to 50");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s2==37)
		{
			outtextxy(471, 352, "Move to 10");
			outtextxy(525, 370, "OR");
			outtextxy(471, 396, "start again");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s2==43)
		{
			outtextxy(471, 352, "In a HURRY ");
			outtextxy(471, 364, "Move -10");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s2==46)
		{
			outtextxy(471, 352, "Good comes");
			s = 352 + textheight(z) + 1;
			outtextxy(525, s, " with bad");
			outtextxy(471, 370, "Move +7");
			outtextxy(525, 394, "&");
			outtextxy(500, 406, "Miss 2 Chance");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s2==51)
		{
			outtextxy(471, 352, "Not well prepared");
			outtextxy(471, 364, "Move -20");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
		else if(s2==54)
		{
			outtextxy(471, 352, "Why in HURRY");
			outtextxy(471, 364, "Start from 20");
			outtextxy(471, 437, "Press any key");
			getch();
			bar(470, 351, 607, 447);
		}
	}
}

int task(int p)
{
	if(s1==5 || s2==5)
	{
		if(p==1)
		{
			s1+=10;
			return s1;
		}
		else
		{
			s2+=10;
			return s2;
		}
	}
	else if(s1==9 || s2==9)
	{
		if(p==1)
		{
			s1+=3;
			return s1;
		}
		else
		{
			s2+=3;
			return s2;
		}
	}
	else if(s1==10 || s2==10)
	{
		if(p==1)
		{
			s1=0;
			return s1;
		}
		else
		{
			s2=0;
			return s2;
		}
	}
	else if(s1==23 || s2==23)
	{
		if(p==1)
		{
			s1+=10;
			return s1;
		}
		else
		{
			s2+=10;
			return s2;
		}
	}
	else if(s1==29 || s2==29)
	{
		if(p==1)
		{
			s1-=3;
			return s1;
		}
		else
		{
			s2-=3;
			return s2;
		}
	}
	else if(s1==34 || s2==34)
	{
		if(p==1)
		{
			s1=50;
			return s1;
		}
		else
		{
			s2=50;
			return s2;
		}
	}
	else if(s1==37 || s2==37)
	{
		if(p==1)
		{
			s1=0;
			return s1;
		}
		else
		{
			s2=0;
			return s2;
		}
	}
	else if(s1==43 || s2==43)
	{
		if(p==1)
		{
			s1-=10;
			return s1;
		}
		else
		{
			s2-=10;
			return s2;
		}
	}
	else if(s1==46 || s2==46)
	{
		if(p==1)
		{
			s1+=7;
			return s1;
		}
		else
		{
			s2+=7;
			return s2;
		}
	}
	else if(s1==51 || s2==51)
	{
		if(p==1)
		{
			s1-=20;
			return s1;
		}
		else
		{
			s2-=20;
			return s2;
		}
	}
	else if(s1==54 || s2==54)
	{
		if(p==1)
		{
			s1=20;
			return s1;
		}
		else
		{
			s2=20;
			return s2;
		}
	}
	return 0;
}

void cut()
{
	if(pl == 1)
	{
		s2 = 0;
		pl = 2;
		move(pl);
		pl = 1;
	}
	else if(pl == 2)
	{
		s1 = 0;
		pl = 1;
		move(pl);
		pl = 2;
	}
}

void won()
{
	int gh = 68, y = 175, gh1 = 510, y1 = 280;
	char a;
	cleardevice();
	setfillstyle(1, 12);
	bar(0, 0, getmaxx(), getmaxy());
	setcolor(10);
	if(s1>=55)
	{
		settextstyle(5, 0, 7);
		outtextxy(70, 180, "Player 1 WINS");
		settextstyle(0, 0, 3);
		for(int i = 0;i<=8;i++)
		{
			setcolor(15);
			outtextxy(gh, y, "");
			setcolor(0);
			outtextxy(gh1, y1, "");
			setcolor(12);
			delay(120);
			outtextxy(gh, y, "");
			outtextxy(gh1, y1, "");
			gh+=26;
			gh1-=26;
			setcolor(15);
			outtextxy(gh, y, "");
			setcolor(0);
			outtextxy(gh1, y1, "");
			setcolor(12);
			delay(120);
			outtextxy(gh, y, "");
			outtextxy(gh1, y1, "");
			gh+=26;
			gh1-=26;
		}
		gh = 68;y = 175;gh1 = 510;y1 = 280;
		for(int i1 = 0;i1<=8;i1++)
		{
			setcolor(15);
			outtextxy(gh, y, "");
			setcolor(0);
			outtextxy(gh1, y1, "");
			delay(120);
			gh+=26;
			gh1-=26;
			setcolor(15);
			outtextxy(gh, y, "");
			setcolor(0);
			outtextxy(gh1, y1, "");
			delay(120);
			gh+=26;
			gh1-=26;
		}
    }

	else if(s2>=55)
	{
		settextstyle(5, 0, 7);
		outtextxy(70, 180, "Player 2 WINS");
		settextstyle(0, 0, 3);
		for(int i = 0;i<=8;i++)
		{
			setcolor(15);
			outtextxy(gh, y, "");
			setcolor(0);
			outtextxy(gh1, y1, "");
			setcolor(12);
			delay(120);
			outtextxy(gh, y, "");
			outtextxy(gh1, y1, "");
			gh+=26;
			gh1-=26;
			setcolor(15);
			outtextxy(gh, y, "");
			setcolor(0);
			outtextxy(gh1, y1, "");
			setcolor(12);
			delay(120);
			outtextxy(gh, y, "");
			outtextxy(gh1, y1, "");
			gh+=26;
			gh1-=26;
		}
		gh = 68; y = 175; gh1 = 510; y1 = 280;
		for(int i1 = 0;i1<=8;i1++)
		{
			setcolor(15);
			outtextxy(gh, y, "");
			setcolor(0);
			outtextxy(gh1, y1, "");
			delay(120);
			gh+=26;
			gh1-=26;
			setcolor(15);
			outtextxy(gh, y, "");
			setcolor(0);
			outtextxy(gh1, y1, "");
			delay(120);
			gh+=26;
			gh1-=26;
		}
    }
	delay(700);
	clrscr();
	cleardevice();
}











