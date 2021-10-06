import java.io.*;
class StackType
{
	int st[];
	int top;
	int size;
	StackType(int s)
	{
		size = s;
		top = -1;
		st = new int[s];
	}
	public void push(int add)
	{
		top++;
		st[top] = add;
	}
	public int pop()
	{
		int d = st[top];
		top--;
		return d;
	}
	public boolean isEmpty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}
	public boolean isFull()
	{
		if (top == size - 1)
			return true;
		else
			return false;
	}
	public void display()
	{
		if (this.isEmpty())
			System.out.println("Cannot display. Empty Stack");
		else
		{
			System.out.print("Contents of the stack :");
			for (int i = 0;i <= top;i++)
				System.out.print(st[i] + " ");
			System.out.println();
		}
	}
}
class StackTest
{
	public static void main(String[] args) throws IOException
	{
		StackType s;
		int n;
		int opChoice;
		char choice;
		int add, del;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Stack Operations Program ");
		System.out.print("\nEnter size of the stack :");
		n = Integer.parseInt(br.readLine());
		s = new StackType(n);
		do
		{
			System.out.println("\n***************************************************************************");
			System.out.println("\nChoose an operation from the given menu :");
			System.out.println("1.Push");
			System.out.println("2.Pop");
			System.out.println("3.Display");
			System.out.print("Enter your choice(1-3) :");
			opChoice = Integer.parseInt(br.readLine());
			switch (opChoice)
			{
			case 1:
				if (s.isFull())
					System.out.println("Cannot Push. Stack Overflow. ");
				else
				{
					System.out.print("Enter an integer to be added :");
					add = Integer.parseInt(br.readLine());
					s.push(add);
					s.display();
				}
				break;
			case 2:
				if (s.isEmpty())
					System.out.println("Cannot Pop. Stack Underflow. ");
				else
				{
					del = s.pop();
					System.out.println(del + " has been popped out of stack.");
					s.display();
				}
				break;
			case 3:
				s.display();
				break;
			default:
				System.out.println("Wrong Operation Choice...");
			}
			System.out.print("\nDo you want to continue?(Y/N) :");
			choice = br.readLine().charAt(0);
		}
		while (choice == 'Y' || choice == 'y');
	}
}

