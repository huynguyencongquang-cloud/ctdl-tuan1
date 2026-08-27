function la_nguyen_to(n::Int64)::Bool
    if n < 2
        return false
    end
    for i in 2:floor(Int64, sqrt(n))
        if n % i == 0
            return false
        end
    end
    return true
end

function sang_eratosthenes(n::Int64)::Vector{Int64}
    if n < 2
        return Int64[]
    end
    is_prime = fill(true, n + 1)
    is_prime[1] = is_prime[2] = false # Julia chỉ số từ 1, index 1 tương ứng số 0, index 2 tương ứng số 1
    
    # Ứng với các số từ 2 đến sqrt(n)
    limit = floor(Int64, sqrt(n))
    for p in 2:limit
        if is_prime[p + 1]
            for i in (p * p):p:n
                is_prime[i + 1] = false
            end
        end
    end
    
    primes = Int64[]
    for p in 2:n
        if is_prime[p + 1]
            push!(primes, p)
        end
    end
    return primes
end

input_str = readline()
if !isempty(input_str)
    n = parse(Int64, input_str)
    primes = sang_eratosthenes(n)
    println(join(primes, " "))
end