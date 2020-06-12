import generators
from source import guess_generator_iterator

gen = generators.guess_generator_1_correct
min_value, max_value, num = 1, 100, 50
lst = guess_generator_iterator(gen, min_value, max_value, num)
print(lst)

gen = generators.guess_generator_2_lazy
min_value, max_value, num = 1, 10, 7
lst = guess_generator_iterator(gen, min_value, max_value, num)
print(lst)

gen = generators.guess_generator_3_careless
min_value, max_value, num = 1, 30, 15
lst = guess_generator_iterator(gen, min_value, max_value, num)
print(lst)

gen = generators.guess_generator_4_stupid
min_value, max_value, num = 1, 10, 5
lst = guess_generator_iterator(gen, min_value, max_value, num)
print(lst)
