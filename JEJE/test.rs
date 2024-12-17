// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
// fn main()
// {
//     let mut v = vec![];
//     match v.is_empty()
//     {
//         true => v.push(0),
//         false => v.push(100),
//     }
//     println!("{:?}", v);
// }

// fn main()
// {
//     let s = String::from("hello");
//     println!("{}", &s[..1]);
//     println!("{}", &s[..=1]);
//     println!("{}", &s[-1..]);
// }

fn main()
{
    let s = String::from("1 2 3 4 5 6 7 8");
    let mut s = s.split_whitespace();
    let num: u32 = s
                .next(2)
                .unwrap()
                .parse()
                .unwrap();
    println!("{}", num)
}