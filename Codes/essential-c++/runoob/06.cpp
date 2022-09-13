#include <iostream>
#include <ctime>

using namespace std;

int main ()
{
    int i,j;

    // 设置种子
    srand( (unsigned)time( NULL ) );

    //生成 10 个随机数
    for( i = 0; i < 10; i++ )
    {
        //生成实际的随机数
        j= rand();
        cout <<"随机数 " << j << endl;
    }
    double balance[6] = {1000.0, 2.0, 3.4, 7.0};
    for (int ix = 0; ix < 6; ix++) {
        cout << balance[ix] << endl;
    }
    return 0;
}