history = ['']

q = int(input())
for _ in range(q):
    op = input().split()
    op[0] = int(op[0])
    if 2 <= op[0] <= 3:
        op[1] = int(op[1])

    text = history[-1]
    if op[0] == 1:
        history.append(text + op[1])
    elif op[0] == 2:
        history.append(text[:-op[1]])
    elif op[0] == 3:
        print(text[op[1] - 1])
    else:
        history.pop()
