m=100000001
cri=[0]*m
for i in range(2,m):
    if cri[i]==0:
        cri[i]=i
        for j in range(i*i,m,i):
            cri[j]=i
print("criba lista")
def toti(n):
    t=1
    while n > 1:
        d=cri[n]
        c=0
        while n%d==0:
            n//=d
            c+=1
        t*=(d-1)*(d**(c-1))
    return t

a=15499
b=94744
minr=float(1.0)
for i in range(2,m):
    t=toti(i)
    er=t/float(i-1)
    if er<minr:
        print(i,t,i-1,er)
        minr=er
    if t*b<(i-1)*a:
        print(i,t,i/t)
        break