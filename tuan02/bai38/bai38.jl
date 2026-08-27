function tang_nghiem_ngat(a::Vector{Int64})::Bool
    for i in 2:length(a)
        if a[i] <= a[i - 1]
            return false
        end
    end
    return true
end

function khong_giam(a::Vector{Int64})::Bool
    for i in 2:length(a)
        if a[i] < a[i - 1]
            return false
        end
    end
    return true
end

input_str = read(stdin, String)
tokens = split(input_str)
if !isempty(tokens)
    n = parse(Int64, tokens[1])
    a = [parse(Int64, tokens[i]) for i in 2:(n+1)]
    println(khong_giam(a) ? "YES" : "NO")
end