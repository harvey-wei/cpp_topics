#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <string_view>

template<typename T>
void print(std::string_view name, T const& q) {
    std::cout << name << ": \t";
    for (auto const& n : q)
        std::cout << n << ' ';
    std::cout << '\n';
}

template<typename Q>
void print_queue(std::string_view name, Q q) {
    // NB: q is passed by value because there is no way to traverse
    // priority_queue's content without erasing the queue.
    for (std::cout << name << ": \t"; !q.empty(); q.pop())
        std::cout << q.top() << ' ';
    std::cout << '\n';
}

struct Node
{
    int x, y;

    Node(int _x, int _y)
        :x(_x), y(_y)
    {}
};

struct comp_node
{
    bool operator()(const Node& lhs, const Node&rhs)
    {
        /* pq will pop the element which is put in the last position.
           Note that the Compare parameter is defined such that it returns true if its first
           argument comes before its second argument in a weak ordering.
        */
        if (lhs.x == rhs.x) return lhs.y > rhs.y;
        return lhs.x > rhs.x;
    }
};

struct NodeCmp
{
	bool operator()(const Node& lhs, const Node& rhs)
	{
		/* PQ will pop the element which is put in the back. */
		if (lhs.x == rhs.x) return lhs.y > rhs.y;

		/* In descending order, smaller is the root of pq*/
		/* smaller is poped first*/
		return lhs.x > rhs.x;

	}
};

int main()
{
	std::vector<int> data{1,8,5,6,3,4,0,9,7,2};
	print("data", data);

	std::priority_queue<int> q1; // Max queue

	for (int n : data)
	{
		q1.push(n);
	}

	print_queue("q1", q1);

	auto comp = [](const int& lhs, const int& rhs){ return lhs > rhs;};
	std::priority_queue<int, std::vector<int>, decltype(comp)> q2(comp); // min queue


	for (int n : data)
	{
		q2.push(n);
	}

	print_queue("q2", q2);

	std::priority_queue<int, std::vector<int>, std::greater<int>> q3; // min heap
	for (int n : data)
	{
		q3.push(n);
	}

	print_queue("q3", q3);


    std::priority_queue<Node, std::vector<Node>, NodeCmp> pq_node;

    for (int i = 0; i < 10; ++i)
    {
        pq_node.push(Node(rand(), rand()));
    }


    while (!pq_node.empty())
    {
        std::cout << pq_node.top().x << " " << pq_node.top().y << std::endl;
        pq_node.pop();
    }
	return 0;
}


int main1()
{
    const auto data = {1,8,5,6,3,4,0,9,7,2};
    print("data", data);

    std::priority_queue<int> q1; // Max priority queue
    for(int n : data)
        q1.push(n);

    print_queue("q1", q1);

    // Min priority queue
    // That is, the front of the queue contains the "last" element according to the weak ordering
    //  imposed by Compare.
    // std::greater<int> makes the max priority queue act as a min priority queue
    // When comparator returns true, the lhs element is placed before the rhs element.
    // In the case of std::greater as comparator, the "last" element according to the weak ordering
    // imposed by std::greater is the smaller one. Hence, mim heap
    std::priority_queue<int, std::vector<int>, std::greater<int>>
        minq1(data.begin(), data.end());

    print_queue("minq1", minq1);


    // Using a custom function object to compare elements.
    /* struct { */
    /*     bool operator() (const int l, const int r) const { return l > r; } */
    /* } customLess; */
    /* std::priority_queue<int> minq3(data.begin(), data.end(), customLess); */
    /**/
    /* print_queue("minq3", minq3); */

    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q5(cmp);

    for(int n : data)
        q5.push(n);
    print_queue("q5", q5);

    std::priority_queue<Node, std::vector<Node>, comp_node> pq_node;

    for (int i = 0; i < 10; ++i)
    {
        pq_node.push(Node(rand(), rand()));
    }

    while (!pq_node.empty())
    {
        std::cout << pq_node.top().x << " " << pq_node.top().y << std::endl;
        pq_node.pop();
    }

    return 0;
}


/*
 * Q: What is greater?
 * A: https://cplusplus.com/reference/functional/greater/
 */
