import java.util.Stack;

class Solution {
    /**
     * Brute Force: Time: O(n^2), Space: O(n)
     * 
     * @param prices Prices of items in the shop
     * @return Final price you will pay for the i-th item of the shop,
     */
    private int[] solution1(int[] prices) {
        int n = prices.length;
        int[] answer = new int[n];
        for (int i = 0; i < n; i++) {
            answer[i] = prices[i];
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    answer[i] -= prices[j];
                    break;
                }
            }
        }
        return answer;
    }

    /**
     * Monotonic Stack - Time: O(n), Space: O(n)
     * 
     * @param prices Prices of items in the shop
     * @return Final price you will pay for the i-th item of the shop,
     */
    private int[] solution2(int[] prices) {
        int n = prices.length;
        int[] answer = new int[n];

        Stack<Integer> stack = new Stack<>();
        for (int j = 0; j < n; j++) {
            while (!stack.isEmpty() && prices[stack.peek()] >= prices[j]) {
                int i = stack.pop();
                answer[i] -= prices[j];
            }

            answer[j] = prices[j];
            stack.push(j);
        }
        return answer;
    }

    public int[] finalPrices(int[] prices) {
        return solution2(prices);
    }
}
