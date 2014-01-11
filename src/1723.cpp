#include <bits/stdc++.h>


namespace task1723
{
    int solve(std::istream & in, std::ostream & out)
    {
        int w[256] = {};
        int m = 0;
        char c, r = 'a';
        while (in >> c)
        {
            ++w[c];
            if (w[c] > m)
            {
                m = w[c];
                r = c;
            }
        }
        out << r << std::endl;
        return 0;
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    srand((unsigned)time(0));

#ifdef ONLINE_JUDGE
    do
    {
        (void)task1723::solve(std::cin, std::cout);
    }
    while (0);
#else
    do
    {
        std::ifstream fin("../input/1723.in");
        if (!(fin.is_open()))
        {
            std::cerr << "The input file isn't found!\n";
            break;
        }
        std::ofstream fout("../output/1723.out");
        int status = task1723::solve(fin, fout);
        std::cout << status << std::endl;
        fout.close();
        fin.close();
    }
    while (0);
#endif // ONLINE_JUDGE

    return 0;
}
