
#include <iostream>
#include <stack>

using namespace std;

const int ROW = 5;
const int COL = 5;

// Helper function to check if the pixel is valid
bool isValid(int x, int y, int fill_color, int target_color, int image[][COL]) {
    return (x >= 0) && (x < ROW) && (y >= 0) && (y < COL) && (image[x][y] == target_color);
}

// Flood fill algorithm using stack
void floodFill(int x, int y, int fill_color, int target_color, int image[][COL]) {
    stack<pair<int, int>> st;
    st.push({x, y});

    while (!st.empty()) {
        auto p = st.top();
        st.pop();

        int x = p.first;
        int y = p.second;

        // Check if the pixel is valid
        if (!isValid(x, y, fill_color, target_color, image)) {
            continue;
        }

        // Replace the color of current pixel with fill color
        image[x][y] = fill_color;

        // Add all 4-neighbors to stack
        st.push({x+1, y});
        st.push({x-1, y});
        st.push({x, y+1});
        st.push({x, y-1});
    }
}

int main() {
    int image[ROW][COL] = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 2, 2, 2},
        {1, 1, 2, 2, 2},
        {1, 1, 2, 2, 2}
    };

    int x = 2, y = 2, fill_color = 3;

    floodFill(x, y, fill_color, image[x][y], image);

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
