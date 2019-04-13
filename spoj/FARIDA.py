for t in range(int(input())):
        n = int(input())
        li = [int(x) for x in input().split()]
        if n > 1 and li[0] > li[1]:
                li[1] = li[0]
        for i in range(2, n):
                li[i] += li[i-2]
                if li[i-1] > li[i]:
                        li[i] = li[i-1]
        print("Case {}: {}".format(t+1, li[-1]))
