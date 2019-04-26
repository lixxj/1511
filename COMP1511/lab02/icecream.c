//"Icecream Scoops"
//Matilda wants to buy some ice-cream, but she only has $10. Write a program so that she can input how many scoops of ice-cream she wants and how much each scoop costs and it will let her know if she has enough money. 
//XJ

#include <stdio.h>

int main(void)
{
    
    int amount;
    int singleprice;
    
    printf("How many scoops?");
    scanf("%d", &amount);
    printf("How many dollars does each scoop cost?");
    scanf("%d", &singleprice);
    int totalprice = amount * singleprice;
    if (totalprice > 10){
       printf("Oh no, you don't have enough money :(\n");}
    else if (totalprice < 0){
       printf("invalid\n");}
    else {
       printf("You have enough money!\n");}
    return 0;
}
