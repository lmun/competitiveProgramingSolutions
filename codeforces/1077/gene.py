from random import randrange
li = [randrange(10**4) for i in range(10**5)]
print(len(li))
print(' '.join(map(str, li)))
