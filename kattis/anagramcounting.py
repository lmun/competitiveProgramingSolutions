from sys import stdin
from collections import Counter
fact = [1]*110
for i in range(1, 110):
	fact[i] = i*fact[i-1]
for line in stdin:
	res = 1
	for i in Counter(line.strip()).values():
		res *= fact[i]
	print(fact[len(line.strip())] // res)
