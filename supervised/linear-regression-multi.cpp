#include <vector>
#include <iostream>

using namespace std;

float predict(vector<float> *theta, vector<float> *x) {

    float y;
    int size_theta = theta->size();
    int size_x = x->size();

    y = size_theta * size_x;
    cout << y << endl;
    return y;
}

int  main() {

    vector<float> v1 = {.2, .3, .1};
    vector<float> v2 = {.2, .3, .1};

    cout << v1[1] << endl;
    return 0;
}