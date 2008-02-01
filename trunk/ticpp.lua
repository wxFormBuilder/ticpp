--*****************************************************************************
--*	Author:		RJP Computing <rjpcomputing@gmail.com>
--*	Date:		01/21/2008
--*	Version:	1.02
--*	
--*	NOTES:
--*		- use the '/' slash for all paths.
--*****************************************************************************

--******* Initial Setup ************
--*	Most of the setting are set here.
--**********************************

-- Set the name of your package.
package.name								= "TiCPP"
-- Set this if you want a different name for your target than the package's name.
local targetName							= "ticpp"
-- Set the kind of package you want to create.
if ( options["ticpp-shared"] ) then
	package.kind							= "dll"
else
	package.kind							= "lib"
end
-- Set the files to include/exclude.
package.files								= { matchfiles( "*.cpp", "*.h" ) }
package.excludes							= { "xmltest.cpp" }
-- Setup the output directory options.
--		Note: Use 'libdir' for "lib" kind only.
package.bindir								= "../lib"
package.libdir								= "../lib"
-- Set the defines.
package.defines								= { "TIXML_USE_TICPP" }

--------------------------- DO NOT EDIT BELOW ----------------------------------

--******* GENAERAL SETUP **********
--*	Settings that are not dependant
--*	on the operating system.
--*********************************
-- Package options
addoption( "ticpp-shared", "Build the library as a dll" )

-- Common setup
package.language							= "c++"

-- Set object output directory.
if ( target == "cb-gcc" or target == "gnu" ) then
	package.objdir							= ".obj"
end

-- Set the default targetName if none is specified.
if ( string.len( targetName ) == 0 ) then
	targetName								= package.name
end

-- Set the targets.
package.config["Release"].target			= targetName
package.config["Debug"].target				= targetName.."d"

-- Set the build options.
if ( options["dynamic-runtime"] ) then
	package.buildflags						= { "extra-warnings" }
	package.config["Release"].buildflags	= { "no-symbols", "optimize-speed" }
else
	package.buildflags						= { "static-runtime", "extra-warnings" }
	package.config["Release"].buildflags	= { "no-symbols", "optimize-speed" }
end
if ( options["unicode"] ) then
	table.insert( package.buildflags, "unicode" )
end
if ( target == "cb-gcc" or target == "gnu" ) then
	table.insert( package.config["Debug"].buildoptions, "-O0" )
end

-- Set the defines.
if ( options["unicode"] ) then
	table.insert( package.defines, { "UNICODE", "_UNICODE" } )
end
table.insert( package.config["Debug"].defines, { "DEBUG", "_DEBUG" } )
table.insert( package.config["Release"].defines, "NDEBUG" )
if ( ( target == "vs2005" ) or ( target == "vs2008" ) ) then
		-- Windows and Visual C++ 2005/2008
	table.insert( package.defines, "_CRT_SECURE_NO_DEPRECATE" )
end

if ( OS == "windows" ) then
--******* WINDOWS SETUP ***********
--*	Settings that are Windows specific.
--*********************************	
	-- Set the Windows defines.
	table.insert( package.defines, { "WIN32", "_WINDOWS" } )
else
--******* LINUX SETUP *************
--*	Settings that are Linux specific.
--*********************************
	-- Ignore resource files in Linux.
	table.insert( package.excludes, matchrecursive( "*.rc" ) )
end

