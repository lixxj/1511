// speeding check

#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

#define LEARNER 1
#define PPLATE 2
#define FULL 3

int getLicenseType(void);
int getSpeed(void);
int getSpeedLimit();
int drivingTooFast(int,int,int);

int main(void)
{
   int licenseType = getLicenseType();
   int speed = getSpeed(); 
   int speedLimit = getSpeedLimit();

if (drivingTooFast(licenseType, speed, speedLimit)) {
      printf("You're under arrest!!!\n");
   } else {
      printf("Have a nice day\n");
   } 
   return 0;  

int getSpeed()
{
   return getNumber("Enter the speed");
}

int getSpeedLimit()
{
   int limit;
   limit = getNumber("Enter the speed limit");
   return limit;
}

int getLicenseType()
{
   char licence;
   printf("Enter licence (L|P|F): ");
   scanf("%c", &licence);
   if (licence == 'L')
      return LEARNER;
   else if (licence == 'P')
      return PPLATE;
   else if (licence == 'F')
      return FULL;
   else {
      printf("Invalid licence type\n");
      exit(1);
   }
}

int drivingTooFast(int lic, int spd, int lim)
{
    if (lim == 40 && spd > 40) {
        return 1;
    }
	else if (lic == LEARNER) {
        if (lim < 80) {
           return (spd > lim);
        }
        else {
           return (spd > 80);
		}
    }
	else if (lic == PPLATE) {
    }
	else if (lic == FULL) {
    }
} 


}
