let moveCount, currentState;
let initialState = [
	[2, 3, 5],
	[1, 4, ""],
	[7, 8, 6],
];
let finalState = [
	[1, 2, 3],
	[4, 5, 6],
	[7, 8, ""],
];
let dir = [
	[-1, 0],
	[+1, 0],
	[0, -1],
	[0, +1],
];

let getId = (x, y) => 3 * x + y;
let getValue = (cell) => cell.lastChild.innerText;
let setValue = (cell, value) => (cell.lastChild.innerText = value);

let setMoveCount = (value) => {
	moveCount = value;
	let moves = document.getElementById("moves");
	moves.innerText = value;
};

let updateGameStatus = () => {
	let status = "You won !";
	finalState.forEach((row, i) => {
		row.forEach((value, j) => {
			let cell = document.getElementById(getId(i, j));
			if (getValue(cell) != value) status = "Start moving Tile !";
		});
	});
	document.getElementById("game_status").innerText = status;
};

let move = (x, y) => {
	let cell = document.getElementById(getId(x, y));
	let cellValue = getValue(cell);
	dir.forEach(([dx, dy]) => {
		let tx = (x + dx + 3) % 3,
			ty = (y + dy + 3) % 3;
		let neighbour = document.getElementById(getId(tx, ty));
		if (getValue(neighbour) === "") {
			setValue(neighbour, cellValue);
			setValue(cell, "");
			setMoveCount(moveCount + 1);
			updateGameStatus();
		}
	});
};

function reset() {
	initialState.forEach((row, i) => {
		row.forEach((value, j) => {
			let cell = document.getElementById(getId(i, j));
			setValue(cell, value);
			cell.onclick = () => move(i, j);
		});
	});
	setMoveCount(0);
	updateGameStatus();
}

reset();
let resetButton = document.getElementsByClassName("btn")[0];
resetButton.onclick = () => reset();
