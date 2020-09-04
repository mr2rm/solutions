import '@testing-library/jest-dom/extend-expect';
import React from 'react';
import {render, fireEvent} from '@testing-library/react';
import App from '../App';
import cities from '../cities.json';

test('sample test', () => {
  const {getByTestId} = render(<App />);

  const input = getByTestId('input');
  const hint = getByTestId('hint');

  expect(hint).toHaveTextContent('');

  fireEvent.change(input, {target: {value: 'New'}});
  expect(hint).toHaveTextContent('New Bedford');

  fireEvent.change(input, {target: {value: 'Mi'}});
  expect(hint).toHaveTextContent('Miami');

  fireEvent.change(input, {target: {value: ''}});
  expect(hint).toHaveTextContent('');
});
