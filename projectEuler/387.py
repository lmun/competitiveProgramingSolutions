primes = []
m = 10 ** 8
criba = [0] * m
criba[1] = 1
for i in range(2, m):
    if criba[i] == 0:
        primes.append(i)
        criba[i] = i
        for j in range(i * i, m, i):
            criba[j] = i

print(f"total primes: {len(primes)}")


def is_prime(n):
    if n < m:
        return criba[n] == n
    for i in primes:
        if i * i > n:
            break
        if n % i == 0:
            return False
    else:
        print("me pase")
    return True


limi = 10 ** 14


def test_hardshan(n):
    if n > limi:
        return 0
    sudi = sum(int(i) for i in str(n))
    if n % sudi != 0:
        return 0
    # is hardshan
    res = 0
    if (n // sudi) > 1 and is_prime(n // sudi):
        for i in range(10):
            if n * 10 + i < limi and is_prime(n * 10 + i):
                # print(n, n * 10 + i)
                res += n * 10 + i
    for i in range(10):
        res += test_hardshan(n * 10 + i)
    return res


def main():
    print(sum(test_hardshan(i) for i in range(1, 10)))


if __name__ == "__main__":
    main()
