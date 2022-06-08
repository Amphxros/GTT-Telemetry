#include "../../include/Persistance/FilePersistence.h"
#include "../../include/Events/TrackingEvent.h"
#include "../../include/Serialization/ISerializer.h"

#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include "../../include/Tracker.h"
#include "../../include/Serialization/IStream.h"

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
    if (mEvents_.empty()) {
        return;
    }
    std::ofstream mFile_;

    try {
        mEventMutex_.lock();
        for (auto it = 0; it < mEvents_.size(); ++it) {
            {
                auto& ev = mEvents_.front();
                mEvents_.pop();

                mEventMutex_.unlock();
                //add the event

                mEventMutex_.lock();

            }
            mEventMutex_.unlock();

            if (mFileName_.empty()) {
                mFileName_ = "data/" + TrackerManager()->getIDSession() + mSerializer_->getExtension();
            }

            mFile_.open(mFileName_, std::ofstream::out | std::ofstream::app);
            if (mFile_.fail()) {
                throw std::runtime_error("Tracker error: data folder is missing");
            }

            if (!Tracker::isRunning())
                mStream_->close();
            

        }
    }
    catch (std::exception& e) {
        std::cerr << e.what();
    }
}

void FilePersistence::run()
{
    try {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        auto prevFlushTime = std::clock();
        prevFlushTime /= CLOCKS_PER_SEC;

        while (Tracker::isRunning()) {
            auto currTime = std::clock();
            currTime /= CLOCKS_PER_SEC;
            if (currTime - prevFlushTime >= mTimer_) {
                flush();
                prevFlushTime = currTime;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    catch(std::exception& e){
        std::cerr << e.what();
    }
}

void FilePersistence::startThread()
{
    mFlushThread_ = new std::thread([&]() { run(); });
}
