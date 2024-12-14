// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};
// use std::convert::TryInto;

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let tmp: Vec<_> = buf.split_ascii_whitespace()
                         .flat_map(str::parse::<i32>)
                         .filter(|&num| num % 2 != 0)
                         .collect();

    let ans1:i32 = tmp.iter().sum();
    let ans2:i32 = *tmp.iter().min().unwrap_or(&-1);
    
    if ans2 != -1{
        write!(writer, "{ans1}\n").unwrap();
    }
    write!(writer, "{ans2}\n").unwrap();
    
}