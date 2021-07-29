/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int num) {
        // Employee* boss;
        // vector<int> workers_ids;
        // int sum = 0;
        // for(Employee* e:employees)
        //     if(e->id == num) {
        //         boss = e;
        //         sum += e->importance;
        //     }   
        // for(auto w:boss->subordinates)
        //     workers_ids.push_back(w);
        // for(int i=0;i<workers_ids.size();++i)
        //     for(Employee* e:employees)
        //         if(e->id == workers_ids[i])
        //             sum += e->importance;
        // return sum;
        queue<Employee *> employees_queue;
        Employee *boss;
        int sum = 0;
        for(Employee* e:employees)
            if(e->id == num) 
                boss = e;
        employees_queue.push(boss);
        while(!employees_queue.empty()) {
            Employee *curr = employees_queue.front();
            vector<int> workers_ids;
            vector<Employee *> workers;
            sum += curr->importance;
            employees_queue.pop();
            for(int w:curr->subordinates)
                workers_ids.push_back(w);
            for(int i=0;i<workers_ids.size();++i)
                for(Employee* e:employees)
                    if(e->id == workers_ids[i])
                        workers.push_back(e);
            for(auto w:workers)
                employees_queue.push(w);
        }
        return sum;   
    }
};
// @lc code=end

