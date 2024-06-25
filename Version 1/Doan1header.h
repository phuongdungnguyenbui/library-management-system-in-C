#pragma once
// Function prototypes
void viewReaderList(char(*readers)[9][50], int size);
void addReader(char(*readers)[9][50], int size);
void modifyReader(char(*readers)[9][50], int size);
void deleteReader(char(*readers)[9][50], int size);
void searchReaderById(char(*readers)[9][50], int size);
void searchReaderByName(char(*readers)[9][50], int size);
void viewBookList(char(*books)[8][50], int size);
void addBook(char(*books)[8][50], int size);
void modifyBook(char(*books)[8][50], int size);
void deleteBook(char(*books)[8][50], int size);
void searchBookByISBN(char(*books)[8][50], int size);
void searchBookByName(char(*books)[8][50], int size);
void createBorrowForm(char(*borrowform)[14][50], int size, char(*listISBN)[2][50]);
void viewListBorrowBook(char(*borrowform)[14][50], int size);
void createReturnForm(char(*returnform)[14][50], int size, char(*listISBN)[2][50]);
void viewListReturnBook(char(*returnform)[14][50], int size);
void countBooksofLibrary(char(*books)[8][50], int size);
void countBooksByGenre(char(*books)[8][50], int size);
void countReadersofLibrary(char(*readers)[9][50], int size);
void countReadersByGender(char(*readers)[9][50], int size);
void updateListISBN(char(*listISBN)[2][50], int size, char(*books)[8][50]);
void updateISBN_Status(char(*listISBN)[2][50], char(*ISBN), int statusCode);
void countBooksinBorrowed(char(*listISBN)[2][50], int size);