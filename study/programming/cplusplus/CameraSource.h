#ifndef _CAMERA_SOURCE_H_
#define _CAMERA_SOURCE_H_

class CameraSource {
public:
    CameraSource();
    ~CameraSource();
    bool start();
    bool stop();
    bool getBuffer(int streamId, char**ptr);
private:
    static void threadFunc(void *param);
    char *m_data[4];
};
#endif
