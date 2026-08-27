    function giai_thua(n::Int64)
        if n < 0
            return Int64(0), false
        end
        kq = Int64(1)
        llong_max = typemax(Int64)
        for i in 1:n
            if div(llong_max, i) < kq
                return Int64(0), false # Bị tràn số
            end
            kq *= i
        end
        return kq, true
    end

    input_str = readline()
    if !isempty(input_str)
        n = parse(Int64, input_str)
        kq, ok = giai_thua(n)
        if ok
            println(kq)
        else
            println("Tran so")
        end
    end