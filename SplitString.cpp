#include<iostream>
#include<vector>
#include<cstring>
using namespace std ;

vector <string> split(string s)
{
	vector<string> ans;
	int size=s.length();
	for (int i = 0; i < size; i++)
	{
		int j = 0;
		string s2;
		// splitting bases on space " "
		while(s[i+j]!= ' ' && (i+j)<size)
		{
			s2.push_back(s[i+j]);
			j++;
		}
		ans.push_back(s2);
		i = i+j;
	}
	return ans;
}

int main ()
{
	// string str;
	vector <string> ans = split("welcome to the jungle");
	for (int i = 0; i < ans.size(); i++)
	{
		cout<<ans[i]<<endl;
	}
	
	return 0 ;
}