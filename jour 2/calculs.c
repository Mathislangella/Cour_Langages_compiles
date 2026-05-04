#include <stdio.h>

int main(void) {
    int a = 17;
    int b = 5;
    int sum = a + b;
    int diff = a - b;
    int prod = a * b;
    int quot = a / b;
    float quot_float = (float)a / b;
    int res = a % b;


    printf("a = %d, b = %d\n", a, b);
    printf("somme      = %d\n", sum);
    printf("difference = %d\n", diff);
    printf("produit    = %d\n", prod);
    printf("quotient   = %d (entier), %.2f (flottant) \n", quot, quot_float);
    printf("reste      = %d\n", res);

    return 0;
}