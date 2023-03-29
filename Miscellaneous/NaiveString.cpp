#include<iostream>
using namespace std;

void strMatch(char* pat, char* txt){
    int m=strlen(pat);  // length of pattern 
    int n=strlen(txt);  // length of text

    if(m>n){
        cout<<"The length of pattern can't be greater than the length of text"<<endl;
    }

    else{
            for(int i=0;i<n-m;i++){
            int j;
            for(j=0;j<m;j++){
                if(txt[i+j]!=pat[j]){   // in this loop if any of the values of the strings don't match further and break the loop and proceed with the new value of i
                    break;
                }
            }
            if(j==m){ //if the above if condition does not break and we proceed upto the end of the pattern, it means that the match is found 
                cout<<endl<<"Pattern found at index "<<i<<endl<<endl;
            }
        }
        cout<<endl<<"No match for the pattern is found in the text"<<endl<<endl;
    }
}

int main()
{
    char txt[]="ABCCDDAEFG";
    char pat[]="ABCCDDAEFSD";
    strMatch(pat, txt);
    return 0;
}