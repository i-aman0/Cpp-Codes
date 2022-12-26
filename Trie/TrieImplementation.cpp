#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data=ch;
            for(int i=0; i<26; i++){
                children[i]=NULL;
            }

            isTerminal=false;
        }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        // creating root node having null character
        root=new TrieNode('\0');
    }




    // INSERTION IN TRIE
    void insertUtil(TrieNode* root, string word){

        // base case
        if(word.length() == 0){
            // complete word is traversed, mark the last character as terminal 
            root->isTerminal=true;
            return;
        }

        // assume that the word will always be in caps
        int index=word[0]-'A';
        TrieNode* child;

        //present, to age badh jao 
        if(root->children[index] != NULL){
            child=root->children[index];
        }
        else{
            //absent, to create karo and age badh jao
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        //RECURSION
        insertUtil(child, word.substr(1));
    }

    void insert(string word){
        insertUtil(root, word);
    }




    // SEARCHING IN TRIE
    bool searchUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index=word[0] - 'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child=root->children[index];
        }
        else{
            //absent
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }

    bool searchPrefix(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            return true;
        }

        int index=word[0] - 'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child=root->children[index];
        }
        else{
            //absent
            return false;
        }

        return searchPrefix(child, word.substr(1));
    }

    bool startsWith(string word){
        return searchPrefix(root, word);
    }

};

int main()
{
    Trie* t=new Trie();
    t->insert("CAT");
    t->insert("DO");
    t->insert("TIME");
    t->insert("APPLE");

    cout<<"TIME Present or not : "<<t->searchWord("TIME")<<endl;
    cout<<"TIM Present or not : "<<t->searchWord("TIM")<<endl;
    cout<<"Prefix having APP : "<<t->startsWith("APP")<<endl;
    return 0;
}