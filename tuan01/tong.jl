function main()
    tokens = Int64[]
    for line in readlines(stdin)
        for token in split(line)
            push!(tokens, parse(Int64, token))
        end
    end
    if isempty(tokens) return end
    n = tokens[1]
    arr = tokens[2:n+1]
    println("$(sum(arr)) $(maximum(arr))")
end

main()