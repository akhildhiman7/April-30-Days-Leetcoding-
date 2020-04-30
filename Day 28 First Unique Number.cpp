/*
You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
void add(int value) insert value to the queue.


Example 1:

Input:
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
Output:
[null,2,null,2,null,3,null,-1]

Explanation:
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1

Example 2:

Input:
["FirstUnique","showFirstUnique","add","add","add","add","add","showFirstUnique"]
[[[7,7,7,7,7,7]],[],[7],[3],[3],[7],[17],[]]
Output:
[null,-1,null,null,null,null,null,17]

Explanation:
FirstUnique firstUnique = new FirstUnique([7,7,7,7,7,7]);
firstUnique.showFirstUnique(); // return -1
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7]
firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3]
firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3,3]
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7,3,3,7]
firstUnique.add(17);           // the queue is now [7,7,7,7,7,7,7,3,3,7,17]
firstUnique.showFirstUnique(); // return 17

Example 3:

Input:
["FirstUnique","showFirstUnique","add","showFirstUnique"]
[[[809]],[],[809],[]]
Output:
[null,809,null,-1]

Explanation:
FirstUnique firstUnique = new FirstUnique([809]);
firstUnique.showFirstUnique(); // return 809
firstUnique.add(809);          // the queue is now [809,809]
firstUnique.showFirstUnique(); // return -1



Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^8
1 <= value <= 10^8
At most 50000 calls will be made to showFirstUnique and add.
*/

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node (int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class FirstUnique {
private:
	unordered_map<int, int> um;
    unordered_map<int, Node*> linked;
    queue<int> q;
    set<int> unique;

    Node *head = NULL;
    Node *prev = NULL;

    void addNode(int data) {
        Node *newnode = new Node(data);
        linked[data] = newnode;
        if (head == NULL) {
            head = newnode;
            prev = newnode;
            return;
        }
        prev->next = newnode;
        newnode->prev = prev;
        prev = newnode;
    }

    void deleteNode(int data) {
        Node *curr = linked[data];
        if (curr == NULL)
            cout<<NULL;
        else
            cout<<curr->data<<endl;
        if (curr->next == NULL and curr->prev == NULL) {
            delete curr;
            head = NULL;
            prev = NULL;
            linked.erase(data);
            return;
        }
        if (curr == head) {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            linked.erase(data);
            return;
        }
        if (curr == prev) {
            Node *temp = prev;
            prev = prev->prev;
            prev->next = NULL;
            delete temp;
            linked.erase(data);
            return;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        linked.erase(data);
    }

public:
    FirstUnique(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			add(nums[i]);
		}
    }

    int showFirstUnique() {
    	if (head == NULL)
    		return -1;
    	return head->data;
    }

    void add(int value) {
    	q.push(value);
    	if (um.count(value) < 1) {
    		addNode(value);
    		um[value] = 1;
		}
		else {
            if (linked.count(value) > 0)
			    deleteNode(value);
			um[value] += 1;
		}
    }
};


/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
