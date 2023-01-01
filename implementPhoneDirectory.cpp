


class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
    
};

class Trie{
    public:
    TrieNode* root;
    
        Trie(){
            root=new TrieNode('\0');
        }
            void insertUtil(TrieNode* root, string word){
                if(word.length()==0){
                    root->isTerminal=true;
                    return;
                }
            
            TrieNode* child;;
            int index=word[0]-'a';
            if(root->children[index]!=NULL){
                 child=root->children[index];
            }
            else{
                 child=new TrieNode(word[0]);
                root->children[index]=child;
            }
            insertUtil(child,word.substr(1));
        }
        
        void insert(string word){
            insertUtil(root, word);
        }
        
        void printSuggestion(TrieNode* curr, vector<string> &temp,string &prefix){
            if(curr->isTerminal){
                temp.push_back(prefix);
            }
            for(char ch='a';ch<='z';ch++){
                TrieNode* next=curr->children[ch-'a'];
                if(next!=NULL){
                    prefix.push_back(ch);
                    printSuggestion(next,temp,prefix);
                    prefix.pop_back();
                }
            }
        }
        
        vector<vector<string>> getSuggestions(string str){
            TrieNode* prev=root;
            vector<vector<string>> output;
            string prefix="";
            for(int i=0;i<str.length();i++){
                char lastch=str[i];
                prefix.push_back(lastch);
                
                TrieNode* curr=prev->children[lastch-'a'];
                
                if(curr==NULL){
                    break;
                }
                vector<string> temp;
                printSuggestion(curr,temp,prefix);
                output.push_back(temp);
                temp.clear();
                prev=curr;
            }
            return output;
        }
};




vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
     Trie *t=new Trie();
        for(int i=0;i<contactList.size();i++){
            string str=contactList[i];
            t->insert(str);
        }
        return t->getSuggestions(queryStr);   
}