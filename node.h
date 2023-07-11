
class TreeNode {
  private:
   int data; // node value                               
   TreeNode* leftPtr; // pointer to left subtree 
   TreeNode* rightPtr; // pointer to right subtree
  public:
   TreeNode(int); 
   ~TreeNode();
   void set_left(TreeNode* t){ leftPtr = t; }
   void set_right(TreeNode* t){ rightPtr=t; }
   int get_data(){ return data; }
   TreeNode* move_right(){ return rightPtr; }
   TreeNode* move_left(){ return leftPtr; }
};
        
typedef TreeNode* TreeNodePtr; 

TreeNode::TreeNode(int x){
   data = x;
   leftPtr = NULL;
   rightPtr = NULL; 
}

TreeNode::~TreeNode(){
  cout <<"Deleting "<< data << endl;  
}
