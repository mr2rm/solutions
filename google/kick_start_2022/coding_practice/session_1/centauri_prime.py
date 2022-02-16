def get_ruler(kingdom):
    ruler = 'nobody'
    last_letter = kingdom[-1].lower()
    if last_letter in 'aeiou':
        ruler = 'Alice'
    elif last_letter != 'y':
        ruler = 'Bob'
    return ruler


def main():
    # Get the number of test cases
    T = int(input())
    for t in range(T):
        # Get the kingdom
        kingdom = input()
        print('Case #%d: %s is ruled by %s.' %
              (t + 1, kingdom, get_ruler(kingdom)))


if __name__ == '__main__':
    main()
