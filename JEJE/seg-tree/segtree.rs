use std::io::{self, BufRead};

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
    if left <= start && right >= end {
        return tree[node];
    }
    let mid = (start + end) / 2;
    return quary(tree, node*2, start, mid, left, right)+quary(tree, node*2+1, mid + 1, end, left, right);
}

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    let mut reader = io::BufReader::new(stdin.lock());
    let mut lines = stdin.lock().lines();
    let mut line = lines.next().unwrap().unwrap();
    let mut iter = line.split_whitespace();
    let stdout = stdout();
    let mut lock = stdout.lock();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();

    let tree: Vec<i64> = vec![0; 4 * n];

    for _ in 0..m {
        io::stdin().read_line(&mut buf).unwrap();
        let mut info: Vec<i32> = buf.split_whitespace().map(|x| x.parse().unwrap()).collect();
        buf.clear();
        let mut a = info[0];
        let mut b = info[1];
        let mut c = info[2];
        match a {
            1 => {
                update(&mut tree, 1, 0, n - 1, b as usize, c as i64);
            }
            2 => {
                writeln!(lock, "{}", quary(&tree, 1, 0, n - 1, b as usize, c as usize)).unwrap();
            }
            _ => {}
        }
    }
}