let [n, k] = readline()
	.split(" ")
	.map(x => parseInt(x));

for (let i = 0; i < n; ++i) {
	let x = parseInt(readline());
	k -= x;
}

print(k > 0 ? "NO" : "YES");
