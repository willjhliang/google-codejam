
import random

def solve():
    print("01010101")
    while True:
        n = int(input())
        if n == -1 or n == 0:
            break
        m = random.sample(range(0, 8), n)
        o = ["0"] * 8
        for i in m:
            o[i] = "1"
        print("".join(o))

t = int(input())
for i in range(t):
    solve()