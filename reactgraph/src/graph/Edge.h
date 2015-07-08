// Edge

namespace reactive {
namespace graph {
	
class Edge: public Node {
  public:
    Identity source;
	Identity predicate;
	Identity destination;
};

}
}
