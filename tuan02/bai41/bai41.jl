function tich_lon_nhat(a::Vector{Int64})::Int64
    if isempty(a)
        return 0
    end
    
    max_prod = Int64(a[1])
    min_prod = Int64(a[1])
    ans = Int64(a[1])
    
    for i in 2:length(a)
        if a[i] < 0
            max_prod, min_prod = min_prod, max_prod
        end
        
        max_prod = max(Int64(a[i]), max_prod * a[i])
        min_prod = min(Int64(a[i]), min_prod * a[i])
        
        ans = max(ans, max_prod)
    end
    
    return ans
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
    println(tich_lon_nhat(a))
end