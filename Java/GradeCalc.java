import java.util.*;
class array{

	static Character grader(int Mark) {
		if (Mark >= 90)
			return 'S';

		else if (Mark >= 80 && Mark<90)
			return 'A';

		else if (Mark >= 70 && Mark<80)
			return 'B';

		else if (Mark >= 60 && Mark<70)
			return 'C';

		else if (Mark >= 50 && Mark<60)
			return 'D';

		else
			return 'F';

	}

	public static void main(String args[]) {

		Scanner s = new Scanner(System.in);

		String registernum[] = new String[5];

		int Mark[] = new int[5];

		char grade[] = new char[5];

		int Total = 0;

		System.out.println("Please enter the register numbers and marks");

		for (int m = 0; m < 5; m++) {
			registernum[m] = s.next();
			Mark[m] = s.nextInt();
			s.nextLine();

			grade[m] = grader(Mark[m]);

			Total = Total + Mark[m];

		}

		for (int j = 0; j < 5; j++) {
			System.out.println("Grade for student - " + registernum[j] + " is " + grade[j]);
		}

		System.out.println("Class Average = " + (double) (Total / 5));

	}
}
