n, result = int(input()), 0

prev_state = curr_state = None
for _ in range(n):
    curr_state = input()
    if prev_state and curr_state != prev_state:
        result += 1
    prev_state = curr_state

print(result)
