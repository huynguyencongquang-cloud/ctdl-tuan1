using Printf

struct Mau
    x::Vector{Float64}
    y::String
end

kc_euclid(u::Vector{Float64}, v::Vector{Float64}) = sqrt(sum((u .- v).^2))
kc_manhattan(u::Vector{Float64}, v::Vector{Float64}) = sum(abs.(u .- v))

function do_chinh_xac_bo_mot_mau(D::Vector{Mau}, fn_khoang_cach)::Float64
    n = length(D)
    if n == 0
        return 0.0
    end
    
    count_correct = 0
    for i in 1:n
        nhan_du_doan = ""
        min_dist = -1.0
        for j in 1:n
            if i == j
                continue
            end
            dist = fn_khoang_cach(D[i].x, D[j].x)
            if min_dist < 0 || dist < min_dist
                min_dist = dist
                nhan_du_doan = D[j].y
            end
        end
        if nhan_du_doan == D[i].y
            count_correct += 1
        end
    end
    return count_correct / n
end

function doc_du_lieu(ten_tep::String)::Vector{Mau}
    D = Vector{Mau}()
    if !isfile(ten_tep)
        return D
    end
    
    for line in eachline(ten_tep)
        tokens = split(strip(line))
        if isempty(tokens) || length(tokens) == 2  # Bỏ qua dòng trống hoặc dòng khai báo (30 4)
            continue
        end
        if length(tokens) >= 3
            x = [parse(Float64, replace(t, "," => ".")) for t in tokens[1:end-1]]
            y = String(tokens[end])
            push!(D, Mau(x, y))
        end
    end
    return D
end

D = doc_du_lieu("data.txt")
if !isempty(D)
    acc_e = do_chinh_xac_bo_mot_mau(D, kc_euclid)
    acc_m = do_chinh_xac_bo_mot_mau(D, kc_manhattan)
    @printf("Euclid: %.2f%%\n", acc_e * 100)
    @printf("Manhattan: %.2f%%\n", acc_m * 100)
end