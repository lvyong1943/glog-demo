// This file should be used C++11 or above, and using google glog.
// Created by Martin on 6/20/2019

#include "GLogger.h"

const static std::string PRE_EXTENSION_NAME = "log_";

CGLogger::CGLogger(const char *argv0, const std::string& log_dir) :
	m_app_dir_(GetCurrentAppPath(argv0)),
	m_logger_path_(log_dir)
{
	//FLAGS_log_dir = m_logger_path_;			 // Set log dir, you can delete this
	FLAGS_colorlogtostderr = true;			 // Set log color
	FLAGS_logbufsecs = 0;					 // Set log output speed(s)
	FLAGS_max_log_size = 1024;				 // Set max log file size, MB
	FLAGS_stop_logging_if_full_disk = true;  // If disk is full

	google::InitGoogleLogging(argv0);
	google::SetLogDestination(google::GLOG_INFO, m_logger_path_.c_str());
	google::SetStderrLogging(google::GLOG_INFO);
	google::SetLogFilenameExtension(PRE_EXTENSION_NAME.c_str());
	google::SetLogSymlink(google::GLOG_INFO, "");
	google::FlushLogFiles(google::GLOG_ERROR);
	google::FlushLogFilesUnsafe(google::GLOG_FATAL);
}

CGLogger::~CGLogger()
{
	google::ShutdownGoogleLogging();
}

std::string CGLogger::GetCurrentAppPath(const char *argv0)
{
	std::string fullPath(argv0);
	int pos = fullPath.find_last_of('/');
	if (pos == std::string::npos) {
		pos = fullPath.find_last_of('\\');
	}
	if (pos == std::string::npos) {
		fullPath = "./";
	}
	else {
		fullPath = fullPath.substr(0, pos);
	}

	return fullPath;
}

const std::string & CGLogger::GetLoggerPath(void) const
{
	return m_logger_path_;
}

const std::string & CGLogger::GetAppDir(void) const
{
	return m_app_dir_;
}

