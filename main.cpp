

#include "minigit.h"

int main()
{
    fs::copy("../minigit.h", "../.minigit/testing.h");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
