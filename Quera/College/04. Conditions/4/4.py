string = input()
g = r = y = 0

if string[0] == 'G':    g += 1
elif string[0] == 'R':  r += 1
else:                   y += 1
if string[1] == 'G':    g += 1
elif string[1] == 'R':  r += 1
else:                   y += 1
if string[2] == 'G':    g += 1
elif string[2] == 'R':  r += 1
else:                   y += 1
if string[3] == 'G':    g += 1
elif string[3] == 'R':  r += 1
else:                   y += 1
if string[4] == 'G':    g += 1
elif string[4] == 'R':  r += 1
else:                   y += 1

if r >= 3 or (r >= 2 and y >= 2) or g == 0:
    print('nakhor lite')
else:
    print('rahat baash')
