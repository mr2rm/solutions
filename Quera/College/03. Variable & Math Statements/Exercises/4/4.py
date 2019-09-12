a, b = input().split()
print("%02d:%02d" % ((12 - int(a)) % 12, (60 - int(b)) % 60))
