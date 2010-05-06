#if !defined ( __TINY_XML_MOCK__ )
#define __TINY_XML_MOCK__

namespace ticpp
{
	namespace mock
	{
		struct Element;
		
		struct Node
		{
			MOCK_METHOD0( Clear, void ( void ) );
			MOCK_METHOD1( SetValue, void( const std::string& ) );
			MOCK_METHOD1( InsertEndChild, void( const StrictMock< Element >& ) );
			MOCK_METHOD1( LinkEndChild, void( const StrictMock< Node >* ) );
			MOCK_METHOD1( LinkEndChild, void( const StrictMock< Element >* ) );
			MOCK_METHOD1( SetText, void ( const double ) );
			MOCK_METHOD1( SetText, void ( const std::string& ) );
			MOCK_METHOD1( GetValue, void ( std::string* ) );
			MOCK_CONST_METHOD0( GetText, std::string (void) );
			MOCK_METHOD1( SetIntText, void ( const unsigned int ) );
			MOCK_METHOD1( RemoveChild, void ( Node* ) );
			MOCK_CONST_METHOD0( ToElement, StrictMock< Element >* (void) );
			MOCK_CONST_METHOD0( FirstChild, StrictMock< Node >* (void) );
			MOCK_CONST_METHOD1( FirstChild, StrictMock< Node >* ( const std::string& value) );
			MOCK_CONST_METHOD2( FirstChild, StrictMock< Node >* ( const std::string& value, bool ) );
			MOCK_CONST_METHOD1( IterateChildren, StrictMock< Node >* ( StrictMock< Node >* ) );
			MOCK_CONST_METHOD0( FirstChildElement, StrictMock< Element >* () );
			MOCK_CONST_METHOD1( FirstChildElement, StrictMock< Element >* ( bool ) );
			MOCK_CONST_METHOD0( Value, std::string (void) );
		};
		
		struct Element : public Node
		{
			Element( const std::string& ) : Node()
			{
			}
			MOCK_CONST_METHOD1( GetAttribute, std::string ( const std::string& ) );
			MOCK_METHOD2( SetAttribute, void ( const std::string&, const int ) );
			MOCK_METHOD2( SetAttribute, void ( const std::string&, const std::string& ) );
		};

		struct Document : public Node
		{
			Document(void) : Node()
			{
			}
			Document( const std::string& ) : Node()
			{
			}
			MOCK_METHOD0( SaveFile, void ( void ) );
			MOCK_METHOD1( LoadFile, void ( const std::string& ) );
			MOCK_METHOD1( Parse, void ( const std::string& ) );
			MOCK_CONST_METHOD0( GetDocument, StrictMock< Document >* (void) );
		};
	}
}
inline std::ostream& operator << ( std::ostream& os, const ticpp::mock::Node& )
{
	return( os );
}

#endif // !defined ( __TINY_XML_MOCK__ )
