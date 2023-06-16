/*
* MIT License
*
* Copyright (c) 2021 ApiGear
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#pragma once

#include <functional>
#include <string>
#include <QString>

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define APIGEAR_LOGGER __attribute__ ((dllexport))
#else
#define APIGEAR_LOGGER __declspec(dllexport)
#endif
#else
#if __GNUC__ >= 4
#define APIGEAR_LOGGER __attribute__ ((visibility ("default")))
#else
#define APIGEAR_LOGGER
#endif
#endif

/**
* File defines functionality for logging used in apigear implementation.
* To avoid conversions, loggers are defined for three types of message used in the project:
* const std::string&
* const QString&
* const char*
* Have that in mind if you'd like to set your own loggers instead of default one (logging to std::cout/cerr),
* you may want to change all three of them. See setLogger functions.
* For convenience of use below macros are defined.
* Alternatively we recommend using logInfo, logDebug, logWarning, logError functions.
*/

#define AG_LOG_INFO(str) ApiGear::Utilities::logInfo(str)
#define AG_LOG_DEBUG(str) ApiGear::Utilities::logDebug(str)
#define AG_LOG_WARNING(str) ApiGear::Utilities::logWarning(str)
#define AG_LOG_ERROR(str) ApiGear::Utilities::logError(str)

namespace ApiGear { namespace Utilities {

/**
* Logging levels for logs across the application.
*/
enum APIGEAR_LOGGER LogLevel {
    Debug = 0,      // Useful for debugging during development
    Info = 1,       // Some event happened, usually not important
    Warning = 2,    // Important to know
    Error = 3       // Must know - something is wrong
};

/**
* Used to log messages of type const std::string&.
* @param level specify the LogLevel
* @param msg content to be logged
*/
void APIGEAR_LOGGER emitLog(LogLevel level, const std::string& msg);

/**
* Used to log messages of type const QString&.
* @param level specify the LogLevel
* @param msg content to be logged
*/
void APIGEAR_LOGGER emitLog(LogLevel level, const QString& msg);

/**
* Used to log messages of type const char*.
* @param level specify the LogLevel
* @param msg content to be logged
*/
void APIGEAR_LOGGER emitLog(LogLevel level, const char* msg);


/**
* Use to log on LogLevel::Info
* @param msg to be logged
* msgType should be one of: std::string&, QString&, char*.
* For other types user must define own emitLog function.
*/
template<typename msgType>
void APIGEAR_LOGGER logInfo(const msgType msg)
{
    emitLog(LogLevel::Info, msg);
}

/**
* Use to log on LogLevel::Debug
* @param msg to be logged
* msgType should be one of: std::string&, QString&, char*.
* For other types user must define own emitLog function.
*/
template<typename msgType>
void APIGEAR_LOGGER logDebug(const msgType msg)
{
    emitLog(LogLevel::Debug, msg);
}

/**
* Use to log on LogLevel::Warning
* @param msg to be logged
* msgType should be one of: std::string&, QString&, char*.
* For other types user must define own emitLog function.
*/
template<typename msgType>
void APIGEAR_LOGGER logWarning(const msgType msg)
{
    emitLog(LogLevel::Warning, msg);
}

/*
* Use to log on LogLevel::Error
* @param msg to be logged
* msgType should be one of: std::string&, QString&, char*.
* For other types user must define own emitLog function.
*/
template<typename msgType>
void APIGEAR_LOGGER logError(const msgType msg)
{
    emitLog(LogLevel::Error, msg);
}


/** A type of function to log messages of const std::string& type. */
using WriteLogFuncStdString = std::function<void(LogLevel level, const std::string& msg)>;
/** A type of function to log messages of const QString& type. */
using WriteLogFuncQString = std::function<void(LogLevel level, const QString& msg)>;
/** A type of function to log of const char* type. */
using WriteLogFuncCharPtr = std::function<void(LogLevel level, const char* msg)>;

/**
* Use to set logger function for messages of const std::string& type.
* @param func a functions which implements the WriteLogFuncStdString signature
*/
void APIGEAR_LOGGER setLogger(WriteLogFuncStdString func);
/**
* Use to set logger function for messages of const QString& type.
* @param func a functions which implements the WriteLogFuncQString signature
*/
void APIGEAR_LOGGER setLogger(WriteLogFuncQString func);
/**
* Use to set logger function for messages of const char* type.
* @param func a functions which implements the WriteLogFuncCharPtr signature
*/
void APIGEAR_LOGGER setLogger(WriteLogFuncCharPtr func);

/**
* A getter the default logger for const std::string& messages.
* @param minimumLevel A log level below which all the logging is skipped.
* @return A default WriteLogFuncStdString logger function. 
* Logs info and debug level to std::cout (if log level allows).
* Logs warnings and errors to std::error (if log level allows).
*/
WriteLogFuncStdString APIGEAR_LOGGER getDefaultLogStdStringFunc(LogLevel minimumLevel);

/**
* A getter the default logger for const QString& messages.
* @param minimumLevel A log level below which all the logging is skipped.
* @return A default WriteLogFuncQString logger function.
* Logs info and debug level to std::cout (if log level allows).
* Logs warnings and errors to std::error (if log level allows).
*/
WriteLogFuncQString APIGEAR_LOGGER getDefaultQStringLogFunc(LogLevel minimumLevel);

/**
* A getter the default logger for const char* messages.
* @param minimumLevel A log level below which all the logging is skipped.
* @return A default WriteLogFuncCharPtr logger function.
* Logs info and debug level to std::cout (if log level allows).
* Logs warnings and errors to std::error (if log level allows).
*/
WriteLogFuncCharPtr APIGEAR_LOGGER getDefaultCharLogFunc(LogLevel minimumLevel);


} } // ApiGear::Utilities

