import math

class Mau:
    def __init__(self, x: list[float], y: str):
        self.x = x
        self.y = y

def kc_euclid(u: list[float], v: list[float]) -> float:
    return math.sqrt(sum((u[i] - v[i]) ** 2 for i in range(len(u))))

def kc_manhattan(u: list[float], v: list[float]) -> float:
    return sum(abs(u[i] - v[i]) for i in range(len(u)))

def do_chinh_xac_bo_mot_mau(D: list[Mau], fn_khoang_cach) -> float:
    n = len(D)
    if n == 0:
        return 0.0
    
    count_correct = 0
    for i in range(n):
        nhan_du_doan = ""
        min_dist = -1.0
        
        for j in range(n):
            if i == j:
                continue
            dist = fn_khoang_cach(D[i].x, D[j].x)
            if min_dist < 0 or dist < min_dist:
                min_dist = dist
                nhan_du_doan = D[j].y
                
        if nhan_du_doan == D[i].y:
            count_correct += 1
            
    return count_correct / n

def doc_du_lieu(ten_tep: str) -> list[Mau]:
    D = []
    try:
        with open(ten_tep, 'r', encoding='utf-8') as f:
            for line in f:
                tokens = line.strip().split()
                if not tokens or len(tokens) == 2:  # Bỏ qua dòng trống hoặc dòng khai báo size (30 4)
                    continue
                if len(tokens) >= 3:
                    x = [float(val.replace(',', '.')) for val in tokens[:-1]]
                    y = tokens[-1]
                    D.append(Mau(x, y))
    except FileNotFoundError:
        pass
    return D

if __name__ == "__main__":
    D = doc_du_lieu("data.txt")
    if D:
        acc_e = do_chinh_xac_bo_mot_mau(D, kc_euclid)
        acc_m = do_chinh_xac_bo_mot_mau(D, kc_manhattan)
        print(f"Euclid: {acc_e * 100:.2f}%")
        print(f"Manhattan: {acc_m * 100:.2f}%")