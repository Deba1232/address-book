#include <stdio.h>
#include <string.h>
#include "contact.h"

void editName(AddressBook *addressBook){
    char nameToEdit[50],editedName[50];
    int flag = 0,count,similarNamesCount;
            
    do{
        printf("Enter the name you want to edit: ");
        scanf(" %49[^\n]", nameToEdit);

        if(isValidName(nameToEdit)){
            printf("Details for name(s) starting with \"%s\":\n",nameToEdit);

            if(searchByName(addressBook,nameToEdit)){
                do{
                    count = 0;
                    similarNamesCount = 0;
                    printf("\nEnter the exact name you want to edit: ");
                    scanf(" %[^\n]", nameToEdit);

                    if(isValidName(nameToEdit)){
                        for(int i=0;i<addressBook->contactCount;i++){

                            if(!strncmp(addressBook->contacts[i].name,nameToEdit,strlen(nameToEdit))){
                                if(!strcmp(addressBook->contacts[i].name,nameToEdit)){
                                    count = LOWEST_VALUE;
                                    similarNamesCount++;
                                }

                                if(strlen(addressBook->contacts[i].name) != strlen(nameToEdit)){
                                    count++;
                                }
                            }
                        }

                        if(count > 0){
                            printf("You have not entered exact name. Try again :)");
                            continue;
                        }
                            
                        printf("Details for %s:\n",nameToEdit);

                        if(searchByName(addressBook,nameToEdit)){
                            do{
                                printf("Enter the new name: ");
                                scanf(" %49[^\n]",editedName);

                                if(isValidName(editedName)){
                                    for(int i=0;i<addressBook->contactCount;i++){

                                        if(!strcmp(addressBook->contacts[i].name,nameToEdit)){

                                            if(!strcmp(addressBook->contacts[i].name,editedName)){
                                                flag = 0;
                                                printf("Please enter a unique name. ");
                                            }
                                            else{
                                                flag = 1;
                                                strcpy(addressBook->contacts[i].name,editedName);
                                            }
                                        }
                                    }

                                    if(!flag){
                                        printf("No changes were made.\n");
                                    }
                                    else{
                                        printf("\nUpdated address book:\n");
                                    }
                            
                                    listContacts(addressBook);
                                }
                                else{
                                    printf("Not a proper name, try again :)\n");
                                }

                            }while(!isValidName(editedName));
                                
                        } 
                                
                    }
                    else{
                        printf("Not a proper name, try again :)\n");
                    }

                }while(!isValidName(nameToEdit) || count>0);   
            }
        }
        else{
            printf("Not a proper name, try again :)\n");
        }

    }while(!isValidName(nameToEdit));
}

void editContactNumber(AddressBook *addressBook){
    char contactNumberToEdit[20],editedContactNumber[20];
    int flag = 0,isUniqueContactNumber = 0;
            
    do{
        printf("Enter the contact number you want to edit: ");
        scanf(" %19[^\n]", contactNumberToEdit);

        if(isValidContactNumber(addressBook, contactNumberToEdit)){
            printf("Details for %s:\n",contactNumberToEdit);

            if(searchByContactNumber(addressBook,contactNumberToEdit)){
                do{
                    printf("Enter the new contact number: ");
                    scanf(" %19[^\n]",editedContactNumber);

                    if(isValidContactNumber(addressBook, editedContactNumber) == -1){
                        printf("This contact number is already in the list. Enter a different contact number.\n");
                    }
                    
                    else if(isValidContactNumber(addressBook, editedContactNumber) == 1){
                        for(int i=0;i<addressBook->contactCount;i++){

                            if(!strcmp(addressBook->contacts[i].phone,contactNumberToEdit)){
                                isUniqueContactNumber=1;
                                strcpy(addressBook->contacts[i].phone,editedContactNumber);
                            }
                        }

                        printf("\nUpdated address book:\n");
                            
                        listContacts(addressBook);
                    }
                    
                    else{
                            printf("Not a proper contact number, try again :)\n");
                    }

                }while(!isValidContactNumber(addressBook, editedContactNumber) || !isUniqueContactNumber);            
                                
            }

        }
        else{
            printf("Not a proper contact number, try again :)\n");
        }

    }while(!isValidContactNumber(addressBook, contactNumberToEdit));
}

void editEmailId(AddressBook *addressBook){
    char emailIdToEdit[50],editedEmailId[50];
    int flag = 0,isUniqueEmailId = 0;
            
    do{
        printf("Enter the email ID you want to edit: ");
        scanf(" %49[^\n]", emailIdToEdit);

        if(isValidEmailId(addressBook, emailIdToEdit)){
            printf("Details for %s:\n",emailIdToEdit);

            if(searchByEmailId(addressBook,emailIdToEdit)){
                do{
                    printf("Enter the new email ID: ");
                    scanf(" %49[^\n]",editedEmailId);

                    if(isValidEmailId(addressBook, editedEmailId) == -1){
                        printf("This email ID is already in the list. Enter a different email ID.\n");
                    }
                    
                    else if(isValidEmailId(addressBook, editedEmailId) == 1){
                        for(int i=0;i<addressBook->contactCount;i++){

                            if(!strcmp(addressBook->contacts[i].email,emailIdToEdit)){
                                isUniqueEmailId=1;
                                strcpy(addressBook->contacts[i].email,editedEmailId);
                              
                            }
                        }

                        printf("\nUpdated address book:\n");
                        
                            
                        listContacts(addressBook);
                    }
                    
                    else{
                            printf("Not a proper email ID, try again :)\n");
                    }

                }while(!isValidEmailId(addressBook, editedEmailId) || !isUniqueEmailId);            
                                
            }

        }
        else{
            printf("Not a proper email ID, try again :)\n");
        }

    }while(!isValidEmailId(addressBook, emailIdToEdit));
}