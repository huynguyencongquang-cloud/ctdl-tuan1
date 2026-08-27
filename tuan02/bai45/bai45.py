import sys

def luy_thua_mod(a: int, b: int, m: int) -> int:
    r = 1 % m
    a %= m
    while b > 0:
        if b & 1:
            r = (r * a) % m
        a = (a * a) % m
        b >>= 1
    return r

if __name__ == "__main__":
    tokens = sys.stdin.read().split()
    if len(tokens) >= 3:
        a, b, m = map(int, tokens[:3])
        print(luy_thua_mod(a, b, m))