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
}

FilePersistence::~FilePersistence()
{
    try {
        flush();
    }
    catch(std::exception& e){
        std::cerr << e.what();
    }

}

void FilePersistence::send(TrackingEvent* nEvent) {
    mEvents_.push(nEvent);
}

void FilePersistence::flush() {
    if (!mEvents_.empty()) {
        std::ofstream mFile_;

        try {
            for (auto it = 0; it < mEvents_.size(); ++it) {
                {
                    auto& ev = mEvents_.front();
                    mEvents_.pop();


                    //add the event
                    mSerializer_->serialize(ev);


                }

                if (mFileName_.empty()) {
                    mFileName_ = /*"data/" + */TrackerManager()->getIDSession() + mSerializer_->getExtension();
                }

                mFile_.open(mFileName_, std::ofstream::out | std::ofstream::app);
                if (mFile_.fail()) {
                    std::cout << mFileName_ << std::endl;
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
}

void FilePersistence::run()
{
    try {
        auto prevFlushTime = std::clock();
        prevFlushTime /= CLOCKS_PER_SEC;

        while (Tracker::isRunning()) {
            auto currTime = std::clock();
            currTime /= CLOCKS_PER_SEC;
            if (currTime - prevFlushTime >= mTimer_) {
                flush();
                prevFlushTime = currTime;
            }
        }

    }
    catch(std::exception& e){
        std::cerr << e.what();
    }
}
