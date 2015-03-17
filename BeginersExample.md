# Introduction #

Here is a simple example that shows how to use TinyXML++ to read an xml file in and get at all the contents.

# Details #

XML-file to be parsed:
```
<?xml version="1.0" encoding="UTF-8" ?>
<Fruits>
	<Apple colour="green" price="1.1" amount="10" />
	<Banana colour="yellow" price="1.5" amount="10" />
	<Cherry colour="red" price="2.5" amount="1" />
</Fruits>
```

Approach how to achieve that:
```
#include <iostream>
#include <ticpp.h>

// simple function to parse a xml file
void Parse(const char* pcFilename);

int main()
{
	// whatch out for exceptions
	try
	{
		// parse the xml file with the name fruits.xml
		Parse("fruits.xml");
	}
	catch(ticpp::Exception& ex)
	{
		std::cout << ex.what();
	}

	return -1;
}

void Parse(const char* pcFilename)
{
	// first load the xml file
	ticpp::Document doc(pcFilename);
	doc.LoadFile();

	// parse through all fruit elements
	ticpp::Iterator<ticpp::Element> child;
	for(child = child.begin(doc.FirstChildElement()); child != child.end(); child++)
	{
		// The value of this child identifies the name of this element
		std::string strName;
		std::string strValue;
		child->GetValue(&strName);
		std::cout << "fruit: " << strName << std::endl;
		std::cout << "-------------" << std::endl;

		// now parse through all the attributes of this fruit
		ticpp::Iterator< ticpp::Attribute > attribute;
		for(attribute = attribute.begin(child.Get()); attribute != attribute.end();
attribute++)
		{
			attribute->GetName(&strName);
			attribute->GetValue(&strValue);
			std::cout << strName << ": " << strValue << std::endl;
		}
		std::cout << std::endl;
	}
}
```