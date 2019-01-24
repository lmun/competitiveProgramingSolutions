m = 6*10**4+1
mod = 10**9
pent = [0]*m
part = [0]*m
part[0] = 1

ttt = m
for x in range(1, ttt):
    # print(wa-1, end=" ")
    # print(x//2, x % 2)
    p = x//2*((-1)**(x % 2))
    # print((3*p*p-p)//2)
    pent[x] = (3*p*p-p)//2
    if pent[x] > m:
        print(x, pent[x])
        break

for i in range(1, ttt):
    steval = part[i-1]
    j = 3
    while True:
        if pent[j] > i:
            break
        # print(i, part[i-pent[j]], ((-1)**(((j//2) % 2)+1)))
        steval += part[i-pent[j]]*((-1)**(((j//2) % 2)+1))
        j += 1
    steval %= mod
    part[i] = steval
for _ in range(int(input())):
    print(part[int(input())])
