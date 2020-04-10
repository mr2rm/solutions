let n = Int(readLine()!)!
let line = readLine()!
var colors = line.split(separator: " ").map{Int($0)!}
var res: [(Int, Int)] = []

for i in 0...n - 1 {
    if colors[i] == -1 {
        continue
    }
    for j in stride(from: i + 1, to: n - 1, by: 1) {
        if colors[i] == colors[j] {
            colors[j] = -1
            res.append((i + 1, j + 1))
            break
        }
    }
}

print(res.count);
for r in res {
    print(r.0, r.1)
}
