function cua_so_truot(a::Vector{Int64}, k::Int64)::Tuple{Int64, Int64}
    n = length(a)
    if n < k || k <= 0
        return (0, -1)
    end

    current_sum = sum(a[1:k])
    max_sum = current_sum
    best_start = 1

    for i in (k + 1):n
        current_sum += a[i] - a[i - k]
        if current_sum > max_sum
            max_sum = current_sum
            best_start = i - k + 1
        end
    end

    # Tra ve 0-based index cho dong bo voi C++ va Python
    return (max_sum, best_start - 1)
end

input_str = read(stdin, String)
tokens = split(input_str)
if !isempty(tokens)
    n = parse(Int64, tokens[1])
    k = parse(Int64, tokens[2])
    idx = 3
    if idx <= length(tokens) && tokens[idx] == "/"
        idx += 1
    end
    a = [parse(Int64, tokens[i]) for i in idx:(idx+n-1)]
    res = cua_so_truot(a, k)
    println("$(res[1]) $(res[2])")
end