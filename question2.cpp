#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Task {
    string name;
    int priority;

    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

int main() {
    int N;
    cin >> N;
    cin.ignore();

    priority_queue<Task> pq;

    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "ADD") {
            string task_name;
            int priority;
            ss >> task_name >> priority;
            pq.push({ task_name, priority });
        }
        else if (command == "GET") {
            if (!pq.empty()) {
                Task top_task = pq.top();
                pq.pop();
                cout << top_task.name << endl;
            }
            else {
                cout << "No tasks available" << endl;
            }
        }
    }

    vector<Task> remaining_tasks;
    while (!pq.empty()) {
        remaining_tasks.push_back(pq.top());
        pq.pop();
    }

    sort(remaining_tasks.begin(), remaining_tasks.end(), [](const Task& a, const Task& b) {
        return a.priority > b.priority;
        });

    cout << "Remaining tasks: ";
    for (size_t i = 0; i < remaining_tasks.size(); ++i) {
        cout << remaining_tasks[i].name << ' ' << remaining_tasks[i].priority << ' ';
    }
    cout << endl;

    return 0;
}
