#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Task {
    int profit;
    int deadline;
};

bool compareTasks(const Task& a, const Task& b) {
    return a.profit > b.profit;
}

int scheduleTasks(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end(), compareTasks);

    int maxDeadline = 0;
    for (const auto& task : tasks) {
        maxDeadline = max(maxDeadline, task.deadline);
    }

    vector<int> slots(maxDeadline + 1, -1);
    int totalProfit = 0;

    vector<int> scheduledTasks;

    for (const auto& task : tasks) {
        for (int i = task.deadline; i > 0; --i) {
            if (slots[i] == -1) {
                slots[i] = task.profit;
                totalProfit += task.profit;
                scheduledTasks.push_back(task.profit);
                break;
            }
        }
    }

    cout << "Maximum Profit: " << totalProfit << endl;
    cout << "Scheduled Tasks: ";
    for (size_t i = 0; i < scheduledTasks.size(); ++i) {
        cout << scheduledTasks[i] << ' ';
    }
    cout << endl;

    return totalProfit;
}

int main() {
    int N;
    cin >> N;

    vector<Task> tasks(N);

    for (int i = 0; i < N; ++i) {
        cin >> tasks[i].profit >> tasks[i].deadline;
    }

    scheduleTasks(tasks);

    return 0;
}
