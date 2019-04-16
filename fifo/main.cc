#include <Poco/Exception.h>
#include <Poco/Format.h>
#include <Poco/Logger.h>
#include <Poco/Stopwatch.h>
#include <Poco/Util/Application.h>
#include <Poco/Util/LayeredConfiguration.h>

#include <iostream>
#include <memory>
#include <sstream>

class MyApp : public Poco::Util::Application {
   private:
    void initialize(Poco::Util::Application &self) {
        loadConfiguration();

        Poco::Util::Application::initialize(self);
    }

    void uninitialize() { Poco::Util::Application::uninitialize(); }

    int main(const std::vector<std::string> &arguments) {
        Poco::Logger &logger = Application::instance().logger();
        try {
            Poco::Stopwatch stop_watch;
            stop_watch.start();

            logger.trace("hello algorithm");

            stop_watch.stop();
            logger.trace("%ld", stop_watch.elapsed());
        } catch (Poco::Exception &ex) {
            logger.error(ex.what());
        }

        return EXIT_OK;
    }
};

POCO_APP_MAIN(MyApp)
