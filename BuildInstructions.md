# Introduction #
'TiCPP' is short for the official name TinyXML++. It is a completely new interface to
TinyXML (http://www.grinninglizard.com/tinyxml/) that uses MANY of the C++
strengths. Templates, exceptions, and much better error handling. It is also fully
documented in doxygen. It is really cool because this version let's you interface tiny the
exact same way as before or you can choose to use the new 'TiCPP' classes. All you need to
do is define `TIXML_USE_TICPP`. It has been tested in VC 6.0, VC 7.0, VC 7.1, VC 8.0,MinGW
gcc 4.4.1+, and in Linux GNU gcc 4+.

TinyXML++ uses Premake as the build system, so you won't find any project files because
you generate them for your specific system. Premake is a build script generator. Premake
supports creatation of build scripts for:
  * MS Visual Studio 6, 2002, 2003, or 2005
  * GNU make (including Cygwin and MinGW)
  * Code::Blocks
  * And more ...

# Build Steps #
  1. Download Premake from http://premake.sf.net/download
  1. Checkout the source for TinyXML++ using Subversion.
> > `svn checkout http://ticpp.googlecode.com/svn/trunk/ ticpp`
  1. Place the Premake executable in the root directory of TiCPP or somewhere in your path.
  1. To create the needed build files navigate to the TinyXML++ directory (ticpp) and type:
    * Code::Blocks Projects and workspace:
> > _Premake v3.x:_ |`premake --target cb-gcc [--unicode] [--ticpp-shared] [--dynamic-runtime]`|
|:-------------------------------------------------------------------------|
> > _Premake v4.x:_   |`premake4 codeblocks [--unicode] [--ticpp-shared] [--dynamic-runtime]`|
    * GNU makefiles:
> > _Premake v3.x:_ |`premake --target gnu [--unicode] [--ticpp-shared] [--dynamic-runtime]`|
> > _Premake v4.x:_   |`premake4 gmake [--unicode] [--ticpp-shared] [--dynamic-runtime]`|
    * Visual Studio 2005 (8.0) **Windows ONLY**
> > _Premake v3.x:_ |`premake --target vs2005 [--unicode] [--ticpp-shared] [--dynamic-runtime]`|
> > _Premake v4.x:_ |`premake4 vs2005 [--unicode] [--ticpp-shared] [--dynamic-runtime]`|
  1. Now use the build system of your choice.
    * For Code::Blocks, use the generated .cbp/.workspace
    * For GNU makefiles type:
> > _Release_ |`make CONFIG=release`|
> > _Debug_ |`make`|
    * For Visual Studio, use the generated .vcproj/.sln.

# Notes #

  * Premake can be found here:

> http://premake.sourceforge.net
  * For GNU makefiles they assume you have properly setup your system to build with gcc or
MinGW.
  * Subversion is a great free cross-platform version control manager. It can be found here:
> http://subversion.tigris.org
  * Code::Blocks is a free cross-platform IDE and it can be found here:
> http://codeblocks.org