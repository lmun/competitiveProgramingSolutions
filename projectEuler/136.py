from itertools import count
"""(x+2a)**2 -(x+a)**2 - x**2 = n
 +4ax + 4a2  - 2xa - a2 
-x2 + 2ax +3a2
"""


def main():
    popo = 1
    fif = 5*10**7
    # fif = 100
    fifarr = [0]*fif
    lama = False
    lahi = 0
    for x in count(1):
        lo, hi = 1, 1
        while 2*hi*x+3*hi*hi-x*x <= 0:
            hi *= 2
        while hi > lo:
            mid = (lo+hi)//2
            if 2*mid*x+3*mid*mid-x*x <= 0:
                lo = mid+1
            else:
                hi = mid
        if x == popo:
            print(x, hi, 2*hi*x+3*hi*hi-x*x)
            popo *= 2
        # if x % 10**6 == 0:
        #     print('tata',sum(1 for f in fifarr if f == 1))
        # print(hi, x, 2*hi*x+3*hi*hi-x*x)
        if 2*hi*x+3*hi*hi-x*x >= fif:
            if lama and lahi < hi:
                print(f'breaking on {hi} {x} {2*hi*x+3*hi*hi-x*x}')
                break
            lama = True
        else:
            lama = False
        lahi = hi
        for a in count(hi):
            ne = 2*a*x+3*a*a-x*x
            if ne >= fif:
                break
            try:
                fifarr[ne] += 1
                pass
            except Exception as e:
                print(x, a, ne)
                raise e
    # co = 1
    # for a, b in enumerate(fifarr):
    #     if b == 1:
    #         print(co, a)
    #         co += 1
    #         if co > 26:
    #             break
    re = sum(1 for f in fifarr if f == 1)
    print(re)
    return re


if __name__ == '__main__':
    try:
        a = main()
        print('-', a)
    except Exception as e:
        raise print(e)
    else:
        pass
# print(sum(1 for f in fifarr if f==1))
