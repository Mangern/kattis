use std::io::*;

fn main() {
    let mut io = IO::new(stdin(), stdout());

    let n: usize = io.read();
    let k: usize = io.read();

    let s = io.chars();

    let mut included = vec![true; n];

    let mut ptr = 0;
    for _ in 0..n {
        let mut count = k;
        loop {
            while !included[ptr] { ptr = (ptr + 1) % n; }
            count -= 1;
            if count == 0 { break; }
            ptr = (ptr + 1) % n;
        }
        io.write(s[ptr]);
        included[ptr] = false;
        ptr = (ptr + 1) % n;
    }
    io.write('\n');
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
        (0..n).map(|_| self.read()).collect()
    }
    pub fn chars(&mut self) -> Vec<char> {
        self.read::<String>().chars().collect()
    }
}
