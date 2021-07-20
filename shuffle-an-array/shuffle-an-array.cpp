class Solution {
private:
    vector<int> temp;    
public:
    Solution(vector<int>& nums) {
        temp = nums;        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return temp;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector <int> temp_2;
        temp_2 = temp;
        
        for(int i = 0;i < temp_2.size();i++){
            
            //  rand() generates random number. It can generate any number between 1 to temp.size() - 1;
            int index = rand() % (i+1);
            
            // Swap to randomly shuffle the numbers.
            swap(temp_2[i],temp_2[index]);
        }
        return temp_2;
    }
};
