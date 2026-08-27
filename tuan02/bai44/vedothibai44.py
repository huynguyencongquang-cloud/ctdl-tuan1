import matplotlib.pyplot as plt

# Dữ liệu từ bảng đo thời gian
n = [500, 1000, 2000, 4000]
cpp_time = [0.0003, 0.0012, 0.0048, 0.0192]
python_time = [0.0060, 0.0240, 0.0980, 0.3850]
julia_time = [0.0008, 0.0032, 0.0128, 0.0512]

# Vẽ đồ thị
plt.figure(figsize=(8, 5))
plt.plot(n, cpp_time, marker='o', label='C++', linewidth=2)
plt.plot(n, python_time, marker='s', label='Python', linewidth=2)
plt.plot(n, julia_time, marker='^', label='Julia', linewidth=2)

# Thiết lập nhãn hai trục và tiêu đề
plt.title('Đồ thị biểu diễn thời gian chạy theo kích thước dữ liệu n', fontsize=12)
plt.xlabel('Kích thước mảng (n)', fontsize=11)
plt.ylabel('Thời gian thực thi (giây)', fontsize=11)
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()

# Lưu và hiển thị ảnh
plt.tight_layout()
plt.savefig('do_thi_bai44.png', dpi=300)
plt.show()