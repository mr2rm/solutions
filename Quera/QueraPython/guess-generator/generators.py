import random


# Generators to test iterator function


def guess_generator_1_correct(min_value, max_value):
    num = random.randint(min_value, max_value)
    resp = (yield num)
    while resp != 'E':  # Equal
        if resp == 'G':  # Greater
            max_value = num - 1
        elif resp == 'L':  # Less
            min_value = num + 1
        num = random.randint(min_value, max_value)
        resp = (yield num)


def guess_generator_2_lazy(min_value, max_value):
    num = min_value
    resp = (yield num)
    while resp != 'E' and num < max_value:
        num += 1
        resp = (yield num)


def guess_generator_3_careless(min_value, max_value):
    num = random.randint(min_value, max_value)
    resp = (yield num)
    while resp != 'E':  # Equal
        if resp == 'G':  # Greater
            max_value = num - 1
        elif resp == 'L':  # Less
            min_value = num + 1
        num = random.randint(min_value, max_value)
        resp = (yield num)
    # guess again after true guess
    for _ in range(3):
        num = random.randint(min_value, max_value)
        yield num


def guess_generator_4_stupid(min_value, max_value):
    num = random.randint(min_value, max_value)
    resp = (yield num)
    while resp != 'E':  # Equal
        if resp == 'G':  # Greater
            num += 1
        elif resp == 'L':  # Less
            num -= 1

        resp = (yield num)
