#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int dim=0;

typedef struct psw{
	int alb;
	int nbr;
	int car;
	int maj;
	int min;
	
}psw;

typedef struct user{
	char firstname[20];
	char lastname[10];
	char login[10];
	char mail[30];
	char pasword[30];
	double id;
}user;

// aaaAAA111@@@
psw Pasword (char p[])
{
	struct psw Is={0,0,0,0,0};
	int i;
	FILE *F;
	
	for (i=0; i<strlen(p) ;i++)
	{
		
		
		if (  	isalpha( p[i]  )    ) Is.alb=1;
		if (  	isdigit( p[i]  )    ) Is.nbr=1;
		if (  	islower( p[i]  )    ) Is.min=1;
		if (  	isupper( p[i]  )    ) Is.maj=1;
		if (   !isalpha(p[i]) && !isdigit(p[i]) && !islower(p[i]) &&  !isupper(p[i])  )Is.car=1; else Is.car=0;
		
		
	}
	
	
	
	return Is;
	
}


int Choix()
{
	
	int choix;
    char op[5];
    int i,choixtest;

	do
	{
	   	
      	choixtest=1;
	      
	    printf("\n\n\n\t  %c * * * * * * * * * * * * * * * %c",17,16);
	    printf("\n\t %c                                %c",30,30);
	    printf("\n\t  *                              *");
	    printf("\n\t   *                            *");
	    printf("\n\t    *\t  FOR SIGN-IN  (1)     *");
	    printf("\n\t     *                        *");
	    printf("\n\t    *\t  FOR SIGN-UP  (2)     *");
	    printf("\n\t   *                            *");
	    printf("\n\t  *\t                         *");
	    printf("\n\t %c                                %c",31,31);
	    printf("\n\t  %c * * * * * * * * * * * * * * * %c\n",17,16);
	
	   	printf("\n\t\t  %c ENTRER VOTRE CHOIX : ",254);
		
		gets(op);
	    fflush(stdin);
	    

	    sscanf(op, "%d", &choix);
	    fflush(stdin);
	    
	    
	    for(i=0; i<strlen(op) ; i++) if( !isdigit(*(op+i)) ) choixtest=0;
	    
		if(choix<0 || choix>2 || choixtest==0 )
		{
		    system("cls");
			printf("\n\t\t\aVEUILLER ENTRER UN CHOIX VALABLE !!!");
	    }
		
	}while(choix<0 || choix>2 || choixtest==0 ) ;

}

void signup( struct user *USER, int id)
{
	
	
	
	struct user;
	
    printf("\n\n\tENTER YOUR FIRST NAME:\n");
	printf("\n\t*****************************************************************\n");
	printf("\t***                                                           ***");
	printf("\n\t                    ");
	fflush(stdin);
	gets((USER)->firstname);
	printf("\t***                                                           ***");
	printf("\n\t*****************************************************************\n");
	
	printf("\n\n\tENTER YOUR LASTE NAME:\n");
	printf("\n\t*****************************************************************\n");
	printf("\t***                                                           ***\n");
	printf("\n\t                    ");
	fflush(stdin);
	gets((USER)->lastname);
	printf("\t***                                                           ***");
	printf("\n\t*****************************************************************\n");
	
	printf("\n\n\tENTER YOUR MAIL OR YOUR NUMBER PHONE:\n");
	printf("\n\t*****************************************************************\n");
	printf("\t***                                                           ***\n");
	printf("\t                    ");
	fflush(stdin);
	gets((USER)->mail);
	printf("\t***                                                           ***");
	printf("\n\t*****************************************************************\n");
	
	again: 
	
	
	struct psw Is;
	char pasword[20];
	
	
	printf("\n\n\tENTER YOUR PASWORD:(more than 8, uppercase, number and character)\n");
	printf("\n\t*****************************************************************\n");
	printf("\t***                                                           ***\n");
	printf("\t     ");
	fflush(stdin);               
	gets(pasword);
	printf("\t***                                                           ***");
	printf("\n\t*****************************************************************\n");
    
	
    Is=Pasword(pasword);
	    
	    
	   // printf("\n\t%d\t%d\t%d\t%d\t%d",Is.car,Is.alb,Is.maj,Is.min,Is.nbr);
	    
	    
	    if ( strlen(pasword)<8 ) {
	    	printf("\n\tVEUILER ENTRER UN MOT DE PASSE PLUS GRAND >8"); 
	    }
	    	
	    if(  Is.car!=1 )  {
	    	printf("\n\tVEUILER ENTRER AU MOIN UN CARACTER !"); 
	    }
	    
	    if (  	Is.alb!=1   ) {
			printf("\n\tVEUILER ENTRER AU MOIN UNE ALPHABET !");
		}
			
		if (  	Is.nbr!=1   ){
			printf("\n\tVEUILER ENTRER AU MOIN UN NOMBRE !"); 
		}
			
		if (  	Is.min!=1   ) {
			printf("\n\tVEUILER ENTRER AU MOIN UNE LETTRE NINISCUL !"); 
		}
			
		if (  	Is.maj!=1 ) {
			printf("\n\tVEUILER ENTRER AU MOIN UNE LETTRE MAJUSCUL !"); 
		}
			
	    	
	    	
	    	
	    if ( strlen(pasword)<8 ) {
	    	
	    	sleep(4);
			system("cls"); 
			printf("\n\tTRY AGAIN !");
			goto again;
		} 
	    else if(  Is.car!=1 )  {
	    	
	    	sleep(4);
	    	system("cls"); 
			printf("\n\tTRY AGAIN !");
			goto again;
		}      
		else if (  	Is.alb!=1   ) {
			
			sleep(4);
			system("cls"); 
			printf("\n\tTRY AGAIN !");
			goto again;
		}
		else if (  	Is.nbr!=1   ){
			
			sleep(4);
			system("cls"); 
			printf("TRY AGAIN !");
			goto again;
		} 
		else if (  	Is.min!=1   ) {
			
			sleep(4);
			system("cls"); 
			printf("\n\tTRY AGAIN !");
			goto again;
		}
		else if (  	Is.maj!=1 ) {
			
			sleep(4);
			system("cls"); 
			printf("\n\tTRY AGAIN !");
			goto again;
		}else
		{
			printf("\n\n\tVOTRE MOT DE PASSE EST BIEN ");
			strcpy((USER)->pasword,pasword);
			(USER)->id=id;
			
		}
		
		
		
		
	
	
}




int main ()
{
	struct user USERS[100];
	int choix1=Choix();
	FILE *F;
	
	F = fopen("pasword.txt","w");
		fscanf(F,"%d",dim);
		fclose(F);
	
	
	if(choix1==2)
	{
		F = fopen("pasword.txt","r");
		fscanf(F,"%d",dim);
		fclose(F);
	
		system("cls");
		dim++;
		
		F = fopen("pasword.txt","w");
		fscanf(F,"%d",dim);
		fclose(F);
		

		
		
		
	//fwrite(pasword,1,sizeof(F),F);
	//fread(pasword,strlen(pasword),10,F);
	//puts(pasword);
		
		
	    signup(&USERS[dim],dim);
	}
	
	
            printf("\n%lf\n",USERS[0].id);
	        puts(USERS[0].mail);
			puts(USERS[0].lastname);
			puts(USERS[0].firstname);
			puts(USERS[0].pasword);
			
			printf("\n%lf\n",USERS[1].id);
			puts(USERS[1].mail);
			puts(USERS[1].lastname);
			puts(USERS[1].firstname);
			puts(USERS[1].pasword);
	
	
	

	
}
