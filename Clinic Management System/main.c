#include "STD_Types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Prototypes of functions

// MAIN MENU
void MainMenu();

//For ADMIN
void Admin();
void AdminMenu(); 
void AddNewPatient();
void EditPatient();
void Reservation();
void Cancel_Reservation();
bool CheckID(u32 id);
void PrintSlots();
void Slot(u32 s);

//For USER
void User(); 
void ViewPatientRecord();
void ViewReservation();


typedef struct patient
{
	u8 name[50];
	u32 age;
	u8 gender[10];
	u32 id;
	u32 slot;
	struct patient *next;
}patient;




int main()
{
	
	MainMenu();
	
	return 0;
	
}


void MainMenu()
{
	int choice,Exitflag=0;
	while(Exitflag ==0)
	{
	printf("Welcome to Main Menu\n");
	printf("Please Enter your choice: \n");
	printf("1.Admin Mode \n");
	printf("2.User Mode \n");
	printf("3.Exit \n");
	scanf("%d",&choice);
	
	
	switch(choice)
	{
		case 1:    Admin();                          break;
		case 2:    User();                           break;
		case 3:    printf("Goodbye!\n"); Exitflag=1; break;
		default:   printf("Invalid choice!\n");      break;
	}
	}
}

void Admin()
{
	#define PASSWORD 1234
	int password;
	int counter=0;
	while(counter <=2)
	{
	printf("Please enter password: ");
	scanf("%d",&password);
	
	if(password == PASSWORD)
	{
		AdminMenu();
	}
	else 
	{
		printf("Wrong password\n");
		counter++;	
		
	}
	
	}
	
	if (counter>=3)
	{
	printf("Sorry you had only 3 trials for password, Return to main menu \n");
	MainMenu();
	}
}




//Functions

void AdminMenu()
{
	int Adminchoice;
	printf("----------------------------\n");
	printf("Welcome to Admin Menu\n");
	printf("----------------------------\n");
	printf("Please Enter your choice: \n");
	printf("1.Add New Patient record \n");
	printf("2.Edit Patient record \n");
	printf("3.Reserve a slot \n");
	printf("4.Cancel Reservation \n");
	printf("5.Return to Main Menu \n");
	scanf("%d",&Adminchoice);
	printf("----------------------------\n");
	
	switch(Adminchoice)
	{
		case 1:   AddNewPatient();                              break;
		case 2:   EditPatient();                                break;
		case 3:   Reservation();   		                        break;
		case 4:   Cancel_Reservation();                         break;
		case 5:   MainMenu();   		  		                break;
		default:  printf("Invalid choice!\n");                  break;
	}
	
}





patient *head = NULL;

void AddNewPatient()
{
	u32 IDcheck;
	u8 name[50];
	u32 age;
	u8 gender[10];
	u32 id;
	
		printf("Please enter Patient Name: \n");
		scanf("\n");
		scanf("%[^\n]s",name);
		printf("Please enter Patient Age: \n");
		scanf("%d",&age);
		printf("Please enter Patient Gender: \n");
		scanf("\n");
		scanf("%[^\n]s",gender);
		printf("Please enter Patient ID: \n");
		scanf("%d",&id);
			
		/* Allocate the node */
		patient *neww = (patient*) malloc(sizeof(patient));
		// if allocation failed
		if (neww == NULL)
		{
			// Handle memory allocation error
			printf("Error: Memory allocation failed\n");
			return;
		}
		
		bool c = CheckID(id);

		if(c==true)
		{
			printf("ID already taken, Can't add\n");
			return;
			
		}
		
		
		else
		{
	
			strcpy(neww->name, name);
			neww->age = age;
			strcpy(neww->gender, gender);
			neww->id = id;
			
			neww->next=head;
			head = neww;

		}
		
		
	printf("Added Successfuly! \n");
	AdminMenu();
	
	return;
		
}


bool CheckID(u32 id)

{	
	
		patient *check=head;
		
		while (check!= NULL)
		{
			if(check->id == id)
			{
				return true;
			}
			check = check->next;
		}
		
		return false;
}





void EditPatient()
{
	
	u8 name[50];
	u32 age;
	u8 gender[10];
	u32 id;
	u8 counter = 0;
	patient *ptr = head;
	
	printf("Please enter your ID: ");
	scanf("%d", &id);
	
	while(ptr != NULL)
	{
	
		if(id == ptr->id)
		{
			printf("ID exists \n");
			counter++;
			break;
		}
		ptr = ptr->next;
	}
	
	if(counter == 0)
	{
		printf("ID not found! \n");
		AdminMenu();
		
	}
	
	
		printf("Please enter Patient Name: \n");
		scanf("\n");
		scanf("%[^\n]s",name);
		printf("Please enter Patient Age: \n");
		scanf("%d",&age);
		printf("Please enter Patient Gender: \n");
		scanf("\n");
		scanf("%[^\n]s",gender);

		
		
		strcpy(ptr->name, name);
		ptr->age = age;
		strcpy(ptr->gender, gender);
		
		printf("Patient information updated successfully.\n");
		AdminMenu();
		
			
}



int a = 0, b = 0, c = 0, d = 0, e = 0; // For slots


void PrintSlots()
{
	printf("Slots:\n");
	
		if(a == 0)
	{
		printf("1. 2pm to 2:30pm\n");
	}
	
	if(b == 0)
	{
		printf("2. 2:30pm to 3pm\n");
	}
	
	if(c == 0)
	{
		printf("3. 3pm to 3:30pm\n");
	}
	
	if(d == 0)
	{
		printf("4. 4pm to 4:30pm\n");
	}
	
	if(e == 0)
	{
		printf("5. 4:30pm to 5pm\n");
	}
	
	if(a==1&&b==1&&c==1&&d==1&&e==1)
	{
		printf("No slots are available\n");
		return;
	}
}





void Reservation()
{
	u32 id;
	u32 counter=0;
	u32 reservation;
	patient *ptr = head;
	
	printf("Enter ID to reserve:\n");
	scanf("%d",&id);
	while(ptr !=NULL)
	{
		if(ptr->id==id)
		{
			PrintSlots();
			printf("Please choose reservation slot:\n");
			scanf("%d",&reservation);
			
			switch(reservation)
			{
				case 1: ptr->slot = reservation; a=1; printf("Reserved Successfuly\n"); break;
				case 2:	ptr->slot = reservation; b=1; printf("Reserved Successfuly\n"); break;
				case 3:	ptr->slot = reservation; c=1; printf("Reserved Successfuly\n"); break;
				case 4:	ptr->slot = reservation; d=1; printf("Reserved Successfuly\n"); break;
				case 5:	ptr->slot = reservation; e=1; printf("Reserved Successfuly\n"); break;
				default: printf("Invalid choice\n");  break;
			}
			

			counter++;
		}
		
		
	ptr = ptr->next;
	}
	
	
	if (counter==0)
	{
		printf("ID not found\n");
		AdminMenu();
	}
	
	AdminMenu();
}





void Cancel_Reservation()
{
	u32 id;
	u32 counter=0;
	u32 slot=0;
	patient *ptr = head;
	
	printf("Enter ID to cancel reservation:\n");
	scanf("%d",&id);
	while(ptr !=NULL)
	{
		if(ptr->id==id)
		{
			slot = ptr->slot;
			switch(slot)
			{
				case 1: ptr->slot = 0; a=0; printf("Reserved is cancelled Successfuly\n"); break;
				case 2:	ptr->slot = 0; b=0; printf("Reserved is cancelled Successfuly\n"); break;
				case 3:	ptr->slot = 0; c=0; printf("Reserved is cancelled Successfuly\n"); break;
				case 4:	ptr->slot = 0; d=0; printf("Reserved is cancelled Successfuly\n"); break;
				case 5:	ptr->slot = 0; e=0; printf("Reserved is cancelled Successfuly\n"); break;
				default: printf("No reservation to delete\n");
			}
			

			counter++;
		}
		
		
	ptr = ptr->next;
	}
	
	
	if (counter==0)
	{
		printf("ID not found\n");
		AdminMenu();
	}
	
	AdminMenu();
	
	
}




void User()
{
	int Userchoice;
	printf("----------------------------\n");
	printf("Welcome to User Menu\n");
	printf("----------------------------\n");
	printf("Please Enter your choice: \n");
	printf("1.View patient record\n");
	printf("2.View today's reservation\n");
	printf("3.Return to Main Menu \n");
	scanf("%d",&Userchoice);
	printf("----------------------------\n");
	
	switch(Userchoice)
	{
		case 1:   ViewPatientRecord();                              break;
		case 2:   ViewReservation();                                break;
		case 3:   MainMenu();   		                            break;
		default:  printf("Invalid choice!\n");                      break;
	}
		
}




void Slot(u32 s)
{
	switch(s)
	{
		case 0: printf("No Reservation Slot\n");               break;
		case 1: printf("Reservation Slot: 2pm to 2:30pm\n");   break;
		case 2: printf("Reservation Slot: 2:30pm to 3pm\n");   break;
		case 3: printf("Reservation Slot: 3pm to 3:30pm\n");   break;
		case 4: printf("Reservation Slot: 4pm to 4:30pm\n");   break;
		case 5: printf("Reservation Slot: 4:30pm to 5pm\n");   break;
	
	}
}




void ViewPatientRecord()
{

	patient *ptr = head;
	u32 id;
	u32 counter=0;
	
	printf("Enter Patient ID:\n");
	scanf("%d",&id);
	
	while(ptr!=NULL)
	{
		if(ptr->id==id)
		{
		printf("Name: %s\n", ptr->name);
		printf("Age: %d\n", ptr->age);
		printf("Gender: %s\n", ptr->gender);
		printf("ID: %d\n", ptr->id);
		Slot(ptr->slot);
	
	
		counter++;
		}
			
		ptr = ptr->next;

	}

	

	if (counter==0)
	{
		printf("ID not found\n");
		User();
	}
	
}




void ViewReservation()
{
		patient *ptr = head;
		u32 counter=0;

	while(ptr!=NULL)
	{
		if( ptr->slot !=0)
		{
		Slot(ptr->slot);
		printf("ID: %d\n", ptr->id);
		}
			
		ptr = ptr->next;
		counter++;

	}
	if(counter==0)
	{
		printf("No data found\n");
	}
	
}