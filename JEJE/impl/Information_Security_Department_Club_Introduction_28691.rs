// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let ans;
    let name = input.next().unwrap();
    
    match name{
        "M"=> ans="MatKor",
        "W" => ans="WiCys",
        "C" => ans="CyKor",
        "A" => ans="AlKor",
        "$" => ans="$clear",
        &_ => ans="2013.12",
    }

    write!(writer, "{}\n", ans).unwrap();
}