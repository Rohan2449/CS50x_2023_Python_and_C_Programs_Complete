#include <stdio.h>
#include <cs50.h>
int main(void){
    string name = get_string("Enter your name: ");
    int age = get_int("Enter your age: ");
    long number = get_long("Enter your phone number: ");

    printf("Name: %s\nAge: %i\nNumber: %li\n", name, age, number);

    }

