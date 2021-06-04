from collections import defaultdict


def compress(s):
    cnt = defaultdict(int)
    for dig in s:
        cnt[dig] += 1

    res = ''.join(map(str, cnt.keys()))
    res += ''.join(map(str, filter(lambda v: v > 1, cnt.values())))
    res = ''.join(sorted(res))
    return res


s = input()
while True:
    t = compress(s)
    if t == s:
        break
    s = t

print(s)
