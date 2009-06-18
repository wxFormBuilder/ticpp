#include "ticpp_sugar.h"

namespace ticpp
{
namespace sugar
{
    const Element& NodeCombiner::RootNode() const
    {
        return m_CombinerNode;
    }

    NodeCombiner& NodeCombiner::operator+ (Node& rhs)
    {
        m_CombinerNode.Insert(rhs);
        return *this;
    }

    NodeCombiner operator+ (Node& lhs,  Node& rhs)
    {
        NodeCombiner nc;
        nc.m_CombinerNode.InsertEndChild(lhs);
        nc.m_CombinerNode.InsertEndChild(rhs);

        return nc;
    }

} //namespace ticpp
} //namespace sugar
