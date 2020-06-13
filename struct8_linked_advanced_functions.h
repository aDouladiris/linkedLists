#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern struct student* head;

void display()
{
    struct student *r;
	  r=head;
    if(r==NULL)
    {
		  return;
    }
	  printf("***************************************\n");
    while(r!=NULL)
	  {		
      printf("Student: %s %s,\twith AM: %d,\tAddress: %s,\tMobile: %s\n",r->stname,r->stsurname,r->am,r->address,r->mobile); 
      r=r->next;
    }
	  printf("***************************************\n");
}

int check_duplicate_record(int am, char mobile[10])
{
    char mobile_buffer[13];
    strcpy(mobile_buffer, "+30");
    strcat(mobile_buffer, mobile);

    struct student *r;
	  r=head;
    if(r==NULL)
    {
		  return;
    }
	  printf("***************************************\n");
    while(r!=NULL)
    {		
      if ( strcmp(r->mobile, mobile_buffer) == 0 && r->am == am )
      {
        printf("Duplicate record found!\n");
        printf("Student: %s %s,\twith AM: %d,\tAddress: %s,\tMobile: %s\n",r->stname,r->stsurname,r->am,r->address,r->mobile); 
        printf("Student cannot be added.\n");
        printf("***************************************\n");
        return 1;
      }	
      r=r->next;
    }
    return 0;	
}

void add(int am, char stname[20], char stsurname[20], char addressStreet[20], char addressNumber[3], char mobile[10])
{	
    struct student* temp;
    temp=(struct student *)malloc(sizeof(struct student));
    temp->am=am;
    strcpy(temp->stname, stname);
    strcpy(temp->stsurname, stsurname);	
    strcpy(temp->address, addressStreet);
    strcat(temp->address, " ");
    strcat(temp->address, addressNumber);
    strcpy(temp->mobile, "+30");
    strcat(temp->mobile, mobile);
	
    if (head== NULL)
    {
      head=temp;
      head->next=NULL;
    }
    else
    {
      temp->next=head;
      head=temp;
    }
    printf("Student: %s %s, with AM: %d, Address: %s, Mobile: %s\n",head->stname,head->stsurname,head->am,head->address,head->mobile);
    printf("Student added!\n");
}

void delete(char stsurname[20])
{
	struct student* r;
	struct student* prv_r;
	
	r=head;
  if(r==NULL)
  {
		return;
  }
	printf("***************************************\n");
  while(r!=NULL)
	{		
		if ( strcmp(r->stsurname, stsurname) == 0 )
		{
        char answer;
        printf("Are you sure to delete this student (Y\\N)?\n");
        fflush(stdin);
        scanf("%c", &answer);
        if ( answer == 'N' || answer == 'n' )
        {
            printf("Return to main menu...\n");
            return;
        }
        else if ( answer == 'Y' || answer ==  'y' )
        {
            if (r == head)
            {
                printf("Student: %s %s, with AM:%d deleted\n",r->stname,r->stsurname,r->am,r->address,r->mobile);
                printf("***************************************\n");
                head = head->next;
                free(r);
                return;
            }
            else if ( r->next == NULL )
            {
                printf("Student: %s %s, with AM:%d deleted\n",r->stname,r->stsurname,r->am,r->address,r->mobile);
                printf("***************************************\n");
                prv_r->next = NULL;
                free(r);
                return;
            }
            else
            {
                printf("Student: %s %s, with AM:%d deleted\n",r->stname,r->stsurname,r->am,r->address,r->mobile);
                printf("***************************************\n");
                prv_r->next = r->next;
                free(r);
                return;				
            }		
        }
        else
        {
          printf("Wrong answer.\nReturn to main menu...\n");
        }
      
		}
		prv_r=r;
		r=r->next;
    }
    printf("Student not found!\n");
	  printf("***************************************\n");
}

void search(int am)
{
    struct student *r;
	  r=head;
    if(r==NULL)
    {
		  return;
    }
	  printf("***************************************\n");
    while(r!=NULL)
    {    	
    	if ( r->am == am )
    	{
    		printf("Student found!\n");
    		printf("***************************************\n");
    		printf("Student: %s %s, with AM: %d, Address: %s, Mobile: %s\n",r->stname,r->stsurname,r->am,r->address,r->mobile); 
    		printf("***************************************\n");
    		return;
		  }		
		  r=r->next;
    }
    printf("Student not found!\n");
	  printf("***************************************\n");
	  return;
}

void modify(int am)
{
	struct student *r;
	r=head;
  if(r==NULL)
  {
	  return;
  }

  while(r!=NULL)
  {    	
    	if ( r->am == am )
    	{
        char fields[5];

        printf("Enter the fields to modify without commas\n");
        printf("1. Student's Name\n");
        printf("2. Student's Surname\n");
        printf("3. Student's AM\n");
        printf("4. Student's Address\n");
        printf("5. Student's Mobile\n");
        scanf("%s", fields);
        printf("fields %s\n", fields);

		    int i;
        for (i=0; i<5; i++)
        {
          if (fields[i] == '1')
          {
            printf("Enter Student's new name\n");
            char stname[20];
            scanf("%s", stname);
            strcpy(r->stname, stname);
          }
          else if (fields[i] == '2')
          {
            printf("Enter Student's new surname\n");
            char stsurname[20];
            scanf("%s", stsurname);
            strcpy(r->stsurname, stsurname);
          }
          else if (fields[i] == '3')
          {
            printf("Enter Student's new AM\n");
            int am;
            scanf("%d", &am);
            r->am = am;
          }
          else if (fields[i] == '4')
          {
            printf("Enter Student's new address\n");
            char address[30];
            char addressStreet[20];
            char addressNumber[3];                      
            scanf("%s",addressStreet);
            printf("Enter the student's address number: ");
            scanf("%s",addressNumber);
            strcpy(r->address, addressStreet);
            strcat(r->address, " ");
            strcat(r->address, addressNumber);
          }
          else if (fields[i] == '5')
          {
            printf("Enter Student's new telephone\n");
            char mobile[10];
            scanf("%s", mobile);
            strcpy(r->mobile, "+30");
            strcat(r->mobile, mobile);
          }
        }

    		printf("Student: %s %s, with AM: %d, Address: %s, Mobile: %s\n",r->stname,r->stsurname,r->am,r->address,r->mobile); 
    		printf("***************************************\n");
    		return;
      }		
      r=r->next;
  }
  printf("Student not found!\n");
  printf("***************************************\n");	
}

void save()
{
	
	FILE *file_ptr;
	
	file_ptr=(fopen("./student.dat","wb"));
	if(file_ptr==NULL)
	{
    printf("Error!");
    exit(1);
  }
  else
  {
      struct student* save_ptr;
      save_ptr = head;
      while(save_ptr != NULL)
      {    

        fwrite(save_ptr, sizeof(struct student), 1, file_ptr);
        save_ptr = save_ptr->next;
      }
      free(save_ptr);
      
  }
	printf("File saved!\n");
  fclose(file_ptr);
}

void load()
{
	FILE *file_ptr;	
	file_ptr = fopen("./student.dat","rb");
	if( file_ptr == NULL )
	{
       printf("Save file not found. Cannot load to buffer\n");
  }
  else
  {
      struct student* tmp;
      struct student* buffer;
      struct student* tail;

      tmp = (struct student*)malloc(sizeof(struct student));

      while( fread(tmp, sizeof(struct student), 1, file_ptr) )
      {      

          buffer = (struct student*)malloc(sizeof(struct student));
          memcpy ( buffer, tmp, sizeof(struct student) );

          if ( head == NULL)
          {
            
            buffer->next = NULL;
            head = buffer;
            tail = buffer;
          }
          else
          {
            buffer->next = NULL;
            tail->next = buffer;
            tail = buffer;
          }
          printf("*");
      }
      printf(" Loading complete!\n"); 
      fclose(file_ptr);		
	}
}

