#include<stdio.h>
#include<windows.h>
#include<conio.h>
void gotoxy(int x, int y);
void draw_ship(int x,int y);
void setcursor(bool visible);
void setcolor(int fg,int bg);
void erase_ship(int x,int y);
//.......................
int main()
{
    char ch='.';
    int x=38,y=20,direction;
    setcursor(0);
    setcolor(2,4);
    draw_ship(x,y);
    do {
        if (kbhit()){
            ch=getch();
            if(ch=='a') {       //direction  -1 => left / 0 => stop / 1 => right
                direction = -1;
            }
            if(ch=='d') {
                direction = 1;
            }
            if(ch=='s') {
                direction = 0;
            }

        }
            if(direction == -1) {
                erase_ship(x,y);
                draw_ship(--x,y);
            }
            if(direction == 1) {
                erase_ship(x,y);
                draw_ship(++x,y);
            }
            fflush(stdin);
        
        Sleep(100);
    } while (ch!='x');
    return 0;
}

void erase_ship(int x,int y){
        gotoxy(x,y);
        setcolor (2,0);
        printf("       ");
        
    }
void setcursor(bool visible){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console,&lpCursor);
}
void gotoxy(int x, int y){
    COORD c = { x, y };
    SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
void draw_ship(int x,int y){
    gotoxy(x,y); 
    setcolor(2,4);
    printf(" <-0-> ");
}
void setcolor(int fg,int bg){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg*16+fg);
}