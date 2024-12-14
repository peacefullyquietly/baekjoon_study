// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split((/ |\n/)).map(Number);

let input_iterator = input[Symbol.iterator]();

function next() {
    return input_iterator.next().value;
}

let original = [1, 1, 2, 2, 2, 8];
let ans = [...original].map((val) => {
    return val - input_iterator.next().value;
});

console.log(ans.join(' '));