x = input()

res, j = "0", -1
for i in range(len(x) - 1, -1, -1):
    for k, ch in enumerate(x[i+1:]):
        if ch > x[i] and (j == -1 or ch < x[j]):
            j = i + k + 1
    if j != -1:
        res = x[:i] + x[j] + "".join(sorted(x[i+1:j] + x[i] + x[j+1:]))
        break
print(res)
