function dao_nguoc(n::Int64)::Int64
    is_negative = n < 0
    n = abs(n)
    res = Int64(0)
    
    while n > 0
        res = res * 10 + (n % 10)
        n = div(n, 10)
    end
    
    return is_negative ? -res : res
end

input_str = readline()
if !isempty(input_str)
    n = parse(Int64, input_str)
    println(dao_nguoc(n))
end