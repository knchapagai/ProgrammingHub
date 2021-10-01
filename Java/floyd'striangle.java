package patterns;

public class Star {

public static void main(String[] args) {

int i, j, k = 1;

for (i = 1; i <= 5; i++) {

for (j = 1; j < i + 1; j++) {

System.out.print(k++ + " "); /Floyd’s triangle logic(prints K value and increments on every iteration)

}

System.out.println();

}

}

}