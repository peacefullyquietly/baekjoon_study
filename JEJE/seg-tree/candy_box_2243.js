let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split((/ |\n/)).map(Number);
let input_iterator = input[Symbol.iterator]();

function next() {
    return input_iterator.next().value;
}

const MAX = 1000001;
let tree = new Array(MAX * 4).fill(0);

function update(node, start, end, idx, chg){
    if(idx < start || idx > end) return;
    if(start === end){
        tree[node] += chg;
        return;
    }
    let mid = Math.floor((start + end) / 2);
    update(node*2, start, mid, idx, chg);
    update(node*2+1, mid+1, end, idx, chg);
    tree[node] = tree[node*2]+tree[node*2+1];
}

function getCandy(node, start, end, want){
    if(start === end) return start;
    if(want <= tree[node*2]){
        return getCandy(node*2, start, Math.floor((start+end)/2), want);
    } else {
        return getCandy(node*2+1, Math.floor((start+end)/2)+1, end, want-tree[node*2]);
    }
}

let query = next();
while(query--){
    if(next() === 1){
        let ans_idx = getCandy(1, 1, MAX, next());
        console.log(ans_idx);
        update(1, 1, MAX, ans_idx, -1);
    } else {
        update(1, 1, MAX, next(), next());
    }
}
