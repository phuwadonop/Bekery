#include<iostream>

using namespace std;

void calCake(int,int*);

int main() {

    int n; int nCake = 0;

    int* nCakePtr = &nCake;

    cin >> n;

    calCake(n, nCakePtr);

    cout << *nCakePtr;
}

void calCake(int n, int* nCake)
{
    short order[5];

    int tqCake = 0, halfCake = 0, oqCake = 0, oeCake = 0;

    while (n)
    {
        for (int i = 0; i < 5; i++)
            cin >> order[i];

        // full
        if (order[0] != 0)
        {
            *nCake += order[0];
        }
        // 3/4
        if (order[1] != 0)
        {
            int b = order[1];
            if (tqCake == 0)
            {
                *nCake += b;
                oqCake += b;
            }
            else
            {
                if (tqCake > b)
                {
                    tqCake -= b;
                }
                else
                {
                    b -= tqCake;
                    tqCake = 0;
                    *nCake += b;
                    oqCake += b;
                }
            }

        }
        // 1/2
        if (order[2] != 0)
        {
            int c = order[2];
            if (halfCake == 0)
            {
                if (c % 2 == 0)
                {
                    *nCake += c / 2;
                }
                else
                {
                    *nCake += c / 2;
                    halfCake += 1;
                }
            }
            else
            {
                c -= halfCake;
                halfCake = 0;

                if (c % 2 == 0)
                {
                    *nCake += c / 2;
                }
                else
                {
                    *nCake += c / 2;
                    halfCake += 1;
                }

            }

        }
        // 1/4
        if (order[3] != 0)
        {
            int e = order[3];
            if (oqCake == 0)
            {
                if (e % 4 == 0)
                {
                    *nCake += e / 4;
                }
                else
                {
                    *nCake += e / 4;
                    int q = e % 4;
                    *nCake += 1;
                    oqCake += 4;
                    oqCake -= q;
                }
            }
            else
            {
                e -= oqCake;
                oqCake = 0;
                if (e % 4 == 0)
                {
                    *nCake += e / 4;
                }
                else
                {
                    *nCake += e / 4;
                    int q = e % 4;
                    *nCake += 1;
                    oqCake += 4;
                    oqCake -= q;
                }
            }

        }
        // 1/8 
        if (order[4] != 0)
        {
            int d = order[4];
            if (oeCake == 0)
            {
                if (d % 8 == 0)
                {
                    *nCake += d / 8;
                }
                else
                {
                    *nCake += d / 8;
                    int q = d % 8;
                    *nCake += 1;
                    oeCake += 8;
                    oeCake -= q;
                }
            }
            else
            {
                d -= oeCake;
                oeCake = 0;
                if (d % 8 == 0)
                {
                    *nCake += d / 8;
                }
                else
                {
                    *nCake += d / 8;
                    int q = d % 8;
                    *nCake += 1;
                    oeCake += 8;
                    oeCake -= q;
                }
            }

        }
        n--;
    }

}