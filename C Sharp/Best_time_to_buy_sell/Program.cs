namespace Best{
    public class Program{
        public int MaxProfit(int[] prices){
            int min=prices[0];
            int result = 0;
            foreach(int i in prices){
                min=Math.Min(min,i);
                result=Math.Max(result,i-min);
            }
            return result;
        }
        public static void Main(string[] args)
        {
            //int[] arr=[7,1,5,3,6,4];
            int[] arr=[1,2];
            Program p=new Program();
            Console.WriteLine("Best Time to Sell is : "+p.MaxProfit(arr));
        }
    }
}