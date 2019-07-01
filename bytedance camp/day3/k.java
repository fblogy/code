import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	
	static int N = 20202;

	static BigInteger F[] = new BigInteger[N];
	static BigInteger _0 = BigInteger.valueOf(0);
	static BigInteger _1 = BigInteger.valueOf(1);
	static BigInteger _10 = BigInteger.valueOf(10);
	static BigInteger _2 = BigInteger.valueOf(2);

	static BigInteger Gcd(BigInteger a, BigInteger b) {
		if(a.equals(_0)) return b;
		if(b.equals(_0)) return a;
		int ca = 0, cb = 0;
		while(a.and(_1).equals(_0)) {
			++ca;
			a = a.shiftRight(1);
		}
		while(b.and(_1).equals(_0)) {
			++cb;
			b = b.shiftRight(1);
		}
		int ans = ca;
		if(ans > cb) ans = cb;
		while(true) {
			if(b.equals(_0)) return a.shiftLeft(ans);
			BigInteger t = a.mod(b);
			a = b;
			b = t;
		}
		/*
			 while(true) {
			 if(a.compareTo(b) < 0) {
			 BigInteger k = b;
			 b = a;
			 a = k;
			 }
			 a = a.subtract(b);
			 if(a.equals(_0)) return b.shiftLeft(ans);
			 while(a.and(_1).equals(_0)) {
			 a = a.shiftRight(1);
			 }
			 }
		 */
	}

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		int K = cin.nextInt();
		F[0] = _1;
		for(int i = 2; i <= 2 * n - 1; ++i) F[0] = F[0].multiply(BigInteger.valueOf(i));
		for(int i = 1; i <= n; ++i) {
			F[i] = F[i - 1].multiply(BigInteger.valueOf(2 * (n - i + 1)));
			F[i] = F[i].divide(BigInteger.valueOf((2 * n - i) * i));
			if (i > K) {
				F[i] = F[i].multiply(BigInteger.valueOf(i));	
				F[i] = F[i].divide(BigInteger.valueOf(i - K));
			}
		}
		BigInteger ans = _0;
		int sig = 1;
		BigInteger cik = _1;
		for(int i = K; i <= n; ++i) {
		/*	BigInteger res = cik.multiply(F[i]);
			++i;
			cik = cik.multiply(BigInteger.valueOf(i));
			cik = cik.divide(BigInteger.valueOf(i - K));
			--i;*/
			if(sig == 1) {
				ans = ans.add(F[i]);
			} else {
				ans = ans.subtract(F[i]);
			}
			sig *= -1;
		}
		BigInteger res = F[0];
		BigInteger d = Gcd(ans, res);
		ans = ans.divide(d);
		res = res.divide(d);
		System.out.println(ans + "/" + res);
	}
}