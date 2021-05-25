l, r = map(int, input().split())
s = '1'

# while len(s) < r:
#     s += ''.join(map(lambda x: str(1 - int(x)), s))
# print(s[l-1:r])

i, size = 0, 1
while len(s) < r:
    if i == size:
        size *= 2
        i = 0
    s += str(1 - int(s[i]))
    i += 1
print(s[l-1:])

