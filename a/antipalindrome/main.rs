#[allow(unused_imports)]
use std::cmp::{min,max};
use std::io::{BufWriter, stdin, stdout, Write};
const INF: i64 = 0x3f3f3f3f;
 
#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}
 
fn main() {
    let mut line = String::new();
    stdin().read_line(&mut line).expect("");

    line.make_ascii_lowercase();
    line.retain(|c| !c.is_whitespace());

    let n = line.len();

    for (i, c) in line.chars().enumerate().take(n-1) {
        if c == line.chars().nth(i+1).unwrap() || (i < n - 2 && c == line.chars().nth(i+2).unwrap()) {
            println!("Palindrome");
            return;
        }
    }

    println!("Anti-palindrome");
}

