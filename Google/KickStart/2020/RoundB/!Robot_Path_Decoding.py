t = int(input())

for tc in range(1, t + 1):
    s = input()
    n = int(1e9)
    mvdic = {
        'N': (-1, 0),
        'S': (1, 0),
        'E': (0, 1),
        'W': (0, -1),
    }

    st = ['']
    for c in s:
        if c.isdigit():
            st.append(int(c))
        elif c.isalpha():
            cs = st.pop() + c
            st.append(cs)
        elif c == '(':
            st.append('')
        elif c == ')':
            cs, x = st.pop(), st.pop()
            ps = st.pop()
            st.append(ps + x * cs)

    s = st.pop()
    x = y = 0
    for c in s:
        x = (x + mvdic[c][0]) % n
        y = (y + mvdic[c][1]) % n

    print('Case #%d: %d %d' % (tc, y + 1, x + 1))
