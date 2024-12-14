use std::io::{stdin, stdout, Read, Write, BufWriter};
use std::str::FromStr;
use std::vec::IntoIter;
use std::cmp::{min, max};

fn update(tree: &mut Vec<i64>, node: usize, start: usize, end: usize, idx: usize, val: i64) {
    if idx < start || idx > end {
        return;
    }
    if start == end {
        tree[node] = val;
        return;
    }
    let mid = (start + end) / 2;
    update(tree, node*2, start, mid, idx, val);
    update(tree, node*2+1, mid + 1, end, idx, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

fn quary(tree: &Vec<i64>, node: usize, start: usize, end: usize, left: usize, right: usize) -> i64 {
    if left > end || right < start {
        return 0;
    }
    if left <= start && right >= end{
        return tree[node];
    }
    let mid = (start + end) / 2;
    return quary(tree, node*2, start, mid, left, right)+quary(tree, node*2+1, mid + 1, end, left, right);
}

fn main() {

    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i64>);
 
    let n = input.next().unwrap() as usize;
    let m = input.next().unwrap();
    let mut tree = vec![0;n*4];

    for _ in 0..m {
        
        let a = input.next().unwrap();
        let b = input.next().unwrap() as usize;
        let c = input.next().unwrap() as usize;

        if a==1 {
            update(&mut tree, 1, 0, n - 1, b-1, c as i64);
        }else{
            writeln!(writer, "{}", quary(&tree, 1, 0, (n - 1), min(b-1,c-1), max(c-1,b-1))).unwrap();
        }
    }
}