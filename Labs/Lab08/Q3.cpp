#include <cstdio>

class Lock {
    private:
        int l, r;
        int cur_l, cur_r;
        int lst;
    public:
        Lock(int _l, int _r) {
            l = _l;
            r = _r;
            cur_l = 0;
            cur_r = 0;
            lst = 0;
        }
        void turn_left(int);
        void turn_right(int);
        void reset();
        bool unlock();
};

void Lock::turn_left(int n) {
    if (lst == 2) { // lst == turn_right
        cur_r = 0;
    }
    cur_l += n;
    lst = 1;
}

void Lock::turn_right(int n) {
    if (lst == 1) { // lst == turn_left
        cur_l = 0;
    }
    cur_r += n;
    lst = 2;
}

void Lock::reset() {
    cur_l = 0, cur_r = 0;
    lst = 0;
}

bool Lock::unlock() {
    // fprintf(stderr, "cur_l = %d, cur_r = %d", cur_l, cur_r);
    lst = 0;
    if (cur_l == l && cur_r == r) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int l, r;
    puts("Enter the value for the left counter:");
    scanf("%d", &l);
    puts("Enter the value for the right counter:");
    scanf("%d", &r);
    Lock lock(l, r);
    while (true) {
        puts("Enter the operation:");
        char op;
        int n;
        scanf(" %c", &op);
        switch(op) {
            case 'l':
                scanf("%d", &n);
                lock.turn_left(n);
                break;
            case 'r':
                scanf("%d", &n);
                lock.turn_right(n);
                break;
            case 'u':
                if (lock.unlock()) {
                    puts("Successful!");
                    return 0;
                } else {
                    puts("Failed!");
                }
                break;
            case 's':
                lock.reset();
                break;
            case 'e':
                puts("Program terminate!");
                return 0;
        }
    }
}