#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>


#define DETAILS_FOLDER_PATH "users_details"
#define TRANSACTION_DETAILS_FOLDER_PATH "users_Transaction_details"
#define DETAILS_FOLDER_PATH_FOR_ADMIN "admin"
#define REQUEST_REGESTRANTION_FOLDER_PATH "admin/request_regestration"


typedef struct {
    char username[20];
    char password[20];
    char firstname[20];
    char name[20];
    int id;
    int acc_no;
    int amt;
    char detailsFilePath[200];
    char TransactiondetailsFilePath[200];
    char reauest_regestrationFilePath[200];
} Account;

void divider() {
    for (int i = 0; i < 50; i++) {
        printf("-");
    }
}

void depositMoney(Account *account) {
        system("cls");
         char TransactiondetailsFilePath[200];
    sprintf(TransactiondetailsFilePath, "%s/%s_TransactionDetails.txt", TRANSACTION_DETAILS_FOLDER_PATH, account->username);
    FILE *ptr1 = fopen(TransactiondetailsFilePath, "a+");
    FILE *ptr2 = fopen(TransactiondetailsFilePath, "a+");


    fseek(ptr2, 0, SEEK_SET);
    char line[100];
    int current_amt = 0;

    while (fgets(line, sizeof(line), ptr2)) {
        if (strstr(line, "Now balance:") != NULL) {
            sscanf(line, "Now balance: %d", &current_amt);
        }
    }

        account->amt =  current_amt;

    time_t tm;
    int deps_amt;
    time(&tm);

    divider();
    printf("\n");
    printf("     DEPOSITING MONEY     \n");
    divider();
    printf("\nEnter the amount you want to deposit: ");
    scanf("%d", &deps_amt);

    account->amt += deps_amt;


    printf("Money Deposited successfully !!!!   \n");
    printf("\n");
    printf("Now balance: %dDa\n", account->amt);
    printf("\n %d Da had been deposited to your account \n", deps_amt);
    printf("Date/Time of transaction: %s\n", ctime(&tm));


    fprintf(ptr1, "\nfirst name: %s\n", account->firstname);
    fprintf(ptr1, "last name: %s\n", account->name);
    fprintf(ptr1, "Now balance: %dDa\n", account->amt);
    fprintf(ptr1, "\n %d Da had been deposited to your account \n", deps_amt);
    fprintf(ptr1, "Date/Time of transaction: %s\n", ctime(&tm));
    fprintf(ptr1, "-----------------------------------------------------------------\n");
    fclose(ptr1);
    printf("Press any key....\n");
    getch();
}

void withdrawMoney(Account *account) {
    system("cls");
    char TransactiondetailsFilePath[200];
    sprintf(TransactiondetailsFilePath, "%s/%s_TransactionDetails.txt", TRANSACTION_DETAILS_FOLDER_PATH, account->username);
    FILE *ptr1 = fopen(TransactiondetailsFilePath, "a+");
    FILE *ptr2 = fopen(TransactiondetailsFilePath, "a+");


    fseek(ptr2, 0, SEEK_SET);
    char line[100];
    int current_amt = 0;

    while (fgets(line, sizeof(line), ptr2)) {
        if (strstr(line, "Now balance:") != NULL) {
            sscanf(line, "Now balance: %d", &current_amt);
        }
    }

        account->amt =  current_amt;
    
    time_t tm;
    int whith_amt;
    time(&tm);
     divider();
    printf("\n");
    printf("*****WITHDRAWING MONEY*****\n");
    divider();
    printf("\nEnter the amount you want to withdraw: ");
    scanf("%d", &whith_amt);

    if (whith_amt > account->amt) {
        printf("Insufficient balance\n");
    } else {
        account->amt -= whith_amt;
        printf("\nMoney withdrawn successfully !!!    \n");
         printf("\n");
         printf("Current balance: %dDa\n", account->amt);
         printf("\n%dDa had been withdrawn from your account \n", whith_amt);
         printf("Date/Time of transaction: %s\n", ctime(&tm));

        fprintf(ptr1, "\nfirst name: %s\n", account->firstname);
        fprintf(ptr1, "last name: %s\n", account->name);
        fprintf(ptr1, "Now balance: %dDa\n", account->amt);
        fprintf(ptr1, "\n%dDa had been withdrawn from your account \n", whith_amt);
        fprintf(ptr1, "Date/Time of transaction: %s\n", ctime(&tm));
        fprintf(ptr1, "-----------------------------------------------------------------\n");
    }
        fclose(ptr1);
    printf("Press any key....\n");
    getch();
    
}

void transferMoney(Account *account) {
    system("cls");
   char TransactiondetailsFilePath[200];
    sprintf(TransactiondetailsFilePath, "%s/%s_TransactionDetails.txt", TRANSACTION_DETAILS_FOLDER_PATH, account->username);
    FILE *ptr1 = fopen(TransactiondetailsFilePath, "a+");
    FILE *ptr2 = fopen(TransactiondetailsFilePath, "a+");


    fseek(ptr2, 0, SEEK_SET);
    char line[100];
    int current_amt = 0;

    while (fgets(line, sizeof(line), ptr2)) {
        if (strstr(line, "Now balance:") != NULL) {
            sscanf(line, "Now balance: %d", &current_amt);
        }
    }

        account->amt =  current_amt;

    int tran_amt;
    char reciver_username[20];
    time_t tm;
    time(&tm);
     divider();
    printf("\n");
    printf("     TRANSFERRING MONEY     \n");
    divider();
    printf("\nEnter the username(first name_account number) which you want to transfer the money to: ");
    scanf("%s", &reciver_username);
    printf("\nEnter the amount you want to transfer: ");
    scanf("%d", &tran_amt);

    if (tran_amt > account->amt) {
        printf("Sorry !!!! You do not have sufficient balance.");
    } else {
        account->amt -= tran_amt;
        divider();
        printf("\n");
        printf("\n      Money Transferred     \n");
        divider();
        printf("\n");
        printf("Current balance: %d\n", account->amt);
        printf("\n%d Da had been transferred from your account to %s\n", tran_amt, reciver_username);
        printf("Date/Time of transaction: %s\n", ctime(&tm));



        fprintf(ptr1, "name: %s\n", account->username);
        fprintf(ptr1, "last name: %s\n", account->name);
        fprintf(ptr1, "Now balance: %dDa\n", account->amt);
        fprintf(ptr1, "\n%d Da had been transferred from your account to %s\n", tran_amt, reciver_username);
        fprintf(ptr1, "Date/Time of transaction: %s\n", ctime(&tm));
        fprintf(ptr1, "-----------------------------------------------------------------\n");
          
          char reciv_TransactiondetailsFilePath[200];

        sprintf(reciv_TransactiondetailsFilePath, "%s/%s_TransactionDetails.txt", TRANSACTION_DETAILS_FOLDER_PATH, reciver_username);
        FILE *ptr3 = fopen(reciv_TransactiondetailsFilePath, "a+");
        int reciv_current_amt;

        while (fgets(line, sizeof(line), ptr3)) {
        if (strstr(line, "Now balance:") != NULL) {
            
            sscanf(line, "Now balance: %d", &reciv_current_amt);
        }
    }

    int reciv_now_amt = reciv_current_amt + tran_amt;
        fprintf(ptr3, "\nNow balance: %dDa\n", reciv_now_amt);

        fprintf(ptr3, "\n%d Da had been transferred from %s to your account.\n", tran_amt, account->username);
        fprintf(ptr3, "Date/Time of transaction: %s\n", ctime(&tm));
        fprintf(ptr3, "-----------------------------------------------------------------\n");

            fclose(ptr3);

    }


        fclose(ptr1);
        

    printf("Press any key....\n");
    getch();
}

void displayAccountDetails(Account *account) {
    system("cls");
    char displaydetails[200];
    sprintf(displaydetails, "%s/%s_Details.txt", DETAILS_FOLDER_PATH, account->username);
    FILE *ptr2 = fopen(displaydetails, "a+");
;
    if (ptr2 == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    char c;
    while ((c = fgetc(ptr2)) != EOF) {
        printf("%c", c);
    }

    fclose(ptr2);
    printf("\n\nPress any key to exit.....");
        getch();
}

void displayTransactionDetails(Account *account) {
    system("cls");
    sprintf(account->TransactiondetailsFilePath, "%s/%s_TransactionDetails.txt", TRANSACTION_DETAILS_FOLDER_PATH, account->username);
    FILE *ptr1 = fopen(account->TransactiondetailsFilePath, "a+");
    if (ptr1 == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    char c = fgetc(ptr1);
    if (c == EOF) {
         divider();
    printf("\n");
        printf("TRANSACTION DETAILS\n");
        divider();
        printf("\n*******NO RECENT TRANSACTION*******\n");
    } else {
        divider();
        printf("\n        TRANSACTION DETAILS      \n");
        divider();
        printf("\n");
        while (c != EOF) {
            printf("%c", c);
            c = fgetc(ptr1);
        }
    }
    printf("Press any key....\n");
    getch();
    fclose(ptr1);
}

void displayLastDetails(Account *account) {
    system("cls");
    char TransactiondetailsFilePath[200];
    sprintf(TransactiondetailsFilePath, "%s/%s_TransactionDetails.txt", TRANSACTION_DETAILS_FOLDER_PATH, account->username);
    FILE *ptr2 = fopen(TransactiondetailsFilePath, "a+");


                 fseek(ptr2, 0, SEEK_SET);
                  char line[100];
                  int curent_amount;
   
                  while (fgets(line, sizeof(line), ptr2)) {
                      if (strstr(line, "Now balance:") != NULL) {
            
                     sscanf(line, "Now balance: %d", &curent_amount);
                  }
                  }

                  
    printf("ACCOUNT DETAILS\n");
    divider();
    printf("\nusername: %s\n", account->username);
    printf("Total balance: %d\n", curent_amount);
    fclose(ptr2);
    printf("\n\nPress any key to exit.....");
    getch();
}

int generateRandom() {
    srand(time(NULL));
    return rand() % 900000 + 100000;
}

int getID() {
    char Accounts[200];
     sprintf(Accounts, "%s/Accounts.txt", DETAILS_FOLDER_PATH_FOR_ADMIN);
   FILE *ptr = fopen(Accounts, "r");

    if (ptr == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    fseek(ptr, 0, SEEK_SET);
    char line[100];
    int maxID = -1;

    while (fgets(line, sizeof(line), ptr)) {
        if (strstr(line, "ID:") != NULL) {
            int currentID;
            sscanf(line, "ID: %d", &currentID);
            if (currentID > maxID) {
                maxID = currentID;
            }
        }
    }

    fclose(ptr);
    return maxID + 1;
}



int registerAccount(char first_Name[20] , char Last_Name[20] , char Pass[25]) {
    system("cls");
    Account account;
     char Accounts[200];
     sprintf(Accounts, "%s/Accounts.txt", DETAILS_FOLDER_PATH_FOR_ADMIN);
    FILE *acc_ptr = fopen(Accounts, "a+");

    if (acc_ptr == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

char firstname[20];
char name[20];
char password[25];

strcpy(firstname, first_Name);
strcpy(name, Last_Name);
strcpy(password, Pass);

    int id = getID();
    int acc_no = generateRandom();
    int amt = 0;
    char username[20];
    sprintf(username, "%s_%d", firstname, acc_no);

          char detailsFilePath[200];
        sprintf(detailsFilePath, "%s/%s_Details.txt", DETAILS_FOLDER_PATH, username);
        
        FILE *detailsFile = fopen(detailsFilePath, "w");

       

    if (detailsFile == NULL) {
        printf("Error creating the details file.\n");
        exit(1);
    }

    char TransactiondetailsFilePath[200];

        sprintf(TransactiondetailsFilePath, "%s/%s_TransactionDetails.txt", TRANSACTION_DETAILS_FOLDER_PATH,username);

        FILE *TransactionDetailsfile = fopen(TransactiondetailsFilePath, "w");

    if (TransactionDetailsfile == NULL) {
        printf("Error creating the details file.\n");
        exit(1);
    }

    

    fprintf(acc_ptr, "\nUsername: %s\n", username);
    fprintf(acc_ptr, "first Name: %s\n", firstname);
    fprintf(acc_ptr, "Last Name: %s\n", name);
    fprintf(acc_ptr, "Account No.: %d\n", acc_no);
    fprintf(acc_ptr, "ID: %d\n", id);
    fprintf(acc_ptr, "-----------------------------------------------------------------\n");

    

   

    fprintf(detailsFile, "Username: %s\n",username);
    fprintf(detailsFile, "Password: %s\n",password);
    fprintf(detailsFile, "Account No.: %d\n",acc_no);
    fprintf(detailsFile, "first name: %s\n",firstname);
    fprintf(detailsFile, "last name: %s\n",name);
    fprintf(detailsFile, "-----------------------------------------------------------------\n");

        fprintf(TransactionDetailsfile, "user name: %s\n",username);
        fprintf(TransactionDetailsfile, "first name: %s\n", firstname);
        fprintf(TransactionDetailsfile, "last name: %s\n", name);
        fprintf(TransactionDetailsfile, "Now balance: %dDa\n", amt);
        fprintf(TransactionDetailsfile, "-----------------------------------------------------------------\n");


    
    fclose(TransactionDetailsfile);
    fclose(detailsFile);
    fclose(acc_ptr);

     printf("\nThe account has been created successfully.\n");

    printf("\n\nPress any key to exit.....");
        getch();
        adminInterface();

}

int request_regestration(Account *account) {

    char firstname[20];
    char name[20];
    char password[25];

   system("cls");
   printf("Enter your first name: ");
    scanf("%s", firstname);
    printf("Enter your last name: ");
    scanf("%s", name);
    printf("Enter a password: ");
    scanf("%s", password);


    char reauest_regestrationFilePath[200];
    sprintf(reauest_regestrationFilePath, "%s/request_regestration.txt", REQUEST_REGESTRANTION_FOLDER_PATH);

     FILE *request_regestration = fopen(reauest_regestrationFilePath, "a+");

    fprintf(request_regestration, "\nfirst Name: %s\n", firstname);
    fprintf(request_regestration, "Last Name: %s\n", name);
    fprintf(request_regestration, "Password: %s\n", password);
    fprintf(request_regestration, "-----------------------------------------------------------------\n");

    
     fclose(request_regestration);

     printf("\nYour regestration request is done wait until admin accept it.\n");

    printf("\n\nPress any key to exit.....");

        getch();

    
}

int addAccount(){
    start:
    system("cls");
    char temp[200];
    char Accounts[200];
    sprintf(temp, "%s/temp.txt", REQUEST_REGESTRANTION_FOLDER_PATH);
    sprintf(Accounts, "%s/request_regestration.txt", REQUEST_REGESTRANTION_FOLDER_PATH);

    FILE *ptr = fopen(Accounts, "r");
    if (ptr == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }


    FILE *tempFile = fopen(temp, "w");
    if (tempFile == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    displayAllRequastes();

    printf("\nEnter the request name that you want to add: ");
    char username[20];
    scanf("%s", username);

    fseek(ptr, 0, SEEK_SET);
    char line[100];
    int found = 0;
    char l_name[20];
    char pass[25];

    while (fgets(line, sizeof(line), ptr)) {
        if (strstr(line, "first Name:") != NULL && strstr(line + 10, username) != NULL) {
            int choice;
            printf("\n whould you want to add this account %s press (1/0) : ",username);
            scanf("%d", &choice);
            if( choice == 1){
                found = 1;
            sscanf(line, "first Name: %s", &username);
            fgets(line, sizeof(line), ptr);
            sscanf(line, "Last Name: %s", &l_name);
            fgets(line, sizeof(line), ptr);
            sscanf(line, "Password: %s", &pass);
            fgets(line, sizeof(line), ptr);


            }
            else {
                printf("\n\nPress any key to exit.....");
                  getch();
            }
            
        } else {
            fputs(line, tempFile);
        }
    }

      fclose(ptr);
      fclose(tempFile);
    
    if (!found) {
        remove(temp);  
        printf("Username %s not found.\n", username);
        printf("\n\nPress any key to try again.....");
                  getch();
                  goto start;
    } else {
        
        remove(Accounts);
        rename(temp, Accounts);
        registerAccount(username,l_name,pass);

    }


   
}


int login(Account *account) {
    start:
    system("cls");
    int choice;
    divider();
    printf("\n                 LOGIN/REGISTER:\n");
    divider();
    printf("\nChoose your choice:\n ");
    printf("\n");
    printf("1. LOGIN\n2. REGISTER\n3. GO BACK\n4. EXIT\n");
    divider();
    printf("\n");
    scanf("%d", &choice);

    
    if (choice == 1) {
        system("cls");
    

    printf("Enter your username: ");
    scanf("%s", account->username);

    sprintf(account->detailsFilePath, "%s/%s_Details.txt", DETAILS_FOLDER_PATH, account->username);
    FILE *acc_dt_ptr = fopen(account->detailsFilePath , "a+");
    if (acc_dt_ptr == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }


    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), acc_dt_ptr)) {
        if (strstr(line, account->username) != NULL) {
            found = 1;
            printf("Enter your password: ");
            scanf("%s", account->password);
            fgets(line, sizeof(line), acc_dt_ptr); 
            if (strstr(line, account->password) != NULL) {
                fgets(line, sizeof(line), acc_dt_ptr); 
                sscanf(line, "Account no.: %d", &account->acc_no);
                fgets(line, sizeof(line), acc_dt_ptr); 
                sscanf(line, "first name: %s", &account->firstname);
                fgets(line, sizeof(line), acc_dt_ptr); 
                sscanf(line, "last name: %s", &account->name);

                fclose(acc_dt_ptr);
                return 0; // Login successful

            } else {
                printf("Incorrect password.\n");
                fclose(acc_dt_ptr);
                return 1; 
            }
        }
    }

    fclose(acc_dt_ptr);

    if (!found) {
        remove(acc_dt_ptr);
        printf("Username not found. Do you want to register a new account? (1/0): ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            request_regestration(account);
        } else {
            return 1;
        }
    }

    return 1; 

    } else if (choice == 2) {
         request_regestration(account);
         return 2;
    } 
    
    else if (choice == 3) {
        return 2; 
    } 

    else if (choice == 4) {

        printf("\n\nPress any key to exit.....");
        getch();
        exit(0);

    } 
    
    else {

        printf("*****Invalid choice*****\n");
        goto start;

    }


}



int userInterface(Account *account) {
    etiq1:
    int choice;
    if (login(account) == 0) {
        printf("Login successful!\n");
    }
    else if (login(account) == 2){
        return 2; 
    }
     else {
        printf("Login failed..\n");

        printf("\n\nPress any key to exit.....");
                getch();
                 goto etiq1;
    }

    while (1) {
        system("cls");
        divider();
         printf("\n\tMENU\n");
         divider();
         printf("\n1. Deposit Money\n");
         printf("2. Withdraw Money\n");
         printf("3. Transfer Money\n");
         printf("4. Account details\n");
         printf("5. Transaction details\n");
         printf("6. Lougout\n");
         printf("7. Exit\n");
         divider();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                depositMoney(account);
                break;
            case 2:
                withdrawMoney(account);
                break;
            case 3:
                transferMoney(account);
                break;
            case 4:
                displayAccountDetails(account);
                break;
            case 5:
                displayTransactionDetails(account);
                break;
            case 6:
                printf("\n\nPress any key to exit.....");
                getch();
                 goto etiq1;
            case 7:
                displayLastDetails(account);
                exit(0);
            default:
                printf("*****Invalid choice*****");
        }
    }

}

void deleteAccount() {
    system("cls");
    char temp[200];
    char Accounts[200];
    sprintf(temp, "%s/temp.txt", DETAILS_FOLDER_PATH_FOR_ADMIN);
    sprintf(Accounts, "%s/Accounts.txt", DETAILS_FOLDER_PATH_FOR_ADMIN);

    FILE *tempFile = fopen(temp, "w");
    FILE *ptr = fopen(Accounts, "r");

    if (ptr == NULL || tempFile == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    printf("Enter the username to delete: ");
    char username[20];
    scanf("%s", username);

    char TransactiondetailsFilePath[200];
    sprintf(TransactiondetailsFilePath, "%s/%s_TransactionDetails.txt", TRANSACTION_DETAILS_FOLDER_PATH, username);
    char detailsFilePath[200];
    sprintf(detailsFilePath, "%s/%s_Details.txt", DETAILS_FOLDER_PATH, username);
    fseek(ptr, 0, SEEK_SET);
    char line[100];
    int found = 0;

    while (fgets(line, sizeof(line), ptr)) {
        if (strstr(line, "Username:") != NULL && strstr(line + 10, username) != NULL) {
            int choice;
            printf("\n whould you want to delete this account %s press (1/0) : ",username);
            scanf("%d", &choice);
            if( choice == 1){
                found = 1;
            fprintf(tempFile, "-----Account Deleted-----\n");
            fgets(line, sizeof(line), ptr);
            fgets(line, sizeof(line), ptr);
            fgets(line, sizeof(line), ptr);
            }
            else {
                printf("\n\nPress any key to exit.....");
                  getch();
            }
            
        } else {
            fputs(line, tempFile);
        }
    }

      fclose(ptr);
      fclose(tempFile);
    
    if (!found) {
        remove(temp);  
        printf("Username %s not found.\n", username);
    } else {
        remove(TransactiondetailsFilePath);
        remove(detailsFilePath);
        remove(Accounts);
        rename(temp, Accounts);
        printf("Account with Username %s deleted successfully.\n", username);
        printf("\n\nPress any key to exit.....");
        getch();
    }

   

}


void displayAllAccounts() {
    system("cls");
     char Accounts[200];
     sprintf(Accounts, "%s/Accounts.txt", DETAILS_FOLDER_PATH_FOR_ADMIN);
    FILE *ptr = fopen(Accounts, "r");
    if (ptr == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    char c;
    while ((c = fgetc(ptr)) != EOF) {
        printf("%c", c);
    }

    fclose(ptr);
    printf("\n\nPress any key to exit.....");
        getch();
}

void displayAllRequastes() {
    system("cls");
     char requests[200];
     sprintf(requests, "%s/request_regestration.txt", REQUEST_REGESTRANTION_FOLDER_PATH);
    FILE *ptr = fopen(requests, "r");
    if (ptr == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    char c;
    while ((c = fgetc(ptr)) != EOF) {
        printf("%c", c);
    }

    fclose(ptr);
    printf("\n\nPress any key to continue.....");
        getch();
}

int authenticateAdmin() {


    char enteredUsername[20];
    char enteredPassword[20];

    printf("Enter your username: ");
    scanf("%s", enteredUsername);

    printf("Enter your password: ");
    scanf("%s", enteredPassword);

    char ADMIN_CREDENTIALS_FILE[200];
    sprintf(ADMIN_CREDENTIALS_FILE, "%s/Admin.txt", DETAILS_FOLDER_PATH_FOR_ADMIN);

    FILE *adminCredentialsFile = fopen(ADMIN_CREDENTIALS_FILE, "r");

    if (adminCredentialsFile == NULL) {
        perror("Error opening admin credentials file");
        exit(1);
    }

    char storedUsername[20];
    char storedPassword[20];

    fscanf(adminCredentialsFile, "Username: %s\n", storedUsername);
    fscanf(adminCredentialsFile, "Password: %s\n", storedPassword);

    fclose(adminCredentialsFile);

    if (strcmp(enteredUsername, storedUsername) == 0 && strcmp(enteredPassword, storedPassword) == 0) {
        printf("Authentication successful!\n");
        return 1;  
    } else {
        printf("Authentication failed!\n");
        return 0;  
    }
}

int adminInterface() {
    start:
    system("cls");
    Account account;
    int adminChoice;
    if(authenticateAdmin() == 1){

    
    do {
        system("cls");
        divider();
        printf("\nADMIN MENU:\n");
        divider();
        printf("\nChoose your choice:\n ");
        printf("\n");
        printf("1. Display all accounts\n");
        printf("2. Delete an account\n");
        printf("3. Add an account\n");
        printf("4. Logging out\n");   
        printf("5. Exit\n");             
        divider();
        printf("\nEnter your choice: ");
        scanf("%d", &adminChoice);

        switch (adminChoice) {
            case 1:
                displayAllAccounts();
                break;
            case 2:
                deleteAccount();
                break;
            case 3:
                addAccount(account);
                break;
            case 4:
                printf("Logging out...\n");
                return 1;
                break;
            case 5:
            printf("\n\nPress any key to exit.....");
              getch();
            default:
                printf("Invalid choice. Try again.\n");

        }
    } while (adminChoice != 3);

    }
    else{
        printf("Authentication failed. Exiting...\n");
        printf("\n\nPress any key to try again.....");
        getch();
        goto start;
    }

    return 0;
}

int main() {
    start:
    system("cls");
    Account account;
    int choice;

    divider();
    printf("\n                 Login Interface:\n");
    divider();
    printf("\nChoose your choice:\n ");
    printf("\n");
    printf("1. Admin \n2. User\n3. EXIT\n");
    divider();
    printf("\nEnter your choice: ");
    scanf("\n%d", &choice);

    

    if (choice == 1) {
        if(adminInterface() == 1){
            goto start;
        }
    }
     else if (choice == 2) {
        if ( userInterface(&account) == 2){
           goto start;
    } 
    }
    else if (choice == 3) {
        printf("\n\nPress any key to exit.....");
        getch();
    } 
    else {
        printf("*****Invalid choice*****\n");

        printf("\n\nPress any key to reaturn.....");
        goto start;
    }


    return 0;
}