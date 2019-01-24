res = 0
rl = set()
for i in range(1, 10000):
    r = i*i
    for j in range(1, 10000):
        r += ((i+j)**2)
        if r > 10**8:
            break
        rstr = str(r)
        if rstr[::-1] == rstr:
            # print(rstr)
            res += r
            rl.add(r)

print(res)
print(sum(rl))
