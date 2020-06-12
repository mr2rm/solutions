def guess_generator_iterator(guess_generator, min_value, max_value, assumed_number):
    gen = guess_generator(min_value, max_value)
    try:
        guess = next(gen)
    except StopIteration:
        return []

    res = []
    found, oops_count = False, 0
    minl, maxg = min_value - 1, max_value + 1

    while True:
        judge = None
        if guess == assumed_number:
            judge = 'E'
        elif guess > assumed_number:
            judge = 'G'
        elif guess < assumed_number:
            judge = 'L'

        oops = False
        if guess < min_value or guess > max_value or found:
            oops = True
        else:
            if guess <= minl or guess >= maxg:
                oops = True

            if judge == 'E':
                found = True
            elif judge == 'G':
                maxg = min(maxg, guess)
            elif judge == 'L':
                minl = max(minl, guess)

        res.append(guess)
        if oops:
            res.append('!')
            oops_count += 1

        if oops_count == 3:
            res.append('!!!')
            break
        try:
            guess = gen.send(judge)
        except StopIteration:
            break

    return res
