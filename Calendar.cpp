// TODO: add your code to this file
#include<stdio.h>
#include <math.h>

/**
prototypes for functions defined later
**/
int days_in_month(int month, int year);
bool is_leap_year(int year);
int get_jdn(int month, int year, int day);

int main(void){
	//non-temporary variables declared here
	int month, year, monthDays, weekday;
	bool valid=false;
	
	//gather input from user
	printf("Enter month and year: ");
	scanf("%i %i", &month, &year);
	//check if valid
	while(!valid){
		if(month>=1 && month<=12){
			valid=true;
		}
		else{
			printf("Invalid month: please enter a month value in the range 1-12.\n");
			printf("Enter month and year: ");
			scanf("%i %i", &month, &year);
		}
	}
	
	//get days in the month, will internally check for leap years
	monthDays = days_in_month(month, year);
	
	//calculate day of week
	weekday=get_jdn(month, year, 1);
	
	//print results
	printf("This month has %i days\n", monthDays);
	printf("The first day of that month is ");
	if(weekday%7==0){
		printf("Monday");
	}
	else if(weekday%7==1){
		printf("Tuesday");
	}
	else if(weekday%7==2){
		printf("Wednesday");
	}
	else if(weekday%7==3){
		printf("Thursday");
	}
	else if(weekday%7==4){
		printf("Friday");
	}
	else if(weekday%7==5){
		printf("Saturday");
	}
	else if(weekday%7==6){
		printf("Sunday");
	}
	else{
		printf("broken.");
	}
	return 0;
}//end main


//returns days of the month
int days_in_month(int month, int year){
	int output;
	if(month==2){
		bool leapYR=false;
		leapYR=is_leap_year(year);
		if(leapYR){
			output=29;
		}
		else{
			output=28;
		}
	}
	else if(month==9 || month==4 || month==6 || month==11){
		output=30;
	}
	else{
		output=31;
	}
	
	return output;
}

//checks if a leap year was entered, responds with true/false
bool is_leap_year(int year){
	if(year%4==0 && year%100!=0){
		return true;
	}
	else if(year%400==0){
		return true;
	}
	return false;
}

//returns the JDN
int get_jdn(int month, int year, int day){
	int jdn=0;
	jdn=((1461 * (year + 4800 + (month - 14)/12))/4 +(367 * (month - 2 - 12 * ((month - 14)/12)))/12 - (3 * ((year + 4900 + (month - 14)/12)/100))/4 + day - 32075);
	return jdn;
}