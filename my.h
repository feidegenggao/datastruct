#ifndef     _MY_HEADER
#define     _MY_HEADER
#include 	<iostream>
#include    <errno.h>
#include    <string.h>
#include    <strings.h>
using namespace std;
using std::cout;
using std::cerr;
using std::endl;
using std::cin;
//使用该头文件的应该在自身目录中定义Elemtype的类型。
//typedef int Elemtype
typedef int Status;

const Status ERROR = 1;
const Status SUCCESS = 0;
#endif
