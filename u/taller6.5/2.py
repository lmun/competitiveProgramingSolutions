#!/usr/bin/python3.5
while True:
    try:
        n=int(input())
        s=list()
        for _ in range(n):
        	x,y=map(int,input().split())
        	s.append((x,y))
        s.sort(key=lambda x:x[1])
        s.sort(key=lambda x:x[0])
        x,y=0,11*10**9
        t=1
        for a,b in s:
        	if a > y:
        		t+=1
        		x,y=a,b
        	x=max(x,a)
        	y=min(y,b)
        print(t)
    except EOFError:
        break