using Printf

struct Mau
    x::Vector{Float64}
    y::String
end

function doc_du_lieu(ten_tep::String)::Vector{Mau}
    D = Vector{Mau}()
    if !isfile(ten_tep)
        return [
            Mau([5.1, 3.5, 1.4, 0.2], "Setosa"),
            Mau([4.9, 3.2, 1.4, 0.2], "Setosa"),
            Mau([4.7, 3.2, 1.3, 0.2], "Setosa"),
            Mau([7.0, 3.2, 4.7, 1.4], "Versicolor"),
            Mau([6.4, 3.2, 4.5, 1.5], "Versicolor"),
            Mau([6.5, 2.8, 4.6, 1.5], "Versicolor"),
            Mau([6.3, 3.3, 6.0, 2.5], "Virginica"),
            Mau([5.8, 2.7, 5.1, 1.9], "Virginica"),
            Mau([6.5, 3.0, 5.8, 2.2], "Virginica")
        ]
    end

    content = read(ten_tep, String)
    tokens = split(content)
    if !isempty(tokens)
        n = parse(Int64, tokens[1])
        d = parse(Int64, tokens[2])
        idx = 3
        for i in 1:n
            x = [parse(Float64, replace(tokens[j], "," => ".")) for j in idx:(idx+d-1)]
            idx += d
            y = String(tokens[idx])
            idx += 1
            push!(D, Mau(x, y))
        end
    end
    return D
end

kc_euclid(u::Vector{Float64}, v::Vector{Float64}) = sqrt(sum((u .- v).^2))
kc_manhattan(u::Vector{Float64}, v::Vector{Float64}) = sum(abs.(u .- v))

function lang_gieng_gan_nhat(q::Vector{Float64}, D::Vector{Mau}, fn_khoang_cach)::Tuple{String, Float64}
    nhan_tot_nhat = ""
    min_dist = -1.0

    for mau in D
        if length(mau.x) != length(q)
            continue
        end
        dist = fn_khoang_cach(q, mau.x)
        if min_dist < 0 || dist < min_dist
            min_dist = dist
            nhan_tot_nhat = mau.y
        end
    end
    return (nhan_tot_nhat, min_dist)
end

D = doc_du_lieu("data.txt")
line = readline()

cleaned = replace(line, r"(\d+),(\d+)" => s"\1.\2")
cleaned = replace(cleaned, r"[(),;]" => " ")
tokens = split(cleaned)
q = [parse(Float64, t) for t in tokens if !isempty(t)]

if !isempty(q)
    res_e = lang_gieng_gan_nhat(q, D, kc_euclid)
    res_m = lang_gieng_gan_nhat(q, D, kc_manhattan)
    @printf("Euclid: %s (%.4f)\n", res_e[1], res_e[2])
    @printf("Manhattan: %s (%.4f)\n", res_m[1], res_m[2])
end