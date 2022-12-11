#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <functional> // Default hash function object class
#include <cmath>

struct Node
{
    int key;
    Node* left;
    Node* righ;

    Node(int _key = 0, Node* _left = nullptr, Node* _right = nullptr)
        : key(_key), left(_left), righ(_right)
    {}
};

struct NodeHasher
{
    size_t operator()(const Node* const & node_ptr)
    {
        size_t shift = (size_t) log2(1 + sizeof(node_ptr));

        return (size_t) (((size_t) (node_ptr)) >> shift);
    }
};

struct NodeComparator
{
    bool operator()(const Node* lhs, const Node* rhs)
    {
        return lhs == rhs;
    }

};

struct Vertex
{
    int id;
    int key;

    Vertex(int _id, int _key = 0)
        : id(_id), key(_key)
    {}
};

class Graph
{
    public:
        int accu_vertex_cnt;
        std::unordered_map<int, Vertex*> id2vertex;
        std::unordered_map<int, std::unordered_set<int>> adj_list;

        Graph(int _cnt  = 0)
            : accu_vertex_cnt(_cnt)
        {}

        void insert_vertex(int key)
        {
            int id = ++accu_vertex_cnt;
            Vertex* v_new = new Vertex(id, key);
            id2vertex[id] = v_new;
            adj_list[id] = {};
        }

        void delete_vertex(int v_id)
        {
            /* Return if vertex does not exist. */
            if (adj_list.end() == adj_list.find(v_id)) return;

            for (const auto& neighbor: adj_list[v_id])
            {
                adj_list[neighbor].erase(v_id);
            }

            delete id2vertex[v_id];
            id2vertex.erase(v_id);
            adj_list.erase(v_id);

            return;
        }

        void insert_edge(int v_one, int v_two)
        {

        }
};

/* ref: https://stackoverflow.com/questions/20953390/what-is-the-fastest-hash-function-for-pointers */
template<typename Tval>
struct MyTemplatePointerHash1 {
    size_t operator()(const Tval* val) const {
        static const size_t shift = (size_t) log2(1 + sizeof(Tval));
        return (size_t)(val) >> shift;
    }
};

int main()
{
    char nts1[] = "Test";
    char nts2[] = "Test";
    std::string str1 (nts1);
    std::string str2 (nts2);

    std::hash<char*> ptr_hash;  // functor
    std::hash<std::string> str_hash; // functor

    std::cout << "same hashes:\n" << std::boolalpha;
    std::cout << "nts1 and nts2: " << (ptr_hash(nts1)==ptr_hash(nts2)) << '\n';
    std::cout << "str1 and str2: " << (str_hash(str1)==str_hash(str2)) << '\n';

    return 0;
}


/**
 * \ref https://thispointer.com/how-to-use-unordered_set-with-user-defined-classes-tutorial-example/
 */
