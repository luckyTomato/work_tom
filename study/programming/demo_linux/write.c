#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024  // 定义共享内存的大小

int main() {
    key_t key;
    int shmid;
    char *data;

    // 生成一个独特的键值
    key = ftok("shmfile", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // 创建共享内存段
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // 连接到共享内存段
    data = (char *)shmat(shmid, (void *)0, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    // 向共享内存写入数据
    const char *msg = "Hello from writer!";
    strncpy(data, msg, SHM_SIZE);

    printf("Writer wrote: %s\n", msg);

    // 分离共享内存
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}

