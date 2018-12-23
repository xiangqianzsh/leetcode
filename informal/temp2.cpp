#include <algorithm>
class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        map<char, int> task_to_count;
        for (char &task : tasks) {
            task_to_count[task] += 1;
        }

        struct TaskInfo {
            char task;
            int count; // 总共多少个
            int index;  // 目前处理的为第几个
        };

        vector <TaskInfo> task_infos;
        for (auto it = task_to_count.begin(); it != task_to_count.end(); ++it) {
            TaskInfo task_info;
            task_info.task = it->first;
            task_info.count = it->second;

            task_info.index = 0;
            task_infos.push_back(task_info);
            // task_infos.emplace_back(it->first, it->second, 0);
        }

        struct Comp {
            bool operator()(TaskInfo &lhs, TaskInfo & rhs) {
                if (lhs.count > rhs.count) {  // 越大越靠前
                    return true;
                } else {
                    return false;
                }
            }
        };

        std::sort(task_infos.begin(), task_infos.end(), Comp());

        int all_intervals = 0;
        int interval_idx_of_first_task_group = 0; // 上一次处理的第首个任务时所在总任务的下标.

        // 最多的那个分组没任务时, 也就认为任务结束了
        while (task_infos[0].index != task_infos[0].count) {
            for (int i = 0; i < task_infos.size(); i++) {
                auto & task_info = task_infos[i];
                if (task_info.index == task_info.count) {  // 已经运行完了
                    continue;
                }
//                cout << "before task_info: " << task_info.task
//                     << ",cout:" << task_info.count
//                     << ", index:" << task_info.index
//                     << endl;
                if (i == 0) {
                    // 这中间再加一些idle, 如果需要的话
                    if (interval_idx_of_first_task_group > 0) {  // 需要加入idle interval
                        int between_task_num = all_intervals - interval_idx_of_first_task_group;
                        if (between_task_num < n) {
                            all_intervals += (n - between_task_num);  // 加入一定量的idle
                            cout << "aadd idle " << n - between_task_num << endl;
                        }
                    }

                    all_intervals += 1;
                    interval_idx_of_first_task_group = all_intervals;
                    task_info.index += 1;
                } else {
                    all_intervals += 1;
                    task_info.index += 1;
                }

                cout << "after task_info: " << task_info.task
                     << ",cout:" << task_info.count
                     << ", index:" << task_info.index
                     << ",all_intervals:" << all_intervals
                     << ",interval_idx_of_first_task_group:" << interval_idx_of_first_task_group
                     << endl;
            }
        }

        return all_intervals;

    }
};