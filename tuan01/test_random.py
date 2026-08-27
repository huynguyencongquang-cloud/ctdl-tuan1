import random
import subprocess

def solve_python(arr):
    return f"{sum(arr)} {max(arr)}"

def run_test_cases(num_tests=200):
    print(f"--- Dang kiem thu {num_tests} bo du lieu ngau nhien ---")
    
    # Bien dich C++
    subprocess.run(["g++", "-std=c++17", "-O2", "tong.cpp", "-o", "tong.exe"], check=True)

    for i in range(1, num_tests + 1):
        n = random.randint(1, 1000)
        arr = [random.randint(-1000000, 1000000) for _ in range(n)]
        
        input_str = f"{n}\n" + " ".join(map(str, arr)) + "\n"
        expected_output = solve_python(arr)
        
        res = subprocess.run(["./tong.exe"], input=input_str, capture_output=True, text=True)
        actual_output = res.stdout.strip()
        
        if actual_output != expected_output:
            print(f"[LOI] Sai o bo test thu {i}!")
            return False

    print(f"HOAN THANH: Da kiem thu thanh cong {num_tests} bo du lieu. KHONG TIM THAY BO NAO SAI!")
    return True

if __name__ == "__main__":
    run_test_cases()
