package dsalgos.recursion;

public class Print1ToNRecursively {

    public static void main(String[] args) {
        print1ToN(10);
    }
    static void print1ToN(int n) {

        if(n == 0) {
            return;
        }

        print1ToN(n-1);
        System.out.println(n);
    }
}
