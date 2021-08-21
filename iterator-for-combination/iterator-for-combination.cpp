class CombinationIterator {
private:
    vector<string> combinations;
    void backtrack(int maxLen , string characters , int index , string combination){
        if(combination.size() == maxLen){
            combinations.push_back(combination);
            return ;
        }    
        string substring = characters.substr(index);
        for(auto character : substring){
            if(combination.length() == 0){
                backtrack(maxLen , characters , index + 1 , combination + character);
            } else if (character - 'a' > combination[combination.length() - 1] - 'a'){
                backtrack(maxLen , characters , index + 1 , combination + character);
            } else {
                continue;
            }
        }
    }
public:
    int index = 0;
    CombinationIterator(string characters, int combinationLength) {
        backtrack(combinationLength , characters , 0 , "");
    }
    
    string next() {
        return combinations[index++];
    }
    
    bool hasNext() {
        return index < combinations.size();
    }
};