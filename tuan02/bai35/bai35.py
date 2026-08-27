def la_nguyen_to(n: int) -> bool:
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def sang_eratosthenes(n: int) -> list[int]:
    if n < 2:
        return []
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    
    for p in range(2, int(n**0.5) + 1):
        if is_prime[p]:
            for i in range(p * p, n + 1, p):
                is_prime[i] = False
                
    return [p for p in range(2, n + 1) if is_prime[p]]

if __name__ == "__main__":
    n = int(input())
    primes = sang_eratosthenes(n)
    print(" ".join(map(str, primes)))