n=int(input())
s=list(map(int,input().split()))
s.sort()
print(sum(s[i+1]-s[i] for i in range(0,n,2)))
