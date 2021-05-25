a, b, c, d = int(input()), int(input()), int(input()), int(input())
print("Sum : %.6f" % (a + b + c + d))
print("Average : %6f" % ((a + b + c + d) / 4.))
print("Product : %6f" % (a * b * c * d))
x, y = (a + b + abs(a - b)) / 2, (c + d + abs(c - d)) / 2
print("MAX : %6f" % ((x + y + abs(x - y)) / 2.))
x, y = (a + b - abs(a - b)) / 2, (c + d - abs(c - d)) / 2
print("MIN : %6f" % ((x + y - abs(x - y)) / 2.))
