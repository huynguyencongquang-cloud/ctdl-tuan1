using Random
using Printf

function kc_euclid(u::Vector{Float64}, v::Vector{Float64})
    return sqrt(sum((u .- v) .^ 2))
end

function do_thoi_gian(n::Int; q::Int = 1000, d::Int = 20)
    Random.seed!(12345)
    train = [rand(d) for _ in 1:n]
    test = [rand(d) for _ in 1:q]

    start_time = time()

    for i in 1:q
        min_dist = -1.0
        for j in 1:n
            dist = kc_euclid(test[i], train[j])
            if min_dist < 0 || dist < min_dist
                min_dist = dist
            end
        end
    end

    elapsed = time() - start_time
    @printf("n = %d | Thoi gian: %.4fs\n", n, elapsed)
end

for n in [1000, 10000, 100000]
    do_thoi_gian(n)
end