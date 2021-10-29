public class test {
    public int testing(int a, int b) {
        return a+b;
    }
}
public class App {
    public static void main(String[] args) {
        test testtt = new test();
        System.out.println(testtt.testing(3, 10));
    }
}
