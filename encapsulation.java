// fields to calculate area
class Area {

int length;
int breadth;

// constructor to initialize values
Area(int length, int breadth) {
	this.length = length;
	this.breadth = breadth;
}

// method to calculate area
public void getArea() {
	int area = length * breadth;
	System.out.println("Area: " + area);
}
}

class Main {
public static void main(String[] args) {

	Area rectangle = new Area(2, 16);
	rectangle.getArea();
}
}
