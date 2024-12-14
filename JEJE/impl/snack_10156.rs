use std::io::{stdin, Read, stdout, Write, BufWriter};
// use std::convert::TryInto;

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i64>);

    println!("{:?}", input);

    let mut ans = (input.next().unwrap() * input.next().unwrap()) - input.next().unwrap();
    
    if ans < 0{
        ans = 0;
    }

    write!(writer, "{ans}").unwrap();
}