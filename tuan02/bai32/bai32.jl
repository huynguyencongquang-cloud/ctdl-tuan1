function la_chinh_phuong(n::Int64)
    if n < 0
        return false
    end
    left, right = Int64(0), Int64(10^9)
    while left <= right
        mid = div(left + right, 2)
        binh_phuong = mid * mid
        if binh_phuong == n
            return true
        elseif binh_phuong < n
            left = mid + 1
        else
            right = mid - 1
        end
    end
    return false
end

# Nhận dữ liệu và in kết quả
input_str = readline()
if !isempty(input_str)
    n = parse(Int64, input_str)
    if la_chinh_phuong(n)
        println("YES")
    else
        println("NO")
    end
end