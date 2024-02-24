#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int average =  round((image[i][j].rgbtRed +image[i][j].rgbtGreen + image[i][j].rgbtBlue ) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            int newRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int newGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int newBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if(newRed > 255){
                newRed = 255;
            }
            if(newGreen > 255){
                newGreen = 255;
            }
            if(newBlue > 255){
                newBlue = 255;
            }
            image[i][j].rgbtRed = newRed;
            image[i][j].rgbtGreen = newGreen;
            image[i][j].rgbtBlue = newBlue;

        }
    }
    return;
}



// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        if(width % 2== 0){
            for (int j = 0; j < width / 2; j++){
                RGBTRIPLE temp = image[i][width - (j+1)];
                image[i][width - (j+1)] = image[i][j];
                image[i][j] = temp;
            }
        }
        else{
            for (int j = 0; j < (width-1) / 2; j++){
                RGBTRIPLE temp = image[i][width - (j+1)];
                image[i][width - (j+1)] = image[i][j];
                image[i][j] = temp;
            }

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imageCopy[height][width];
    for (int i = 0; i < height; i++){
        for (int j =0; j < width; j++){
            imageCopy[i][j] = image[i][j];
        }
    }
    for ( int i = 0; i < height; i++){
        for (int j = 0; j < width; j ++){

            int boxes = 0;
            int redSum = 0;
            int greenSum = 0;
            int blueSum = 0;
            for(int r = i -1; r  < i +2; r++){
                if(r >= 0 && r < height){
                    for(int c = j -1; c < j + 2; c++){
                        if(c >= 0 && c < height){
                            redSum += imageCopy[r][c].rgbtRed;
                            greenSum += imageCopy[r][c].rgbtGreen;
                            blueSum += imageCopy[r][c].rgbtBlue;
                            boxes ++;

                        }
                    }
                }
            }
            image[i][j].rgbtRed = round((double)redSum / boxes);
            image[i][j].rgbtGreen = round((double)greenSum / boxes);
            image[i][j].rgbtBlue = round((double)blueSum / boxes);



        }
    }
    return;
}
