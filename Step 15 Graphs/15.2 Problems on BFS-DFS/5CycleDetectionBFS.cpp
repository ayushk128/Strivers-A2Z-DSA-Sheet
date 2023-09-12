#include<bits/stdc++.h>
using namespace std;
// Using BFS
vector<vector<int>> floodFill(vector<vector<int>> &image, int srcR, int srcC, int oldCol, int newCol) {
    int n = image.size();
    int m = image[0].size();

    vector<vector<int>> newImage = image;

    int iniCol = image[srcR][srcC];

    queue<pair<int, int>> q;
    q.push({srcR, srcC});
    newImage[srcR][srcC] = newCol;

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i<4; i++) {
            int nRow = r + delRow[i];
            int nCol = c + delCol[i];

            if(nRow >= 0 && nRow <= n && nCol >= 0 && nRow < m && image[nRow][nCol] == iniCol && newImage[nRow][nCol] != newCol) {
                newImage[nRow][nCol] = newCol;
                q.push({nRow, nCol});
            }
        }
    }
    return newImage;
}

// Using DFS
// void dfs(vector<vector<int>> &image, vector<vector<int>> &newImage, int srcR, int srcC, int delRow[], int delCol[], int iniCol, int newCol) {
    
//     newImage[srcR][srcC] = newCol;
//     int n = image.size();
//     int m = image[0].size();

//     for(int i = 0; i<4; i++) {
//         int r = srcR + delRow[i];
//         int c = srcC + delCol[i];

//         if(r >= 0 && r < n && c >= 0 && c <= m && image[r][c] == iniCol && newImage[r][c] != newCol) {
//                 dfs(image, newImage, r, c, delRow, delCol, iniCol, newCol);
//         }
//     }
// }
// vector<vector<int>> floodFill(vector<vector<int>> &image, int srcR, int srcC, int oldCol, int newCol) {
//     int iniCol = image[srcR][srcC];
//     vector<vector<int>> newImage = image;
//     int delRow[] = {-1, 0, 1, 0};
//     int delCol[] = {0, 1, 0, -1};

//     dfs(image, newImage, srcR, srcC, delRow, delCol, iniCol, newCol);

//     return newImage;

// }
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> image = {{1,1,1}, {1,1,0}, {1,0,1}};

    int srcR = 1;
    int srcC = 1;
    int newCol = 2;
    int oldCol = image[srcR][srcC];

    vector<vector<int>> newImage = floodFill(image, srcR, srcC, oldCol, newCol);

    for(int i = 0; i<newImage.size(); i++) {
        for(int j = 0; j<newImage[0].size(); j++) {
            cout << newImage[i][j] << " ";
        }
        cout << "\n";
    }
}