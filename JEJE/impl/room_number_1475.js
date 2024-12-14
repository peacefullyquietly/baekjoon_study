// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split((/ |\n/)).map(Number);

let input_iterator = input[Symbol.iterator]();

function next() {
    return input_iterator.next().value;
}

let num = next();
let arr = Array.from({length: 10}, () => 0);

while (num > 0) {
    arr[num % 10]++;
    num = ~~(num / 10);
}

arr[6] = ~~((arr[6] + arr[9] + 1) / 2);
arr[9] = 0;

console.log(Math.max(...arr));
