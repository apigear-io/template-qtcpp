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
#include "logger.h"
#include <iostream>



namespace ApiGear {
namespace Utilities {

// static logging functions
static WriteLogFuncStdString logFunc = getDefaultLogStdStringFunc(LogLevel::Warning);
static WriteLogFuncQString logFuncQString = getDefaultQStringLogFunc(LogLevel::Warning);
static WriteLogFuncCharPtr logFuncChar = getDefaultCharLogFunc(LogLevel::Warning);

// Constant text messages to add to log.
static const std::string levelTextDebug = "[debug  ] ";
static const std::string levelTextError = "[error  ] ";
static const std::string levelTextWarning = "[warning] ";
static const std::string levelTextInfo = "[info   ] ";


void emitLog(LogLevel level, const std::string& msg) {
    if (logFunc) {
        logFunc(level, msg);
    }
}

void setLogger(WriteLogFuncStdString func) {
    logFunc = func;
}

void emitLog(LogLevel level, const QString& msg) {
    if (logFuncQString) {
        logFuncQString(level, msg);
    }
}

void setLogger(WriteLogFuncQString func) {
    logFuncQString = func;
}

void emitLog(LogLevel level, const char* msg) {
    if (logFuncChar) {
        logFuncChar(level, msg);
    }
}

void setLogger(WriteLogFuncCharPtr func) {
    logFuncChar = func;
}

WriteLogFuncStdString getDefaultLogStdStringFunc(LogLevel minimumLevel) {
    return [minimumLevel](LogLevel level, const std::string& msg)
    {
        if (level < minimumLevel) {
            return;
        }

        switch (level)
        {
        case LogLevel::Debug:
            std::clog << levelTextDebug << msg << std::endl;
            break;
        case LogLevel::Error:
            std::cerr << levelTextError << msg << std::endl;
            break;
        case LogLevel::Warning:
            std::cerr << levelTextWarning << msg << std::endl;
            break;
        case LogLevel::Info:
            std::cout << levelTextInfo << msg << std::endl;
            break;
        default:
            break;
        }
    };
}

WriteLogFuncQString getDefaultQStringLogFunc(LogLevel minimumLevel) {
    return [minimumLevel](LogLevel level, const QString& msg)
    {
        if (level < minimumLevel) {
            return;
        }

        switch (level)
        {
        case LogLevel::Debug:
            std::clog << levelTextDebug << msg.toStdString() << std::endl;
            break;
        case LogLevel::Error:
            std::cerr << levelTextError << msg.toStdString() << std::endl;
            break;
        case LogLevel::Warning:
            std::cerr << levelTextWarning << msg.toStdString() << std::endl;
            break;
        case LogLevel::Info:
            std::cout << levelTextInfo << msg.toStdString() << std::endl;
            break;
        default:
            break;
        }
    };
}

WriteLogFuncCharPtr getDefaultCharLogFunc(LogLevel minimumLevel) {
    return [minimumLevel](LogLevel level, const char* msg)
    {
        if (level < minimumLevel) {
            return;
        }

        switch (level)
        {
        case LogLevel::Debug:
            std::clog << levelTextDebug << msg << std::endl;
            break;
        case LogLevel::Error:
            std::cerr << levelTextError << msg << std::endl;
            break;
        case LogLevel::Warning:
            std::cerr << levelTextWarning << msg << std::endl;
            break;
        case LogLevel::Info:
            std::cout << levelTextInfo << msg << std::endl;
            break;
        default:
            break;
        }
    };
}


}} // ApiGear::Utilities
