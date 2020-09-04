#include <stdio.h>
int main(){
    float matrix[3][3],a=0;
    int i,j;
    printf("Please enter your matrix 3x3 : \n");
    for(i=0 ; i < 3 ; i++){
        for(j = 0 ;j < 3 ; j++){
            scanf("%f",&matrix[j][i]);
        }
    }
    a = a+ (matrix[0][0]*matrix[1][1]*matrix[2][2]);
    a = a+ (matrix[0][1]*matrix[1][2]*matrix[2][0]);
    a = a+ (matrix[0][2]*matrix[1][0]*matrix[2][1]);

    a = a- (matrix[2][0]*matrix[1][1]*matrix[0][2]);
    a = a- (matrix[2][1]*matrix[1][2]*matrix[0][0]);
    a = a- (matrix[2][2]*matrix[1][0]*matrix[0][1]);
    printf("Determinant is %.3f",a);
    return 0;
}