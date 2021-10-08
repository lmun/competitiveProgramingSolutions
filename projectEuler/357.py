m = 10**8+1
cri = [0]*m
pri = []
for i in range(2,m):
  if cri[i] != 0:
    continue
  pri.append(i)
  cri[i] = i
  for j in range(i*i,m,i):
    cri[j] = i

def getFactors(n):
  a = n
  res = {1}
  while a>1:
    div = cri[a]
    nu=0
    while a%div==0:
      res = res | set(r*div for r in res)
      nu+=1
      a//=div
  return res
def isPrime(nu):
  if nu < m:
    return cri[nu] == nu
  for p in pri:
    if nu % p ==0:
      return False
  return True
susu = 0
for i in range(1,m):
  if all(isPrime(x+i//x) for x in getFactors(i)):
    susu+=i
print(susu)
