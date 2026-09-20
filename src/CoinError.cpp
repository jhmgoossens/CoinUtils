// Copyright (C) 2005, International Business Machines
// Corporation and others.  All Rights Reserved.
// This code is licensed under the terms of the Eclipse Public License (EPL).

#include "CoinError.hpp"

bool COINUTILSLIB_EXPORT CoinError::printErrors_ = false;

/** A function to block the popup windows that windows creates when the code
    crashes */
#ifdef _MSC_VER
#include <windows.h>
#include <stdlib.h>

/// A hook for the CRT debug reporting system to print messages to stderr and abort
/// This is used to avoid the popup windows that windows creates when the code crashes
static int CoinCrtDbgHook(int nReportType, char* szMsg, int* pnRet)
{
    if (nReportType == _CRT_WARN)
    {
        fprintf(stderr, "WARN: %s", szMsg);
    } 
    else if (nReportType == _CRT_ERROR)
    {
        fprintf(stderr, "ERROR: %s", szMsg);
    } 
    else if (nReportType == _CRT_ASSERT)
    {
        fprintf(stderr, "ASSERT: %s", szMsg);
    } 
    else
    {
        fprintf(stderr, "UNKNOWN: %s", szMsg);
	}
    abort();
    return TRUE;
}

COINUTILSLIB_EXPORT
void WindowsErrorPopupBlocker()
{
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);
    _set_abort_behavior(0, _WRITE_ABORT_MSG);
    _CrtSetReportHook2(_CRT_RPTHOOK_INSTALL, CoinCrtDbgHook);
}
#else
COINUTILSLIB_EXPORT
void WindowsErrorPopupBlocker() {}
#endif

/* vi: softtabstop=2 shiftwidth=2 expandtab tabstop=2
*/
