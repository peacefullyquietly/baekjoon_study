use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let mut arr = [[0; 9]; 9];
    let mut max = 0;
    let mut x = 0;
    let mut y = 0;

    for i in 0..9{
        for j in 0..9{
            arr[i][j] = input.next().unwrap();
            if arr[i][j] > max{
                max = arr[i][j];
                x = j;
                y = i;
            }
        }
    }

    write!(writer, "{max}\n{} {}", y+1, x+1).unwrap();
}