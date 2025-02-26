#include <cstdarg>
#include <cstdio>
#include <ctime>
#include <iomanip>

// #define LOG_INFO(format, ...) std::fprintf(stdout, "[INFO] " format "\n" __VA_OPT__(, )
// __VA_ARGS__)

// #define LOG_WARN(format, ...) std::fprintf(stderr, "[WARN] " format "\n" __VA_OPT__(, )
// __VA_ARGS__)

// #define LOG_ERROR(format, ...) \
//     std::fprintf(stderr, "[ERROR] " format "\n" __VA_OPT__(, ) __VA_ARGS__)

namespace component::log {

enum class LogLevel { LOG_DEBUG = 0, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL };
class Logger {
public:
    Logger(const Logger&)            = default;
    Logger(Logger&&)                 = default;
    Logger& operator=(const Logger&) = delete;
    Logger& operator=(Logger&&)      = delete;

    Logger(const std::string& logger)
        : logger_(logger)
        , log_level_(LogLevel::LOG_INFO) {}

    void set_log_level(LogLevel level) { log_level_ = level; }

    void log_message(const std::string message, ...) {

        va_list args;
        va_start(args, message);

        std::string format_message =
            log_time() + "[" + logger_ + "]" + log_level(log_level_) + message + "\n";

        if (log_level_ <= LogLevel::LOG_INFO) {
            std::vfprintf(stdout, format_message.c_str(), args);
        } else {
            std::vfprintf(stderr, format_message.c_str(), args);
        }

        va_end(args);
    }

private:
    const std::string& logger_;
    LogLevel log_level_;

    std::string log_time() {
        std::time_t timestamp = std::time(nullptr);
        std::tm* localtime_   = std::localtime(&timestamp);
        std::ostringstream oss;
        oss << std::put_time(localtime_, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }

    std::string log_level(LogLevel log_level) {
        switch (log_level) {
        case LogLevel::LOG_DEBUG: return "[DEBUG]"; break;
        case LogLevel::LOG_INFO: return "[INFO]"; break;
        case LogLevel::LOG_WARN: return "[WARN]"; break;
        case LogLevel::LOG_ERROR: return "[ERROR]"; break;
        case LogLevel::LOG_FATAL: return "[FATAL]"; break;
        default: return "UNKNOWN"; break;
        }
    }
};
} // namespace component::log