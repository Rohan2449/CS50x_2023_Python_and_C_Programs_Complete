#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validateKey(string key);

int main(int argc, string argv[])
{

    if(argc != 2){
        printf("Usage: ./substitution key\n");
        return 1;

    }

    string key = argv[1];
    for(int i = 0, n = strlen(key); i < n; i++){
        key[i] = toupper(key[i]);
    }
    printf("key: %s\n", key);

    //kicks us out of program if key is unvalid
    if(validateKey(key) != 0){
        return 1;
    }




    string plainText = get_string("plaintext: ");
    string cipherText = plainText;

    // ABCDEFG
    //   T

    for(int i = 0, n = strlen(plainText); i < n; i++){

        if(isalpha(plainText[i])){

            int matchIndex = (toupper(plainText[i]) - 65);
            int diff = key[matchIndex] - toupper(plainText[i]);

            cipherText[i] = (char) (plainText[i]  + diff);

        }
    }

    printf("ciphertext: %s\n", cipherText);



}

// 1 - invalid,    0 - valid
int validateKey(string key){

    if(strlen(key) != 26){
        printf("Key must contain 26 characters\n");
        return 1;
    }

    for(int i = 0, n = strlen(key); i < n; i ++){
        if(!isalpha(key[i])){
            printf("Key must only contain letters.\n");
            return 1;
        }



        for(int j = i + 1; j < n; j++){
            if(key[i] == key[j]){
                printf("Key cannot contain repeated characters.\n");
                return 1;
            }
        }
    }
    return 0;
}

