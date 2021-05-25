let n = parseInt(readline());
let arr = readline()
	.split(" ")
	.map((x) => parseInt(x));

let cnt = 0;
let lastSign = null;

for (let i = 1; i < n; ++i) {
	let diff = arr[i] - arr[i - 1];
	let sign = diff < 0 ? -1 : diff > 0 ? 1 : 0;
	if (cnt === 0 && sign === 0) continue;
	if (lastSign !== null && sign !== lastSign) cnt++;
	lastSign = sign;
}

console.log(cnt <= 1 ? "Yes" : "No");
