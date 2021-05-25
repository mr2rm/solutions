n = int(input())

# while n >= 10:
#     s = 0
#     while n:
#         s += n % 10
#         n //= 10
#     n = s

n %= 9;
if n == 0:
    n = 9

print(n)
