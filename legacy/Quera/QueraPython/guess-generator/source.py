def guess_generator_iterator(guess_generator, min_value, max_value, assumed_number):
    gen = guess_generator(min_value, max_value)
    try:
        guess = next(gen)
    except StopIteration:
        return []

    res = []
    found, oops_count = False, 0
    last_guess = last_judge = None

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
        elif judge == 'E':
            found = True
        elif judge == 'G':
            if last_judge == 'G' and guess >= last_guess:
                oops = True
        elif judge == 'L':
            if last_judge == 'L' and guess <= last_guess:
                oops = True

        last_guess, last_judge = guess, judge
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
