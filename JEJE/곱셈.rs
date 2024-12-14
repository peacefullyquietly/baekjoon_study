// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io;
fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let num = input.trim().parse::<i32>().unwrap();
    for i in 1..10
    {
        println!("{} * {} = {}", num, i, i*num);
    }
}