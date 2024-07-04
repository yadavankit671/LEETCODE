class MyCircularQueue {
    static class List{
        public int val;
        public List next;
        public List prev;
        public List(int val) {
            this.val=val;
            next=null;
            prev=null;
        }
    }
    private List head;
    private List tail;
    private final int Capacity;
    private int size;
    public MyCircularQueue(int k) {
        Capacity=k;
        size=0;
        head=tail=null;
    }
    
    public boolean enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            head=new List(value);
            tail=head;
            head.next=tail;
            tail.prev=head;
        }
        else{
            List newNode= new List(value);
            tail.next=newNode;
            newNode.prev=tail;
            newNode.next=head;
            head.prev=newNode;
            tail=newNode;
        }
        size++;
        return true;
    }
    
    public boolean deQueue() {
        if(isEmpty()) return false;
        if(head==tail){
            head=null;
            tail=null;
        }
        else{
            List temp=head;
            head=head.next;
            head.prev=temp;
            tail.next=head;
        }
        size--;
        return true;
    }
    
    public int Front() {
        if(isEmpty()) return -1;
        return head.val;
    }
    
    public int Rear() {
        if(isEmpty()) return -1;
        return tail.val;
    }
    
    public boolean isEmpty() {
        return size==0;
    }
    
    public boolean isFull() {
        return size==Capacity;
    }
}
public class P622 {
    public static void main(String[] args) {
        MyCircularQueue obj =new MyCircularQueue(0);
        System.out.println(obj.enQueue(1)); // return false
    }
}
