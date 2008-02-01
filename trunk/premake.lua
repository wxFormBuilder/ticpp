project.name	= "TinyXML++"

project.bindir	= "lib"
project.libdir	= "lib"

-- This is for including other Premake scripts.
dopackage( "ticpp.lua" )

-- Add options here.
addoption( "dynamic-runtime", "Use the dynamicly loadable version of the runtime." )
addoption( "unicode", "Use the Unicode character set" )

