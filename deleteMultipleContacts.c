#include <stdio.h>
#include <string.h>
#include "contact.h"

void deleteMultipleContacts(AddressBook *addressBook, int *idxArr, int count){
    printf("Contacts deleted successfully.\n");
    printf("\nUpdated address book:\n");

    for(int i=0;i<count;i++){
        strcpy(addressBook->contacts[idxArr[i]].name,"");
        strcpy(addressBook->contacts[idxArr[i]].phone,"");
        strcpy(addressBook->contacts[idxArr[i]].email,"");
    }

    for(int i=0;i<addressBook->contactCount;i++){ 

        if((!strcmp(addressBook->contacts[i].name, "")) && (!strcmp(addressBook->contacts[i].phone, "")) && (!strcmp(addressBook->contacts[i].email, ""))){
            
            for(int j=i;j<addressBook->contactCount;j++){
                addressBook->contacts[j] = addressBook->contacts[j+1];
            }
            addressBook->contactCount--;
            i--; 
        } 

    }
    listContacts(addressBook);
}