function bubble_sort!(a::Vector{Int})
    n = length(a)
    for i in 1:(n - 1)
        for j in 1:(n - i)
            if a[j] > a[j + 1]
                a[j], a[j + 1] = a[j + 1], a[j]
            end
        end
    end
end

sizes = [1000, 2000, 4000, 8000]
println("Kich thuoc n | Thoi gian (s)")
for n in sizes
    a = collect(n:-1:1)
    
    t0 = time_ns()
    bubble_sort!(a)
    t1 = time_ns()
    
    diff = (t1 - t0) / 1e9
    println(rpad(n, 12), " | ", diff)
end