using System.Collections.Generic;
using System.Linq;

namespace revlinkedlist{
    public class ListNode {
        public int val;
        public  ListNode next;
        public ListNode(int val=0, ListNode next =null) {
            this.val = val;
            this.next = next;
        }
    }

    public class Solution {
        public ListNode ReverseKGroup(ListNode head, int k) {
            if(head is null) return head;
            ListNode result=head;
            List<int> list=new();
            ListNode temp=head;
            while(temp is not null){
                list.Add(temp.val);
                temp=temp.next;
            }
            for(int i=0;i<list.Count;i+=k){
                if(i+k>list.Count) break;
                list.Reverse(i,k);
            }
            int index=0;
            while(head is not null){
                head.val=list[index];
                index++;
                head=head.next;
            }
            return result;
        }
        public void PrintList(ListNode? list){
            Console.WriteLine();
            if(list is null){
                Console.WriteLine("List is empty !!");
                return;
            }
            Console.Write("List : "+list.val);
            list=list.next;
            while(list is not null){
                Console.Write("-->"+list.val);
                list=list.next;
            }
            Console.WriteLine();
        }
    }
    public class Program{
        public static void Main(string[] args)
        {
            Solution obj = new();
            ListNode? list=null;
            for(int i=9;i>0;i--) list=new ListNode(i,list);
            obj.PrintList(list);
            list= obj.ReverseKGroup(list,3);
            obj.PrintList(list);
        }
    }
}