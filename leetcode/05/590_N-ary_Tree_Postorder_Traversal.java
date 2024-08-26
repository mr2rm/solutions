import java.util.ArrayList;
import java.util.List;

// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {
    }

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    public List<Integer> postorder(Node node) {
        // Tree, DFS - Time: O(n), Space: O(n)
        List<Integer> res = new ArrayList<>();
        if (node == null) {
            return res;
        }

        for (Node child : node.children) {
            List<Integer> childResult = postorder(child);
            res.addAll(childResult);
        }

        res.add(node.val);
        return res;
    }
}
