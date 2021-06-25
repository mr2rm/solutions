def compare(string1, string2):
    while string1 and string2:
        c = string1[0]
        if string2[0] < string1[0]:
            c = string2[0]
        if string1[0] == c:
            string1 = string1[1:]
        if string2[0] == c:
            string2 = string2[1:]
        if string1 and string2:
            string1, string2 = string1[::-1], string2[::-1]

    res = string1 or string2
    if res:
        return res
    return 'Both strings are empty!'
