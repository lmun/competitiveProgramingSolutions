from itertools import permutations
n = int(input())
lamps = input().strip()
per = list(permutations("RGB"))
counts = [0]*6
for i, l in enumerate(lamps):
	for j in range(6):
		counts[j] += 0 if per[j][i%3]==l else 1
re = min(counts)
for i, co in enumerate(counts):
	if co == re:
		resp = per[i]*(2+n//3)
		break
print(re)
print("".join(resp)[:n])