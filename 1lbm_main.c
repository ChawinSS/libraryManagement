#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h> //for buyfunction
#define SIZE 30 //standard size of string

struct book{
    int ISBN;
    char bookname[SIZE];
    char author[SIZE];
    int quantity;
    int catagory;
    int rack;
    char request_firstname[SIZE];
    int request_contact_num;
    char issuedate[SIZE];
} ; //a

struct user{
    char firstname[SIZE];
    char lastname[SIZE];
    int customerid;
    char user[SIZE];    
    int password;
    int contact_num;
    char email[SIZE];
}; //b

int increment=1; //for exceed input function

FILE *pf, *pf2;

int count = 0; //login

#include "1myfuncLBMlib.h"

int main(){
    
    basefunction();

    return 0;
};
