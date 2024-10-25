import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<String> removeSubfolders(String[] folder) {
        // NOTE: Sorting, String - Time: O(l * nlogn), Space: O(n * l)
        Arrays.sort(folder);

        List<String> res = new ArrayList<>();
        res.add(folder[0]);

        for (int i = 1; i < folder.length; i++) {
            String lastDir = res.get(res.size() - 1) + "/";
            if (!folder[i].startsWith(lastDir)) {
                res.add(folder[i]);
            }
        }
        return res;
    }
}
