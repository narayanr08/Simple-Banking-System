#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//Global variables
unsigned long amt, dpst, wtdn;
int count = 0;

struct complex //Structure for no particular reason
{
	char cardno[13];
	char name[20];	
};

int input() //Function to input details
{
	int pin;
	struct complex extra;
	struct complex *nouse;	
	
	nouse = &extra;
	
	printf("Welcome to the Complex Bank\n");
	printf("Enter your details.\n\n");
	printf("Enter your card number.\n");
	scanf("%s", nouse->cardno);
	
	printf("Enter your name.\n");
	scanf("%s", nouse->name);
	
	printf("\nCard Number: %s\n", nouse->cardno);
	printf("Name: %s\n\n", nouse->name);
	
	printf("Enter your pin.\n");
	scanf("%d", &pin);
	
	check(pin);
	
	return 0;
}

int check(int pin) //Function to check for the correct pin
{
	while(pin!=0000)
	{
		printf("\n*Incorrect Pin*\n");
		count++;
		printf("Please try again.\n");
		scanf("%d", &pin);
		if(count==3)
		{
			printf("\nYou have entered the wrong pin too many times.\n");
			printf("Please try again later.\n");
			continue;
		}
	}
	
	return 0;
}

int perform() //Function to perfrom ATM functions
{
	int ch, k;
	char ch1 = 'y';
	
	printf("\nEnter your current balance.\n");
	scanf("%lu", &amt);
	
	do
	{   printf("Enter your choice.\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw Cash\n");
        printf("3. Deposit Cash\n");
        printf("4. Calculate Interest\n");
        printf("5. Quit\n\n");
    
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
		switch (ch)
		{
			case 1: balance();
					break;
			
			case 2: withdraw();
					break;
			
			case 3: deposit();
					break;
					
			case 4: calcintrst();
					break;
					
			case 5: goto x;
					break;
			
			default: printf("Invalid Choice\n");
		}
		
		printf("\nDo you wish to conduct another transaction? (y/n): \n");
		fflush(stdin);
        scanf("%c", &ch1);
        
		if (ch1 == 'n'|| ch1 == 'N')
        {
        	k = 1;
		}
    
	} while (!k);
	
	x: printf("\nThank you for using this ATM\n");
	   printf("Please visit again\n");
	
	return 0;	
}

int balance() //Function to check balance
{
	printf("\nYour balance is Rs. %lu. \n", amt);
    return 0;
}

int withdraw() //Function to withdraw money
{
	do
	{	
		printf("\nEnter your amount to be withdrawn.\n");
    	scanf("%lu", &wtdn);
    	
		if(wtdn % 100 != 0)
		printf("Please enter the amount in multiples of 100.\n");
    }while (wtdn % 100 != 0);
    
	if (wtdn > (amt - 500))
    {
        printf("Insufficient Balance\n");
    }
            
	else
    {
    	amt = amt - wtdn;
        printf("Your current balance is Rs. %lu. \n", amt);
    }
    
    return 0;
}

int deposit() //Function to deposit money
{
	printf("\nEnter the amount to be deposited.\n");
    scanf("%lu", &dpst);
	amt = amt + dpst;
    printf("Your new balance is Rs. %lu.\n", amt);
    
    return 0;
}

int calcintrst() //Function to calculate interest for the balance
{
	int i,t;
	double ci,p;
	ci = 0;
	
	p = amt;
	printf("\nEnter the time in years for which you want to check interest.\n");
	scanf("%d", &t);
	
	for(i = 0; i >= t; i++)
	{
		ci += p*0.1;
		p = ci;
	}
	
	printf("Your amount after %d years will be Rs. %f.", t, ci);
}

int main()
{
	input();
	perform();
	
	struct tm *ptr;
	time_t lt;
	lt = time(NULL);
	ptr = localtime(&lt);
	printf(asctime(ptr));
	return 0;
	
	getch();

}
