#include "../Arcade/DLLoader.hpp"

DLLoader::DLLoader(const std::string &path)
{
    handle = dlopen(path.c_str, RTLD_LAZY);
    if (!handle) throw std::runtime_error(dlerror());
}

DLLoader::~DLLoader()
{
    if (handle) dlclose(handle); 
}

template <typename T>
std::unique_ptr<T> DLLoader::getInstance()
{
    using CreateFn = T*();
    auto create = reinterpret_cast<CreateFn*>(dlsym(handle, "game_create"));
    if (!create)
        throw::std::runtime_error(dlerror());
    return std::unique_ptr<T>(create());
}
