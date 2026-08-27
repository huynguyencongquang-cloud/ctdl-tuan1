def tang_nghiem_ngat(a: list[int]) -> bool:
    for i in range(1, len(a)):
        if a[i] <= a[i - 1]:
            return False
    return True

def khong_giam(a: list[int]) -> bool:
    for i in range(1, len(a)):
        if a[i] < a[i - 1]:
            return False
    return True

if __name__ == "__main__":
    import sys
    input_data = sys.stdin.read().split()
    if input_data:
        n = int(input_data[0])
        a = [int(x) for x in input_data[1:n+1]]
        print("YES" if khong_giam(a) else "NO")