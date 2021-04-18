

namespace fs = std::filesystem;

int main()
{
    fs::create_directories("../.minigit");
    fs::copy("../minigit.h", "../.minigit/testing.h");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
