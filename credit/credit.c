#include <cs50.h>
#include <stdio.h>


string getCardType(long cardNum);
int main(void)
{
   long cardNum;
    do{
        cardNum = get_long("Card Number: ");
    }
    while(cardNum < 0);

   printf("%s", getCardType(cardNum));



}

string getCardType(long cardNum){
    int sumOfTwos = 0;

    for(long i = cardNum /10; i > 0; i /= 100){

        sumOfTwos += ((i % 10) * 2)/10 + ((i % 10) * 2)%10;
    }

    int sumOfOnes = 0;

    for(long i = cardNum; i > 0; i /= 100){
        sumOfOnes += i % 10;
    }


   if((sumOfOnes + sumOfTwos)% 10 == 0){
      int digits = 0;

      for(long i = cardNum; i > 0; i /=10){
         digits++;
      }
      //VISA                                                                          4012888888881881
      if((digits == 13 || digits == 16) && (cardNum / 1000000000000 == 4 || cardNum / 1000000000000000 == 4)){
         return "VISA\n";
      }
      //MASTERCARD
      else if(digits == 16 && cardNum / 100000000000000 >= 51 && cardNum / 100000000000000 <= 55){
         return "MASTERCARD\n";
      }
      //AMEX                             378282246310005                   378282246310005
      else if(digits == 15 && (cardNum / 10000000000000 == 34 || cardNum / 10000000000000 == 37)){
         return "AMEX\n";
      }
      else{
         return "INVALID\n";
      }
   }
   else{
      return "INVALID\n";
   }

}


