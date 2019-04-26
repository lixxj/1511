#include<stdio.h>


// Return the units digit of the input
int units_digit_of(int target_number) {
    int digit1 = target_number % 10;
    
    return digit1;
}

// Return the tens digit of the input
int tens_digit_of(int target_number) {
    int digit2 = (target_number - target_number % 10) / 10;
    
    return digit2;
}

int FindSecondLeast(int *array, int size, int target) {  
    int v[10];
    int len = 0;
    int j = 0;
    while (j < size) {
        if (tens_digit_of(target) == tens_digit_of(array[j])) {
            v[len] = array[j];
            len++;
        }
        j++;
    }
    int i, min = v[0], second = v[1];  
    if (min > second) {  
        min = v[1];  
        second = v[0];  
    }  
    for (i = 2; i < len; ++ i) {  
        if (v[i] < min) {  
            second = min;  
            min = v[i];  
        } else if (v[i] < second) {  
            second = v[i];  
        }  
    }  
    return second;  
}


int main(void)  
{  
    int array[6] = {11,24,33,34,35,38};  
    int size = 6;    
    printf("SecondLeast = %d\n", FindSecondLeast(array, 6, 30));  
    return 0;  
}  
