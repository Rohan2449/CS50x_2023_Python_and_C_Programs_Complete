#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do {
        height = get_int("Height of pyramid: ");
    }
    while (height <= 0 || height >= 9);

    for (int h = 0; h < height; h++) {
        //draw spaces
        for( int i = 0; i < height - h -1; i++){
            printf(" ");
        }
        //draw hashes
        for( int i = 0; i < h +1; i++){
            printf("#");
        }
        printf("  ");
        //draw right
        for( int i = 0; i < h +1; i++){
            printf("#");
        }

        printf("\n");
    }



}
