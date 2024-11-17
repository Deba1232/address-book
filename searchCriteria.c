#include <stdio.h>
#include <string.h>
#include "contact.h"

int searchByName(AddressBook *addressBook, char *nameToSearch){
    int nameFound = 0;

    printf("----------------------------------------------------------------------\n");
    printf("%-25s%-25s%-25s\n","Name","Contact Number","Email Id");
    printf("----------------------------------------------------------------------\n");

    for(int i=0;i<addressBook->contactCount;i++){
        if(!strncmp(addressBook->contacts[i].name,nameToSearch,strlen(nameToSearch))){
            nameFound = 1;
            printf("%-25s%-25s%-25s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
    }

    if(!nameFound){
        printf("\nName not in the address book\n");
        return 0;
    }

    return 1;
}

int searchByContactNumber(AddressBook *addressBook, char *contactNumberToSearch){
    int contactNumberFound = 0;

    printf("----------------------------------------------------------------------\n");
    printf("%-25s%-25s%-25s\n","Name","Contact Number","Email Id");
    printf("----------------------------------------------------------------------\n");


    for(int i=0;i<addressBook->contactCount;i++){
        if(!strncmp(addressBook->contacts[i].phone,contactNumberToSearch,strlen(contactNumberToSearch))){
            contactNumberFound = 1;
            printf("%-25s%-25s%-25s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
    }

    if(!contactNumberFound){
        printf("\nContact number not in the address book\n");
        return 0;
    }

    return 1;
}

int searchByEmailId(AddressBook *addressBook, char *emailIdToSearch){
    int emailIdFound = 0;

    printf("----------------------------------------------------------------------\n");
    printf("%-25s%-25s%-25s\n","Name","Contact Number","Email Id");
    printf("----------------------------------------------------------------------\n");


    for(int i=0;i<addressBook->contactCount;i++){
        if(!strncmp(addressBook->contacts[i].email,emailIdToSearch,strlen(emailIdToSearch))){
            emailIdFound = 1;
            printf("%-25s%-25s%-25s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
    }

    if(!emailIdFound){
        printf("\nEmail ID not in the address book\n");
        return 0;
    }

    return 1;
}