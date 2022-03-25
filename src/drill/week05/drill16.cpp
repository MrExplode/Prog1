#include "../../gui/GUI.h"
#include "Lines_window.h"

int main()
{
    try
    {
        Lines_window win{Point{100, 100}, 600, 400, "lines"};
        return gui_main();
    }
    catch (exception &e)
    {
        std::cerr << "exception: " << e.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "unknown exception happened!" << std::endl;
        return 2;
    }
}