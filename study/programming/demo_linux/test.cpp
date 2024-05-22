// Process A
int ion_fd = ion_open();
struct ion_allocation_data alloc_data = {
    .len = size,
    .align = 0,
    .heap_id_mask = ION_HEAP_TYPE_SYSTEM,
    .flags = 0,
};
ioctl(ion_fd, ION_IOC_ALLOC, &alloc_data);
int share_fd = alloc_data.fd;

// Send share_fd to process B (via IPC mechanism, e.g., Unix domain socket)

// Process B
int ion_fd = ion_open();
// Receive share_fd from process A (via IPC mechanism)
int map_fd = share_fd;
void *shared_memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, map_fd, 0);

// Access shared_memory

// Clean up
munmap(shared_memory, size);
close(map_fd);

