#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<math.h>
void draw_ship(int x,int y);
void gotoxy(int x, int y);
void erase_ship(int x, int y);
void setcursor(bool visible);
void setcolor(int fg,int bg);
void map();
char ch = ' ';
int posx=38, posy=20;
int changex=0;
int main()
{

	//map();
	setcursor(0);
	draw_ship(posx, posy);
	do 
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch =='a')
			{
				if (posx == 0)
				{
					erase_ship(posx, posy);
					draw_ship(posx, posy);
				}
				else
				{
					//erase_ship(posx, posy);
					changex=abs(posx-1);
					//draw_ship(--posx, posy);
				}
			}
			if (ch == 'd')
			{
				if (posx == 80)
				{
					//erase_ship(posx, posy); 
					//draw_ship(posx, posy);
				}
				else
				{
					//erase_ship(posx, posy);
					changex=abs(posx+1);
					//draw_ship(++posx, posy);
				}
			}
			if(ch=='s')
			{
				draw_ship(posx, posy);
				break;
			}
		fflush(stdin);
		}
		if(ch=='a')
		{	
			if(changex<posx)
			{
			for(posx=posx ; changex>=0 ; --posx)
			{
				if (_kbhit()){
					ch = getch();
					if(ch == 's'){
						break;
					}
				}
				erase_ship(posx, posy);
				draw_ship(changex,posy);
				--changex;
				Sleep(100);
			}
			}
		}
		if(ch=='d')
		{	
			if(changex>posx)
			{
			for(posx=posx;changex<=80;++posx)
			{
				if (_kbhit()){
					ch = getch();
					if(ch == 's'){
						break;
					}
				}
				erase_ship(posx, posy);
				draw_ship(changex,posy);
				++changex;
				Sleep(100);
			}
			}
		}
		
		
		fflush(stdin);
	} while (ch != 'x');

	return 0;
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x,int y)
{
	gotoxy(x, y);
	setcolor (2,4);
	printf("<-0->");
}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor (2,0);
	printf("     ");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console,&lpCursor);
}
void setcolor(int fg,int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg*16+fg);
}
void map()
{
	for (int i = 0; i <= 21; i++)
	{
		for (int j = 0; j <= 87; j++)
		{
			if (i == 0 || i == 21)
			{
				printf("*");
			}
			else
			{
				if (j == 0 || j == 87)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}