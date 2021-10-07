m = 12*10**6
cri = [False]*m
pri = []
for i in range(2,m):
  if not cri[i]:
    cri[i] = True
    pri.append(i*i)
    for j in range(i*i,m,i):
      cri[j] = True
se = set()
n = 51
cu = [1]
for i in range(1,n):
  cu = [a+b for a,b in zip([0]+cu,cu+[0])]
  # print(max(cu))
  se.update(cu)
res = sum(se)
for a in se:
  for p in pri:
    if p > a:
      break
    if a % p == 0:
      res -= a
      break
  else:
    print('aaaa')
print(res)