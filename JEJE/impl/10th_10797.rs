// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let mut ans = 0;
    let flag = input.next().unwrap();

    for _ in 0..5{
        let num = input.next().unwrap();
        if (num%10) == flag{
            ans+=1;
        }
    }

    write!(writer, "{ans}").unwrap();
}