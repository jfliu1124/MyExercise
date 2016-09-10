#include<memory>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class TreePrinter {
public:
	vector<vector<int> > printTree(TreeNode* root) {
		vector<vector<int>> res;
		TreeNode* last = root;
		TreeNode* next_last = NULL;
		TreeNode* cur = NULL;
		queue<TreeNode*> tmp;
		tmp.push(root);
		shared_ptr<vector<int> > p = make_shared<vector<int> >();
		while (!tmp.empty()) {
			cur = tmp.front();
			p->push_back(cur->val);
			tmp.pop();
			if (cur->left) {
				tmp.push(cur->left);
				next_last = cur->left;
			}
			if (cur->right) {
				tmp.push(cur->right);
				next_last = cur->right;
			}
			if (last == cur) {
				last = next_last;
				res.push_back(*p);
				p = make_shared<vector<int> >();
			}
		}
		return res;
	}
};