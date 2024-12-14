use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);

    while let (Some(n), Some(s)) = (input.next(), input.next()) {
        writeln!(writer, "{}", s/(n+1)).unwrap();
    }
}