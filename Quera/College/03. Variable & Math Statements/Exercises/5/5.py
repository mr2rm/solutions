n = int(input())
m = n // 2
x = m * (m + 1)
y = (1 - n % 2) * m
print((x - y) / (n + 1))
