// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__A2DAB1DA_472E_45CD_9B62_25CAA8A6F762__INCLUDED_)
#define AFX_STDAFX_H__A2DAB1DA_472E_45CD_9B62_25CAA8A6F762__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <stdio.h>

#include "AllCigi.h"

// Do not use namespace 'std' if compiling under Microsoft Visual Studio 
// version 6 and earlier...

#ifndef _WIN32
    using namespace std;
#elif _MSC_VER > 1300
    using namespace std;
#endif


// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__A2DAB1DA_472E_45CD_9B62_25CAA8A6F762__INCLUDED_)
