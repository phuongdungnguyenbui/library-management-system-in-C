// Doan2 main.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "Doan2header.h"
int main()
{
    int inquiry = 0;
    // chuong trinh quan ly thu vien duoc the hien duoi dang menu
    do {
        printf("\nLibrary Management System has the following functions: \n");
        printf("1. View list of readers\n");
        printf("2. Add one or more readers\n");
        printf("3. Modify a reader's information by choice\n");
        printf("4. Delete a reader\n");
        printf("5. Search for a reader by ID number\n");
        printf("6. Search for a reader by Full name\n");
        printf("7. View list of books\n");
        printf("8. Add one or more books\n");
        printf("9. Modify a book's information by choice\n");
        printf("10. Delete a book\n");
        printf("11. Search for a book by ISBN\n");
        printf("12. Search for a book by Name\n");
        printf("13. Fill in book borrow tickets \n");
        printf("14. Fill in book return tickets\n");
        printf("15. Count total number of books the library has\n");
        printf("16. Count total number of books by Genre\n");
        printf("17. Count total number of readers the library has\n");
        printf("18. Count total number of readers by Gender\n");
        printf("19. Count total number of books in borrowed\n");
        printf("20. Exit\n");
        printf("Enter your inquiry by number from 1 to 20, depending on your need: ");
        scanf_s("%d", &inquiry);
        getchar(); // Dung lai de nhap

        switch (inquiry)
        {
        case 1:
            // xem danh sach doc gia trong thu vien
            viewReaderList();
            break;
        case 2:
            // them doc gia
            addReader();
            break;
        case 3:
            // chinh sua thong tin 1 doc gia
            modifyReader();
            break;
        case 4:
            // xoa thong tin 1 doc gia
            deleteReader();
            break;
        case 5:
            // tim kiem doc gia theo CMND
            searchReaderbyID();
            break;
        case 6:
            // tim kiem doc gia theo ho ten
            searchReaderbyName();
            break;
        case 7:
            // xem danh sach cac sach trong thu vien
            viewBookList();
            break;
        case 8:
            // them sach
            addBook();
            break;
        case 9:
            // chinh sua thong tin 1 quyen sach
            modifyBook();
            break;
        case 10:
            // xoa thong tin 1 quyen sach
            deleteBook();
            break;
        case 11:
            // tim kiem sach theo ISBN
            searchBookbyISBN();
            break;
        case 12:
            // tim kiem sach theo ten sach
            searchBookbyName();
            break;
        case 13:
            // lap phieu muon sach
            addBorrowTicket();
            break;
        case 14:
            // lap phieu tra sach
            addReturnTicket();
            break;
        case 15:
            // thong ke so luong sach trong thu vien
            countBooksofLibrary();
            break;
        case 16:
            // thong ke so luong sach theo the loai
            countBooksByGenre();
            break;
        case 17:
            // thong ke so luong doc gia
            countReadersofLibrary();
            break;
        case 18:
            // thong ke so luong doc gia theo gioi tinh
            countReadersByGender();
            break;
        case 19:
            // thong ke so sach dang duoc muon
            countBorrowedBooks();
            break;
        default:
            // nhap sai, vui long nhap lai
            printf("Invalid inquiry. Please enter a number between 1 and 20.\n");
            break;
        }
    } while (inquiry != 20); // chi nhap so 20 moi co the thoat chuong trinh
    return 0;
}

