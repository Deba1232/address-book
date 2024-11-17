#include <stdio.h>
#include <string.h>
#include "contact.h"

void deleteSingleContact(AddressBook *addressbook, int idx){
    printf("Contact deleted successfully.\n");

    for(int i=idx;i<addressbook->contactCount;i++){
        addressbook->contacts[i] = addressbook->contacts[i+1];
    }
    addressbook->contactCount--;

    printf("\nUpdated address book:\n");
    listContacts(addressbook);
}