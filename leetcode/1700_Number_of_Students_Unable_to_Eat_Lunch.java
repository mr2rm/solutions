class Solution {
    int solve1(int[] students, int[] sandwiches) {
        // Simulation - Time: O(n^2), Space: O(1)
        int n = students.length;
        int front = 0;

        for (int top = 0; top < n; top++) {
            int c;
            for (c = 0; c < n; c++) {
                int i = (front + c) % n;
                if (sandwiches[top] == students[i]) {
                    students[i] = -1;
                    front = (i + 1) % n;
                    break;
                }
            }
            if (c == n) {
                return n - top;
            }
        }

        return 0;
    }

    public int countStudents(int[] students, int[] sandwiches) {
        return solve1(students, sandwiches);
    }
}
