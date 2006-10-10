package.name = "TiCPP"
package.libdir = "../lib"
package.kind = "lib"
package.language = "c++"
package.files = { matchfiles( "*.h", "*.cpp" ) }
package.excludes = { "xmltest.cpp" }
-- Change the default lib extention to .a instead of .lib
--package.targetextension = "a"
-- Set object output directory.
package.config["Debug"].objdir = ".objsd"
package.config["Debug (Unicode)"].objdir = ".objsud"
package.config["Release"].objdir = ".objs"
package.config["Release (Unicode)"].objdir = ".objsu"
-- Set the targets.
package.config["Debug"].target = "ticppd"
package.config["Debug (Unicode)"].target = "ticppd"
package.config["Release"].target = "ticpp"
package.config["Release (Unicode)"].target = "ticpp"

-- Set the build options for the Unicode build Targets.
package.buildflags = { "extra-warnings" }
package.config["Debug (Unicode)"].buildflags = { "unicode" }
package.config["Release"].buildflags = { "no-symbols", "optimize-speed" }
package.config["Release (Unicode)"].buildflags = { "unicode", "no-symbols", "optimize-speed" }

-- Set include paths
--package.includepaths = { "../tinyxml" }
-- Set defines.
package.config["Debug"].defines = 
{
	"DEBUG",
	"WIN32",
	"_WINDOWS",
	"HAVE_W32API_H",
	"TIXML_USE_TICPP"
}
package.config["Debug (Unicode)"].defines = 
{
	"DEBUG",
	"WIN32",
	"_WINDOWS",
	"HAVE_W32API_H",
	"TIXML_USE_TICPP",
	"UNICODE",
	"_UNICODE"
}
package.config["Release"].defines = 
{
	"NDEBUG",
	"WIN32",
	"_WINDOWS",
	"HAVE_W32API_H",
	"TIXML_USE_TICPP"
}
package.config["Release (Unicode)"].defines = 
{
	"NDEBUG",
	"WIN32",
	"_WINDOWS",
	"HAVE_W32API_H",
	"TIXML_USE_TICPP",
	"UNICODE",
	"_UNICODE"
}
