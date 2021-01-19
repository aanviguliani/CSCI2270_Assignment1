cmake_minimum_required(VERSION 3.12)
project(CSCI2270_Assignment4)

set(CMAKE_CXX_STANDARD 14)

add_executable(RPNCalculator RPNCalculator.cpp RPNCalculatorDriver.cpp)
add_executable(ProducerConsumer ProducerConsumer.cpp ProducerConsumerDriver.cpp)