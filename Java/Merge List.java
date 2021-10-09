import java.util.Scanner;

/**
  * Prompts user to enter two sorted lists and displays merged list
*/
public class Ex7_31 {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in); //scanner class for inputs
    
    System.out.println("Enter size of list1: ");
    int list1size = s.nextInt();
    System.out.println("Enter list1: ");
    int[] list1 = new int[list1size];
    //for loop to assign inputs to array
    for(int i = 0; i < list1size; i++) {
      list1[i] = s.nextInt();
    } 
    System.out.println("Enter size of list2: ");
    int list2size = s.nextInt();
    System.out.println("Enter list2: ");
    int[] list2 = new int[list2size];
    //for loop to assign inputs to array
    for(int i = 0; i < list2size; i++) {
      list2[i] = s.nextInt();
    } 
    int[] list3 = merge(list1, list2); //variable for merged list
    
    System.out.print("The merged list is ");
    //for loop to print out numbers from array 
    for(int j = 0; j < list3.length; j++){
      System.out.print(list3[j] + " ");
    }x
  }
  /**
    * merge
    * Merges two sorted lists
  */
  public static int[] merge(int[] list1, int[] list2) {
    int[] list3 = new int[list1.length + list2.length]; //initialize list3 variable to size of list1 and list2
    
    //for loop to put list1 items in list3  
    for(int i = 0; i < list1.length; i++)
      list3[i] = list1[i];
    
    //for loop to add list2 items to list3
    for(int i = 0, j = list1.length; i < list2.length; i++, j++) {
      list3[j] = list2[i];  
    }

    selectionSort(list3); //invoke selection sort method on list3

    return list3; //return sorted list3
  }
  /**
    * selectionSort
    * Sorts numbers using selection sort method (altered to find biggest number and swap with last)
  */
  public static void selectionSort(int[] list) {
    //for loops  to run through array and find maximum value
    for(int i = list.length - 1; i >= 0; i--) {
      int currentMax = list[i]; //current max set to size of list
      int currentMaxIndex = i; //index of current max set to first index
    
      for(int j = i - 1; j >= 0; j--) {
        if(currentMax < list[j]) { //if current max is less than next value
          currentMax = list[j]; //current max now equals this value
          currentMaxIndex = j; //index of current max set to this index
        }
      }
      //swap list[i] with list[currentMaxIndex] if necessary
      if(currentMaxIndex != i) {
        list[currentMaxIndex] = list[i];
        list[i] = currentMax;
      }
    }
  }
}
