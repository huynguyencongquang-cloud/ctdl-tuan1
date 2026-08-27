def dao_nguoc(n: int) -> int:
    is_negative = n < 0
    n = abs(n)
    res = 0
    
    while n > 0:
        res = res * 10 + (n % 10)
        n //= 10
        
    return -res if is_negative else res

if __name__ == "__main__":
    n = int(input())
    print(dao_nguoc(n))