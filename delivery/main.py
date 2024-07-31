class Truck:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.content = capacity
        self.position = 0

    def travel_to(self, pos: int) -> int:
        #print(f"Travel {self.position} -> {pos}")
        dist = abs(pos - self.position)
        if (pos <= 0 and self.position >= 0) or (pos >= 0 and self.position <= 0):
            self.content = self.capacity
        self.position = pos
        return dist

    def recollect(self):
        #print("Refuel!")
        return self.travel_to(0)

    def delivery(self, pos: int, required: int) -> int:
        ret = 0
        while required > 0:
            if self.content == 0:
                ret += self.recollect()
            ret += self.travel_to(pos)
            dump = min(required, self.content)
            required -= dump
            self.content -= dump
        return ret

def check(k: int, deliveries: list[tuple]):
    truck = Truck(k)
    ret = 0
    for x, t in deliveries:
        ret += truck.delivery(x, t)
    ret += truck.travel_to(0)
    return ret

n, k = map(int, input().split())

deliveries = [tuple(map(int,input().split())) for _ in range(n)]

a = [(-x,y) for x,y in deliveries if x < 0]
b = [(x,y) for x,y in deliveries if x > 0]

#a.sort()
b.sort(reverse=True)
print(check(k, a) + check(k, b))
