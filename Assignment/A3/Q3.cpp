#include <iostream>
using namespace std;
const int N = 20 + 2;

int num[N];
class node {
    public:
    int data;
    node* next;
    node() {
        data = 0;
        next = NULL;
    }
    node(int d) {
        data = d;
        next = NULL;
    }
};

class LinkList {
    public:
    node* head;
    LinkList() {
        head = new node();
    }
    void insert(int);
    node* getNth(int);
};
void LinkList::insert(int d) {
    node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new node(d);
}
node* LinkList::getNth(int n) {
    node* p = head;
    for (int i = 1; i <= n; i++) {
        p = p->next;
    }
    return p;
}

LinkList l;

void nodeSwap(node* p) {
    int tmp = p->data;
    p->data = p->next->data;
    p->next->data = tmp;
}

int main() {
    int n;
    cout << "Please input the count of the numbers:" << endl;
    cin >> n;
    cout << "Please input the content of the numbers:" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    // build the link list
    for (int i = 1; i <= n; i++) {
        l.insert(num[i]);
    }

    int lft, rht;
    cout << "Input the value of left:" << endl;
    cin >> lft;
    cout << "Input the value of right:" << endl;
    cin >> rht;
    cout << "The sorted linked list is:";
    if (lft > n || rht < 1) {
        return 0;
    }

    // bubble sort
    node* lhead = l.getNth(lft);
    node* rhead = l.getNth(rht);
    // outer loop executes (original_rht-lft) times
    while (lhead != rhead) {
        node* cur = lhead;
        // inner loop executes (current_rht-lft) times
        while (true) { // effectively, cur != rhead
            if (cur->data > cur->next->data) {
                nodeSwap(cur);
            }
            if (cur->next == rhead) {
                // every outer loop, move rhead 1 step left
                rhead = cur;
                break;
            }
            // every inner loop, move cur 1 step right
            cur = cur->next;
        }
    }
    // the original bubble sort, outer loop to right, inner loop to left, and switch arr[j] with arr[j-1]
    // since we cannot move in the opposite direction
    // I make outer loop to left, inner loop to right, and switch cur with cur->next

    // print the full linked list
    node* p = l.head;
    while (p->next != NULL) {
        p = p->next;
        cout << " " << p->data;
    }
    cout << endl;
}