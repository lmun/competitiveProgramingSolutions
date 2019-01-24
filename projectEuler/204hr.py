#!/bin/python3

import sys
prims=[]
res=0
def generalisedHammingNumbers(n, k, x, a):
	global res
	res+=1
	for b in range(a,len(prims)):
		if x*prims[b] > n:
			break
		generalisedHammingNumbers(n,k,x*prims[b],b)
n, k = input().strip().split(' ')
n, k = [int(n), int(k)]
criba=[True]*200
for i in range(2,200):
	if criba[i] and i <= k:
		prims.append(i)
		for j in range(i*i,200,i):
			criba[j]=False
generalisedHammingNumbers(n, k, 1, 0)
print(res)
