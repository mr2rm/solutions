q = int(input())

balance = {}
user_ip = {}

for _ in range(q):
    typ, req = input().split()
    typ = int(typ)
    params = req.split(':')

    if typ == 1:
        ip, username = params
        if not username.isalnum():
            print('invalid username')
            continue
        user_ip[username] = ip
        balance[ip] = 0
    elif typ == 2:
        from_ip, to_username, amount = params
        to_ip = user_ip[to_username]
        amount = int(amount)
        balance[from_ip] -= amount
        balance[to_ip] += amount
    elif typ == 3:
        ip = params[0]
        print(balance[ip])
