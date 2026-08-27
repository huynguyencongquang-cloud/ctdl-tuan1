function cach1(a::Vector{Int64})::Int64
    n = length(a)
    if n == 0 return 0 end
    max_sum = a[1]
    for i in 1:n
        for j in i:n
            s = sum(a[i:j])
            if s > max_sum max_sum = s end
        end
    end
    return max_sum
end

function cach2(a::Vector{Int64})::Int64
    n = length(a)
    if n == 0 return 0 end
    max_sum = a[1]
    for i in 1:n
        s = 0
        for j in i:n
            s += a[j]
            if s > max_sum max_sum = s end
        end
    end
    return max_sum
end

function cach3(a::Vector{Int64})::Int64
    if isempty(a) return 0 end
    max_sum = a[1]
    current_sum = a[1]
    for i in 2:length(a)
        current_sum = max(a[i], current_sum + a[i])
        max_sum = max(max_sum, current_sum)
    end
    return max_sum
end

function kiem_thu_tu_dong()
    ok = true
    for test in 1:100
        n = rand(1:50)
        a = rand(-100:100, n)
        r1, r2, r3 = cach1(a), cach2(a), cach3(a)
        if !(r1 == r2 == r3)
            ok = false
            println("Loi o test $test")
            break
        end
    end
    if ok
        println("Kiem thu 100 test: TAT CA DEU DUNG")
    end
end

input_str = read(stdin, String)
tokens = split(input_str)
if !isempty(tokens)
    n = parse(Int64, tokens[1])
    a = [parse(Int64, tokens[i]) for i in 2:(n+1)]
    println(cach3(a))
else
    kiem_thu_tu_dong()
end