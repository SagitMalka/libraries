#include "NumClass.h"

int isPrime(int n){
    if(n <= 1){
        return 0;
    }else{
        for (int i = 0; i < n/2; i++)
        {
            if(n % i == 0){
                return 0;
            }
        }
        return 1;
        
    }
}

int factorialHelper(int n){
    int counter = 1;
    for (int i = 2; i <= n; i++)
    {
        counter *= i;
    }
    return counter;
    
}

int isStrong(int n){
    int sum = 0;
    int num = 0;
    int temp;

    while (n != 0)
    {
        temp = n%10;
        sum += factorialHelper(temp);
        n /= 10;
    }
    if(num == sum){
        return 1;
    }
    return 0;
}

