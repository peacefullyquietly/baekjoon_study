let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ');

let num = Number(input);
let ans = 1;
for (let i = 1; i <= num; i++) {
    ans *= i;
}
console.log(ans);