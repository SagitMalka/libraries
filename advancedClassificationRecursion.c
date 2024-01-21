#include "NumClass.h"
#include <stdio.h>


int countDigitsRecursive(int n) {
    if (n == 0) {
        return 0;
    }
    return 1 + countDigitsRecursive(n / 10);
}

int reverse(int num, int curr) {
    if (num == 0)
        return curr;
    curr = curr *10 +num%10;
    return reverse(num/10, curr);
}

int isPalindrome(int num) {
    int curr = reverse(num, 0);
    if (num == curr) {
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

