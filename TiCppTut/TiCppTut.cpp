// TinyTut.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>
#include "..\ticpp.h"

void dump_to_stdout( const char* pFileName );
void dump_to_stdout( ticpp::Node* pParent, unsigned int indent = 0 );
const char* getIndent( unsigned int numIndents );
const char* getIndentAlt( unsigned int numIndents );
int dump_attribs_to_stdout( ticpp::Element* pElement, unsigned int indent );

using namespace ticpp;

int main( int argc, char* argv[] )
{
	if ( argc <= 1 )
	{
		std::cout <<  "No arguments found.\nPass an xml file as an argument or just drop it on this executable." << std::endl;
		return 1;
	}

	for ( int i = 1; i < argc; i++ )
	{
		dump_to_stdout( argv[i] );
	}

	return 0;
}

// ----------------------------------------------------------------------
// STDOUT dump and indenting utility functions
// ----------------------------------------------------------------------
const unsigned int NUM_INDENTS_PER_SPACE=2;

const char* getIndent( unsigned int numIndents )
{
	static const char* pINDENT = "                                      + ";
	static const size_t LENGTH = strlen( pINDENT );
	size_t n = numIndents * NUM_INDENTS_PER_SPACE;
	if ( n > LENGTH )
	{
		n = LENGTH;
	}

	return &pINDENT[ LENGTH - n ];
}

// same as getIndent but no "+" at the end
const char* getIndentAlt( unsigned int numIndents )
{
	static const char* pINDENT = "                                        ";
	static const size_t LENGTH = strlen( pINDENT );
	size_t n = numIndents * NUM_INDENTS_PER_SPACE;
	if ( n > LENGTH )
	{
		n = LENGTH;
	}
	return &pINDENT[ LENGTH - n ];
}

int dump_attribs_to_stdout( ticpp::Element* pElement, unsigned int indent )
{
	int i = 0;
	try
	{
		const char* pIndent = getIndent( indent );

		std::cout << std::endl;

		int ival;
		double dval;
		ticpp::Iterator< ticpp::Attribute > attribute;
		for ( attribute = pElement->FirstAttribute( false ); attribute != attribute.end(); attribute++, i++ )
		{
			std::cout << pIndent << attribute->Name() << ": value=[" << attribute->Value() << "]";
			try
			{
				attribute->GetValue( &ival );
				attribute->GetValue( &dval );
				std::cout << " int=[" << ival << "] double=[" << dval << "]\n";
			}
			catch( ticpp::Exception& )
			{
				std::cout << std::endl;
			}

		}
	}
	catch( ticpp::Exception& ex )
	{
		std::cout << "Got exception: " << ex.m_details;
	}
	return i;
}

void dump_to_stdout( ticpp::Node* pParent, unsigned int indent )
{
	try
	{
		int t = pParent->Type();
		std::cout << getIndent( indent );
		int num;

		switch ( t )
		{
			case TiXmlNode::DOCUMENT:
				std::cout << "Document";
				break;

			case TiXmlNode::ELEMENT:
			{
				std::cout << "Element [" << pParent->Value() << "]";
				ticpp::Element* elm = pParent->ToElement();
				num = dump_attribs_to_stdout( elm, indent + 1 );
				switch( num )
				{
					case 0:
						std::cout << " (No attributes)";
						break;
					case 1:
						std::cout << getIndentAlt( indent ) << "1 attribute";
						break;
					default:
						std::cout <<  getIndentAlt( indent ) << num << " attributes";
						break;
				}
				break;
			}

			case TiXmlNode::COMMENT:
				std::cout << "Comment: [" << pParent->Value() << "]";
				break;

			case TiXmlNode::UNKNOWN:
				std::cout << "Unknown";
				break;

			case TiXmlNode::TEXT:
				std::cout << "Text: [" << pParent->ToText()->Value() << "]";
				break;

			case TiXmlNode::DECLARATION:
				std::cout << "Declaration";
				break;

			default:
				break;
		}

		std::cout << "\n";
		ticpp::Iterator< ticpp::Node > iterator;
		for ( iterator = pParent->FirstChild( false ); iterator != iterator.end(); iterator++ )
		{
			dump_to_stdout( &(*iterator), indent + 1 );
		}
	}
	catch( ticpp::Exception& ex )
	{
		std::cout << "Got exception: " << ex.m_details;
	}
}

// load the named file and dump its structure to STDOUT
void dump_to_stdout( const char* pFileName )
{
	try
	{
		ticpp::Document doc( pFileName );
		doc.LoadFile();
		std::cout << std::endl << pFileName << std::endl;
		dump_to_stdout( &doc ); // defined later in the tutorial
	}
	catch( ticpp::Exception& ex )
	{
		std::cout << "Failed to load file \"" << pFileName << "\"\n" << "Got Exception:\n" << ex.m_details;
	}
}
