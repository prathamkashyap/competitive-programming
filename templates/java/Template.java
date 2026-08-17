/**
 * Universal Competitive Programming Boilerplate in Java
 * Author: Pratham Kashyap
 */

import java.io.*;
import java.util.*;

public class Template {
    static class FastScanner {
        private final BufferedReader reader;
        private StringTokenizer tokenizer;

        public FastScanner(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    String line = reader.readLine();
                    if (line == null) return null;
                    tokenizer = new StringTokenizer(line);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void solve(FastScanner in, PrintWriter out) {
        // Solution implementation here
    }

    public static void main(String[] args) {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        String firstToken = in.next();
        if (firstToken != null) {
            int t = Integer.parseInt(firstToken);
            while (t-- > 0) {
                solve(in, out);
            }
        }
        out.flush();
        out.close();
    }
}
