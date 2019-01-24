def ispandi(n, k):
    nums = [0]*11
    for c in n:
        nums[int(c)] += 1
    i = 1
    while nums[i] == 1:
        i += 1
    return i == k


l = 2000001
# l = 20000
fibo = [0]*l
# fibof = [0]*l
fobo = [0]*l
a = int(input())
b = int(input())
k = int(input())
fibo[1] = a
fibo[2] = b
# fibof[1] = a
# fibof[2] = b
fobo[1] = a
fobo[2] = b
waa = 10**20
mod = 10**12
for i in range(3, l):
    fibo[i] = (fibo[i-1]+fibo[i-2]) % mod
    # fibof[i] = float(fibof[i-1] + fibof[i-2])
    fobo[i] = fobo[i-1]+fobo[i-2]
    if fobo[i] > waa:
        fobo[i] //= 10
        fobo[i-1] //= 10
    # print('{:1.0f}'.format(fibof[i])[:9])
    # print(str(fobo[i])[:9])
    esp = str(fibo[i])
    # print(i,esp)
    # if ispandi(('{:1.0f}'.format(fibof[i])[:k]).strip(), k+1):
        # print(('{:1.0f}'.format(fibof[i])[:k]))
    # if ispandi(esp[-k:], k+1) and ispandi(('{:1.0f}'.format(fibof[i])[:k]).strip(), k+1):
    if ispandi(esp[-k:], k+1) and ispandi(str(fobo[i])[:k], k+1):
        print(i)
        break
else:
    print("no solution")
