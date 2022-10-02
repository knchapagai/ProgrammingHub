using System;
using System.Collections;

class Test {

	
	class item {
		public int value;
		public int weight;

		public item(int value, int weight)
		{
			this.value = value;
			this.weight = weight;
		}
	}

	class cprCompare : IComparer {
		public int Compare(Object x, Object y)
		{
			item item1 = (item)x;
			item item2 = (item)y;
			double cpr1 = (double)item1.value
						/ (double)item1.weight;
			double cpr2 = (double)item2.value
						/ (double)item2.weight;

			if (cpr1 < cpr2)
				return 1;

			return cpr1 > cpr2 ? -1 : 0;
		}
	}

	static double FracKnapSack(item[] items, int w)
	{

		cprCompare cmp = new cprCompare();
		Array.Sort(items, cmp);

		double totalVal = 0f;
		int currW = 0;

		foreach(item i in items)
		{
			float remaining = w - currW;

			if (i.weight <= remaining) {
				totalVal += (double)i.value;
				currW += i.weight;
			}

			else {
				if (remaining == 0)
					break;

				double fraction
					= remaining / (double)i.weight;
				totalVal += fraction * (double)i.value;
				currW += (int)(fraction * (double)i.weight);
			}
		}
		return totalVal;
	}

	static void Main(string[] args)
	{
		item[] arr = { new item(60, 10), new item(100, 20),
					new item(120, 30) };

		Console.WriteLine("Maximum value we can obtain = "
						+ FracKnapSack(arr, 50));
	}
}
