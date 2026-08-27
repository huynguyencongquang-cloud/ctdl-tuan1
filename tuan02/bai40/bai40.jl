struct KetQua
    tong::Int64
    dau::Int64
    cuoi::Int64
end

function kadane_chi_so(a::Vector{Int64})::KetQua
    if isempty(a)
        return KetQua(0, -1, -1)
    end
    
    max_sum = Int64(a[1])
    current_sum = Int64(a[1])
    start_idx = 1
    temp_start = 1
    end_idx = 1
    
    for i in 2:length(a)
        if Int64(a[i]) > current_sum + a[i]
            current_sum = Int64(a[i])
            temp_start = i
        else
            current_sum += a[i]
        end
        
        if current_sum > max_sum
            max_sum = current_sum
            start_idx = temp_start
            end_idx = i
        end
    end
    
    # Neu tra ve chi so 0-based cho giong C++/Python
    return KetQua(max_sum, start_idx - 1, end_idx - 1)
end

input_str = read(stdin, String)
tokens = split(input_str)
if !isempty(tokens)
    n = parse(Int64, tokens[1])
    idx = 2
    if idx <= length(tokens) && tokens[idx] == "/"
        idx += 1
    end
    a = [parse(Int64, tokens[i]) for i in idx:(idx+n-1)]
    kq = kadane_chi_so(a)
    println("$(kq.tong) $(kq.dau) $(kq.cuoi)")
end