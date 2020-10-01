#include<stdio.h>
#include<windows.h>
#include<conio.h>
void gotoxy(int x, int y);
void draw_ship(int x,int y);
void setcursor(bool visible);
void setcolor(int fg,int bg);
void erase_ship(int x,int y);
void bulletMove(int x,int y);
void erase_bullet(int x,int y);
void draw_bullet(int x,int y);
//.......................
int main()
{
    char ch='.';
    int x=38,y=20,direction,bullet[5][3],bulletStatus=0,i,j;
    setcursor(0);
    setcolor(2,4);
    draw_ship(x,y);
    for(i = 0 ; i <= 4 ; i++){
        bullet[i][2] = 0;
    }
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
            if(ch==' ') {
                for(i = 0 ; i <= 4 ; i++){
                    if(bullet[i][2] == 0){
                        bullet[i][2] = 1;
                        bullet[i][0] = x+3 ;
                        bullet[i][1] = y-1 ;
                        break;
                    }
                }
            }

        }
            for(i = 0 ; i <= 4 ; i++){
                if(bullet[i][2] == 1 && bullet[i][1] == 0){
                    bullet[i][2] = 0;
                }
            }
            for(i = 0 ; i <= 4 ; i++){
                    if(bullet[i][2] == 1){
                        draw_bullet(bullet[i][0] , bullet[i][1]);
                    }
                }
            if(direction == -1 && x > 1) {
                erase_ship(x,y);
                draw_ship(--x,y);
            }
            if(direction == 1 && x < 80) {
                erase_ship(x,y);
                draw_ship(++x,y);
            }
        Sleep(100);
        for(i = 0 ; i <= 4 ; i++){
                    if(bullet[i][2] == 1){
                    erase_bullet(bullet[i][0],bullet[i][1]); 
            }
        }
        for(i = 0 ; i <= 4 ; i++){
                    if(bullet[i][2] == 1){
                        bullet[i][1]--;
            }
        }
        fflush(stdin);
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

void draw_bullet(int x,int y){
    gotoxy(x,y); 
    setcolor (7,0);
    printf("o");
}
void erase_bullet(int x,int y){
        gotoxy(x,y);
        setcolor (2,0);
        printf(" ");
    }
void bulletMove(int x,int y){
    
}
void setcolor(int fg,int bg){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg*16+fg);
}

    