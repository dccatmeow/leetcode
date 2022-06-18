/**
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer,
or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work.
You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    //root(left)(right)
    string serialize(TreeNode* root) {
        if (root==nullptr){
            return "#";
        }
        return to_string(root->val)+"("+serialize(root->left)+ ")("+serialize(root->right)+")";
    }

    TreeNode* de(string& data, int& i){
        // i is labeling where is the starting position for decoding
        if (data[i] == '#'){
            i++;// move cursor to )
            return nullptr;
        }
        // root ( left )
        // i    j
        auto j = data.find_first_of('(', i);
        auto r = stoi(data.substr(i, j-i));
        auto root = new TreeNode(r);
        // root ( left )
        //        i
        i = j+1;// move cursor from ( to content
        root->left = de(data, i);
        // root ( left ) ( right )
        //             i
        //                 i
        i = i+2; // move from ) to content
        root->right = de(data, i);
        i++; // cursor is at the end of right branch, move one more to end of whole tree
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return de(data, i);
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
