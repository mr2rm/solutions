let [n, b] = readline()
	.split(" ")
	.map((x) => parseInt(x));

let res = "";
while (n != 0) {
	let x = n % b;
	if (x >= 10) x = String.fromCharCode("A".charCodeAt(0) + (x - 10));
	res = x + res;
	n = Math.floor(n / b);
}

console.log(res);
