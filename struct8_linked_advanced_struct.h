#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int am;
    char stname[20];
	char stsurname[20];
	char address[30];
	char mobile[13];
	
	struct student *next;
};


