#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>



// 4003600000000014
bool luhn(long card);
int numberOfDigits(long credit);
long firstNumbers(long card, int n);
bool isAmex(long card);
bool isVisa(long card);
bool isMasterCard(long card);



int main(void){

long int cardNumber = get_long("Number: ");



if(luhn(cardNumber)){
    if(isVisa(cardNumber)){
        printf("VISA\n");
    }
    else if(isAmex(cardNumber)){
        printf("AMEX\n");
    }
    else if(isMasterCard(cardNumber)){
        printf("MASTERCARD\n");
    }
    else{
        printf("INVALID\n");
    }
}
else{
    printf("INVALID\n");
}
}




bool luhn(long card){

int lastDigit;
bool nextStep = false;
int sum = 0;
int checkingNum;

while(card > 0){
    if(nextStep){
    lastDigit = card % 10;
    checkingNum = lastDigit * 2;
        if(checkingNum >= 10){
        sum += checkingNum % 10 + 1;

    }
        else{
        sum += checkingNum;
    }

}
    else if(!nextStep){
        lastDigit = card % 10;
        sum += lastDigit;
    }
        card /= 10;
        nextStep = !nextStep;
    }
    return sum % 10 == 0;
}

long firstNumbers(long card, int n){
    while(card > pow(10, n)){
        card /= 10;
    }
    return card;
}

bool isAmex(long card){
    return numberOfDigits(card) == 15 && (firstNumbers(card, 2) == 34 || firstNumbers(card, 2) == 37);


}

bool isMasterCard(long card){
   return numberOfDigits(card) == 16 && (firstNumbers(card, 2) == 51 || firstNumbers(card, 2) == 52 || firstNumbers(card, 2) == 53 || firstNumbers(card, 2) == 54 || firstNumbers(card, 2) == 55);


}

bool isVisa(long card){
    return (numberOfDigits(card) == 13 || numberOfDigits(card) == 16) && firstNumbers(card, 1) == 4;
}

int numberOfDigits(long credit){
    int count = 0;
    while(credit > 0){
        credit /= 10;
        count++;
    }
    return count;
}
