let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split((/ |\n/)).map(Number);

let input_iterator = input[Symbol.iterator]();

function next() {
    return input_iterator.next().value;
}

let flag = next();
let tc = next();
let tmp = 0;

for (let i = 0; i < tc; i++){
    tmp += next() * next();
}

if (tmp === flag) {
    console.log("Yes");
} else {
    console.log("No");
}
