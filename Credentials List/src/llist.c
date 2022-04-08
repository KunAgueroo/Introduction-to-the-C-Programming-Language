#include "llist.h"

// goal: creates a Cred struct given the username, password, and next credential
// param username: char* representing the username
// param password: char* representing the password
// param next: Cred struct pointer representing the next credential
// return: a Cred struct pointer to a credential with the specified fields
//
// TODO: complete the function
//structure declaration having username,password and next pointer
struct Cred* cred(char* username, char* password, struct Cred* next) {
struct Cred* temp = (struct Cred*)malloc(sizeof(struct Cred));
temp->username = (char*) malloc(strlen(username)+1);
strcpy(temp->username,username); 
temp->password = (char*)malloc(strlen(password)+1);
strcpy(temp->password,password); 
temp->next = next; 
return temp;
}

// goal: frees a list of credentials
// param head: pointer to first credential in the list
// TODO: complete the function
void cred_free(struct Cred* head) {
while(head != NULL){
struct Cred* temp = head; 
head = head->next;
free(temp->username);
free(temp->password);
free(temp);
}
}

// goal: gets the username from a Cred struct
// param head: pointer to a Cred struct
// return: a char* representing the username of the credential
//
// TODO: complete the function
char* get_username(struct Cred* head) {
return head->username;
}

// goal: gets the password from a Cred struct
// param head: pointer to a Cred struct
// return: a char* representing the password of the credential
//
// TODO: complete the function
char* get_password(struct Cred* head) {
return head->password;
}

// goal: gets the pointer to the next credential in a list
// param head: pointer to a Cred struct at the head of a list
// return: a pointer to the next Cred struct in the list
//
// TODO: complete the function
struct Cred* get_next(struct Cred* head) {
return head->next;
}

// goal: sets the username of a Cred struct
// param head: pointer to Cred struct to change username of
// param username: char* representing new username
//
// TODO: complete the function
void set_username(struct Cred* head, char* username) {
free(head->username); 
head->username = (char*)malloc(strlen(username)+1);
strcpy(head->username, username); 
}

// goal: sets the password of a Cred struct
// param head: pointer to Cred struct to change password of
// param password: char* representing new password
//
// TODO: complete the function
void set_password(struct Cred* head, char* password) {
free(head->password); 
head->password = (char*)malloc(strlen(password)+1);
strcpy(head->password, password);
}

// goal: sets the next credential in a list of credentials
// param head: pointer to Cred struct to change successor of
// param next: pointer to new successor credential
//
// TODO: complete the function
void set_next(struct Cred* head, struct Cred* next) {
if(head != NULL){
head->next = next; 
}
}
