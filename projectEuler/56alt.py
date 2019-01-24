#!/usr/bin/env python3.5
def calc_googol(a_to, b_to):
    max_sum = 0
    for a in range(1, a_to):
        for b in range(1, b_to):
            num = a**b
            sum_of_digits = sum(int(x) for x in str(num))
            if sum_of_digits > max_sum:
                max_sum = sum_of_digits
    return max_sum

if __name__ == '__main__':
    print(calc_googol(101, 101))