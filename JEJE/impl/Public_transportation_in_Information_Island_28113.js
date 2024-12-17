// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split((/ |\n/)).map(Number);
let input_iterator = input[Symbol.iterator]();

function next() {
    return input_iterator.next().value;
}

let n = next();
let a = next();
let b = next();

//let subCan = n <= b ? true : false;

if (a < b || n > b){
    console.log("Bus");
} else if (a === b){
    console.log("Anything");
} else {
    console.log("Subway");
}