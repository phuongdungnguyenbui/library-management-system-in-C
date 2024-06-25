#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Doan2header.h"
#include <stdlib.h>

//1a. Function aim: Display the list of readers along with their information.
void viewReaderList()
{
    //Buffer to get output from the file
    struct newReader readers[100] = {};
    //Open the ouput file
    int k = 0;
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Readers.txt", "rt");
    if (fp == NULL)
        printf("Cannot open the record file!\n");
    else
    {
        //Get data from file to buffer
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            fgets(readers[k].readerCode, sizeof(readers[k].readerCode), fp);
            fgets(readers[k].fullName, sizeof(readers[k].fullName), fp);
            fgets(readers[k].idNumber, sizeof(readers[k].idNumber), fp);
            fgets(readers[k].dateofBirth, sizeof(readers[k].dateofBirth), fp);
            fgets(readers[k].gender, sizeof(readers[k].gender), fp);
            fgets(readers[k].email, sizeof(readers[k].email), fp);
            fgets(readers[k].address, sizeof(readers[k].address), fp);
            fscanf_s(fp, "%02d-%02d-%4d", &readers[k].creationDate->Date, &readers[k].creationDate->Month, &readers[k].creationDate->Year);
            fscanf_s(fp, "%02d-%02d-%4d\n", &readers[k].expiryDate->Date, &readers[k].expiryDate->Month, &readers[k].expiryDate->Year);
            k++;
        }
        fclose(fp); // Close the output file
    }
    //View reader list
    for (int i = 0; i < k; i++)
    {
            printf("Reader %d:\n", i + 1); // Print the reader's order
            printf("Reader code: %s", readers[i].readerCode); //View reader code
            printf("Full name: %s", readers[i].fullName);
            printf("ID number: %s", readers[i].idNumber);
            printf("Date of birth: %s", readers[i].dateofBirth);
            printf("Gender: %s", readers[i].gender);
            printf("Email: %s", readers[i].email);
            printf("Address: %s", readers[i].address);
            printf("Creation date: %02d-%02d-%4d\n", readers[i].creationDate->Date, readers[i].creationDate->Month, readers[i].creationDate->Year);
            printf("Expiry date: %02d-%02d-%4d\n", readers[i].expiryDate->Date, readers[i].expiryDate->Month, readers[i].expiryDate->Year);
    }
    printf("End of reader list!\n");
}
//1b. Function aim: Add new readers to the list of readers. Expiry Date is 48 months after Creation Date
void addReader()
{
    //Buffer to get output from the file
    struct newReader readers[100] = {};
    //Open the ouput file
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Readers.txt", "at"); //Open to append input at the end of the file
    if (fp == NULL)
        printf("Cannot open the record file!\n");
    else
    {
        fseek(fp, 0, SEEK_END);
        long fileSize = ftell(fp); //The size of the file
        // Enter the number of readers to add
        int n;
        do
        {
            printf("Enter the number of readers you need to add (>0): ");
            scanf_s("%d", &n);
        } while (n <= 0);
        getchar();
        //Go over the reader list in the file
        for (int i = 0; i < n; i++)
        {
            //Input
            if (fileSize == 0 && i == 0) // If add the first reader in the file, no '\n' before ReaderCode
            {
                printf("Enter Reader Code: "); // Start to input information
                fgets(readers[i].readerCode, 20, stdin); // Get and save input ito buffer
                fprintf(fp, "%s", readers[i].readerCode); // Save input into the file
                readers[i].readerCode[strlen(readers[i].readerCode) - 1] = '\0'; //Remove the newline character when entering ('\n')
            }
            else
            {
                printf("Enter Reader Code: "); // Start to input information
                fgets(readers[i].readerCode, 20, stdin); // Get and save input ito buffer
                fprintf(fp, "\n%s", readers[i].readerCode); // Save input into the file
                readers[i].readerCode[strlen(readers[i].readerCode) - 1] = '\0'; //Remove the newline character when entering ('\n')
            }
            printf("Enter Full Name: "); // Start to input information
            fgets(readers[i].fullName, 50, stdin); // Get and save input ito buffer
            fputs(readers[i].fullName, fp); // Save input into the file
            readers[i].fullName[strlen(readers[i].fullName) - 1] = '\0'; // Remove the newline character when entering ('\n')

            printf("Enter ID Number: ");
            fgets(readers[i].idNumber, 20, stdin);
            fputs(readers[i].idNumber, fp);
            readers[i].idNumber[strlen(readers[i].idNumber) - 1] = '\0';

            printf("Enter Date of birth (dd-mm-yyyy): ");
            fgets(readers[i].dateofBirth, 20, stdin);
            fputs(readers[i].dateofBirth, fp);
            readers[i].dateofBirth[strlen(readers[i].dateofBirth) - 1] = '\0';

            printf("Enter Gender: ");
            fgets(readers[i].gender, 10, stdin);
            fputs(readers[i].gender, fp);
            readers[i].gender[strlen(readers[i].gender) - 1] = '\0';

            printf("Enter Email: ");
            fgets(readers[i].email, 50, stdin);
            fputs(readers[i].email, fp);
            readers[i].email[strlen(readers[i].email) - 1] = '\0';

            printf("Enter Address: ");
            fgets(readers[i].address, 50, stdin);
            fputs(readers[i].address, fp);
            readers[i].address[strlen(readers[i].address) - 1] = '\0';

            printf("Enter Creation Date (dd-mm-yyyy): "); // Start to input information
            scanf_s("%02d-%02d-%4d", &readers[i].creationDate->Date, &readers[i].creationDate->Month, &readers[i].creationDate->Year); // Save user input to buffer
            fprintf(fp, "%02d-%02d-%4d\n", readers[i].creationDate->Date, readers[i].creationDate->Month, readers[i].creationDate->Year); // Save input to the file as predescribed format

            //Calcultate Expiry Date
            readers[i].expiryDate->Year = readers[i].creationDate->Year + 4; // Expiry Date is 48 months (4 years) after Creation Date
            readers[i].expiryDate->Date = readers[i].creationDate->Date;
            readers[i].expiryDate->Month = readers[i].creationDate->Month;
            fprintf(fp, "%02d-%02d-%4d", readers[i].expiryDate->Date, readers[i].expiryDate->Month, readers[i].expiryDate->Year); // Save input to the file as predescribed format
            getchar();
        }
        fclose(fp);
    }
    printf("Add reader successfully!\n");
}
//1c. Function aim: Modify a reader in the list of readers, define the reader to modify by Reader code. Keep his/her Reader Code.
void modifyReader()
{
    //Buffer to get output from the file
    struct newReader readers[100] = {};
    //Open the ouput file
    int k = 0;
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Readers.txt", "rt");
    if (fp == NULL)
        printf("Cannot open the record file!\n");
    else
    {
        //Get data from file to buffer
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            fgets(readers[k].readerCode, sizeof(readers[k].readerCode), fp);
            fgets(readers[k].fullName, sizeof(readers[k].fullName), fp);
            fgets(readers[k].idNumber, sizeof(readers[k].idNumber), fp);
            fgets(readers[k].dateofBirth, sizeof(readers[k].dateofBirth), fp);
            fgets(readers[k].gender, sizeof(readers[k].gender), fp);
            fgets(readers[k].email, sizeof(readers[k].email), fp);
            fgets(readers[k].address, sizeof(readers[k].address), fp);
            fscanf_s(fp, "%02d-%02d-%4d", &readers[k].creationDate->Date, &readers[k].creationDate->Month, &readers[k].creationDate->Year);
            fscanf_s(fp, "%02d-%02d-%4d\n", &readers[k].expiryDate->Date, &readers[k].expiryDate->Month, &readers[k].expiryDate->Year);
            k++;
        }
        fclose(fp);
    }
    // Reader to modify defined by Reader code
    char readerCode[20];
    printf("Enter Reader Code of reader to modify: ");
    fgets(readerCode, 20, stdin); // Get and save the Reader code which the reader has will be modified

    bool found = false;
    for (int i = 0; i < k; i++)
    {
        if (strcmp(readers[i].readerCode, readerCode) == 0) // Define the reader in the buffer to modify, which has similar Reader code to the input
        {
            found = true;
            // Function to choose which information items to modify (keep the Reader Code)
            char modify[3] = "-1";
            do
            {
                printf("What are reader's information items to modify? Not anymore - Enter 0;\nFull name - Enter 1;\nID number - Enter 2;\nDate of birth - Enter 3;\nGender - Enter 4;\nEmail - Enter 5;\nAddress - Enter 6;\nCreation date - Enter 7;\n");
                printf("Enter your choice: ");
                fgets(modify, 3, stdin); // Input the number equivalent to what field to modify
                modify[strlen(modify) - 1] = '\0'; // Remove the newline character when entering ('\n')
                // Enter and save the new information
                switch (atoi(modify)) // From array to int
                {
                case 1:
                    char fullName[50];
                    printf("Enter new Full name: "); // Input information
                    fgets(fullName, 50, stdin); //Save input to buffer
                    //fullName[strlen(fullName)] = '\n';
                    strcpy_s(readers[i].fullName, fullName); // Copy the input value to the buffer
                    printf("Full name updated!\n");
                    break;
                case 2:
                    char idNumber[20];
                    printf("Enter new ID number: ");
                    fgets(idNumber, 20, stdin);
                    strcpy_s(readers[i].idNumber, idNumber); 
                    printf("ID number updated!");
                    break;
                case 3:
                    char Birthday[20];
                    printf("Enter new Date of birth (dd-mm-yyyy): ");
                    fgets(Birthday, 20, stdin);
                    strcpy_s(readers[i].dateofBirth, Birthday);
                    printf("Date of birth updated!");
                    break;
                case 4:
                    char gender[10];
                    printf("Enter new Gender: ");
                    fgets(gender, 10, stdin);
                    strcpy_s(readers[i].gender, gender);
                    printf("Gender updated!");
                    break;
                case 5:
                    char email[50];
                    printf("Enter new Email: ");
                    fgets(email, 50, stdin);
                    strcpy_s(readers[i].email, email);
                    printf("Email updated!");
                    break;
                case 6:
                    char address[50];
                    printf("Enter new Address: ");
                    fgets(address, 50, stdin);
                    strcpy_s(readers[i].address, address);
                    printf("Address updated!");
                    break;
                case 7:
                    printf("Enter new Creation date: "); // Input information
                    scanf_s("%02d-%02d-%4d", &readers[i].creationDate->Date, &readers[i].creationDate->Month, &readers[i].creationDate->Year); //Save user input to buffer
                    //Calcultate Expiry Date
                    readers[i].expiryDate->Year = readers[i].creationDate->Year + 4; //Expiry Date is 48 months (4 years) after Creation Date
                    printf("Creation date and Expiry date updated!");
                    break;
                default:
                    break;
                }
            } while (atoi(modify) != 0);
            break;
        }
    }
    if (!found)
    {
        readerCode[strlen(readerCode) - 1] = '\0'; // Remove the newline character when entering ('\n')
        printf("Reader with Reader Code %s not found.\n", readerCode);
    }
    // Open the file and overwrite if there is change
    if (found)
    {
        fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Readers.txt", "wt");
        if (fp == NULL)
            printf("Cannot open the record file!\n");
        else
        {
            // Save input from the buffer to the file
            for (int i = 0; i < k; i++)
            {
                if (i >= 1)
                    fprintf(fp, "\n%s", readers[i].readerCode); // Save input from the user into the file
                else
                    fprintf(fp, "%s", readers[i].readerCode);
                fputs(readers[i].fullName, fp); // Save input from the user into the file
                fputs(readers[i].idNumber, fp);
                fputs(readers[i].dateofBirth, fp);
                fputs(readers[i].gender, fp);
                fputs(readers[i].email, fp);
                fputs(readers[i].address, fp);
                fprintf(fp, "%02d-%02d-%4d\n", readers[i].creationDate->Date, readers[i].creationDate->Month, readers[i].creationDate->Year); // Save input from the user into the file as predescribed format
                fprintf(fp, "%02d-%02d-%4d", readers[i].expiryDate->Date, readers[i].expiryDate->Month, readers[i].expiryDate->Year);
            }
        }
        fclose(fp);
    }
}
//1d. Function aim: Delete a reader in the list of readers, define the reader to delete by Reader code.
void deleteReader()
{
    //Buffer to get output from the file
    struct newReader readers[100] = {};
    //Open the ouput file
    int k = 0;
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Readers.txt", "rt");
    if (fp == NULL)
        printf("Cannot open the record file!\n");
    else
    {
        //Get data from file to buffer
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            fgets(readers[k].readerCode, sizeof(readers[k].readerCode), fp);
            fgets(readers[k].fullName, sizeof(readers[k].fullName), fp);
            fgets(readers[k].idNumber, sizeof(readers[k].idNumber), fp);
            fgets(readers[k].dateofBirth, sizeof(readers[k].dateofBirth), fp);
            fgets(readers[k].gender, sizeof(readers[k].gender), fp);
            fgets(readers[k].email, sizeof(readers[k].email), fp);
            fgets(readers[k].address, sizeof(readers[k].address), fp);
            fscanf_s(fp, "%02d-%02d-%4d", &readers[k].creationDate->Date, &readers[k].creationDate->Month, &readers[k].creationDate->Year);
            fscanf_s(fp, "%02d-%02d-%4d\n", &readers[k].expiryDate->Date, &readers[k].expiryDate->Month, &readers[k].expiryDate->Year);
            k++; // The position of EOF, there are k-1 readers existing in the file
        }
        fclose(fp);
    }
    // Reader to delete defined by Reader code
    char readerCode[20];
    printf("Enter Reader Code of reader to delete: ");
    fgets(readerCode, 20, stdin); // Get and save the Reader code, with it the reader will be deleted

    bool found = false;
    for (int i = 0; i < k; i++)
    {
        if (strcmp(readers[i].readerCode, readerCode) == 0) // Define the reader in the buffer to delete, which has similar Reader code to the input
        {
            found = true;
            // Delete the reader in buffer by shifting all the subsequent entries to -1 position, the last reader will left duplicated
            for (int j = i; j < k - 1; j++) // Reader at k-1 position is kept but will not be saved to the file
            {
                strcpy_s(readers[j].readerCode, readers[j + 1].readerCode);
                strcpy_s(readers[j].fullName, readers[j + 1].fullName);
                strcpy_s(readers[j].idNumber, readers[j + 1].idNumber);
                strcpy_s(readers[j].dateofBirth, readers[j + 1].dateofBirth);
                strcpy_s(readers[j].gender, readers[j + 1].gender);
                strcpy_s(readers[j].email, readers[j + 1].email);
                strcpy_s(readers[j].address, readers[j + 1].address);
                readers[j].creationDate->Date = readers[j + 1].creationDate->Date;
                readers[j].creationDate->Month = readers[j + 1].creationDate->Month;
                readers[j].creationDate->Year = readers[j + 1].creationDate->Year;
                readers[j].expiryDate->Date = readers[j + 1].expiryDate->Date;
                readers[j].expiryDate->Month = readers[j + 1].expiryDate->Month;
                readers[j].expiryDate->Year = readers[j + 1].expiryDate->Year;
            }
            printf("Delete successfully!");
        }
    }
    if (!found)
    {
        readerCode[strlen(readerCode) - 1] = '\0'; // Remove the newline character when entering ('\n')
        printf("Reader with Reader Code %s not found.\n", readerCode);
    }
    // Open the file and overwrite if there is change
    if (found)
    {
        fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Readers.txt", "wt");
        if (fp == NULL)
            printf("Cannot open the record file!\n");
        else
        {
            for (int i = 0; i < k - 1; i++) // Only save k-2 readers to the file, as 1 reader is deleted
            {
                if (i >= 1)
                    fprintf(fp, "\n%s", readers[i].readerCode); // Save input from the user into the file
                else
                    fprintf(fp, "%s", readers[i].readerCode);
                fputs(readers[i].fullName, fp); // Save input from the user into the file
                fputs(readers[i].idNumber, fp);
                fputs(readers[i].dateofBirth, fp);
                fputs(readers[i].gender, fp);
                fputs(readers[i].email, fp);
                fputs(readers[i].address, fp);
                fprintf(fp, "%02d-%02d-%4d\n", readers[i].creationDate->Date, readers[i].creationDate->Month, readers[i].creationDate->Year); // Save input from the user into the file as predescribed format
                fprintf(fp, "%02d-%02d-%4d", readers[i].expiryDate->Date, readers[i].expiryDate->Month, readers[i].expiryDate->Year);
            }
        }
        fclose(fp);
    }
}
//1e. Function aim: Search Reader by ID number.
void searchReaderbyID()
{
    //Buffer to get output from the file
    struct newReader readers[100] = {};
    //Open the ouput file
    int k = 0;
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Readers.txt", "rt");
    if (fp == NULL)
        printf("Cannot open the record file!\n");
    else
    {
        //Get data from file to buffer
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            fgets(readers[k].readerCode, sizeof(readers[k].readerCode), fp);
            fgets(readers[k].fullName, sizeof(readers[k].fullName), fp);
            fgets(readers[k].idNumber, sizeof(readers[k].idNumber), fp);
            fgets(readers[k].dateofBirth, sizeof(readers[k].dateofBirth), fp);
            fgets(readers[k].gender, sizeof(readers[k].gender), fp);
            fgets(readers[k].email, sizeof(readers[k].email), fp);
            fgets(readers[k].address, sizeof(readers[k].address), fp);
            fscanf_s(fp, "%02d-%02d-%4d", &readers[k].creationDate->Date, &readers[k].creationDate->Month, &readers[k].creationDate->Year);
            fscanf_s(fp, "%02d-%02d-%4d\n", &readers[k].expiryDate->Date, &readers[k].expiryDate->Month, &readers[k].expiryDate->Year);
            k++; // The position of EOF, there are k-1 readers existing in the file
        }
        fclose(fp);
    }
    // Reader defined by ID number
    char idNumber[20];
    printf("Enter ID number of the reader in search: ");
    fgets(idNumber, 20, stdin); // Get and save the ID number of the reader in search

    // Going through the buffer to view the reader in search
    bool found = false;
    for (int i = 0; i < k; i++)
    {
        if (strcmp(readers[i].idNumber, idNumber) == 0) // Define the reader in the buffer to view, which has similar ID number to the input
        {
            found = true;
            printf("Reader in search has the following information:\n");
            printf("Reader %d:\n", i + 1); // Print the reader's order
            printf("Reader code: %s", readers[i].readerCode); //View reader code
            printf("Full name: %s", readers[i].fullName);
            printf("ID number: %s", readers[i].idNumber);
            printf("Date of birth: %s", readers[i].dateofBirth);
            printf("Gender: %s", readers[i].gender);
            printf("Email: %s", readers[i].email);
            printf("Address: %s", readers[i].address);
            printf("Creation date: %02d-%02d-%4d\n", readers[i].creationDate->Date, readers[i].creationDate->Month, readers[i].creationDate->Year);
            printf("Expiry date: %02d-%02d-%4d\n", readers[i].expiryDate->Date, readers[i].expiryDate->Month, readers[i].expiryDate->Year);
            break;
        }
    }
    if (!found)
    {
        idNumber[strlen(idNumber) - 1] = '\0'; // Remove the newline character when entering ('\n')
        printf("Reader with ID number %s not found.\n", idNumber);
    }
}
//1f. Function aim: Search Reader by Full name.
void searchReaderbyName()
{
    //Buffer to get output from the file
    struct newReader readers[100] = {};
    //Open the ouput file
    int k = 0;
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Readers.txt", "rt");
    if (fp == NULL)
        printf("Cannot open the record file!\n");
    else
    {
        //Get data from file to buffer
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            fgets(readers[k].readerCode, sizeof(readers[k].readerCode), fp);
            fgets(readers[k].fullName, sizeof(readers[k].fullName), fp);
            fgets(readers[k].idNumber, sizeof(readers[k].idNumber), fp);
            fgets(readers[k].dateofBirth, sizeof(readers[k].dateofBirth), fp);
            fgets(readers[k].gender, sizeof(readers[k].gender), fp);
            fgets(readers[k].email, sizeof(readers[k].email), fp);
            fgets(readers[k].address, sizeof(readers[k].address), fp);
            fscanf_s(fp, "%02d-%02d-%4d", &readers[k].creationDate->Date, &readers[k].creationDate->Month, &readers[k].creationDate->Year);
            fscanf_s(fp, "%02d-%02d-%4d\n", &readers[k].expiryDate->Date, &readers[k].expiryDate->Month, &readers[k].expiryDate->Year);
            k++; // The position of EOF, there are k-1 readers existing in the file
        }
        fclose(fp);
    }
    // Reader defined by ID number
    char fullName[20];
    printf("Enter Full name of the reader in search: ");
    fgets(fullName, 20, stdin); // Get and save the ID number of the reader in search

    // Going through the buffer to find the reader in search
    bool found = false;
    for (int i = 0; i < k; i++)
    {
        if (strcmp(readers[i].fullName, fullName) == 0) // Define the reader in the buffer to view, which has similar ID number to the input
        {
            found = true;
            printf("Reader %d:\n", i + 1); // Print the reader's order
            printf("Reader code: %s", readers[i].readerCode); //View reader code
            printf("Full name: %s", readers[i].fullName);
            printf("ID number: %s", readers[i].idNumber);
            printf("Date of birth: %s", readers[i].dateofBirth);
            printf("Gender: %s", readers[i].gender);
            printf("Email: %s", readers[i].email);
            printf("Address: %s", readers[i].address);
            printf("Creation date: %02d-%02d-%4d\n", readers[i].creationDate->Date, readers[i].creationDate->Month, readers[i].creationDate->Year);
            printf("Expiry date: %02d-%02d-%4d\n", readers[i].expiryDate->Date, readers[i].expiryDate->Month, readers[i].expiryDate->Year);
            break;
        }
    }
    if (!found)
    {
        fullName[strlen(fullName) - 1] = '\0'; // Remove the newline character when entering ('\n')
        printf("Reader with Full name %s not found.\n", fullName);
    }
}
//2a. Function aim: Display the list of books along with their information.
void viewBookList()
{
    //Buffer to get output from the file
    struct newBook books[100] = {};
    //Open the ouput file
    int k = 0;
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Books.txt", "rt");
    if (fp == NULL)
        printf("Cannot open the record file!\n");
    else
    {
        //Get data from file to buffer
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            fgets(books[k].ISBN, sizeof(books[k].ISBN), fp);
            fgets(books[k].bookName, sizeof(books[k].bookName), fp);
            fgets(books[k].author, sizeof(books[k].author), fp);
            fgets(books[k].publisher, sizeof(books[k].publisher), fp);
            fscanf_s(fp, "%d", &books[k].publicationYear);
            fseek(fp, +2L, SEEK_CUR); // Move to forward 2 steps to ignore the '\n'
            fgets(books[k].genre, sizeof(books[k].genre), fp);
            fscanf_s(fp, "%d\n", &books[k].bookPrice);
            fscanf_s(fp, "%d\n", &books[k].numofCopies);
            k++;
        }
        fclose(fp); // Close the output file
    }
    //View book list
    for (int i = 0; i < k; i++)
    {
        printf("Book %d:\n", i + 1); // Print the book's order
        printf("ISBN: %s", books[i].ISBN); //View Book code
        printf("Book name: %s", books[i].bookName);
        printf("Author: %s", books[i].author);
        printf("Publisher: %s", books[i].publisher);
        printf("Publication Year: %d\n", books[i].publicationYear);
        printf("Genre: %s", books[i].genre);
        printf("Book price: %d VND\n", books[i].bookPrice);
        printf("Number of book copies: %d\n", books[i].numofCopies);
    }
    printf("End of book list!\n");
}
//2b. Function aim: Add new books to the list of books.
void addBook()
{
    //Buffer to get output from the file
    struct newBook books[100] = {};
    //Open the ouput file
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Books.txt", "at");
    if (fp == NULL)
        printf("Cannot open the record file!\n");
    else
    {
        fseek(fp, 0, SEEK_END);
        long fileSize = ftell(fp); //The size of the file
        // Enter the number of books to add
        int n;
        do
        {
            printf("Enter the number of books you need to add : ");
            scanf_s("%d", &n);
        } while (n <= 0);
        getchar();
        //Go over the reader list in the file
        for (int i = 0; i < n; i++)
        {
            //Input
            if (fileSize == 0 && i == 0)
            {
                printf("Enter ISBN: "); // Start to input information
                fgets(books[i].ISBN, 20, stdin); // Get and save input ito buffer
                fprintf(fp, "%s", books[i].ISBN); // Save input into the file
                books[i].ISBN[strlen(books[i].ISBN) - 1] = '\0'; //Remove the newline character when entering ('\n')
            }
            else
            {
                printf("Enter ISBN: "); // Start to input information
                fgets(books[i].ISBN, 20, stdin); // Get and save input ito buffer
                fprintf(fp, "\n%s", books[i].ISBN); // Save input into the file
                books[i].ISBN[strlen(books[i].ISBN) - 1] = '\0'; //Remove the newline character when entering ('\n')
            }

            printf("Enter Book Name: "); // Start to input information
            fgets(books[i].bookName, 50, stdin); // Get and save input ito buffer
            fputs(books[i].bookName, fp); // Save input into the file
            books[i].bookName[strlen(books[i].bookName) - 1] = '\0'; // Remove the newline character when entering ('\n')

            printf("Enter Author: ");
            fgets(books[i].author, 50, stdin);
            fputs(books[i].author, fp);
            books[i].author[strlen(books[i].author) - 1] = '\0';

            printf("Enter Publisher: ");
            fgets(books[i].publisher, 50, stdin);
            fputs(books[i].publisher, fp);
            books[i].publisher[strlen(books[i].publisher) - 1] = '\0';

            printf("Enter Publication Year: "); // Start to input information
            scanf_s("%d", &books[i].publicationYear); // Save user input to buffer
            fprintf(fp, "%d\n", books[i].publicationYear); // Save input to the file as predescribed format
            getchar();

            printf("Enter Genre: ");
            fgets(books[i].genre, 20, stdin);
            fputs(books[i].genre, fp);
            books[i].genre[strlen(books[i].genre) - 1] = '\0';

            printf("Enter Book price: ");
            scanf_s("%d", &books[i].bookPrice);
            fprintf(fp, "%d\n", books[i].bookPrice);

            printf("Enter Number of Book Copies: ");
            scanf_s("%d", &books[i].numofCopies);
            fprintf(fp, "%d", books[i].numofCopies);
            getchar();
        }
        fclose(fp);
    }
    printf("Add book successfully!\n");
}
//2c. Function aim: Modify a book in the list of books, define the book to modify by ISBN. Keep its ISBN.
void modifyBook()
{
    //Buffer to get output from the file
    struct newBook books[100] = {};
    //Open the ouput file
    int k = 0;
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Books.txt", "rt");
    if (fp == NULL)
        printf("Cannot open the record file!\n");
    else
    {
        //Get data from file to buffer
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            fgets(books[k].ISBN, sizeof(books[k].ISBN), fp);
            fgets(books[k].bookName, sizeof(books[k].bookName), fp);
            fgets(books[k].author, sizeof(books[k].author), fp);
            fgets(books[k].publisher, sizeof(books[k].publisher), fp);
            fscanf_s(fp, "%d", &books[k].publicationYear);
            fseek(fp, +2L, SEEK_CUR); // Move to forward 2 steps to ignore the '\n'
            fgets(books[k].genre, sizeof(books[k].genre), fp);
            fscanf_s(fp, "%d\n", &books[k].bookPrice);
            fscanf_s(fp, "%d\n", &books[k].numofCopies);
            k++;
        }
        fclose(fp);
    }
    // Book to modify defined by ISBN
    char ISBN[20];
    printf("Enter ISBN of book needed to be modified: ");
    fgets(ISBN, 20, stdin); // Get and save the ISBN of the book to modify

    bool found = false;
    for (int i = 0; i < k; i++)
    {
        if (strcmp(books[i].ISBN, ISBN) == 0) // Define the book in the buffer to modify, which has similar ISBN to the input
        {
            found = true;
            // Function to choose which information items to modify (keep the ISBN)
            char modify[3] = "-1";
            do
            {
                printf("What are book's information items to modify? Not anymore - Enter 0;\nBook name - Enter 1;\nAuthor - Enter 2;\nPublisher - Enter 3;\nPublication year - Enter 4;\nGenre - Enter 5;\nBook price - Enter 6;\nNumber of book copies - Enter 7\n");
                printf("Enter your choice: ");
                fgets(modify, 3, stdin); // Input the number equivalent to what field to modify
                modify[strlen(modify) - 1] = '\0'; // Remove the newline character when entering ('\n')
                // Enter and save the new information
                switch (atoi(modify)) // From array to int
                {
                case 1:
                    char bookName[50];
                    printf("Enter new Book name: "); // Input information
                    fgets(bookName, 50, stdin); //Save input to buffer
                    //bookName[strlen(bookName)] = '\n';
                    strcpy_s(books[i].bookName, bookName); // Copy the input value to the buffer
                    printf("Book name updated!\n");
                    break;
                case 2:
                    char author[50];
                    printf("Enter new ID number: ");
                    fgets(author, 50, stdin);
                    strcpy_s(books[i].author, author);
                    printf("Author updated!");
                    break;
                case 3:
                    char publisher[50];
                    printf("Enter new Publisher: ");
                    fgets(publisher, 50, stdin);
                    strcpy_s(books[i].publisher, publisher);
                    printf("Publisher updated!");
                    break;
                case 4:
                    int publicationYear;
                    printf("Enter new Publication year: ");
                    scanf_s("%d", &publicationYear);
                    books[i].publicationYear = publicationYear;
                    printf("Publication year updated!");
                    break;
                case 5:
                    char genre[20];
                    printf("Enter new Genre: ");
                    fgets(genre, 20, stdin);
                    strcpy_s(books[i].genre, genre);
                    printf("Genre updated!");
                    break;
                case 6:
                    int Price;
                    printf("Enter new Book price: ");
                    scanf_s("%d", &Price);
                    books[i].bookPrice = Price;
                    printf("Book price updated!");
                    break;
                case 7:
                    int Nocopies;
                    printf("Enter new Number of book copies: ");
                    scanf_s("%d", &Nocopies);
                    books[i].numofCopies = Nocopies;
                    printf("Number of book copies updated!");
                    break;
                default:
                    break;
                }
            } while (atoi(modify) != 0);
            break;
        }
    }
    if (!found)
    {
        ISBN[strlen(ISBN) - 1] = '\0'; // Remove the newline character when entering ('\n')
        printf("Book with ISBN %s not found.\n", ISBN);
    }
    // Open the file and overwrite if there is change
    if (found)
    {
        fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Books.txt", "wt");
        if (fp == NULL)
            printf("Cannot open the record file!\n");
        else
        {
            // Save input from the buffer to the file
            for (int i = 0; i < k; i++)
            {
                if (i >= 1)
                    fprintf(fp, "\n%s", books[i].ISBN); // Save input from the user into the file
                else
                    fprintf(fp, "%s", books[i].ISBN);
                fputs(books[i].bookName, fp); // Save input from the user into the file
                fputs(books[i].author, fp);
                fputs(books[i].publisher, fp);
                fprintf(fp, "%d\n", books[i].publicationYear); // Save input to the file as int
                fputs(books[i].genre, fp);
                fprintf(fp, "%d\n", books[i].bookPrice);
                fprintf(fp, "%d", books[i].numofCopies);
            }
        }
        fclose(fp);
    }
}
//2d. Function aim: Delete a book in the list of books, define the book to delete by ISBN.
void deleteBook()
{
    //Buffer to get output from the file
    struct newBook books[100] = {};
    //Open the ouput file
    int k = 0;
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Books.txt", "rt");
    if (fp == NULL)
        printf("Cannot open the record file!\n");
    else
    {
        //Get data from file to buffer
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            fgets(books[k].ISBN, sizeof(books[k].ISBN), fp);
            fgets(books[k].bookName, sizeof(books[k].bookName), fp);
            fgets(books[k].author, sizeof(books[k].author), fp);
            fgets(books[k].publisher, sizeof(books[k].publisher), fp);
            fscanf_s(fp, "%d", &books[k].publicationYear);
            fseek(fp, +2L, SEEK_CUR); // Move to forward 2 steps to ignore the '\n'
            fgets(books[k].genre, sizeof(books[k].genre), fp);
            fscanf_s(fp, "%d\n", &books[k].bookPrice);
            fscanf_s(fp, "%d\n", &books[k].numofCopies);
            k++; // The position of EOF, there are k-1 books existing in the file
        }
        fclose(fp);
    }
    // Book to delete defined by ISBN
    char ISBN[20];
    printf("Enter ISBN of book to be deleted: ");
    fgets(ISBN, 20, stdin); // Get and save the ISBN of the book to delete

    bool found = false;
    for (int i = 0; i < k; i++)
    {
        if (strcmp(books[i].ISBN, ISBN) == 0) // Define the book in the buffer to delete, which has similar ISBN to the input
        {
            found = true;
            // Delete the book in buffer by shifting all the subsequent entries to -1 position, the last book will left duplicated
            for (int j = i; j < k - 1; j++) // Book at k-1 position (the last position) is kept but will not be saved to the file
            {
                strcpy_s(books[j].ISBN, books[j + 1].ISBN);
                strcpy_s(books[j].bookName, books[j + 1].bookName);
                strcpy_s(books[j].author, books[j + 1].author);
                strcpy_s(books[j].publisher, books[j + 1].publisher);
                books[j].publicationYear = books[j + 1].publicationYear;
                strcpy_s(books[j].genre, books[j + 1].genre);
                books[j].bookPrice = books[j + 1].bookPrice;
                books[j].numofCopies = books[j + 1].numofCopies;
            }
            printf("Delete successfully!");
        }
    }
    if (!found)
    {
        ISBN[strlen(ISBN) - 1] = '\0'; // Remove the newline character when entering ('\n')
        printf("Reader with ISBN %s not found.\n", ISBN);
    }
    // Open the file and overwrite if there is change
    if (found)
    {
        fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Books.txt", "wt");
        if (fp == NULL)
            printf("Cannot open the record file!\n");
        else
        {
            for (int i = 0; i < k - 1; i++) // Only save k-2 books to the file, as 1 reader is deleted
            {
                if (i >= 1)
                    fprintf(fp, "\n%s", books[i].ISBN); // Save input from the user into the file
                else
                    fprintf(fp, "%s", books[i].ISBN);
                fputs(books[i].bookName, fp); // Save input from the user into the file
                fputs(books[i].author, fp);
                fputs(books[i].publisher, fp);
                fprintf(fp, "%d\n", books[i].publicationYear); // Save input to the file as int
                fputs(books[i].genre, fp);
                fprintf(fp, "%d\n", books[i].bookPrice);
                fprintf(fp, "%d", books[i].numofCopies);
            }
        }
        fclose(fp);
    }
}
//2e. Function aim: Search Book by ISBN.
void searchBookbyISBN()
{
    //Buffer to get output from the file
    struct newBook books[100] = {};
    //Open the ouput file
    int k = 0;
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Books.txt", "rt");
    if (fp == NULL)
        printf("Cannot open the record file!\n");
    else
    {
        //Get data from file to buffer
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            fgets(books[k].ISBN, sizeof(books[k].ISBN), fp);
            fgets(books[k].bookName, sizeof(books[k].bookName), fp);
            fgets(books[k].author, sizeof(books[k].author), fp);
            fgets(books[k].publisher, sizeof(books[k].publisher), fp);
            fscanf_s(fp, "%d", &books[k].publicationYear);
            fseek(fp, +2L, SEEK_CUR); // Move to forward 2 steps to ignore the '\n'
            fgets(books[k].genre, sizeof(books[k].genre), fp);
            fscanf_s(fp, "%d\n", &books[k].bookPrice);
            fscanf_s(fp, "%d\n", &books[k].numofCopies);
            k++; // The position of EOF, there are k-1 books existing in the file
        }
        fclose(fp);
    }
    // Book defined by ISBN
    char ISBN[20];
    printf("Enter ISBN of book in search: ");
    fgets(ISBN, 20, stdin); // Get and save the ISBN of the book in search

    // Going through the buffer to view the book in search
    bool found = false;
    for (int i = 0; i < k; i++)
    {
        if (strcmp(books[i].ISBN, ISBN) == 0) // Define the book in the buffer to view, which has similar ISBN to the input
        {
            found = true;
            printf("Book in search has the following information:\n");
            printf("Book %d:\n", i + 1); // Print the book's order
            printf("ISBN: %s", books[i].ISBN); //View Book code
            printf("Book name: %s", books[i].bookName);
            printf("Author: %s", books[i].author);
            printf("Publisher: %s", books[i].publisher);
            printf("Publication Year: %d\n", books[i].publicationYear);
            printf("Genre: %s", books[i].genre);
            printf("Book price: %d VND\n", books[i].bookPrice);
            printf("Number of book copies: %d\n", books[i].numofCopies);
            break;
        }
    }
    if (!found)
    {
        ISBN[strlen(ISBN) - 1] = '\0'; // Remove the newline character when entering ('\n')
        printf("Book with ISBN %s not found.\n", ISBN);
    }
}
//2f. Function aim: Search Book by its Name.
void searchBookbyName()
{
    //Buffer to get output from the file
    struct newBook books[100] = {};
    //Open the ouput file
    int k = 0;
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Books.txt", "rt");
    if (fp == NULL)
        printf("Cannot open the record file!\n");
    else
    {
        //Get data from file to buffer
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            fgets(books[k].ISBN, sizeof(books[k].ISBN), fp);
            fgets(books[k].bookName, sizeof(books[k].bookName), fp);
            fgets(books[k].author, sizeof(books[k].author), fp);
            fgets(books[k].publisher, sizeof(books[k].publisher), fp);
            fscanf_s(fp, "%d", &books[k].publicationYear);
            fseek(fp, +2L, SEEK_CUR); // Move to forward 2 steps to ignore the '\n'
            fgets(books[k].genre, sizeof(books[k].genre), fp);
            fscanf_s(fp, "%d\n", &books[k].bookPrice);
            fscanf_s(fp, "%d\n", &books[k].numofCopies);
            k++; // The position of EOF, there are k-1 books existing in the file
        }
        fclose(fp);
    }
    // Book defined by Book Name
    char Name[20];
    printf("Enter Name of the book in search: ");
    fgets(Name, 20, stdin); // Get and save the Name of the book in search

    // Going through the buffer to view the book in search
    bool found = false;
    for (int i = 0; i < k; i++)
    {
        if (strcmp(books[i].bookName, Name) == 0) // Define the book in the buffer to view, which has similar Name to the input
        {
            found = true;
            printf("Book in search has the following information:\n");
            printf("Book %d:\n", i + 1); // Print the book's order
            printf("ISBN: %s", books[i].ISBN); //View Book code
            printf("Book name: %s", books[i].bookName);
            printf("Author: %s", books[i].author);
            printf("Publisher: %s", books[i].publisher);
            printf("Publication Year: %d\n", books[i].publicationYear);
            printf("Genre: %s", books[i].genre);
            printf("Book price: %d VND\n", books[i].bookPrice);
            printf("Number of book copies: %d\n", books[i].numofCopies);
            break;
        }
    }
    if (!found)
    {
        Name[strlen(Name) - 1] = '\0'; // Remove the newline character when entering ('\n')
        printf("Book with Name %s not found.\n", Name);
    }
}
//5a. Function aim: Count a total number of books the library has
void countBooksofLibrary()
{
    //Buffer to get output from the file
    struct newBook books[100] = {};
    //Open the ouput file
    int k = 0;
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Books.txt", "rt");
    if (fp == NULL)
        printf("Cannot open the record file!\n");
    else
    {
        //Get data from file to buffer
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            fgets(books[k].ISBN, sizeof(books[k].ISBN), fp);
            fgets(books[k].bookName, sizeof(books[k].bookName), fp);
            fgets(books[k].author, sizeof(books[k].author), fp);
            fgets(books[k].publisher, sizeof(books[k].publisher), fp);
            fscanf_s(fp, "%d", &books[k].publicationYear);
            fseek(fp, +2L, SEEK_CUR); // Move to forward 2 steps to ignore the '\n'
            fgets(books[k].genre, sizeof(books[k].genre), fp);
            fscanf_s(fp, "%d\n", &books[k].bookPrice);
            fscanf_s(fp, "%d\n", &books[k].numofCopies);
            k++; // The position of EOF, there are k-1 books existing in the file
        }
        fclose(fp);
    }
    //Total number of books the library has = Total of book copies
    int TotalNumBooks = 0;
    for (int i = 0; i < k; i++)
    {
        TotalNumBooks = TotalNumBooks + books[i].numofCopies;
    }
    printf("The total number of books the library has is: %d", TotalNumBooks);
}
//5b. Function aim: Count a total number of books by Genre
void countBooksByGenre()
{
    //Buffer to get output from the file
    struct newBook books[100] = {};
    //Open the ouput file
    int k = 0;
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Books.txt", "rt");
    if (fp == NULL)
        printf("Cannot open the record file!\n");
    else
    {
        //Get data from file to buffer
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            fgets(books[k].ISBN, sizeof(books[k].ISBN), fp);
            fgets(books[k].bookName, sizeof(books[k].bookName), fp);
            fgets(books[k].author, sizeof(books[k].author), fp);
            fgets(books[k].publisher, sizeof(books[k].publisher), fp);
            fscanf_s(fp, "%d", &books[k].publicationYear);
            fseek(fp, +2L, SEEK_CUR); // Move to forward 2 steps to ignore the '\n'
            fgets(books[k].genre, sizeof(books[k].genre), fp);
            fscanf_s(fp, "%d\n", &books[k].bookPrice);
            fscanf_s(fp, "%d\n", &books[k].numofCopies);
            k++; // The position of EOF, there are k-1 books existing in the file
        }
        fclose(fp);
    }
    for (int i = 0; i < k; i++)
    {
        books[i].genre[strlen(books[i].genre) - 1] = '\0';
    }
    //Define list of genres
    char genre[100][20];
    strcpy_s(genre[0], books[0].genre); // The first genre in the genre list is the first book's genre
    int t = 1; //t is the number of genre
    //Go over the book list to add all kinds of genre into the genre list
    for (int i = 1; i < k; i++) // Go over the book list
    {
        bool newGenre = true;
        for (int j = 0; j < k; j++) // Go over the genre list
        {
            if (strcmp(books[i].genre, genre[j]) == 0) // If the book genre exists in the list of genre, it will not be added in the genre list
            {
                newGenre = false;
                break;
            }
        }
        if (newGenre) //If the book genre doesn't exist in the list of genre, it is added in the genre list
        {
            strcpy_s(genre[t], books[i].genre);
            t = t + 1;
        }
    }
    //Count the number of Book Copies in each Genre
    int numBookbyGenre[100] = {0};
    for (int j = 0; j < t; j++) // Go over the genre list
    {
        for (int i = 0; i < k; i++) // Go over the book list
        {
            //For each genre, find the books of that genre and sum up their copies
            if (strcmp(books[i].genre, genre[j]) == 0)
            {
                numBookbyGenre[j] = numBookbyGenre[j] + books[i].numofCopies;
            }
        }
    }
    //Print the result
    for (int j = 0; j < t; j++)
    {
        printf("The number of book copies in %s genre is: %d\n", genre[j], numBookbyGenre[j]);
    }
}
//5c. Function aim: Count a total number of readers the library has
void countReadersofLibrary()
{
    //Buffer to get output from the file
    struct newReader readers[100] = {};
    //Open the ouput file
    int k = 0;
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Readers.txt", "rt");
    if (fp == NULL)
        printf("Cannot open the record file!\n");
    else
    {
        //Get data from file to buffer
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            fgets(readers[k].readerCode, sizeof(readers[k].readerCode), fp);
            fgets(readers[k].fullName, sizeof(readers[k].fullName), fp);
            fgets(readers[k].idNumber, sizeof(readers[k].idNumber), fp);
            fgets(readers[k].dateofBirth, sizeof(readers[k].dateofBirth), fp);
            fgets(readers[k].gender, sizeof(readers[k].gender), fp);
            fgets(readers[k].email, sizeof(readers[k].email), fp);
            fgets(readers[k].address, sizeof(readers[k].address), fp);
            fscanf_s(fp, "%02d-%02d-%4d", &readers[k].creationDate->Date, &readers[k].creationDate->Month, &readers[k].creationDate->Year);
            fscanf_s(fp, "%02d-%02d-%4d\n", &readers[k].expiryDate->Date, &readers[k].expiryDate->Month, &readers[k].expiryDate->Year);
            k++;
        }
        fclose(fp);
    }
    printf("The number of readers the library has is: %d", k);
}
//5d. Function aim: Count a total number of readers by Gender
void countReadersByGender()
{
    //Buffer to get output from the file
    struct newReader readers[100] = {};
    //Open the ouput file
    int k = 0;
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Readers.txt", "rt");
    if (fp == NULL)
        printf("Cannot open the record file!\n");
    else
    {
        //Get data from file to buffer
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            fgets(readers[k].readerCode, sizeof(readers[k].readerCode), fp);
            fgets(readers[k].fullName, sizeof(readers[k].fullName), fp);
            fgets(readers[k].idNumber, sizeof(readers[k].idNumber), fp);
            fgets(readers[k].dateofBirth, sizeof(readers[k].dateofBirth), fp);
            fgets(readers[k].gender, sizeof(readers[k].gender), fp);
            fgets(readers[k].email, sizeof(readers[k].email), fp);
            fgets(readers[k].address, sizeof(readers[k].address), fp);
            fscanf_s(fp, "%02d-%02d-%4d", &readers[k].creationDate->Date, &readers[k].creationDate->Month, &readers[k].creationDate->Year);
            fscanf_s(fp, "%02d-%02d-%4d\n", &readers[k].expiryDate->Date, &readers[k].expiryDate->Month, &readers[k].expiryDate->Year);
            k++;
        }
        fclose(fp);
    }
    for (int i = 0; i < k; i++)
    {
        readers[i].gender[strlen(readers[i].gender) - 1] = '\0';
    }
    //Define list of Genders
    char gender[100][20];
    strcpy_s(gender[0], readers[0].gender); // The first gender in the gender list is the first reader's gender
    int t = 1; //t is the number of gender
    //Go over the reader list to add all kinds of gender into the gender list
    for (int i = 1; i < k; i++) // Go over the reader list
    {
        bool newGender = true;
        for (int j = 0; j < k; j++) // Go over the gender list
        {
            if (strcmp(readers[i].gender, gender[j]) == 0) // If the reader gender exists in the list of gender, it will not be added in the gender list
            {
                newGender = false;
                break;
            }
        }
        if (newGender) //If the reader gender doesn't exist in the list of gender, it is added in the gender list
        {
            strcpy_s(gender[t], readers[i].gender);
            t = t + 1;
        }
    }
    //Count the number of Readers in each Gender
    int NumReaderbyGender[100] = { 0 };
    for (int j = 0; j < t; j++) // Go over the gender list
    {
        for (int i = 0; i < k; i++) // Go over the reader list
        {
            //For each gender, find the readers with that gender and count them
            if (strcmp(readers[i].gender, gender[j]) == 0)
            {
                NumReaderbyGender[j]++;
            }
        }
    }
    //Print the result
    for (int j = 0; j < t; j++)
    {
        printf("The number of %s readers is: %d\n", gender[j], NumReaderbyGender[j]);
    }
}
//3. Function aim: Creat borrow tickets
void parseBookList(char buffer[128], char book[5][20]) 
{
    char* token;
    char* context = NULL;  // Context pointer for strtok_s
    int book_number = 1; // Track book number within the line

    // Use strtok to split the line based on delimiter (e.g., comma)
    token = strtok_s(buffer, ",", &context);
    int i = 0;
    while (token != NULL) {
        sscanf_s(token, "Book %d: %[^\n]", &book_number, token);
        strcpy_s(book[i], token);
        // Get the next token
        token = strtok_s(NULL, ",", &context);
        book_number++; // Increment book number for next iteration
        i++;
    }
}
void parseReader(char buffer[128], char reader_code[128], char borrow_date[128], char e_return_date[128]) 
{
    sscanf_s(buffer, "Reader Code: %s - Borrow Date: %s - Expected to return: %s", reader_code, borrow_date, e_return_date);
}
void parseISBN(char buffer[128], char ISBN[128], int numOfBorrowed) 
{
    sscanf_s(buffer, "ISBN: %s - Number of Borrowed: %d", ISBN, numOfBorrowed);
}
void addBorrowTicket()
{
    struct borrowTicket newBorowTicket[100] = {};
    struct countISBN_borrowed listISBN[100] = {};

    FILE* fp;
    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\BorrowTickets.txt", "rt");
    if (fp == NULL)
    {
        printf("Cannot open the record file!\n");
        fclose(fp);
    }
    else
    {
        int k = 0;
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            char buffer1[128] = {};//line 1
            char buffer2[128] = {};//line 2
            fgets(buffer1, 128, fp);
            fgets(buffer2, 128, fp);
            parseReader(buffer1, newBorowTicket[k].readerCode, newBorowTicket[k].borrow_date, newBorowTicket[k].expected_return_date);
            parseBookList(buffer2, newBorowTicket[k].listBook);
            k++;
        }
        fclose(fp);
    }

    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\BorrowTickets.txt", "rt");
    if (fp == NULL)
    {
        printf("Cannot open the record file!\n");
        fclose(fp);
    }
    else
    {
        int k = 0;
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            char buffer1[128] = {};
            fgets(buffer1, 128, fp);
            parseISBN(buffer1, listISBN[k].ISBN, listISBN[k].numOfBorrowed);
            k++;
        }
        fclose(fp);
    }

    int n;
    printf("Enter the number of borrow ticket you need to add : ");
    scanf_s("%d", &n);
    getchar();

    for (int i = 0; i < 100; i++)// n <= 100
    {
        if (n == 0) {
            break;
        }
        if (newBorowTicket[i].readerCode[0] == '\0')
        {
            printf("Enter Reader Code: ");
            fgets(newBorowTicket[i].readerCode, 20, stdin);
            newBorowTicket[i].readerCode[strlen(newBorowTicket[i].readerCode) - 1] = '\0';

            printf("Enter date of borrow: ");
            fgets(newBorowTicket[i].borrow_date, 20, stdin);
            newBorowTicket[i].borrow_date[strlen(newBorowTicket[i].borrow_date) - 1] = '\0';

            printf("Enter Expected Return Date: ");
            fgets(newBorowTicket[i].expected_return_date, 20, stdin);
            newBorowTicket[i].expected_return_date[strlen(newBorowTicket[i].expected_return_date) - 1] = '\0';

            printf("Enter number of book to borrow smaller than 5: ");
            int a = 0;
            scanf_s("%d", &a);
            getchar();

            for (int j = 0; j < a; j++)
            {
                printf("Enter book ISBN %d: ", j + 1);
                fgets(newBorowTicket[i].listBook[j], 20, stdin);
                newBorowTicket[i].listBook[j][strlen(newBorowTicket[i].listBook[j]) - 1] = '\0';
                bool found = false;
                for (int k = 0; k < 100; k++) // updating num of borrowed in ISBN list
                {
                    if (strcmp(newBorowTicket[i].listBook[j], listISBN[k].ISBN) == 0)
                    {
                        listISBN[k].numOfBorrowed++;
                        found = true;
                        break;
                    }
                }
                if (!found) { // if not found add ISBN to the list
                    for (int k = 0; k < 100; k++)
                    {
                        if (listISBN[k].ISBN[0] == '\0') {
                            strcpy_s(listISBN[k].ISBN, newBorowTicket[i].listBook[j]);
                            listISBN[k].numOfBorrowed++;
                            found = true;
                            break;
                        }
                    }
                }
            }
            n--;
        }
    }

    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\BorrowTickets.txt", "wt");
    for (int i = 0; i < 100; i++)
    {
        if (newBorowTicket[i].readerCode[0] != '\0') {
            fprintf(fp, "Reader Code: %s - Borrow Date: %s - Expected to return: %s\n", newBorowTicket[i].readerCode, newBorowTicket[i].borrow_date, newBorowTicket[i].expected_return_date);
            for (int j = 0; j < 5; j++)
            {
                fprintf(fp, "Book %d: %s", j + 1, newBorowTicket[i].listBook[j]);
                if (newBorowTicket[i].listBook[j + 1][0] != '\0') {
                    fprintf(fp, ",");
                }
                else {
                    fprintf(fp, "\n");
                    break;
                }
            }
        }
    }
    fclose(fp);

    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\Readers.txt", "at");
    fseek(fp, 0, SEEK_END);
    for (int i = 0; i < 100; i++)
    {
        if (listISBN[i].ISBN[0] != '\0') {
            fprintf(fp, "ISBN: %s - Number of Borrowed: %d\n", listISBN[i].ISBN, listISBN[i].numOfBorrowed);
        }
    }
    fclose(fp);

}
//4. Function aim: Creat return tickets
int daysInMonth(int month)
{
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // from Jan to Dec, days in each month
    return days[month - 1];
}
int daysSinceYearStart(int month, int day) 
{
    int total = 0;
    // Add days from previous months
    for (int i = 0; i < month - 1; i++) {
        total += daysInMonth(i + 1);// month = i + 1 due to rule of index
    }
    // Add current day
    total += day;
    return total;
}
void addReturnTicket()
{
    struct countISBN_borrowed listISBN[100] = {};
    struct returnTicket newTicket[100] = {};
    FILE* fp;

    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\BorrowList.txt", "rt");
    if (fp == NULL)
    {
        printf("Cannot open the record file!\n");
        fclose(fp);
    }
    else
    {
        int k = 0;
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            char buffer1[128] = {};
            fgets(buffer1, 128, fp);
            parseISBN(buffer1, listISBN[k].ISBN, listISBN[k].numOfBorrowed);
            k++;
        }
        fclose(fp);
    }

    int n;
    printf("Enter the number of return ticket you need to add : ");
    scanf_s("%d", &n);
    getchar();

    for (int i = 0; i < 100; i++)// n <= 100
    {
        if (n == 0) {
            break;
        }
        if (newTicket[i].readerCode[0] == '\0')
        {
            printf("Enter Reader Code: ");
            fgets(newTicket[i].readerCode, 20, stdin);
            newTicket[i].readerCode[strlen(newTicket[i].readerCode) - 1] = '\0';

            printf("Enter borrow Date: ");
            scanf_s("%02d-%02d-%4d", &newTicket[i].borrowDate->Date, &newTicket[i].borrowDate->Month, &newTicket[i].borrowDate->Year); // Save user input to buffer

            printf("Enter Return Date (dd-mm-yyyy): ");
            scanf_s("%02d-%02d-%4d", &newTicket[i].date->Date, &newTicket[i].date->Month, &newTicket[i].date->Year); // Save user input to buffer

            newTicket[i].expected_date->Date = newTicket[i].borrowDate->Date + 4;
            newTicket[i].expected_date->Month = newTicket[i].borrowDate->Month;
            newTicket[i].expected_date->Year = newTicket[i].borrowDate->Year;
            if (newTicket[i].expected_date->Date > daysInMonth(newTicket[i].expected_date->Month))
            {
                if (newTicket[i].expected_date->Month + 1 > 12)
                {
                    newTicket[i].expected_date->Year++;
                }
                newTicket[i].expected_date->Date = newTicket[i].expected_date->Date - daysInMonth(newTicket[i].expected_date->Month);
                newTicket[i].expected_date->Month++;
            }
            char input[20];
            getchar();
            printf("Enter Lost(Y) or Return(N): ");
            fgets(input, 20, stdin);
            input[strlen(input) - 1] = '\0';

            if (strcmp(input, "N") == 0 || strcmp(input, "n") == 0)
            {
                int dateDIFF = (newTicket[i].date->Year - newTicket[i].expected_date->Year) * 365 + (daysSinceYearStart(newTicket[i].date->Month, newTicket[i].date->Date)
                    - daysSinceYearStart(newTicket[i].expected_date->Month, newTicket[i].expected_date->Date));
                if (dateDIFF > 0)
                    newTicket[i].late_fee = (dateDIFF) * 5000;
                printf("Enter number of book to return smaller than 5: ");
                int a = 0;
                scanf_s("%d", &a);
                getchar();

                for (int j = 0; j < a; j++)
                {
                    printf("Enter book %d: ", j + 1);
                    fgets(newTicket[i].listBook[j], 20, stdin);
                    newTicket[i].listBook[j][strlen(newTicket[i].listBook[j]) - 1] = '\0';
                }
            }
            if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0)
            {
                printf("Enter number of book lost smaller than 5: ");
                int a = 0;
                scanf_s("%d", &a);
                getchar();

                newTicket[i].late_fee = a * 50000;

                for (int j = 0; j < a; j++)
                {
                    printf("Enter book %d: ", j + 1);
                    fgets(newTicket[i].listBook[j], 20, stdin);
                    newTicket[i].listBook[j][strlen(newTicket[i].listBook[j]) - 1] = '\0';
                    bool found = false;
                    for (int k = 0; k < 100; k++) // updating num of borrowed in ISBN list
                    {
                        if (strcmp(newTicket[i].listBook[j], listISBN[k].ISBN) == 0)
                        {
                            listISBN[k].numOfBorrowed--;
                            found = true;
                            break;
                        }
                    }
                }
            }
            n--;
        }

    }

    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\ReturnTickets.txt", "at");
    fseek(fp, 0, SEEK_END);
    for (int i = 0; i < 100; i++)
    {
        if (newTicket[i].readerCode[0] != '\0') {
            fprintf(fp, "Reader Code: %s - ", newTicket[i].readerCode);
            fprintf(fp, "Borrow Date: %02d-%02d-%4d - ", newTicket[i].borrowDate->Date, newTicket[i].borrowDate->Month, newTicket[i].borrowDate->Year); // Save input to the file as predescribed format
            fprintf(fp, "Expected Return Date: %02d-%02d-%4d - ", newTicket[i].expected_date->Date, newTicket[i].expected_date->Month, newTicket[i].expected_date->Year); // Save input to the file as predescribed format
            fprintf(fp, "Return Date: %02d-%02d-%4d - ", newTicket[i].date->Date, newTicket[i].date->Month, newTicket[i].date->Year); // Save input to the file as predescribed format
            fprintf(fp, "Penalty Fee: %d VND\n", newTicket[i].late_fee);

            for (int j = 0; j < 5; j++)
            {
                fprintf(fp, "Book %d: %s", j + 1, newTicket[i].listBook[j]);
                if (newTicket[i].listBook[j + 1][0] != '\0') {
                    fprintf(fp, ",");
                }
                else {
                    fprintf(fp, "\n");
                    break;
                }
            }
        }
    }
    fclose(fp);

    fopen_s(&fp, "C:\\Users\\Phuong Dung\\source\\repos\\Doan2\\BorrowList.txt", "at");
    fseek(fp, 0, SEEK_END);
    for (int i = 0; i < 100; i++)
    {
        if (listISBN[i].ISBN[0] != '\0') {
            fprintf(fp, "ISBN: %s - Number of Borrowed: %d\n", listISBN[i].ISBN, listISBN[i].numOfBorrowed);
        }
    }
    fclose(fp);
}
//5e. Number of books borrowed
void countBorrowedBooks()
{
    FILE* fp;
    struct countISBN_borrowed listISBN[100] = {};

    fopen_s(&fp, "borrowList.txt", "rt");
    if (fp == NULL)
    {
        printf("Cannot open the record file!\n");
        fclose(fp);
    }
    else
    {
        int k = 0;
        while (k < 100 && !feof(fp)) // Find rows that have inputs in the file
        {
            char buffer1[128] = {};
            fgets(buffer1, 128, fp);
            parseISBN(buffer1, listISBN[k].ISBN, listISBN[k].numOfBorrowed);
            k++;
        }
        fclose(fp);
    }
    int total = 0;
    for (int i = 0; i < 100; i++)
    {
        if (listISBN[i].ISBN[0] != '\0')
        {
            total += listISBN[i].numOfBorrowed;
        }
    }
    printf("The number of borrowed books: %d\n", total);
}