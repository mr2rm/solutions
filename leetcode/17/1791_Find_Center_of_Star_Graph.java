class Solution {
    public int findCenter(int[][] edges) {
        int[] a = edges[0];
        int[] b = edges[1];
        if (a[0] == b[0] || a[0] == b[1]) {
            return a[0];
        }
        return a[1];
    }
}
