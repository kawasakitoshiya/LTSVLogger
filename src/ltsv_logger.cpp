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
  KeyValue kv = {key, value};
  kvs_.push_back(kv);
  return *this;
}

LTSVLogger &LTSVLogger::set(std::string key, int value) {
  std::stringstream tmp;
  tmp << value;
  KeyValue kv = {key, tmp.str()};
  kvs_.push_back(kv);
  return *this;
}

LTSVLogger &LTSVLogger::set(std::string key, float value) {
  std::stringstream tmp;
  tmp << value;
  KeyValue kv = {key, tmp.str()};
  kvs_.push_back(kv);
  return *this;
}

void LTSVLogger::set_level(std::string level) {
  level_.key = "level";
  level_.value = level;
}

void LTSVLogger::critical() {
  set_level("critical");
  print_log();
}

void LTSVLogger::error() {
  set_level("error");
  print_log();
}

void LTSVLogger::warning() {
  set_level("warning");
  print_log();
}

void LTSVLogger::info() {
  set_level("info");
  print_log();
}

void LTSVLogger::debug() {
  set_level("debug");
  print_log();
}

void LTSVLogger::print_log() {
  std::stringstream ss;
  if (print_time_)  append_time(ss);
  ss << level_.key << ":" << level_.value << "\t";
  append_ltsv(ss);

  std::cout << ss.str() << std::endl;

  clear();
}

void LTSVLogger::clear() {
  kvs_.clear();
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
  std::vector<KeyValue>::iterator it;
  int len = kvs_.size();
  for (int i = 0; i < len; i++) {
    ss << kvs_[i].key << ":" << kvs_[i].value << "\t";
  }
}
