package Chapter2;

import java.util.HashSet;

public class Q1removeDuplicates {
    public static void main(String[] args) {
        LinkedList testList = new LinkedList();
        for (int i=0; i<10; i++) {
            testList.appendToTail(i);
            testList.appendToTail(i+3);
        }
        testList.printList();
        removeDuplicates(testList);
        testList.printList();
    }
    
    public static void removeDuplicates(final LinkedList list) {
        
        Node n = list.getHead();
        if (n == null) return;

        HashSet<Integer> set = new HashSet<Integer>();
        set.add(n.data);
        while (n.next != null) {
            if (set.contains(n.next.data)) {
                n.next = n.next.next;
            } else {
                set.add(n.next.data);
                n = n.next;
            }
        }
    }
}
