import math
import time
import random

def kc_euclid(u: list[float], v: list[float], d: int) -> float:
    return math.sqrt(sum((u[i] - v[i]) ** 2 for i in range(d)))

def do_thoi_gian(n: int, q: int = 1000, d: int = 20):
    # 1. Sinh du lieu ngau nhien voi fixed seed
    random.seed(12345)
    train = [[random.random() for _ in range(d)] for _ in range(n)]
    test = [[random.random() for _ in range(d)] for _ in range(q)]

    # 2. Bam gio quanh vong lap phan loai
    start = time.perf_counter()

    for i in range(q):
        min_dist = -1.0
        nearest_idx = -1
        for j in range(n):
            d_val = kc_euclid(test[i], train[j], d)
            if min_dist < 0 or d_val < min_dist:
                min_dist = d_val
                nearest_idx = j

    end = time.perf_counter()
    elapsed = end - start

    print(f"n = {n} | Thoi gian: {elapsed:.4f}s")

if __name__ == "__main__":
    N_list = [1000, 10000, 100000]
    for n in N_list:
        do_thoi_gian(n)