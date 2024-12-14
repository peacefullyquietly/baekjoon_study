// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split((/ |\n/)).map(Number);

let input_iterator = input[Symbol.iterator]();

function next() {
    return input_iterator.next().value;
}

function make_matrix(row, col) {
    let matrix = [];
    for (let i = 0; i < row; i++) {
        let row = [];
        for (let j = 0; j < col; j++) {
            row.push(next());
        }
        matrix.push(row);
    }
    return matrix;
}

function matrix_multiplication(A, B) {
    let result = [];
    let row = A.length;
    let col = B[0].length;

    for (let i = 0; i < row; i++) {
        let row = [];
        for (let j = 0; j < col; j++) {
            let sum = 0;
            for (let k = 0; k < A[0].length; k++) {
                sum += A[i][k] * B[k][j];
            }
            row.push(sum);
        }
        result.push(row);
    }
    return result;
}

let A = make_matrix(next(), next());
let B = make_matrix(next(), next());

console.log(matrix_multiplication(A, B).map(row => row.join(' ')).join('\n'));