#include<stdio.h>
#include <windows.h>
#include<conio.h>
    void gotoxy(int x, int y){
        COORD c = { x, y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , c);
    }
    void draw_ship(){
        printf(" <-0-> ");
    }
    void erase_ship(int x,int y){
        gotoxy(x,y);
        printf("      ");
    }
    int main()
    {
        char ch=' ';
        int x=38,y=20,i,j;
        gotoxy(x, y);
        draw_ship();
        
        do {
                if (_kbhit()){
                    
                        ch=getch();
                        if(ch=='a'&& x>=1){
                            --x;
                            gotoxy(x,y);
                            draw_ship();}
                        if(ch=='d' && x<=80){
                            ++x;
                            gotoxy(x,y);
                            draw_ship();}
                        if(ch=='w' && y >1){
                            erase_ship(x,y);
                            --y;
                            gotoxy(x,y);
                            draw_ship();
                        }
                        if(ch=='s' && y <=30 ){
                            erase_ship(x,y);
                            ++y;
                            gotoxy(x,y);
                            draw_ship();
                        }
                    
                    fflush(stdin);
                }
            Sleep(100);
        } while (ch!='x');
        return 0;
    }
    