#ifndef DLLOADER_HPP
#define DLLOADER_HPP

#include <memory>
#include <string>
#include <dlfcn.h>
#include <stdexcept>

template <typename T>

class DLLoader {
public:
    DLLoader(const std::string &path);
    ~DLLoader();
    std::unique_ptr<T> getInstance();
    //__attribute__((constructor)) DLLoader();
    //__attribute__((destructor)) ~DLLoader();
    //std::unique_ptr<T> myEntryPoint();
private:
    void* handle;
};

#endif