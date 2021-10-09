// Java program to find the number
// of digits in a factorial

import java.io.*;
import java.util.*;

class Digits_in_factorial
{
	// returns the number of digits
	// present in n!
	static int findDigits(int n)
	{
		// factorial exists only for n>=0
		if (n < 0)
			return 0;

		// base case
		if (n <= 1)
			return 1;

		// else iterate through n and calculate the
		// value
		double digits = 0;
		for (int i=2; i<=n; i++)
			digits += Math.log10(i);

		return (int)(Math.floor(digits)) + 1;
	}
	

	public static void main (String[] args)
	{
		System.out.println(findDigits(1));
		System.out.println(findDigits(5));
		System.out.println(findDigits(10));
		System.out.println(findDigits(120));
	}
}
