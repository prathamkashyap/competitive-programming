import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            char[] x = s.toCharArray();
            int n = x.length;
            String best = s;
            int bestFreq = 0;

            // Try replacing every position with every possible letter
            for (int i = 0; i < n; ++i) {
                for (char repl = 'a'; repl <= 'z'; ++repl) {
                    if (x[i] == repl) continue;
                    char orig = x[i];
                    x[i] = repl;
                    int[] freq = new int[26];
                    for (char ch : x) freq[ch - 'a']++;
                    int maxFreq = 0;
                    for (int f : freq) maxFreq = Math.max(maxFreq, f);
                    String candidate = new String(x);
                    if (maxFreq > bestFreq || (maxFreq == bestFreq && candidate.compareTo(best) < 0)) {
                        bestFreq = maxFreq;
                        best = candidate;
                    }
                    x[i] = orig;
                }
            }
            System.out.println(best);
        }
    }

    // FastReader template for Codeforces
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }
        int nextInt() throws IOException { return Integer.parseInt(next()); }
    }
}
