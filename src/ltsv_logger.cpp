/*
 * Copyright 2013 kawasakitoshiya
*/

#include "ltsv_logger.h"
#include <iostream>
#include <sstream>
#include <ctime>

LTSVLogger::LTSVLogger(bool print_time, std::string time_format)
  : print_time_(print_time), time_format_(time_format) {
}

LTSVLogger &LTSVLogger::set(std::string key, std::string value) {
  string_values_[key] = value;
  return *this;
}

LTSVLogger &LTSVLogger::set(std::string key, int value) {
  int_values_[key] = value;
  return *this;
}

LTSVLogger &LTSVLogger::set(std::string key, float value) {
  float_values_[key] = value;
  return *this;
}

void LTSVLogger::critical() {
  set("level", "critical");
  print_log();
}

void LTSVLogger::error() {
  set("level", "error");
  print_log();
}

void LTSVLogger::warning() {
  set("level", "warning");
  print_log();
}

void LTSVLogger::info() {
  set("level", "info");
  print_log();
}

void LTSVLogger::debug() {
  set("level", "debug");
  print_log();
}


void LTSVLogger::print_log() {
  std::stringstream ss;
  if (print_time_)  append_time(ss);
  append_ltsv(ss);

  std::cout << ss.str() << std::endl;

  clear();
}

void LTSVLogger::clear() {
  string_values_.clear();
  int_values_.clear();
  float_values_.clear();
}

void LTSVLogger::append_time(std::stringstream &ss) {
  time_t t;
  struct tm tm;
  char str[81];

  time(&t);

  localtime_r(&t, &tm);
  strftime(str, sizeof(str), time_format_.c_str(), &tm);
  ss << "time" << ":" << str << "\t";
}

void LTSVLogger::append_ltsv(std::stringstream &ss) {
  std::map<std::string, std::string>::iterator it_str = string_values_.begin();
  while ( it_str != string_values_.end() ) {
      ss << (*it_str).first << ":" << (*it_str).second << "\t";
      ++it_str;
    }

  std::map<std::string, int>::iterator it_int = int_values_.begin();
  while ( it_int != int_values_.end() ) {
      ss << (*it_int).first << ":" << (*it_int).second << "\t";
      ++it_int;
    }

  std::map<std::string, float>::iterator it_float = float_values_.begin();
  while ( it_float != float_values_.end() ) {
      ss << (*it_float).first << ":" << (*it_float).second << "\t";
      ++it_float;
    }
}
