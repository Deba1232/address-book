#include <stdio.h>
#include <string.h>
#include "contact.h"
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *contactsFile;

    if((contactsFile = fopen("contacts.csv","w")) == NULL){
        fprintf(stderr,"File could not be accessed");
        return;
    }
    fprintf(contactsFile,"#%d\n",addressBook->contactCount);
    
    for(int i=0;i<addressBook->contactCount;i++){            
        fprintf(contactsFile,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    fclose(contactsFile);
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *contactsFile;

    if((contactsFile = fopen("contacts.csv","r")) == NULL){
        fprintf(stderr,"File could not be accessed");
        return;
    }

    fscanf(contactsFile,"#%d\n",&addressBook->contactCount);
    
    for(int i=0;i<addressBook->contactCount;i++){
        fscanf(contactsFile,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,
        addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    fclose(contactsFile);
}
