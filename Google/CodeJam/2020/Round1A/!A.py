# def attach_char(prefix, patterns):
#     return [prefix + p for p in patterns]


# def get_patterns(s, t):
#     if not s or not t:
#         s, t = s.replace('*', ''), t.replace('*', '')
#         return [''] if s == t else []

#     patterns = []
#     if '*' not in (s[0], t[0]):
#         if s[0] == t[0]:
#             temp_patterns = get_patterns(s[1:], t[1:])
#             patterns = attach_char(s[0], temp_patterns)
#         return patterns

#     if s[0] != '*':
#         s, t = t, s

#     for i in range(len(t) + 1):
#         prefix = t[:i].replace('*', '')
#         temp_patterns = get_patterns(s[1:], t[i:])
#         new_patterns = attach_char(prefix, temp_patterns)
#         patterns.extend(new_patterns)

#     return patterns


# def update_patterns(s, patterns):
#     res = []
#     for p in patterns:
#         new_patterns = get_patterns(s, p)
#         res.extend(new_patterns)
#     return res


# t = int(input())
# for tc in range(1, t + 1):
#     n = int(input())

#     patterns = [input()]
#     for i in range(1, n):
#         s = input()
#         patterns = update_patterns(s, patterns)

#     res = '*'
#     if patterns:
#         res = patterns.pop().replace('*', '')
#     print("Case #{}: {}".format(tc, res))


t = int(input())
for tc in range(1, t + 1):
    n = int(input())

    pattern = input()
    for i in range(1, n):
        s = input()
        if not pattern:
            continue

        for x, y in zip(s[::-1], pattern[::-1]):
            if x != y:
                if y == '*':
                    pattern = s
                elif x != '*':
                    pattern = None
                break

    res = '*'
    if pattern:
        res = pattern.replace('*', '')
    print("Case #{}: {}".format(tc, res))
