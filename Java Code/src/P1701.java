public class P1701 {
    public double averageWaitingTime(int[][] customers) {
        double result = 0;
        int currTime = 0;
        for(int[] x : customers){
            currTime += currTime < x[0] ? x[0]-currTime:0;
            currTime += x[1];
            result += (currTime - x[0]);
        }
        return (double) result/customers.length;
    }
    public static void main(String[] args) {
        P1701 obj = new P1701();
        int[][] customers = {{1,2},{2,5},{4,3}};
        System.out.println(obj.averageWaitingTime(customers));
    }
}
