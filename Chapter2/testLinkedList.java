package Chapter2;


public class testLinkedList {
    public static void main(String[] args) {
        LinkedList testList = new LinkedList();
        testList.addFront(10);
        testList.addFront(20);
        testList.appendToTail(30);
        testList.printList();
        testList.removeValue(40);
        testList.printList();
    }  
}
