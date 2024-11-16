#ifndef ECHOTRAIL_HH
#define ECHOTRAIL_HH

#include <iostream>
#include <string>
#include <ctime>


// Comment out line to disable all logging
#define LOGGING_ENABLED true

enum class LogLevel {
    None,       // For disabling all logging
    Info,
    Warning,
    Error,
    Debug
};

struct LogConfig {
    bool consoleEnabled = true;    // Whether to log to console
    LogLevel minLogLevel = LogLevel::Info;  // Minimum level for logging
};

class Logger {
public:
    Logger() : config({}), filterEnabled(true) {}
    Logger(const LogConfig& config) : config(config), filterEnabled(true) {}

    void setFilterEnabled(bool enable) {
        filterEnabled = enable;
    }

    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& message) {
        logInternal(LogLevel::Info, message);
    }

    void log(LogLevel level, const std::string& message) {
        logInternal(level, message);
    }

private:
    LogConfig config;
    bool filterEnabled;

    void logInternal(LogLevel level, const std::string& message) {
#if defined(LOGGING_ENABLED)  // Check if logging is enabled
        if (LOGGING_ENABLED) {  
            if (!filterEnabled || level >= config.minLogLevel) {
                std::string formattedMessage = formatMessage(level, message);
                if (config.consoleEnabled) {
                    std::cout << formattedMessage << std::endl;
                }
            }
        }
#endif
    }

    std::string formatMessage(LogLevel level, const std::string& message) {
        std::string levelStr;
        switch (level) {
            case LogLevel::Info: levelStr = "INFO"; break;
            case LogLevel::Warning: levelStr = "WARNING"; break;
            case LogLevel::Error: levelStr = "ERROR"; break;
            case LogLevel::Debug: levelStr = "DEBUG"; break;
            default: levelStr = "LOG"; break;
        }

        std::time_t now = std::time(nullptr);
        char timeBuffer[20];
        std::strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

        return "[" + std::string(timeBuffer) + "] [" + levelStr + "] " + message;
    }
};

// Macros for convenience
#if defined(LOGGING_ENABLED) && LOGGING_ENABLED
    #define LOG(...) Logger::getInstance().log(__VA_ARGS__)
#else
    #define LOG(...) do {} while (0)
#endif

#endif // ECHOTRAIL_HH
