#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Declaring array for days in each month                                                                                                                                                         
const int mdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};

//Declaring date structure                                                                                                                                                                       
struct date
{
  int month;
  int day;
  int year;
};
struct date d1, d2;

int daydiff();

int daydiff(){

  //Get user info                                                                                                                                                                              
  printf("\nPlease enter today's date in the format MM DD YYYY:");                                                                                                                            
  scanf("%d %d %d", &(d1.month), &(d1.day), &(d1.year));                                                                                                                                       
  printf("\nNote: The state requires a 6 month (183 days) waiting period between the permit and driving test\n");
  printf("\nPlease enter the day you wish to take your driving portion of the test:");                                                                                                            scanf("%d %d %d", &(d2.month), &(d2.day), &(d2.year));

  // Declare variables to keep count of total number of leap years to date;                                                                                                                     
  int leap1=0;
  int leap2=0;

  // Define variables as values from the struct                                                                                                                                               
  int years1 = d1.year;
  int years2 = d2.year;

  // Declare variable to keep track of total days leading to the first date entered                                                                                                               //Initial declaration includes years + days from current month                                                                                                                               
  int tdays1 = ((d1.year)*365) + (d1.day);
  
  //Adds the total amount of days from each previous month within the year                                                                                                                     
  for (int i=0; i<(d1.month-1);i++)
    tdays1 += mdays[i];

  //Checks to see if current year must be considered in the leap year count                                                                                                                    
  if (d1.month<=2)
    {
      years1--;
    }

  //Finds the total # of leap years from 0000 to said year                                                                                                                                     
  leap1= (years1/4)-(years1/100)+(years1/400);

  //Adds total # leap years to total count                                                                                                                                                    
  tdays1 += leap1;
  int tdays2 = ((d2.year)*365)+ (d2.day);

  //Adds the total amount of days from each previous month within the year                                                                                                                 
  for (int j=0; j<(d2.month-1); j++)
  tdays2 += mdays[j];

  //Checks to see if year entered should be considered in the leap year count                                                                                          
  if (d2.month<=2)
  {
    years2--;
  }

  //Finds the total # of leap years from 0000 to said year                                                                                                                                     
  leap2 = (years2/4)-(years2/100)+(years2/400);

  //Adds # days from leap year count to total days                                                                                                                                             
  tdays2 += leap2;

  return(tdays2-tdays1);
}


int main()
{
  //Declare a variable to hold the value of the difference                                                                                                                                     
  int days=daydiff();

  //Loop to ensure user has waited 183 days                                                                                                                                                  
  do
    {
      printf("Sorry, the day you have selected is within the 6 month waiting period\n");
      printf("Please try again\n");
      days=daydiff();
    } while (days<183);

  //Allow user to continue through the program                                                                                                                                                
  printf("This date is after the 183 day waiting period");
  printf("\nWe'll see you then!\n");
  return(0);
}
