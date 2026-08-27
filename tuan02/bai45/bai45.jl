function luy_thua_mod(a::Int64, b::Int64, m::Int64)::Int64
    r = Int64(1 % m)
    a_mod = Int128(a % m)
    m128 = Int128(m)
    r128 = Int128(r)
    
    while b > 0
        if (b & 1) == 1
            r128 = (r128 * a_mod) % m128
        end
        a_mod = (a_mod * a_mod) % m128
        b >>= 1
    end
    return Int64(r128)
end

input_str = read(stdin, String)
tokens = split(input_str)
if length(tokens) >= 3
    a = parse(Int64, tokens[1])
    b = parse(Int64, tokens[2])
    m = parse(Int64, tokens[3])
    println(luy_thua_mod(a, b, m))
end