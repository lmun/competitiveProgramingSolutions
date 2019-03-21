n=int(input())
s = input().strip()
res = 0
for i, c in enumerate(s):
	if ord(c)%2 == 0:
		res += 1+i
print(res)