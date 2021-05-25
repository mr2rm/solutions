var readline = require("readline");
var rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
	terminal: false,
});

var lineCount = 0;
var res = "";
var n, m;
var mat = [];

rl.on("line", function (line) {
	if (lineCount === 0) [n, m] = line.split(" ").map((x) => parseInt(x));
	else mat.push(line);
	if (lineCount === m) {
		for (let i = 0; i < n; ++i) {
			let wc = mat.map((row) => row[i]).filter((c) => c === "W").length;
			res += wc % 2 === 0 ? "B" : "F";
		}
		console.log(res);
	}
	lineCount++;
});
