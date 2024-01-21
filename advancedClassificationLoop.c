#include "NumClass.h"
#include <math.h>

int isPalindrome(int n){
    int reversed = 0, remainder, originalNumber = n;

    while (n != 0)
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    if(originalNumber == reversed){
        return 1;
    }
    return 0;
}

int isArmstrong(int n){
    int sum = 0, digitsCount = 0, originalNumber = n;

    /*count number of digits*/
    while (n != 0)
    {
        n /= 10;
        digitsCount ++;
    }

    /*reset n*/
    n = originalNumber;
    /*calculate sum of cubes*/
    while (n != 0)
    {
        int digit = n % 10;
        sum += pow(digit, digitsCount);
        n /= 10;
    }
    if(sum == originalNumber){
        return 1;
    }
    return 0;
}
