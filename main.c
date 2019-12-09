//First actual version of main to pull
#include <stdio.h>
#include <string.h>

int permittestPass = 0;

typedef struct{
	int day;
	int month;
	int year;
}permitDate;

typedef struct{
	int day;
	int month;
	int year;
}age;

int permitTest();

int i; //counter
int j; //another counter

int main(void){

permitTest();

  return(0); //main return
} //main

int permitTest(){
	char one,two,three,four,five,six,seven,eight,nine,ten;
	permitDate d;
	age a;
	int counter = 0;
	int driversTest = 0;


	printf("				Permit Test\n\n\n");
	printf("	*You arrive at the DMV with your Mother to take your permit test.*\n\n	*You grab the Permit Test form and begin to fill it out.*\n\n");

	printf("		Please Enter today's date (MM/DD/YYYY)\n");
	scanf("%d%d%d", &d.month, &d.day, &d.year);
//	printf("			%d/%d/%d", d.month, d.day, d.year);

	printf("\n\n		Please Enter your Date of Birth (MM/DD/YYYY)\n");
	scanf("%d%d%d", &a.month, &a.day, &a.year);
//	printf("			%d/%d/%d", a.month, a.day, a.year);

	if((a.month*30.4166) + (a.day) + (d.year - a.year)*365 >= 5657.5){ //Checking to see if the test taker is at least 15.5 (5657.5 days) old
		printf("	You may take the permit test\n\n");
		printf("	*You turn in your paperwork to the only DMV employee working today.\n	You find it little odd that there is only one worker at the DMV today.\n	He looks it over carefully, and then places it in in a file folder.\n	He tells you to go to computer terminal C to take your test.\n\n");
		printf("\n\n	You sit down at the terminal and begin the test\n\n");

	}
	else{
		printf("	You are not old enough to take the permit test. Come back when you are at least 15.5 years old");
		return(0);
	}

		printf("\n\n\n	You are taking the California State Driver's Permit Test.\n\n	This test will be 10 questions long.\n	You must answer 80%% of the questions correctly to pass.\n\n");

		printf("	1)  In which of the following scenarios should your car wheels not be pointed straight ahead?\n\n	a)  When waiting to make a left turn at a traffic light\n	b)  When parked on a hill or sloping driveway\n	c)  when parked on the side of a level roadway where there is no curb\n");
		scanf(" %c", &one);

		if(one == 'b'){
			counter++;
		}

		printf("	\n\n\n	2)  You should increase the distance between your vehicle and the vehicle ahead when you:\n\n	a)  Are following a small passenger vehicle\n	b)  Are being tailgated by another driver\n	c)  Are driving more slowly than the posted speed limit\n\n\n");
		scanf(" %c", &two);

		if(two == 'b'){
			counter++;
		}

		printf("	3)  When Driving under snowy or icy conditions:\n\n	a)  It is safe to use cruise control\n	b)  Make speed and directional changes more gradually than you would otherwise\n	c)  Driver as you would under normal conditions\n\n\n");
		scanf(" %c", &three);

		if(three == 'b'){
			counter++;
		}

		printf("	4)  When being followed by a tailgater, which of the following will is the best course of action to take?\n\n	a)  Scare the driver behind you by slamming the breaks\n	b)  Speed away from the tailgater\n	c)  Merge into another lane\n\n\n");
		scanf(" %c", &four);

		if(four == 'c'){
			counter++;
		}

		printf("	5)  A broken yellow centerline means\n\n	a)  Passing on the left is permitted when the way ahead is clear\n	b)  Passing is not permitted\n	c)  Passing is permitted if the car in front of you signals you to pass them\n\n\n");
		scanf(" %c", &five);

		if(five == 'a'){
			counter++;
		}

		printf("	6)  If a bicycle on your right reaches an intersection at the same time as you do, you should:\n\n	a)  Yield to the bicycle\n	b)  move slowly along with the bicycle\n	c)  Move because you have the right of way\n\n\n");
		scanf(" %c", &six);

		if(six == 'a'){
			counter++;
		}
		printf("	7)  Four cars are at a 4-way intersection, an ambulance, a firetruck, a squad car, and a funeral procession, which one has the right of way?\n\n	a)  The funeral procession\n	b)  The squad car\n	c)  The Fire Truck\n	d)  The ambulance\n\n\n");
		scanf(" %c", &seven);

		if(seven == 'c'){
			counter++;
		}

		printf("	8)  You should use _____ steering when correcting a skid\n\n	a)  hand-over-hand\n	b)  one-hand\n	c)  10 & 2 steering\n\n\n");
		scanf(" %c", &eight);

		if(eight == 'a'){
			counter++;
		}

		printf("	9)  A driver in front of you is signaling with their hand and arm pointing upward, this driver wants to...\n\n	a)  Stop\n	b)  Turn Right\n	c)  Turn Left\n\n\n");
		scanf(" %c", &nine);

		if(nine == 'b'){
			counter++;
		}

		printf("	10)  When driving in fog, rain, or snow, use:\n\n	a)  Low Beams\n	b)  High Beams\n	c)  Fog Lights only\n\n\n");
		scanf(" %c", &ten);

		if(ten == 'a'){
			counter++;
		}

		if(counter >= 8){
			printf("	Congradulations!\n	You have passed your permit test. Come back in 6 months to get your drivers test");
			permittestPass++;
		}
		else{
			printf("	You have failed your driver's test. What the heck man.");
			printf("\n\n\n	You turn around disappointed. You meet the DMV employee's eyes.\n\n	A single tear rolls down your cold cheek.\n\n	The DMV employee stares back, unable to feel sympathy.\n\n	The life sucking blackhole that is his goverment has reduced him into a cold, calcualting, unfeeling machine.\n\n	He looks you and says 'Come back in 6 weeks.'");
		}

return(0);
}
