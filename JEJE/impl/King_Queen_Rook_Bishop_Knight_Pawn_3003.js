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