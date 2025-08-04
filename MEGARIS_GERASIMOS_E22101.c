#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ta parapanw preprocessor commands epitrepoun tin xrisi orismenwn entolwn parakatw, prostithetai to string.h me skopo thn xrhsimopoihsh strings kai tin sigkrisi tous

/*to programma auto kanei emulate ena systima pou xrisimopoiei mia etairia enoikiasis autokinitwn kathws kai oi xristes tis. mesa apo to sistima o admin ( kapoios upallilos h upeuthinos tis etairias) mporei
na kanei allages sta rates gia tin enoikiasi, enw oi xristes mporoun na allilepidrasoun kanontas orismenes energeies*/

char user[],pass[7];
int signcheck=0; //global metabliti pou leitourgei os flag gia to an exei kanei eggrafi h oxi o xristis
int exc=0; //ulopoiei to logout @39,521
int exu=0; //metabliti pou epitrepei ston user na epistrepsei sto user menu @584
int exr=0; //metabliti pou epitrepei ston admin na epistrepsei sto root menu @LINE 418
int chcalcost=0; //elegxos gia to an exei ginei calculate to kostos 566
int chpay=0;//elegxos gia to an exei ginei h pliromi @575
float gcost; //h gcost (global cost) apothikeuei to kostos pliromis tou xristi gia na ginei epita o elegxos kata to payment stin grammi @149
char ruser[]="root",rpass[]="Root123"; 

//global metablites gia to receipt, lines addlines, lambanoun times apo tin calculate_cost
int gdays,gage,gcarcc,chcard;
float gdaycost,gdisc,gamount,grate;	
char gccnum[17];

//ta rates twn asfalistrwn einai global metablites pou arxikopoiountai edw
float r1=0.00052;
float r2=0.00043;
float r3=0.00028;
																		
void terminate(void) { //h termiante void xrisimopoiei tin exit(0) tis stdlib me skopo na termatisei to programma
	printf("Program terminating...");
	sleep(3);
	system("cls");
    exit(0);  
}

void logout(void) {
	printf("Exiting to main menu...");
	sleep(3);
	exc=1; //xreiazetai gia ton elegxo stin grammi 521
}

//END OF GENERIC FUNCTIONS 

void signup_user(void){ //ulopoiei to singup tou xristi xrisimopoiontas global metablites 
	printf("Please enter a username:");
	scanf("%s", user);
	do{
		printf("Please enter a password that consists of 6 characters:");	
		scanf("%6s", pass);
		if (strlen(pass)!=6){
			printf("Wrong input, please try again!\n");
		}
	}
	while (strlen(pass)!=6);
	signcheck=1;
	system("cls");
}

void calculate_cost (void){ //upologizei to kostos tis enoikiasis
	int carcc,age,days;
	char am[6]="E22101";
	float dcost,scost,tcost;//dcost days cost, scost safety cost, tha prostethoun argotera gia na bgei to tcost=total cost
	printf("Please enter your age:");
	scanf("%d",&age);
	gage=age;//xrisimopoieitai epeita gia tin apodeiji, global metabliti
	printf("Please enter the cubic centimeters of the car you would like to rent:");
	scanf("%d",&carcc);
	gcarcc=carcc;//xrisimopoieitai epeita gia tin apodeiji, global metabliti
    days=atoi(am+4); //ta duo teleutaia characters ginontai int
    days=days/10+days%10; //me to days/10 briskoume to 5o character tou string kai me to days%10 to ekto, epeita ta prosthetoume kai exoume tis imeres enoikiasis
    gdays=days;//xrisimopoieitai epeita gia tin apodeiji, global metabliti
    if (age>=18 && age<=22){ //pollapli epilogi gia ilikia
    	scost=age*r1*carcc;//upologismos kostous asfaleias me xrisi twn global rates 
    	grate=r1;//xrisimopoieitai epeita gia tin apodeiji, global metabliti
	}
	else if (age>22 && age<=30) {
		scost=age*r2*carcc;
		grate=r2;//xrisimopoieitai epeita gia tin apodeiji, global metabliti
	}
	else if (age>30) {
		scost=age*r3*carcc;
		grate=r3;//xrisimopoieitai epeita gia tin apodeiji, global metabliti
	}
	if (carcc>=0 && carcc<=1600){ //pollapli epilogi ana kubika kai epeita emfoleumeni ana imeres
    	if (days>0 && days<=5){
			dcost=11.42*days;//upologismos kostous gia kathe mera analoga me ta kubika kai to plithois ton imeron
		}
		else if(days>=6 && days<=10){
			dcost=13.82*days;
		}
		else{
			dcost=16.22*days;
		}
	}
	else if(carcc>=1601 && carcc<=2000){
		if (days>0 && days<=5){
    		dcost=10.22*days;	
		}
		else if(days>=6 && days<=10){
			dcost=12.16*days;	
		}
		else{
			dcost=15.10*days;	
		}
	}
	else{
		if (days>0 && days<=5){
    		dcost=9.15*days;
		}
		else if(days>=6 && days<=10){
			dcost=10.62*days;
		}
		else{
			dcost=13.80*days;	
		}
	}
	tcost=dcost+scost;
	printf("The total cost for your car rental is: %.6f", tcost);
	gcost=tcost; //h global gcost pou tha xrisimopoiithei epeita (opws leme kata tin arxikopoiisi tis stin grammi 16) lambanei tin timi tis local tcost
	chcalcost=1; //allazei h timi tis global metablitis gia ton elegxo tou an exei ginei calculation tou kostous gia na probei epeita o xristis se payment, line 566 (see 14(
	gamount=tcost;//xrisimopoieitai epeita gia tin apodeiji, global metabliti
	gdaycost=dcost;//xrisimopoieitai epeita gia tin apodeiji, global metabliti
	sleep(5);
}

void payment(void){
	char ch[5];// card/cash lejeis me 4 grammata + 1 space gia to escape character
	float paym;//h metabliti pou apothikeuei to poso pou eisagei o xristis os pliroteo
	if (chcalcost==1){
		printf("You can pay the %f with either card or cash, please type the corresponding choice:", gcost);
		scanf("%s", ch);
		if (strcmp(ch,"card")==0){
			chcard=1;//xrisimopoieitai epeita gia tin apodeiji, global metabliti
			gdisc=0.15*gcost;//xrisimopoieitai epeita gia tin apodeiji, global metabliti
			gcost=gcost-0.15*gcost;
			printf("\nYour new total is %f\n", gcost);
			do{
				printf("Please input your credit card number:");
				scanf("%16s", gccnum);
				if (strlen(gccnum)!=16){
					printf("\nYour credit card should consist of 16 numbers, please try again...\n");
				}
			}
			while (strlen(gccnum)!=16);
			printf("Please input the amount you need to pay:");
			do{
				chpay=0;
				scanf("%f",&paym);
				if (paym==gcost){
					printf("Successful payment, redirecting to user menu...");
					chpay=1;
				}
				else{
					printf("The amount you entered wasn't the right one, please try again...'");
				}
			}
			while (chpay==0);
		}
		else if (strcmp(ch,"cash")==0){
			printf("Please input the ammount you need to pay:");
			do{
				scanf("%f",&paym);
				if (paym==gcost){
					printf("Successful payment, redirecting to user menu...");
					chpay=1;
				}
				else{
					printf("The ammount you entered wasn't the right one, please try again...");
				}
			}
			while (chpay==0);
		}
		sleep(3);
	}
}


void get_receipt(void){
	int i;
	printf("************************************************************\n");
	for (i = 0; i < 23; i++) {
    	if (i == 0) {
      		printf("*  			CarRental S.A.                	   *\n");
    	}
    	else if (i == 4){
			printf("*	-Days:			%d	(%.2f EUR / day)  *\n", gdays, gdaycost);	
			printf("*	-Driver Age:		%d	(%.5f / CC)	   *\n", gage, grate);
			printf("*	-Engine CC:		%d			   *\n", gcarcc);
		}
		else if (i == 9){
			printf("*			PAYMENT DETAILS			   *\n");
		}
		else if (i == 11){
			printf("*	- AMOUNT:		%.2f EUR		   *\n",gamount);
			if (chcard==1){
				printf("*	-Pay with Credit Card? 		Y		   *\n");
				printf("*	-Discount (15%):		%.2f EUR 	 	   *\n", gdisc);
			}
			else{
				printf("*	-Pay with Credit Card? 		N		   *\n");
				printf("*	-Discount (15%):		- EUR			   *\n");
			}
			printf("*	-TOTAL AMOUNT:		%.2f EUR	    	   *\n",gcost);
		}
		else if (i == 17){
			printf("*			CREDIT CARD			   *\n");
		}
		else if (i == 20){
			if(chcard==1){
				char d1[5], d2[5], d3[5], d4[5]; //ftiaxnouime 4 substrings me xoritikotita 4 xaraktirwn (reserve 1 slot gia to escape char)
				strncpy(d1,gccnum, 4);  // to d1 einai ta prota 4 psifia tis pistotikis, to d2 ta 5-8, to d3 ta 9-12 kai to d4 ta 13-16
				d1[4] = '\0';  //prosthetei to escape characdter
				strncpy(d2, gccnum + 4, 4); 
	    		d2[4] = '\0';
	    		strncpy(d3, gccnum + 8, 4);  
	    		d3[4] = '\0';
	    		strncpy(d4, gccnum + 12, 4);  
				d4[4] = '\0';
				printf("*	-Credit card number:				   *\n");
				printf("*		%s %s %s %s 			   *\n", d1, d2, d3, d4);
			}
			else{
				printf("*		  No credit card was used 		   *\n");
			}
		}
		else {
			printf("*                                                          *\n");
    	}
	}
	printf("************************************************************\n");
	sleep(5);
}

void login_user(void); // h login ulopoieitai katw apo tin main 

void exit_user(void){ //ulopoiei tin epistrofi sto menu tou xristi 560
	printf("Exiting to user menu...");
	sleep(3);
	exu=1;
	system("cls");
}



//END OF USER FUNCTIONS

void exit_root(void){ //ulopoiei tin epistrofi tou root sto root menu 412
	printf("Exiting to root menu...");
	sleep(3);
	exr=1;
	system("cls");
}

void change_cost(void){ //dinei tin dinatotita ston admin na allajei ta rates gia tin asfalisi-line 415
	int i;
	char ch;
	printf("************************************************************\n");
	for (i = 0; i < 23; i++) {
    	if (i == 8) {
      		printf("*  		Please input your choice:                  *\n");
    	}
		else {
      		printf("*                                                          *\n");
    	}
    	if (i == 11){	
    		printf("*		1. Change rate for 0-1600 cc	   	   *\n");
			printf("*		2. Change rate for 1601-2000 cc            *\n");	
			printf("*		3. Change rate for over 2000 cc 	   *\n");	
		}
	}
	printf("************************************************************\n");
	printf("  	 Input the number of your choice here:"); //kanei to ui pio omorfo/filiko - kamia xrisimotita
	scanf(" %c", &ch);//xrisi tis ch jana, ejoikonomisi mnimis
	system("cls");
	char ch1[7]; //xrisimopoietai gia na kanei ton elegxo raise/lower
	int per;
	if (ch=='1'){
		printf("You chose to change the first rate, would you like to raise it or lower it?");
		scanf("%6s", ch1);
		if ((strcmp(ch1,"raise"))==0){
			printf("Input the percentage you would like to raise the rate, it cannot be over 10%:");
			int rcc=0;//rate change check, an to per>10 to janazitaei 
			do{
				scanf("%d", &per);				
				if (per<=10){
					r1=r1+r1*per/100;
					rcc=1;
				}
				else{
					printf("The rate you inputted was too high, please try again!");
				}
			}
			while(rcc==0);
		}
		else if ((strcmp(ch1,"lower"))==0){
			printf("Input the percentage you would like to lower the rate, it cannot be over 10%:");
			int rcc=0;//rate change check, an to per>10 to janazitaei 
			do{
				scanf("%d", &per);				
				if (per<=10){
					r1=r1-r1*per/100;
					rcc=1;
				}
				else{
					printf("The rate you inputted was too high, please try again!");
				}
			}
			while(rcc==0);
		}
	}
	else if(ch=='2'){
		printf("You chose to change the second rate, would you like to raise it or lower it?");
		scanf("%6s", ch1);
		if ((strcmp(ch1,"raise"))==0){
			printf("Input the percentage you would like to raise the rate, it cannot be over 10%:");
			int rcc=0;//rate change check, an to per>10 to janazitaei 
			do{
				scanf("%d", &per);				
				if (per<=10){
					r2=r2+r2*per/100;
					rcc=1;
				}
				else{
					printf("The rate you inputted was too high, please try again!");
				}
			}
			while(rcc==0);		
		}
		else if ((strcmp(ch1,"lower"))==0){
			printf("Input the percentage you would like to lower the rate, it cannot be over 10%:");
			int rcc=0;//rate change check, an to per>10 to janazitaei 
			do{
				scanf("%d", &per);				
				if (per<=10){
					r2=r2-r2*per/100;
					rcc=1;
				}
				else{
					printf("The rate you inputted was too high, please try again!");
				}
			}
			while(rcc==0);
		}
	}
	else if(ch=='3'){
		printf("You chose to change the third rate, would you like to raise it or lower it?");
		scanf("%6s", ch1);
		if ((strcmp(ch1,"raise"))==0){
			int rcc=0;//rate change check, an to per>10 to janazitaei 
			do{
				printf("Input the percentage you would like to raise the rate, it cannot be over 10%:");
				scanf("%d", &per);				
				if (per<=10){
					r3=r3+r3*per/100;
					rcc=1;
				}
				else{
					printf("The rate you inputted was too high, please try again!");
				}
			}
			while(rcc==0);
		}
		else if ((strcmp(ch1,"lower"))==0){
			printf("Input the percentage you would like to lower the rate, it cannot be over 10%:");
			int rcc=0;//rate change check, an to per>10 to janazitaei 
			do{
				scanf("%d", &per);				
				if (per<=10){
					r3=r3-r3*per/100;
					rcc=1;
				}
				else{
					printf("The rate you inputted was too high, please try again!");
				}
			}
			while(rcc==0);
		}
	}
}

void login_root(void){ //ulopoiei to login tou administrator xrisimopoiontas tis global metablites ruser kai rpas
	char iuser[13], ipass[13]; /*tha bazame 5 kai 8 gia ejoikonomisi mnimis alla den to kanoume kathws ean o user grapsei p.x. root123 to programma
	tha diabasei mono to root kai etsi tha exoume problima me tin asfaleia tou sustimatos, kanoume tis metablites na exoun ena mesaio megethos, estw 12*/
	int i;
	char ch; //local metabliti ch, den epireazei to upoloipo programma, apothikeuei tin epilogi tou root
	printf("Please type the username that is used to login as an admin:");
	scanf("%12s", iuser);
	printf("Please type the password that is used to login as an admin:");
	scanf("%12s", ipass);
	if ((strcmp(ruser,iuser)==0)&&(strcmp(rpass,ipass)==0)){ //tsekarei oti to username kai to password pou edwse o xristis kata to login einai ta idia me ta prokathorismena apo ton admin
		exr=0; //resets login status
		do
		{
			printf("************************************************************\n");
			for (i = 0; i < 23; i++) {
    			if (i == 8) {
      				printf("*  		Please input your choice:                  *\n");
    			}
				else {
      				printf("*                                                          *\n");
    			}
    			if (i == 11){	
    				printf("*		  a. Change cost		   	   *\n");
   					printf("*		  b. Exit			       	   *\n");	
				}
			}
			printf("************************************************************\n");
			printf("	Input the letter of your choice here:"); //kanei to ui pio omorfo/filiko - kamia xrisimotita
			scanf("%c", &ch);
			system("cls");
			if (ch=='b'){
				exit_root();
			}
			else if (ch=='a'){
				change_cost();
			}
		}
		while (exr==0);
	}
	else {
		system("cls");
		printf("Wrong input,please try again! Redirectring to root menu...");
		sleep(2);
	}
}

int main(int argc, char *argv[]) {
	int i;
	char ch[4]; //array size=4 epeidh to megalitero input einai root h user pou exoun 4 grammata, ejoikonomei mnimi
	do{
		// emfanisi panw asteriwn
		printf("************************************************************\n");
		// emfanisi aristera-dejia + ston xristi
		for (i = 0; i < 23; i++) {
    		if (i == 8) {
      			printf("*  		Please input your choice:                  *\n");
    		}
			else {
      			printf("*                                                          *\n");
    		}
    		if (i == 11){	
    			printf("*			root				   *\n");
   				printf("*			user				   *\n");	
    			printf("*		0 - exit the program			   *\n");
			}
  		}
		// emfanisi katw asteriwnz
		printf("************************************************************\n");
		printf("		Input text here:"); //kanei to ui pio omorfo/filiko - kamia xrisimotita
		scanf("%s", ch);
		system("cls"); //katharizei tin othoni apo ta teleutaia outputs
		if (strcmp(ch, "user") == 0) { //h strcmp kanei output 0 otan einai omoia
			exc=0; //arxikopoiei tin exc kathe fora pou mpainoume stin if
			do{
				printf("************************************************************\n");
				for (i = 0; i < 23; i++) {
    				if (i == 8) {
      					printf("*  		Please input your choice:                  *\n");
    				}
					else {
      					printf("*                                                          *\n");
    				}
    				if (i == 11){	
    					printf("*			1. Sign Up			   *\n");
   						printf("*			2. Login			   *\n");	
    					printf("*			3. Logout			   *\n");
					}
  				}
				printf("************************************************************\n");
				printf("		Input number here:");
				scanf("%c", &ch); //xrisi tis ch jana gia ejoikonomisi mnimis
				system ("cls");
				if (*ch=='3'){
					logout();
					system("cls");
				}
				else if (*ch=='1'){
					signup_user();
				}
				else if (*ch=='2'){
					if (signcheck==1){
						login_user();
					}				// o elegxos xrisimopoieitai me skopo o xristis na pliroforithei oti xreiazetai prota na kanei sign up kai meta login
					else{
						printf("You haven't signed up yet. Please sign up and then login.\n"); 
						sleep(5); // dinei xrono ston xristi na diabasei to minima prin ton petajei sto arxiko menu
						system("cls");
					}	
				}
    		}
    		while (exc==0);//xrisimopoieitai gia tin ilopoiisi tis periptosis d meta to login tou xristi, allazei episis kata to logout
    	}
    	if (strcmp(ch, "root") == 0) { //h strcmp kanei output 0 otan einai omoia
    		exc=0; //arxikopoiei tin exc kathe fora pou mpainoume stin if
			do{
       	 		printf("************************************************************\n");
				for (i = 0; i < 23; i++) {
    				if (i == 8) {
      					printf("*  		Please input your choice:                  *\n");
    				}
					else {
      					printf("*                                                          *\n");
    				}
    				if (i == 12){	
    					printf("*			1. Login			   *\n");
   						printf("*			2. Logout			   *\n");	
					}
  				}
				printf("************************************************************\n");
				printf("		Input number here:");
				scanf("%c", &ch); //xrisi tis ch jana gia ejoikonomisi mnimis
				system("cls");
				if (*ch=='1'){
					login_root();
				}
				else if (*ch=='2'){
					logout();
					system("cls");
				}
    		}
    		while (exc==0);//xrisimopoieitai gia tin ilopoiisi tis periptosis b meta to login tou root, brisketai entos tis logout
    	}
	}
	while (*ch!='0');//otan o xristis dwsei os input to 0 to programma termatizei, xrisimopoiontas to function terminate();
	terminate();
	return 0;
}

void login_user(void){
	int i;
	char ch1; //nea metabliti gia to input tou xristi
	char iuser[100], ipass[7];//iuser kai ipass einai oi local metablites pou tha xrisimopoiei - dinei o xristis gia to login tou afou kanei signup
	printf("Please type the username you singed up with:");
	scanf("%s", iuser);
	printf("Please type the password you signed up with:");
	scanf("%6s", ipass);
	if ((strcmp(user,iuser)==0)&&(strcmp(pass,ipass)==0)){ //tsekarei oti to username kai to password pou edwse o xristis kata to signup kai to login einai ta idia
		do{
			exu=0; //resets login status
			printf("************************************************************\n");
			for (i = 0; i < 23; i++) {
    			if (i == 8) {
      				printf("*  		Please input your choice:                  *\n");
    			}
				else {
      				printf("*                                                          *\n");
    			}
    			if (i == 11){	
    				printf("*		  a. Calculate Cost			   *\n");
   					printf("*		  b. Payment			       	   *\n");	
    				printf("*		  c. Receipt				   *\n");
    				printf("*		  d. Exit				   *\n");
				}
			}
			printf("************************************************************\n");
			printf("	Input the letter of your choice here:"); //kanei to ui pio omorfo/filiko - kamia xrisimotita
			scanf("%c", &ch1);
			system("cls");
			if (ch1=='d'){
				exit_user();
			}
			else if(ch1=='a'){
				calculate_cost();
			}
			else if(ch1=='b'){
				if (chcalcost==1){
					payment();
				}
				else{
					printf("Please calculate the cost of your rental first!");
					sleep(3);
				}
			}
			else if(ch1=='c'){
				if (chpay==1){
					get_receipt();
				}
				else{
					printf("Please pay for your rental service first!");
					sleep(3);
				}
			}
		}
		while (exu==0);
	}
	else{
		system("cls");
		printf("Wrong input, please try again! Redirecting to user menu...");
		sleep(3);
	}
}
