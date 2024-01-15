def insertion_sort_books(book_list):
    for i in range(1, len(book_list)):
        current_book = book_list[i]
        j = i - 1

        while j >= 0 and current_book["book_id"] < book_list[j]["book_id"]:
            book_list[j + 1] = book_list[j]
            j -= 1

        book_list[j + 1] = current_book


books = [
    {"book_id": 103, "title": "Book C", "author": "Author C", "quantity": 5},
    {"book_id": 101, "title": "Book A", "author": "Author A", "quantity": 3},
    {"book_id": 102, "title": "Book B", "author": "Author B", "quantity": 8},
]

insertion_sort_books(books)

print("Books after Insertion Sort:")
for book in books:
    print(book)
