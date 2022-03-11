# history = ['']

text, deleted = [], []
op_history = []

q = int(input())
for _ in range(q):
    op = input().split()
    op[0] = int(op[0])
    if 2 <= op[0] <= 3:
        op[1] = int(op[1])

    # text = history[-1]
    # if op[0] == 1:
    #     history.append(text + op[1])
    # elif op[0] == 2:
    #     history.append(text[:-op[1]])
    # elif op[0] == 3:
    #     print(text[op[1] - 1])
    # else:
    #     history.pop()

    if op[0] == 1:
        op_history.append(op)
        text.extend(op[1])
    elif op[0] == 2:
        op_history.append(op)
        for _ in range(op[1]):
            deleted.append(text.pop())
    elif op[0] == 3:
        print(text[op[1] - 1])
    else:
        last_op = op_history.pop()
        if last_op[0] == 1:
            for _ in range(len(last_op[1])):
                text.pop()
        else:
            for _ in range(last_op[1]):
                text.append(deleted.pop())
