#include <iostream>
#include "dma.h"

int main() {
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    lacksDMA ballon("res", "Blimpo", 4);
    hasDMA map("MEcator", "Buffali Keys", 5);
    cout << "Displaying baseDMA object:\n";
    cout << shirt << endl;
    cout << "Displaying lacksDMA object:\n";
    cout << ballon << endl;
    cout << "Displaying hasDMA object:\n";
    cout << map << endl;

    lacksDMA ballon2(ballon);
    cout << "result of lacksDMA copy:\n";
    cout << ballon2 << endl;
    hasDMA map2;
    map2 = map;
    cout << "result of hasDMA assignment:\n";
    cout << map2 << endl;
    return 0;
}