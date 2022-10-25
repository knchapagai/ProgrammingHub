using System;

namespace Add{
	public class Program{

		public static int addition(int a, int b){
			return (a+b);
		}

		public static void Main(){
			int a,b;
			int sum;

			Console.Write("Enter first number: ");
			a = Convert.ToInt32(Console.ReadLine());

			Console.Write("Enter second number: ");
			b = Convert.ToInt32(Console.ReadLine());

			sum = addition(a,b);

			Console.WriteLine("Sum is: " + sum);
		}
	}
}
4
C# add two numbers using a methodC# By Debmalya Banerjee on May 10 2022 ThankComment
using System;
