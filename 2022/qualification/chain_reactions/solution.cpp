#include <deque>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int T, N, i;

struct Node {
    int value;
    int parent;
    unordered_set<int> children;
    int min_child;
};

int main() {
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        vector<Node> vec(1e5 + 1);
        unordered_set<int> is_parent;
        int value, parent, front, min_child;
        Node current;
        vec[0].parent = -1;

        vec[0].min_child = 0;
        vec[0].value = 0;

        cin >> N;
        for (i = 1; i <= N; ++i) {
            cin >> value;
            vec[i].value = value;
        }
        for (i = 1; i <= N; ++i) {
            cin >> parent;
            vec[i].parent = parent;
            vec[parent].children.insert(i);
            is_parent.insert(parent);
        }

        deque<int> deq;

        for (i = 0; i <= N; ++i) {
            if (is_parent.find(i) == is_parent.end()) {
                deq.push_back(i);
                // cout << i << " ";
            }
        }
        // cout << endl;
        int64_t total = 0;

        while (!deq.empty() && vec[deq.front()].parent != -1) {
            front = deq.front();
            deq.pop_front();
            // cout << front << endl;
            current = vec[front];
            min_child = vec[current.parent].min_child;
            if (min_child == 0) {
                vec[current.parent].min_child = vec[front].value;
            } else {
                if (min_child <= vec[front].value) {
                    total += vec[front].value;
                } else {
                    total += min_child;
                    vec[current.parent].min_child = vec[front].value;
                }
            }
            vec[current.parent].children.erase(front);
            if (vec[current.parent].children.empty()) {
                vec[current.parent].value = max(vec[current.parent].min_child,
                                                vec[current.parent].value);
                deq.push_back(current.parent);
                vec[front].min_child = 0;
                vec[front].value = 0;
            }
            // cout << "total: " << total << endl;
        }
        total += vec[0].value;
        cout << "Case #" << t << ": " << total << endl;
        is_parent.clear();
    }
}