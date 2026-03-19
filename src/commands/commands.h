#pragma once
#include <iostream>

namespace cmd{
    void Help();

    void Version();

    void License();

    void About();

    void run(bool& runFile);

    void manager(const std::string& arg, bool& runFile);
}
