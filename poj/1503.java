import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        BigInteger sum = BigInteger.ZERO;
        String line;
        while ((line = in.readLine()) != null) {
            if ("0".equals(line)) {
                break;
            }
            sum = sum.add(new BigInteger(line));
        }
        out.println(sum);
        in.close();
        out.close();
    }
}