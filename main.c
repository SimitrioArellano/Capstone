//First actual Secong
#include <stdio.h>
#include <string.h>
#define A1 'A'
#define B1 'B'
#define C1 'C'
#define D1 'D'
#define A2 'a'
#define B2 'b'
#define C2 'c'
#define D2 'd'


int i; //counter.
int j; //another counter.
int n; //switch variable

char testFunc ();
char res2A();
char res2B();
char res2C();
char res2D();
char res3AC();
char res3AD();
char res3BA();
char res3DA();
char res4ACC();
char res4ADC();
char res4BAA();
char res5ACCC();
char res5ADCD();
char res5BAAB();
char res6ACCCD();
char res6ADCDB();
char res6BAABD();
char res7BAABDB();
char res8BAABDBC();

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

void driveTest();

int daydiff(){

  //Get user info
  printf("\nPlease enter today's date in the format MM DD YYYY:");
  scanf("%d %d %d", &(d1.month), &(d1.day), &(d1.year));
  printf("\nNote: The state requires a 6 month (183 days) waiting period between the permit and driving test\n");
  printf("\nPlease enter the day you wish to take your driving portion of the test:");
  scanf(" %d %d %d", &(d2.month), &(d2.day), &(d2.year));

  // Declare variables to keep count of total number of leap years to date;
  int leap1=0;
  int leap2=0;

  // Define variables as values from the struct
  int years1 = d1.year;
  int years2 = d2.year;

  // Declare variable to keep track of total days leading to the first date entered                      //Initial declaration includes years + days from current month
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
  while (days<183){
	printf("Sorry, the day you have selected is within the 6 month waiting period\n");
	printf("Please try again\n");
	days=daydiff();
      }

    //Allow user to continue through the program
    printf("This date is after the 183 day waiting period");
    printf("\nWe'll see you then!\n");

    testFunc();

    
    return(0);
}


/*void driveTest(){

  testFunc();
  
  return(0); //main return
} //main
*/

char testFunc(){
  char res1;
  char res3;
  
  printf("\tIt is now %d-%d-%d\n\nYou are now about to take the Driver's Test.\n\tA Driving Instructer will give you commands and a narrator will explain\n\tthe situation based off the decisions you make.\n\tGood Luck\n\n\n",d2.month,d2.day,d2.year);

  if (i==0){
    printf("*It is raining outside.*\n*A large man with a polka dot umbrella comes out of the DMV*\n*He passes right by you and walks toward a black Chevy Impala*\nDriving Instructure: \"Let's go\"\n*You both get into the car.*\n*There is an awkward pause...*\n\n");
    
    printf("You can say\nA: \"How is your day going?\"\nB: \"Can I adjust the seat?\"\nC: \"How many miles does this baby get?\"\nD: \"How old are you?\"\n\n");
      
    scanf(" %c", &res1);
    
    switch (res1>='a' && res1<= 'z' ? res1-32 : res1) {
    case A1:
      printf("You say: \"How is your day going?\"\n\n");
      printf("*The Driving Instructor makes a loud grunting noice*\nDriving Instructer: \"Don't even get me started!\nThis morning I sat in bubble gum\nThis afternoon I lost my wallet and cracked my phone screen\nAnd now I have to work late without getting a lunch break.\nThank you so much for reminding me!\nTurn on the car now and let's get this over with!\"\n\n");
      res2A();
      break; // res1
    case B1:
      printf("You say: \"Can I adjust the seat?\"\n");
      printf("*The Driving Instructure seems uninterested*\nDriving Instructer: \"Yeah. Whatever, hurry up!\"\n\n");
      res2B();
      break; // res1
    case C1:
      printf("You say: \"How many miles does this baby get?\"\n\n");
      printf("*The Driving intructor gives you a confused look*\nDriving Instructor: \"What?\nJust drive the car.\"\n");
      res2C();
      break; // res1	
    case D1:
      printf("You say: \"How old are you?\"");
      printf("*The Driving Instructor becomes ecstatic!*\nDriving Instructor: \"Today is my birthday!\nThank you so much for asking!\"\n*The Driving Instructor gives you a high-five*\nDriving Instructor: \"Is this your first driving test?\"\n\n");
      res2D();
      break;      
    default:
      printf("\nPlease enter one of the specified commands\n\n");
   
    } //switch
  } //if
} //testFunc

char res2A(){
  char res2;
  
  printf("What do you do next?\nA: Turn on the car and apologize\nB: Adjust the seat and check the mirrors\nC: Put your seatbelt on\nD: Turn on the radio\n\n");

  scanf(" %c", &res2);
  
  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You turn on the car and apologize*\n\n");
    printf("AUTOMATIC FAIL\nYou can never turn on the vehicle without first securing your seatbelt.\n*The Driving Instructor kicks you out of the car and you fall into a puddle*\nDriving Instructor: \"You may try again in six months.\"\n\n");
    break;//res2
  case B1:
    printf("*You adjust the seat and check the mirrors*\n\n");
    printf("*You grab the handle on the side of the car chair*\n*As you pull the handle up, it rips off the chair*\n*The chair slides off its tram and into the backseat*\n*You have broken the car*\nDriving Instructor: \"...get out.\"\n*You have failed your test*\n*You can retake your test in 6 weeks*\n\n");
    break;//res2
  case C1:
    printf("*You properly put on your seatbelt and adjust the mirrors*\n\n");
    res3AC();
    break;//res2
  case D1:
    printf("*You turn on the radio*\n\n");
    printf("*The Driving Instructor immediatly turns off the radio and writes on his clipboard*\n*You back the car out and are about to pull out of the DMV parking lot*\n\n");
    res3AD();
    break;//res2
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  } // resA2
  return(0);
}//res2AFunc

char res2B(){
char res2;

printf("What do you do next?\nA: Turn on the radio\nB: Turn on the car\nC: Put your seatbelt on\nD: Adjust the seat and check the mirrors\n\n");

scanf(" %c", &res2);

switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
 case A1:
   printf("*You turn on the radio*\n\n");
   printf("*The music station cuts off to an emergency broadcast*\nRadio: \"Caution in effect!\nSuspected bank robber is at large in the DMV area and extremely dangerous.\nPolice describe him as a large man with a polka dot umbrella\"\n*The Driving Instructor turns the radio off and holds you at gunpoint*\nDriving Instructor: \"DRIVE!\"\n\n");
   res3BA();
   break;//res2
 case B1:
   printf("*You turn the car on*\n\n");
   printf("*As you turn on the car, the radio cuts off to an emergency broadcast*\nRadio: \"Caution in effect!\nSuspected bank robber is at large in the DMV area and extremely dangerous.\nPolice describe him as a large man with a polka dot umbrella\"\n*The Driving Instructor turns the radio off and holds you at gunpoint*\nDriving Instructor: \"DRIVE!\"\n\n");   
   res3BA();
   break;//res2
 case C1:
   printf("*You put your seatbelt on*");
   printf("*The Driving Instructor writes on his clipboard*\n\n");
   res3AC();
   break;//res2
 case D1:
   printf("*You adjust the seat and check the mirrors*");
   printf("*The Driving Instructor writes on his clipboard*\n\n");
   res3AC();   
   break;//res2
 default:
   printf("\nPlease enter one of the specified commands\n\n");
 } // res2B
return(0);
}//res2B

char res2C(){
  char res2;
  printf("What do you do next?\nA: Adjust the seat\nB: Ask again\nC: Drive\nD: Secure seatbelt and ask if he is ready\n\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You adjust the seat*\n\n");
    printf("*To look cool you recline the seat back like a G*\n*You pull out and start driving down the road*\n*Police lights go off and you get pulled over*\n*The officer explains he could not see anyone in the driver's seat so he pulled the car over*\n*You have failed your test*\n*You can retake your test in 6 weeks*\n\n");
    break;
  case B1:
    printf("*You ask again*\n\n");
    printf("You: \"No really...how many miles does this baby get.\"\n*The Driving Instructor is annoyed*\nDriving Instructor: \"I don't know like 15 miles per gallon?\"\n*You become very upset*\nYou: \"WhAT! I cannot drive this car.\nI will not support any car that gets less than 35 miles per gallon.\"\n*You get out of the car and leave*\n*You have failed your test*\n*You can retake your test in 6 weeks*\n\n");
    break;
  case C1:
    printf("*You drive*\n\n");
    printf("*As you drive down the road your sandal comes off your right foot*\n*You try to pull over and fix your shoe but the break is jammed*\n*Your dirty birkenstock shoe is lodged behind the break pedal*\n*The car goes out of control and into the ditch*\n*You have failed your test*\n*You can retake your test in 6 weeks*\n\n");
    break;
  case D1:
    printf("*You put your seatbelt on and ask if he is ready*\n\n");
    printf("*The Driving Instructor secures his seatbelt*\nDriving Instructor: \"Yes. Thank you for asking.\nAre you ready? Do you have your driver's permit?\"\n*You grab your wallet and show him your permit card*\nDriving Instructor: \"Driving Instructor: \"Is this a joke?\nThis is a fake ID\nGet out of the car\"\n*He hands back the card and you see you accidentally gave him your fake 21 year old ID*\n*You have failed your test*\n*You can retake your test in 6 weeks*\n\n");
    break;
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  } // res2C
  return(0);
}//res2C
    
char res2D(){
  char res2;
  printf("What do you do next?\nA: Yes\nB: No\n\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You say yes*");
    printf("Driving Instructor \"Okay. Well can you identify the accelerator and the brake for me?\"\n\n");
    res3DA();
    break;
  case B1:
    printf("*You say no*");
    printf("Driving Instructor \"Okay. Well can you identify the accelerator and the brake for me?\"\n\n");
    res3DA();
    break;
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  } // res2D
  return(0);
}//res2D

char res3AC(){
  char res2;
  printf("What do you do next?\nA: Look over your left shoulder and back out \nB: Look over right shoulder and back out\nC: Ask if the Driving Instructor is ready\nD: Turn your phone off\n\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You look over your left shoulder and back out*\n\n");
    printf("*You can hardly see anything looking from your left shoulder*\nYou begin to back out when you hear a scream*\n*You nearly hit an elderly woman*\n*You have failed your test*\n*You can retake your test in 6 weeks*\n\n");
    break;
  case B1:
    printf("*You look over your right shoulder and back out*\n\n");
    printf("Driving Instructor: \"Stop the car.\"\n*You failed to make sure your passenger has their seatbelt secured*\n*You have failed your test*\n*You can retake your test in 6 weeks*\n\n");
    break;
  case C1:
    printf("*You ask if the Driving Instructor is ready*\n\n");
    printf("*The Driving Instructor secures his seatbelt and writes on his clipboard*\nDriving Instructor: \"Yes, proceed\"\n*You back out and are about to leave the DMV parking lot*\n\n");
    res4ACC();
    break;
  case D1:
    printf("*You turn your phone off*\n\n");
    printf("*The Driving Instructor sees your phone in your hand*\nDriving Instructor: \"What are you doing on your phone!\nGet out of the car.\"\n*Before you can explain he has pushed you out of the vehicle*\n*You have failed your test*\n*You can retake yourtest in 6 weeks*\n\n");
    break;
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  } // res3AC
  return(0);
}//res3AC

char res3AD(){
  char res2;
  printf("What do you do next?\nA: Drive straight\nB: Start whistling\nC: Turn right\nD: Turn left\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You drive straight*\n\n");
    printf("*You go straight*\n*As you get across the intersection you realize the road is closed to construction*\n*The car tires hit some nails and explode*\n*You have failed your test*\n*You can retake yourtest in 6 weeks*\n\n");
    break;
  case B1:
    printf("*You start whistling*\n\n");
    printf("*The Driving Instructor throws his clipboard out of the window*\nDriving Instructor: \"Get out of the car!\"\n*You have failed your test*\n*You can retake yourtest in 6 weeks*\n\n");
    break;
  case C1:
    printf("*You turn right*\n\n");
    printf("*You make a successful right turn and drive down the street*\n*Down the street you see a McDonald's sign and you hear the Driving Instructor's stomach rumbles*\n\n");
    res4ADC();
    break;
  case D1:
    printf("*You turn left*\n\n");
    printf("*Soon after you turn left, you realize you are on the wrong side of a one-way street*\n*You swerve widely to avoid the oncoming traffic and hit a fire hydrant*\n*Water is everywhere*\n*You have failed your test*\n*You can retake yourtest in 6 months*\n\n");
    break;
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  } // res3AD
  return(0);
}//res3AD

    
char res3BA(){
  char res2;
  printf("What do you do next?\nA: Drive\nB: Try to get out of the car\n\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You Drive*\n\n");
    printf("*You back out of the parking lot and start driving down the road*\nDriving Instructor: \"Take a right here!\"\n\n");
    res4BAA();
    break;
  case B1:
    printf("*You try to get out of the car*\n\n");
    printf("*The Driving instructor pushes you out of the car*\nHe shoots in the air and peels out*\n*You will be able to retake your test in six months*\n\n");
    return(0);
    break;
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  }//swtich 3BA
  return(0);
}//res3BA

char res3DA(){
  char res2;
  printf("What do you do next?\nA: Point at the left and right pedals\nB: Point at the right and left pedals\nC: Point at the left pedal and the dial behind the steering wheel\nD: Point at the right pedal and the dial behind the steering wheel*\n\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You point at the left and right pedals*\n\n");
    printf("Driving Instructor: \"Okay well you might want to practice more before taking this test\nI'll pretend I had a scheduling conflict becasue I want to go home\"\n*You get out of the car*\n*You may retake the test in one week*\n\n");
    break;
  case B1:
    printf("*You point at the right and left pedals*\n\n");
    printf("*Driving Instructor writes on his clipboard*\nDriving Instructor: \"Congratualtions you have passed the test\"\n*You have successfully shmoozed the instructor*\n*Congratulations you have passed your test*\n\n");
    break;
  case C1:
    printf("*You point at the left pedal anf the dial behind the steering wheel*\n\n");
    printf("Driving Instructor: \"Close enough\"\n*The Driving Instructor writes on his clipboard*\nDriving Instructor: \"Congratulations you have passed your test\"\n*You have successfully shmoozed the instructor*\n*Congratulations you have passed your test*\n\n");
    break;
  case D1:
    printf("*You point at the right pedal and the dial behind the steering wheel*\n\n");
    printf("Driving Instructor: \"Okay well you might want to practice more before taking this test\nI'll pretend I had a scheduling conflict becasue I want to go home\"\n*You get out of the car*\n*You may retake the test in one week*\n\n");
    break;
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  }//swtich 3DA
  return(0);
}//res3DA
    


char res4ACC(){
  char res2;
  printf("What do you do next?\nA: Go through the round-about\nB: Go straight\nC: Take a right\nD:\
 Take a left\n\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You go through the round-about*\n\n");
    printf("*The lane you are in becomes the inside lane in the round-about*\n*There are too many cars in the adjacent lane*\nYou cannot switch lanes to get out of the round-about*\n *You make 4 full circles around the round-about before giving up and parking in the middle of the round-about*\n*You have failed your test*\n*You can retake yourtest in 6 weeks*\n\n");
    break;
  case B1:
    printf("*You go straight*\n\n");
    printf("*As you go forward the intersection turns red and you hesitate*\n*You are stuck in half-way in the middle of the of the instersection*\n*Cars are honking at you*\n*A car pulls right up behind you*\n*You go forward and run the light nearly T-boning a chevy impala*\n*You have failed your test*\n*You can retake yourtest in 6 weeks*\n\n");
    break;
  case C1:
    printf("*You take a right*\n\n");
    printf("*Looking both ways before pulling out, you make a successful right turn*\n*You are approaching a Yield sign*\n*A car is approaching from the right a block away*\n\n");
    res5ACCC();
    break;
  case D1:
      printf("*You take a left turn*\n\n");
    printf("*Looking both ways before pulling out, you make a successful left turn*\n\n");
    printf("*Looking both ways before pulling out, you make a successful left turn*\n*You are approaching a Yield sign*\n*A car is approaching from the right a block away*\n\n");
    res5ACCC();
    break;
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  }//swtich 4ACC
  return(0);
}//res4ACC

char res4ADC(){
  char res2;
  printf("What do you do next?\nA: Go into the drive-thru\nB: Go straight\nC: Make a U-turn\nD: Ask the Driving Instructor where to go\n\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You go into the drive-thru*\n\n");
    printf("*You get to the McDonald's drive-thru window*\nDriving Instructor: \"What do you think you are doing? Get out of here!\"\nMcDonald's Employee: \"One ten piece McChicken meal. That'll be $7.46\nPlease pay at the next window\"\n*You realize you cannot leave without paying*\n*You pull ahead to the next window*\nMcDonald's Employee 2: \"$7.46 please\"\n*You reach for your wallet and realize you left it at home*\n*A long awkward pause follows and cars behind honk*\n*You have to ask the Driving Instructor for money*\nDriving Instructor: \"Get out of the car\"\n*You get out of the car and drives away leaving you at the McDonald's window*\n*You have failed your test*\n*You can retake your test in 6 weeks*\n\n");
    break;
  case B1:
    printf("*You go straight*\n\n");
    printf("*As you drive straight a car quickly pulls out of the drive-thru and nearly hits you*\n*You have failed your test*\n*You can retake your test in 6 weeks*\n\n");
    break;
  case C1:
    printf("*Make a U-turn*\n\n");
    printf("*Half-way through your U-turn you see an NO U-TURN sign*\n*You have failed your test*\n*You can retake your test in 6 weeks*\n\n");
    break;
  case D1:
    printf("*You ask the Driving Instructor where to go*\n\n");
    printf("*You turn your head to ask the Driving Instructor where to go*\n*As you face the Driving Instructor you accidentally sneeze into his open mouth*\n\n");
    res5ADCD();
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  }//res5ADCD switch
}//res5ADCD

    

char res4BAA(){
  char res2;
  printf("What do you do next?\nA: Open the door and tuck and roll\nB: Take a right\nC: Go straight\nD: Take a left\n\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You open the door and tuck and roll*\n\n");
    printf("*You roll out of the moving car and onto the pavement*\n*The police immediatly surround you*\n*You are detetained and sentenced to 5 years in state Juvenile detention*\n\n");
    return(0);
    break;   
  case B1:
    printf("*You take a right*\n\n");
    printf("*You drive onto the freeway*\n*Police vehicles are right on your tail*\nDriving Instructor: \"LOSE THEM!\"\n\n");
    res5BAAB();
    break;
  case C1:
    printf("*You go straight*\n\n");
    printf("*The police vehicles catch up on you*\n*A police Ford Explorer clips the tail of your car*\n*You spin out*\n*The police immediatly surround you*\n*You are detetained and sentenced to 5 years in state Juvenile detention*\n\n");
    return(0);
    break;
  case D1:
    printf("*You take a left*\n\n");
    printf("*As you turn you realize that you are now on a one way street*\n*You skid to avoid the traffic and go into the ditch*\n*The police immediatly surround you*\n*You are detetained and sentenced to 5 years in state Juvenile detention*\n\n");
    return(0);
    break;
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  }//res4BAA switch
}//res4BAA

char res5ADCD(){
  char res2;
  printf("What do you do next?\nA: Reach for a napkin in the glove compartment\nB: Pretend nothing happened\nC: Say a joke\nD: Apologize\n\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You reach for a napkin in the glove compartment*\n\n");
    printf("*You reach over the lap of the Driving Instructor and pull on the glove compartment handle*\n*The glove compartment is locked*\n*Your grip on the wheel slips and you nearly hit a child on the sidewalk*\n*You have failed your test*\n*You can retake your test in 6 weeks*\n\n");
    break;
  case B1:
    printf("*You pretend nothing happened*\n\n");
    printf("*You continue driving down the road*\n*The road loops back around toward the DMV*\n*You realize you need to impress him to pass the test*\n*There are two open spaces*\nOne is in between two cars*\n*The other is a wide open spot*\n\n");
    res6ADCDB();
    break;
  case C1:
    printf("*You say a joke*\n\n");
    printf("You: \"Well...I guess it's still raining\"\nDriving Instructor: \"Get out of the car\"\n*You have failed your test*\n*You can retake your test in 6 weeks*\n\n");
    break;
  case D1:
    printf("*You apologize*\n\n");
    printf("*You turn your head to apologize*\n*You loose sight of the road for one moment when a biker rolls out in front of you*\n*You nearly hit the biker*\n*You have failed your test*\n*You can retake your test in 6 weeks*\n\n");
    break;
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  }//res5ADCD switch
}//res5ADCD
    
char res5ACCC(){
  char res2;
  printf("What do you do next?\nA: Go through the Yield sign\nB: Slow down\nC: Honk\nD: Slowy stop\n\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You go through the yield sign*\n\n");
    printf("*You speed up to avoid the oncoming car*\n*The approaching car speeds up to get through before you*\n*The two cars nearly collide*\nDriving Instructor: \"Stop the car\"\n*You have failed your test*\n*You can retake your test in 6 weeks*\n\n");
    break;
  case B1:
    printf("*You slow down*\n\n");
    printf("*You apply pressure to the break but the car is going to fast*\n*You are stuck in the middle of the intersection and hit by the car*\n*You have failed your test*\n*You can retake yourtest in 6 weeks*\n\n");
    break;
  case C1:
    printf("*You honk*\n\n");
    printf("*The driver of the oncoming car hears your honk as a sign of aggression*\n*The driver stops and gets out of their car*\n*They go over to your car stopped at the Yield sign and initiates a fist fight*\n*You get a few licks in before the knock you out in the street*\n*You wake up 3 hours later in the hospital*\n*You have failed your test*\n*You can retake yourtest in 6 weeks*\n\n");
    break;
  case D1:
    printf("*You slowly stop*\n\n");
    printf("*The car properly stops before the Yield sign*\n*The oncoming car passes safely*\n*You continue straight*\n*The road wraps around back toward the DMV*\nDriving Instructor: \"You can pull back into the DMV parking lot and parallel park\"\n*There is an open space between two cars on the road and an open spot without any closer to the DMV door*\n\n");
    res6ACCCD();
    break;
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  }//res5ACCC switch
}//res5ACCC


char res5BAAB(){
  char res2;
  printf("What do you do next?\nA: Swerve\nB: Pull over\nC: Make a U-turn\nD: Hit the gas\n\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You swerve*\n\n");
    printf("*The car begins to fish-tail as you lose control*\n*You spin out*\n*The police immediatly surround you*\n*You are detetained and sentenced to 5 years in state Juvenile detention*\n\n");
    return(0);
    break;
  case B1:
    printf("*You pull over*\n\n");
    printf("*You slowly put the car into the shoulder of the road*\nDriving Instructor: \"WHAT ARE YOU DOING!?\"\n*The Driving Instructor smacks you in the head*\n*You black out*\n*Three days later you wake up in a Juvenile detention center*\n\n");
    return(0);
    break;
  case C1:
    printf("*You make a U-turn*\n\n");
    printf("*You turn hard left at the next U-turn opening on the freeway*\n*The police shoot the car's back tire out*\n*The police immediatly surround you*\n*You are detetained and sentenced to 5 years in state Juvenile detention center*\n\n");
    return(0);
    break;
  case D1:
    printf("*You hit the gas*\n\n");
    printf("*The car accelerates and you break away from the police*\n*As you speed forward and see an open bridge straight ahead*\n*The Driving Instructor puts his gun back into his waistband*\n");
    res6BAABD();
    break;
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  }//res5BAAB switch
}//res5BAAB

char res6ACCCD(){
  char res2;
  printf("What do you do next?\nA: Back the car in between the two cars\nB: Pull foward in between the two cars\nC: Put your blinker on\nD: Park in the open spot with no cars\n\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You back the car in between the two cars*\n\n");
    printf("*You successfully back the tail of the car inbetween the two and straighten it out  parallel parking the car*\nDriving Instructor: \"Congratulations you passed your test\nYou made 0 mistakes.\"\n*Congratulations you have passed your test*\n\n");
    break;
  case B1:
    printf("*Pull forward in between the two cars*\n\n");
    printf("*You put the front of the car between the two parked cars*\n*There is no space to straighten out the back of the car*\n*People gather to watch you struggle and people honk at you*\n*It takes 3 attempts but you finally parallel park the car*\nDriving Instructor: \"Congratulations you passed your test\nYou made 3 mistakes while parallel parking.\"\n*Congratulations you have passed your test*\n\n");
    break;
  case C1:
    printf("*You put your blinker on*\n\n");
    printf("*You grab the blinker handle and pull down*\n*You pull down a little to hard*\n*The handle snaps off the wheel*\n*You pull forward into the wide open parking spot*\nDriving Instructor: \"Congratulations you passed your test\nYou made 3 mistakes for not parallel parking\nHowever you must pay $280 for breaking the blinker handle\"\n*Congratulations you have passed your test*\n\n");
    break;
  case D1:
    printf("*You park in the open spot with no cars*\n\n");
    printf("*You easily pull forward into the open spot, but do not parallel park*\nDriving Instructor: \"Congratulations you passed your test\nYou made 3 mistakes for not parallel parking.\"\n*Congratulations you have passed your test*\n\n");
    break;
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  }//res6ACCCD switch
}//res6ACCCD

char res6ADCDB(){
  char res2;
  printf("What do you do next?\nA: Refuse to park & ask for another try\nB: Pull forward into the spot\nC: Back into the spot\nD: Parallel park \n\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You refuse to park & ask for another try*\n\n");
    printf("Driving Instructor: \"No. Get out of the car\"\n*You have failed your test*\n*You can retake your test in 6 weeks*\n\n");
    break;
  case B1:
    printf("*You pull forward into the spot*\n\n");
    printf("*You turn the car off*\n*The Driving Instructor writes on his clipboard*\nDriving Instructor:\"Congratulations you passed your test\nYou lost 3 points for turning the radio on and sneezing in my mouth.\"\n*Congratulations you have passed your test*\n\n");
    break;
  case C1:
    printf("*You back into the spot*\n\n");
    printf("*You back up and hit the curb and turn the car off*\n*The Driving Instructor writes on his clipboard*\nDriving Instructor:\"Congratulations you passed your test\nYou lost 4 points for turning the radio on, sneezing in my mouth, and hitting the curb.\"\n*Congratulations you have passed your test*\n\n");
    break;
  case D1:
    printf("*You parallel park*\n\n");
    printf("*You back into between the two cars and hit the headlight of the parked car*\nDriving Instructor: \"You just hit my car\"\n*You turn the car off*\n*The Driving Instructor writes on his clipboard*\nDriving Instructor: \"You have failed the test\nYou lost 5 points for\nTurning on the radio\nSneezing in my mouth\nAnd hitting my car\"\n*You have failed your test*\n*You can retake your test in 6 weeks*\n\n");
    break;
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  }//res6ADCDB switch
}//res6ADCDB
   

char res6BAABD(){
  char res2;
  printf("What do you do next?\nA: Tuck and roll\nB: Speed up\nC: Make a U-turn\nD: Get off the freeway\n\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You tuck and roll*\n\n");
    printf("*You open the car door, tuck, and roll out*\n*The car is going to fast*\n*When you hit the pavement you immediatly pass out*\n*You wake up 5 months later in a Juvenile detention center*\n\n");
    return(0);
    break;
  case B1:
    printf("*You speed up*\n\n");
    printf("*The open bridge approaches faster and faster*\nDriving Instructor: \"Are you in? Or are you out?\"\n\n");
    res7BAABDB();
    break;
  case C1:
    printf("*You make a U-turn*\n\n");
    printf("*You begin to turn the wheel to U-turn left*\n*The car is going too fast*\n*The car rolls three times before landing upside down*\nYou wake up 7 months later in a Juvenile detention center*\n\n");
    return(0);
    break;
  case D1:
    printf("*You get off the freeway*");
    printf("*You turn right off the freeway*\n*When you get onto the off ramp, the police lay out a spike strip*\n*The car tires explode and you skid into the ditch*\n*The police immediatly surround you*\n*You are detetained and sentenced to 5 years in state Juvenile detention*\n\n");
    return(0);
    break;
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  }//res6BAABD switch
}//res6BAABD

char res7BAABDB(){
  char res2;
  printf("What do you do next?\nA: Remain silent\nB: Out\nC: In\nD: Pretend you didn't hear him\n\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You remain silent*\n\n");
    printf("*The Driving Instructor opens your door and pushes you out of the car*\n*The police immediatly surround you*\n*You are detetained and sentenced to 5 years in state Juvenile detention*\n\n");
    return(0);
    break;
  case B1:
    printf("*You say out*\n\n");
    printf("*The Driving Instructor opens your door and pushes you out of the car*\n*The police immediatly surround you*\n*You are detetained and sentenced to 5 years in state Juvenile detention*\n\n");
    return(0);
    break;
  case C1:
    printf("*You say you are in*\n\n");
    printf("Driving Instructor: \"That's my guy!\nOkay when the car makes it over the bridge jump out of the car!\"\n*The car speeds up and over the bridge*\n*The car goes airborne over the Chicago river*\nTime freezes while you are flying in the car*\n\n");
    res8BAABDBC();
    break;
  case D1:
    printf("*You pretend you didn't hear him*\n\n");
    printf("*The Driving Instructor opens your door and pushes you out of the car*\n*The police immediatly surround you*\n*You are detetained and sentenced to 5 years in state Juvenile detention*\n\n");
    return(0);
    break;
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  }//res7BAABD switch
}//res7BAABD

char res8BAABDBC(){
  char res2;
  printf("What do you do next?\nA: Stay in the car\nB: Jump out of the car\n\n");

  scanf(" %c",&res2);

  switch (res2>='a' && res2<= 'z' ? res2-32 : res2) {
  case A1:
    printf("*You stay in the car*\n\n");
    printf("*The car flies through the air*\n*The front tires clip the bridges edge*\n*The car teeter back and falls into the water*\n*You escape through the sunroof*\n*The police immediatly surround you*\n*You are detetained and sentenced to 5 years in state Juvenile detention*\n\n");
    return(0);
    break;
  case B1:
    printf("*You jump out of the car*\n\n");
    printf("*You fall thirty feet down towards the Chicago river*\n*At the last moment, a speed boat breaks your fall with a CFD safety net*\n*The boat takes you to a plane*\n*You and the Driving Instructor escape to Milan*\n*The Driving Instructor splits the money he stole with you*\n*You begin a new life as a billionaire in Zanzibar*\n\n*Congratulations you passed your drivers exam*\n\n");
    break;
  default:
    printf("\nPlease enter one of the specified commands\n\n");
  }//res8BAABDC switch
}//res8BAABDC
    
