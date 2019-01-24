n, k = map(int, input().split())
nums = n+100
cri = [0]*nums
for i in range(2, nums):
    if cri[i] == 0:
        # pri.append(i)
        for j in range(i*2, nums, i):
            cri[j] += 1
for i in range(nums):
    # if cri[i]==4 and cri[i+1]==4 and cri[i+2]==4 and cri[i+3]==4:
    if cri[i] == k and all(cri[i+p] == cri[i+p+1] for p in range(k-1)):
        print(i)
        break
