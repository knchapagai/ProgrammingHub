public class Holiday{
    private String name;
    private int day;
    private String month;
    public static void main(String[] args) {
        int[] array = {10,15,20,25,30};
        Holiday h1 = new Holiday();
        h1.inSameMonth();
        h1.avgDate(array);
    }
// Creating Constructor     
public Holiday(String n, int d, String m) {
    this.name = n;
    this.day = d;
    this.month = m;
}
String getName(){
    return name;
}
String getMonth(){
    return month;
}
int getDay(){
    return day;
}
Holiday(){
    //Testing the code
}
//Creating method to check the month 
public void inSameMonth(){
    boolean sameMonthValue = false;
    Holiday h1 = new Holiday("Independence Day ", 15, "August");
    Holiday h2 = new Holiday("Republic Day", 26, "August");
    if(h1.month == h2.month){
        System.out.println(h1.getName() + h1.getDay() + "th" + " " + h1.getMonth());
        sameMonthValue = true;
        System.out.println("MONTH VALUE : " + sameMonthValue);
    }
    if(h1.month != h2.month){
        System.out.println("Months are Different");
        sameMonthValue = false;
        System.out.println("MONTH VALUE : " + sameMonthValue);
    }
}
//Creating method Average Date
public static double avgDate(int[] Temp) {
        double avgDateValue = 0.0;
        int day = 0;
        for(int i = 0; i < Temp.length; i++) {
        int A = Temp[i];
        day = A + day;
        avgDateValue = day/Temp.length;
        }
        System.out.println("AVERAGE DATE : " + avgDateValue);
        return avgDateValue;
    }
}