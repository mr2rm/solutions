import React from "react";

const Input = ({ handleChange, hint }) => {
	return (
		<div className="input">
			<label htmlFor="input" data-testid="hint">
				{hint}
			</label>
			<input
				data-testid="input"
				type="text"
				id="input"
				onChange={handleChange}
			/>
		</div>
	);
};

export default Input;
