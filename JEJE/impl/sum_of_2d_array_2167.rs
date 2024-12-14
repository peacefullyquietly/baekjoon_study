// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);

    let mut dp = [[0 as i32; 301]; 301];
    let n = input.next().unwrap() as usize;
    let m = input.next().unwrap() as usize;

    for i in 1..=n {
        for j in 1..=m {
            dp[i][j] = input.next().unwrap();
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    let k = input.next().unwrap() as usize;
    for _ in 0..k {
        let i = input.next().unwrap() as usize;
        let j = input.next().unwrap() as usize;
        let x = input.next().unwrap() as usize;
        let y = input.next().unwrap() as usize;

        write!(writer, "{}\n", dp[x][y] + dp[i-1][j-1] - dp[i-1][y] - dp[x][j-1]).unwrap();
    }
}
