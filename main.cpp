#include <iostream>
#include "multimapclass.hpp"

using namespace std;

int main() {
    Multimap_class<string, int> mc;

    mc.insert("aaa", 1);
    mc.insert("bbb", 2);
    mc.insert("ccc", 3);
    mc.insert("aaa", 4);

    mc.erase("aaa");

    auto b = mc.find("bbb");
    for (auto &i: b) {
        cout << i << " ";
    }
    cout << endl;
    cout << mc;
}
