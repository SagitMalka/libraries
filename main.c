#include "NumClass.h"
#include <stdio.h>


int main(){
    int startNum, endNum;
    scanf("%d %d", &startNum, &endNum);

    printf("The Armstrong numbers are:");
    for (int i = startNum; i < endNum; i++)
    {
        if(isArmstrong(i) == 1){
            printf(" %d", i);
        }
    }
    printf("\n");

    printf("The Palindromes are:");
    for (int i = startNum; i < endNum; i++)
    {
        if(isPalindrome(i) == 1){
            printf(" %d", i);
        }
    }
    printf("\n");

    printf("The Prime numbers are:");
    for (int i = startNum; i < endNum; i++)
    {
        if(isPrime(i) == 1){
            printf(" %d", i);
        }
    }
    printf("\n");

    printf("The Strong numbers are:");
    for (int i = startNum; i < endNum; i++)
    {
        if(isStrong(i) == 1){
            printf(" %d", i);
        }
    }
    
    return 0;
}
