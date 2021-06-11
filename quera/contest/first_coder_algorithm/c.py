from datetime import datetime, timedelta
import pytz


def solve(i, l, r):
    global members, t
    if l + timedelta(minutes=t) > r:
        return False
    if i == len(members):
        print(l.strftime('%H:%M'))
        return True
    for start, end in timesheet[members[i]]:
        if solve(i + 1, max(l, start), min(r, end)):
            return True
    return False


def get_utc(timestring, timezone=None):
    timeformat = '%H:%M'
    if timezone:
        timestring += timezone
        timeformat += '%z'
    return datetime.strptime(timestring, timeformat).astimezone(pytz.UTC)


n, m = map(int, input().split())
timesheet = {}
for _ in range(n):
    name, timezone, start, end = input().split()
    start, end = get_utc(start, timezone), get_utc(end, timezone)
    timesheet[name] = [(start, end)]

s, e = get_utc('00:00'), get_utc('23:59')
for _ in range(m):
    c, t = map(int, input().split())
    members = input().split()
    if not solve(0, s, e):
        print('N/A')
