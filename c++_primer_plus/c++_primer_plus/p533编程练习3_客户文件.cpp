#include "p533�����ϰ3_ͷ�ļ�.h"
#include <iostream>
int main()
{
    using std::cout;
    using std::endl;
    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    cout << shirt << endl;
    cout << balloon << endl;
    cout << map << endl;
    lacksDMA balloon2(balloon);
    hasDMA map2;
    map2 = map;
    cout << balloon2 << endl;
    cout << map2 << endl;

    ABC * pts[3];
    pts[0] = &shirt;
    pts[1] = &balloon;
    pts[2] = &map;

    for (int i = 0; i < 3; i++)
        cout << *pts[i] << endl;
    for (int i = 0; i < 3; i++)
        pts[i]->View();
  return 0;
}
