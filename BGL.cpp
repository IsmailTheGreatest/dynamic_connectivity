#include <boost/graph/disjoint_sets.hpp>
#include <boost/graph/adjacency_list.hpp>

// Define the graph type
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> Graph;

int main() {
    // Create a graph
    Graph graph(5);

    // Add edges to the graph
    boost::add_edge(0, 1, graph);
    boost::add_edge(1, 2, graph);
    boost::add_edge(3, 4, graph);

    // Create a disjoint sets data structure with 5 elements
    boost::disjoint_sets<boost::property_map<Graph, boost::vertex_index_t>::type> ds(boost::vertices(graph));

    // Perform some union operations
    ds.union_set(0, 1);
    ds.union_set(1, 2);

    // Check if two elements are connected
    if (ds.find_set(0) == ds.find_set(2)) {
        std::cout << "Vertices 0 and 2 are connected.\n";
    } else {
        std::cout << "Vertices 0 and 2 are not connected.\n";
    }

    if (ds.find_set(3) == ds.find_set(4)) {
        std::cout << "Vertices 3 and 4 are connected.\n";
    } else {
        std::cout << "Vertices 3 and 4 are not connected.\n";
    }

    return 0;
}
