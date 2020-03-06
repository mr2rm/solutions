let [n, m] = readline()
	.split(" ")
	.map(x => parseInt(x));

let mat = [];
for (let i = 0; i < n; ++i) {
	let l = readline();
	mat.push(l);
}

const countL = (i, j) => {
	let maxi = Math.min(Math.floor((n - i) / 2), m - j);
	let cnt = 0;
	let ok = true;
	for (let k = 2; k <= maxi; ++k) {
		let v;
		for (v = i; ok && v < i + 2 * k; ++v) if (mat[v][j] !== "*") ok = false;
		for (let h = j; ok && h < j + k; ++h) if (mat[v - 1][h] !== "*") ok = false;
		if (!ok) break;
		cnt += 1;
	}
	return cnt;
};

let res = 0;
for (let i = 0; i < n; ++i) for (let j = 0; j < m; ++j) res += countL(i, j);
print(res);
