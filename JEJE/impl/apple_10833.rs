use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let mut ans = 0;
    let tc = input.next().unwrap();

    for _ in 0..tc{
        let a = input.next().unwrap();
        let b = input.next().unwrap();
        ans += b%a;
    }

    write!(writer, "{ans}").unwrap();
}