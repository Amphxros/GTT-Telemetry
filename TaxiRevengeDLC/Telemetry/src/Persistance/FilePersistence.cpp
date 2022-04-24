#include "../../include/Persistance/FilePersistence.h"
#include "../../include/TrackingEvent.h"

#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>


FilePersistence::FilePersistence(uint64_t time):
    mTimer_(time)
{
    std::ofstream file;
    startThread();
}

FilePersistence::~FilePersistence()
{
    mFlushThread_->join();
    delete mFlushThread_;
    try {
        flush();
    }
    catch(std::exception& e){
        std::cerr << e.what();
    }

}

void FilePersistence::send(TrackingEvent* nEvent) {
    std::lock_guard<std::mutex> lock(mEventMutex_);
    mEvents_.push(nEvent);
}

void FilePersistence::flush() {

}

void FilePersistence::run()
{
    try {

    }
    catch(std::exception& e){
        std::cerr << e.what();
    }
}

void FilePersistence::startThread()
{
    mFlushThread_ = new std::thread([&]() { run(); });
}
