n = int(input())

for _ in range(n):
    s = input()

    max_char = t = s[-1]
    char_index = [-1] * 128
    char_index[ord(s[-1])] = 0

    res = None
    for i in range(len(s) - 2, -1, -1):
        c = s[i]
        if c < max_char:
            for j in range(ord(c) + 1, ord(max_char) + 1):
                idx = char_index[j]
                if idx != -1:
                    lt = list(t)
                    lt[idx] = c
                    res = s[:i] + t[idx] + ''.join(sorted(lt))
                    break
            break

        max_char = c
        char_index[ord(c)] = len(t)
        t += c

    print(res or 'no answer')
