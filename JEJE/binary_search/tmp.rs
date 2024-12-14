use std::io::{self, Read, Write, BufWriter};

fn main() {
    const BIAS: usize = 10_000_000;
    let mut bitset = vec![false; BIAS << 1 | 1];

    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut numbers = input.split_whitespace().map(|num| num.parse::<i32>().unwrap());

    let n = numbers.next().unwrap();
    for _ in 0..n {
        let num = numbers.next().unwrap() as usize;
        bitset[num + BIAS] = true;
    }

    let m = numbers.next().unwrap();
    let stdout = io::stdout();
    let mut writer = BufWriter::new(stdout.lock());
    for _ in 0..m {
        let result = if bitset[numbers.next().unwrap() as usize + BIAS] { "1 " } else { "0 " };
        write!(writer, "{}", result).unwrap();
    }
    writer.flush().unwrap();
    println!();
}