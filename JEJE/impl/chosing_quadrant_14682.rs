use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);

    if input.next().unwrap() < 0 {
        if input.next().unwrap() < 0 {
            write!(writer, "3");
        }else{
            write!(writer, "2");
        }
    } else {
        if input.next().unwrap() < 0 {
            write!(writer, "4");
        }else{
            write!(writer, "1");
        }
    }
}