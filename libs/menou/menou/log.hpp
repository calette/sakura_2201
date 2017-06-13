﻿// -*- mode:c++; coding:utf-8-ws -*-
//====================================================================
//! @file  log.hpp
//! @brief ログ
//!
//! @author (C) 2017, takamo.
//====================================================================
#ifndef MENOU_LOG_HPP
#define MENOU_LOG_HPP

#include <stdio.h>
#include <stdarg.h>
#include <tchar.h>

//template<typename First, typename... Rest>
//int isum(const First& first, const Rest&... rest)
//{
//  return first + isum(rest...);
//}

namespace mn {

//------------------------------------------------------------------
//! 出力
//------------------------------------------------------------------
MENOU_INLINE void log(const TCHAR *fmt, ...) {
  TCHAR buf[1024];

  va_list arg;
  va_start(arg, fmt);
  _vstprintf_s(buf, 1024, fmt, arg);
  va_end(arg);

#ifdef _WIN32
  OutputDebugStringW(buf);
#else
  printf(buf);
#endif
}

//------------------------------------------------------------------
//! 出力 (改行つき)
//------------------------------------------------------------------
MENOU_INLINE void logln(const TCHAR *fmt, ...) {
  TCHAR buf[1024];

  va_list arg;
  va_start(arg, fmt);
  _vstprintf_s(buf, 1024, fmt, arg);
  va_end(arg);

  _tcscat_s(buf, _T("\n"));

#ifdef _WIN32
  OutputDebugStringW(buf);
#else
  printf(buf);
#endif
}

} /* namespace of mn */

#endif /* MENOU_LOG_HPP */
