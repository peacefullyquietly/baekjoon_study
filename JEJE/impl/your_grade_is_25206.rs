// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};

fn get_grade(s: &str) -> f32{
    let mut ret;
    match s{
        "A+"=> ret=4.5,
        "A0" => ret=4.0,
        "B+" => ret=3.5,
        "B0" => ret=3.0,
        "C+" => ret=2.5,
        "C0" => ret=2.0,
        "D+" => ret=1.5,
        "D0" => ret=1.0,
        "F" => ret=0.0,
        &_ => ret=2013.12,
    }
    ret
}

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let mut cnt = 0.0;
    let mut sum = 0.0;
    for _ in 0..20{
        let _title = input.next().unwrap();
        let n = input.next().unwrap().parse::<f32>().unwrap();
        let grade = input.next().unwrap();

        if grade == "P"{
            continue;
        }else{
            sum += n*get_grade(grade);
            cnt += n;
        }
    }

    write!(writer, "{}", sum/cnt).unwrap();
}