import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ArrayList1 {

	public static void main(String[] args) {
		
		List<String> list = new ArrayList<String>();
		list.add("Yellow");
		list.add("Pink");
		list.add("Blue");
		list.add("Green");
		System.out.println("List before sort: "+list);
		//Collections.sort(list);
		Collections.reverse(list);
		System.out.println("List after sort: "+list);
	}

}
