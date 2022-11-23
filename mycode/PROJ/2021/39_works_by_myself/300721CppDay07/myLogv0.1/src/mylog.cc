#include "../include/mylog.hh"

#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Priority.hh>

#include <pthread.h>

#include <iostream>

using std::cout;
using std::endl;

using std::string;

using namespace log4cpp;

MyLogger* MyLogger::_pMylog = nullptr;
/* MyLogger::AutoRelease MyLogger::_auto; */

MyLogger* MyLogger::getInstance(string logName){
    if(!_pMylog){
        _pMylog = new MyLogger(logName);//都可以不传参
    }
    return _pMylog;
}

void MyLogger::rmInstance(){
    if(_pMylog){
        delete _pMylog;
        _pMylog = nullptr;
    }
}
/* MyLogger::AutoRelease::~AutoRelease(){ */
/*     if(_pMylog){ */
/*         delete _pMylog; */
/*         _pMylog = nullptr; */
/*     } */
/* } */

MyLogger::MyLogger(string logName)
: _root(Category::getRoot().getInstance("myCat")){
    cout << "MyLogger()" << endl;
    PatternLayout* ppl1 = new PatternLayout();
    ppl1->setConversionPattern(" %d %c [%p] %m %n");

    PatternLayout* ppl2 = new PatternLayout();
    ppl2->setConversionPattern(" %d %c [%p] %m %n");

    OstreamAppender* pos = new OstreamAppender("OstreamAppender", &cout);
    pos->setLayout(ppl1);

    RollingFileAppender* prfa = new RollingFileAppender("OstreamAppender", logName, 3*1024, 3);
    prfa->setLayout(ppl2);

    _root.addAppender(pos);
    _root.addAppender(prfa);
    _root.setPriority(Priority::DEBUG);
}

MyLogger::~MyLogger(){
    cout << "~MyLogger()" << endl;
    Category::shutdown();//段错误
}

void MyLogger::warn(const char *msg){
    _root.warn(msg);
}
void MyLogger::error(const char *msg){
    _root.error(msg);
}
void MyLogger::debug(const char *msg){
    _root.debug(msg);
}
void MyLogger::info(const char *msg){
    _root.info(msg);
}