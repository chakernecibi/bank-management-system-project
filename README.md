# Bank Account Management System 
by `chaker necibi`

This program is a simple banking system implemented in C. It provides basic functionalities such as depositing money, withdrawing money, transferring money between accounts, viewing account details, and transaction history. It also includes administrative features such as adding, deleting, and viewing accounts

## Features

`User :`
- Deposit Money: Allows users to deposit money into their account.
- Withdraw Money: Allows users to withdraw money from their account.
- Transfer Money: Allows users to transfer money to another user's account.
- Account Details: Displays the details of the user's account.
- Transaction Details: Displays the transaction history of the user's account.
 
`Admin :`

- Add Account (Admin): Allows the admin to add a new user account based on registration requests.
- Delete Account (Admin): Allows the admin to delete a user account.
- Display All Accounts (Admin): Allows the admin to view details of all user accounts.

## Structure

The program uses a `struct` to represent an account. Each account has the following fields:

- `username`: The account username.
- `password`: The account password.
- `firstname`: The account holder's first name.
- `name`: The account holder's last name.
- `id`: The account ID.
- `acc_no`: The account number.
- `amt`: The account balance.
- `detailsFilePath`: The path to the file containing the account details.
- `TransactiondetailsFilePath`: The path to the file containing the account transaction details.
- `reauest_regestrationFilePath`: The path to the file containing the account registration requests.

## Project Structure
The project has the following folder structure:

*   `main.c`: The main source code file containing the implementation of the banking system.
*   `users_details/`: Folder containing users account details files.
*   `users_Transaction_details/`: Folder containing transaction details files for each user.
*   `admin/`: Folder containing admin-related files.
*   `admin/request_registration/`: Folder containing files for user registration requests

## Usage

Compile the program with a C compiler, then run the resulting executable. Follow the prompts to manage accounts.

## Note

This program uses the `conio.h` library, which is not standard C and may not be available on all platforms. You may need to modify the code to use a different method for console input/output if you're not on a platform that supports `conio.h`.
