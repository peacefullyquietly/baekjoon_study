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