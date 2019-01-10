
/*
 *			BATPROBATPROBATPROBATPROBATPROBATPROBATPROBATPROBATPROBATPROBATPR
 * 			BATPROBATPROBATPROBATPROBATPROBATPROBATPROBATPROBATPROBATPROBATPR
 * 			BAT.             `PROBATPROBA|\___/|TPROBATPROB'             .ATP
 * 			BATPR.            `OBATPROBAT|     |PROBATPROBA'           .TPROB
 * 			BATPRO.            `BATPROBA/       \TPROBATP'            .ROBATP
 * 			BATPROB.                                                 .ATPROBA
 * 			BATPROB'                                                 `ATPROBA
 * 			BATPRO'                                                   `BATPRO
 * 			BATPROBATPROBATP`---._                     _.---'ROBATPROBATPROBA
 * 			BATPROBATPROBATPROBATPR--.             .--OBATPROBATPROBATPROBATP
 * 			BATPROBATPROBATPROBATPROBAT-.       .-PROBATPROBATPROBATPROBATPRO
 * 			BATPROBATPROBATPROBATPROBATPRO.   .BATPROBATPROBATPROBATPROBATPRO
 * 			BATPROBATPROBATPROBATPROBATPROB\ /ATPROBATPROBATPROBATPROBATPROBA
 * 			BATPROBATPROBATPROBATPROBATPROBAVTPROBATPROBATPROBATPROBATPROBATP
 *
 */

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {
		BigInteger[] arr = new BigInteger[110];
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			int n = 0;
			int idx = 0;
			int x;
			while ((x = in.nextInt()) != -999999) {
				arr[idx++] = BigInteger.valueOf(x);
				n++;
			}

			BigInteger mx = BigInteger.valueOf(-999999);
			for (int i = 0; i < n; i++) {
				for (int j = i; j < n; j++) {
					BigInteger p = BigInteger.valueOf(1);
					for (int k = i; k <= j; k++) {
						p = p.multiply(arr[k]);
					}
					mx = mx.max(p);
				}
			}
			System.out.println(mx);
		}
	}

}

