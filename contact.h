#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100
#define LOWEST_VALUE -999

typedef struct {
    char name[50]; 
    char phone[20];
    char email[50];
} Contact; 

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

int isValidName(char *);
int isValidContactNumber(AddressBook *, char *);
int isValidEmailId(AddressBook *, char *);

int searchByName(AddressBook *, char *);
int searchByContactNumber(AddressBook *, char *);
int searchByEmailId(AddressBook *, char *);

void editName(AddressBook *);
void editContactNumber(AddressBook *);
void editEmailId(AddressBook *);

void deleteSingleContact(AddressBook *, int);
void deleteMultipleContacts(AddressBook *, int *,int);

#endif
