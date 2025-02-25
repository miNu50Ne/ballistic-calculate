#include <cstdio>
#include <ctime>
#include <iomanip>

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

    template <typename... Args>
    void log_message(LogLevel level, const chat& format) {}

    void debug() {}
    void info() {}
    void warn() {}
    void error() {}
    void fatal() {}

private:
    const std::string& logger_;
    LogLevel log_level_;

    // 获取当前时间戳
    std::string getCurrentTime() {
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