#pragma once
//The reader's information needed to manage:
struct time
{
    int Date;
    int Month;
    int Year;
};

struct newReader
{
    char readerCode[20];
    char fullName[50];
    char idNumber[20];
    char dateofBirth[20];
    char gender[10];
    char email[50];
    char address[50];
    struct time creationDate[20];
    struct time expiryDate[20];
};

struct newBook
{
    char ISBN[20];
    char bookName[50];
    char author[50];
    char publisher[50];
    int publicationYear;
    char genre[20];
    int bookPrice;
    int numofCopies;
};

struct borrowTicket
{
    char readerCode[20] = "";
    char borrow_date[20];
    char expected_return_date[20];
    char listBook[5][20];
};
struct returnTicket
{
    char readerCode[20] = "";
    struct time borrowDate[20];
    struct time expected_date[20];
    struct time date[20];
    char listBook[5][20];
    int late_fee = 0;
};

struct countISBN_borrowed
{
    char ISBN[20] = "";
    int numOfBorrowed = 0;
};
// Function prototypes
void viewReaderList();
void addReader();
void modifyReader();
void deleteReader();
void searchReaderbyID();
void searchReaderbyName();
void viewBookList();
void addBook();
void modifyBook();
void deleteBook();
void searchBookbyISBN();
void searchBookbyName();
void countBooksofLibrary();
void countBooksByGenre();
void countReadersofLibrary();
void countReadersByGender();
void parseBookList(char buffer[128], char book[5][20]);
void parseReader(char buffer[128], char reader_code[128], char borrow_date[128], char e_return_date[128]);
void parseISBN(char buffer[128], char ISBN[128], int numOfBorrowed);
void addBorrowTicket();
int daysInMonth(int month);
int daysSinceYearStart(int month, int day);
void addReturnTicket();
void countBorrowedBooks();