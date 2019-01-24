wa = int(input())
a = 1
n = wa-3
l = list()
for i in range(1, wa):
    l.append(1)
    l.append(2*i)
    l.append(1)
if wa > 1:
    b = l[n+1]
else:
    print(2)
    exit(0)
while n >= 0:
    aux = b
    b = a+l[n]*b
    a = aux
    n -= 1
    # print(a, b)
# print(a+b+b, b)
res = 0
for ch in str(a+b+b):
    res += int(ch)
print(res)
