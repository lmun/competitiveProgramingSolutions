from sys import stdin
from itertools import combinations
res = 0
for line in stdin:
    nums = [int(x) for x in line.strip().split(',')]
    se = {0}
    for i in range(1, len(nums)):
        su = {sum(comb) for comb in combinations(nums, i)}
        if max(se) > min(su):
            break
        se |= su
    else:
        if 2**len(nums)-len(se) == 1:
            res += sum(nums)
print(res)
