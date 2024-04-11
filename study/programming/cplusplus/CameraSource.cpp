#include "CameraSource.h"
#include <thread>
#include <iostream>
#include <cstring>

const int WIDTH = 1936;
const int HEIGHT = 1112;
const char testStr1[] = "aaaaaa";
const char testStr2[] = "bbbbbbbb";
const char testStr3[] = "cccccc";
const char testStr4[] = "dddddddd";


CameraSource::CameraSource() {
    for (int i = 0; i < 4; i++) {
	m_data[i] = new char[WIDTH * HEIGHT *2];
	std::cout<<"m_data["<<i<<"]="<<m_data[i]<<std::endl;
	printf("[i]:%p\n", m_data[i]);
    }

    strcpy(m_data[0], testStr1);
    strcpy(m_data[1], testStr2);
    strcpy(m_data[2], testStr3);
    strcpy(m_data[3], testStr4);
    
    printf("m_data[0]:%s\n", m_data[0]);
    std::cout<<"m_data[0]="<<m_data[0]<<std::endl;
}

CameraSource::~CameraSource() {
    for (int i = 0; i < 4; i++) {
        delete[] m_data[i];
	m_data[i] = nullptr;
    }
}

bool CameraSource::start() {
    std::thread t(threadFunc, this);
    t.join();
    return true;
}

bool CameraSource::stop() {
    return true;
}

bool CameraSource::getBuffer(int streamId, char**ptr) {
    if (streamId < 0 || streamId > 3)
	return false;
    printf("in ptr:%p\n", ptr);
    *ptr = m_data[streamId];
    printf("out ptr:%p\n", ptr);
    return true;
}


void CameraSource::threadFunc(void *param) {
   std::cout<<"=== enter threadFunc"<<std::endl;
   CameraSource *pSource = (CameraSource*)(param);
   char *ptr = nullptr;
   std::cout<<"ptr="<<ptr<<std::endl;
   printf("iin ptr:%p\n", ptr);
   pSource->getBuffer(0, &ptr);
   printf("oout ptr:%s\n", ptr);

}
