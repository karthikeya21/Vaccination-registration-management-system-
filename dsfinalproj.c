#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//creating file
FILE *fp;

//node for storing details in linked list
typedef struct mynode {
	char name[20];
	char gen[6];
	int id;
	int age;
	char vac[15];
	char mob[20];
	char comor[3];
	char date[12];
	char hour[6];

	struct mynode* link;
}Node;
Node* start = NULL;

//details of venue
int n=0;
char state[20], dis[20], h[6],dt[12];

//function for heading of the portal
void heading()
{
	printf(
		"\t\t\t\t***Covid Vaccination Registration***\n");
	printf("\t\t\t***Take Vaccine At Your Time & Fight "
		"Against Corona***\n\n");
}

//using queue to allocate appointment
#define MAX 4
int queue[MAX];
int r=-1,f=-1;
int enque(int id)
{

    if(r==MAX-1)
    {

        printf("\n\n\t\t\t\tCHOOSE ANOTHER TIME SLOT or DATE\n\n\n");
        f=r=-1;
        return 0;

	}

    else{
        if(f==-1)
            f=r=0;
        else
            r=r+1;
        queue[r]=id;
    }
}


//adding node(data) to the linked list

void addnode(char a[20], char b[10], char c[40], int d,int age,char v[15],
			char e[20], char f[3], char hur[12],char dat[6])
{
	Node *newptr = NULL, *ptr;
	newptr = (Node*)malloc(sizeof(Node));
	strcpy(newptr->name, a);
	strcpy(newptr->gen, b);
	newptr->id= d;
	newptr->age= age;
	strcpy(newptr->mob, e);
	strcpy(newptr->comor, f);
	strcpy(newptr->date, dat);
	strcpy(newptr->hour,hur);
	strcpy(newptr->vac, v);

	newptr->link = NULL;
	if (start == NULL)
		start = newptr;
	else {
		ptr = start;
		while (ptr->link != NULL)
			ptr = ptr->link;
		ptr->link = newptr;
	}
}

//taking details of the candidate
void enterdetails()
{
	int i,id,age,ch;
	char a[20], b[6], c[40], e[20], f[3],date[12],hour[6],con,vac[15];
	int x = 1;

	heading();


	fp = fopen("data.csv", "a+");
	// For Clear Screen
	system("cls");

	// Calling Heading() Function
	heading();

	printf("\t\t\t\tEnter State: ");
	scanf("%s",state);


	//choosing time slot of appointment
	start:
	printf("\t\t\t\tENTER TIME IN 24HRS FORMAT(ex:16:30):");
	scanf("%s",hour);
	strcpy(h, hour);
	fflush(stdin);
	printf("\t\t\t\tEnter Date (DD-MM-YY): ");

	gets(date);
	strcpy(dt, date);


		while(1) {


		// For Clear Screen
		system("cls");


		// Calling Heading() Function
		heading();



		printf("\t\t\t\tEnter The  Candidate Name: ");
		fflush(stdin);
		gets(a);

		printf("\t\t\t\tEnter The  Candidate Id-Number(last 4 digits): ");
		fflush(stdin);
		scanf("%d",&id);
		x=enque(id);
		if(x==0)
		{

			goto start;
		}
	//showing available vaccines based on age
		printf("\t\t\t\tEnter Age of candidate: ");
		fflush(stdin);
		scanf("%d",&age);


		if(age<18)
		{
			printf("\t\t\t\t1.Covaxin\n");
			printf("\t\t\t\t2.Covishield\n");



		}
		else
		{
			printf("\t\t\t\t1.Covaxin\n");
			printf("\t\t\t\t2.Covishield\n");
			printf("\t\t\t\t3.SputnikV\n");
		}
		printf("\t\t\t\tChoose vaccine:");
		scanf("%d",&ch);
		if(ch==1)
			strcpy(vac,"Covaxin");
		if(ch==2)
			strcpy(vac,"Covishield");
		if(ch==3)
			strcpy(vac,"SputnikV");


		printf("\t\t\t\tEnter The  Candidate Gender(m/f): ");
		fflush(stdin);
		gets(b);

	//sanding data int a file

		fprintf(fp," %d ",id);
		fputs(",",fp);

		printf("\t\t\t\tEnter The  Candidate Mobile Number: ");
		fflush(stdin);
		gets(e);

		fprintf(fp," %s ",e);
		fputs(",",fp);

		fprintf(fp," %d ",age);
		fputs(",",fp);

		fprintf(fp," %s ",vac);
		fputs(",",fp);
		fputs("\n",fp);

		printf("\t\t\t\tEnter The  Candidate Co-Morbidity Status (Yes or No): ");
		fflush(stdin);
		gets(f);
		n++;

		// Calling Function addnode()
		addnode(a, b, c, id,age,vac, e, f,hour,date);
		printf("\t\t\t\tenter y to continue\n");
		printf("\t\t\t\tenter n to exit\n");
		fflush(stdin);
		scanf("%c",&con);
		if(con=='n')
			break;


	}

	// For Clear Screen
	system("cls");

	fclose(fp);

}


// Function To Print Receipt
void receipt()
{
	int i;
	Node* ptr = start;

	// For Clear Screen
	system("cls");
	heading();
	printf(
		"\n\t\t\t\t**Take Screenshot For Further Use**\n");

	// Printing Candidate All Details
	for (i = 1; i <= n; i++) {
		printf("\t\t\t\tAppointment number:%d\n",i);
		printf("\t\t\t\tCandidate Name: ");
		puts(ptr->name);
		printf("\t\t\t\tCandidate Gender: ");
		puts(ptr->gen);
		printf("\t\t\t\tCandidate Id Number: ");
		printf("%d",ptr->id);
		printf("\n");
		printf("\t\t\t\tCandidate age: ");
		printf("%d",ptr->age);
		printf("\n");
		printf("\t\t\t\tName of vaccine: ");
		puts(ptr->vac);

		printf("\t\t\t\tCandidate Mobile Number: ");
		puts(ptr->mob);

		printf(
			"\t\t\t\tCandidate Co-Morbidity Status: ");
		puts(ptr->comor);
		printf(
			"\t\t\t\tDate of appointment:");
			puts(ptr->date);
		printf(
			"\t\t\t\tTime slot:");
			printf("%s hrs\n",ptr->hour);


		printf("\n");
		ptr = ptr->link;
	}


	printf("\n\t\t\t\t**Thank You For registration**\n");
}


//function to print total vaccination data
void Print()
{
	printf("\n\t**VACCINATION DATA**\n\n");
	fp = fopen("data.csv", "r");
	char c;
	printf(" ID\tPh.no.\t     Age  Vaccine\n");
	c = fgetc(fp);
    while (c != EOF)
    {
    	if(c!=',')
        {
		printf ("%c", c);

		}
		if(c==',')
			printf(" ");
        c = fgetc(fp);
    }
    printf("\n");

    fclose(fp);
}
//function to get appointment details by giving id number
void search(void)
{
    int a,i=0;
    printf("\n");
    printf(
			"\t\t\t\tEnter last 4 digits of id number:");
    scanf("%d",&a);

    Node *ptr;
    ptr=start;
    printf("\n");
  	while(ptr != NULL)
    {
        if (ptr->id == a)
        	break;

        ptr=ptr->link;

    }
    if(ptr==NULL)
    {
    	printf("\t\t\t\tData not found\n");
    	return;
	}
   	 printf("\t\t\t\tCandidate Name: ");
		puts(ptr->name);
		printf("\t\t\t\tCandidate Gender: ");
		puts(ptr->gen);
		printf("\t\t\t\tCandidate Id Number: ");
		printf("%d",ptr->id);
		printf("\n");
		printf("\t\t\t\tCandidate age: ");
		printf("%d",ptr->age);
		printf("\n");
		printf("\t\t\t\tName of vaccine: ");
		puts(ptr->vac);

		printf("\t\t\t\tCandidate Mobile Number: ");
		puts(ptr->mob);

		printf(
			"\t\t\t\tCandidate Co-Morbidity Status: ");
		puts(ptr->comor);
		printf(
			"\t\t\t\tDate of appointment:");
			puts(ptr->date);
		printf(
			"\t\t\t\tTime slot:");
			printf("%s hrs\n",ptr->hour);


		printf("\n");

}
//placing order for vaccines
void order()
{	int c1=0,c2=0,c3=0;
	Node *ptr;
	ptr=start;
	if(ptr==NULL)
	{
		printf("\t\t\t\t NO REQUIREMENT OF VACCINES CURRENTLY\n");
		return;

	}

	while(ptr != NULL)
    {
    	if (!strcmp(ptr->vac,"Covaxin"))
        	c1++;
        if (!strcmp(ptr->vac,"Covishield"))
        	c2++;
        if (!strcmp(ptr->vac,"SputnikV"))
        	c3++;

        ptr=ptr->link;

    }
    printf("\t\t\t\t**Required Vaccines**\n");
    printf("\t\t\t\t Covaxin:%d\n",c1);
    printf("\t\t\t\t Covishield:%d\n",c2);
    printf("\t\t\t\t SputnikV:%d\n",c3);
    printf("\n\t\t\t\t**ORDER PLACED SUCCESSFULLY**\n");

}
//giving options after admin login
void admin()
{
	int ch;
	printf("\t\t\t\tChoose an option\n");
	printf("\t\t\t\t1.Place an order for vaccines\n ");
	printf("\t\t\t\t2.Get vaccination data\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:order();
				break;
		case 2:Print();
				break;


	}

}
//admin login
void login()
{
	int n=3,i=2;
	char p[7]="abc123";
	char P[7];

	while(n--)
	{

	fflush(stdin);
	printf("\n");
	printf("\t\t\t\tEnter password:");
	gets(P);
	if(!strcmp(P,p))
	{
			printf("\n\t\t\t\t**SUCCESSFULLY LOGGED IN**\n\n");
			admin();
			break;

	}
	else
	{
		printf("\t\t\t\tWrong password\n");
		printf("\t\t\t\t%d attempts remaining\n",i);
		i--;
	}
	}



}

//main function
void main()
{
	int ch;
	heading();
	do{
		printf("\t\t\t\tChoose option:\n");
		printf("\t\t\t\t1.Vaccination registration\n");
		printf("\t\t\t\t2.Appointment details(receipt)\n");
		printf("\t\t\t\t3.Admin login\n");
		printf("\t\t\t\t4.exit\n");
		printf("\t\t\t\tEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enterdetails();
					printf("\n");
					receipt();
					break;
			case 2:search();
					break;

			case 3:login();
					break;

			case 4:exit(0);break;
		}
		printf("\n");
	}while(1);

}



