use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let N = input.next().unwrap();
    let K = input.next().unwrap();

    let mut ans = 0;
    let mut cnt = 0;

    let mut i = 1;
    while i <= N{
        if N%i == 0{
            cnt+=1;
        }
        if cnt == K{
            ans = i;
            break;
        }
        i+=1;
    }

    write!(writer, "{ans}").unwrap();
}