import sys
import re
import math

class Mau:
    def __init__(self, x: list[float], y: str):
        self.x = x
        self.y = y

def doc_du_lieu(ten_tep: str) -> tuple[list[Mau], int]:
    D = []
    d = 4
    try:
        with open(ten_tep, 'r', encoding='utf-8') as f:
            tokens = f.read().split()
            if tokens:
                n = int(tokens[0])
                d = int(tokens[1])
                idx = 2
                for _ in range(n):
                    x = [float(val.replace(',', '.')) for val in tokens[idx:idx+d]]
                    idx += d
                    y = tokens[idx]
                    idx += 1
                    D.append(Mau(x, y))
    except FileNotFoundError:
        # Tập mẫu Iris dự phòng
        D = [
            Mau([5.1, 3.5, 1.4, 0.2], "Setosa"),
            Mau([4.9, 3.0, 1.4, 0.2], "Setosa"),
            Mau([4.7, 3.2, 1.3, 0.2], "Setosa"),
            Mau([4.6, 3.1, 1.5, 0.2], "Setosa"),
            Mau([5.0, 3.6, 1.4, 0.2], "Setosa"),
            Mau([7.0, 3.2, 4.7, 1.4], "Versicolor"),
            Mau([6.4, 3.2, 4.5, 1.5], "Versicolor"),
            Mau([6.9, 3.1, 4.9, 1.5], "Versicolor"),
            Mau([5.5, 2.3, 4.0, 1.3], "Versicolor"),
            Mau([6.5, 2.8, 4.6, 1.5], "Versicolor"),
            Mau([6.3, 3.3, 6.0, 2.5], "Virginica"),
            Mau([5.8, 2.7, 5.1, 1.9], "Virginica"),
            Mau([7.1, 3.0, 5.9, 2.1], "Virginica"),
            Mau([6.3, 2.9, 5.6, 1.8], "Virginica"),
            Mau([6.5, 3.0, 5.8, 2.2], "Virginica")
        ]
    return D, d

def lang_gieng_gan_nhat(q: list[float], D: list[Mau]) -> tuple[str, float]:
    nhan_tot_nhat = ""
    min_dist = -1.0

    for mau in D:
        if len(mau.x) != len(q):
            continue
        dist_sq = sum((q[i] - mau.x[i]) ** 2 for i in range(len(q)))
        dist = math.sqrt(dist_sq)

        if min_dist < 0 or dist < min_dist:
            min_dist = dist
            nhan_tot_nhat = mau.y

    return (nhan_tot_nhat, min_dist)

if __name__ == "__main__":
    D, d = doc_du_lieu("data.txt")
    line = sys.stdin.readline()
    
    # Chuẩn hóa dấu phẩy thập phân thành dấu chấm
    line_clean = re.sub(r'(\d+),(\d+)', r'\1.\2', line)
    nums = [float(val) for val in re.findall(r"[-+]?\d*\.\d+|\d+", line_clean)]
    
    if nums:
        res = lang_gieng_gan_nhat(nums, D)
        # Làm tròn chính xác 4 chữ số thập phân
        print(f"{res[0]} {res[1]:.4f}")