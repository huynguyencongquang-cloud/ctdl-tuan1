dem = 0

def fib_de_quy(n: int) -> int:
    global dem
    dem += 1
    if n <= 1:
        return n
    return fib_de_quy(n - 1) + fib_de_quy(n - 2)

def fib_ghi_nho_helper(n: int, memo: list[int]) -> int:
    global dem
    dem += 1
    if n <= 1:
        return n
    if memo[n] != -1:
        return memo[n]
    memo[n] = fib_ghi_nho_helper(n - 1, memo) + fib_ghi_nho_helper(n - 2, memo)
    return memo[n]

def fib_ghi_nho(n: int) -> int:
    memo = [-1] * (n + 1)
    return fib_ghi_nho_helper(n, memo)

def fib_lap(n: int) -> int:
    if n <= 1:
        return n
    a, b = 0, 1
    for _ in range(2, n + 1):
        a, b = b, a + b
    return b

if __name__ == "__main__":
    import sys
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        
        dem = 0
        val1 = fib_de_quy(n)
        call1 = dem
        
        dem = 0
        val2 = fib_ghi_nho(n)
        call2 = dem
        
        val3 = fib_lap(n)
        
        print(f"{val1} {call1} {call2}")