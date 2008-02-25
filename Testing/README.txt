To build any of the examples:
1. Download Tinyxml from www.sourceforge.net/projects/tinyxml
   Note: The examples were tested using TinyXML 2.3.4
2. Expand the Tinyxml zip file
3. Copy the "tinyxml" directory to the ccl_<version>/examples directory
4. The resulting directory tree should look like the following:
   ccl_<version>
   |- ccl_dll
   |- ccl_lib
   |- examples
   |  |- CigiDummyIG
   |  |- CigiMiniHost
   |  |- CigiTestHost
   |  |- CigiTestIG
   |  |- tinyxml
   |- include
   |- source



For Windows:
1. Open Visual Studio
2. Select Open Workspace (V6) or Open Project (V7)
3. Go to the ccl_<version>\ccl_lib directory.
4. Select ccl_lib.dsw
5. Select Build->Set Active Configuration
6. Select  one of the following:
   a. ccl_lib - Win32 libDebugMT_DLL
   b. ccl_lib - Win32 libReleaseMT_DLL
7. Build the CCL library.
8. Close the workspace or solution.
9. Select Open Workspace (V6) or Open Project (V7)
10. Go to the ccl_<version>\examples\tinyxml directory.
11. Select tinyxml.dsw
12. Select Build->Set Active Configuration
13. Select one of the following:
   a. tinyxmlStl - Win32 Debug
   b. tinyxmlStl - Win32 Release
14. Select Project -> Settings
15. Select "C/C++" tab.
16. Select "Code Generation" in the pulldown.
17. In the "Use run-time library" box change to one of the following:
   a. Debug Multithreaded DLL
   b. Multithreaded DLL
18. Build tinyxml.
19. Close the workspace or solution
20. Select Open Workspace (V6) or Open Project (V7)
21. Go to one of the example project directorys.
22. Select the .dsw file
23. Select Build->Set Active Configuration
24. Select one of the following:
   a. <example> - Win32 Debug
   b. <example> - Win32 Release
25. Build the example project.
26. Close the workspace or solution



For Linux:
1. Go to the "ccl_<version>" directory
2. make configure executable
3. Type the following:
   a. ./configure
   b. make
4. change to root user.
5. Type the following:
   a. make install
6. Exit root user.
7. Go to the "ccl_<version>\examples\tinyxml" directory.
8. Edit "Makefile"
9. Change the following:
   a. From:

# DEBUG can be set to YES to include debugging info, or NO otherwise
DEBUG          := NO

   b. To:

# DEBUG can be set to YES to include debugging info, or NO otherwise
DEBUG          := YES

   c. From:

# TINYXML_USE_STL can be used to turn on STL support. NO, then STL
# will not be used. YES will include the STL files.
TINYXML_USE_STL := NO

   d. To:

# TINYXML_USE_STL can be used to turn on STL support. NO, then STL
# will not be used. YES will include the STL files.
TINYXML_USE_STL := YES

   e. From:

#**********************************************************
# Output
#**********************************************************

${OUTPUT}: ${OBJS}
	${LD} -o $@ ${LDFLAGS} ${OBJS} ${LIBS} ${EXTRA_LIBS}

   f. To:

#**********************************************************
# Output
#**********************************************************

${OUTPUT}: ${OBJS}
	${LD} -o $@ ${LDFLAGS} ${OBJS} ${LIBS} ${EXTRA_LIBS}
	ar rc TinyXML.a tinyxml.o tinystr.o tinyxmlerror.o tinyxmlparser.o
	ranlib TinyXML.a


10. Type the following:
   a. make
11. Go to the example project directory.
12. Type the following:
   a. make



You can edit the configuration/definition file ".def".

Make sure a copy of this file is in the same directory
as the executable before starting the program.

You can start the program by going to the directory
containing the example executable and typing the name
of the example for windows or "./<name of the example>" for Linux.


