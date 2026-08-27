def la_chinh_phuong(n: int) -> bool:
    if n < 0:
        return False
    left, right = 0, 10**9
    while left <= right:
        mid = (left + right) // 2
        binh_phuong = mid * mid
        if binh_phuong == n:
            return True
        elif binh_phuong < n:
            left = mid + 1
        else:
            right = mid - 1
    return False

if __name__ == "__main__":
    n = int(input())
    if la_chinh_phuong(n):
        print("YES")
    else:
        print("NO")