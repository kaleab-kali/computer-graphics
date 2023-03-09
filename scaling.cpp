#include <iostream>
using namespace std;

int main(){
    int x,y;
    float sx,sy;

    cout << "enter x and y coordinates of a point";
    cin >> x >> y ;
    cout << " enter scaling factor dx and dy";
    cin >> sx >> sy;

    float scalingmatrix[3][3] = {
        {sx,0,0},{0,sy,0},{0,0,1}
    };

    int pointmatrix[3][1] = {
        {x},{y},{1}
    };

    int resultmatrix[3][1] = {
        {0}
    };
    for(int i=0;i< 3;i++){
        for(int j=0;j<1;j++){
            for(int k=0;k<3;k++){
                resultmatrix[i][j] += scalingmatrix[i][k] * pointmatrix[k][j];
            }
        }
    }
    cout << "translated point (" << resultmatrix[0][0] << "," << resultmatrix[1][0] << ")" << endl;

    return 0;
}