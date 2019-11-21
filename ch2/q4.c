#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int *add_int(int array[], int n, int toAdd) {
    int *ret = (int*) calloc(n + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
     ret[i] = array[i]; 
    }
    ret[n+1] = toAdd;

    return ret;
}

int * convert(double number) {
    static int whole = 0;
    double decimal = number - ((int) number);
    int n = 0;
    int digits = (int) number;
    double x;


    // gets the number of digits 
    // to the left of the decimal
    while(digits) {
        digits /= 10;
        n++;
    }
    
    printf("%f\n", decimal); 
    while(decimal > 0) {
        decimal *= 10;
        x = decimal - ((int) decimal);
        printf("%f : %f\n", decimal, x);
        n++;
    }

    printf("%d\n", n);

    /*for (int i = n - 1; i >= 0; i--) {
        result[i] = whole % 10;
        whole /= 10;
    }*/

    return &whole;
}





int main() {
    double number;
    int * result;
    while (scanf("%lf", &number) != EOF) {
        result = convert(number);
    }
}
