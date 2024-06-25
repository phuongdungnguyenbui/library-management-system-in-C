#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "Doan1header.h"

int main()
{
    // du lieu nhap san
    const int size = 100;
    char readers[100][9][50] = { {"01AX","Nguyen Bui Phuong Dung", "079301007265", "24-01-2001","Female","dung.ngbp@gmail.com","220 XVNT, W.21, Binh Thanh Dis, HCMC, Vietnam","20-04-2023","20-04-2027"} };
    char newReader[9][50] = { "Reader code", "Full name", "ID number", "Date of birth", "Gender", "Email", "Address", "Creation date", "Expiry date" };

    char books[100][8][50] = { {"604993780X", "Sans Family", "Hector Malot", "Van Hoc", "2020", "Fiction", "2", "80"} };
    char newBook[8][50] = { "ISBN (book code)", "Book name", "Author", "Publisher", "Publication year", "Genre", "Self number", "No.of copies" };

    char borrowform[100][14][50] = { {"01AX","21-04-2024","21-04-2024","604993780X"} };
    char returnform[100][14][50] = { {"01AX","21-04-2024","21-04-2024","29-04-2024","604993780X"} };
    char listISBN[100][2][50] = { {"01AX","Returned"} };
    char status[2][50] = { "Borrowed","Returned" };

    char Genre[4][20] = { "Poetry", "Fiction", "Nonfiction", "Drama" };
    int totalBooksbyGenre[4] = { 0 };
    char Gender[3][20] = { "Male", "Female", "LGBTIQA+" };
    int totalReadersbyGender[3] = { 0 };

    int inquiry = 0;
    // chuong trinh quan ly thu vien duoc the hien duoi dang menu
    do {
        printf("\nLibrary Management System has the following functions: \n");
        printf("1. View list of readers\n");
        printf("2. Add a reader\n");
        printf("3. Modify a reader's information\n");
        printf("4. Delete a reader's information\n");
        printf("5. Search for a reader by ID number\n");
        printf("6. Search for a reader by Full name\n");
        printf("7. View list of books\n");
        printf("8. Add a book\n");
        printf("9. Modify a book's information\n");
        printf("10. Delete a book's information\n");
        printf("11. Search for a book by ISBN\n");
        printf("12. Search for a book by Name\n");
        printf("13. Fill in a book borrow form \n");
        printf("14. Fill in a book return form\n");
        printf("15. Count total number of books the library has\n");
        printf("16. Count total number of books by Genre\n");
        printf("17. Count total number of readers the library has\n");
        printf("18. Count total number of readers by Gender\n");
        printf("19. Count total number of books in borrowed\n");
        printf("20. View list of Count total number of books in borrowed\n");
        printf("21. List readers who are late in returning books\n");
        printf("22. Exit\n");
        printf("Enter your inquiry by number from 1 to 22, depending on your need: ");
        scanf_s("%d", &inquiry);
        getchar(); // Dung lai de nhap

        switch (inquiry) {
        case 1:
        {
            // xem danh sach doc gia trong thu vien
            viewReaderList(readers, size);
            break;
        }
        case 2:
        {
            // them doc gia
            addReader(readers, size);
            break;
        }
        case 3:
        {
            // chinh sua thong tin 1 doc gia
            modifyReader(readers, size);
            break;
        }
        case 4:
            // xoa thong tin 1 doc gia
            deleteReader(readers, size);
            break;
        case 5:
            // tim kiem doc gia theo CMND
            searchReaderById(readers, size);
            break;
        case 6:
            // tim kiem doc gia theo ho ten
            searchReaderByName(readers, size);
            break;
        case 7:
            // xem danh sach cac sach trong thu vien
            viewBookList(books, size);
            break;
        case 8:
            // them sach
            addBook(books, size);
            break;
        case 9:
            // chinh sua thong tin 1 quyen sach
            modifyBook(books, size);
            break;
        case 10:
            // xoa thong tin sach
            deleteBook(books, size);
            break;
        case 11:
            // tim kiem sach theo ISBN
            searchBookByISBN(books, size);
            break;
        case 12:
            // tim kiem sach theo ten sach
            searchBookByName(books, size);
            break;
        case 13:
            // lap phieu muon sach
            createBorrowForm(borrowform, size, listISBN);
            break;
        case 14:
            // lap phieu tra sach
            createReturnForm(returnform, size, listISBN);
            break;
        case 15:
            // thong ke so luong sach trong thu vien
            countBooksofLibrary(books, size);
            break;
        case 16:
            // thong ke so luong sach theo the loai
            countBooksByGenre(books, size);
            break;
        case 17:
            // thong ke so luong doc gia
            countReadersofLibrary(readers, size);
            break;
        case 18:
            // thong ke so luong doc gia theo gioi tinh
            countReadersByGender(readers, size);
            break;
        case 19:
            // thong ke so sach dang duoc muon
            countBooksinBorrowed(listISBN, size);
            break;
        case 20:
            // xem danh sach phieu muon
            viewListBorrowBook(borrowform, size);
            break;
        case 21:
            // xem danh sach phieu tra
            viewListReturnBook(returnform, size);
            break;
        case 22:
            // thoat chuong trinh
            printf("Exit\n");
            break;
        default:
            // nhap sai, can nhap lai
            printf("Invalid inquiry. Please enter a number between 1 and 22.\n");
            break;
        }
    } while (inquiry != 22); // chi nhap so 22 moi co the thoat chuong trinh

    return 0;
}