import sys

def giai_thua(n: int):
    if n < 0:
        return None, False
    kq = 1
    llong_max = 2**63 - 1
    for i in range(1, n + 1):
        if llong_max // i < kq:
            return None, False  # Bị tràn kiểu long long 64-bit
        kq *= i
    return kq, True

if __name__ == "__main__":
    n = int(input())
    kq, ok = giai_thua(n)
    if ok:
        print(kq)
    else:
        print("Tran so")