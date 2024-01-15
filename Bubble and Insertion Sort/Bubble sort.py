def bubble_sort_books(book_list):
    n = len(book_list)

    for i in range(n):
        for j in range(0, n - i - 1):
            if book_list[j]["book_id"] > book_list[j + 1]["book_id"]:
                temp = book_list[j]
                book_list[j] = book_list[j + 1]
                book_list[j + 1] = temp

books = [
    {"book_id": 103, "title": "Book C", "author": "Author C", "quantity": 5},
    {"book_id": 101, "title": "Book A", "author": "Author A", "quantity": 3},
    {"book_id": 102, "title": "Book B", "author": "Author B", "quantity": 8},
]

bubble_sort_books(books)


print("Books after Bubble Sort:")
for book in books:
    print(book)
