use std::io::{stdin, Read, stdout, Write, BufWriter};
use std::cmp::Reverse;
use std::collections::BinaryHeap;
use std::cmp::{min, max};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);

    let n = input.next().unwrap() as usize;
    let mut arr = vec![(0,0); n];
    
    for i in arr.iter_mut() {
        let (tmp_a, tmp_b) = (input.next().unwrap(), input.next().unwrap());
        i.0 = min(tmp_a, tmp_b);
        i.1 = max(tmp_a, tmp_b);
    }
    arr.sort_by(|a, b| a.1.cmp(&b.1));
    let l = input.next().unwrap();
    let mut ans = 0;

    let mut pq = BinaryHeap::new();
    for i in 0..n {
        let iL = arr[i].0;
        let iR = arr[i].1;

        if iR - iL <= l {
            pq.push(Reverse(iL));
        } else {
            continue;    
        }

        while !pq.is_empty() && pq.peek().unwrap().0 < iR - l {
            pq.pop();
        }
        ans = ans.max(pq.len());
    }
    write!(writer, "{}", ans).unwrap();
}
