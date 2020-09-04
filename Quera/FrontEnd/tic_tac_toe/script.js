const statusDisplay = document.querySelector(".game--status");

let currentPlayer = "X";
let gameState = ["", "", "", "", "", "", "", "", ""];
let gameActive = true;
let winner = null;

const currentPlayerTurn = () => `It's ${currentPlayer}'s turn`;
const resultStatus = () =>
	winner ? `Player ${winner} has won` : `Game ended in a draw`;
const isGameOver = () => winner !== null || !gameState.includes("");

statusDisplay.innerHTML = currentPlayerTurn();

function handleCellPlayed(clickedCell, clickedCellIndex) {
	gameState[clickedCellIndex] = currentPlayer;
	clickedCell.innerHTML = currentPlayer;
}

function handlePlayerChange() {
	currentPlayer = currentPlayer === "X" ? "O" : "X";
	statusDisplay.innerHTML = currentPlayerTurn();
}

function getWinner(str) {
	switch (str) {
		case "OOO":
			return "O";
		case "XXX":
			return "X";
		default:
			return null;
	}
}

function updateResult() {
	for (let i = 0; winner === null && i < gameState.length; i += 3)
		winner = getWinner(gameState.slice(i, i + 3).join(""));

	for (let j = 0; winner === null && j < 3; ++j) {
		let row = "";
		for (let i = 0; i < 3; ++i) row += gameState[j + 3 * i];
		winner = getWinner(row);
	}

	if (winner === null)
		winner =
			getWinner(gameState[0] + gameState[4] + gameState[8]) ||
			getWinner(gameState[2] + gameState[4] + gameState[6]);

	if (isGameOver()) {
		gameActive = false;
		statusDisplay.innerHTML = resultStatus();
	}
}

function handleCellClick(clickedCellEvent) {
	if (!gameActive) {
		return;
	}
	const clickedCell = clickedCellEvent.target;
	const clickedCellIndex = parseInt(clickedCell.getAttribute("data-cell-index"));

	if (gameState[clickedCellIndex] !== "") {
		return;
	}

	handleCellPlayed(clickedCell, clickedCellIndex);
	handlePlayerChange();
	updateResult();
}

function handleRestartGame() {
	winner = null;
	gameActive = true;
	currentPlayer = "X";
	gameState = ["", "", "", "", "", "", "", "", ""];
	statusDisplay.innerHTML = currentPlayerTurn();
	document.querySelectorAll(".cell").forEach((cell) => (cell.innerHTML = ""));
}

document
	.querySelectorAll(".cell")
	.forEach((cell) => cell.addEventListener("click", handleCellClick));
document
	.querySelector(".game--restart")
	.addEventListener("click", handleRestartGame);
