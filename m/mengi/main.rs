use std::io::*;

fn is_mengi(a: &Vec<char>, b: &Vec<char>, c: &Vec<char>) -> bool {
    for i in 0..4 {
        let all_equal = a[i] == b[i] && b[i] == c[i];
        let all_different = a[i] != b[i] && b[i] != c[i] && a[i] != c[i];
        if !all_equal && !all_different {
            return false;
        }
    }
    true
}

fn main() {
    let mut io = IO::new(stdin(), stdout());

    let n = 12;

    let mut a = vec![vec!['X'; 4]; 12];

    for i in 0..n {
        let x = io.chars();
        a[i] = x;
    }
    a.sort();

    let mut had_mengi = false;
    for i in 0..n {
        for j in i+1..n {
            for k in j+1..n {
                if is_mengi(&a[i], &a[j], &a[k]) {
                    println!("{} {} {}",
                        a[i].iter().collect::<String>(),
                        a[j].iter().collect::<String>(),
                        a[k].iter().collect::<String>(),
                    );
                    had_mengi = true;
                }
            }
        }
    }

    if !had_mengi {
        println!("Engin Mengi");
    }
}

pub struct IO<R, W: std::io::Write>(R, std::io::BufWriter<W>);

impl<R: std::io::Read, W: std::io::Write> IO<R, W> {
    pub fn new(r: R, w: W) -> IO<R, W> {
        IO(r, std::io::BufWriter::new(w))
    }
    pub fn write<S: ToString>(&mut self, s: S) {
        use std::io::Write;
        self.1.write_all(s.to_string().as_bytes()).unwrap();
    }
    pub fn read<T: std::str::FromStr>(&mut self) -> T {
        use std::io::Read;
        let buf = self
            .0
            .by_ref()
            .bytes()
            .map(|b| b.unwrap())
            .skip_while(|&b| b == b' ' || b == b'\n' || b == b'\r' || b == b'\t')
            .take_while(|&b| b != b' ' && b != b'\n' && b != b'\r' && b != b'\t')
            .collect::<Vec<_>>();
        unsafe { std::str::from_utf8_unchecked(&buf) }
            .parse()
            .ok()
            .expect("Parse error.")
    }

    pub fn vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.read::<T>()).collect()
    }
    pub fn chars(&mut self) -> Vec<char> {
        self.read::<String>().chars().collect()
    }
}
