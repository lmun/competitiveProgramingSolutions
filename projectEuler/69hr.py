m=1000001
cri=[0]*m
pri=list()
for i in range(2,m):
    if cri[i]==0:
        cri[i]=i
        pri.append(i)
        for j in range(i*i,m,i):
            cri[j]=i
for j in range(100):
    r=1
    ra=1
    for i in range(j):
        r*=pri[i]
        ra*=(pri[i]-1)

    print(r/ra)