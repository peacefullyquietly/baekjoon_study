// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
fn main() {
    let mut vec = vec![1, 3, 5, 7, 9];
    vec.sort();

    match vec.binary_search(&3) {
        Ok(index) => {
            println!("{} is at {}", 3, index);
            println!("{} is at {}", 3, vec[index]);
        }
        Err(_) => println!("Not found"),
    }
}