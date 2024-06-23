# library-management-system-in-C
**C project for CSC10001 Course.**

# Introduction
This project is the Library Management System written in C language. It allows users to choose one of the existing functions to handle, update, count and list all the details about Library Cards, Books, and Book Borrowing & Returning Tickets.

This project is the individual final project of the CSC10001 Course (VNG-HCMUS) created by Nguyen Bui Phuong Dung - school year 2023.12 - 2026.07. 

This project has 2 versions: the first allows information to be saved in the console cache, and the second saves information in text files.

# Content
Details of information are:
1. A Library Card's information includes reader code, full name, ID card number, date of birth, gender, email, address, creation date, and expiration date (48 months from the creation date).
2. Book information includes ISBN (book code), book title, author, publisher, year of publication, genre, book price, and number of copies.
3. A Book Borrowing Ticket contains reader code, borrowing date, expected return date, actual return date, and list of ISBNs borrowed. Each book can be borrowed for a maximum of 7 days. If a book is returned after 7 days, there will be a 5,000 VND/day fine. If a book is lost, the reader will be fined an amount equivalent to 200% of the book's price. 
4. A Book Returning Ticket contains reader code, borrowing date, actual return date, list of ISBNs returned, and fines for lost books or late returns.

The user can choose to perform the following functions in the shown Menu:

_Functions related to Library Cards:_
View a list of existing readers; Add a new reader; Edit information of an existing reader; Remove a reader; Search a reader by ID card number; Search a reader by full name; Count the total number of readers the library has; Count the total number of readers by gender; View a list of readers that return at least a book after 7 days; Import/ Export readers' information from/to a text file (for 2nd version).

_Functions related to Books:_
View a list of existing books; Add a new book; Edit information of an existing book; Remove a book; Search a book by ISBN; Search a book by book title; Count the total number of books the library has; Count the total number of books by genre; Count the total of books in borrowed; Import/Export books' information from/to a text file (for 2nd version).

_Functions related to Book Borrowing & Returning Tickets:_
View lists of Book Borrowing Tickets and Book Returning Tickets separately.

All changes are saved in the console cache or text files.
