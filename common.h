#ifndef COMMON_H
#define COMMON_H

template<typename T, int DefaultValue>
struct ___x3 {
public:
    T x, y, z;

    void operator() (const T &x, const T &y, const T &z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

protected:
    ___x3() : x(DefaultValue), y(DefaultValue), z(DefaultValue) {}
    ___x3(const T &x, const T &y, const T &z) : x(x), y(y), z(z) {}
};

// по красоте, надо написать макросы

struct float3 : public ___x3<float, 0> {
    float3() {}
    float3(float x, float y, float z) : ___x3(x, y, z) {}
};

struct int3 : public ___x3<int, 0> {
    int3() {}
    int3(int x, int y, int z) : ___x3(x, y, z) {}
};

struct dim3 : public ___x3<int, 1> {
    dim3() {}
    dim3(int x, int y, int z) : ___x3(x, y, z) {}
};

#endif // COMMON_H
