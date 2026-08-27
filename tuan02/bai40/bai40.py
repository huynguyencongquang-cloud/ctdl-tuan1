from typing import NamedTuple

class KetQua(NamedTuple):
    tong: int
    dau: int
    cuoi: int

def kadane_chi_so(a: list[int]) -> KetQua:
    if not a:
        return KetQua(0, -1, -1)
    
    max_sum = current_sum = a[0]
    start = temp_start = end = 0
    
    for i in range(1, len(a)):
        if a[i] > current_sum + a[i]:
            current_sum = a[i]
            temp_start = i
        else:
            current_sum += a[i]
            
        if current_sum > max_sum:
            max_sum = current_sum
            start = temp_start
            end = i
            
    return KetQua(max_sum, start, end)

if __name__ == "__main__":
    import sys
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        idx = 1
        if idx < len(tokens) and tokens[idx] == "/":
            idx += 1
        a = [int(x) for x in tokens[idx:idx+n]]
        kq = kadane_chi_so(a)
        print(f"{kq.tong} {kq.dau} {kq.cuoi}")