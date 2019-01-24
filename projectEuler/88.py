l = int(input())+1
mins = [0]*l


def calcu(a, b, c, d):  # a mult,b sum,c max,d total
    global l
    if a - b + d >= l:
        return
    # print(a-b+d,a,d)
    if d > 1:
        mins[a-b+d] = a if mins[a-b+d] == 0 else min(a, mins[a-b+d])
    for i in range(l):
        x = i+c
        if x*(a-b) > l:
            break
        calcu(a*x, b+x, x, d+1)


for i in range(2, 1000):
    calcu(i, i, i, 1)
"""
mama = 0
for i in range(l):
    if mins[i]-i >= mama:
        print(i, mins[i], mins[i]-i)
        mama = mins[i]-i
"""
print(sum(set(mins[2:])))
