//
// Copyright (c) 2019. All rights reserved.
// Created by Jin.Ma on Jun,20 2019.
// This file should be used C++11 or above, and using google glog.
//

#include <iostream>
#include <memory>

#include "GLogger.h"

std::string GetLoggerPath(const char *argv0);

int main(int argc, char **argv) {
  // Start google log system:
  std::shared_ptr<CGLogger> logger = std::make_shared<CGLogger>(argv[0]);

  // GLogger output test:
  char str[20] = "hello log!";
  LOG(INFO) << str;
  LOG(INFO) << "info test"
            << "hello log!";
  LOG(WARNING) << "warning test";
  LOG(ERROR) << "error test";
  // LOG(FATAL) << "fatal test"; // FATAL: may stop the app

#ifdef WIN32
  std::system("pause");
#endif // WIN32

  return 0;
}

std::string GetLoggerPath(const char *argv0) {
  std::string path = CGLogger::GetCurrentAppPath(argv0);
  if (path.find('\\') != std::string::npos) {
    path.append("\\logs\\");
  } else {
    path.append("/logs/");
  }
  return path;
}
