#include <stdio.h>
#include <stdlib.h>

/* variable definition */
float interest_rate; 
float investment;
float arrInvest[12];
float arrQuarter[12];
float arrYear[3];

/* function calculate */
void calculate() {
	
	int i;
	arrInvest[0] = investment;
	arrQuarter[0] = investment*(interest_rate/100.0);
	for (i=1 ; i< 12; i++){

		arrInvest[i] = arrInvest[i-1] + arrQuarter[i-1];
		arrQuarter[i] = arrInvest[i]*(interest_rate/100.0);
		
	}
	
	arrYear[0] = arrQuarter[1] + arrQuarter[2] + arrQuarter[3] + arrQuarter[0];
	arrYear[1] = arrQuarter[5] + arrQuarter[6] + arrQuarter[7] + arrQuarter[4];
	arrYear[2] = arrQuarter[8] + arrQuarter[9] + arrQuarter[10] + arrQuarter[11];
	
}

/* function input */
void input() {
	
	printf("Enter your initial investment fund (USD): ");
	scanf("%f", &investment);
	
	do {
		
		printf("Enter your interest rate (%%): ");
		scanf("%f", &interest_rate);
		
		if ( (interest_rate < 5) || (interest_rate > 20) ) {
			
			printf("Your interest rate must greater than 5%% and less than 20%%.\n Please enter again! \n");					
		}
				
	} while ( (interest_rate < 5) || (interest_rate > 20) );
	
}

/* function output */
void output () {
	
	int i;
	printf("\n");
	printf(" %80s             ","TABLE INTEREST RATE");
	printf("\n");
	printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
	printf(" %22s | %41s | %41s | %41s |","YEAR","FIRST YEAR","SECOND YEAR","THIRD YEAR");	
	
	printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf(" %22s |", "QUARTER");
	for (i = 1; i <= 12; i++) {
		printf("%8d  |",i);
	};
	
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf(" %22s |", "Starting amount");
	for (i = 0; i < 12; i++) {
		printf("%9.2f |",arrInvest[i]);
	};
	
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf(" %22s |", "Interest in a quarter");
	for (i = 0; i < 12; i++) {
		printf("%9.2f |",arrQuarter[i]);
	};
	
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf(" %22s |", "Ending amount");
	for (i = 0; i < 12; i++) {
		printf("%9.2f |",arrInvest[i]+arrQuarter[i]);
	};
	
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf(" %22s |", "Interest in a year");
	for (i = 0; i < 3; i++) {
		printf(" %30.2f            |",arrYear[i]);
	};
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
    
	printf(" %22s |", "Total interest");
	printf(" %75.2f                                                       |",arrInvest[11]+arrQuarter[11]-investment);
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	
	printf(" %22s |", "Total amount");
	printf(" %75.2f                                                       |",arrInvest[11]+arrQuarter[11] );
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

/* function file fprintf */
void writefile() {
	FILE *fd;
	fd = fopen("output.txt", "w");
	int i;
	fprintf(fd,"\n");
	fprintf(fd," %80s             ","TABLE INTEREST RATE");
	fprintf(fd,"\n");
	fprintf(fd,"\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
	fprintf(fd," %22s | %41s | %41s | %41s |","YEAR","FIRST YEAR","SECOND YEAR","THIRD YEAR");	
	
	fprintf(fd,"\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	fprintf(fd," %22s |", "QUARTER");
	for (i = 1; i <= 12; i++) {
		fprintf(fd,"%8d  |",i);
	};
	
	fprintf(fd,"\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	fprintf(fd," %22s |", "Starting amount");
	for (i = 0; i < 12; i++) {
		fprintf(fd,"%9.2f |",arrInvest[i]);
	};
	
	fprintf(fd,"\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	fprintf(fd," %22s |", "Interest in a quarter");
	for (i = 0; i < 12; i++) {
		fprintf(fd,"%9.2f |",arrQuarter[i]);
	};
	
	fprintf(fd,"\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	fprintf(fd," %22s |", "Ending amount");
	for (i = 0; i < 12; i++) {
		fprintf(fd,"%9.2f |",arrInvest[i]+arrQuarter[i]);
	};
	
	fprintf(fd,"\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	fprintf(fd," %22s |", "Interest in a year");
	for (i = 0; i < 3; i++) {
		fprintf(fd," %30.2f            |",arrYear[i]);
	};
	fprintf(fd,"\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
    
	fprintf(fd," %22s |", "Total interest");
	fprintf(fd," %75.2f                                                       |",arrInvest[11]+arrQuarter[11]-investment);
	fprintf(fd,"\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	
	fprintf(fd," %22s |", "Total amount");
	fprintf(fd," %75.2f                                                       |",arrInvest[11]+arrQuarter[11] );
	fprintf(fd,"\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    fclose(fd);
}

int main(int argc, char *argv[]) {
	
	int choice = 1;
	while (choice) {
		
		system("cls");
		
		input();
		calculate();
		output();
		writefile();
		printf("\n"); printf("\n");
		printf("%81s","0 . Exit program ! \n");
		printf("%87s","1 . Start program again !\n");
		printf("%80s","Enter your choose: ");	
		scanf("%d", &choice);	
	}
		
	system("pause");
	return 0;
}
