// glogDemo.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <memory>

#include "GLogger.h"

using namespace std;

std::string GetLoggerPath(const char *argv0);

int main(int argc, char **argv)
{
	// Start google log system:
	std::shared_ptr<CGLogger> logger = std::make_shared<CGLogger>(argv[0], GetLoggerPath(argv[0]));
	
	// GLogger output test:
	char str[20] = "hello log!";
	LOG(INFO) << str;
	LOG(INFO) << "info test" << "hello log!";
	LOG(WARNING) << "warning test";
	LOG(ERROR) << "error test";
	LOG(FATAL) << "fatal test"; // See Document

	std::system("pause");
    return 0;
}

std::string GetLoggerPath(const char *argv0)
{
	std::string path = CGLogger::GetCurrentAppPath(argv0);
	if (path.find('\\') != std::string::npos) {
		path.append("\\logs\\");
	}
	else {
		path.append("/logs/");
	}
	return path;
}

