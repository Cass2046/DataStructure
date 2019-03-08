#include <string>
#include "Executive.h"
int main(int argc, char* argv[])
{
    Executive E(argv[1]);
    E.run("data.txt");
    return 0;
}