def count_complaints(preferences, forbiddens, num_options):
    complaints = float('inf')
    for x in range(1 << num_options):
        x_bin = f'{x:0{num_options}b}'
        if x_bin in forbiddens:
            continue

        curr_complaints = 0
        for pref in preferences:
            diff = list(filter(lambda p: p[0] != p[1], zip(x_bin, pref)))
            curr_complaints += len(diff)

        complaints = min(complaints, curr_complaints)

    return complaints


if __name__ == '__main__':
    # Read number of test cases
    num_cases = int(input())

    for tc in range(1, num_cases + 1):
        # Read number of friends, number of forbidden teas, and number of options
        num_friends, num_forbidden, num_options = map(int, input().split())

        # Read the friends' preferences
        preferences = [input() for _ in range(num_friends)]

        # Read the forbidden teas
        forbiddens = [input() for _ in range(num_forbidden)]

        print("Case #%d: %d" % (tc, count_complaints(
            preferences, forbiddens, num_options)))
