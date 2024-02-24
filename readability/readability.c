#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count_sentences(string text);
int count_words(string text);
int count_letters(string text);
int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    printf("%i sentences\n", sentences);
    printf("%i words\n", words);

    printf("%i letters\n", letters);


    float index = 0.0588 * ( (float) letters / words * 100) - 0.296 * ( (float) sentences / words * 100.0) - 15.8;

    printf("index: %f\n", index);

    if(index >= 16){
        printf("Grade 16+\n");
    }
    else if(index < 1){
        printf("Before Grade 1\n");
    }
    else{
        printf("Grade %i\n", (int) round(index) );
    }


}

int count_letters(string text){
    int i =0;
    int letter;
    int count = 0;
    while(text[i] != '\0'){
        letter = text[i];
        if((letter >= 65 && letter <= 90) || (letter >=97 && letter <= 122)){
            count++;
        }
        i++;
    }
    return count;
}

int count_words(string text){
    int i = 0;
    char letter;
    int count = 0;
    while(text[i] != '\0'){
        letter = text[i];
        if(letter == ' '){
            count++;
        }
        i++;
    }
    return count + 1;
}

int count_sentences(string text){
    int i = 0;
    char letter;
    int count = 0;
    while(text[i] != '\0'){
        letter = text[i];
        if(letter == '.' || letter == '!' || letter == '?'){
            count++;
        }
        i++;
    }
    return count;


}
