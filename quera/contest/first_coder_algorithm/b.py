import calendar
from datetime import time, datetime
n, m, q = map(int, input().split())

day_name = list(calendar.day_name)
work_hours = [list() for _ in range(7)]
for _ in range(n):
    day, start, end = input().split()
    week_day = day_name.index(day)
    start = time(*map(int, start.split(':')))
    end = time(*map(int, end.split(':')))
    work_hours[week_day].append((start, end))

level_name = ('Station', 'Store', 'Tenant')
exceptions = [list() for _ in range(3)]
for _ in range(m):
    level, start, end, status = input().split()
    start = datetime.fromisoformat(start)
    end = datetime.fromisoformat(end)
    level_index = level_name.index(level)
    exceptions[level_index].append((start, end, status))

for _ in range(q):
    res, dt = None, datetime.fromisoformat(input())
    for level_exceptions in exceptions:
        for start, end, status in level_exceptions:
            if start <= dt <= end:
                res = (status == 'open')
                break
        if res is not None:
            break
    else:
        res, hours = False, work_hours[dt.weekday()]
        for start, end in hours:
            if start <= dt.time() <= end:
                res = True
                break

    print('true' if res else 'false')
