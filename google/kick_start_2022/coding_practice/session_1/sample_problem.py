def solve():
    _, m = map(int, input().split())
    candies = sum(map(int, input().split()))
    return candies % m


testcases = int(input())
for t in range(testcases):
    result = solve()
    print(f"Case #{t + 1}: {result}")
