class Piece:
    def __init__(self, sort, color, position):
        self.sort = sort
        self.color = color
        self.position = position

    def __eq__(self, pc):
        for attr in ('sort', 'color', 'position'):
            if getattr(self, attr, None) != getattr(pc, attr, None):
                return False
        return True

    def __ne__(self, pc):
        return not (self == pc)


class Board():
    def __init__(self):
        self.position = {
            k.position: k
            for k in [
                Piece('K', 'white', (-10, -10)),
                Piece('K', 'black', (10, 10)),
            ]
        }

    @property
    def kings(self):
        return list(filter(lambda pc: pc.sort == 'K', self.position.values()))

    def add(self, piece):
        if piece.sort == 'K':
            if piece.color in map(lambda k: k.color, self.kings):
                print("invalid query")
                return

        if piece.position in self.position:
            print("invalid query")
            return

        self.position.update({piece.position: piece})

    def remove(self, position):
        pc = self.position.get(position)
        if not pc or pc.sort == 'K':
            print("invalid query")
            return

        del self.position[position]

    def move(self, piece, position2):
        position1 = piece.position
        if piece != self.position.get(position1):
            print("invalid query")
            return

        dest_pc = self.position.get(position2)
        if dest_pc and (dest_pc.color == piece.color or dest_pc.sort == 'K'):
            print("invalid query")
            return

        del self.position[position1]
        self.position[position2] = piece

    def is_mate(self, color):
        k = list(filter(lambda k: k.color == color, self.kings))[0]
        for dx in range(-1, 2):
            for dy in range(-1, 2):
                pos = (k.position[0] + dx, k.position[1] + dy)
                pc = self.position.get(pos)
                if pc and pc.sort != 'K' and pc.color != color:
                    return True
        return False
