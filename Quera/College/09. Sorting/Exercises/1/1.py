def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def bubble_sort(arr):
	n = len(arr)
	for _ in range(n):
		for i in range(n - 1):
			if arr[i + 1] < arr[i]:
				arr[i], arr[i + 1] = arr[i + 1], arr[i]

def insertion_sort(arr):
	n = len(arr)
	for i in range(1, n):
		p = i
		while p > 0 and arr[p] < arr[p - 1]:
			arr[p], arr[p-1] = arr[p - 1], arr[p]
			p -= 1


n, k = map(int, input().split())
numbers = list(map(int, input().split()))

res = -1
insertion_sort(numbers)
for i in range(n):
	cnt = 1
	for j in range(i + 1, n):
		if numbers[j] != numbers[j - 1]:
			cnt += 1
		if cnt == k:
			diff = numbers[j] - numbers[i]
			res = diff if res == -1 else min(diff, res)
			break
print(res)
