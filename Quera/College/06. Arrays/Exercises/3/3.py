n, t = input().split()
n = int(n)

sub_alpha = set(t)
for _ in range(n):
    s = input().strip()
    print('Yes' if set(s) == sub_alpha else 'No')
