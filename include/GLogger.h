//
// Copyright (c) 2019. All rights reserved.
// Created by Jin.Ma on Jun,20 2019.
// This file should be used C++11 or above, and using google glog.
//

#ifndef INCLUDE_GLOGGER_H_
#define INCLUDE_GLOGGER_H_

// You need add this macro when using static lib.
#define GOOGLE_GLOG_DLL_DECL

// You need add this macro when including the header <Windows.h> in windows OS.
#define GLOG_NO_ABBREVIATED_SEVERITIES

#include "./logging.h"

#include <string>

class CGLogger {
public:
  explicit CGLogger(const char *argv0, const std::string &logger_path = "./");
  ~CGLogger();

  static std::string GetCurrentAppPath(const char *argv0);

  const std::string &GetLoggerPath(void) const;
  const std::string &GetAppDir(void) const;

private:
  CGLogger(const CGLogger &) = delete;
  CGLogger &operator=(const CGLogger &) = delete;
  CGLogger(CGLogger &&) = delete;
  CGLogger &operator=(CGLogger &&) = delete;

private:
  std::string m_logger_path_;
  std::string m_app_dir_;
};

#endif // INCLUDE_GLOGGER_H_
