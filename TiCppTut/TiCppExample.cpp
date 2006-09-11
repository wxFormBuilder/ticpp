
#include <iostream>
#include <string>
#include "../ticpp.h"

void GenerateExample( std::string filename );

int main( int argc, char* argv[] )
{
	GenerateExample( "TiCppExample.xml" );
}

void GenerateExample( std::string filename )
{
	try
	{
		// Create the document
		ticpp::Document doc( filename );

		// Append the declaration
		doc.LinkEndChild( &ticpp::Declaration( "1.0", "UTF-8", "" ) );

		// Create the root element
		ticpp::Element root( "vehicle" );

		// Create type comment
		root.LinkEndChild( &ticpp::Comment( "Types of Vehicles" ) );

		// Create type element
		ticpp::Element type1( "type" );
		type1.SetAttribute( "make", "buick" );
		type1.SetAttribute( "model", "regal" );
		type1.SetAttribute( "year", "1998" );

		// Create type children elements
		ticpp::Element axles1( "axels" );
		axles1.SetText( 2 );
		type1.LinkEndChild( &axles1 );

		ticpp::Element wheels1( "wheels1" );
		wheels1.SetText( 4 );
		type1.LinkEndChild( &wheels1 );

		ticpp::Element color1( "color1" );
		color1.SetText( "blue" );
		type1.LinkEndChild( &color1 );

		type1.SetText( "car" );

		root.LinkEndChild( &type1 );

		// Create type element
		ticpp::Element type2( "type" );
		type2.SetAttribute( "make", "ford" );
		type2.SetAttribute( "model", "F350" );
		type2.SetAttribute( "year", "2000" );

		// Create type children elements
		ticpp::Element axles2( "axels" );
		axles2.SetText( 2 );
		type2.LinkEndChild( &axles2 );

		ticpp::Element wheels2( "wheels2" );
		wheels2.SetText( 6 );
		type2.LinkEndChild( &wheels2 );

		ticpp::Element color2( "color" );
		color2.SetText( "black" );
		type2.LinkEndChild( &color2 );

		type2.SetText( "truck" );

		root.LinkEndChild( &type2 );

		// Create type3 element
		ticpp::Element type3( "type" );
		type3.SetAttribute( "make", "harley-davidson" );
		type3.SetAttribute( "model", "sportster" );
		type3.SetAttribute( "year", "2007" );

		// Create type3 children elements
		ticpp::Element axles3( "axels" );
		axles3.SetText( 2 );
		type3.LinkEndChild( &axles3 );

		ticpp::Element wheels3( "wheels" );
		wheels3.SetText( 2 );
		type3.LinkEndChild( &wheels3 );

		ticpp::Element color3( "color" );
		color3.SetText( "silver" );
		type3.LinkEndChild( &color3 );

		type3.SetText( "motorcycle" );

		root.LinkEndChild( &type3 );

		doc.LinkEndChild( &root );

		doc.SaveFile();
	}
	catch( ticpp::Exception& ex )
	{
		std::cout << "Error: " << ex.m_details;
	}
}
