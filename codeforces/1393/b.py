from collections import Counter
n = int(input())
planks = Counter(int(x) for x in input().split())
tengo = [0]*10
for a, b in planks.items():
	if b<10:
		tengo[b]+=1
	else:
		tengo[9]+=1

for i in range(1,10):
	tengo[i]+=tengo[i-1]
for q in range(int(input())):
	a, b = input().split()
	b = int(b)
	if a=='-':
		planks[b] -= 1
		if planks[b]<10:
			tengo[planks[b]]+=1
	else:
		if planks[b] < 10:
			tengo[planks[b]]-=1
		planks[b] += 1
	if tengo[9]-tengo[7]>0:
		print("YES")
	elif tengo[9]-tengo[5]>0 and tengo[9]-tengo[1]>1:
		print("YES")
	elif tengo[9]-tengo[3]>0 and (tengo[9]-tengo[3]>1 or tengo[9]-tengo[1]>2):
		print("YES")
	else:
		print("NO")
