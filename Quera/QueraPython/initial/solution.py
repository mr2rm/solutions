def fruits(fruit_list):
    res = {}
    for fruit in fruit_list:
        if fruit['shape'] == 'sphere' and 300 <= fruit['mass'] <= 600 and 100 <= fruit['volume'] <= 500:
            k = fruit['name']
            v = res.setdefault(k, 0) + 1
            res[k] = v

    return res
