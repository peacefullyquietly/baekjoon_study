use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);

    let L = input.next().unwrap();
    let P = input.next().unwrap();

    let flag = L*P;

    for _ in 0..5{
        let tmp = input.next().unwrap();
        write!(writer, "{} ", tmp - flag).unwrap();
    }
}