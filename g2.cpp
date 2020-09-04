#include<stdio.h>
int main(){
        int n,key,i;
        
        printf("Text Length : ");
        scanf("%d",&n);
        char text[n];
        printf("Your text : ");
        scanf("%s",text);
        printf("Shift  : ");
        scanf("%d",&key);
        for(i=0 ; i < n ; i++){
            text[i] = text[i] + key;
            if(text[i] > 90){
                text[i] = text[i] - 26 ;
            }
            if(text[i] < 65){
                text[i] = text[i] + 26 ;
            }
        }
        for(i=0 ; i < n ; i++){
            printf("%c",text[i]);
        }
        return 0;
    }