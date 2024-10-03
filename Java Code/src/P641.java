class MyCircularDeque {
    private class Node {
        int val;
        Node next;
        Node prev;
        public Node(int val){
            this.val = val;
            this.next = null;
            this.prev = null;
        }
        
    }
    private Node head;
    private Node tail;
    private int curr;
    private int size;

    public MyCircularDeque(int k) {
        this.size = k;
        this.curr = 0;
        this.head = new Node(-1);
        this.tail = new Node(-1);
        this.head.next = this.tail;
        this.tail.prev = this.head;
    }
    
    public boolean insertFront(int value) {
        if(curr == size) return false;
        Node newNode = new Node(value);
        newNode.next = head.next;
        newNode.prev = head;
        head.next.prev = newNode;
        head.next = newNode;
        curr++;
        return true;
    }
    
    public boolean insertLast(int value) {
        if(curr == size) return false;
        Node newNode = new Node(value);
        newNode.prev = tail.prev;
        tail.prev.next = newNode;
        newNode.next = tail;
        tail.prev = newNode;
        curr++;
        return true;
    }
    
    public boolean deleteFront() {
        if(curr == 0) return false;
        Node temp = head.next;
        head.next = temp.next;
        temp.next.prev = head;
        curr--;
        return true;
    }
    
    public boolean deleteLast() {
        if(curr == 0) return false;
        Node temp = tail.prev;
        tail.prev = temp.prev;
        temp.prev.next = tail;
        curr--;
        return true;
    }
    
    public int getFront() {
        return head.next.val;
    }
    
    public int getRear() {
        return tail.prev.val;
    }
    
    public boolean isEmpty() {
        return curr == 0;
    }
    
    public boolean isFull() {
        return curr == size;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */
public class P641 {

}
