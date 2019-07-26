def sign(num):
    if num < 0:
        return -1
    if num > 0:
        return 1
    return 0


n = int(input())
arr = list(map(int, input().split()))

res, last_sign = [arr[0]], 0
for i in range(1, n):
    current_sign = sign(arr[i] - arr[i-1])
    if current_sign != last_sign and current_sign != 0:
        res.append(arr[i])
        last_sign = current_sign

if len(res) > 1 and sign(res[1] - res[0]) == -1:
    res.pop(0)
print(len(res))
