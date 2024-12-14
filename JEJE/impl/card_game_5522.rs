use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
    write!(writer, "{}", input.sum::<i32>()).unwrap();
}