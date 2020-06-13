#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct8_linked_advanced_struct.h"
#include "struct8_linked_advanced_functions.h"

struct student* head;

int main()
{

	int i,AM;
	char stname[20], stsurname[20], addressStreet[20], addressNumber[3], mobile[10];

  	load();
	 
	while(1)
	{
		printf("1. Add\t\tStudent\n");
		printf("2. Delete\tStudent\n");
		printf("3. Search\tStudent\n");
		printf("4. Modify\tStudent\n");
		printf("5. Display\tStudents\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&i);
		if(i==1)
		{
			printf("Note: Students with same AMs and mobile numbers cannot be added.\n");
			printf("Enter the student's AM: ");
            scanf("%d",&AM);
			printf("Enter the student's name: ");
            scanf("%s",stname);
			printf("Enter the student's surname: ");
            scanf("%s",stsurname);
			printf("Enter the student's address street: ");
            scanf("%s",addressStreet);
			printf("Enter the student's address number: ");
            scanf("%s",addressNumber);
			printf("Enter the student's mobile without +30 prefix: ");
            scanf("%s",mobile);
			if ( check_duplicate_record(AM, mobile) == 0)
			{
				add(AM,stname,stsurname,addressStreet,addressNumber,mobile);				
			}		
		}
		else if (i==2)
		{
			printf("Enter the student's surname to delete: ");
    		scanf("%s",stsurname);	
			delete(stsurname);
		}
		else if (i==3)
		{
			printf("Enter the student's AM to search: ");
    		scanf("%d",&AM);
			search(AM);
		}
		else if (i==4)
		{
		    printf("Enter the student's AM: ");
		    scanf("%d",&AM);
			modify(AM);
		}						
		else if (i==5)
		{
			display();
		}
		else if (i==6)
		{
			save();
			printf("Exiting...");
			return 0;
		}
	}
    return 0;
}



