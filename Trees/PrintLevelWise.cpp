/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
#include <queue>
void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int> *> pendingnodestoprint;
    pendingnodestoprint.push(root);
    while(!pendingnodestoprint.empty())
    {
        TreeNode<int> * frontelement = pendingnodestoprint.front();
        pendingnodestoprint.pop();
        cout<< frontelement -> data << ":";
        for(int i = 0; i< frontelement -> children.size(); i++)
        {
            cout<<frontelement -> children[i] -> data;
            if(i+1 < frontelement -> children.size())
            {
                cout<<",";
            }
            
            pendingnodestoprint.push(frontelement -> children[i]);
        }
        cout<<endl;
        
    }
}


TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}
