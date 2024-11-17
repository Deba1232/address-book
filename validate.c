#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"

int isValidName(char *name){
    for(int i=0;name[i]!='\0';i++){
        if(!(isalpha(name[i]) || name[i]==' ')){
            return 0;
        }
    }

    return 1;
}

int isValidContactNumber(AddressBook *addressBook, char *phone){
    if(strlen(phone) != 10){
        return 0;
    }

    for(int i=0;phone[i]!='\0';i++){
        if(!isdigit(phone[i])){
            return 0;
        }
    }

    for(int i=0;i<addressBook->contactCount;i++){
        
        for(int j=i;j<addressBook->contactCount;j++){
            if(!strcmp(addressBook->contacts[i].phone,addressBook->contacts[j+1].phone)){
                return -1;
            }
            if(!strcmp(addressBook->contacts[i].phone,phone)){
                return -1;
            }
        }
    }

    return 1;
}

int isValidEmailId(AddressBook *addressBook, char *email){
    int flag = 0;

    for(int i=0;email[i]!='\0';i++){

        if(email[i] == '@'){                    //checking for @

            if(isalnum(email[i-1])){            //checking whether the character before @ is alphabet/digit

                for(int j=0;email[j]!='\0';j++){

                    if(email[j]=='.' && email[j+1]=='c' && email[j+2]=='o' && email[j+3] == 'm'){//checking for .com

                        if(isalnum(email[j-1])){ //checking whether the character before .com is alphabet/digit
                            flag = 1;
                        }

                    }
                }  
            }
            
        }
    }

    if(flag == 0){
        return 0;
    }

    for(int i=0;i<addressBook->contactCount;i++){
        
        for(int j=i;j<addressBook->contactCount;j++){
            if(!strcmp(addressBook->contacts[i].email,addressBook->contacts[j+1].email)){
                return -1;
            }
            if(!strcmp(addressBook->contacts[i].email,email)){
                return -1;
            }
        }
    }

    return 1;
}