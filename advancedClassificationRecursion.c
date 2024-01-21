#include "NumClass.h"
#include <stdio.h>
#include <math.h>


int power(int x, int n){
    
    if (n == 0)
        return 1;
 
    if (x == 0)
        return 0;
    return x * power(x, n - 1);
}

int countDigitsRecursive(int n){
    if(n == 0){
        return 0;
    }
    return 1+ countDigitsRecursive(n/10);
}

int reverse(int num) {
    int digit = countDigitsRecursive(num);
    if (num == 0)
        return 0;

    return ((num % 10 * pow(10, digit)) + reverse(num / 10));
}

int isPalindrome(int num) {
    if (num == reverse(num)) {
        return 1;
    }
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

