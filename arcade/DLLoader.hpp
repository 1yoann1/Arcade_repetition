#ifndef DLLOADER_HPP
#define DLLOADER_HPP

#include <memory>
#include <string>
#include <dlfcn.h>
#include <stdexcept>
#include <iostream>

template <typename T>

class DLLoader {
public:
    DLLoader(const std::string &path) {
        handle = dlopen(path.c_str(), RTLD_LAZY);
        if (!handle) throw std::runtime_error(dlerror());
    }

    ~DLLoader() {
        if (handle) dlclose(handle); 
    }

    std::unique_ptr<T> getInstance() {
        using CreateFn = T*();
        auto create = reinterpret_cast<CreateFn*>(dlsym(handle, "create_lib"));
        if (!create) throw std::runtime_error(dlerror());
        return std::unique_ptr<T>(create());
    }
    //__attribute__((constructor)) DLLoader();
    //__attribute__((destructor)) ~DLLoader();
    //std::unique_ptr<T> myEntryPoint();
private:
    void* handle;
};

#endif