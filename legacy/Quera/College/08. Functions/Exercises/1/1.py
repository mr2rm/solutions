def is_prime(n):
    if n < 2 or (n != 2 and n % 2 == 0):
        return False
    for x in range(3, int(n**0.5) + 1, 2):
        if n % x == 0:
            return False
    return True

def count_primes(n):
    primes = list(filter(is_prime, range(1, n)))
    return len(primes)

def count_prime_factors(n):
    cnt = 0
    for x in range(1, int(n**0.5) + 1):
        if n % x == 0:
            cnt += int(is_prime(x))
            y = n // x;
            if y != x:
                cnt += int(is_prime(y))
    return cnt

def calculate_value(n):
    if is_prime(n):
        return count_primes(n)
    return count_prime_factors(n)
    

n, res = int(input()), 0
for _ in range(n):
    x = int(input())
    res += calculate_value(x)
res -= calculate_value(res)
print(res)
