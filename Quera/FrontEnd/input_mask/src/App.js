import React, { useState } from "react";
import Input from "./Input";
import cityList from "./cities.json";

function App() {
	const [currentHint, setCurrentHint] = useState("");

	return (
		<div>
			<Input
				handleChange={(e) => {
					let inputValue = e.target.value;
					let hint = "";
					if (inputValue !== "")
						hint = cityList.find((city) => city.startsWith(inputValue));
					setCurrentHint(hint);
				}}
				hint={currentHint}
			></Input>
		</div>
	);
}

export default App;
