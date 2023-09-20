// defining the constructor within the class
// ref: https://www.geeksforgeeks.org/constructors-c/

#include <iostream>
using namespace std;

class student {
    private:
        int rno;
        char name[10];
        double fee;

    public:
        /*
           Explicit default constructor by user. Even if we do not define any constructor explicitly,
           the compiler will automatically provide a default constructor implicitly.
        */
        student()
        {
            cout << "Enter the RollNo:";
            cin >> rno;
            cout << "Enter the Name:";
            cin >> name;
            cout << "Enter the Fee:";
            cin >> fee;
        }

        void display()
        {
            cout << endl << rno << "\t" << name << "\t" << fee;
        }
};

class Point {
    private:
        int x, y;

    public:
        /*
           Parameterized Constructor
           when the parameterized constructor is defined and no default constructor is defined
           explicitly, the compiler will not implicitly call the default constructor and hence
           creating a simple object as
           Point p;
           will give rise to an error!
        */
        Point(int x1, int y1)
        {
            x = x1;
            y = y1;
        }

        /* Copy constructor

        */
        Point(const Point& pt)
        {
            x = pt.x;
            y = pt.y;
        }

        /* Move cosntructor */
        Point(const Point&& pt)
        {
            x = pt.x;
            y = pt.y;
        }

        /* initilizer list constructor */
        Point(std::initializer_list<int> list)
        {

        }

        /* Destructor */
        ~Point()
        {

        }

        /*
            Copy assignment operator

            param[in] must be a constant lvalue reference which accepts both lvalue and rvalue.

            when we don’t write our own assignment operator, the compiler creates an copy assignment
            operator itself that does shallow copy and thus causes problems
            ref: https://www.geeksforgeeks.org/default-assignment-operator-and-references-in-cpp/

            The compiler defines the default copy constructor. If the user defines no copy
            constructor, compiler supplies its constructor.
            But NO default move assignment operator and move constructor!
            ref: https://stackoverflow.com/questions/4819936/why-no-default-move-assignment-move-constructor

            return reference to the assigned object for cascade assignment.
        */
        Point& operator=(const Point& other)
        {
            x = other.x;
            y = other.y;

            return *this;
        }

        /* Move assignment operator */
        Point& operator=(const Point&& other)
        {
            x = other.x;
            y = other.y;

            return *this;
        }

        int getX() { return x; }
        int getY() { return y; }
};

struct Node
{
    int val;

    Node(){};
    Node(int _val)
        : val(_val)
    {}
};

int main()
{
    Node* n = new Node();
	student s; // constructor gets called automatically when
			// we create the object of the class
	s.display();

    /* Point p;  Error! */
    Point p1(10, 15);

    // Access values assigned by constructor
    cout << "p1.x = " << p1.getX()
         << ", p1.y = " << p1.getY();


	return 0;
}

/*
    When an object is declared in a parameterized constructor, the initial values have to be passed
    as arguments to the constructor function. The normal way of object declaration may not work.
    The constructors can be called explicitly or implicitly.
    Example e = Example(0, 50); // Explicit call
    Example e(0, 50);           // Implicit call
*/
