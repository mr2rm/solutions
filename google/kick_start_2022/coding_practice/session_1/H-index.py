def h_index(_, citations):
    ans = []
    cnt = [0] * 100_001
    h, lte, ute = 1, 0, 0

    for i, c in enumerate(citations, start=1):
        cnt[c] += 1
        if c <= h:
            lte += 1
        if c >= h:
            ute += 1

        if ute == h:
            h += 1
            ute = i - lte
            lte += cnt[h]
        ans.append(h - 1)

    return ans


if __name__ == '__main__':
    t = int(input())

    for test_case in range(1, t + 1):
        n = int(input())                      # The number of papers
        # The number of citations for each paper
        citations = list(map(int, input().split()))
        h_index_scores = h_index(n, citations)
        print("Case #" + str(test_case) + ": " +
              ' '.join(map(str, h_index_scores)))
