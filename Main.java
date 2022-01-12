import java.util.Scanner;

/* Name of the class has to be "Main" only if the class is public. */
public class Main {
  public static void main(String[] args) throws java.lang.Exception {
    Scanner scanner = new Scanner(System.in);
    String sc = "";
    while (!sc.startsWith("00")) {
      System.out.print("Type a number: ");
      sc = scanner.nextLine();
      System.out.println(sc);
    }
    scanner.close();
  }
}