#include <stdio.h>
#include <cs50.h>

int main(void){
    long x = get_long("X: ");
    long y = get_long("Y: ");

    double z = (double) x /  y;

    printf("%.20f\n", z);
}