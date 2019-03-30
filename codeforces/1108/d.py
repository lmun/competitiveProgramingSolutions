from itertools import permutations
def difi(a, b):
	if a != 'R' and b!= 'R':
		return 'R'
	if a!='G' and b!= 'G':
		return 'G'
	return 'B'

n = int(input())
lamps = list(input().strip())
res = 0
for i in range(1, n-1):
	if lamps[i] == lamps[i-1]:
		lamps[i] = difi(lamps[i+1], lamps[i-1])
		res += 1
if n > 1:
	if lamps[-1] == lamps[-2]:
		lamps[-1] = difi(lamps[-2],lamps[-2])
		res += 1
print(res)
print("".join(lamps))