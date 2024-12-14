let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ');

let num = Number(input);
let ans = 0;
for (let i = 1; i <= num; i++) {
    ans += i;
}
console.log(ans);