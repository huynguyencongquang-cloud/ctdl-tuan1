using Printf

struct Mau
    x::Vector{Float64}
    y::String
end

function doc_du_lieu(ten_tep::String)::Tuple{Vector{Mau}, Int64}
    D = Vector{Mau}()
    d = 4
    if !isfile(ten_tep)
        D = [
            Mau([5.1, 3.5, 1.4, 0.2], "Setosa"),
            Mau([4.9, 3.0, 1.4, 0.2], "Setosa"),
            Mau([4.7, 3.2, 1.3, 0.2], "Setosa"),
            Mau([4.6, 3.1, 1.5, 0.2], "Setosa"),
            Mau([5.0, 3.6, 1.4, 0.2], "Setosa"),
            Mau([7.0, 3.2, 4.7, 1.4], "Versicolor"),
            Mau([6.4, 3.2, 4.5, 1.5], "Versicolor"),
            Mau([6.9, 3.1, 4.9, 1.5], "Versicolor"),
            Mau([5.5, 2.3, 4.0, 1.3], "Versicolor"),
            Mau([6.5, 2.8, 4.6, 1.5], "Versicolor"),
            Mau([6.3, 3.3, 6.0, 2.5], "Virginica"),
            Mau([5.8, 2.7, 5.1, 1.9], "Virginica"),
            Mau([7.1, 3.0, 5.9, 2.1], "Virginica"),
            Mau([6.3, 2.9, 5.6, 1.8], "Virginica"),
            Mau([6.5, 3.0, 5.8, 2.2], "Virginica")
        ]
        return D, d
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
    return D, d
end

function lang_gieng_gan_nhat(q::Vector{Float64}, D::Vector{Mau})::Tuple{String, Float64}
    nhan_tot_nhat = ""
    min_dist = -1.0

    for mau in D
        if length(mau.x) != length(q)
            continue
        end
        dist_sq = sum((q[i] - mau.x[i])^2 for i in 1:length(q))
        dist = sqrt(dist_sq)

        if min_dist < 0 || dist < min_dist
            min_dist = dist
            nhan_tot_nhat = mau.y
        end
    end
    return (nhan_tot_nhat, min_dist)
end

D, d = doc_du_lieu("data.txt")
line = readline()

cleaned = replace(line, r"(\d+),(\d+)" => s"\1.\2")
cleaned = replace(cleaned, r"[(),;]" => " ")
tokens = split(cleaned)
q = [parse(Float64, t) for t in tokens if !isempty(t)]

if !isempty(q)
    res = lang_gieng_gan_nhat(q, D)
    # Định dạng 4 chữ số thập phân
    @printf("%s %.4f\n", res[1], res[2])
end