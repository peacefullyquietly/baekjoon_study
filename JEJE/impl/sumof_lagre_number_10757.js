let fs = require('fs');
let nums = fs.readFileSync('/dev/stdin').toString().split(' ').map(BigInt);

console.log((nums[0] + nums[1]).toString());