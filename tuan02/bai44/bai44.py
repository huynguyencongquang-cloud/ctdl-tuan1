import time

def bubble_sort(a):
    n = len(a)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]

if __name__ == "__main__":
    sizes = [1000, 2000, 4000, 8000]
    print("Kich thuoc n | Thoi gian (s)")
    for n in sizes:
        a = [n - i for i in range(n)]
        
        t0 = time.time()
        bubble_sort(a)
        t1 = time.time()
        
        print(f"{n:<12} | {t1 - t0:.6f}")