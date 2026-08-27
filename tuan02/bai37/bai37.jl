function dem(a::Vector{Int64})::Tuple{Int64, Int64, Int64}
    chan = 0
    le = 0
    am = 0
    for x in a
        if x < 0
            am += 1
        end
        if x % 2 == 0
            chan += 1
        else
            le += 1
        end
    end
    return chan, le, am
end

input_str = read(stdin, String)
tokens = split(input_str)
if !isempty(tokens)
    n = parse(Int64, tokens[1])
    a = [parse(Int64, tokens[i]) for i in 2:(n+1)]
    chan, le, am = dem(a)
    println("$chan $le $am")
end