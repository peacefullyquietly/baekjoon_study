use std::io::{stdin, Read, stdout, Write, BufWriter};


fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let s = input.next().unwrap();

    let mut arr = [0; 26];
    for c in s.bytes(){
        let idx = c as usize - 97;
        arr[idx] += 1;
    }

    for i in &arr{
        write!(writer, "{} ", i).unwrap();
    }
    write!(writer, "\n").unwrap();
}