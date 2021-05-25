def print_hanoi(n, from_tower, to_tower, help_tower):
    if n == 0:
        return

    print_hanoi(n - 1, from_tower, help_tower, to_tower)

    global move_count
    move_count += 1
    print(move_count, from_tower, to_tower)

    print_hanoi(n - 1, help_tower, to_tower, from_tower)


n, move_count = int(input()), 0
print_hanoi(n, 'A', 'B', 'C')
