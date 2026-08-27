import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        int T = fs.nextInt();

        for (int i = 0; i < T; ++i) {
            String[] grid = new String[3];
            int cx = 0;
            int co = 0;
            for (int j = 0; j < 3; ++j) {
                grid[j] = fs.next();

                for (int k = 0; k < 3; ++k) {
                    if (grid[j].charAt(k) == 'X') {
                        ++cx;
                    }
                    if (grid[j].charAt(k) == 'O') {
                        ++co;
                    }
                }
            }

            if (cx < co || cx >= co + 2) {
                System.out.println("no");
                continue;
            }

            int wxr = 0;
            int wxc = 0;
            int wxd = 0;
            int wor = 0;
            int woc = 0;
            int wod = 0;

            int r = -1;
            int c = -1;
            int d = -1;

            for (int j = 0; j < 3; ++j) {
                if (grid[j].compareTo("XXX") == 0) {
                    wxr++;
                    r = j;
                }
                if (grid[j].compareTo("OOO") == 0) {
                    wor++;
                    r = j;
                }
                if (grid[0].charAt(j) == 'X' && 
                    grid[1].charAt(j) == 'X' &&
                    grid[2].charAt(j) == 'X') {
                    wxc++;
                    c = j;
                }
                if (grid[0].charAt(j) == 'O' && 
                    grid[1].charAt(j) == 'O' &&
                    grid[2].charAt(j) == 'O') {
                    woc++;
                    c = j;
                }
            }
            if (grid[0].charAt(0) == 'X' && 
                grid[1].charAt(1) == 'X' &&
                grid[2].charAt(2) == 'X') {
                wxd++;
                d = 0;
            }
            if (grid[0].charAt(2) == 'X' && 
                grid[1].charAt(1) == 'X' &&
                grid[2].charAt(0) == 'X') {
                wxd++;
                d = 1;
            }

            if (grid[0].charAt(0) == 'O' && 
                grid[1].charAt(1) == 'O' &&
                grid[2].charAt(2) == 'O') {
                wod++;
                d = 0;
            }
            if (grid[0].charAt(2) == 'O' && 
                grid[1].charAt(1) == 'O' &&
                grid[2].charAt(0) == 'O') {
                wod++;
                d = 1;
            }

            if (wxr > 1 || wor > 1 || wxc > 1 || woc > 1) {
                System.out.println("no");
                continue;
            }

            if (wxr+wxc+wxd > 0 && wor+woc+wod > 0) {
                System.out.println("no");
                continue;
            }

            if (wxr+wxc+wxd > 0 && cx == co) {
                System.out.println("no");
                continue;
            }

            if (wor+woc+wod > 0 && cx != co) {
                System.out.println("no");
                continue;
            }


            if (wxd == 2 || wod == 2) {
                if ((r != -1 && r != 1) || (c != -1 && c != 1)) {
                    System.out.println("no");
                    continue;
                }
            } else if (wxd == 1 || wod == 1) {
                if (c != -1 && r != -1) {
                    if ((d == 0 && r != c) || (d == 1 && r != 2 - c)) {
                        System.out.println("no");
                        continue;
                    }
                }
            }
            System.out.println("yes");
        }
    }
	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");
 
		String next() {
			while (!st.hasMoreTokens())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
 
		int nextInt() {
			return Integer.parseInt(next());
		}
 
		int[] readArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
 
		long nextLong() {
			return Long.parseLong(next());
		}
	}
}
