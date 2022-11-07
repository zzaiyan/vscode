#include <bits/stdc++.h>
using namespace std;

int main()
{
    printf("Hello iPhone!\n");
    int v = __cplusplus;
    printf("std = c++%d%d\n", v / 1000 % 10, v / 100 % 10);
    cout << v << endl;

    string line, out;
    while (getline(cin, line))
    {
        if (line != "end")
            out.append("\"" + line + "\"\n");
        else
            break;
    }
    cout << "\n"
         << out << "\n";
    return 0;
}