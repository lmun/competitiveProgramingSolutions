from sys import stdin
"""def ispandi(n):
    #print(n)
    nums=[0]*11
    for c in n:
        nums[int(c)]+=1
    i=1
    while nums[i]==1:
        i+=1
    return i==10
nums=[]
for line in stdin:
    nums.append(int(line))

l=50000000
fibo=[0]*l
fibo[1]=1
fibo[2]=1
fobo=[0]*l
fobo[1]=1
fobo[2]=1
n=0
wa=10**100
for i in range(3,l):
    #fibo[i]=(fibo[i-1]+fibo[i-2])
    fobo[i]=(fobo[i-1]+fobo[i-2])
    #esp=str(fibo[i])
    #print(i,esp)
    if fobo[i]>wa:
        #print(fobo[i])
        fobo[i]//=100
        fobo[i-1]//=100
    if nums[n]==i:
        #print(esp[:15])
        #print(str(fobo[i]))
        if ispandi(str(fobo[i])[:9]):
            print(i)
        n+=1
        #print(n)
"""
print(int('-'))
