#include <algorithm>
#include <iostream>
#include <list>
#include <sstream>
#include <unordered_map>
#include <vector>
#include "math.h"
using namespace std;

typedef struct peca {
    int left, right;
    char letter;
} peca;

string quebraCabe(int tamanho, vector<peca> matriz) {
    unordered_map<int, pair<vector<int>, int>> leftMap, rightMap;
    stringstream ss;

    // Cria um mapeamento de left e right integers
    for(int i = 0; i < matriz.size(); i++) {
        peca& p = matriz[i];
        leftMap[p.left].first.push_back(i);
        leftMap[p.left].second = 0;
        rightMap[p.right].first.push_back(i);
        rightMap[p.right].second = 0;
    }

    int left = 0;
    // Enquanto nao for o fim
    while(left != 1) {
        int last = leftMap[left].second++;
        int pIdx = leftMap[left].first[last];
        //
        ss << matriz[pIdx].letter;
        left = matriz[pIdx].right;
    }

    return ss.str();
}
