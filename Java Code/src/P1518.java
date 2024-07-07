public class P1518 {
    public int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        int empty = numBottles;
        while (empty >= numExchange) {
            int rem = empty / numExchange;
            result += rem;
            empty = rem + (empty % numExchange);
        }
        return result;
    }
}
