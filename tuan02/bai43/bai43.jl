dem = 0

function fib_de_quy(n::Int64)::Int64
    global dem += 1
    if n <= 1
        return n
    end
    return fib_de_quy(n - 1) + fib_de_quy(n - 2)
end

function fib_ghi_nho_helper(n::Int64, memo::Vector{Int64})::Int64
    global dem += 1
    if n <= 1
        return n
    end
    if memo[n + 1] != -1
        return memo[n + 1]
    end
    memo[n + 1] = fib_ghi_nho_helper(n - 1, memo) + fib_ghi_nho_helper(n - 2, memo)
    return memo[n + 1]
end

function fib_ghi_nho(n::Int64)::Int64
    memo = fill(Int64(-1), n + 1)
    return fib_ghi_nho_helper(n, memo)
end

function fib_lap(n::Int64)::Int64
    if n <= 1
        return n
    end
    a, b = Int64(0), Int64(1)
    for i in 2:n
        a, b = b, a + b
    end
    return b
end

input_str = read(stdin, String)
tokens = split(input_str)
if !isempty(tokens)
    n = parse(Int64, tokens[1])
    
    global dem = 0
    val1 = fib_de_quy(n)
    call1 = dem
    
    global dem = 0
    val2 = fib_ghi_nho(n)
    call2 = dem
    
    val3 = fib_lap(n)
    
    println("$val1 $call1 $call2")
end