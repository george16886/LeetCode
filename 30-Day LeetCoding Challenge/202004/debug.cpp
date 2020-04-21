#include <iostream>
#include <vector>
using namespace std;

// This is the BinaryMatrix's API interface.
// You should not implement it, or speculate about its implementation
class BinaryMatrix {
   private:
    vector<vector<int>> mat;

   public:
    BinaryMatrix(vector<vector<int>> in) {
        mat = in;
        for (auto row : mat) {
            cout << "  [ ";
            for (auto i : row)
                cout << i << " ";
            cout << "]" << endl;
        }
    };

    int get(int x, int y) {
        return mat[x][y];
    };

    vector<int> dimensions() {
        int rows = mat.size();
        int cols = mat[0].size();
        return {rows, cols};
    };
};

class Solution {
   public:
    int leftMostColumnWithOne(BinaryMatrix& binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int rows = dim[0];
        int cols = dim[1];

        int ans = cols - 1;
        for (int row = 0; row < rows; row++) {
            if (binaryMatrix.get(row, ans)) {
                for (int col = ans; col >= 0; col--) {
                    if (!ans)
                        return 0;
                    if (!binaryMatrix.get(row, ans - 1))
                        break;
                    ans--;
                }
            } else if ((row == rows - 1) && (ans == cols - 1))
                return -1;
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution solution;

    vector<vector<int>> mat = {{0, 0, 0, 1}, {0, 0, 1, 1}, {0, 1, 1, 1}};
    BinaryMatrix binaryMatrix(mat);
    vector<int> dim = binaryMatrix.dimensions();
    int rows = dim[0];
    int cols = dim[1];
    cout << "mat is a " << cols << "x" << rows << " matrix." << endl;
    cout << "and mat(1, 1) = " << binaryMatrix.get(1, 1) << endl;
    cout << "======================== test over ========================" << endl
         << endl;

    mat = {{0, 0}, {1, 1}};
    cout << "Input: mat = [";
    for (auto row : mat) {
        cout << " [ ";
        for (auto i : row)
            cout << i << " ";
        cout << "] ";
    }
    cout << "] " << endl;
    BinaryMatrix m1(mat);
    cout << "Output: " << solution.leftMostColumnWithOne(m1) << endl
         << endl;

    mat = {{0, 0}, {0, 1}};
    cout << "Input: mat = [";
    for (auto row : mat) {
        cout << " [ ";
        for (auto i : row)
            cout << i << " ";
        cout << "] ";
    }
    cout << "] " << endl;
    BinaryMatrix m2(mat);
    cout << "Output: " << solution.leftMostColumnWithOne(m2) << endl
         << endl;

    mat = {{0, 0}, {0, 0}};
    cout << "Input: mat = [";
    for (auto row : mat) {
        cout << " [ ";
        for (auto i : row)
            cout << i << " ";
        cout << "] ";
    }
    cout << "] " << endl;
    BinaryMatrix m3(mat);
    cout << "Output: " << solution.leftMostColumnWithOne(m3) << endl
         << endl;

    mat = {{0, 0, 0, 1}, {0, 0, 1, 1}, {0, 1, 1, 1}};
    cout << "Input: mat = [";
    for (auto row : mat) {
        cout << " [ ";
        for (auto i : row)
            cout << i << " ";
        cout << "] ";
    }
    cout << "] " << endl;
    BinaryMatrix m4(mat);
    cout << "Output: " << solution.leftMostColumnWithOne(m4) << endl
         << endl;

    return 0;
}
