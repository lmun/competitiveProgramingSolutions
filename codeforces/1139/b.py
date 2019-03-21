a = int(input())
co = [int(x) for x in input().split()]
last = 10**10
res = 0
# print(co)
for c in reversed(co):
	# print(res, c)
	last = max(min(c, last-1), 0)
	res += last
	# print(res)
	# last = c
print(res)