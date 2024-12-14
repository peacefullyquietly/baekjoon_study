use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let sum: i32 = buf
        .trim()
        .split_ascii_whitespace()
        .skip(1)
        .flat_map(str::parse::<i32>)
        .sum();

    write!(writer, "{:#?}\n", sum).unwrap();
}