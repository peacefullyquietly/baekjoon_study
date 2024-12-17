// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);

    let mut n = input.next().unwrap();
    let mut cnt = [0; 10];
    
    while n > 0 {
        cnt[(n % 10) as usize] += 1;
        n /= 10;
    }
    
    cnt[6] = (cnt[6] + cnt[9] + 1) / 2;
    cnt[9] = 0;
    
    let ans = cnt.iter().max().unwrap();
    write!(writer, "{}", ans).unwrap();
}