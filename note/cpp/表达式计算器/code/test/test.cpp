#include "node.h"
#include "scanner.h"
#include "parser.h"
#include "stack.h"

#include <iostream>
int main()
{
    STATUS status = STATUS_OK;
    do
    {
        std::cout << "> ";
        std::string buf;
        std::getline(std::cin, buf);
        std::cout << buf << std::endl;
        Scanner scanner(buf);
        Parser parser(scanner);
        parser.Parse();
        parser.Calculate();
    } while (status != STATUS_QUIT);
    return 0;
}