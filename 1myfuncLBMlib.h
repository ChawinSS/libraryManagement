void header();
void basefunction();                                    
void pressfunction();   
void end(); 
void attempExceed();

void adminLoginDisplay();

void adminLoginRequest();// ab+ admin.txt...struct user b
void adminLogin(); // rb+ admin.txt...struct user b

void adminMenu();

void userLoginDisplay();
void help();

void userLoginRequest();// ab+ userLogin_request.txt...struct user b
void viewUserRequest(); // rb+ userLogin_request.txt...struct user b 

void acceptUser(); // ab+ userlist.txt...struct user b
void acceptdisplay(); // rb+ userlist.txt...struct user b 
void userLogin(); // rb+ userlist.txt...struct user b

void rejectUser(); // ab+ userrejectlist.txt...struct user b
void rejectdisplay(); // rb+ userrejectlist.txt...struct user b 
void userMenu();
void deleteUserRequest(); // rb+ userLogin_request.txt, wb+ temp.txt ...user b

//phase admin to user action
void viewUser(); //rb+ userlist.txt...user b 
void searchUser_name(); //rb+ userlist.txt...user b 
void searchUser_id(); //rb+ userlist.txt...user b 
void searchUser_contact(); //rb+ userlist.txt...user b 
void userEditUserDetail(); //rb+ userlist.txt...user b
void userChangePassword(); //rb+ userlist.txt...user b
void deleteUser();  // rb+ userlist.txt, wb+ tempuser.txt ...user b

void adminBookRegistration();// ab+ booklist.txt...struct book a
void adminInventory();//rb+ booklist.txt...struct book a 
void userViewInventory();//rb+ booklist.txt...struct book a 
void adminEditBook(); //rb+ booklist.txt...book a
void adminDeleteBook(); // rb+ booklist.txt, wb+ tempbook.txt ...book a

//phase admin action
void adminBookSearch_title();//rb+ booklist.txt...book a *
void adminBookSearch_catagory(); //rb+ booklist.txt...book a *
void adminBookSearch_id(); //rb+ booklist.txt...book a *

//phase user action
void userBookSearch_title(); //rb+ booklist.txt...book a *
void userBookSearch_catagory(); //rb+ booklist.txt...book a *
void userBookSearch_id(); //rb+ booklist.txt...book a *

void userRequestBook(); //ab+ userBook_request.txt...book a

void adminViewbookRequest(); //rb+ userBook_request.txt...book a 
void adminBookRequestAccept(); //ab+ booklist.txt...book a
void adminBookRequestReject(); //ab+ userBook_requestReject.txt...book a
void adminViewbookRequestReject(); //rb+ userBook_requestReject.txt...book a 
void adminBookRequestDelete(); // rb+ userBook_request.txt, wb+ temp_request.txt...book a
void userRequestDeleteRequest(); //ab+ userRequestDeleteRequest.txt...book a
void adminViewuserRequestDeleteRequest(); //rb+ userRequestDeleteRequest.txt...book a 
//void userBuyBook();

void booknotfound_admin();
void booknotfound_user();
void usernotfound_admin();
void usernotfound_user();
void userViewbookRequest();
void admindeleteRequestDeleteRequest(); // delete all problem
void adminsearchrequest_date();
void adminsearchrequest_name();


void header(){
    system("clear");
    printf("\n<--:Library Management System:-->");
    printf("\n═════════════════════════════════");
}

void pressfunction(){
        printf("\npress any key...\n\n");
        fflush(stdin);
        getchar();
}

void basefunction(){

    int opt_input;

    header();

    printf("\nPress①  Admin\tPress②  User: ");
        scanf("%d",&opt_input); 

    if(opt_input==1){   adminLoginDisplay();   }
    else if(opt_input==2){  userLoginDisplay();    }
    else{
        printf("\nInvalid Operation\n"); 
        printf("\nTry again...\n");

        pressfunction();
        basefunction();
    }

}

void attempExceed(){

    header();
    printf("\nEXIST SYSTEM");

    printf("\nPlease try again...");
    printf("\nThank you\n\n\n");

exit(1);

}

void end(){

    header();
    printf("\nEXIST SYSTEM");
    printf("\nUntil next time\n\n");

exit(1);

}

void help(){

    header();
    printf("\nHELP");
    printf("\nFor new user");
    printf("\n1) Requst a user login in the User request site");
    printf("\n2) Wait for 2 to 3 hours");
    printf("\n3) Check the access garnted list or rejected list\n");
    printf("\n\n First time access password is 1994\n");

    printf("\nMore information please contact libarian on duty");

    pressfunction();
    userLoginDisplay();
}

void adminLoginDisplay(){

    int opt_input;

    header();
    printf("\nADMIN LOG");

    printf("\nPress①  Login\tPress②  Create account\tPress③  Back\tPress④  Exit: ");
	scanf("%d",&opt_input); 

    if(opt_input==1){ adminLogin();}
    else if(opt_input==2){  adminLoginRequest();}
    else if(opt_input==3){  basefunction();}
    else if(opt_input==4){  end();}
    else{
    printf("\nInvalid Operation\n");

    pressfunction();
    adminLoginDisplay();
    }

}
 
void adminLoginRequest(){

    struct user b;

    char another ='y';

    int count=0;
    int id_input;

    header();
    printf("\nADMIN REQUEST");
    
    pf =fopen("admin.txt","ab+");
        if(pf == NULL){
            printf("Error opening file");
            adminLoginDisplay();
        }
        while(another == 'y'){
        printf("\nFirstname: ");
        fflush(stdin);
        scanf("%s",b.firstname);

        printf("\nLastname: ");
        fflush(stdin);
        scanf("%s",b.lastname);

        printf("\nprefer ID: ");
        fflush(stdin);
        scanf("%d",&id_input);
///
            while(fread(&b,sizeof(b),1,pf)==1){
                if (id_input==b.customerid){
                    printf("\n\t\t\tThis user ID is already in libibarary...");
                    count=1;
                }
            }
                if (count==1){
                    pressfunction();
                    adminLoginRequest();
                }
            b.customerid=id_input;
///
        printf("\npassword: ");
        fflush(stdin);
        scanf("%d",&b.password);

        printf("\nContact number: ");
        fflush(stdin);
        scanf("%d",&b.contact_num);
        fflush(stdin);


        fwrite(&b,sizeof(b),1,pf);
	    printf("\nsuccess");

        printf("\npress 'y' to add more admin");
        printf("\npress 'n' to  menu");
        printf("\n: ");
	    fflush(stdin);	
        another = getchar();
        fflush(stdin);

        }
    fclose(pf);

    pressfunction();
    adminLoginDisplay();
}

void adminLogin(){

    struct user b;

    char another ='y';

    int count=0;

    int id_input, secretcode=1993,password_input,secretcode_input;


    header();
    printf("\nADMIN LOGIN");

    printf("\nAdmin ID: ");
    fflush(stdin);
    scanf("%d",&id_input);

    printf("\npassword: ");
    fflush(stdin);
    scanf("%d",&password_input);
 
    printf("\nsecret password: ");
    fflush(stdin);
    scanf("%d",&secretcode_input);
    fflush(stdin);

    pf= fopen("admin.txt","rb+");
    if(pf == NULL){
        printf("\nError opening file");
        adminLoginDisplay();
    }
    else{  
        while(fread(&b,sizeof(b),1,pf ) == 1){
            if(id_input==b.customerid && password_input == b.password && secretcode_input==secretcode){

                printf("\n\nlogin success \n");
                printf("\n%s loged in ",b.firstname);
                printf("\nWelcome to our libabry Mr/Mrs. %s ",b.firstname);
                count=1; 
                pressfunction();
                adminMenu();
            }
        }
        if(count==0){            
        printf("\nIncorrect password %d to 3\n",increment);
        printf("\ntry again...");
        increment++;   
        pressfunction();
        if(increment==4){
            attempExceed();
        }
        adminLogin();
}
        
    }
    pressfunction();
end();

    fclose(pf);
}

void adminMenu(){
    
    int input;

    header();
    printf("\n\nADMIN MENU");
    
    printf("\n════════════");
    printf("\n  -INHOUSE BOOK");
    printf("\n   Press①  Register book");
    printf("\n   Press②  Book inventory");
    printf("\n   Press③  Edit book");
    printf("\n   Press④  Delete book\n");

    printf("\n  -BOOK REQUEST");
    printf("\n   Press⑤  View Books Request (A/R)");
    printf("\n   Press⑥  Reject books request list");
    printf("\n   Press⑦  View cancel book request");
    printf("\n   Press⑧  Delete Book request");
    printf("\n   Press⑨ Delete cancel Request");
    printf("\n   Press⑩ Search Request by date");
    printf("\n   Press⑪  Search Request by name\n");
    
    printf("\n  -BOOK SEARCH");    
    printf("\n   Press⑫  Search fors Book by title");
    printf("\n   Press⑬  Serach for books from ID");
    printf("\n   Press⑭  Search fors Book by catagory\n");

    printf("\n  -INHOUSE USER ");    
    printf("\n   Press⑮  View Users");
    printf("\n   Press⑯  Delete User");

    printf("\n  -USER REQUEST");    
    printf("\n   Press⑰  View Users Request (A/R)");
    printf("\n   Press⑱  Delete User request\n");

    printf("\n  -USER SEARCH");    
    printf("\n   Press⑲  Search User by name");
    printf("\n   Press⑳  Search User by ID");
    printf("\n   Press㉑  Search User by Contact\n");

    printf("\n  -OTHER");   
    printf("\n   Press㉒  Back");
    printf("\n   Press㉓  Exist");

        printf("\nEnter Operation: ");
        scanf("%d",&input);

          if(input==1){adminBookRegistration();}
            else if(input==2){adminInventory();}
            else if(input==3){adminEditBook();}     
            else if(input==4){adminDeleteBook();}       

            else if(input==5){adminViewbookRequest();}
            else if(input==6){adminViewbookRequestReject();}
            else if(input==7){adminViewuserRequestDeleteRequest();}
            else if(input==8){adminBookRequestDelete();}  
            else if(input==9){admindeleteRequestDeleteRequest();}
            else if(input==10){adminsearchrequest_date();}
            else if(input==11){adminsearchrequest_name();}

            else if(input==12){adminBookSearch_title();}
            else if(input==13){adminBookSearch_id();}
            else if(input==14){adminBookSearch_catagory();}


            else if(input==15){viewUser();}
            else if(input==16){deleteUser();}

            else if(input==17){viewUserRequest();}
            else if(input==18){deleteUserRequest();} 

            else if(input==19){searchUser_name();}
            else if(input==20){searchUser_id();}
            else if(input==21){searchUser_contact();}

            else if(input==22){adminLoginDisplay();}
            else if(input==23){end();}

            else{
                printf("\n\t\t\tInvalid Operation");
                pressfunction();

                adminMenu();
            }
}

void userLoginDisplay(){

    int opt_input;
    
    header();
    printf("\nUSER LOG");

    printf("\nPress①  Login\tPress②  Request login\tPress③  Loginlist\tPress④  Denylist\nPress⑤  Help\tPress⑥  Back\t\tPress⑦  Exit: ");
	scanf("%d",&opt_input); 

    if(opt_input==1){ userLogin();}
    else if(opt_input==2){  userLoginRequest();}
    else if(opt_input==3){  acceptdisplay();}
    else if(opt_input==4){  rejectdisplay();}
    else if(opt_input==5){  help();}
    else if(opt_input==6){  basefunction();}
    else if(opt_input==7){  end();}
    else{
    printf("\nInvalid Operation\n");

    pressfunction();
    userLoginDisplay();
    }

}

void userLoginRequest(){


    struct user b;

    char another ='y';

    header();
    printf("\nUSER REQUEST");
    
    pf =fopen("userLogin_request.txt","ab+");
    if(pf == NULL){
        printf("Error opening file");
        userLoginDisplay();
    }
    else{
    fflush(stdin);  
    printf("\nPlease enter ");
    while(another == 'y')
    {
    printf("\nFirstname: ");
    fflush(stdin);
    scanf("%s",b.firstname);

    printf("\nLastname: ");
    fflush(stdin);
    scanf("%s",b.lastname);

    printf("\nUsername: ");
    fflush(stdin);
    scanf("%s",b.user);

    printf("\nprefer ID: ");
    fflush(stdin);
    scanf("%d",&b.customerid);

    printf("\nContact number: ");
    fflush(stdin);
    scanf("%d",&b.contact_num);
    fflush(stdin);

    printf("\nEmail: ");
    fflush(stdin);
    scanf("%s",b.email);


    fwrite(&b,sizeof(b),1,pf);
	printf("\nRequest send");

    printf("\npress 'y' to request another user");
    printf("\npress 'n' to  menu");
    printf("\n: ");
	fflush(stdin);	
    another = getchar();
    fflush(stdin);

    }
        fclose(pf);
        pressfunction();
        userLoginDisplay();
    }
    }

void viewUserRequest(){

    struct user b;

    int input;
    
    int count =0;

    header();
    printf("\n\n<--:VIEW USER REQUEST:-->");
    printf("\nfirstname\tLastname\tUserID\tID\tcontact number\tEmail: ");

    pf = fopen("userLogin_request.txt","rb+");
    if(pf == NULL){
        printf("\nError opening file.");
        exit(1);
    }
    
    while(fread(&b,sizeof(b),1,pf) == 1){
        printf("\n%s\t\t%s\t\t%s\t%d\t%d\t\t%s",b.firstname,b.lastname,b.user,b.customerid,b.contact_num,b.email);
        count +=1;
    }
        printf("\n\nTotal requests: %d",count);

    pressfunction();
    fclose(pf);

    printf("\n①  Accept Request / ②  Reject Request / ③  Back: ");
    scanf("%d",&input);

    if(input==1){ acceptUser();}
    else if( input==2){rejectUser();}
    else if(input==3){adminMenu(); }
    else{
    printf("\n\t\t\tInvalid Operation\n");
    pressfunction();
    adminMenu();
    }
}

void acceptUser(){

    struct user b;

    char another ='y';

    char input_fname[SIZE],input_lname[SIZE];
    int input_id, input_contact;
    int count = 0;

    header();
    printf("\nACEPT USER REQUEST");
    
    pf =fopen("userlist.txt","ab+");
        if(pf == NULL){
            printf("Error opening file");
            viewUserRequest();
        }
        while(another == 'y'){
            printf("\nFirstname: ");
            fflush(stdin);
            scanf("%s",input_fname);

            printf("\nLastname: ");
            fflush(stdin);
            scanf("%s",input_lname);

            printf("\nUsername: ");
            fflush(stdin);
            scanf("%s",b.user);

            printf("\nprefer ID: ");
            fflush(stdin);
            scanf("%d",&input_id);

            b.password=1994;

            printf("\nContact number: ");
            fflush(stdin);
            scanf("%d",&input_contact);
            fflush(stdin);

///
            while(fread(&b,sizeof(b),1,pf)==1){
                if (strcmp(input_fname,b.firstname) == 0 && strcmp(input_lname,b.lastname) == 0 && input_id==b.customerid && input_contact==b.contact_num){
                    printf("\n\t\t\tThis user is already in libibarary...");
                    count=1;
                }
            }
                if (count==1){
                    pressfunction();
                    adminMenu();
                }
                strcpy(b.firstname,input_fname);
                strcpy(b.lastname,input_lname);
                b.customerid=input_id;
                b.contact_num=input_contact;
///

            printf("\nEmail: ");
            fflush(stdin);
            scanf("%s",b.email);

            fwrite(&b,sizeof(b),1,pf);
            printf("\nsuccess");

            printf("\npress 'y' to add more admin");
            printf("\npress 'n' to  menu");
            printf("\n: ");
            fflush(stdin);	
            another = getchar();
            fflush(stdin);

        }
        fclose(pf);
        pressfunction();
        adminMenu();
}

void acceptdisplay(){

    struct user b;

    int input;
    
    int count =0;

    header();
    printf("\n\n<--:VIEW USER REQUEST:-->");
    printf("\nfirstname\tLastname: ");

    pf = fopen("userlist.txt","rb+");
    if(pf == NULL){
        printf("\nError opening file.");
        userLoginDisplay();
    }
    
    while(fread(&b,sizeof(b),1,pf) == 1){
        printf("\n\n%s\t\t%s",b.firstname,b.lastname);
        count +=1;
    }
        printf("\nTotal requests: %d",count);

    pressfunction();
    fclose(pf);

    userLoginDisplay();
}

void userLogin(){

    struct user b;

    int count=0;

    char another ='y';

    int id_input,password_input;


    header();
    printf("\nUSER LOGIN");

    printf("\nPlease enter ");
    printf("\nUser ID: ");
    fflush(stdin);
    scanf("%d",&id_input);

    printf("\npassword: ");
    fflush(stdin);
    scanf("%d",&password_input);
     fflush(stdin);


    pf= fopen("userlist.txt","rb+");
    if(pf == NULL){
        printf("\nError opening file");
        userLoginDisplay();
    }
    else{  
        while(fread(&b,sizeof(b),1,pf ) == 1){
            if(id_input==b.customerid && password_input == b.password){

                printf("\n\nlogin success \n");
                printf("\n%s loged in ",b.firstname);
                printf("\nWelcome to our libabry Mr/Mrs. %s ",b.firstname);
                count=1; 
                pressfunction();
               userMenu();
            }
        }
        if(count==0){            
        printf("\nIncorrect password %d to 3\n",increment);
        printf("\ntry again...");
        increment++;   
        pressfunction();
        if(increment==4){
            attempExceed();
        }
        userLogin();
}
        
    }
    pressfunction();
end();

    fclose(pf);
}

void rejectUser(){

    struct user b;

    char another ='y';

    header();
    printf("\nREJECT USER REQUEST");
    
    pf =fopen("userrejectlist.txt","ab+");
    if(pf == NULL){
        printf("Error opening file");
        viewUserRequest();
    }
    else{
    fflush(stdin);  
    while(another == 'y')
    {
    printf("\nFirstname: ");
    fflush(stdin);
    scanf("%s",b.firstname);

    printf("\nLastname: ");
    fflush(stdin);
    scanf("%s",b.lastname);

    fwrite(&b,sizeof(b),1,pf);
	printf("\nsuccess");

    printf("\npress 'y' to reject more user");
    printf("\npress 'n' to  menu");
    printf("\n: ");
	fflush(stdin);	
    another = getchar();
    fflush(stdin);

    }
        fclose(pf);
        pressfunction();
        adminMenu();
    }
}

void rejectdisplay(){

    struct user b;

    int input;
    
    int count =0;

    header();
    printf("\n\n<--:VIEW USER REQUEST:-->");
    printf("\nfirstname\tLastname: ");

    pf = fopen("userrejectlist.txt","rb+");
    if(pf == NULL){
        printf("\nError opening file.");
        userLoginDisplay();
    }
    
    while(fread(&b,sizeof(b),1,pf) == 1){
        printf("\n%s\t\t%s",b.firstname,b.lastname);
        count +=1;
    }
        printf("\nTotal requests: %d",count);

    pressfunction();
    fclose(pf);

    userLoginDisplay();
}

void userMenu(){
    
    int input;

    header();
    printf("\n\nUSER MENU");

    printf("\n═══════════");
    printf("\n  -INHOUSE & REQUEST BOOK");
    printf("\n   Press①  View book");
    printf("\n   Press②  Request book");
    printf("\n   Press③  cancel Book request\n");


    printf("\n  -BOOK SEARCH");    
    printf("\n   Press④  Search fors Book by title");
    printf("\n   Press⑤  Serach for books from ID");
    printf("\n   Press⑥  Search fors Book by catagory\n");
    

    printf("\n  -USER ");    
    printf("\n   Press⑦  Edit account detail");
    printf("\n   Press⑧  Change Password\n");

    printf("\n  -OTHER");   
    printf("\n   Press⑨  Back");
    printf("\n   Press⑩  Exist");
    printf("\n   Press⑪  View Book request\n");

        printf("\n\nEnter Operation: ");
        scanf("%d",&input);

        if(input==1){userViewInventory();}
        else if(input==2){userRequestBook();}
        else if(input==3){userRequestDeleteRequest();}

        else if(input==4){userBookSearch_title();}
        else if(input==5){userBookSearch_id();}
        else if(input==6){userBookSearch_catagory();}

        else if(input==7){userEditUserDetail();}
        else if(input==8){userChangePassword();}

        else if(input==9){basefunction();}
        else if(input==10){ end();}
        else if(input==11){ userViewbookRequest();}
        else{
            printf("\nInvalid Operation");

            pressfunction();

            userMenu();
        }
}

/*action functions*/

void deleteUserRequest(){

    struct user b;

    char firstname_input[SIZE],lastname_input[SIZE];
    
    int count =0;
    
    header();
    printf("\n\n<--:DELETE USER REQUEST:-->");

    printf("\nEnter firstname : ");
    fflush(stdin);
    scanf("%s",firstname_input);

    printf("\nEnter lastname : ");
    fflush(stdin);
    scanf("%s",lastname_input);

    pf = fopen("userLogin_request.txt","r+");
    if(pf == NULL){
        printf("\nError opening file 1");
        adminMenu();
    }

    pf2 = fopen("temp.txt","a+");
    if(pf2 == NULL){
        printf("\nError opening file 2");
        adminMenu();
    }
    while(fread(&b,sizeof(b),1,pf) == 1){
            if(strcmp(firstname_input,b.firstname)!=0 && strcmp(lastname_input,b.lastname)!=0){
            fwrite(&b,sizeof(b),1,pf2);
            }

            if(strcmp(firstname_input,b.firstname)==0 && strcmp(lastname_input,b.lastname)==0){
            printf("\nUser is aviable");
            printf("\nSuccessfully delete");
            count=1;
            }

    }
    fclose(pf);
    fclose(pf2);
    remove("userLogin_request.txt");
    rename("temp.txt","userLogin_request.txt");
    if(count!=1){
        printf("User is not found");
        }
    pressfunction();
    adminMenu();
}

void viewUser(){
    
    struct user b;

    int input;

    int count = 0;

    header();
    printf("\n\n<--:VIEW USER:-->");
    printf("\nfirstname\tLastname\tUserID\tID\tPassword\tcontact number\tEmail: ");

    pf = fopen("userlist.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file.");
            adminMenu();
        }
        while(fread(&b,sizeof(b),1,pf) == 1){
                printf("\n%s\t\t%s\t\t%s\t%d\t%d\t\t%d\t\t%s",b.firstname,b.lastname,b.user,b.customerid,b.password,b.contact_num,b.email);
                count +=1;
        }
    printf("\nTotal requests: %d",count);

    fclose(pf);

    pressfunction();
    adminMenu();
}

void searchUser_name(){
   
    struct user b;

    char firstname_input[SIZE];

    int count=0;

    header();
    printf("\n\n<--:SEARCH USER BY FIRSTNAME:-->");

    printf("\nEnter firstname: ");
    fflush(stdin);
    scanf("%s",firstname_input);

    pf = fopen("userlist.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file");
            adminMenu();
        }
    
        while(fread(&b,sizeof(b),1,pf ) == 1){
            if(strcmp(firstname_input,b.firstname) == 0){
              printf("\nfirstname\tLastname\tUserID\tID\tPassword\tcontact number\tEmail: ");
            }

            if(strcmp(firstname_input,b.firstname) == 0){
               printf("\n%s\t\t%s\t\t%s\t%d\t%d\t\t%d\t\t%s",b.firstname,b.lastname,b.user,b.customerid,b.password,b.contact_num,b.email);
               count=1;
            }
        }    
        if(count==0){
            usernotfound_admin();
        }    
    fclose(pf);

    pressfunction();
    adminMenu();
}

void searchUser_id(){
   
    struct user b;

    int id_input;
    int count=0;

    header();
    printf("\n\n<--:SEARCH USER BY ID:-->");
    
    printf("\nEnter ID: ");
    fflush(stdin);
    scanf("%d",&id_input);

    pf = fopen("userlist.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file");
            adminMenu();
        }

        while(fread(&b,sizeof(b),1,pf ) == 1){
            if(id_input==b.customerid){
            printf("\nfirstname\tLastname\tUserID\tID\tPassword\tcontact number\tEmail: ");
            }

            if(id_input==b.customerid){
        printf("\n%s\t\t%s\t\t%s\t%d\t%d\t\t%d\t\t%s",b.firstname,b.lastname,b.user,b.customerid,b.password,b.contact_num,b.email);
            count=1;
            }
        }    
        if(count==0){
            usernotfound_admin();
        }    
    fclose(pf);

    pressfunction();
    adminMenu();
}

void searchUser_contact(){
  
    struct user b;

    int contact_input;
int count=0;
    header();
    printf("\n\n<--:SEARCH USER BY CONTACT:-->");
    
    printf("\nEnter user contact number: ");
    fflush(stdin);
    scanf("%d",&contact_input);

    pf = fopen("userlist.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file");
            adminMenu();
        }
        while(fread(&b,sizeof(b),1,pf ) == 1){
            if(contact_input==b.contact_num){
printf("\nfirstname\tLastname\tUserID\tID\tPassword\tcontact number\tEmail: ");
        }  
            
            if(contact_input==b.contact_num){
        printf("\n%s\t\t%s\t\t%s\t%d\t%d\t\t%d\t\t%s",b.firstname,b.lastname,b.user,b.customerid,b.password,b.contact_num,b.email);
            count=1;
            }
        }  
        if(count==0){
            usernotfound_admin();
        }     
    fclose(pf);

    pressfunction();
    adminMenu();
}

void userEditUserDetail(){

    struct user b;

    char fname_input[SIZE];
    int id_input;

    int count = 0;

    header();
    printf("\n\nEDIT USER");

    printf("\nUser ID:");
    scanf("%d",&id_input);

    printf("\nUser name:");
    scanf("%s",fname_input);
    
    pf =fopen("userlist.txt","rb+");
        if(pf == NULL){
            printf("Error opening file");
            adminMenu();
        }
            while(fread(&b,sizeof(b),1,pf ) == 1){
                if(id_input == b.customerid && strcmp(fname_input,b.firstname) == 0){

                    printf("\nUser is aviable \n");

                    printf("\nuser name:");
                    scanf("%s",b.firstname);

                    printf("\nlast name:");
                    scanf("%s",b.lastname);

                    printf("\nUsername: ");
                    fflush(stdin);
                    scanf("%s",b.user);

                    printf("\npassword: ");
                    fflush(stdin);
                    scanf("%d",&b.password);

                    printf("\nContact number: ");
                    fflush(stdin);
                    scanf("%d",&b.contact_num);
                    fflush(stdin);

                    printf("\nEmail: ");
                    fflush(stdin);
                    scanf("%s",b.email);

                    fseek(pf,ftell(pf)-sizeof(b),0);
                    fwrite(&b,sizeof(b),1,pf);

                    count =1;
                    printf("\nEdit success");
                } 
            }
    fclose(pf);
    system("clear");
    if(count==0){
    usernotfound_user();
    }

    pressfunction();
    userMenu();
}

void userChangePassword(){

    struct user b;

    int id_input;
    char fname_input[SIZE];

    int count=0;

    header();
    printf("\n\nEDIT PASSWORD");

    printf("\nUser ID:");
    scanf("%d",&id_input);

    printf("\nUser name:");
    scanf("%s",fname_input);
    
        pf =fopen("userlist.txt","rb+");
            if(pf == NULL){
                printf("Error opening file");
                adminMenu();
            }
            while(fread(&b,sizeof(b),1,pf ) == 1){
                if(id_input == b.customerid && strcmp(fname_input,b.firstname) == 0){

                    printf("\nUser is aviable \n");

                    printf("\nPlease enter new password: ");
                    fflush(stdin);
                    scanf("%d",&b.password);

                    count = 1;
                    printf("\nEdit success");
                    fseek(pf,ftell(pf)-sizeof(b),0);
                    fwrite(&b,sizeof(b),1,pf);
                }
            }
    fclose(pf);
    system("clear");
    if(count==0){
    usernotfound_user();
    }
    pressfunction();
    userMenu();
}

void deleteUser(){

   struct user b;
   int count=0;

    char firstname_input[SIZE],lastname_input[SIZE];

    header();
    printf("\n\n<--:DELETE USER:-->");

    printf("\nEnter firstname : ");
    fflush(stdin);
    scanf("%s",firstname_input);

    printf("\nEnter lastname : ");
    fflush(stdin);
    scanf("%s",lastname_input);

    pf = fopen("userlist.txt","r+");
    if(pf == NULL){
        printf("\nError opening file 1");
        adminMenu();
    }

    pf2 = fopen("tempuser.txt","a+");
    if(pf2 == NULL){
        printf("\nError opening file 2");
        adminMenu();
    }
    while(fread(&b,sizeof(b),1,pf) == 1){
            if(strcmp(firstname_input,b.firstname)!=0 && strcmp(lastname_input,b.lastname)!=0){
            fwrite(&b,sizeof(b),1,pf2);
            }
            if(strcmp(firstname_input,b.firstname)==0 && strcmp(lastname_input,b.lastname)==0){
            printf("\nUser aviable");
            printf("\nDelete Successful");
            count=1;
            }
    }
    fclose(pf);
    fclose(pf2);

    remove("userlist.txt");
    rename("tempuser.txt","userlist.txt");

    if(count!=1){usernotfound_admin();}

    pressfunction();
    adminMenu();
}

void adminBookRegistration(){

    struct book a;

    char another ='y';

    int count =0;

    char booktitle_input[20], authorname_input[30];
    int id_input;

    header();
    printf("\nADD BOOKS");
    
    pf =fopen("booklist.txt","ab+");
        if(pf == NULL){
            printf("Error opening file");
            adminMenu();
        }
        while(another == 'y'){
            printf("\nBook title: ");
            fflush(stdin);
            scanf("%s",booktitle_input);

            printf("\nAuthor: ");
            fflush(stdin);
            scanf("%s",authorname_input);

            printf("\nBook code ( ISBN ): ");
            fflush(stdin);
            scanf("%d",&id_input);
///
            while(fread(&a,sizeof(a),1,pf)==1){
                if (strcmp(booktitle_input,a.bookname) == 0 && id_input==a.ISBN){
                    printf("\n\t\t\tThis book is already in libibarary...");
                    count=1;
                }
            }
                if (count==1){
                    pressfunction();
                    adminMenu();
                }
            strcpy(a.bookname,booktitle_input);
            strcpy(a.author,authorname_input);
            a.ISBN=id_input;
///
            printf("\nCatagory table");
            printf("\nAnimals:1     Art:2               Careers:3  Cooking & Food:4");
            printf("\nCrime:5       Fun Facts:6         Fiction:7  Health:8");
            printf("\nLiterature:9  Nature:10           Math:11    Music:12");
            printf("\nPoetrye:13    Reference:14        Careers:15 Religion:16");
            printf("\nScience:17    Social/Cultural:18  Sports:19  Supernatural:20");
            printf("\nWar:21\n");

            printf("\nPlease enter a relevance catagory number: ");
            fflush(stdin);
            scanf("%d",&a.catagory);

            printf("\nQuantity: ");
            fflush(stdin);
            scanf("%d",&a.quantity);
            fflush(stdin);

            printf("\nRack: ");
            fflush(stdin);
            scanf("%d",&a.rack);


            fwrite(&a,sizeof(a),1,pf);

            system("clear");
            printf("\nBook added");

            printf("\npress 'y' to add more books");
            printf("\npress 'n' to  menu: ");

            fflush(stdin);	
            another = getchar();
            fflush(stdin);
        }
    fclose(pf);
        
    pressfunction();
    adminMenu();
}

void adminInventory(){

    struct book a;

    int input;
    int count = 0;

    header();
    printf("\n\n<--:BOOK INVENTORY:-->");

    pf = fopen("booklist.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file.");
            adminMenu();
        }
        printf("\nISBN\tBook title\tAuthor\tQuantity\tCatagory\tRack: ");
        while(fread(&a,sizeof(a),1,pf) == 1){
            printf("\n%d\t%s\t\t%s\t%d\t\t%d\t\t%d",a.ISBN,a.bookname,a.author,a.quantity,a.catagory,a.rack);
            count +=1;
        }
    
    printf("\nTotal Book: %d",count);
    
    fclose(pf);
    pressfunction();

    adminMenu();
}

void userViewInventory(){

    struct book a;
    
    int input;

    int count =0;

    header();
    printf("\n\n<--:BOOK INVENTORY:-->");

    pf = fopen("booklist.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file.");
            userMenu();
        }
        printf("\nISBN\tBook title\tAuthor\tQuantity\tCatagory\tRack: ");
        while(fread(&a,sizeof(a),1,pf) == 1){
            printf("\n%d\t%s\t%s\t%d\t%d\t%d",a.ISBN,a.bookname,a.author,a.quantity,a.catagory,a.rack);
            count +=1;
        }
    printf("\nTotal Book: %d",count);

    pressfunction();
    fclose(pf);

    userMenu();
}

void adminEditBook(){

    struct book a;

    int input_id;
    
    int count=0;

    header();
    printf("\n\nEDIT Book");
    
    pf =fopen("booklist.txt","rb+");
        if(pf == NULL){
            printf("Error opening file");
            adminMenu();
        }

        printf("\nEnter ISBN:");
        scanf("%d",&input_id);

        while(fread(&a,sizeof(a),1,pf ) == 1){
                if(input_id == a.ISBN){
                    
                    printf("\nBook is aviable \n");
                    a.ISBN=input_id;

                    printf("\nBook name: ");
                    fflush(stdin);
                    scanf("%s",a.bookname);

                    printf("\nBook author: ");
                    fflush(stdin);
                    scanf("%s",a.author);

                    printf("\nCatagory table");
                    printf("\nAnimals:1     Art:2               Careers:3  Cooking & Food:4");
                    printf("\nCrime:5       Fun Facts:6         Fiction:7  Health:8");
                    printf("\nLiterature:9  Nature:10           Math:11    Music:12");
                    printf("\nPoetrye:13    Reference:14        Careers:15 Religion:16");
                    printf("\nScience:17    Social/Cultural:18  Sports:19  Supernatural:20");
                    printf("\nWar:21\n");

                    printf("\nPlease enter a relevance catagory number: ");
                    fflush(stdin);
                    scanf("%d",&a.catagory);

                    printf("\nQuantity: ");
                    fflush(stdin);
                        scanf("%d",&a.quantity);

                    printf("\nRack: ");
                    fflush(stdin);
                    scanf("%d",&a.rack);
                    fflush(stdin);
                    
                    fseek(pf,ftell(pf)-sizeof(a),0);
                    fwrite(&a,sizeof(a),1,pf);

                    count+=1;
                    printf("\nEdit success");
                }
        }
    fclose(pf);
    system("clear");

    if(count!=1){
    booknotfound_admin();
    }

    pressfunction();
    adminMenu();
}

void adminDeleteBook(){

    struct book a;

    int idinput;
    int count=0;
    header();
    printf("\n\n<--:DELETE RECORD:-->");

    printf("\nEnter ISBN to delete : ");
    fflush(stdin);
    scanf("%d",&idinput);

    pf = fopen("booklist.txt","r+");
    if(pf == NULL){
        printf("\nError opening file 1");
        adminMenu();
    }

    pf2 = fopen("tempbook.txt","a+");
    if(pf2 == NULL){
        printf("\nError opening file 2");
        adminMenu();
    }

    while(fread(&a,sizeof(a),1,pf) == 1){
        if(idinput!=a.ISBN){
            fwrite(&a,sizeof(a),1,pf2);
            }
        if(idinput==a.ISBN){
        printf("\nBook is aviable");
        printf("\nSuccessfully delete");
        count=1;
        }
    }
    fclose(pf);
    fclose(pf2);
    remove("booklist.txt");
    rename("tempbook.txt","booklist.txt");

    if(count!=1){
        printf("\nBook is not found");
        }

    pressfunction();
    adminMenu();
}

void adminBookSearch_title(){
   
    struct book a;
    char title_input[20];
    int count=0;

    header();
    printf("\n\n<--:SEARCH BOOK BY TITLE:-->");

    printf("\nEnter book title: ");
    fflush(stdin);
    scanf("%s",title_input);

    pf = fopen("booklist.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file");
            adminMenu();
        }
        while(fread(&a,sizeof(a),1,pf ) == 1){
            if(strcmp(title_input,a.bookname) == 0){
                printf("\nISBN\tBook title\tAuthor\tQuantity\tCatagory\tRack: ");
            }
            if(strcmp(title_input,a.bookname) == 0){
                printf("\n%d\t%s\t\t%s\t%d\t\t%d\t\t%d",a.ISBN,a.bookname,a.author,a.quantity,a.catagory,a.rack);
                count=1;
            }
            // else booknotfound_admin();
        }
        if(count==0){
            booknotfound_admin();
        }    
    printf("\n\nCatagory table");
    printf("\nAnimals:1     Art:2               Careers:3  Cooking & Food:4");
    printf("\nCrime:5       Fun Facts:6         Fiction:7  Health:8");
    printf("\nLiterature:9  Nature:10           Math:11    Music:12");
    printf("\nPoetrye:13    Reference:14        Careers:15 Religion:16");
    printf("\nScience:17    Social/Cultural:18  Sports:19  Supernatural:20");
    printf("\nWar:21\n");

    fclose(pf);

    pressfunction();
    adminMenu();
}

void adminBookSearch_catagory(){
  
    struct book a;

    int catagory_input;
    int count=0;

    header();
    printf("\n\n<--:SEARCH BOOK BY Catagory:-->");

    printf("\nCatagory table");
    printf("\nAnimals:1     Art:2               Careers:3  Cooking & Food:4");
    printf("\nCrime:5       Fun Facts:6         Fiction:7  Health:8");
    printf("\nLiterature:9  Nature:10           Math:11    Music:12");
    printf("\nPoetrye:13    Reference:14        Careers:15 Religion:16");
    printf("\nScience:17    Social/Cultural:18  Sports:19  Supernatural:20");
    printf("\nWar:21\n");

    printf("\nPlease enter a relevance catagory number: ");
    fflush(stdin);
    scanf("%d",&catagory_input);

    pf = fopen("booklist.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file");
            adminMenu();
        }

        while(fread(&a,sizeof(a),1,pf ) == 1){
           if(catagory_input == a.catagory){
            system("clear");
             printf("\nISBN\tBook title\tAuthor\tQuantity\tCatagory\tRack: ");
            }

            if(catagory_input == a.catagory){
                printf("\n%d\t%s\t\t%s\t%d\t\t%d\t\t%d",a.ISBN,a.bookname,a.author,a.quantity,a.catagory,a.rack);
            count=1;}
        }  
        if(count==0){
        booknotfound_admin();
        }     
    printf("\nCatagory table");
    printf("\nAnimals:1     Art:2               Careers:3  Cooking & Food:4");
    printf("\nCrime:5       Fun Facts:6         Fiction:7  Health:8");
    printf("\nLiterature:9  Nature:10           Math:11    Music:12");
    printf("\nPoetrye:13    Reference:14        Careers:15 Religion:16");
    printf("\nScience:17    Social/Cultural:18  Sports:19  Supernatural:20");
    printf("\nWar:21\n");

    fclose(pf);

    pressfunction();
    adminMenu();
}

void adminBookSearch_id(){
  
    struct book a;

    int id_input;
    int count=0;

    header();
    printf("\n\n<--:SEARCH BOOK BY ISBN:-->");

    printf("\nEnter ISBN: ");
    fflush(stdin);
    scanf("%d",&id_input);

    pf = fopen("booklist.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file");
            adminMenu();
        }
        while(fread(&a,sizeof(a),1,pf ) == 1){
            if(id_input == a.ISBN){
                printf("\nISBN\tBook title\tAuthor\tQuantity\tCatagory\tRack: ");
            }

            if(id_input == a.ISBN){
                printf("\n%d\t%s\t\t%s\t%d\t\t%d\t\t%d",a.ISBN,a.bookname,a.author,a.quantity,a.catagory,a.rack);
                count=1;
            }
        } 
        if(count==0){
            booknotfound_admin();
        }     
    printf("\nCatagory table");
    printf("\nAnimals:1     Art:2               Careers:3  Cooking & Food:4");
    printf("\nCrime:5       Fun Facts:6         Fiction:7  Health:8");
    printf("\nLiterature:9  Nature:10           Math:11    Music:12");
    printf("\nPoetrye:13    Reference:14        Careers:15 Religion:16");
    printf("\nScience:17    Social/Cultural:18  Sports:19  Supernatural:20");
    printf("\nWar:21\n");

    fclose(pf);

    pressfunction();
    adminMenu();
}

void userBookSearch_title(){
  
    struct book a;

    char title_input[SIZE];

    int count=0;

    header();
    printf("\n\n<--:SEARCH BOOK BY TITLE:-->");

    printf("\nEnter book title: ");
    fflush(stdin);
    scanf("%s",title_input);

    pf = fopen("booklist.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file");
            userMenu();
        }
        while(fread(&a,sizeof(a),1,pf ) == 1){
            if(strcmp(title_input,a.bookname) == 0){
        printf("\nISBN\tBook title\tAuthor\tQuantity\tCatagory\tRack: ");
            }
            if(strcmp(title_input,a.bookname) == 0){
                printf("\n%d\t%s\t\t%s\t%d\t\t%d\t\t%d",a.ISBN,a.bookname,a.author,a.quantity,a.catagory,a.rack);
                count=1;
            }
        }
        if(count==0){
            booknotfound_user();
        }      
    printf("\nCatagory table");
    printf("\nAnimals:1     Art:2               Careers:3  Cooking & Food:4");
    printf("\nCrime:5       Fun Facts:6         Fiction:7  Health:8");
    printf("\nLiterature:9  Nature:10           Math:11    Music:12");
    printf("\nPoetrye:13    Reference:14        Careers:15 Religion:16");
    printf("\nScience:17    Social/Cultural:18  Sports:19  Supernatural:20");
    printf("\nWar:21\n");
    fclose(pf);

    pressfunction();
    userMenu();
}

void adminsearchrequest_date(){
  
    struct book a;

    char date_input[SIZE];

    int count=0;

    header();
    printf("\n\n<--:SEARCH BOOK BY DATE:-->");

    printf("\nEnter date of issue (xx.xx.xxxx): ");
    fflush(stdin);
    scanf("%s",date_input);

    pf = fopen("userBook_request.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file");
            adminMenu();
        }
        while(fread(&a,sizeof(a),1,pf ) == 1){
            if(strcmp(date_input,a.issuedate) == 0){
           printf("\nBook title\tAuthor\tISBN\tQuantity\tFirst name\tContact Number\tissue date: ");
            }
            if(strcmp(date_input,a.issuedate) == 0){
            printf("\n%s\t\t%s\t%d\t%d\t\t%s\t\t%d\t\t%s",a.bookname,a.author,a.ISBN,a.quantity,a.request_firstname,a.request_contact_num,a.issuedate);
            count +=1;
            }
        }
        if(count==0){
            booknotfound_admin();
        }      
            printf("\nCatagory table");
            printf("\nAnimals:1     Art:2               Careers:3  Cooking & Food:4");
            printf("\nCrime:5       Fun Facts:6         Fiction:7  Health:8");
            printf("\nLiterature:9  Nature:10           Math:11    Music:12");
            printf("\nPoetrye:13    Reference:14        Careers:15 Religion:16");
            printf("\nScience:17    Social/Cultural:18  Sports:19  Supernatural:20");
            printf("\nWar:21\n");
            fclose(pf);

    pressfunction();
    adminMenu();
}

void adminsearchrequest_name(){
  
    struct book a;

    char username_input[SIZE];

    int count=0;

    header();
    printf("\n\n<--:SEARCH BOOK BY REQUEST NAME:-->");

    printf("\nEnter name of user: ");
    fflush(stdin);
    scanf("%s",username_input);

    pf = fopen("userBook_request.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file");
            adminMenu();
        }
        while(fread(&a,sizeof(a),1,pf ) == 1){
            if(strcmp(username_input,a.request_firstname) == 0){
           printf("\nBook title\tAuthor\tISBN\tQuantity\tFirst name\tContact Number\tissue date: ");
            }
            if(strcmp(username_input,a.request_firstname) == 0){
            printf("\n%s\t\t%s\t%d\t%d\t\t%s\t\t%d\t\t%s",a.bookname,a.author,a.ISBN,a.quantity,a.request_firstname,a.request_contact_num,a.issuedate);
            count +=1;
            }
        }
        if(count==0){
            booknotfound_admin();
        }      
    printf("\nCatagory table");
    printf("\nAnimals:1     Art:2               Careers:3  Cooking & Food:4");
    printf("\nCrime:5       Fun Facts:6         Fiction:7  Health:8");
    printf("\nLiterature:9  Nature:10           Math:11    Music:12");
    printf("\nPoetrye:13    Reference:14        Careers:15 Religion:16");
    printf("\nScience:17    Social/Cultural:18  Sports:19  Supernatural:20");
    printf("\nWar:21\n");
    fclose(pf);

    pressfunction();
    adminMenu();
}

void userBookSearch_catagory(){
   
    struct book a;

    int catagory_input;

    int count=0;

    header();
    printf("\n\n<--:SEARCH BOOK BY Catagory:-->");

    printf("\nCatagory table");
    printf("\nAnimals:1     Art:2               Careers:3  Cooking & Food:4");
    printf("\nCrime:5       Fun Facts:6         Fiction:7  Health:8");
    printf("\nLiterature:9  Nature:10           Math:11    Music:12");
    printf("\nPoetrye:13    Reference:14        Careers:15 Religion:16");
    printf("\nScience:17    Social/Cultural:18  Sports:19  Supernatural:20");
    printf("\nWar:21\n");

    printf("\nPlease enter a relevance catagory number: ");
    fflush(stdin);
    scanf("%d",&catagory_input);

    pf = fopen("booklist.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file");
            userMenu();
        }
        while(fread(&a,sizeof(a),1,pf ) == 1){
            if(catagory_input == a.catagory){
                system("clear");
        printf("\nISBN\tBook title\tAuthor\tQuantity\tCatagory\tRack: ");
            }

            if(catagory_input == a.catagory){
                printf("\n%d\t%s\t\t%s\t%d\t\t%d\t\t%d",a.ISBN,a.bookname,a.author,a.quantity,a.catagory,a.rack);
                count=1;
            }
        }
        if(count==0){
            booknotfound_user();
        }      
    printf("\nCatagory table");
    printf("\nAnimals:1     Art:2               Careers:3  Cooking & Food:4");
    printf("\nCrime:5       Fun Facts:6         Fiction:7  Health:8");
    printf("\nLiterature:9  Nature:10           Math:11    Music:12");
    printf("\nPoetrye:13    Reference:14        Careers:15 Religion:16");
    printf("\nScience:17    Social/Cultural:18  Sports:19  Supernatural:20");
    printf("\nWar:21\n");
    fclose(pf);

    pressfunction();
    userMenu();
}

void userBookSearch_id(){
  
    struct book a;

    int id_input;

    int count=0;

    header();
    printf("\n\n<--:SEARCH BOOK BY ISBN:-->");

    printf("\nEnter ISBN: ");
    fflush(stdin);
    scanf("%d",&id_input);

    pf = fopen("booklist.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file");
            userMenu();
        }
            while(fread(&a,sizeof(a),1,pf ) == 1){
                if(id_input == a.ISBN){
              printf("\nISBN\tBook title\tAuthor\tQuantity\tCatagory\tRack: ");
                }

                if(id_input == a.ISBN){
                    printf("\n%d\t%s\t%s\t%d\t%d\t%d",a.ISBN,a.bookname,a.author,a.quantity,a.catagory,a.rack);
                    count=1;
                }
            }  
        if(count==0){
            booknotfound_user();
        }  
                printf("\nCatagory table");
    printf("\nAnimals:1     Art:2               Careers:3  Cooking & Food:4");
    printf("\nCrime:5       Fun Facts:6         Fiction:7  Health:8");
    printf("\nLiterature:9  Nature:10           Math:11    Music:12");
    printf("\nPoetrye:13    Reference:14        Careers:15 Religion:16");
    printf("\nScience:17    Social/Cultural:18  Sports:19  Supernatural:20");
    printf("\nWar:21\n");  
    fclose(pf);
    pressfunction();
    userMenu();
}

void userRequestBook(){

    struct book a;

    char another ='y';

    header();
    printf("\n\nUSER BOOK REQUEST");
    
    pf =fopen("userBook_request.txt","ab+");
        if(pf == NULL){
            printf("Error opening file");
            userMenu();
        }
        printf("\nPlease enter ");
        while(another == 'y'){
            printf("\nBook title: ");
            fflush(stdin);
            scanf("%s",a.bookname);

            printf("\nBook author: ");
            fflush(stdin);
            scanf("%s",a.author);

            printf("\nISBN: ");
            fflush(stdin);
            scanf("%d",&a.ISBN);

            printf("\nQuantity: ");
            fflush(stdin);
            scanf("%d",&a.quantity);

            printf("\nYour firstName: ");
            fflush(stdin);
            scanf("%s",a.request_firstname);
            fflush(stdin);

            printf("\nYour Contact number: ");
            fflush(stdin);
            scanf("%d",&a.request_contact_num);
            fflush(stdin);

            printf("\nissue date: (xx.xx.xxxx)");
            fflush(stdin);
            scanf("%s",a.issuedate);
            fflush(stdin);

            fwrite(&a,sizeof(a),1,pf);

            system("clear");
            printf("\nRequest sent");

            printf("\npress 'y' to request another book");
            printf("\npress 'n' to  menu ");
            fflush(stdin);	
            another = getchar();
            fflush(stdin);

        }
    fclose(pf);
    pressfunction();
    userMenu();
}

void adminViewbookRequest(){

    struct book a;

    int input;

    int count = 0;

    header();
    printf("\n\n<--:VIEW BOOK REQUEST:-->");
    printf("\nBook title\tAuthor\tISBN\tQuantity\tFirst name\tContact Number\tissue date: ");

    pf = fopen("userBook_request.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file.");
            adminMenu();
        }
    
        while(fread(&a,sizeof(a),1,pf) == 1){
            printf("\n%s\t\t%s\t%d\t%d\t\t%s\t\t%d\t\t%s",a.bookname,a.author,a.ISBN,a.quantity,a.request_firstname,a.request_contact_num,a.issuedate);
            count +=1;
        }
    printf("\nTotal requests: %d",count);

    pressfunction();
    fclose(pf);

    printf("\n①  Accept Request / ②  Reject Request / ③  Back: ");
    scanf("%d",&input);

    if(input==1){ adminBookRequestAccept();}
        else if( input==2){adminBookRequestReject();}
        else if(input==3){adminMenu(); }
            else{
                printf("\n\t\t\tInvalid Operation\n");
                pressfunction();
                adminMenu();
            }
    pressfunction();
    adminMenu();
}

void userViewbookRequest(){

    struct book a;

    int input;

    int count = 0;

    header();
    printf("\n\n<--:VIEW BOOK REQUEST:-->");
    printf("\nBook title\tAuthor\tISBN\tQuantity\tFirst name\tContact Number\t Issue date: ");

    pf = fopen("userBook_request.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file.");
            adminMenu();
        }
    
        while(fread(&a,sizeof(a),1,pf) == 1){
            printf("\n%s\t\t%s\t%d\t%d\t\t%s\t\t%d\t\t%s",a.bookname,a.author,a.ISBN,a.quantity,a.request_firstname,a.request_contact_num,a.issuedate);
            count +=1;
        }
    printf("\nTotal requests: %d",count);

    pressfunction();
    fclose(pf);
    userMenu();
}

void adminBookRequestAccept(){

    struct book a;

    char another ='y';

    int count = 0;

    char booktitle_input[20], authorname_input[30];
    int id_input;

    header();
    printf("\n\nADD BOOKS");
    
    pf =fopen("booklist.txt","ab+");
        if(pf == NULL){
            printf("Error opening file");
            adminMenu();
        }
        while(another == 'y'){
            printf("\nBook title: ");
            fflush(stdin);
            scanf("%s",booktitle_input);

            printf("\nAuthor: ");
            fflush(stdin);
            scanf("%s",authorname_input);

            printf("\nISBN: ");
            fflush(stdin);
            scanf("%d",&id_input);

///
            while(fread(&a,sizeof(a),1,pf)==1){
                if (strcmp(booktitle_input,a.bookname) == 0 && id_input==a.ISBN){
                    printf("\n\t\t\tThis book is already in libibarary...");
                    count=1;
                }
            }
                if (count==1){
                    pressfunction();
                    adminMenu();
                }
            strcpy(a.bookname,booktitle_input);
            strcpy(a.author,authorname_input);
            a.ISBN=id_input;
///

            printf("\nCatagory table");
            printf("\nAnimals:1     Art:2               Careers:3  Cooking & Food:4");
            printf("\nCrime:5       Fun Facts:6         Fiction:7  Health:8");
            printf("\nLiterature:9  Nature:10           Math:11    Music:12");
            printf("\nPoetrye:13    Reference:14        Careers:15 Religion:16");
            printf("\nScience:17    Social/Cultural:18  Sports:19  Supernatural:20");
            printf("\nWar:21\n");

            printf("\nPlease enter a relevance catagory number: ");
            fflush(stdin);
            scanf("%d",&a.catagory);

            printf("\nQuantity: ");
            fflush(stdin);
            scanf("%d",&a.quantity);
            fflush(stdin);

            printf("\nRack: ");
            fflush(stdin);
            scanf("%d",&a.rack);


            fwrite(&a,sizeof(a),1,pf);
            
            system("clear");
            printf("\n Book added success");

            printf("\npress 'y' to add more admin");
            printf("\npress 'n' to  menu: ");
            fflush(stdin);	
            another = getchar();
            fflush(stdin);

        }
    fclose(pf);
    pressfunction();

    adminMenu();
}

void adminBookRequestReject(){

    struct book a;

    char another ='y';

    header();
    printf("\n\nREJECT BOOKS REQUEST");
    
    pf =fopen("userBook_requestReject.txt","ab+");
        if(pf == NULL){
            printf("Error opening file");
            adminMenu();
        } 
        while(another == 'y'){
            printf("\nBook title: ");
            fflush(stdin);
            scanf("%s",a.bookname);

            printf("\nAuthor: ");
            fflush(stdin);
            scanf("%s",a.author);

            printf("\nISBN: ");
            fflush(stdin);
            scanf("%d",&a.ISBN);

            printf("\nCatagory table");
            printf("\nAnimals:1     Art:2               Careers:3  Cooking & Food:4");
            printf("\nCrime:5       Fun Facts:6         Fiction:7  Health:8");
            printf("\nLiterature:9  Nature:10           Math:11    Music:12");
            printf("\nPoetrye:13    Reference:14        Careers:15 Religion:16");
            printf("\nScience:17    Social/Cultural:18  Sports:19  Supernatural:20");
            printf("\nWar:21\n");

            printf("\nPlease enter a relevance catagory number: ");
            fflush(stdin);
            scanf("%d",&a.catagory);

            printf("\nQuantity: ");
            fflush(stdin);
            scanf("%d",&a.quantity);
            fflush(stdin);

            fwrite(&a,sizeof(a),1,pf);
            
            system("clear");
            printf("\n Reject success");

            printf("\npress 'y' to add more books");
            printf("\npress 'n' to  menu: ");
            fflush(stdin);	
            another = getchar();
            fflush(stdin);

        }
    fclose(pf);
    pressfunction();
    adminMenu();
}

void adminViewbookRequestReject(){

    struct book a;

    int input;
    
    int count = 0;

    header();
    printf("\n\n<--:VIEW BOOK REQUEST:-->");
    printf("\nBook title\tAuthor\tISBN\tCatagory\tQuantity: ");

    pf = fopen("userBook_requestReject.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file.");
            adminMenu();
        }
    
        while(fread(&a,sizeof(a),1,pf) == 1){
            printf("\n%s\t\t%s\t%d\t%d\t\t%d",a.bookname,a.author,a.ISBN,a.catagory,a.quantity);
            count +=1;
        }
    printf("\nTotal requests: %d",count);

    fclose(pf);

    pressfunction();
    adminMenu();
}

void adminBookRequestDelete(){

    struct book a;

    int id_input;
    int count = 0;
    header();
    printf("\n\n<--:DELETE RECORD:-->");

    printf("\nISBN: ");
    fflush(stdin);
    scanf("%d",&id_input);

    pf = fopen("userBook_request.txt","r+");
    if(pf == NULL){
        printf("\nError opening file 1");
        adminMenu();
    }

    pf2 = fopen("temp_request.txt","a+");
    if(pf2 == NULL){
        printf("\nError opening file 2");
        adminMenu();
    }
    while(fread(&a,sizeof(a),1,pf) == 1){
        if(id_input!=a.ISBN){
            fwrite(&a,sizeof(a),1,pf2);
            }
        if(id_input==a.ISBN){
            printf("\nBook aviable");
            printf("\nSuccessfully delete");
            count=1;
            }
    }
    fclose(pf);
    fclose(pf2);
    remove("userBook_request.txt");
    rename("temp_request.txt","userBook_request.txt");
    if(count!=1){
    booknotfound_admin();
        }
    pressfunction();
    adminMenu();
}

void userRequestDeleteRequest(){

    struct book a;

    char another ='y';

    header();
    printf("\n\nUSER REQUEST CANCLE REQUEST");
    
    pf =fopen("userRequestDeleteRequest.txt","ab+");
    if(pf == NULL){
        printf("\nError opening file");
        userMenu();
    }
        printf("\nPlease enter ");
        while(another == 'y'){
            printf("\nBook title: ");
            fflush(stdin);
            scanf("%s",a.bookname);

            printf("\nAuthor: ");
            fflush(stdin);
            scanf("%s",a.author);

            printf("\n:Firstname ");
            fflush(stdin);
            scanf("%s",a.request_firstname);

            printf("\n:Contact number");
            fflush(stdin);
            scanf("%d",&a.request_contact_num);

            fwrite(&a,sizeof(a),1,pf);

            system("clear");
	        printf("\nRequest sent");

            printf("\npress 'y' to request another user");
            printf("\npress 'n' to  menu: ");
	            
            fflush(stdin);	
            another = getchar();
            fflush(stdin);
        }
    fclose(pf);
    pressfunction();
    userMenu();
}

void adminViewuserRequestDeleteRequest(){

    struct book a;

    int input;

    int count = 0;

    header();
    printf("\n\n<--:VIEW USER'S BOOK REQUEST:-->");
    printf("\nBook title\tAuthor\tUser firstname\tUser contact number: ");

    pf = fopen("userRequestDeleteRequest.txt","rb+");
        if(pf == NULL){
            printf("\nError opening file.");
            adminMenu();
        }
        while(fread(&a,sizeof(a),1,pf) == 1){
            printf("\n%s\t\t%s\t%s\t\t%d",a.bookname,a.author,a.request_firstname,a.request_contact_num);
            count +=1;
        }
    
    printf("\nTotal requests: %d",count);

    pressfunction();
    fclose(pf);

    adminMenu();
}

void booknotfound_admin(){
    system("clear");
    printf("\n\nbook not found");
    pressfunction();
    adminMenu();
}

void booknotfound_user(){
    system("clear");
    printf("\n\nbook not found");
    pressfunction();
    userMenu();
}

void usernotfound_admin(){
    system("clear");
    printf("\n\nUser not found");
    pressfunction();
    adminMenu();
}

void usernotfound_user(){
    system("clear");
    printf("\n\nUser not found");
    pressfunction();
    userMenu();
}

void admindeleteRequestDeleteRequest(){

    struct book a;

    char bookname_input[SIZE],user_input[SIZE];

    int count = 0;

    header();
    printf("\n\n<--:DELETE RECORD:-->");

    printf("\nbook title: ");
    fflush(stdin);
    scanf("%s",bookname_input);

    printf("\nuser first name: ");
    fflush(stdin);
    scanf("%s",user_input);


    pf = fopen("userRequestDeleteRequest.txt","r+");
    if(pf == NULL){
        printf("\nError opening file 1");
        adminMenu();
    }

    pf2 = fopen("temp_dede_request.txt","a+");
    if(pf2 == NULL){
        printf("\nError opening file 2");
        adminMenu();
    }
    while(fread(&a,sizeof(a),1,pf) == 1){
        if(strcmp(bookname_input,a.bookname)!=0 && strcmp(user_input,a.request_firstname)!=0){
            fwrite(&a,sizeof(a),1,pf2);
            }
        if(strcmp(bookname_input,a.bookname)==0 && strcmp(user_input,a.request_firstname)==0){
            printf("\nBook aviable");
            printf("\nSuccessfully delete");
            count=1;
            }
    }

    fclose(pf);
    fclose(pf2);

    remove("userRequestDeleteRequest.txt");
    rename("temp_dede_request.txt","userRequestDeleteRequest.txt");
    
    if(count!=1){booknotfound_admin();}

    pressfunction();
    adminMenu();
}