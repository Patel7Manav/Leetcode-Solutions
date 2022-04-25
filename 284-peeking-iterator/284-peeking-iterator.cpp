/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
   
    struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
    ListNode *temp;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    ListNode *head=new ListNode(nums[0]);
        ListNode *curr=head;
        for(int i=1;i<nums.size();i++)
        {
            curr->next=new ListNode(nums[i]);
            curr=curr->next;
        }
        temp=head;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
       return temp->val;
        
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int value=temp->val;
        temp=temp->next;
        return value;
	}
	
	bool hasNext() const {
	    if(temp==NULL)
            return false;
        return true;
	}
};