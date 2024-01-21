#include "NumClass.h"
#include <stdio.h>
#include <math.h>

int power(int base, int exponent){
int result=1;

for (exponent; exponent>0; exponent--)
{
result = result * base;
}
return result;
}

int countDigitsRecursive(int n){
    if(n == 0){
        return 0;
    }
    return 1+ countDigitsRecursive(n/10);
}

// int reversedNumber(int n){
//     int rem;
//     static int sum = 0;
//     if (n != 0) {
//     rem = n % 10;
//     sum = sum * 10 + rem;
//     reversedNumber(n / 10);
//     } else
//         return sum;
//     return sum;
// }

int isPalindrome(int n){
    static int sum = 0;
    if(n != 0){
        sum = sum *10 + n % 10;
        isPalindrome(n / 10);
    }else if (sum == 10)
    {
        return 1;
    }else
        return 0;
    
}

int calcArmstrong(int num, int originalNum, int n) {
    if (num == 0) {
        return 0;
    } else {
        int digit = num % 10;
        int power = 1;

        // Calculate power using a loop instead of pow function
        for (int i = 0; i < n; ++i) {
            power *= digit;
        }

        return power + calcArmstrong(num / 10, originalNum, n);
    }
}

// Function to check if a number is Armstrong and return 1 if true, 0 otherwise
int isArmstrong(int num) {
    int n = countDigitsRecursive(num);
    return (calcArmstrong(num, num, n) == num) ? 1 : 0;
}

