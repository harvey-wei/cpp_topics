// C++ program to demonstrate shared_ptr
#include <iostream>
#include <memory>
using namespace std;

class A {
public:
	void show()
	{
		cout << "A::show()" << endl;
	}
    ~A(){ cout << "destroyed" << endl;}
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int _val = 0, TreeNode* _left = nullptr, TreeNode* _right = nullptr)
        : val(_val), left(_left), right(_right)
    {}

    ~TreeNode()
    {
        std::cout << "The tree node is destroyed! " << std::endl;
    }
};

int main()
{
	shared_ptr<A> p1(new A);

    /* returns the raw pointer. */
	cout << p1.get() << endl;
	p1->show();
	shared_ptr<A> p2(p1); // copy constructor to pass the reference counter
	p2->show();
	cout << p1.get() << endl;
	cout << p2.get() << endl;

	// Returns the number of shared_ptr objects
	// referring to the same managed object.
    // Return the reference count.
	cout << p1.use_count() << endl;
	cout << p2.use_count() << endl;

	// Relinquishes ownership of p1 on the object
	// and pointer becomes NULL
    // shared_ptr has data member: raw pointer to the resource and raw pointer to the counter().
	p1.reset();
	cout << p1.get() << endl;

    cout << "After resetting: the use_count: ";
	cout << p2.use_count() << endl;
	cout << p2.get() << endl;

    std::shared_ptr<TreeNode> node_ptr(new TreeNode);
    std::shared_ptr<TreeNode> node_ptr_another(node_ptr);
    node_ptr->val = 100; // access raw TreeNode memember by shared_ptr
    node_ptr_another->val = 1000;
    std::cout << "The ref_count for node: " << node_ptr.use_count() << std::endl;
    std::cout << "The ref_count for node: " << node_ptr_another.use_count() << std::endl;

    node_ptr_another.reset();
    std::cout << "After resetting: ";
    std::cout << "The ref_count for node: " << node_ptr.use_count() << std::endl;

    std::cout << "The value of the tree node: " << node_ptr->val << std::endl;

	return 0;
}

/** Q: When to use shared_ptr?
  * A: Use shared_ptr if you want to share ownership of a resource.
  * Many shared_ptr can point to a single resource. shared_ptr maintains reference count
  * for this propose. when all shared_ptr pointers pointing to resource goes out of scope the resource
  * is destroyed.
  * The reference counter increments each time the
  * ref: https://docs.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-shared-ptr-instances?view=msvc-170
  * ref: https://www.geeksforgeeks.org/auto_ptr-unique_ptr-shared_ptr-weak_ptr-2/
  */
