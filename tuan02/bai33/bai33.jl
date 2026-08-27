function phan_tich(n::Int64)::Tuple{Int64, Int64}
    if n == 0
        return (1, 0)
    end
    
    n = abs(n)
    so_chu_so = 0
    tong_chu_so = 0
    
    while n > 0
        tong_chu_so += n % 10
        so_chu_so += 1
        n = div(n, 10)
    end
    
    return (so_chu_so, tong_chu_so)
end

# Đọc dữ liệu từ bàn phím và in kết quả
input_str = readline()
if !isempty(input_str)
    n = parse(Int64, input_str)
    so_cs, tong_cs = phan_tich(n)
    println("$so_cs $tong_cs")
end