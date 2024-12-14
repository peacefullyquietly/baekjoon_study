// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);
        
    write!(writer, "{}", input.map(|score| if score < 40 { 40 } else { score })
                              .sum::<i32>()
                              /5
          ).unwrap();
}