def find(num1, num2, num3):
    for i in range(4):
        if i + 1 not in (num1, num2, num3):
            return i + 1


