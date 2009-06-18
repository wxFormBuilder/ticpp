#ifndef TicppSugar_h__
#define TicppSugar_h__

#include "ticpp.h"
#include <string>

namespace ticpp
{
	/**
	@subpage ticpp::sugar provides an alternative syntax to create and manipulate TinyXML++ 
	elements.  
	
	To use ticpp::sugar:
	
	@code
	#include "ticpp_sugar.h"
	using namespace ticpp::sugar;
	@endcode 
	
	The syntax is best described with a real example:
	@code

    Element myApp("MyApp");
    myApp.Insert(
        Comment(" Settings for MyApp ") + 
        Element("Messages").Insert(
            Element("Welcome").SetText("Welcome to MyApp") + 
            Element("Farewell").SetText("Thank you for using MyApp")) +
        Element("Windows").Insert(
            Element("Window")("name", "MainFrame")("x", 5)("y", 15)("w", 400)("h", 250)) +
        Element("Connection")("ip", "192.168.0.1")("timeout", "123.456000"));
	
	@endcode 
	*/
	namespace sugar
	{
        class NodeCombiner
        {
        public:
            NodeCombiner& operator+ (Node& rhs);

            const Element& RootNode() const;

        private:
            Element m_CombinerNode;

            friend NodeCombiner operator+(Node&, Node&);
        };

        NodeCombiner operator+ (Node& lhs,  Node& rhs);

	} //namespace sugar
} //namespace ticpp

#endif // TicppSugar_h__
