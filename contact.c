#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
// #include "populate.h"

void listContacts(AddressBook *addressBook)    //int sortCriteria -> this arg may be needed later
{
    // Sort contacts based on the chosen criteria
    if(!addressBook->contactCount){
        printf("\nNo contacts in the address book (-_-;)\n");
    }
    else{
        printf("\n----------------------------------------------------------------------\n");
        printf("%-25s%-25s%-25s\n","Name","Contact Number","Email Id");
        printf("----------------------------------------------------------------------\n");
        for(int i=0;i<addressBook->contactCount;i++){            
            printf("%-25s%-25s%-25s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
    }
    
}

void initialize(AddressBook *addressBook) {
         addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

// void saveAndExit(AddressBook *addressBook) {
//     saveContactsToFile(addressBook); // Save contacts to file
//     exit(EXIT_SUCCESS); // Exit the program
// }


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    //Input Name
    do{
        printf("Enter name : ");
        scanf(" %49[^\n]",addressBook->contacts[addressBook->contactCount].name);

        if(!isValidName(addressBook->contacts[addressBook->contactCount].name)){
            printf("Not a proper name, try again :)\n");
        }

    }while(!isValidName(addressBook->contacts[addressBook->contactCount].name));

    //Input phone number
    do{
        printf("Enter contact number : ");
        scanf(" %19[^\n]",addressBook->contacts[addressBook->contactCount].phone);

        if(isValidContactNumber(addressBook, addressBook->contacts[addressBook->contactCount].phone) == 0){
            printf("Not a proper contact number, try again :)\n");
        }
        if(isValidContactNumber(addressBook, addressBook->contacts[addressBook->contactCount].phone) == -1){
            printf("Not a unique contact number, try again :)\n");
        }

    }while(!isValidContactNumber(addressBook, addressBook->contacts[addressBook->contactCount].phone) ||   isValidContactNumber(addressBook, addressBook->contacts[addressBook->contactCount].phone) == -1);

    //Input email id
    do{
        printf("Enter email id : ");
        scanf(" %49[^\n]",addressBook->contacts[addressBook->contactCount].email);

        if(isValidEmailId(addressBook, addressBook->contacts[addressBook->contactCount].email) == 0){
            printf("Not a proper email id, try again :)\n");
        }
        if(isValidEmailId(addressBook, addressBook->contacts[addressBook->contactCount].email) == -1){
            printf("Not a unique email id, try again :)\n");
        }

    }while(!isValidEmailId(addressBook, addressBook->contacts[addressBook->contactCount].email) || isValidEmailId(addressBook, addressBook->contacts[addressBook->contactCount].email) == -1);

    printf("Contact created successfully\n");
    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int choice;

    do{
        printf("\nSelect search criteria:\n");
        printf("1. Search by name\n2. Search by contact number\n3. Search by email id\n");
    
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                char nameToSearch[50];
            
                printf("Enter the name to search: ");
                scanf(" %49[^\n]",nameToSearch);

                searchByName(addressBook,nameToSearch);

                break;

            case 2:
                char contactNumberToSearch[50];

                printf("Enter the contact number to search: ");
                scanf(" %49[^\n]",contactNumberToSearch);

                searchByContactNumber(addressBook,contactNumberToSearch);
               
                break;

            case 3:
                char emailIdToSearch[50];

                printf("Enter the email id to search: ");
                scanf(" %49[^\n]",emailIdToSearch);       

                searchByEmailId(addressBook,emailIdToSearch);
                      
                break;

            default:
                printf("Invalid choice. Please try again :)\n");
        
        }

    }while((choice!=1) && (choice!=2) && (choice!=3));  
    
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int choice;

    do{
        printf("\nWhat do you want to edit?\n");
        printf("1. Edit name\n2. Edit contact number\n3. Edit email id");

        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                editName(addressBook);
                break;

            case 2:
                editContactNumber(addressBook);
                break;

            case 3:
                editEmailId(addressBook);
                break;

            default:
                printf("Invalid choice. Please try again :)\n");

        }

    }while((choice!=1) && (choice!=2) && (choice!=3));

}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */

    char nameToDelete[50];
    int flag = 0,idx = 0,contactsToDeleteIdxArr[MAX_CONTACTS],count;

    do{
        printf("Enter the name for the contact to delete: ");
        scanf(" %49[^\n]",nameToDelete);

        if(isValidName(nameToDelete)){
            printf("Details for contact(s) with names containing \"%s\":\n",nameToDelete);

            if(searchByName(addressBook,nameToDelete)){
                do{ 
                    printf("Enter the exact name for the contact to delete: ");
                    scanf(" %49[^\n]",nameToDelete);

                    if(isValidName(nameToDelete)){
                        count = 0;
                        for(int i=0;i<addressBook->contactCount;i++){
                            if(!strcmp(addressBook->contacts[i].name,nameToDelete)){
                                flag = 1;
                                idx = i;
                            }
                            else if(!strncmp(addressBook->contacts[i].name,nameToDelete,strlen(nameToDelete))){
                                flag = -1;
                                contactsToDeleteIdxArr[count] = i;
                                count++;
                            }
                        }

                        if(flag == 1){
                            printf("\nDetails for contact with the name %s :\n",nameToDelete);

                            printf("----------------------------------------------------------------------\n");
                            printf("%-25s%-25s%-25s\n","Name","Contact Number","Email Id");
                            printf("----------------------------------------------------------------------\n");

                            printf("%-25s%-25s%-25s\n",addressBook->contacts[idx].name,addressBook->contacts[idx].phone,addressBook->contacts[idx].email);

                            char choice;
                            do{
                                printf("Do you want to delete this contact?[y/n]: ");
                                scanf(" %c",&choice);

                                switch (choice)
                                {
                                    case 'Y':
                                    case 'y':
                                        deleteSingleContact(addressBook,idx);
                                        break;

                                    case 'N':
                                    case 'n':
                                        break;
                                
                                    default:
                                        printf("Invalid choice. Please try again :)\n");
                                }

                            }while((choice!='Y') && (choice!='y') && (choice!='N') && (choice!='n'));

                        }
                        if(flag == -1){
                            char choice;
                            
                            do{
                                printf("Do you want to delete all the contacts with names containing \"%s\"?[y/n]: ",nameToDelete);
                                scanf(" %c",&choice);

                                switch (choice)
                                {
                                    case 'Y':
                                    case 'y':
                                        deleteMultipleContacts(addressBook,contactsToDeleteIdxArr,count);
                                        break;

                                    case 'N':
                                    case 'n':
                                        break;
                                
                                    default:
                                        printf("Invalid choice. Please try again :)\n");
                                }

                            }while((choice!='Y') && (choice!='y') && (choice!='N') && (choice!='n'));
                        }
                        else{
                            printf("----------------------------------------------------------------------\n");
                            printf("%-25s%-25s%-25s\n","Name","Contact Number","Email Id");
                            printf("----------------------------------------------------------------------\n");

                            printf("Name not in the address book\n");
                        }
                    }
                    else{
                         printf("Not a valid name, try again :)\n");
                    }

                }while(!isValidName(nameToDelete));
                
            }

        }
        else{
            printf("Not a valid name, try again :)\n");
        }

    }while(!isValidName(nameToDelete));

}