#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int r) {
    int m = matrix.size();
    int n = matrix[0].size();
    int startr = 0;
    int endr = m-1;
    int startc = 0;
    int endc = n-1;
    int temp = 0;
    vector <int> holder;
    while(startr<endr&&startc<endc){
        for(int i = startr;i<=endr-1;i++){
 
        holder.push_back(matrix[i][startc]);
        }

        for(int i = startc;i<=endc-1;i++){

            holder.push_back(matrix[endr][i]);
        }

        for(int i=endr;i>=startr+1;i--){
            holder.push_back(matrix[i][endc]);
        }

        for(int i = endc;i>=startc+1;i--){
            holder.push_back(matrix[startr][i]);
        }
        int rot = r;
        rot = rot%holder.size();
        while(rot>0){
            int le = holder[holder.size()-1];
        holder.insert(holder.begin(),le);
        holder.pop_back();
        rot--;
        }
        int count = 0;
        for(int i = startr;i<=endr-1;i++){
            if(count==holder.size()) break;
            matrix[i][startc] = holder[count++];
        }
        for(int i = startc;i<=endc-1;i++){
            if(count==holder.size()) break;
            matrix[endr][i] = holder[count++];
        }
        for(int i=endr;i>=startr+1;i--){
            if(count==holder.size()) break;
            matrix[i][endc] = holder[count++];
        }
        for(int i = endc;i>=startc+1;i--){
            if(count==holder.size()) break;
            matrix[startr][i] = holder[count++];
        }
        holder.clear();
        startc++;
        startr++;
        endr--;
        endc--;
    }
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    int m,n,r;
    cin>>m>>n>>r;
    vector <vector<int>> matrix(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    matrixRotation(matrix,r);
    return 0;
}

