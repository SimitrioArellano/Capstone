//First actual version of main to pull
#include <stdio.h>
#include <string.h>
#define A 'A'
#define B 'B'
#define C 'C'
#define D 'D'

int i; //counter.
int j; //another counter.
int n; //switch variable

char testFunc ();

int main(void){

  testFunc();
  
  return(0); //main return
} //main


char testFunc(){
  char res1;
  printf("\tYou are now about to take the Driver's Test.\n\tA Driving Instructer will give you commands and a narrator will explain\n\tthe situation based off the decisions you make.\n\tGood Luck\n\n\n");

  if (i==0){
    printf("*It is raining outside.*\n*A large man with an umbrella comes out of the DMV*\n*He passes right by you and walks toward a black Chevy Impala*\nDriving Instructure: \"Let's go\"\n*You both get into the car.*\n*There is an awkward pause...*\n\nYou can say\nA: \"How is your day going?\"\nB: \"Can I adjust the seat?\"\nC: \"How many miles does this baby get?\"\nD: \"How old are you?\"\n\n");
      
    scanf("%c", &res1);
    
    switch (res1>='a' && res1<= 'z' ? res1-32 : res1) {
    case A:
      printf("You say: \"How is your day going?\"\n\n");
      
      break;
     
    case B:
      printf("You say: \"How is your day going?\"");
      break;
       
    case C:
      printf("You say: \"How is your day going?\"");
      break;
	
    case D:
      printf("You say: \"How is your day going?\"");
      
      break;
      
    default:
      printf("\nPlease enter one of the specified commands\n\n");
   
    } //switch
  } //if
} //testFunc
