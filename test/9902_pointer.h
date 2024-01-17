static inline int Pointer(void *mutex) {
    int hoge = 3;
    mutex = &hoge;
    return 0;
}