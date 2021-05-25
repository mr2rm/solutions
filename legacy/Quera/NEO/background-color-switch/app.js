const buttonElements = document.getElementsByClassName("button");
Array.from(buttonElements).forEach(button => {
	const color = button.id;
	button.addEventListener("click", () => {
		document.body.style.background = color;
	});
});
