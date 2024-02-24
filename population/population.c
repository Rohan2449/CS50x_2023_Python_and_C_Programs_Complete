#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startPop;
    do
    {
        startPop = get_int("Number of starting Llamas: ");
    }
    while (startPop < 9);


    int endPop;
    do
    {
        endPop = get_int("Ending population: ");
    }
    while (endPop < startPop);

    int years = 0;

    while (startPop < endPop)
    {
        startPop +=  startPop / 3 -  startPop / 4;
        years++;
    }

    printf("Years: %i\n", years);

}
