use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let input: Vec<i32> = buf.split_ascii_whitespace()
                             .flat_map(str::parse::<i32>)
                             .collect();

    let (burger, drink) = input.split_at(3);
    
    write!(writer, "{}", burger.iter().min().unwrap_or(&0)
                        +drink.iter().min().unwrap_or(&0)
                        -50
          ).unwrap();
}
