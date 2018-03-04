```c++
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class ListNodeHelper {
public:
    void display(ListNode * head, bool is_show_location = true) {
        if (head == NULL) {
            std::cout << "nil" << std::endl;
            return;
        }

        while (head != NULL) {
            if (is_show_location) {
                std::cout << head->val << ":" << head << "->";
            } else {
                std::cout << head->val << "->";
            }
            head = head->next;
        }
        std::cout << "nil" << std::endl;
    }

    ListNode * createList(std::vector<int> & vec) {
        if (vec.size() == 0) {
            return NULL;
        }
        ListNode * head = new ListNode(vec[0]);
        ListNode * p = head;
        int idx = 1;
        while (idx < vec.size()) {
            p->next = new ListNode(vec[idx]);
            p = p->next;
            ++idx;
        }
        return head;
    }

    void delete_nodes(ListNode * head) {
        if (head == NULL) {
            return;
        }
        if (head->next != NULL) {
            delete_nodes(head->next);
        }
        delete head;
    }
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // ListNodeHelper helper;
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode nil_head(0);
        ListNode * nil_head_ptr = &nil_head;
        nil_head_ptr->next = head;
        
        ListNode * pre = nil_head_ptr, *cur = head, *next = head->next;
        while (cur != NULL) {
            next = cur->next;
            ListNode *p = nil_head_ptr;
            bool changed = false;
            while (p->next != cur) {
                if (cur->val < p->next->val) {
                    pre->next = cur->next;
                    cur->next = p->next;
                    p->next = cur;
                    changed = true;
                    break;
                }
                p = p->next;
            }
            if (!changed) {
                pre = cur;
            }
            cur = next;
            // helper.display(nil_head_ptr);
        }
        
        return nil_head_ptr->next;
    }
};

int main()
{
    ListNodeHelper listNodeHelper;

    vector<int> a{5, 2, 1, 4, 3};
    // vector<int> a{3, 2, 1}
    ListNode * head = listNodeHelper.createList(a);
    listNodeHelper.display(head);

    Solution solution;
    ListNode * sorted = solution.insertionSortList(head);
    listNodeHelper.display(sorted);    

    return 0;
}
```