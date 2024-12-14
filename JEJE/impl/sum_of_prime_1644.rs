use std::io::{Write, stdin, Read, stdout, BufWriter};
use std::convert::TryInto;

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let N = buf.split_ascii_whitespace().flat_map(str::parse::<i32>).next().unwrap();

    let mut is_prime = vec![true; (N+1).try_into().unwrap()];
    is_prime[0] = false;
    is_prime[1] = false;
    for i in 2..=(N as f64).sqrt() as usize {
        if !is_prime[i]{
            continue;
        }
        for i in (i*i..(N+1) as usize).step_by(i){
            is_prime[i] = false;
        }
    }

    let prime_sum: Vec<usize> = std::iter::once(0 as usize)
        .chain(is_prime.iter()
            .enumerate()
            .filter_map(|(i, &j)| if j { Some(i) } else { None })
            .scan(0, |sum, x| {
                *sum += x;
                Some(*sum)
            }))
        .collect();

    let mut ans = 0;
    let mut left: usize = 0;
    let mut right: usize = 0;
    while left <= right && right < prime_sum.len(){
        let tmp = prime_sum[right] - prime_sum[left];
        if tmp < N.try_into().unwrap(){
            right += 1;
        }else if tmp > N.try_into().unwrap(){
            left += 1;
        }else{
            ans += 1;
            left += 1;
        }
    }
    write!(writer, "{}", ans).unwrap();
}