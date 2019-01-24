ma = 1
mb = 3
for i in range(1000001, 0, -1):
    if i % 7 == 0:
        continue
    n = (i*3)//7
    if n*mb > ma*i:
        ma = n
        mb = i
        print(n, i)
print(ma, mb)
