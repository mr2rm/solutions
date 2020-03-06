var arr = [
	"Alborz",
	"Ardabil",
	"Bushehr",
	"Chaharmahal and Bakhtiari",
	"East Azerbaijan",
	"Isfahan",
	"Fars",
	"Gilan",
	"Golestan",
	"Hamadan",
	"Hormozgan",
	"Ilam",
	"Kerman",
	"Kermanshah",
	"Khuzestan",
	"Kohgiluyeh and Boyer-Ahmad",
	"Kurdistan",
	"Lorestan",
	"Markazi",
	"Mazandaran",
	"North Khorasan",
	"Qazvin",
	"Qom",
	"Razavi Khorasan",
	"Semnan",
	"Sistan and Baluchestan",
	"South Khorasan",
	"Tehran",
	"West Azerbaijan",
	"Yazd",
	"Zanjan"
];

const appendChild = (parent, childs) => {
	childs.forEach(child => parent.appendChild(child));
	return parent;
};

const createElement = (tag, className, { text = null, onClick = null }) => {
	const element = document.createElement(tag);
	element.setAttribute("class", className);
	if (onClick) element.onclick = onClick;
	if (text) appendChild(element, [document.createTextNode(text)]);
	return element;
};

const removeAutoComplete = () => {
	const autoComplete = document.getElementsByClassName("autocomplete-items")[0];
	if (autoComplete) autoComplete.remove();
};

const input = document.getElementById("myInput");
input.addEventListener("input", e => {
	removeAutoComplete();

	value = e.target.value.toLowerCase();
	if (value.length === 0) return;

	const items = arr
		.filter(city => city.toLowerCase().startsWith(value))
		.map(city =>
			createElement("div", "item", {
				text: city,
				onClick: e => {
					input.value = city;
					removeAutoComplete();
				}
			})
		);

	if (items.length === 0)
		items.push(createElement("div", "not-found", { text: "Not Found!" }));

	const autoCompleteItems = appendChild(
		createElement("div", "autocomplete-items", {}),
		items
	);

	appendChild(document.getElementsByClassName("autocomplete")[0], [
		autoCompleteItems
	]);
});

document.body.addEventListener("click", e => {
	removeAutoComplete();
});
