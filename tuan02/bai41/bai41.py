def tich_lon_nhat(a: list[int]) -> int:
    if not a:
        return 0
    
    max_prod = min_prod = ans = a[0]
    
    for i in range(1, len(a)):
        if a[i] < 0:
            max_prod, min_prod = min_prod, max_prod
            
        max_prod = max(a[i], max_prod * a[i])
        min_prod = min(a[i], min_prod * a[i])
        
        ans = max(ans, max_prod)
        
    return ans

if __name__ == "__main__":
    import sys
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        idx = 1
        if idx < len(tokens) and tokens[idx] == "/":
            idx += 1
        a = [int(x) for x in tokens[idx:idx+n]]
        print(tich_lon_nhat(a))