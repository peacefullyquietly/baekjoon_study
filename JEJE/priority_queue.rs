fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }

    &s[..]
}

fn main() {
    let mut s = String::from("hello world");
    let s1 = &s[..];
    let word = first_word(&s1);

    s.clear(); // Error!

    println!("the first word is: {}", word);
}