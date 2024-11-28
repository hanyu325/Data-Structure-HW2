#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

struct HeapNode {
    int value;      
    int arrayIndex;  
    int elementIndex; 

    bool operator>(const HeapNode& other) const {
        return value > other.value; 
    }
};

vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays) {
    vector<int> result;
    priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> minHeap;

    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            minHeap.push({ arrays[i][0], i, 0 });
        }
    }

    while (!minHeap.empty()) {
        HeapNode node = minHeap.top();
        minHeap.pop();

        result.push_back(node.value);

        if (node.elementIndex + 1 < arrays[node.arrayIndex].size()) {
            minHeap.push({ arrays[node.arrayIndex][node.elementIndex + 1], node.arrayIndex, node.elementIndex + 1 });
        }
    }

    return result;
}

int main() {
    int n; 
    cin >> n;
    cin.ignore();

    vector<vector<int>> arrays(n);

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int num;
        while (ss >> num) {
            arrays[i].push_back(num);
        }
    }

    vector<int> mergedArray = mergeKSortedArrays(arrays);

    cout << "Merged Array: ";
    for (size_t i = 0; i < mergedArray.size(); ++i) {
        cout << mergedArray[i];
        if (i < mergedArray.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
