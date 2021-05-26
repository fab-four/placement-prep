/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/employee-importance/
 */

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
    unordered_map<int, int> m;

  public:
    int getImportance(vector<Employee *> employees, int id) {
        for (int i = 0; i < employees.size(); i++) {
            m[employees[i]->id] = i;
        }
        return getImportanceUtil(employees, id);
    }
    int getImportanceUtil(vector<Employee *> employees, int id) {
        int index = m[id];
        int importance = employees[index]->importance;
        for (int subId : employees[index]->subordinates) {
            importance += getImportanceUtil(employees, subId);
        }
        return importance;
    }
};