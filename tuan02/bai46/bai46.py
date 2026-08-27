import sys
import re
import math

class Mau:
    def __init__(self, x: list[float], y: str):
        self.x = x
        self.y = y

def lang_gieng_gan_nhat(q: list[float], D: list[Mau]) -> tuple[str, float]:
    nhan_tot_nhat = ""
    min_dist = -1.0

    for mau in D:
        dist_sq = sum((q[i] - mau.x[i]) ** 2 for i in range(len(q)))
        dist = math.sqrt(dist_sq)

        if min_dist < 0 or dist < min_dist:
            min_dist = dist
            nhan_tot_nhat = mau.y

    return (nhan_tot_nhat, min_dist)

if __name__ == "__main__":
    D = [
        Mau([1.4, 0.2], "Setosa"),
        Mau([4.7, 1.4], "Versicolor"),
        Mau([4.9, 1.5], "Versicolor"),
        Mau([6.0, 2.5], "Virginica")
    ]
    
    line = sys.stdin.readline()
    nums = [float(val) for val in re.findall(r"[-+]?\d*\.\d+|\d+", line)]
    if nums:
        res = lang_gieng_gan_nhat(nums, D)
        print(f"{res[0]} {res[1]:.4f}")