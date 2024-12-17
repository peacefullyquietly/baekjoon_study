// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
let fs = require('fs');
let nums = fs.readFileSync('/dev/stdin').toString().split(' ').map(BigInt);

console.log((nums[0] + nums[1]).toString());