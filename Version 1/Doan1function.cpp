#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "Doan1header.h"

/* 1a. Function aim: Displays the list of readers along with their information.
Parameters:
 - readers: a 2D array representing the list of readers, where each row contains information of a reader. It is expected to have dimensions [100][9][50] -> 100 rows where each row contains 9 fields of maximum length 50 characters.
 - *readers: pass by reference*/
void viewReaderList(char (*readers)[9][50], int size)
{
    //The reader's information needed to manage:
    char newReader[9][50] = { "Reader code", "Full name", "ID number", "Date of birth", "Gender", "Email", "Address", "Creation date (dd-mm-yyyy)", "Expiry date (dd-mm-yyyy)" };
    // Go over the reader list array to list all the actual readers
    for (int i = 0; i < size; i++)
    {
        if (readers[i][0][0] != '\0') // find rows that have inputs in reader code column
        {
            printf("Reader %d:\n", i+1); // Print the reader's index
            for (int j = 0; j < 9; j++) //Go over the fields/columns to list the reader with his/her information in turn
            {
                printf("%s: %s\n", newReader[j], readers[i][j]);
            }
        }
    }
    printf("Print successfully!\n");
}

/* 1b. Function aim: Adds a new reader to the list of readers.
Parameters: similar to 1a.*/
void addReader(char (*readers)[9][50], int size)
{
    char newReader[9][50] = { "Reader code", "Full name", "ID number", "Date of birth", "Gender", "Email", "Address", "Creation date (dd-mm-yyyy)", "Expiry date (dd-mm-yyyy)" };
    for (int i = 0; i < size; i++)
    {
        if (readers[i][0][0] == '\0') // Find empty slot in reader list array to add new reader
        {
            for (int j = 0; j < 9; j++) // Go over 9 columns to fill in the new reader's information
            {
                printf("Enter %s: ", newReader[j]); // Input information
                fgets(newReader[j], 50, stdin); // Read input from the user
                newReader[j][strlen(newReader[j]) - 1] = '\0'; //Remove the newline character ('\n')
                // Copy the input to the corresponding field in the reader list array
                strcpy_s(readers[i][j], newReader[j]);
            }
            break;
        }
    }
}

/* 1c. Function aim: Modify a reader in the list of readers, define reader to modify by Reader code. Keep the reader code.
Parameters: similar to 1a.*/
void modifyReader(char (*readers)[9][50], int size) 
{
    char newReader[9][50] = { "Reader code", "Full name", "ID number", "Date of birth", "Gender", "Email", "Address", "Creation date (dd-mm-yyyy)", "Expiry date (dd-mm-yyyy)" };
    // Reader defined by Reader code
    char readerCode[20];
    printf("Enter reader code of reader to modify: ");
    fgets(readerCode, 20, stdin);
    readerCode[strlen(readerCode) - 1] = '\0'; //Remove the newline character ('\n') from the string readerCode by replacing it with the null terminator ('\0')

    bool found = false;
    for (int i = 0; i < size; i++) 
    {
        if (strcmp(readers[i][0], readerCode) == 0) // Define the row to modify, which has similar Reader code to the input
        {
            strcpy_s(readers[i][0], readers[i][0]); // Keep original Reader code
            // Function to choose which information items to modify
            int j = -1;
            while( j != 0)
            {
                printf("What are reader's information items to modify? Not anymore - Enter 0; \nFull name - Enter 1; \nID number - Enter 2; \nDate of birth - Enter 3; \nGender - Enter 4; \nEmail - Enter 5; \nAddress - Enter 6; \nCreation date (dd-mm-yyyy) - Enter 7; \nExpiry date (dd-mm-yyyy) - Enter 8\n");
                printf("Enter your choice: ");
                scanf_s("%d", &j);
                if(j == 0)
                    break;   
                getchar();

                // Enter and save the new information
                printf("Enter new %s: ", newReader[j]);
                fgets(newReader[j], 50, stdin);
                newReader[j][strlen(newReader[j]) - 1] = '\0';

                strcpy_s(readers[i][j], newReader[j]);

                printf("Updated!");
                getchar();
            }
            found = true;
            break;
        }
    }
    if (!found)
        printf("Reader with ID number %s not found.\n", readerCode);
}

/* 1d. Function aim: Delete a reader in the list of readers, define reader to delete by ID number.
Parameters: similar to 1a.*/
void deleteReader(char(*readers)[9][50], int size)
{
    // Reader defined by ID number
    char idNumber[20];
    printf("Enter ID number of reader to delete: ");
    fgets(idNumber, 20, stdin);
    idNumber[strlen(idNumber) - 1] = '\0';

    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(readers[i][2], idNumber) == 0) // Define the reader to delete, which has similar idNumber to the input
        {
            // Delete the reader by shifting all the subsequent entries to -1 position 
            for (int j = i; j < size - 1; j++)
            {
                for (int k = 0; k < 9; k++)
                    strcpy_s(readers[j][k], readers[j + 1][k]);
            }
            // Clear the last reader's entries by replacing them with the null terminator ('\0')
            for (int k = 0; k < 9; k++)
                readers[size - 1][k][0] = '\0';
            printf("Reader with ID number %s deleted successfully.\n", idNumber);
            found = true;
            break;
        }
    }
    if (!found)
        printf("Reader with ID number %s not found.\n", idNumber);
    // view Book list after deletion
    viewReaderList(readers, size);
}

/* 1e. Function aim: search Reader by ID number.
Parameters: similar to 1a.*/
void searchReaderById(char (*readers)[9][50], int size)
{
    char newReader[9][50] = { "Reader code", "Full name", "ID number", "Date of birth", "Gender", "Email", "Address", "Creation date (dd-mm-yyyy)", "Expiry date (dd-mm-yyyy)" };
    // Reader defined by ID number
    char idNumber[20];
    printf("Enter ID number to search: ");
    fgets(idNumber, 20, stdin);
    idNumber[strlen(idNumber) - 1] = '\0';

    int found = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(readers[i][2], idNumber) == 0) // Define the reader to list, which has similar idNumber to the input
        {
            printf("Reader found has the following information:\n");
            for (int j = 0; j < 9; j++) 
            {
                printf("%s: %s\n", newReader[j], readers[i][j]);
            }
            found = true;
            break;
        }
    }
    if (!found)
        printf("Reader with ID number %s not found.\n", idNumber);
}

/* 1f. Function aim: search Reader by Full name.
Parameters: similar to 1a.*/
void searchReaderByName(char (*readers)[9][50], int size)
{
    char newReader[9][50] = { "Reader code", "Full name", "ID number", "Date of birth", "Gender", "Email", "Address", "Creation date (dd-mm-yyyy)", "Expiry date (dd-mm-yyyy)" };
    // (Reader defined by Full name)
    char fullName[30];
    printf("Enter full name to search: ");
    fgets(fullName, 30, stdin);
    fullName[strlen(fullName) - 1] = '\0';

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(readers[i][1], fullName) == 0) // Define the reader to list, which has similar fullName to the input
        {
            printf("Reader found has the following information:\n");
            for (int j = 0; j < 9; j++) {
                printf("%s: %s\n", newReader[j], readers[i][j]);
            }
            found = true;
            break;
        }
    }
    if (!found)
        printf("Reader with full name %s not found.\n", fullName);
}

// 2a. view Book List
void viewBookList(char(*books)[8][50], int size)
{
    char newBook[8][50] = { "ISBN (book code)", "Book name", "Author", "Publisher", "Publication year", "Genre", "Self no.", "No.of copies" };
    for (int i = 0; i < size; i++)
    {
        if (books[i][0][0] != '\0')
        {
            printf("Reader %d:\n", i+1);
            for (int j = 0; j < 8; j++)
            {
                printf("%s: %s\n", newBook[j], books[i][j]);
            }
        }
    }
    printf("Print successfully!\n");
}

// 2b. add Book
void addBook(char(*books)[8][50], int size)
{
    char newBook[8][50] = { "ISBN (book code)", "Book name", "Author", "Publisher", "Publication year", "Genre", "Self no.", "No.of copies" };
    for (int i = 0; i < size; i++)
    {
        if (books[i][0][0] == '\0') // Find empty slot in book array to add new book
        {
            for (int j = 0; j < 8; j++)
            {
                printf("Enter %s: ", newBook[j]);
                fgets(newBook[j], 50, stdin);
                newBook[j][strlen(newBook[j]) - 1] = '\0';

                strcpy_s(books[i][j], newBook[j]);
            }
            break;
        }
    }
}

// 2c. modify Book
void modifyBook(char(*books)[8][50], int size)
{
    char newBook[8][50] = { "ISBN (book code)", "Book name", "Author", "Publisher", "Publication year", "Genre", "Self no.", "No.of copies" };
    // (Book defined by ISBN)
    char ISBN[20];
    printf("Enter ISBN of the book to modify: ");
    fgets(ISBN, 20, stdin);
    ISBN[strlen(ISBN) - 1] = '\0'; //remove the newline character ('\n') from the string ISBN by replacing it with the null terminator ('\0')

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(books[i][0], ISBN) == 0)
        {
            strcpy_s(books[i][0], books[i][0]); // Keep original ISBN
            int j = -1;
            while (j != 0)
            {
                printf("What are book's information items to modify? Not anymore - Enter 0; \nBook name - Enter 1; \nAuthor - Enter 2; \nPublisher - Enter 3; \nPublication year - Enter 4; \nGenre - Enter 5; \nSelf no. - Enter 6; \nNo.of copies - Enter 7\n");
                printf("Enter your choice: ");
                scanf_s("%d", &j);
                if (j == 0)
                    break;
                getchar();

                printf("Enter new %s: ", newBook[j]);
                fgets(newBook[j], 50, stdin);
                newBook[j][strlen(newBook[j]) - 1] = '\0';
                
                strcpy_s(books[i][j], newBook[j]);
                
                printf("Updated!");
                getchar();
            }
            found = true;
            break;
        }
    }
    if (!found)
        printf("Book with ISBN %s not found.\n", ISBN);
}

// 2d. delete Book 
void deleteBook(char(*books)[8][50], int size)
{
    // (Book defined by ISBN)
    char ISBN[20];
    printf("Enter ISBN of the book to delete: ");
    fgets(ISBN, 20, stdin);
    ISBN[strlen(ISBN) - 1] = '\0'; //remove the newline character ('\n') from the string ISBN by replacing it with the null terminator ('\0')

    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(books[i][0], ISBN) == 0)
        {
            // Found the book with the given ISBN, delete it by shifting all the subsequent entries to -1 position 
            for (int j = i; j < size - 1; j++)
            {
                for (int k = 0; k < 8; k++)
                    strcpy_s(books[j][k], books[j + 1][k]);
            }
            // Clear the last book's entries by replacing it with the null terminator ('\0')
            for (int k = 0; k < 8; k++)
                books[size - 1][k][0] = '\0';
            printf("Book with ISBN %s deleted successfully.\n", ISBN);
            found = true;
            break;
        }
    }
    if (!found)
        printf("Book with ISBN %s not found.\n", ISBN);
    // view Book list after deletion
    viewBookList(books, size);
}

// 2e. search Book by ISBN
void searchBookByISBN(char(*books)[8][50], int size)
{
    char newBook[8][50] = { "ISBN (book code)", "Book name", "Author", "Publisher", "Publication year", "Genre", "Self no.", "No.of copies" };
    // (Book defined by ISBN)
    char ISBN[20];
    printf("Enter ISBN to search: ");
    fgets(ISBN, 20, stdin);
    ISBN[strlen(ISBN) - 1] = '\0';

    int found = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(books[i][0], ISBN) == 0)
        {
            printf("Book found has the following information:\n");
            for (int j = 0; j < 8; j++)
            {
                printf("%s: %s\n", newBook[j], books[i][j]);
            }
            found = true;
            break;
        }
    }
    if (!found)
        printf("Book with ISBN %s not found.\n", ISBN);
}

// 2f. search Book by Name
void searchBookByName(char(*books)[8][50], int size)
{
    char newBook[8][50] = { "ISBN (book code)", "Book name", "Author", "Publisher", "Publication year", "Genre", "Self no.", "No.of copies" };
    // (Book defined by ISBN)
    char Name[30];
    printf("Enter full name to search: ");
    fgets(Name, 30, stdin);
    Name[strlen(Name) - 1] = '\0';

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(books[i][1], Name) == 0) {
            printf("Book found has the following information : \n");
            for (int j = 0; j < 8; j++) {
                printf("%s: %s\n", newBook[j], books[i][j]);
            }
            found = true;
            break;
        }
    }
    if (!found)
        printf("Book with ISBN %s not found.\n", Name);
}

// 3. create Book Borrow Form
void createBorrowForm(char(*borrowform)[14][50], int size, char(*listISBN)[2][50])
{
    char newBorrow[3][50] = { "Reader Code", "Borrow date (dd-mm-yyyy)", "Expected return date (dd-mm-yyyy)" };
    int nBooks = 0;
    for (int i = 0; i < size; i++)
    {
        if (borrowform[i][0][0] == '\0') // Find empty slot in borrowform array and add new return
        {
            printf("Enter the number of books to borrow: \n");
            scanf_s("%d", &nBooks);
            if (nBooks < 1 || nBooks > 10) // The maximun of books can be borrowed is 10
            {
                printf("Invalid input. 1 reader can only borrow between 1 and 10 books for 1 time.\n");
                break;
            }
            getchar();
            // Enter inputs for 3 fields in newBorrow array
            for (int j = 0; j < 3; j++) // j is the number of cols of newBorrow
            {
                printf("Enter %s: ", newBorrow[j]);
                fgets(newBorrow[j], 50, stdin);
                newBorrow[j][strlen(newBorrow[j]) - 1] = '\0';

                strcpy_s(borrowform[i][j], newBorrow[j]);
            }
            // Enter ISBNs needed to borrow
            for (int j = 3; j < nBooks + 3; j++)
            {
                char ISBNborrow[1][50] = { "" }; // Initialize array to hold user input of ISBNs borrowed
                printf("Enter ISBN %d: ", j - 2); // Enter ISBN start from 1
                fgets(ISBNborrow[0], 50, stdin);
                ISBNborrow[0][strlen(ISBNborrow[0]) - 1] = '\0';

                strcpy_s(borrowform[i][j], ISBNborrow[0]);
                updateISBN_Status(listISBN, ISBNborrow[0], 0);
            }
            printf("Added!\n");
            break;
        }
    }
}

// 3-add-in. view List of books borrowed
void viewListBorrowBook(char(*borrowform)[14][50], int size)
{
    char newBorrow[3][50] = { "Reader Code", "Borrow date (dd-mm-yyyy)", "Expected return date (dd-mm-yyyy)" };
    for (int i = 0; i < size; i++)
    {
        if (borrowform[i][0][0] != '\0')
        {
            printf("Phieu %d:\n", i);
            for (int j = 0; j < 3; j++) // j is the number of cols of newBorrow array
            {
                printf("%s: %s\n", newBorrow[j], borrowform[i][j]);
            }
            for (int j = 3; j < size; j++)
            {
                if (borrowform[i][j][0] != '\0')
                    printf("ISBN %d: %s\n", j - 2, borrowform[i][j]); // View ISBN start from 1
            }
            printf("\n");
        }
    }
}

// 4. create Book Return Form
void createReturnForm(char(*returnform)[14][50], int size, char(*listISBN)[2][50])
{
    char newReturn[4][50] = { "Reader Code","Borrow date (dd-mm-yyyy)", "Expected return date (dd-mm-yyyy)","Actual return date (dd-mm-yyyy)" };
    int nBooks = 0;
    for (int i = 0; i < size; i++)
    {
        if (returnform[i][0][0] == '\0') // Find empty slot in returnform array to add new return
        {
            printf("Enter the number of books to return: \n");
            scanf_s("%d", &nBooks);
            getchar();
            // Enter inputs for 4 fields in newReturn array
            for (int j = 0; j < 4; j++) // j is the number of cols of newReturn
            {
                printf("Enter %s: ", newReturn[j]);
                fgets(newReturn[j], 50, stdin);
                newReturn[j][strlen(newReturn[j]) - 1] = '\0';

                strcpy_s(returnform[i][j], newReturn[j]);
            }
            // Enter ISBNs needed to return
            for (int j = 4; j < nBooks + 4; j++)
            {
                char ISBNreturn[1][50] = { "" }; // Initialize array to hold user input of ISBNs returned
                printf("Enter ISBN %d: ", j - 3); // Enter ISBN start from 1
                fgets(ISBNreturn[0], 50, stdin);
                ISBNreturn[0][strlen(ISBNreturn[0]) - 1] = '\0';

                strcpy_s(returnform[i][j], ISBNreturn[0]);
                updateISBN_Status(listISBN, ISBNreturn[0], 1);
            }
            printf("Added!\n");
            break;
        }
    }
}

// 4-add-in. view List of books returned
void viewListReturnBook(char(*returnform)[14][50], int size)
{
    char newReturn[4][50] = { "Reader Code","Borrow date (dd-mm-yyyy)", "Expected return date (dd-mm-yyyy)","Actual return date (dd-mm-yyyy)" };
    for (int i = 0; i < size; i++)
    {
        if (returnform[i][0][0] != '\0')
        {
            printf("Phieu %d:\n", i);
            for (int j = 0; j < 4; j++) // j is the number of cols of newReturn
            {
                printf("%s: %s\n", newReturn[j], returnform[i][j]);
            }
            for (int j = 4; j < size; j++)
            {
                if (returnform[i][j][0] != '\0')
                    printf("ISBN %d: %s\n", j - 3, returnform[i][j]); // View ISBN start from 1
            }
            printf("\n");
        }
    }
}

// 5a. Count total number of books the library has
void countBooksofLibrary(char(*books)[8][50], int size)
{
    int totalBooks = 0;

    // Iterate over the book list to count ISBNs
    for (int i = 0; i < size; i++) 
    {
        if (books[i][0][0] != '\0') // Check if ISBN is not empty
            totalBooks++;
    }
    printf("Total number of books the library has is: %d", totalBooks);
}

// 5b. Count total number of books by Genre
void countBooksByGenre(char(*books)[8][50], int size)
{
    //Genre includes Poetry, Fiction, Nonfiction, Drama
    char Genre[4][20] = { "Poetry", "Fiction", "Nonfiction", "Drama"};
    int totalBooksbyGenre[4] = { 0 };
    // Iterate over the book list to count books by genre
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < size; i++)
        {
            if (strcmp(books[i][5], Genre[j]) == 0)
            {
                totalBooksbyGenre[j]++;
            }
        }
        printf("The number of books in %s genre is: %d\n", Genre[j], totalBooksbyGenre[j]);
    }
}

// 5c. Count a total number of readers the library has
void countReadersofLibrary(char(*readers)[9][50], int size)
{
    int totalReaders = 0;

    // Iterate over the reader list to count ID numbers
    for (int i = 0; i < size; i++)
    {
        if (readers[i][2][0] != '\0') // Check if ISBN is not empty
            totalReaders++;
    }
    printf("Total number of readers the library has is: %d", totalReaders);
}

// 5d. Count a total number of readers by Gender
void countReadersByGender(char(*readers)[9][50], int size)
{
    //Gender includes Male, Female, LGBTIQA+
    char Gender[3][20] = { "Male", "Female", "LGBTIQA+" };
    int totalReadersbyGender[3] = { 0 };
    // Iterate over the book list to count books by genre
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < size; i++)
        {
            if (strcmp(readers[i][4], Gender[j]) == 0)
            {
                totalReadersbyGender[j]++;
            }
        }
        printf("The number of books in %s genre is: %d\n", Gender[j], totalReadersbyGender[j]);
    }
}

// 5e.  Count a total number books in borrowed
// Copy list of ISBNs from book array to the ISBN list array in order to manage ISBN properties
void updateListISBN(char(*listISBN)[2][50], int size, char(*books)[8][50])
{
    for (int i = 0; i < size; i++)
    {
        strcpy_s(listISBN[i][0], books[i][0]);
    }
    printf("Updated!\n");
    getchar();
}
// Update status in ISBN list array to record borrowed/ returned books
void updateISBN_Status(char(*listISBN)[2][50], char(*ISBN), int statusCode)
{
    char status[2][50] = { "Borrowed","Returned" };
    for (int i = 0; i < 100; i++) // 100 is the size of returnform char array
    {
        if (strcmp(listISBN[i][0], ISBN) == 0)
        {
            strcpy_s(listISBN[i][1], status[statusCode]);
            printf("ISBN %s Updated!\n", ISBN);
            getchar();
            break;
        }
    }
}
// Count books in borrowed by comparing status properties of ISBNs to the borrowed condition
void countBooksinBorrowed(char(*listISBN)[2][50], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(listISBN[i][1], "Borrowed") == 0) // 0 is col of status of each ISBN
        {
            count++;
        }
    }
    printf("The number of books in borrowed now is: %d", count);
}