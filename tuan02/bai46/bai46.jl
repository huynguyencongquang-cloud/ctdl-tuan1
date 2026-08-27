struct Mau
    x::Vector{Float64}
    y::String
end

function lang_gieng_gan_nhat(q::Vector{Float64}, D::Vector{Mau})::Tuple{String, Float64}
    nhan_tot_nhat = ""
    min_dist = -1.0

    for mau in D
        dist_sq = sum((q[i] - mau.x[i])^2 for i in 1:length(q))
        dist = sqrt(dist_sq)

        if min_dist < 0 || dist < min_dist
            min_dist = dist
            nhan_tot_nhat = mau.y
        end
    end
    return (nhan_tot_nhat, min_dist)
end

D = [
    Mau([1.4, 0.2], "Setosa"),
    Mau([4.7, 1.4], "Versicolor"),
    Mau([4.9, 1.5], "Versicolor"),
    Mau([6.0, 2.5], "Virginica")
]

line = readline()
cleaned = replace(line, r"[(),;]" => " ")
tokens = split(cleaned)
q = [parse(Float64, t) for t in tokens if !isempty(t)]

if !isempty(q)
    res = lang_gieng_gan_nhat(q, D)
    println("$(res[1]) $(res[2])")
end