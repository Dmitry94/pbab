#ifndef GRAPH_PAINTING_STRUCTURES
#define GRAPH_PAINTING_STRUCTURES

#include <list>

#include "Node.h"

typedef std::pair<int, int> VertexColorPair;

struct PartialPaint : public std::list<VertexColorPair>
{
	int MaxColor = 1;
	int CountOfVertexes = 0;
	PartialPaint(int count, VertexColorPair elem) : std::list<VertexColorPair>(count, elem) {}
	PartialPaint() : std::list<VertexColorPair>() {}
};

class PaintingRating
{
public:
	bool operator()(Node<PartialPaint> const*p1, Node<PartialPaint> const*p2) const
	{
		return p1->value.size() / (double)p1->value.MaxColor > p2->value.size() / (double)p2->value.MaxColor;
	}
};

#endif /* GRAPH_PAINTING_STRUCTURES */