res = maxi = -1
for i in (1..4) do
    x = gets.split.map(&:to_i).max
    if x > maxi
        maxi, res = x, i
    end
end
puts res
