#include <bits/stdc++.h>


namespace task0000
{
    int solve(std::istream & in, std::ostream & out)
    {
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
        (void)task0000::solve(std::cin, std::cout);
    }
    while (0);
#else
    do
    {
        std::ifstream fin("../input/0000.in");
        if (!(fin.is_open()))
        {
            std::cerr << "The input file not found!\n";
            break;
        }
        std::ofstream fout("../output/0000.out");
        int status = task0000::solve(fin, fout);
        std::cout << status << std::endl;
        fout.close();
        fin.close();
    }
    while (0);
#endif // ONLINE_JUDGE

    return 0;
}
