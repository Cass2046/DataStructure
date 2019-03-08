#include <string>
#include "Executive.h"
int main(int argc, char* argv[])
{
    Executive E(argv[1]);
    E.run();
    return 0;
}
