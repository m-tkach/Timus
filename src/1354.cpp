#include <bits/stdc++.h>


namespace task1354
{
    inline bool is_pal(const std::string & p, int border)
    {
        int left = border;
        int right = (int)p.size() - 1;
        while (left < right)
        {
            if (p[left++] != p[right--])
            {
                return false;
            }
        }
        return true;
    }


    int solve(std::istream & in, std::ostream & out)
    {
        std::string s;
        in >> s;
        int n = (int)s.size();
        for (int i = 1; i <= n; ++i)
        {
            if (is_pal(s, i))
            {
                std::string r = s.substr(0, i);
                std::reverse(r.begin(), r.end());
                out << s << r << std::endl;
                return 1;
            }
        }
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
        (void)task1354::solve(std::cin, std::cout);
    }
    while (0);
#else
    do
    {
        std::ifstream fin("../input/1354.in");
        if (!(fin.is_open()))
        {
            std::cerr << "The input file isn't found!\n";
            break;
        }
        std::ofstream fout("../output/1354.out");
        int status = task1354::solve(fin, fout);
        std::cout << status << std::endl;
        fout.close();
        fin.close();
    }
    while (0);
#endif // ONLINE_JUDGE

    return 0;
}
