li = []
la = [0]*200
lb = [0]*200
for i in range(1, 21):
    li.append(i)
    li.append(2*i)
    li.append(3*i)
    la[i] += 1
    la[2*i] += 1
    la[3*i] += 1
li.append(25)
li.append(50)
la[25] += 1
la[50] += 1
li.sort()

for i in range(len(li)):
    for j in range(i+1):
        # print(li[i]+li[j])
        lb[li[i]+li[j]] += 1

tot = 0
for yy in range(2, 100):
    r = 1 if ((yy % 2 == 0 and yy <= 40) or yy == 50) else 0
    for wa in range(2, 41, 2):
        if wa > yy:
            break
        r += la[yy-wa]
        r += lb[yy-wa]
    if yy >= 50:
        r += la[yy-50]
        r += lb[yy-50]
    # print(yy, r)
    tot += r
print(tot)
