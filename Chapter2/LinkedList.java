package Chapter2;

public class LinkedList {

    private Node head = null;
    private int size;

    public LinkedList() {
        size = 0;
    }

    public void addFront(int value) {
        Node newHead = new Node(value);
        newHead.next = head;
        head = newHead;
        size += 1;
    }

    public void appendToTail(int value) {
        
        if (head == null) {
            head = new Node(value);
        }
        Node currentNode = head;
        while (currentNode.next != null) {
            currentNode = currentNode.next;
        }
        Node end = new Node(value);
        currentNode.next = end;
    }

    public int size() {
        return size;
    }

    public int removeValue(int value) {
        if (head == null) return 0;

        if (head.data == value) {
            head = head.next;
            return 1;
        }
        
        Node n = head;
        while (n.next != null) {
            if (n.next.data == value) {
                n.next = n.next.next;
                return 1;
            }
            n = n.next;
        }
        return 0;
    }

    public Node getHead() {
        return head;
    }

    public void printList() {
        Node currentNode = head;
        System.out.println("Displaying list:");
        while (currentNode != null) {
            System.out.println(Integer.toString(currentNode.data));
            currentNode = currentNode.next;
        }
    }
}