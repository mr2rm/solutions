x, y = input().strip(), input().strip()
if x[2] != y[2]:
    if x[2] > y[2]:
        x, y = y, x
elif x[1] != y[1]:
    if x[1] > y[1]:
        x, y = y, x
elif x[0] != y[0]:
    if x[0] > y[0]:
        x, y = y, x
if x == y:
    print("%s = %s" % (x, y))
else:
    print("%s < %s" % (x, y))
