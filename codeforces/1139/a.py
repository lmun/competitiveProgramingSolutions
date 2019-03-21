input()
print(sum(i if ord(c)%2 == 0 else 0 for i,c in enumerate(input().strip(), 1)))
