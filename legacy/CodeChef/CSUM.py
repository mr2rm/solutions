t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    found = False
    for i, a in enumerate(arr):
        for j, b in enumerate(arr):
            if i != j and a + b == k:
                found = True
    
    print('Yes' if found else 'No')
