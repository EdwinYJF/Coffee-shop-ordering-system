//Yong Jun Fai
//TP068053

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#define FILENAME_SIZE 1024
#define MAX_LINE 2048
#define SEEK_SET 0

FILE* cusFile;
FILE* loginFile;
FILE* dishFile;
FILE* bvgFile;
FILE* tempFile;
FILE* tempFile1;
FILE* tempFile2;
FILE* tempFile3;
FILE* orderFile;

void main_menu();
void staff_login();
void staff_menu();
void add_new_menu();
void add_new_food();
void add_new_beverage();
void update_menu_item();
void update_food();
void update_beverage();
void search_cus_order();
void new_customer();
void login_customer();
void food_menu();
void bvg_menu();
void customer_menu(char username[100],char cusID[100]);
void modify_cus_details(char username[100],char cusID[100]);
void modify_name(char username[100], char cusID[100]);
void modify_houseadd(char username[100],char cusID[100]);
void modify_emailadd(char username[100], char cusID[100]);
void modify_phonenum(char username[100], char cusID[100]);
void modify_gender(char username[100],char cusID[100]);
void modify_DOB(char username[100],char cusID[100]);
void modify_password(char username[100], char cusID[100]);
void order_menu(char username[100],char cusID[100]);
void order_food(char username[100], char cusID[100]);
void order_beverage(char username[100], char cusID[100]);
void payment(char username[100],char cusID[100]);
void view_cancel_order(char username[100], char cusID[100]);

struct customer{

    char customerID[6];
    char cus_name[100];
    char house_address[100];
    char email_address[100];
    char phone_number[100];
    char gender[100];
    char DOB[100];
    char username[100];
    char password[100];
    char confirm_password[100];

};

struct menu{

    char food_name[100];
    char beverages[100];
    double price;
};


void main_menu(){

    char cusID[100], a;
    int user_input;
    while(1){
        printf("\n\t\t\t--------------------------------------------");
        printf("\n\t\t\tDear customer, welcome to Dosta Coffee Shop!");
        printf("\n\t\t\t--------------------------------------------\n");
        printf("\nPlease choose your user type by entering the respective numbers.\n");
        printf("\n");
        printf("\t1. Staff\n \t2. New customers\n \t3. Registered customers\n \t4. Exit\n");
        printf("\nPlease type '1','2', '3' to choose the user type or type '4' to Exit\n");
        printf("\nEnter your choice (1-4): ");
        scanf(" %d",&user_input);
        while (getchar() != '\n'){

        }

        switch (user_input)
        {
        case 1:
            staff_login();
            break;

        case 2:
            new_customer();
            printf("\nPress ANY key to continue....");
            scanf(" %c", &a);
            main_menu();
            break;

        case 3:
            login_customer();
            break;

        case 4:
            printf("\nPlease visit us again, thank you and have a nice day!\n");
            exit(1);

        default:
            printf("\nInvalid input!\n");
            printf("\nPlease follow the instructions given!\n");
            main_menu();
            break;
        }
        break;
        }
    return;
}

void staff_login(){

    int user_input = 0;
    char staff1[100] = "Yong Jun Fai";
    char staff2[100] = "Lecturer";
    char pw1[50] = "Yong123";
    char pw2[50] = "Lec123";
    char staff_username_input[100];
    char staff_pw_input[50];
    while(user_input != 2){
        printf("\nType '1' to continue or type '2' to exit from the staff login\n");
        printf("\n\t1. Continue\n\t2. Exit\n");
        printf("\nEnter your choice (1-2): ");
        scanf("%d",&user_input);
        while (getchar() != '\n'){

        }
        switch(user_input)
        {
        case 1:
            while(1){
                printf("\nThis is the staff login interface. Please enter your username and password to login.\n");
                printf("\nEnter staff username: ");
                scanf(" %[^\n]%*c", staff_username_input);
                printf("\nEnter password: ");
                scanf(" %[^\n]%*c", staff_pw_input);
                if (strcmp(staff_username_input,staff1) == 0 || strcmp(staff_username_input, staff2) == 0){
                }
                else{
                    fflush(stdin);
                    printf("\nInvalid username! Please enter the correct username.\n");
                    continue;
                }
                if (strcmp(staff_pw_input, pw1) == 0 || strcmp(staff_pw_input,pw2) == 0){
                    printf("\nAccess granted!\n");
                    printf("\nWelcome to the staff system, %s!\n",staff_username_input);
                    staff_menu();
                    break;
                }
                else{
                    fflush(stdin);
                    printf("\nInvalid password! Please enter the correct password.\n");
                    continue;
                }
            }
            break;

        case 2:
            main_menu();
            break;

        default:
            printf("\nInvalid input!\n");
            staff_login();
            break;
        }
        break;
    }
    return;
}


void new_customer(){

    int user_input = 0, cusID = 1, flag = 1;
    struct customer cus;
    char buffer[100], a, line [255], file_cusID[100], file_name[100], file_address[100], file_email[100], file_phone[100], file_gender[100], file_DOB[100], file_username[100], file_password[100];
    char gender1[10] = "Male";
    char gender2[10] = "Female";
    char password[100];
    while(user_input != 2){
        printf("\n\t\t******* Hello there our new customer! Welcome to Dosta Coffee Shop! *******\n");
        printf("\n");
        printf("\nType '1' to register an account now or type '2' to exit from the registration interface\n");
        printf("\n");
        printf("\t1. Register\n\t2. Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %d",&user_input);
        while (getchar() != '\n'){

        }

        switch (user_input)
        {
        case 1:
            break;

        case 2:
            main_menu();
            break;

        default:
            printf("\nInvalid input! Please type '1' to register an account or type '2' to exit!\n");
            new_customer();
            break;
        }
        break;
    }

    cusFile = fopen("cus_details.txt","a+");
    if(cusFile != NULL){

        printf("\nBefore you register, here is your customer ID generated by our system\n");
        while(fgets(line, 1024, cusFile)) cusID++;
        printf("\nDear customer, your customer ID is DT%03d\n", cusID);
        printf("\nPlease jot down your customer ID so that you won't forget\n");
        fprintf(cusFile, "DT%03d ", cusID);
        printf("\nEnter your full name: ");
        scanf(" %[^\n]%*c", cus.cus_name);
        for(int i = 0; cus.cus_name[i] != '\0'; i++)
        {
            if (cus.cus_name[i] == ' ')
            {
                cus.cus_name[i] = '_';
            }
        }
        fprintf(cusFile, "%s", cus.cus_name);

        for(int i = 0; cus.cus_name[i] != '\0'; i++)
        {
            if (cus.cus_name[i] == '_')
            {
                cus.cus_name[i] = ' ';
            }
        }
        printf("\nHi %s, welcome to Dosta Coffee Shop, please continue to register.\n",cus.cus_name);
        printf("\nEnter your house address: ");
        scanf(" %[^\n]%*c", cus.house_address);
        for(int i = 0; cus.house_address[i] != '\0'; i++)
        {
            if (cus.house_address[i] == ' ')
            {
                cus.house_address[i] = '_';
            }
        }
        fprintf(cusFile, " %s", cus.house_address);

        printf("\nEnter your email address: ");
        scanf(" %s", cus.email_address);
        fprintf(cusFile, " %s", cus.email_address);

        printf("\nEnter your phone number: ");
        scanf(" %s", cus.phone_number);
        fprintf(cusFile, " %s", cus.phone_number);

        while(1)
        {
            printf("\nEnter your gender (Male / Female): ");
            scanf(" %s", cus.gender);
            cus.gender[0] = toupper(cus.gender[0]);
            if (strcmp(cus.gender, gender1) == 0 || strcmp(cus.gender, gender2) == 0)
            {
                fprintf(cusFile, " %s", cus.gender);
                break;
            }
            else
            {
                printf("\nInvalid input! Please insert a valid gender!\n");
                continue;
            }
        }

        printf("\nEnter your date of birth (DD/MM/YY): ");
        scanf(" %s", cus.DOB);
        fprintf(cusFile, " %s", cus.DOB);

        while(1)
        {
            printf("\nNow create your username!\n");
            printf("\nYour username should not consist of spaces!\n");
            printf("\nEnter your username: ");
            scanf(" %s", cus.username);
            fseek(cusFile, 0, SEEK_SET);
            while(!feof(cusFile))
            {
                fscanf(cusFile, "%s %s %s %s %s %s %s %s %s\n",file_cusID,file_name,file_address,file_email,file_phone,file_gender,file_DOB,file_username,file_password);
                if (strcmp(cus.username,file_username) == 0)
                {
                    flag = 0;
                    printf("\nUsername has already existed!\n");
                    printf("\nPlease create another username\n");
                    break;
                }
                else
                {
                    flag++;
                    continue;
                }
            }
            if(flag)
            {
                fprintf(cusFile, " %s", cus.username);
                break;
            }
        }
        printf("\nDear %s, your username is %s\n",cus.cus_name, cus.username);
        while(1)
        {
            char c;
            printf("\nEnter your password that should satisfy the following criteria\n");
            printf("\n\t1. Password should contain atleast one capital letter\n\t2. Should have one digit from(0-9)\n\t3. Atleast one special charecter($,*,#,&,@)\n\t4. Length should be atleast 8\n");
            printf("\nEnter your password: ");
            scanf(" %s",password);
            int len, i, flag1 = 0,flag2 = 0,flag3 = 0,flag4 = 0;
            len=strlen(password);
            if(len < 8)
            {
                flag1=1;
            }

            else
            {
                for(i=0; i<len; i++)
                if((password[i]>= 48 && password[i] <= 58))// numbers from 0-9 including :
                {
                    flag2=0;
                    break;
                }
                else
                flag2=1;

                for(i=0; i<len; i++)
                if((password[i]>= 65&& password[i]<= 90))// capital letters from A to Z
                {
                    flag3=0;
                    break;
                }
                else
                flag3 = 1;

                for(i=0;i<len;i++)
                if(password[i]=='#'||password[i]=='$'||password[i]=='*'||password[i]=='&'||password[i] == '@')
                {
                    flag4 = 0;
                    break;
                }
                else
                flag4=1;
            }

            if(flag1==1||flag2==1||flag3==1||flag4==1)
            {
                printf("\nPassword is not strong enough!\n");
                continue;
            }
            else
            {
                printf("\nYour password is created successfully\n");
                printf("\nYour password is %s, please remember to jot down this password and use it to login to your account\n", password);
                fprintf(cusFile, " %s\n", password);
                break;
            }
        }
        printf("\nYou have registered succesfully!\n");
        fclose(cusFile);
    }
    else{
        printf("\nFile does not exist!\n");
        exit(1);
    }
    return;
}

void login_customer(){

    int opt, count = 3;
    struct customer login;
    char filecus_ID[100], filecus_name[100], filehouse_add[100], file_email[100], filephone_number[100], file_gender[100], file_DOB[100], username[100], password[100], file_password[13], cusID[100];
    while(1){
        printf("\n\t\t******* Welcome to Dosta Coffee Shop! *******\n");
        printf("\nWe are a coffee shop that sells food and beverages!\n");
        printf("\nThis is the login interface!\n");
        printf("\nDo you wish to continue?\n");
        printf("\nType '1' to continue or type '2' to Exit\n");
        printf("\n\t1. Continue\n \t2. Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %d", &opt);
        while (getchar() != '\n'){

        }

        if(opt == 1)
        {
            break;
        }

        else if (opt == 2)
        {
            main_menu();
            break;
        }

        else
        {
            printf("\nInvalid input!\n");
            continue;
        }
    }

    printf("\nPlease enter your login credentials to get access to the customer menu!\n");

    cusFile = fopen("cus_details.txt","r");
    if (cusFile == NULL){
        printf("\nFile can't be opened!\n");
        exit(1);
    }

    printf("\nEnter username: ");
    scanf(" %s", username);
    printf("\nEnter password: ");
    scanf(" %s", password);

    int flag = 0;
    fseek(cusFile, 0, SEEK_SET);
    cusID[0] = "\0";
    while (!feof(cusFile))
    {
        fscanf(cusFile, "%s %s %s %s %s %s %s %s %s\n",filecus_ID,filecus_name,filehouse_add,file_email,filephone_number,file_gender,file_DOB,login.username,file_password);
        if (strcmp(username, login.username) == 0 && strcmp(password, file_password) == 0)
        {
            printf("\nAccess granted!\n");
            printf("\nIt's great to see you again %s!\n", login.username);
            printf("\n");
            flag = 1;
            fclose(cusFile);
            customer_menu(login.username,filecus_ID);
            break;
        }
        else
        {
            flag++;
            continue;
        }
    }
    if(flag)
    {
        printf("\nIncorrect username or password! Please enter the correct credentials!\n");
        fclose(cusFile);
        login_customer();
    }

    return;
}

void staff_menu(){

    int user_input = 0;
    char a;
    while(user_input != 6){
        printf("\nYou may select a type of function by entering the number from the options given below.\n");
        printf("\n\t1. View menu\n \t2. Add new menu item\n \t3. Update the menu item\n \t4. Create customer account\n \t5. Search customer order\n \t6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&user_input);
        while (getchar() != '\n'){

        }

        switch(user_input)
        {
        case 1:
            food_menu();
            printf("\n");
            bvg_menu();
            char ch;
            printf("\n\t\tPress ENTER key to Continue....\n");
            scanf("%c",&ch);
            staff_menu();
            break;

        case 2:
            add_new_menu();
            break;

        case 3:
            update_menu_item();
            break;

        case 4:
            new_customer();
            printf("\nPress ANY key to continue....");
            scanf(" %c", &a);
            staff_menu();
            break;

        case 5:
            search_cus_order();
            break;

        case 6:
            main_menu();
            break;

        default:
            printf("\nInvalid input!");
            staff_menu();
            break;

        }
        break;
        }
    return;
}


void add_new_menu(){

    int opt = 0;
    while(opt != 3){

        printf("\nThis interface allows the staffs to add new items to the menu!\n");
        printf("\n\t1. Food\n \t2. Beverages\n \t3. Exit\n");
        printf("\nEnter your choice (1-3): ");
        scanf(" %d",&opt);
        while (getchar() != '\n'){

        }
        printf("\n");

        switch(opt)
        {
        case 1:
            add_new_food();
            break;

        case 2:
            add_new_beverage();
            break;

        case 3:
            staff_menu();
            break;

        default:
            printf("\nInvalid input!\n");
            printf("\nPlease follow the instructions given!\n");
            add_new_menu();
            break;
        }
        break;
    }
    return;
}

void food_menu(){

    char line[255], filefood_name[100], ID[6];
    double filefood_price;
    dishFile = fopen("dish_menu.txt","r");
    if (dishFile == NULL)
    {
        printf("\nFile can't be opened!\n");
        exit(1);
    }
    printf("\t\t------------------------------");
    printf("\n\t\t\t  Food menu\n");
    printf("\t\t------------------------------\n");
    printf("\n\t\tID   Food name\t\t  Price\n");
    printf("\n");
    while(!feof(dishFile))
    {
        fscanf(dishFile, "%s %s %lf\n",ID,filefood_name,&filefood_price);
        for(int i = 0; filefood_name[i] != '\0'; i++)
        {
            if(filefood_name[i] == '_')
            {
                filefood_name[i] = ' ';
            }
        }
        printf("\t\t%-2s %-20s RM%.2f\n",ID,filefood_name,filefood_price);
    }
    fclose(dishFile);
    return;
}


void bvg_menu(){

    char line[255], filebvg_name[100], ID[6];
    double filebvg_price;
    bvgFile = fopen("beverage_menu.txt","r");
    if (bvgFile == NULL)
    {
        printf("\nFile can't be opened");
        exit(1);
    }
    printf("\t\t-------------------------------");
    printf("\n\t\t\t  Beverage menu\n");
    printf("\t\t-------------------------------\n");
    printf("\n\t\tID   Beverage name        Price\n");
    printf("\n");

    while(!feof(bvgFile))
    {
        fscanf(bvgFile, "%s %s %lf\n",ID,filebvg_name,&filebvg_price);
        for(int i = 0; filebvg_name[i] != '\0'; i++)
        {
            if(filebvg_name[i] == '_')
            {
                filebvg_name[i] = ' ';
            }
        }
        printf("\t\t%-2s %-20s RM%.2f\n",ID,filebvg_name,filebvg_price);
    }
    fclose(bvgFile);
    return;
}

void add_new_food()
{
    struct menu food;
    char line[255], filefood_name[100], ID[6];
    double filefood_price;
    int opt, foodID = 1, flag = 1;
    dishFile = fopen("dish_menu.txt","a+");
    food_menu();
    if (dishFile != NULL)
    {
        dishFile = fopen("dish_menu.txt","a+");
        while(fgets(line, 1024, dishFile)) foodID++;
        while(1)
        {
            printf("\nEnter food name: ");
            scanf(" %[^\n]%*c", food.food_name);
            for(int i = 0; food.food_name[i] != '\0'; i++)
            {
                if(food.food_name[i] == ' ')
                {
                    food.food_name[i] = '_';
                }
            }

            while(1)
            {
                printf("\nEnter Price (RM): ");
                scanf(" %lf", &food.price);
                if(food.price <= 0)
                {
                    fflush(stdin);
                    printf("\nInvalid input, please enter a valid price!\n");
                    continue;
                }
                else
                {
                    fflush(stdin);
                    break;
                }
            }
            fseek(dishFile, 0, SEEK_SET);
            while(!feof(dishFile))
            {
                fscanf(dishFile, "%s %s %lf\n",ID,filefood_name,&filefood_price);
                if (strcmp(food.food_name, filefood_name) == 0)
                {
                    flag = 0;
                    printf("\nFood name has already exist in the menu!\n");
                    printf("\nPlease insert another name\n");
                    fclose(dishFile);
                    add_new_food();
                    break;
                }
                else
                {
                    continue;
                }
            }

            if (flag)
            {
                fprintf(dishFile, "F%03d ", foodID);
                fprintf(dishFile,"%s ", food.food_name);
                fprintf(dishFile, "%.2f\n", food.price);
                printf("\nThe food name and price has been appended into text file successfully!\n");
                fclose(dishFile);
                break;
            }
        }
    }
    else
    {
        printf("\nFile can't be opened!\n");
        exit(1);
    }

    do{
        printf("\nType '1' to continue add new items to menu or type '2' to exit.\n");
        printf("\n\t1. Continue\n \t2. Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %d",&opt);
        while (getchar() != '\n'){

        }

        if (opt == 1)
        {
            add_new_food();
            break;
        }
        else if (opt < 1 || opt > 2)
        {
            printf("\nInvalid input!\n");
            continue;
        }
    }while(opt != 2);
    add_new_menu();
    return;
}

void add_new_beverage()
{
    struct menu bvg;
    char line[255], filebvg_name[100], ID[6];
    double filebvg_price;
    int opt, bvgID = 1, flag = 1;
    bvgFile = fopen("beverage_menu.txt","a+");
    bvg_menu();
    if (bvgFile != NULL)
    {
        bvgFile = fopen("beverage_menu.txt","a+");
        while(fgets(line, 1024, bvgFile)) bvgID++;
        while(1)
        {
            printf("\nEnter beverage name: ");
            scanf(" %[^\n]%*c", bvg.beverages);
            for(int i = 0; bvg.beverages[i] != '\0'; i++)
            {
                if(bvg.beverages[i] == ' ')
                {
                    bvg.beverages[i] = '_';
                }
            }

            while(1)
            {
                printf("\nEnter Price (RM): ");
                scanf(" %lf", &bvg.price);
                if(bvg.price <= 0)
                {
                    fflush(stdin);
                    printf("\nInvalid input, please enter a valid price!\n");
                    continue;
                }
                else
                {
                    fflush(stdin);
                    break;
                }
            }
            fseek(bvgFile, 0, SEEK_SET);
            while(!feof(bvgFile))
            {
                fscanf(bvgFile, "%s %s %lf\n",ID,filebvg_name,&filebvg_price);
                if (strcmp(bvg.beverages, filebvg_name) == 0)
                {
                    flag = 0;
                    printf("\nBeverage name has already exist in the menu!\n");
                    printf("\nPlease insert another name\n");
                    fclose(bvgFile);
                    add_new_beverage();
                    break;
                }
                else
                {
                    continue;
                }
            }

            if (flag)
            {
                fprintf(bvgFile, "B%03d ", bvgID);
                fprintf(bvgFile,"%s ", bvg.beverages);
                fprintf(bvgFile, "%.2f\n", bvg.price);
                printf("\nThe beverage name and price has been appended into text file successfully!\n");
                fclose(bvgFile);
                break;
            }
        }
    }
    else
    {
        printf("\nFile can't be opened!\n");
    }

    do{
        printf("\nType '1' to continue add new items to menu or type '2' to exit.\n");
        printf("\n\t1. Continue\n \t2. Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %d",&opt);
        while (getchar() != '\n'){

        }

        if (opt == 1)
        {
            add_new_beverage();
            break;
        }
        else if (opt < 1 || opt > 2)
        {
            printf("\nInvalid input!\n");
            printf("\nPlease follow the instructions given!\n");
            continue;
        }
    }while(opt != 2);
    add_new_menu();
    return;
}


void update_menu_item(){

    int opt = 0;
    while(opt != 3){

        printf("\nThis interface allows the staffs to update the items in the menu!\n");
        printf("\n\t1. Food\n \t2. Beverages\n \t3. Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %d",&opt);
        while (getchar() != '\n'){

        }

        switch(opt)
        {
        case 1:
            update_food();
            break;

        case 2:
            update_beverage();
            break;

        case 3:
            staff_menu();
            break;

        default:
            printf("\nInvalid input!\n");
            printf("\nPlease follow the instructions given!\n");
            update_menu_item();
            break;

        }
        break;
    }
    return;
}

void update_food(){

    char foodID[MAX_LINE], file_ID[7],filefood_name[100],new_name[100];
    char nfile_ID[7], nfilefood_name[100];
    double new_price, filefood_price, nfilefood_price;
    int opt, flag = 1;
    printf("\nYou have chosen to update the food section in the menu!\n");
    printf("\nBelow is the current menu\n");
    printf("\n");
    food_menu();
    dishFile = fopen("dish_menu.txt","r");
    tempFile = fopen("temp_file_food.txt","w");
    printf("\nEnter the food ID to update the menu!\n");
    printf("\nEnter food ID (eg F001): ");
    fgets(foodID, MAX_LINE, stdin);
    foodID[strcspn(foodID, "\n")] = 0;
    foodID[0] = toupper(foodID[0]);
    while(!feof(dishFile))
    {
        fscanf(dishFile,"%s %s %lf\n",file_ID,filefood_name,&filefood_price);
        if(strcmp(foodID, file_ID) == 0)
        {
            flag = 0;
            printf("\nItem found!\n");
            for (int i = 0; filefood_name[i] != '\0'; i++)
            {
                if (filefood_name[i] == '_')
                {
                    filefood_name[i] = ' ';
                }
            }
            printf("\n\t\tID   Food name\t\t  Price\n");
            printf("\t\t%-2s %-20s RM%.2f\n",file_ID,filefood_name,filefood_price);
            break;
        }
        else
        {
            continue;
        }
    }

    if(flag)
    {
        printf("\nItem not found or item does not exist in the menu!\n");
        fclose(dishFile);
        update_food();
    }
    while(1)
    {
        if (dishFile == NULL)
        {
            printf("\nFile can't be opened!\n");
            exit(1);
        }
        printf("\nEnter the new food name that you wanted to update\n");
        printf("\nEnter new food name: ");
        fgets(new_name, 100, stdin);
        new_name[strcspn(new_name, "\n")] = 0;

        for(int i = 0; new_name[i] != '\0'; i++)
        {
            if (new_name[i] == ' ')
            {
                new_name[i] = '_';
            }
        }

        fseek(dishFile, 0 ,SEEK_SET);
        while(!feof(dishFile))
        {
            fscanf(dishFile, "%s %s %lf\n",nfile_ID,nfilefood_name,&nfilefood_price);
            if (strcmp(new_name, nfilefood_name) == 0)
            {
                flag = 0;
                printf("\nFood name has already exist in the menu!\n");
                printf("\nPlease insert another name\n");
                update_food();
                break;
            }
            else
            {
                flag++;
                continue;
            }
        }

        if (flag)
        {
            break;
        }
        break;
    }

    flag = 1;

    while(1)
    {
        printf("\nEnter the new food price that you wanted to update\n");
        printf("\nEnter new price (RM): ");
        scanf(" %lf", &new_price);
        if(new_price <= 0)
        {
            fflush(stdin);
            printf("\nInvalid input, please enter a valid price!\n");
            continue;
        }
        else
        {
            break;
        }
    }
    fseek(dishFile, 0, SEEK_SET);
    while(!feof(dishFile))
    {
        fscanf(dishFile, "%s %s %lf\n",file_ID, filefood_name, &filefood_price);

        if(strcmp(foodID, file_ID) == 0)
        {
            flag = 0;
            fprintf(tempFile, "%s %s %.2f\n", file_ID, new_name, new_price);
        }
        else
        {
            fprintf(tempFile, "%s %s %.2f\n", file_ID, filefood_name, filefood_price);
            continue;
        }
    }

    fclose(dishFile);
    fclose(tempFile);
    remove("dish_menu.txt");
    rename("temp_file_food.txt","dish_menu.txt");

    if (flag)
    {
        printf("\nItem not found or item does not exist in the menu!\n");
        fclose(dishFile);
        fclose(tempFile);
        update_food();
    }
    printf("\t\t------------------------------------");
    printf("\n\t\tThe menu has been updated successfully\n");
    printf("\t\t------------------------------------\n");
    do{
        printf("\nType '1' to continue update food menu or type '2' to exit.\n");
        printf("\n\t1. Continue\n \t2. Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %d",&opt);
        while (getchar() != '\n'){

        }

        if (opt == 1)
        {
            update_food();
            break;
        }
        else if (opt < 1 || opt > 2)
        {
            printf("\nInvalid input!\n");
            printf("\nPlease follow the instructions given!\n");
            continue;
        }
    }while(opt != 2);
    update_menu_item();
    return;
}

void update_beverage(){

    char bvgID[7], file_ID[7],filebvg_name[100],new_name[100];
    char nfile_ID[7], nfilebvg_name[100];
    double new_price, filebvg_price, nfilebvg_price;
    int opt, flag = 1;
    printf("\nYou have chosen to update the beverages section in the menu!\n");
    printf("\nBelow is the current menu\n");
    printf("\n");
    bvg_menu();
    bvgFile = fopen("beverage_menu.txt","r");
    tempFile1 = fopen("temp_file_bvg.txt","w");
    printf("\nEnter the beverage ID to update the menu!\n");
    printf("\nEnter beverage ID (eg B001): ");
    scanf(" %s",bvgID);
    bvgID[0] = toupper(bvgID[0]);

    while(!feof(bvgFile))
    {
        fscanf(bvgFile,"%s %s %lf\n",file_ID,filebvg_name,&filebvg_price);
        if(strcmp(bvgID, file_ID) == 0)
        {
            flag = 0;
            printf("\nItem found!\n");
            for (int i = 0; filebvg_name[i] != '\0'; i++)
            {
                if (filebvg_name[i] == '_')
                {
                    filebvg_name[i] = ' ';
                }
            }
            printf("\n\t\tID   Beverage name\t\t  Price\n");
            printf("\t\t%-2s %-28s RM%.2f\n",file_ID,filebvg_name,filebvg_price);
            break;
        }
        else
        {
            continue;
        }
    }

    if(flag)
    {
        printf("\nItem not found or item does not exist in the menu!\n");
        fclose(bvgFile);
        update_beverage();
    }

    while(1)
    {
        if (bvgFile == NULL)
        {
            printf("\nFile does not exist!\n");
            exit(1);
        }
        printf("\nEnter the new beverage name that you wanted to update\n");
        printf("\nEnter new beverage name: ");
        scanf(" %[^\n]%*c", new_name);

        for(int i = 0; new_name[i] != '\0'; i++)
        {
            if (new_name[i] == ' ')
            {
                new_name[i] = '_';
            }
        }

        fseek(bvgFile, 0 ,SEEK_SET);
        while(!feof(bvgFile))
        {
            fscanf(bvgFile, "%s %s %lf\n",nfile_ID,nfilebvg_name,&nfilebvg_price);
            if (strcmp(new_name, nfilebvg_name) == 0)
            {
                flag = 0;
                printf("\nBeverage name has already exist in the menu!\n");
                printf("\nPlease insert another name\n");
                update_beverage();
                break;
            }
            else
            {
                flag++;
                continue;
            }
        }

        if (flag)
        {
            break;
        }
        break;
    }

    flag = 1;
    while(1)
    {
        printf("\nEnter the new beverage price that you wanted to update\n");
        printf("\nEnter new price (RM): ");
        scanf(" %lf", &new_price);
        if(new_price <= 0)
        {
            fflush(stdin);
            printf("\nInvalid input, please enter a valid price!\n");
            continue;
        }
        else
        {
            break;
        }
    }
    fseek(bvgFile, 0, SEEK_SET);
    while(!feof(bvgFile))
    {
        fscanf(bvgFile, "%s %s %lf\n",file_ID, filebvg_name, &filebvg_price);

        if(strcmp(bvgID, file_ID) == 0)
        {
            flag = 0;
            fprintf(tempFile1, "%s %s %.2f\n", file_ID, new_name, new_price);
        }
        else
        {
            fprintf(tempFile1, "%s %s %.2f\n", file_ID, filebvg_name, filebvg_price);
            continue;
        }
    }

    fclose(bvgFile);
    fclose(tempFile1);
    remove("beverage_menu.txt");
    rename("temp_file_bvg.txt","beverage_menu.txt");

    if (flag)
    {
        printf("\nItem not found or item does not exist in the menu!\n");
        fclose(dishFile);
        fclose(tempFile1);
        update_beverage();
    }
    printf("\t\t------------------------------------");
    printf("\n\t\tThe menu has been updated successfully\n");
    printf("\t\t------------------------------------\n");
    do{
        printf("\nType '1' to continue update beverage menu or type '2' to exit.\n");
        printf("\n\t1. Continue\n \t2. Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %d",&opt);
        while (getchar() != '\n'){

        }

        if (opt == 1)
        {
            update_beverage();
            break;
        }
        else if (opt < 1 || opt > 2)
        {
            printf("\nInvalid input!\n");
            printf("\nPlease follow the instructions given!\n");
            continue;
        }
    }while(opt != 2);
    update_menu_item();
    return;
}


void search_cus_order(){

    char customer_ID[100], filecus_ID[100], file_username[100], fileitem_name[100];
    int flag = 1, orderID, quantity, opt;
    double price, sub_total = 0, total = 0;
    orderFile = fopen("cus_order.txt","r");

    if (orderFile == NULL)
    {
        printf("\nFile can't be opened!\n");
        exit(1);
    }
    printf("\nThis is the search function!\n");
    printf("\nType the customer's Customer ID in the search bar to search for their orders!\n");
    printf("\nEnter customer's ID: ");
    scanf(" %s",customer_ID);

    printf("\n\tOrder ID    Customer ID    Username    Item name\t  Quantity    Price\t\tSub total\n");
    printf("\n\t--------------------------------------------------------------------------------------------------\n");
    while(!feof(orderFile))
    {
        fscanf(orderFile,"%03d %s %s %s %d %lf\n",&orderID, filecus_ID, file_username, fileitem_name, &quantity, &price);
        if (strcmp(customer_ID, filecus_ID) == 0)
        {
            flag = 0;
            for (int i = 0; fileitem_name[i] != '\0'; i++)
            {
                if (fileitem_name[i] == '_')
                {
                    fileitem_name[i] = ' ';
                }
            }
            sub_total = quantity * price;
            total = total + sub_total;
            printf("\n\t%03d \t    %-14s %-11s %-15s       %d        RM %2.2f \t\tRM %2.2f\n", orderID, filecus_ID, file_username, fileitem_name, quantity, price, sub_total);
        }
    }
    printf("\n\t--------------------------------------------------------------------------------------------------");
    printf("\n\tTotal:                                                                                  RM %.2f\n",total);
    if (flag)
    {
        printf("\nThe customer did not make any orders\n");
        fclose(orderFile);
        staff_menu();
    }

    do{
        printf("\nType '1' to CONTINUE SEARCHING CUSTOMER'S ORDERS or type '2' to EXIT.\n");
        printf("\n\t1. Search again\n\t2. Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %d",&opt);
        while (getchar() != '\n'){

        }

        if (opt == 1)
        {
            fclose(orderFile);
            search_cus_order();
            break;
        }
        else if (opt < 1 || opt > 2)
        {
            fflush(stdin);
            printf("\nInvalid input!\n");
            printf("\nPlease follow the instructions given!\n");
            continue;
        }
    }while(opt != 2);
    fclose(orderFile);
    staff_menu();
    return;
}

void customer_menu(char username[100], char cusID[100]){

    int user_input = 0;
    while(user_input != 5){
        printf("\t\t------------------------------");
        printf("\n\t\t\t    %s\n",username);
        printf("\t\t------------------------------\n");
        printf("\nYou may select a type of function from the options below by entering the number.\n");
        printf("\n\t1. Modify your details\n \t2. Order food & beverages\n \t3. View & cancel order\n \t4. Payment\n \t5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&user_input);
        while (getchar() != '\n'){

        }
        printf("\n");

        switch(user_input){

        case 1:
            modify_cus_details(username,cusID);
            break;

        case 2:
            order_menu(username,cusID);
            break;

        case 3:
            view_cancel_order(username, cusID);
            break;

        case 4:
            payment(username, cusID);
            break;

        case 5:
            main_menu();
            break;

        default:
            printf("\nInvalid input!\n");
            printf("\nPlease follow the instructions given!\n");
            customer_menu(username,cusID);
            break;

        }
        break;
    }
    return;
}

void modify_cus_details(char username[100],char cusID[100]){

    int opt = 0, flag = 1;
    char file_cusID[100], file_name[100], file_address[100], file_email[100], file_phone_num[100], file_gender[100], file_DOB[100], file_username[100], file_password[100];
    cusFile = fopen("cus_details.txt","r");

    if (cusFile == NULL)
    {
        printf("\nFile can't be opened!\n");
        exit(1);
    }
    printf("\nDear %s, this interface allows you to change your details\n",username);
    printf("\nYou are not allowed to modify your username!\n");
    printf("\n");
    while(opt != 8)
    {
        while(!feof(cusFile))
        {
            fscanf(cusFile,"%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
            if (strcmp(cusID, file_cusID) == 0)
            {
                for (int i = 0; file_name[i] != '\0'; i++)
                {
                    if (file_name[i] == '_')
                    {
                        file_name[i] = ' ';
                    }
                }
                for (int i = 0; file_address[i] != '\0'; i++)
                {
                    if (file_address[i] == '_')
                    {
                        file_address[i] = ' ';
                    }
                }
                flag = 0;
                printf("\t\t------------------------------");
                printf("\n\t\t\t    %s\n", file_username);
                printf("\t\t------------------------------\n");
                printf("\n\t\tCustomer ID: %s",cusID);
                printf("\n\t\tName: %s",file_name);
                printf("\n\t\tHouse address: %s",file_address);
                printf("\n\t\tEmail address: %s",file_email);
                printf("\n\t\tPhone number: %s",file_phone_num);
                printf("\n\t\tGender: %s",file_gender);
                printf("\n\t\tDate of birth: %s",file_DOB);
                printf("\n\t\tUsername: %s",file_username);
                printf("\n\t\tPassword: %s",file_password);
                printf("\n");
                break;
            }
            else
            {
                flag++;
                continue;
            }
        }
        if (flag)
        {
            fclose(cusFile);
            printf("\nUser does not exist!\n");
            customer_menu(username, cusID);
        }
        fclose(cusFile);
        printf("\nSelect from '1-7' to modify your details or select '8' to exit\n");
        printf("\n\t1. Name\n\t2. House address\n\t3. Email address\n\t4. Phone number\n \t5. Gender\n \t6. Date of birth\n \t7. Password\n \t8. Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %d", &opt);
        while (getchar() != '\n'){

        }
        switch(opt)
        {
        case 1:
            modify_name(username,cusID);
            break;

        case 2:
            modify_houseadd(username,cusID);
            break;

        case 3:
            modify_emailadd(username,cusID);
            break;

        case 4:
            modify_phonenum(username,cusID);
            break;

        case 5:
            modify_gender(username, cusID);
            break;

        case 6:
            modify_DOB(username, cusID);
            break;

        case 7:
            modify_password(username,cusID);
            break;

        case 8:
            customer_menu(username, cusID);
            return;

        default:
            printf("\nInvalid input! Please follow the instructions given!\n");
            modify_cus_details(username,cusID);
            break;
        }
        break;
    }
    return;
}


void modify_name(char username[100], char cusID[100])
{
    int flag = 1;
    char new_name[100], a;
    char file_cusID[100], file_name[100], file_address[100], file_email[100], file_phone_num[100], file_gender[100], file_DOB[100], file_username[100], file_password[100];
    cusFile = fopen("cus_details.txt","r");
    if(cusFile == NULL)
    {
        printf("\nFile can't be opened!\n");
        exit(1);
    }
    printf("\nEnter new name: ");
    scanf(" %[^\n]%*c", new_name);
    for (int i = 0; new_name[i] != '\0'; i++)
    {
        if (new_name[i] == ' ')
        {
            new_name[i] = '_';
        }
    }
    tempFile3 = fopen("temp_cus_details.txt","w");
    while(!feof(cusFile))
    {
        fscanf(cusFile,"%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
        if (strcmp(cusID, file_cusID) == 0)
        {
            flag = 0;
            fprintf(tempFile3, "%s %s %s %s %s %s %s %s %s\n", file_cusID, new_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
        }
        else
        {
            fprintf(tempFile3, "%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
            continue;
        }
    }
    fclose(cusFile);
    fclose(tempFile3);
    remove("cus_details.txt");
    rename("temp_cus_details.txt","cus_details.txt");

    if (flag)
    {
        printf("\nName not found!\n");
        fclose(cusFile);
        fclose(tempFile3);
        modify_cus_details(username, cusID);
    }
    printf("\t\t-----------------------------------------------");
    printf("\n\t\tName has been modified successfully\n");
    printf("\t\t-----------------------------------------------\n");
    printf("\nPress any key to continue....");
    scanf(" %c", &a);
    modify_cus_details(username, cusID);
    return;
}


void modify_houseadd(char username[100],char cusID[100]){

    int flag = 1;
    char new_house_address[100], a;
    char file_cusID[100], file_name[100], file_address[100], file_email[100], file_phone_num[100], file_gender[100], file_DOB[100], file_username[100], file_password[100];
    cusFile = fopen("cus_details.txt","r");
    if(cusFile == NULL)
    {
        printf("\nFile can't be opened!\n");
        exit(1);
    }
    printf("\nEnter new house address: ");
    scanf(" %[^\n]%*c", new_house_address);
    for (int i = 0; new_house_address[i] != '\0'; i++)
    {
        if (new_house_address[i] == ' ')
        {
            new_house_address[i] = '_';
        }
    }
    tempFile3 = fopen("temp_cus_details.txt","w");
    while(!feof(cusFile))
    {
        fscanf(cusFile,"%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
        if (strcmp(cusID, file_cusID) == 0)
        {
            flag = 0;
            fprintf(tempFile3, "%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, new_house_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
        }
        else
        {
            fprintf(tempFile3, "%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
            continue;
        }
    }
    fclose(cusFile);
    fclose(tempFile3);
    remove("cus_details.txt");
    rename("temp_cus_details.txt","cus_details.txt");

    if (flag)
    {
        printf("\nHouse address not found!\n");
        fclose(cusFile);
        fclose(tempFile3);
        modify_cus_details(username, cusID);
    }
    printf("\t\t-----------------------------------------------");
    printf("\n\t\tThe house address has been modified successfully\n");
    printf("\t\t-----------------------------------------------\n");
    printf("\nPress any key to continue....");
    scanf(" %c", &a);
    modify_cus_details(username, cusID);
    return;
}


void modify_emailadd(char username[100], char cusID[100]){

    int flag = 1;
    char new_email_address[100], a;
    char file_cusID[100], file_name[100], file_address[100], file_email[100], file_phone_num[100], file_gender[100], file_DOB[100], file_username[100], file_password[100];
    cusFile = fopen("cus_details.txt","r");

    if(cusFile == NULL)
    {
        printf("\nFile can't be opened!\n");
        exit(1);
    }
    while(1)
    {
        printf("\nEnter new email address: ");
        scanf(" %[^\n]%*c", new_email_address);
        for (int i = 0; new_email_address[i] != '\0'; i++)
        {
            if (new_email_address[i] == ' ')
            {
                new_email_address[i] = '_';
            }
        }
        while(!feof(cusFile))
        {
            fscanf(cusFile,"%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
            if (strcmp(new_email_address, file_email) == 0)
            {
                flag = 0;
                printf("\nThe email address has already been used!\n");
                printf("\nPlease insert another email address\n");
                fclose(cusFile);
                modify_emailadd(username, cusID);
                break;
            }
            else
            {
                flag++;
                continue;
            }
        }
        if (flag)
        {
            break;
        }
    }
    tempFile3 = fopen("temp_cus_details.txt","w");
    fseek(cusFile, 0, SEEK_SET);
    while(!feof(cusFile))
    {
        fscanf(cusFile,"%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
        if (strcmp(cusID, file_cusID) == 0)
        {
            flag = 0;
            fprintf(tempFile3, "%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, new_email_address, file_phone_num, file_gender, file_DOB, file_username, file_password);
        }
        else
        {
            fprintf(tempFile3, "%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
            continue;
        }
    }
    fclose(cusFile);
    fclose(tempFile3);
    remove("cus_details.txt");
    rename("temp_cus_details.txt","cus_details.txt");

    if (flag)
    {
        printf("\nEmail address not found!\n");
        fclose(cusFile);
        fclose(tempFile3);
        modify_cus_details(username, cusID);
    }
    printf("\t\t-----------------------------------------------");
    printf("\n\t\tThe email address has been modified successfully\n");
    printf("\t\t-----------------------------------------------\n");
    printf("\nPress any key to continue....");
    scanf(" %c", &a);
    modify_cus_details(username, cusID);
    return;
}


void modify_phonenum(char username[100], char cusID[100]){

    int flag = 1;
    char new_phone_number[100], a;
    char file_cusID[100], file_name[100], file_address[100], file_email[100], file_phone_num[100], file_gender[100], file_DOB[100], file_username[100], file_password[100];
    cusFile = fopen("cus_details.txt","r");
    tempFile3 = fopen("temp_cus_details.txt","w");

    if(cusFile == NULL || tempFile3 == NULL)
    {
        printf("\nFile can't be opened!\n");
        exit(1);
    }
    while(1)
    {
        printf("\nEnter new phone number: ");
        scanf(" %[^\n]%*c", new_phone_number);
        while(!feof(cusFile))
        {
            fscanf(cusFile,"%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
            if (strcmp(new_phone_number, file_phone_num) == 0)
            {
                flag = 0;
                printf("\nThe phone number has already been used!\n");
                printf("\nPlease insert another phone number\n");
                fclose(cusFile);
                fclose(tempFile3);
                modify_phonenum(username, cusID);
                break;
            }
            else
            {
                flag++;
                continue;
            }
        }
        if (flag)
        {
            break;
        }
    }

    fseek(cusFile, 0, SEEK_SET);
    while(!feof(cusFile))
    {
        fscanf(cusFile,"%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
        if (strcmp(cusID, file_cusID) == 0)
        {
            flag = 0;
            fprintf(tempFile3, "%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, new_phone_number, file_gender, file_DOB, file_username, file_password);
        }
        else
        {
            fprintf(tempFile3, "%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
            continue;
        }
    }
    fclose(cusFile);
    fclose(tempFile3);
    remove("cus_details.txt");
    rename("temp_cus_details.txt","cus_details.txt");

    if (flag)
    {
        printf("\nPhone number not found!\n");
        fclose(cusFile);
        fclose(tempFile3);
        modify_cus_details(username, cusID);
    }
    printf("\t\t-----------------------------------------------");
    printf("\n\t\tThe phone number has been modified successfully\n");
    printf("\t\t-----------------------------------------------\n");
    printf("\nPress any key to continue....");
    scanf(" %c", &a);
    modify_cus_details(username, cusID);
    return;
}


void modify_gender(char username[100],char cusID[100]){

    int flag = 1;
    char new_gender[100], a;
    char gender1[10] = "Male";
    char gender2[10] = "Female";
    char file_cusID[100], file_name[100], file_address[100], file_email[100], file_phone_num[100], file_gender[100], file_DOB[100], file_username[100], file_password[100];
    cusFile = fopen("cus_details.txt","r");
    if(cusFile == NULL)
    {
        printf("\nFile can't be opened!\n");
        exit(1);
    }

    while(1)
    {
        printf("\nEnter new gender: ");
        scanf(" %s", new_gender);
        new_gender[0] = toupper(new_gender[0]);
        if (strcmp(new_gender, gender1) == 0 || strcmp(new_gender, gender2) == 0)
        {
            break;
        }
        else
        {
            printf("\nInvalid input! Please insert a valid gender!\n");
            continue;
        }
    }
    tempFile3 = fopen("temp_cus_details.txt","w");
    while(!feof(cusFile))
    {
        fscanf(cusFile,"%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
        if (strcmp(cusID, file_cusID) == 0)
        {
            flag = 0;
            fprintf(tempFile3, "%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, new_gender, file_DOB, file_username, file_password);
        }
        else
        {
            fprintf(tempFile3, "%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
            continue;
        }
    }
    fclose(cusFile);
    fclose(tempFile3);
    remove("cus_details.txt");
    rename("temp_cus_details.txt","cus_details.txt");

    if (flag)
    {
        printf("\nGender not found!\n");
        fclose(cusFile);
        fclose(tempFile3);
        modify_cus_details(username, cusID);
    }
    printf("\t\t-----------------------------------------------");
    printf("\n\t\tGender has been modified successfully\n");
    printf("\t\t-----------------------------------------------\n");
    printf("\nPress any key to continue....");
    scanf(" %c", &a);
    modify_cus_details(username, cusID);
    return;
}


void modify_DOB(char username[100],char cusID[100]){

    int flag = 1;
    char new_DOB[100], a;
    char file_cusID[100], file_name[100], file_address[100], file_email[100], file_phone_num[100], file_gender[100], file_DOB[100], file_username[100], file_password[100];
    cusFile = fopen("cus_details.txt","r");
    if(cusFile == NULL)
    {
        printf("\nFile can't be opened!\n");
        exit(1);
    }
    printf("\nEnter new date of birth (DD/MM/YYYY): ");
    scanf(" %[^\n]%*c", new_DOB);
    tempFile3 = fopen("temp_cus_details.txt","w");
    while(!feof(cusFile))
    {
        fscanf(cusFile,"%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
        if (strcmp(cusID, file_cusID) == 0)
        {
            flag = 0;
            fprintf(tempFile3, "%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, new_DOB, file_username, file_password);
        }
        else
        {
            fprintf(tempFile3, "%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
            continue;
        }
    }
    fclose(cusFile);
    fclose(tempFile3);
    remove("cus_details.txt");
    rename("temp_cus_details.txt","cus_details.txt");

    if (flag)
    {
        printf("\nDate of birth not found!\n");
        fclose(cusFile);
        fclose(tempFile3);
        modify_cus_details(username, cusID);
    }
    printf("\t\t-----------------------------------------------");
    printf("\n\t\tDate of birth has been modified successfully\n");
    printf("\t\t-----------------------------------------------\n");
    printf("\nPress any key to continue....");
    scanf(" %c", &a);
    modify_cus_details(username, cusID);
    return;
}


void modify_password(char username[100], char cusID[100]){

    int flag = 1;
    char new_password[100], a;
    char file_cusID[100], file_name[100], file_address[100], file_email[100], file_phone_num[100], file_gender[100], file_DOB[100], file_username[100], file_password[100];
    cusFile = fopen("cus_details.txt","r");
    tempFile3 = fopen("temp_cus_details.txt","w");

    if(cusFile == NULL || tempFile3 == NULL)
    {
        printf("\nFile can't be opened!\n");
        exit(1);
    }
    while(1)
    {
        printf("\nNo spaces are allowed when creating you new password!\n");
        printf("\nEnter your password that should satisfy the following criteria\n");
        printf("\n\t1. Password should contain atleast one capital letter\n\t2. Should have one digit from(0-9)\n\t3. Atleast one special charecter($,*,#,&,@)\n\t4. Length should be atleast 8\n");
        printf("\nEnter new password: ");
        scanf(" %s", new_password);
        int len,i,flag1=0,flag2=0,flag3=0,flag4=0;
        len=strlen(new_password);
        if(len<8)
        {
            flag1=1;
        }

        else
        {
            for(i=0;i<len;i++)
            if((new_password[i]>=48 && new_password[i]<=58))
            {
                flag2=0;
                break;
            }
            else
            flag2=1;

            for(i=0;i<len;i++)
            if((new_password[i]>=65&& new_password[i]<=90))
            {
                flag3=0;
                break;
            }
            else
            flag3=1;

            for(i=0;i<len;i++)
            if(new_password[i]=='#'|| new_password[i]=='$'|| new_password[i]=='*'|| new_password[i]=='&'|| new_password[i] == '@')
            {
                flag4=0;
                break;
            }
            else
            flag4=1;
        }

        if(flag1==1||flag2==1||flag3==1||flag4==1)
        {
            printf("\nPassword is not strong enough!\n");
            continue;
        }
        else
        {
            break;
        }
    }

    fseek(cusFile, 0, SEEK_SET);
    while(!feof(cusFile))
    {
        fscanf(cusFile,"%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
        if (strcmp(cusID, file_cusID) == 0)
        {
            flag = 0;
            fprintf(tempFile3, "%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, new_password);
        }
        else
        {
            fprintf(tempFile3, "%s %s %s %s %s %s %s %s %s\n", file_cusID, file_name, file_address, file_email, file_phone_num, file_gender, file_DOB, file_username, file_password);
            continue;
        }
    }
    fclose(cusFile);
    fclose(tempFile3);
    remove("cus_details.txt");
    rename("temp_cus_details.txt","cus_details.txt");

    if (flag)
    {
        printf("\nPassword not found!\n");
        fclose(cusFile);
        fclose(tempFile3);
        modify_cus_details(username, cusID);
    }
    printf("\t\t-----------------------------------------------");
    printf("\n\t\tThe password has been modified successfully\n");
    printf("\t\t-----------------------------------------------\n");
    printf("\nPress any key to continue....");
    scanf(" %c", &a);
    modify_cus_details(username, cusID);
    return;
}


void order_menu(char username[100],char cusID[100]){

    int opt = 0;
    while(opt != 3)
    {
        printf("\t\t------------------------------");
        printf("\n\t\t\t    Order\n");
        printf("\t\t------------------------------\n");
        printf("\nDear %s, this is the interface where you can choose to order food and beverages!\n",username);
        printf("\nType '1' to ORDER FOOD or type '2' to ORDER BEVERAGE or type '3' to EXIT\n");
        printf("\n\t1. Order food\n \t2. Order beverages\n \t3. Exit\n");
        printf("\nEnter your choice (1-3): ");
        scanf(" %d", &opt);
        while (getchar() != '\n'){

        }
        switch(opt)
        {
        case 1:
            order_food(username,cusID);
            break;

        case 2:
            order_beverage(username,cusID);
            break;

        case 3:
            customer_menu(username,cusID);
            break;

        default:
            printf("\nInvalid input!\n");
            printf("\nPlease follow the instructions given!\n");
            order_menu(username,cusID);
            break;
        }
        break;
    }
    return;
}


void order_food(char username[100],char cusID[100]){

    char foodID[10], file_ID[6], filefood_name[100], line[255];
    int opt, flag = 1, quantity, orderID = 1;
    double price, filefood_price;
    printf("\nDear %s, below is the food menu of our coffee shop!\n",username);
    printf("\nWe have a variety of choices for you to choose!\n");
    printf("\n");
    food_menu();
    dishFile = fopen("dish_menu.txt","r");
    orderFile = fopen("cus_order.txt","a+");

    if (dishFile == NULL)
    {
        printf("\nFile does not exist!\n");
        exit(1);
    }
    printf("\nEnter the food ID to add into your order!\n");
    printf("\nEnter food ID (eg. F001): ");
    scanf(" %s",foodID);
    foodID[0] = toupper(foodID[0]);

    fseek(dishFile, 0, SEEK_SET);
    while(!feof(dishFile))
    {
        fscanf(dishFile, "%s %s %lf\n", file_ID, filefood_name, &filefood_price);
        if (strcmp(foodID, file_ID) == 0)
        {
            flag = 0;
            for (int i = 0; filefood_name[i] != '\0'; i++)
            {
                if (filefood_name[i] == '_')
                {
                    filefood_name[i] = ' ';
                }
            }
            printf("\n\t\tID   Food name\t\t  Price\n");
            printf("\t\t%-2s %-20s RM%.2f\n",file_ID,filefood_name,filefood_price);
            break;
        }
        else
        {
            flag++;
            continue;
        }
    }

    if (flag)
    {
        printf("\nItem not found or item does not exist in the menu!\n");
        fclose(dishFile);
        fclose(orderFile);
        order_food(username, cusID);
    }

    while(1)
    {
        printf("\nEnter the quantity of %s that you would like to order!\n",filefood_name);
        printf("\nEnter quantity: ");
        scanf(" %d", &quantity);
        while (getchar() != '\n'){

        }
        if (quantity <= 0)
        {
            printf("\Invalid input!\n");
            printf("\nPlease enter a valid quantity!\n");
            continue;
        }
        else
        {
            break;
        }
    }
    while(1)
    {
        printf("\nDo you wish to add %d %s into your order?\n",quantity,filefood_name);
        printf("\nType '1' for YES or type '2' for NO\n");
        printf("\n\t1. Yes\n \t2. No\n");
        printf("\nEnter your choice (1-2): ");
        scanf(" %d",&opt);
        while (getchar() != '\n'){

        }
        if (opt == 1)
        {
            while (fgets(line, 255, orderFile)) orderID++;
            for (int i = 0; filefood_name[i] != '\0'; i++)
            {
                if (filefood_name[i] == ' ')
                {
                    filefood_name[i] = '_';
                }
            }
            printf("\nYour order ID is %03d\n",orderID);
            fprintf(orderFile, "%03d %s %s %s %d %.2lf\n",orderID,cusID,username,filefood_name,quantity,filefood_price);
            break;
        }
        else if (opt == 2)
        {
            fclose(dishFile);
            fclose(orderFile);
            order_food(username,cusID);
            break;

        }
        else
        {
            printf("\nInvalid input!\n");
            printf("\nPlease follow the instructions given!\n");
            continue;
        }
        break;
    }
    do{
        printf("\nType '1' to CONTINUE ORDERING FOOD or type '2' to PAY or type '3' to EXIT.\n");
        printf("\n\t1. Order food\n\t2. Pay\n \t3. Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %d",&opt);
        while (getchar() != '\n'){

        }

        if (opt == 1)
        {
            fclose(dishFile);
            fclose(orderFile);
            order_food(username,cusID);
            break;
        }
        else if (opt == 2)
        {
            fclose(dishFile);
            fclose(orderFile);
            payment(username,cusID);
            break;
        }
        else if (opt < 1 || opt > 3)
        {
            fflush(stdin);
            printf("\nInvalid input!\n");
            printf("\nPlease follow the instructions given!\n");
            continue;
        }
    }while(opt != 3);
    fclose(dishFile);
    fclose(orderFile);
    order_menu(username, cusID);
    return;
}


void order_beverage(char username[100], char cusID[100])
{
    char bvgID[10], file_ID[6], filebvg_name[100], line[255];
    int opt, flag = 1, quantity, orderID = 1;
    double price, filebvg_price;
    printf("\nDear %s, below is the beverage menu of our coffee shop!\n", username);
    printf("\nWe have a variety of choices for you to choose!\n");
    printf("\n");
    bvg_menu();
    bvgFile = fopen("beverage_menu.txt","r");
    orderFile = fopen("cus_order.txt","a+");

    if (bvgFile == NULL)
    {
        printf("\nFile does not exist!\n");
        exit(1);
    }
    printf("\nEnter the beverage ID to add into your order!\n");
    printf("\nEnter beverage ID (eg. B001): ");
    scanf(" %s",bvgID);
    bvgID[0] = toupper(bvgID[0]);

    fseek(bvgFile, 0, SEEK_SET);
    while(!feof(bvgFile))
    {
        fscanf(bvgFile, "%s %s %lf\n", file_ID, filebvg_name, &filebvg_price);
        if (strcmp(bvgID, file_ID) == 0)
        {
            flag = 0;
            for (int i = 0; filebvg_name[i] != '\0'; i++)
            {
                if (filebvg_name[i] == '_')
                {
                    filebvg_name[i] = ' ';
                }
            }
            printf("\n\t\tID   Beverage name\t\t  Price\n");
            printf("\t\t%-2s %-28s RM%.2f\n",file_ID,filebvg_name,filebvg_price);
            break;
        }
        else
        {
            flag++;
            continue;
        }
    }

    if (flag)
    {
        fflush(stdin);
        printf("\nItem not found or item does not exist in the menu!\n");
        fclose(bvgFile);
        fclose(orderFile);
        order_beverage(username, cusID);
    }

    while(1)
    {
        printf("\nEnter the quantity of %s that you would like to order!\n",filebvg_name);
        printf("\nEnter quantity: ");
        scanf(" %d", &quantity);
        while (getchar() != '\n'){

        }
        if (quantity <= 0)
        {
            fflush(stdin);
            printf("\Invalid input!\n");
            printf("\nPlease enter a valid quantity!\n");
            continue;
        }
        else
        {
            break;
        }
    }
    while(1)
    {
        printf("\nDo you wish to add %d %s into your order?\n",quantity,filebvg_name);
        printf("\nType '1' for YES or type '2' for NO\n");
        printf("\n\t1. Yes\n \t2. No\n");
        printf("\nEnter your choice (1-2): ");
        scanf(" %d",&opt);
        while (getchar() != '\n'){

        }
        if (opt == 1)
        {
            while (fgets(line, 255, orderFile)) orderID++;
            for (int i = 0; filebvg_name[i] != '\0'; i++)
            {
                if (filebvg_name[i] == ' ')
                {
                    filebvg_name[i] = '_';
                }
            }
            printf("\nYour order ID is %03d\n",orderID);
            fprintf(orderFile, "%03d %s %s %s %d %.2lf\n",orderID,cusID,username,filebvg_name,quantity,filebvg_price);
            break;
        }
        else if (opt == 2)
        {
            fclose(bvgFile);
            fclose(orderFile);
            order_beverage(username,cusID);
            break;

        }
        else
        {
            fflush(stdin);
            printf("\nInvalid input!\n");
            printf("\nPlease follow the instructions given!\n");
            continue;
        }
        break;
    }
    do{
        printf("\nType '1' to CONTINUE ORDERING BEVERAGE or type '2' to EXIT.\n");
        printf("\n\t1. Order beverage\n\t2. Pay\n \t3. Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %d",&opt);
        while (getchar() != '\n'){

        }

        if (opt == 1)
        {
            fclose(bvgFile);
            fclose(orderFile);
            order_beverage(username,cusID);
            break;
        }
        else if (opt == 2)
        {
            fclose(bvgFile);
            fclose(orderFile);
            payment(username,cusID);
            break;
        }
        else if (opt < 1 || opt > 3)
        {
            fflush(stdin);
            printf("\nInvalid input!\n");
            printf("\nPlease follow the instructions given!\n");
            continue;
        }
    }while(opt != 3);
    fclose(bvgFile);
    fclose(orderFile);
    order_menu(username, cusID);
    return;
}


void payment(char username[100],char cusID[100]){

    int orderID, quantity, flag = 1, find_result = 0, file_orderID;
    double price, sub_total = 0, total = 0, cus_pay, change;
    char fileitem_name[100], filecusID[100], line[255];
    printf("\t\t\t\t\t------------------------------");
    printf("\n\t\t\t\t\t\t    RECEIPT\n");
    printf("\t\t\t\t\t------------------------------\n");
    orderFile = fopen("cus_order.txt","r");
    if (orderFile == NULL)
    {
        printf("\nFile can't be open\n");
        exit(1);
    }

    printf("\n");
    printf("\n\tOrder ID    Customer ID    Username    Item name\t  Quantity    Price\t\tSub total\n");
    printf("\n\t--------------------------------------------------------------------------------------------------\n");
    printf("\n");
    while(!feof(orderFile))
    {
        fscanf(orderFile, "%d %s %s %s %d %lf\n", &orderID, filecusID, username, fileitem_name, &quantity, &price);
        if ((strcmp(cusID, filecusID)) == 0)
        {
            flag = 0;
            for (int i = 0; fileitem_name[i] != '\0'; i++)
            {
                if (fileitem_name[i] == '_')
                {
                    fileitem_name[i] = ' ';
                }
            }
            sub_total = quantity * price;
            total = total + sub_total;
            printf("\n\t%03d \t    %-14s %-11s %-15s       %d        RM %2.2f \t\tRM %2.2f\n", orderID, filecusID, username, fileitem_name, quantity, price, sub_total);
        }
    }
    printf("\n\t--------------------------------------------------------------------------------------------------");
    printf("\n\tTotal:                                                                                  RM %.2f\n",total);
    if (flag)
    {
        printf("\nItem not found or you have not made any orders!\n");
        fclose(orderFile);
        customer_menu(username, cusID);
        return;
    }

    while(1)
    {
        printf("\nEnter the amount that you need to pay\n");
        printf("\nEnter amount: RM ");
        scanf(" %lf",&cus_pay);

        if (cus_pay < total)
        {
            printf("\nInvalid input!\n");
            printf("\nPlease enter a valid amount of money!\n");
            continue;
        }
        else if (cus_pay >= total)
        {
            change = cus_pay - total;
            printf("\nPayment is successful!\n");
            printf("\nDear %s, your change is RM %.2f\n",username, change);
            printf("\nThank you %s, we hope to see you again!\n",username);
            break;
        }
    }
    tempFile2 = fopen("temp_cus_order.txt","w");
    while(!feof(orderFile))
    {
        fscanf(orderFile, "%d %s %s %s %d %lf\n", &orderID, filecusID, username, fileitem_name, &quantity, &price);
        if (strcmp(cusID, filecusID) == 0)
        {
            continue;
        }
        else
        {
            fprintf(tempFile2, "%03d %s %s %s %d %.2f\n", orderID, filecusID, username, fileitem_name, quantity, price);
            break;
        }
    }
    fclose(orderFile);
    fclose(tempFile2);
    remove("cus_order.txt");
    rename("temp_cus_order.txt","cus_order.txt");
    customer_menu(username, cusID);
    return;
}


void view_cancel_order(char username[100], char cusID[100]){

    int orderID, quantity, flag = 1, find_result = 0, opt, choice;
    double price, sub_total = 0, total = 0;
    char fileitem_name[100], filecusID[100], line[255];
    printf(" %s", cusID);
    printf("\t\t\t\t\t------------------------------");
    printf("\n\t\t\t\t\t\t    %s\n",username);
    printf("\t\t\t\t\t------------------------------\n");
    orderFile = fopen("cus_order.txt","r");
    if (orderFile == NULL)
    {
        printf("\nFile can't be open\n");
        exit(1);
    }
    printf("\n");
    printf("\n\tOrder ID    Customer ID    Username    Item name\t  Quantity    Price\t\tSub total\n");
    printf("\n\t--------------------------------------------------------------------------------------------------\n");
    printf("\n");
    while(!feof(orderFile))
    {
        fscanf(orderFile, "%d %s %s %s %d %lf\n", &orderID, filecusID, username, fileitem_name, &quantity, &price);
        if ((strcmp(cusID, filecusID)) == 0)
        {
            flag = 0;
            for (int i = 0; fileitem_name[i] != '\0'; i++)
            {
                if (fileitem_name[i] == '_')
                {
                    fileitem_name[i] = ' ';
                }
            }
            sub_total = quantity * price;
            total = total + sub_total;
            printf("\n\t%03d \t    %-14s %-11s %-15s       %d        RM %2.2f \t\tRM %2.2f\n", orderID, filecusID, username, fileitem_name, quantity, price, sub_total);
        }
    }
    printf("\n\t--------------------------------------------------------------------------------------------------");
    printf("\n\tTotal:                                                                                  RM %.2f\n",total);
    if (flag)
    {
        printf("\nItem not found or you have not made any orders!\n");
        fclose(orderFile);
        customer_menu(username, cusID);
        return;
    }

    while(1)
    {
        printf("\nDear %s, do you want to cancel your order?\n",username);
        printf("\nType '1' for YES or type '2' for NO\n");
        printf("\nEnter your choice: ");
        scanf(" %d",&opt);

        if(opt == 1)
        {
            break;
        }
        else if (opt == 2)
        {
            fclose(orderFile);
            printf("\nRedirecting you back to the customer menu!\n");
            customer_menu(username, cusID);
            return;
        }
        else
        {
            fflush(stdin);
            printf("\nInvalid input!\n");
            printf("\nPlease follow the instructions given!\n");
            continue;
        }
    }
    printf("\nEnter the order ID (e.g. 001): ");
    scanf(" %d", &choice);
    tempFile2 = fopen("temp_cus_order.txt","w");
    fseek(orderFile, 0, SEEK_SET);
    while(!feof(orderFile))
    {
        fscanf(orderFile, "%d %s %s %s %d %lf\n", &orderID, filecusID, username, fileitem_name, &quantity, &price);
        if (orderID == choice)
        {
            continue;
        }
        else
        {
            fprintf(tempFile2, "%03d %s %s %s %d %.2f\n", orderID, filecusID, username, fileitem_name, quantity, price);
            break;
        }
    }
    fclose(orderFile);
    fclose(tempFile2);
    remove("cus_order.txt");
    rename("temp_cus_order.txt","cus_order.txt");
    printf("\nDear %s, your order has been cancelled!\n",username);
    printf("\nRedirecting you back to the customer menu!\n");
    customer_menu(username, cusID);
    return;
}

int main()
{
    main_menu();
    return 0;
}
