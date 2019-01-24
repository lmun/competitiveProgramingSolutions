from math import *
x,y=map(int,input().split())
eve=""
if x==y:
	if x==0:
		print("Not a moose")
		exit(0)
	eve="Even"
else:
	eve="Odd"
print(eve,2*max(x,y))