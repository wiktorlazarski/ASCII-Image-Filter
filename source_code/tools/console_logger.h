#pragma once
#include <string>
#include <iostream>
#include <mutex>

class ConsoleLogger 
{
public:
	static ConsoleLogger& get_instance() {
		static ConsoleLogger instance;
		return instance;
	}

	void log(const std::string& msg) {
		std::lock_guard<std::mutex> lock(m_mutex);
		std::cout << msg;
	}

private:
	std::mutex m_mutex;

	//constructors
	ConsoleLogger() = default;
	ConsoleLogger(const ConsoleLogger&) = delete;
	ConsoleLogger(ConsoleLogger&&) = delete;

	//assign operators
	ConsoleLogger& operator=(const ConsoleLogger&) = delete;
	ConsoleLogger& operator=(ConsoleLogger&&) = delete;
};