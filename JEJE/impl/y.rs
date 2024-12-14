use std::io::{Write, stdin, Read, stdout, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let n = buf.split_ascii_whitespace().flat_map(str::parse::<i32>).next().unwrap();

    if n == 1{
        write!(writer, "Leading the Way to the Future").unwrap();
        return;
    }
    write!(writer, "YONSEI").unwrap();
}