class Team:
    last_id = 0
    team_list = []

    def __init__(self, name, money):
        self.id = Team.last_id
        self.name = name
        self.money = money
        self.players = []
        self.wins = self.looses = self.draws = 0

    def __lt__(self, other):
        if self.wins != other.wins:
            return self.wins > other.wins
        if self.looses != other.looses:
            return self.looses < other.looses
        return self.id < other.id

    @classmethod
    def create(cls, name, *args, **kwargs):
        if name in [t.name for t in cls.team_list]:
            return

        cls.last_id += 1
        team = cls(name, *args, **kwargs)
        cls.team_list.append(team)
        return team

    @classmethod
    def get(cls, tid):
        for t in cls.team_list:
            if t.id == tid:
                return t

    @classmethod
    def rank(cls):
        for i, t in enumerate(sorted(cls.team_list), start=1):
            print(f'{i}. {t.name}')

    @classmethod
    def print(cls):
        for t in cls.team_list:
            print(f'{t.id} -> {t.name}')

    def power(self, first=True):
        pwr = sum(p.speed for p in self.players[:11])
        if first:
            pwr += sum(p.finishing for p in self.players[:11])
        else:
            pwr += sum(p.defence for p in self.players[:11])
        return pwr


class Player:
    last_id = 0
    player_list = []

    def __init__(self, name, price, speed, finishing, defence):
        self.id = Player.last_id
        self.name = name
        self.price = price
        self.speed = speed
        self.finishing = finishing
        self.defence = defence

    @classmethod
    def create(cls, *args, **kwargs):
        cls.last_id += 1
        player = cls(*args, **kwargs)
        cls.player_list.append(player)
        return player

    @classmethod
    def get(cls, pid):
        for p in cls.player_list:
            if p.id == pid:
                return p

    @classmethod
    def print(cls):
        for p in cls.player_list:
            print(f'{p.id} -> {p.name}')

    @property
    def has_team(self):
        for t in Team.team_list:
            if self in t.players:
                return True
        return False


def buy_player(pid, tid):
    player = Player.get(pid)
    if not player:
        print(f'player with the id {pid} doesnt exist')
        return

    team = Team.get(tid)
    if not team:
        print(f'team with the id {tid} doesnt exist')
        return

    if team.money < player.price:
        print('the team cant afford to buy this player')
        return

    if player.has_team:
        print('player already has a team')
        return

    team.money -= player.price
    team.players.append(player)
    print('player added to the team succesfully')


def sell_player(pid, tid):
    team = Team.get(tid)
    if not team:
        print('team doesnt exist')
        return

    player = Player.get(pid)
    if player not in team.players:
        print('team doesnt have this player')
        return

    team.money += player.price
    team.players.remove(player)
    print('player sold succesfully')


def do_match(tid1, tid2):
    team1, team2 = Team.get(tid1), Team.get(tid2)
    if not team1 or not team2:
        print('team doesnt exist')
        return

    if len(team1.players) < 11 or len(team2.players) < 11:
        print('the game can not be held due to loss of the players')
        return

    power1, power2 = team1.power(), team2.power(first=False)
    if power1 == power2:
        team1.draws += 1
        team2.draws += 1
    elif power1 > power2:
        team1.wins += 1
        team2.looses += 1
        team1.money += 1000
    else:
        team2.wins += 1
        team1.looses += 1
        team2.money += 1000


while True:
    line = input()
    if not line:
        continue

    args = line.split(' ')
    if args[0] == 'new':
        params = [args[2]] + list(map(int, args[3:]))
        klass = Player if args[1] == 'player' else Team
        klass.create(*params)
    elif args[0] == 'buy':
        params = list(map(int, args[1:]))
        buy_player(*params)
    elif args[0] == 'sell':
        params = list(map(int, args[1:]))
        sell_player(*params)
    elif args[0] == 'match':
        params = list(map(int, args[1:]))
        do_match(*params)
    elif args[0] == 'rank':
        Team.rank()
    elif args[0] == 'end':
        break
