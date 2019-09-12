n = int(input())
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if j != 1:
            print(end=' ')
        print(i * j, end='')
    print()
