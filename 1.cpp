#include <stdio.h>
int main(){
    int i;
    char x[30];
    scanf("%s",x);
    for(i=0 ; i < 30 ; i++){
        if(x[i]>=65 && x[i]<=90){
            printf("%c",x[i]);
        }
    }
}