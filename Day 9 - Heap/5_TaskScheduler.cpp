/*
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

https://leetcode.com/problems/task-scheduler/description/
*/

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::vector<int> taskCount(26, 0);
        for (char task : tasks) {
            taskCount[task - 'A']++;
        }

        std::priority_queue<std::pair<int, char>> taskQueue;

        for (int i = 0; i < 26; i++) {
            if (taskCount[i] > 0) {
                taskQueue.push({taskCount[i], 'A' + i});
            }
        }

        int time = 0;
        while (!taskQueue.empty()) {
            std::vector<std::pair<int, char>> temp;
            for (int i = 0; i <= n; i++) {
                if (!taskQueue.empty()) {
                    auto task = taskQueue.top();
                    taskQueue.pop();
                    if (task.first > 1) {
                        temp.push_back({task.first - 1, task.second});
                    }
                }

                time++;

                if (taskQueue.empty() && temp.empty()) {
                    break;
                }
            }

            for (auto& task : temp) {
                taskQueue.push(task);
            }
        }

        return time;
    }
};