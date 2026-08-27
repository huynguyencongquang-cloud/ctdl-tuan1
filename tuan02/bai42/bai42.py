def cua_so_truot(a: list[int], k: int) -> tuple[int, int]:
    n = len(a)
    if n < k or k <= 0:
        return (0, -1)

    current_sum = sum(a[:k])
    max_sum = current_sum
    best_start = 0

    for i in range(k, n):
        current_sum += a[i] - a[i - k]
        if current_sum > max_sum:
            max_sum = current_sum
            best_start = i - k + 1

    return (max_sum, best_start)

if __name__ == "__main__":
    import sys
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        k = int(tokens[1])
        idx = 2
        if idx < len(tokens) and tokens[idx] == "/":
            idx += 1
        a = [int(x) for x in tokens[idx:idx+n]]
        res = cua_so_truot(a, k)
        print(f"{res[0]} {res[1]}")