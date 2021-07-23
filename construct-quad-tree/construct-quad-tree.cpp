class Solution {
public:
    bool _all_are_same(vector<vector<int> >&grid,int l1,int l2,int m1,int m2)
    {
       int val=grid[l1][m1];
        for(int i=l1;i<=l2;i++)
        {
            for(int j=m1;j<=m2;j++)
            {
                if(val!=grid[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    Node*generate(vector<vector<int> >&grid,int l1,int l2,int m1,int m2)
    {
        Node*root;
        if(_all_are_same(grid,l1,l2,m1,m2))
        {
           root= new Node(grid[l1][m1],true);
            
        }
        else
        {
            root=new Node(1,false);
            root->topLeft= generate(grid,l1,l1+(l2-l1)/2,m1,m1+(m2-m1)/2);
            root->bottomLeft=generate(grid,l1+(l2-l1)/2+1,l2,m1,(m2-m1)/2+m1);
            root->topRight=generate(grid,l1,l1+(l2-l1)/2,(m2-m1)/2+1+m1,m2);
            root->bottomRight=generate(grid,l1+(l2-l1)/2+1,l2,(m2-m1)/2+1+m1,m2);
            
        }
        return root;
    }
    Node* construct(vector<vector<int>>& grid) 
    {
        return generate(grid,0,grid.size()-1,0,grid.size()-1);
    }
};