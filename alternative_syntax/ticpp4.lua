--*****************************************************************************
--*	Author:		RJP Computing <rjpcomputing@gmail.com>
--*	Date:		01/21/2008
--*	Version:	1.02
--* Copyright (C) 2009 RJP Computing
--*
--*	Permission is hereby granted, free of charge, to any person obtaining a copy of
--*	this software and associated documentation files (the "Software"), to deal in
--*	the Software without restriction, including without limitation the rights to
--* use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
--*	the Software, and to permit persons to whom the Software is furnished to do so,
--*	subject to the following conditions:
--*
--* The above copyright notice and this permission notice shall be included in all
--*	copies or substantial portions of the Software.
--*
--*	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
--* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
--*	FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
--*	COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
--*	IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
--* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
--*
--*	NOTES:
--*		- use the '/' slash for all paths.
--*****************************************************************************

--******* Initial Setup ************
--*	Most of the setting are set here.
--**********************************

-- Set the name of your package.
project "TiCPP"
	-- Set this if you want a different name for your target than the projects's name.
	outName						= "ticpp"
	-- Set the files to include/exclude.
	files						{ "*.cpp", "*.h" }
	excludes					{ "xmltest.cpp" }
	-- Setup the output directory options.
	--		Note: Use 'libdir' for "lib" kind only.
	--bindir					"../lib"
	--libdir					"../lib"
	-- Set the defines.
	defines						{ "TIXML_USE_TICPP" }

--------------------------- DO NOT EDIT BELOW ----------------------------------
	-- Common setup
	language					"C++"
	flags						{ "ExtraWarnings" }
	--******* GENAERAL SETUP **********
	--*	Settings that are not dependant
	--*	on the operating system.
	--*********************************

-- OPTIONS ---------------------------------------------------------------------
--
	--
	-- Package options
	--
	newoption
	{
		trigger = "ticpp-shared",
		description = "Build TinyXML++ as a dll"
	}

	--
	-- TinyXML++ dll
	--
	if _OPTIONS["ticpp-shared"] then
		kind 					"SharedLib"
	else
		kind 					"StaticLib"
	end

	--
	-- Dynamic Runtime
	--
	if not _OPTIONS["dynamic-runtime"] then
		flags					{ "StaticRuntime" }
	end

-- CONFIGURATIONS -------------------------------------------------------------
--
	--
	-- Unicode
	--
	configuration "unicode"
		flags					{ "Unicode" }
		defines					{ "UNICODE", "_UNICODE" }

	--
	-- GCC compilers
	--
	configuration { "code*", "gmake" }
		objdir					".obj"
		buildoptions			{ "-O0" }

	--
	-- Visual Studio
	--
	configuration "vs*"
		-- Windows and Visual C++ 2005/2008
		defines					{ "_CRT_SECURE_NO_DEPRECATE" }

	--
	-- Release/Debug
	--
	-- Set the default targetName if none is specified.
	if #outName <= 0 then outName = project().name end
	print( outName )
	print( project().name )
	-- Set the targets.
	configuration "Release"
		targetname				( outName )
		defines					{ "NDEBUG" }
		flags					{ "OptimizeSpeed" }
	configuration "Debug"
		targetname 				( outName.."d" )
		defines					{ "DEBUG", "_DEBUG" }
		flags					{ "Symbols" }

	--
	-- Operating Systems specific
	--
	if configuration "windows" then
		defines					{ "WIN32", "_WINDOWS" }
	else
		excludes				{ "**.rc" }		-- Ignore resource files in Linux.
		buildoptions			{ "-fPIC" }
	end
