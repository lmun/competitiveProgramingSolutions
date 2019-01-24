#!/usr/bin/python3.6
def aux(lis):
    ma = max(list(map(lambda x: x[0], lis[:-1])))
    mi = min(list(map(lambda x: x[1], lis[:-1])))
    return mi-ma


a = int(input())
li = []
for i in range(a):
    li.append(tuple(map(int, input().split())))
alta = sorted(li, key=lambda x: x[1], reverse=True)
alta = sorted(alta, key=lambda x: x[0])
altb = sorted(li, key=lambda x: x[0])
altb = sorted(altb, key=lambda x: x[1], reverse=True)
res = max(aux(alta), aux(altb))
if res < 0:
    res = 0
print(res)
