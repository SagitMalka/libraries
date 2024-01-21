#include "NumClass.h"


int power(int base, int exponent){
    int result=1;
    
    for (exponent; exponent>0; exponent--){
    result = result * base;
    }
    return result;
}

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
        sum += power(digit, digitsCount);
        n /= 10;
    }
    if(sum == originalNumber){
        return 1;
    }
    return 0;
}
