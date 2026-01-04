// Copyright (C) 2005, International Business Machines
// Corporation and others.  All Rights Reserved.
// This code is licensed under the terms of the Eclipse Public License (EPL).

#include "CoinError.hpp"

bool COINUTILSLIB_EXPORT CoinError::printErrors_ = false;

/** A function to block the popup windows that windows creates when the code
    crashes */
#ifdef _MSC_VER
#include <windows.h>
#include <crtdbg.h>
#include <stdlib.h>
COINUTILSLIB_EXPORT
void WindowsErrorPopupBlocker()
{
    printf("WindowsErrorPopupBlocker called printf");
    std::cout << "WindowsErrorPopupBlocker called" << std::endl;
  SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);
  _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
  _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
    _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
}
#else
COINUTILSLIB_EXPORT
void WindowsErrorPopupBlocker() 
{
    printf("Ignore WindowsErrorPopupBlocker called printf");
    std::cout << "Ignore WindowsErrorPopupBlocker called" << std::endl;
}

#endif

/* vi: softtabstop=2 shiftwidth=2 expandtab tabstop=2
*/
