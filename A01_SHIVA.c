//MINI PROJECT
//LEAVE MANAGMENT SYSTEM
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>	
void module1();//function prototype for entering employee detail
void module2();//function prototype for viewing employee detail
void module3();//function prototype for viewing the leave taken and pending
struct detail//structure
{
	char u_id[20],name[50],sex[6];
	int sick_leave,casual_leave;
};
/*global variables*/
//variable choice -To choose the option for entering or veiwing the leave taken by employee
//variable mm for returning to function main
//variable name_org for entering the name of organization
int choice,mm;
char name_org[30];
void main()
{
	printf("\n              welcome to                  ");
	printf("\n        ******Leave Managment System******");
	//main menu starts from here
	printf("\n 1.Enter employee detail");
	printf("\n Enter the name of organisation\n");
	gets(name_org);
	puts(name_org);	
	printf("\n Enter choice\n");
	printf("\n Pres 1 to Enter the employee details\n");
	printf("\n press 2 to view employee details\n");
	printf("\n press 3 to view leave taken or leave pending\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			puts("\nenter employee detail\n");
			module1();//module for entering employee detail
			printf("\n would you like to go to main menu\n");
			printf("\n 1. YES \t\t 0-NO\n\t");
			scanf("%d",&mm);
			if(mm==1)
			{
				main();
			}
			else
			{
				break;
			}
			
	case 2:
	printf("\nview employee detail\n");
	module2();//module for viewing the entered employee detail
	printf(" \nwould you like to goto the main menu\n");
          printf(" \n 1 - yes \t\t 0 - no\n\t");
        scanf("%d",&mm);
        if(mm==1)
         {
          main();
         }
         else
           {
             break;
            }
            case 3:
            	printf("\nview leave taken or pending\n");
	            module3();//module for viewing the leave taken or pending
	            printf(" \nwould you like to goto the main menu\n");
                printf(" \n 1 - yes \t\t 0 - no\n\t");
                scanf("%d",&mm);
                if(mm==1)
                {
                 main();
                }
               else
               {
                break;
                }
	default ://default is used if none of the given case match
         printf("not valid");
          printf(" \nwould you like to goto the main menu");
          printf(" \n 1 - yes \t\t 0 - no\n\t");
        scanf("%d",&mm);
        if(mm==1)
         {
          main
		  ();
         }
         else
           {
             break;
            }
            
	}
}
 void module1()//module for entering the employee details
      {
      	FILE *source;//source is a file pointer
      	char another='y';
      	struct detail employee;//variable employee for stucture detail
      	source=fopen("employee_det.txt","w+");
      	while(another=='y'||another=='Y')
      	{
      		printf("enter employee details---\n");
      		printf("\n employee ID: ");
      		fflush(stdin);
      		gets(employee.u_id);
      		printf("\nemployee name:");
      		fflush(stdin);
      		gets(employee.name);
      		printf("\n sex");
      		fflush(stdin);
      		gets(employee.sex);
      		printf("\n sick leave\n");
      		fflush(stdin);
      		scanf("%d",&employee.sick_leave);
      		printf("%d \n",employee.sick_leave);
      		printf("\n casual leave\n");
      		fflush(stdin);
      		scanf("%d",&employee.casual_leave);
      		printf("%d \n",employee.casual_leave);
      fwrite(&employee,sizeof(employee),1,source); /// write the record in the file
      		if(source==NULL)
			  {
			  	printf("\n cannot open file");
		}
			  else
			  {
			  	fprintf(source,"%s%s%s%d%d",employee.u_id,employee.name,employee.sex,employee.sick_leave,employee.casual_leave);
			  fwrite(&employee,sizeof(employee),1,source);
			  	fclose(source);
			  }
			  printf("\n Add another record(Y/N):");
			  another=getche();
		}
  }
  void module2()//module for viewing the details of entered employee
  {
  	FILE *target;//target is another file pointer to read the enterd details
  	struct detail employee;
  	//employee =(struct detail*)malloc(sizeof(struct detail));
  	target=fopen("employee_det.txt","r");
  	if(target==NULL)//condition for checking the file is existing or not
  	{
  		printf("\n cannot open file");
	  }
	  else
	  {
	  	while(fread(&employee,sizeof(struct detail),1,target)==1)
	  	{printf("\nemplyee_uid\temployee_name\temployee_sex\temployee_sick_leave\temployee_sick_leave\t\n");
	  		printf("\n%s\t%s\t%s\t%d\t%d\t\n",employee.u_id,employee.name,employee.sex,employee.sick_leave,employee.casual_leave);
			  fprintf(target,"\n%s\t%s\t%s\t%d\t%d\t\n",employee.u_id,employee.name,employee.sex,employee.sick_leave,employee.casual_leave);
			  }
			  fclose(target);
			  }
			  }
void module3()//module for displaying the leave taken or pending
{
	int choice_leave,pending_sick,pending_casual;
	int l_sick;
	int l_casual,total_sick,total_casual;
	printf("please select the leave category\n");
	printf("\nPress 1 for sick leave");
    printf("\nPress 2 for casual leave");
    scanf("%d",&choice_leave);
		switch(choice_leave)
		{
			case 1:
				printf("enter the total no. of sick leave in a term as entered before in main \n");
	        	scanf("%d ",&total_sick);
	        	printf("%d \n",total_sick);
	        	printf("\n enter the no. of leaves:");
	        	scanf("%d",&l_sick);
	        	printf("%d\n",l_sick);
	        	printf("no. of days leave pending\n");
	            pending_sick=total_sick-l_sick;
	        	printf("%d\n",pending_sick);
				break;
			case 2:	
			
	        	printf("enter the total no. of casual leave in a term as entered before in main \n");
	        	scanf("%d ",&total_casual);
	        	printf("%d\n",total_casual);
	        	printf("enter the no. of leaves");
	        	scanf("%d",&l_casual);
	        	printf("%d\n",l_casual);
	        	printf("no. of days leave pending\n");
	            pending_casual=total_casual-l_casual;
	        	printf("%d\n",pending_casual);
				break;
			default:
				printf("please enter the correct leave category\n");
				exit(1);
				
	  }
 }
	

