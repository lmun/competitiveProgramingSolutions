books = [int(input()) for _ in range(int(input()))]
books.sort(reverse=True)
print(sum(b if a % 3 != 2 else 0 for a, b in enumerate(books)))
