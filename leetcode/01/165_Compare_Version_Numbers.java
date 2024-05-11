class Solution {
    int[] getIntegerRevision(String version, int startIndex) {
        if (startIndex >= version.length()) {
            return new int[] { 0, version.length() };
        }

        int endIndex = version.indexOf('.', startIndex);
        if (endIndex == -1) {
            endIndex = version.length();
        }

        String revision = version.substring(startIndex, endIndex);
        int res = Integer.valueOf(revision);

        return new int[] { res, endIndex };
    }

    public int compareVersion(String version1, String version2) {
        // String, Two Pointers - Time: O(n), Space: O(1)
        int i = 0, j = 0;
        while (i < version1.length() || j < version2.length()) {
            int[] x = getIntegerRevision(version1, i);
            int[] y = getIntegerRevision(version2, j);

            if (x[0] < y[0]) {
                return -1;
            } else if (x[0] > y[0]) {
                return 1;
            }

            i = x[1] + 1;
            j = y[1] + 1;
        }

        return 0;
    }
}
