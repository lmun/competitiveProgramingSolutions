n = int(input())
res = 0
for i in reversed(range(n)):
	c = input().strip()
	if c == 'O':
		res |= (1<<i)
print(res)
print((1<<n)-res)