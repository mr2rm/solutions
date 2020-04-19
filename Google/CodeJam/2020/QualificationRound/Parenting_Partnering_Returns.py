t = int(input())
for tc in range(1, t + 1):
    n = int(input())
    todo_list = []
    for i in range(n):
        s, e = map(int, input().split())
        todo_list.append(((s, e), i))

    c = j = 0
    possible = True
    assignee_list = [None] * n
    for (s, e), i in sorted(todo_list):
        assignee = None
        if s >= c:
            c, assignee = e, 'C'
        elif s >= j:
            j, assignee = e, 'J'

        if not assignee:
            possible = False
            break

        assignee_list[i] = assignee

    res = 'IMPOSSIBLE' if not possible else ''.join(assignee_list)
    print("Case #{}: {}".format(tc, res))
