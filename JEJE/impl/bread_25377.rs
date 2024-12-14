// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};
use std::convert::TryInto;

fn main() {
    let mut buffer = String::new();
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    stdin().read_to_string(&mut buffer).unwrap();
    let mut input = buffer.split_ascii_whitespace().flat_map(str::parse::<usize>);

    // for num in input {
    //     println!("{}", num);
    // }
 
    let tc = input.next().unwrap();
    let mut answer:i32 = 10001;
    for _ in 0..tc{
        // println!("{} {}",answer,tc);
        let mut arr = [0; 2];
        for i in 0..2{
            arr[i] = input.next().unwrap();
        }

        if arr[0] <= arr[1] {
            answer = std::cmp::min(answer,arr[1].try_into().unwrap());
        }
    }

    if answer == 10001 {
        answer = -1;
    }

    write!(writer, "{answer}").unwrap();
}