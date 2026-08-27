import random

def cach1(a: list[int]) -> int:
    n = len(a)
    if n == 0: return 0
    max_sum = a[0]
    for i in range(n):
        for j in range(i, n):
            s = sum(a[i:j+1])
            if s > max_sum: max_sum = s
    return max_sum

def cach2(a: list[int]) -> int:
    n = len(a)
    if n == 0: return 0
    max_sum = a[0]
    for i in range(n):
        s = 0
        for j in range(i, n):
            s += a[j]
            if s > max_sum: max_sum = s
    return max_sum

def cach3(a: list[int]) -> int:
    if not a: return 0
    max_sum = current_sum = a[0]
    for x in a[1:]:
        current_sum = max(x, current_sum + x)
        max_sum = max(max_sum, current_sum)
    return max_sum

def kiem_thu_tu_dong():
    ok = True
    for test in range(100):
        n = random.randint(1, 50)
        a = [random.randint(-100, 100) for _ in range(n)]
        r1, r2, r3 = cach1(a), cach2(a), cach3(a)
        if not (r1 == r2 == r3):
            ok = False
            print(f"Loi o test {test}")
            break
    if ok:
        print("Kiem thu 100 test: TAT CA DEU DUNG")

if __name__ == "__main__":
    import sys
    input_data = sys.stdin.read().split()
    if input_data:
        n = int(input_data[0])
        a = [int(x) for x in input_data[1:n+1]]
        print(cach3(a))
    else:
        kiem_thu_tu_dong()