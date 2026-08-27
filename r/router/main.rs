use std::io::*;

fn main() {
    let mut io = IO::new(stdin(), stdout());

    let n: usize = io.read();

    let mut x = 0;
    let mut y = 0;

    let mut xmin = 0;
    let mut xmax = 0;
    let mut ymin = 0;
    let mut ymax = 0;

    for _ in 0..n {
        let c: char = io.read();

        let d: i64 = io.read();

        match c {
            'U' => y += d,
            'D' => y -= d,
            'R' => x += d,
            'L' => x -= d,
            _ => unreachable!()
        }
        xmin = std::cmp::min(xmin, x);
        xmax = std::cmp::max(xmax, x);
        ymin = std::cmp::min(ymin, y);
        ymax = std::cmp::max(ymax, y);
    }

    let w = xmax - xmin + 40;
    let h = ymax - ymin + 40;
    println!("{w} {h}");
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
