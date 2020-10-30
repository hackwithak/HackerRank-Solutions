#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// vector<string> getSubStr(string s){
//     vector<string> result;
//     for(int i=0;i<s.length();i++){
//         for(int len = 1;len<=s.length()-i;len++){
//             result.push_back(s.substr(i,len));
//         }
//     }
//     return result;
// }
// int sherlockAndAnagrams(string s) {
//     vector <string> subs;
//     unordered_multiset<char> Check;
//     unordered_multiset<char> CheckHelper;
//     subs = getSubStr(s);
//     int count = 0;
//     for(int i=0;i<subs.size()-1;i++){
//         for(int j=0;j<subs[i].length();j++){
//             Check.insert(subs[i][j]);
//         }
//         for(int j=i+1;j<subs.size();j++){
//                 if(subs[j].length()==Check.size()){
//                 int flag =0;
//                 for(int k=0;k<subs[j].length();k++){
//                     CheckHelper.insert(subs[j][k]);
//                 }
//                 if(Check==CheckHelper){
//                     count++;
//                 }
//                 }
//                 CheckHelper.clear();
//             }
               
//       Check.clear();
//         }
      
//     return count;
// }

int main()
{
    ios::sync_with_stdio(0);
    int q;
    cin >> q;
    while(q){
        string s;
        cin>>s;
        unordered_map<string,int> mp;
        for(int i=0;i<s.length();i++){
            for(int len = 1;len<=s.length()-i;len++){
                string t = s.substr(i,len);
                sort(t.begin(),t.end());
                mp[t]++;
            }
        }
        long long int ans = 0;
        for (auto t:mp){
            ans+=(t.second*(t.second-1))/2;
        }
        cout<<ans;
        cout<<"\n";
        q--;
    }
    return 0;
}
