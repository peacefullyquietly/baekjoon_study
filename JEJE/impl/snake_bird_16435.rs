use std::io::{stdin, Read, stdout, Write, BufWriter};
use std::collections::BinaryHeap;

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i64>);

    let n = input.next().unwrap();
    let mut length = input.next().unwrap();

    let mut pq = BinaryHeap::new();
    for _ in 0..n{
        pq.push(-input.next().unwrap());
    }

    while !pq.is_empty() {
        if length >= -pq.pop().unwrap(){
            length += 1;
        }else{
            break;
        }
    }

    write!(writer, "{}", length).unwrap();
}